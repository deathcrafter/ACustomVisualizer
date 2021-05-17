function Update {

}
function Craft{
    $initiated=$RmAPI.Variable('Initiated')
    
    if ($initiated -eq 0) {
        PrepareBackup
        Start-Sleep -Milliseconds 100
        CreateVariables
        Start-Sleep -Milliseconds 100
        PrepareIncludes
        $RmAPI.Bang("!WriteKeyValue Variables Initiated 1")
        $RmAPI.Bang("!Refresh")
        exit
    }else{
        MakeVisualizers
        Start-Sleep -Milliseconds 200
        CreateMeasures
        $RmAPI.Bang("!WriteKeyValue Variables Initiated 0")
        $RmAPI.Bang("!Refresh `"ACustomVisualizer\Visualizer`"")
        $RmAPI.Bang("!Refresh")
    }
}
function Change{
    MakeVisualizers
    Start-Sleep -Milliseconds 1000
    CreateMeasures
    $RmAPI.Bang("!Refresh `"ACustomVisualizer\Visualizer`"")
}
function CreateVariables{
    $groupCount = $RmAPI.Variable('GroupCount')

    $varPath = $RmAPI.VariableStr('@')

    $RmAPI.Log('Creating variables...')

    $existingCount = (Get-ChildItem -Path $($varPath + 'Variables')).Count

    $existingFile = Get-ChildItem -Path $($varPath + 'Variables') -Name

#Creates variables for each group.
    for ($i=$existingCount; $i -lt $groupCount; $i++) {
        if ($existingFile -notcontains "Variable$i.inc") {
        $variables=@"
[Variables]
XG$i=$(90*$i)
YG$i=0
MeasureStartG$i=1
BarCountG$i=5
HeightG$i=300
WidthG$i=12
GapG$i=6
StrokeWidthG$i=0
RoundingG$i=3
XFlipG$i=0
AngleG$i=0
MinimumHeightG$i=10
ColorG$i=150, 200, 250
GradientG$i=180 | 255,0,0;0.0 | 150,200,250;1.0
GradientBoolG$i=0
"@
        }
        $variables | Out-File -FilePath $($varPath+"Variables\Variable$i.inc")
    }
    $RmAPI.Log('Successfully created variables.')
}

$shapeNum=@()
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

Shape=Rectangle 0,([#HeightG$i]+2*[#StrokeWidthG$i]), [#WidthG$i],(Clamp((-[#HeightG$i]*$($measureHash["G$i$j"])), -[#HeightG$i], -[#MinimumHeightG$i])), [#RoundingG$i] | StrokeWidth #StrokeWidthG$i# | Extend Color[#GradientBoolG$i]
"@
            }else{
                $visContent+=@"

Shape$($j+1)=Rectangle ($j*([#WidthG$i]+[#GapG$i])),(#HeightG$i#+[#StrokeWidthG$i]), #WidthG$i#, (Clamp((-[#HeightG$i]*$($measureHash["G$i$j"])), -[#HeightG$i], -[#MinimumHeightG$i])), [#RoundingG$i] | StrokeWidth #StrokeWidthG$i#
"@
                $visCombine+=" | Union Shape$($j+1)"
            }
        }
        $visContent+=@"

Shape$($barCount + 1)=$($visCombine + " | Rotate [#AngleG$i], 0, (#HeightG$i#+[#StrokeWidthG$i])") 
Color0=Fill Color [#ColorG$i]
Color1=Fill LinearGradient1 MyGradient
MyGradient=[#GradientG$i]
LeftMouseDownAction=[!SetVariable CurrentGroup $i][!SetVariable DiffX ([&MouseX]-#CURRENTCONFIGX#-[#XG$i])][!SetVariable DiffY ([&MouseY]-#CURRENTCONFIGY#-[#YG$i])][!EnableMeasure ShapeMover]
LeftMouseUpAction=[!WriteKeyValue Variables XG$i [#XG$i] "#@#Variables\Variable$i.inc"][!WriteKeyValue Variables YG$i [#YG$i] "#@#Variables\Variable$i.inc"][!Refresh]
MouseScrollUpAction=[!WriteKeyValue Variables AngleG$i ([#AngleG$i]+1) "#@#Variables\Variable$i.inc"][!Refresh]
MouseScrollDownAction=[!WriteKeyValue Variables AngleG$i ([#AngleG$i]-1) "#@#Variables\Variable$i.inc"][!Refresh]
DynamicVariables=1
"@
        $visContent | Out-File -FilePath $($varPath+"Visualizers\Visualizer$i.inc")
    }
    $RmAPI.Log('Successfully created visualizers!')
}
function CreateMeasures {
    $groupCount = $RmAPI.Variable('GroupCount')

    $varPath = $RmAPI.VariableStr('@')

    $measureArray=PrepareMeasures -groupCount $groupCount

    $measureCount = DecideBands -groupCount $groupCount
    
    $RmAPI.Bang("!WriteKeyValue Variables Bands $measureCount `"$($RmAPI.VariableStr('@')+'GlobalVariables.inc')`"" )

    $RmAPI.Log('Creating measures...') 

    $measureContent=@"
"@

    $measureArray | ForEach-Object {
        
        $measureContent+=@"

[Measure$_]
Measure=Plugin
Plugin=AudioAnalyzer
Parent=MeasureAudioAnalyzer
Type=Child
Index=$_
Channel=Auto
HandlerName=MainFinalOutput
Disabled=[#EditMode]

"@
    }
    $measureContent | Out-File -FilePath $($varPath+"Measure$i.inc")
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
function PrepareMeasures {
    param(
        [Parameter(mandatory=$true)]
        $groupCount
    )
    $measure=@()
    for ($i=0; $i -lt $groupCount; $i++) {
        $barCount = $RmAPI.Variable("BarCountG$i")
        $measureStart = $RmAPI.Variable("MeasureStartG$i")
        for ($j=0; $j -lt $barCount; $j++) {
            if ($measure -notcontains $j+$measureStart) {
            $measure+=$j+$measureStart
            }
        }
    }
    return $measure
}
function AssignMeasures {
#This function assigns "key","value" pairs to 'measureHash' hashtable in MakeVisualizers.
#This also takes care of X-Flip.
    param(
        [Parameter(Mandatory = $true)]
        $groupCount
    )
    $measure=[ordered]@{}
    for ($i=0; $i -lt $groupCount; $i++) {
        $barCount = $RmAPI.Variable("BarCountG$i")
        $measureStart = $RmAPI.Variable("MeasureStartG$i")
        $flipBool = $RmAPI.Variable("XFlipG$i")
        for ($j=0; $j -lt $barCount; $j++) {
            if ($flipBool -eq 0) {
                $measure.Add($('G'+"$i"+"$j"), "[Measure$($j+$measureStart)]")
            } else {
                $measure.Add($('G'+"$i"+"$j"), "[Measure$(($measureStart+$barCount-1)-$j)]")
            }
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
    $directory = Get-Date -Format ddMMMy_HH-mm-ss
    $RmAPI.Log('Preparing directories...')
    New-Item -Path $($skinPath + '@Backup') -Name "$directory" -ItemType "Directory"
    New-Item -Path $($skinPath + "@Backup\$directory") -Name "Variables" -ItemType "Directory"
    New-Item -Path $($skinPath + "@Backup\$directory") -Name "Visualizers" -ItemType "Directory"
    New-Item -Path $($skinPath + "@Backup\$directory") -Name "Measures" -ItemType "Directory"
    $RmAPI.Log('Backing up...')
    Copy-Item -Path $($varPath+'Variables\*.inc') -Destination $($skinPath+"@Backup\$directory\Variables") -Recurse
     
    Copy-Item -Path $($varPath+'Visualizers\*.inc') -Destination $($skinPath+"@Backup\$directory\Visualizers") -Recurse
    
    Copy-Item -Path $($varPath+'*.inc') -Destination $($skinPath+"@Backup\$directory") -Recurse
    $RmAPI.Log('Backup complete!')
    Purge
}
function Purge {
    $varPath = $RmAPI.VariableStr('@')
    $groupCount = $RmAPI.Variable('GroupCount')
    
    $existingCount = (Get-ChildItem -Path $($varPath + 'Variables')).Count
    if ($existingCount -gt $groupCount) {
        $RmAPI.Log('Purging previous files...')
        for ($i=$groupCount; $i -lt $existingCount; $i++) { 
            Remove-Item -Path $($varPath+"Variables\Variable$i.inc") -Force
            Remove-Item -Path $($varPath+"Visualizers\Visualizer$i.inc") -Force
            Remove-Item -Path $($varPath+"Measures\Measure$i.inc") -Force
        }
        $RmAPI.Log('Purging completed successfully!')
    } 
}
function CompletePurge {
    $varPath = $RmAPI.VariableStr('@')
    PrepareBackup
    $RmAPI.Log('Purging all files...')
    $exclude = @('GlobalVariables.inc', 'EditModeVars.inc') 
    Remove-Item -Path $($varPath+"Variables\*.inc") -Force
    Remove-Item -Path $($varPath+"Visualizers\*.inc") -Force
    Remove-Item -Path $($varPath+"Measures\*.inc") -Force
    Remove-Item -Path $($varPath+"*.inc")  -Exclude $exclude -Force
    
    $RmAPI.Log('Purged all files successfully!')
}
function EnterEditMode{
    $groupCount = $RmAPI.Variable('GroupCount')
    for ($i=0; $i -lt $groupCount; $i++) {
        $minimumHeight=$RmAPI.Variable("MinimumHeightG$i")
        $RmAPI.Bang("!WriteKeyValue Variables EditMinimumHeightG$i $minimumHeight `"$($RmAPI.VariableStr('@')+'EditModeVars.inc')`"")
        $RmAPI.Bang("!WriteKeyValue Variables MinimumHeightG$i `"[#*HeightG$i*]`" `"$($RmAPI.VariableStr('@')+"Variables\Variable$i.inc")`"")
    }
    $RmAPI.Bang("!WriteKeyValue Variables EditMode 1 `"$($RmAPI.VariableStr('@')+"GlobalVariables.inc")`"")
    $RmAPI.Bang("!Refresh `"ACustomVisualizer\Visualizer`"")
    $RmAPI.Bang("!Refresh")
}
function ExitEditMode {
    $varPath = $RmAPI.VariableStr('@')
    $groupCount = $RmAPI.Variable('GroupCount')
    for ($i=0; $i -lt $groupCount; $i++) {
        $minimumHeight=$RmAPI.Variable("EditMinimumHeightG$i")
        $RmAPI.Bang("!WriteKeyValue Variables MinimumHeightG$i $minimumHeight `"$($varPath+"Variables\Variable$i.inc")`"") 
    }
    Clear-Content -Path $($varPath + 'EditModeVars.inc') -Exclude '[Variables]'
    $RmAPI.Bang("!WriteKeyValue Variables EditMode 0 `"$($RmAPI.VariableStr('@')+"GlobalVariables.inc")`"")
    $RmAPI.Bang("!Refresh `"ACustomVisualizer\Visualizer`"")
    $RmAPI.Bang("!Refresh")
}
function AssignShapeNumbers {
    param(
        [Parameter(Mandatory=$true)]
        $groupCount
    )
    $shapeNum=[ordered]@{}
    $shapeNum.Add("G00", "")
    $k=1
    for ($i=0; $i -lt $groupCount; $i++) {
        $barCount=$RmAPI.Variable("BarCountG$i")
        for ($j = $(if($i -eq 0){1}else{0}); $j -lt $barCount; $j++) {
            $k=$k+1
            $shapeNum.Add("G$i$j", "$k")
        }
    }
    for ($i=0; $i -lt $groupCount; $i++) {
        $k=$k+1
        $shapeNum.Add("C$i", "$k")
    }
    $shapeNum.Add("U", "$($k+1)")
    return $shapeNum
}
function MakePermanentVisualizer {
    $varPath = $RmAPI.VariableStr('@')

    $groupCount = $RmAPI.Variable('GroupCount')

    $measureHash = AssignMeasures -groupCount $groupCount

    $shapeHash = AssignShapeNumbers -groupCount $groupCount

    $RmAPI.Log('Creating permanent visualizer...')
    $combine=[ordered]@{}
    $unite=@"
"@
    $shapeContent=@"

[Shape]
Meter=Shape
X=0
Y=0
"@

    for ($i=0; $i -lt $groupCount;$i++) {
        $RmAPI.Log("Getting variables for group$i")
        $x=$RmAPI.Variable("XG$i")
        $y=$RmAPI.Variable("YG$i")
        $barCount=$RmAPI.Variable("BarCountG$i")
        $height=$RmAPI.Variable("HeightG$i")
        $width=$RmAPI.Variable("WidthG$i")
        $gap=$RmAPI.Variable("GapG$i")
        $strokeWidth=$RmAPI.Variable("StrokeWidthG$i")
        $rounding=$RmAPI.Variable("RoundingG$i")
        $angle=$RmAPI.Variable("AngleG$i")
        $minimumHeight=$RmAPI.Variable("MinimumHeightG$i")
        
        $combineContent=@"
"@
        for ($j=0; $j -lt $barCount; $j++) {
            
            $shapeContent+=@"

Shape$($shapeHash["G$i$j"])=Rectangle $($x+$j*($width+$gap)),$($y+$height+$strokeWidth), $width, (Clamp((-$height*$($measureHash["G$i$j"])), -$height, -$minimumHeight)), $rounding | StrokeWidth $strokeWidth
"@
            if ($j -eq 0) {
                $shapeContent+=@"
 | Fill LinearGradient1 MyGradient$i
"@
                $combineContent+=@"

Shape$($shapeHash["C$i"])=Combine Shape$($shapeHash["G$i$j"])
"@
            }else{
                $combineContent+=@"
 | Union Shape$($shapeHash["G$i$j"])
"@
            }
        }
        $combineContent+=@"
 | Rotate $angle, $x, $($y+$height+$strokeWidth)
"@
        $combine.Add("$i", "$combineContent")
        $RmAPI.Log("Completed group$i...")
    }
    for ($i=0; $i -lt $groupCount; $i++) {
        $gradient=$RmAPI.VariableStr("GradientG$i")
        $shapeContent+=@"

$($combine["$i"])
MyGradient$i=$gradient
"@
        if ($i -eq 0) {
            $unite+=@"

Shape$($shapeHash["U"])=Combine Shape$($shapeHash["C$i"])
"@
        }else{
            $unite+=@"
 | Union Shape$($shapeHash["C$i"])
"@
        }
        
    }
    if (0 -eq 1){
        $shapeContent+=@"

$unite
"@
    }
    $shapeContent+=@"

DynamicVariables=1
"@
    $RmAPI.Log('Completed!')
    $shapeContent | Out-File -FilePath $($varPath+'Visualizer.inc')
}