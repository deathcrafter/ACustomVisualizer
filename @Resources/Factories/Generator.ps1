function Update {

}
function Craft{
    $initiated=$RmAPI.Variable('Initiated')
    
    if ($initiated -eq 0) {
        PrepareBackup
        Start-Sleep -Milliseconds 500
        CreateVariables
        Start-Sleep -Milliseconds 1000
        PrepareIncludes
        $RmAPI.Bang("!WriteKeyValue Variables Initiated 1")
        $RmAPI.Bang("!Refresh")
        exit
    }else{
        Start-Sleep -Milliseconds 500
        MakeVisualizers
        Start-Sleep -Milliseconds 1000
        CreateMeasures
        $RmAPI.Bang("!WriteKeyValue Variables Initiated 0")
        $RmAPI.Bang("!Refresh")
    }
}
function Change{
    MakeVisualizers
    Start-Sleep -Milliseconds 1000
    CreateMeasures
    $RmAPI.Bang("!Refresh")
}
function CreateVariables{
    $groupCount = $RmAPI.Variable('GroupCount')

    $varPath = $RmAPI.VariableStr('@')

    $RmAPI.Log('Creating variables...')

#Creates variables for each group.
    for ($i=0; $i -lt $groupCount; $i++) {
        $variables=@"
[Variables]
Group=$i
XG$i=6R
YG$i=r
MeasureStartG$i=1
BarCountG$i=5
HeightG$i=300
WidthG$i=12
GapG$i=6
StrokeWidthG$i=0
RoundingG$i=3
LevitateG$i=10
XFlipG$i=0
AngleG$i=0
MinimumHeightG$i=10
ImageNameG$i=
ColorG$i=150, 200, 250
GradientG$i=180 | 255,0,0;0.0 | 150,200,250;1.0
GradientBoolG$i=0
"@
        $variables | Out-File -FilePath $($varPath+"Variables\Variable$i.inc")
    }
    $RmAPI.Log('Successfully created variables.')
}

function MakeVisualizers {
    $varPath = $RmAPI.VariableStr('@')

    $groupCount = $RmAPI.Variable('GroupCount')

    $measureHash = AssignMeasures -groupCount $groupCount

    $RmAPI.Log('Creating visualizers...')

    for ($i=0; $i -lt $groupCount; $i++) {
        $barCount = $RmAPI.Variable("BarCountG$i")
        $visContent = @"

[Shape$i]
Meter=Shape
X=[#XG$i]
Y=[#YG$i]
"@
        $visCombine="Combine Shape"
        for ($j=0; $j -lt $barCount; $j++) {
            if ($j -eq 0) {
                $visContent+=@"

Shape=Rectangle 0,([#HeightG$i]+2*[#StrokeWidthG$i]-[#LevitateG$i]), [#WidthG$i],(Clamp((-[#HeightG$i]*$($measureHash["G$i$j"])), -[#HeightG$i], [#MinimumHeightG$i])), [#RoundingG$i] | StrokeWidth #StrokeWidthG$i# | Extend Color[#GradientBoolG$i]
"@
            }else{
                $visContent+=@"

Shape$($j+1)=Rectangle ($j*([#WidthG$i]+[#GapG$i])),(#HeightG$i#+2*[#StrokeWidthG$i]-#LevitateG$i#), #WidthG$i#, (Clamp((-[#HeightG$i]*$($measureHash["G$i$j"])), -[#HeightG$i], [#MinimumHeightG$i])), [#RoundingG$i] | StrokeWidth #StrokeWidthG$i#
"@
                $visCombine+=" | Union Shape$($j+1)"
            }
        }
        $visContent+=@"

Shape$($barCount + 1)=$($visCombine + " | Rotate [#AngleG$i]") 
Color0=Fill Color [#ColorG$i]
Color1=Fill LinearGradient1 MyGradient
MyGradient=[#GradientG$i]
DynamicVariables=1
"@
        $visContent | Out-File -FilePath $($varPath+"Visualizers\Visualizer$i.inc")
    }
    $RmAPI.Log('Successfully created visualizers!')
}
function CreateMeasures {
    $groupCount = $RmAPI.Variable('GroupCount')

    $varPath = $RmAPI.VariableStr('@')

    $measureHash=AssignMeasures -groupCount $groupCount

    $measureIndex=1

    $measureCount = DecideBands -groupCount $groupCount
    
    $RmAPI.Bang("!WriteKeyValue Variables Bands $measureCount `"@Resources\GlobalVariables.inc`"" )

    $RmAPI.Log('Creating measures...')

    for ($i=0; $i -lt $groupCount; $i++) {
        $barCount = $RmAPI.Variable("BarCountG$i")
        $measureStart = $RmAPI.Variable("MeasureStartG$i")
        $measureOrder = $RmAPI.Variable("XFlipG$i")
        $measureContent=@"
"@
        if ($measureOrder -eq 0) {
            for ($j=0; $j -lt $barCount; $j++) {
                $measureContent+=@"

$($measureHash["G$i$j"])
Measure=Plugin
Plugin=AudioAnalyzer
Parent=MeasureAudioAnalyzer
Type=Child
Index=$($measureStart+$j)
Channel=Auto
HandlerName=MainFinalOutput

"@       
            }
        }else{
            for ($j=0; $j -lt $barCount; $j++) {
                $measureContent+=@"

$($measureHash["G$i$j"])
Measure=Plugin
Plugin=AudioAnalyzer
Parent=MeasureAudioAnalyzer
Type=Child
Index=$(($measureStart+$barCount-1)-$j)
Channel=Auto
HandlerName=MainFinalOutput

"@       
            }
        }
        $measureIndex+=$barCount
        $measureContent | Out-File -FilePath $($varPath+"Measures\Measure$i.inc")
    }
    $RmAPI.Log('Successfully created measures')
}

function DecideBands {
    param(
        [Parameter(Mandatory=$true)]
        $groupCount
    )
    $measureCount=@()
    for ($i=0; $i -lt $groupCount; $i++) {
        $barCount = $RmAPI.Variable("BarCountG$i")
        $measureStart = $RmAPI.Variable("MeasureStartG$i")
        $measureCount += $barCount+$measureStart-1
    }
    $b=$measureCount | Measure-Object -Maximum
    return $b.Maximum
}
function AssignMeasures {
#This function assigns "key","value" pairs to 'measureHash' hashtable in MakeVisualizers function.
    param(
        [Parameter(Mandatory = $true)]
        $groupCount
    )
    $measure=[ordered]@{}
    for ($i=0; $i -lt $groupCount; $i++) {
        $barCount = $RmAPI.Variable("BarCountG$i")
        for ($j=0; $j -lt $barCount; $j++) {
            $measure.Add($('G'+"$i"+"$j"), "[Measure$("$i" + 'G')$j]")
        }
    }
    return $measure
}
function PrepareIncludes{
    $groupCount = $RmAPI.Variable('GroupCount')
    $varPath = $RmAPI.VariableStr('@')
    $RmAPI.Log('Preparing includes...')
    $includeVariables = @"

[Includes]
"@
    $includeVisualizer = @"
    
[Includes]
"@

    for ($i=0; $i -lt $groupCount; $i++) {
        $includeVisualizer+=@"

@includeMeasureG$i=#@#Measures\Measure$i.inc
@includeVisualizerG$i=#@#Visualizers\Visualizer$i.inc
"@
        $includeVariables+=@"

@includeMeasureG$i=#@#Variables\Variable$i.inc
"@
    }
    $includeVisualizer | Out-File -FilePath $($varPath+'VisInclude.inc')
    Start-Sleep -Milliseconds 500
    $includeVariables | Out-File -FilePath $($varPath+'VarInclude.inc')
    $RmAPI.Log('Successfully prepared includes!')
}
function PrepareBackup {
    $varPath = $RmAPI.VariableStr('@')
    $skinPath = $RmAPI.VariableStr('ROOTCONFIGPATH')
    $directory = Get-Date -Format ddMMMy_hh-mm-ss
    $RmAPI.Log('Preparing directories...')
    New-Item -Path $($skinPath + '@Backup') -Name "$directory" -ItemType "Directory"
    New-Item -Path $($skinPath + "@Backup\$directory") -Name "Variables" -ItemType "Directory"
    New-Item -Path $($skinPath + "@Backup\$directory") -Name "Visualizers" -ItemType "Directory"
    New-Item -Path $($skinPath + "@Backup\$directory") -Name "Measures" -ItemType "Directory"
    $RmAPI.Log('Backing up...')
    Copy-Item -Path $($varPath+'Variables\*.inc') -Destination $($skinPath+"@Backup\$directory\Variables") -Recurse
    Start-Sleep -Milliseconds 200
    Copy-Item -Path $($varPath+'Visualizers\*.inc') -Destination $($skinPath+"@Backup\$directory\Visualizers") -Recurse
    Start-Sleep -Milliseconds 200
    Copy-Item -Path $($varPath+'Measures\*.inc') -Destination $($skinPath+"@Backup\$directory\Measures") -Recurse
    Start-Sleep -Milliseconds 200
    Copy-Item -Path $($varPath+'*.inc') -Destination $($skinPath+"@Backup\$directory") -Recurse
    $RmAPI.Log('Backup complete!')
    Purge
}
function Purge {
    $varPath = $RmAPI.VariableStr('@')
    Remove-Item -Path $($varPath+'Variables\*.inc') -Force
    Remove-Item -Path $($varPath+'Visualizers\*.inc') -Force
    Remove-Item -Path $($varPath+'Measures\*.inc') -Force
}