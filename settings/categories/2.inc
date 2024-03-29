[FirstRightPanel]
Meter=String
Text=First
FontColor=0,0,0,0
MeterStyle=FirstItem | RightPanel
Y=[#s_ScrollRightPanel]
[CategoryIcon2]
Meter=String
Text=[\xE98F]
MeterStyle=CategoryIcon | RightPanel

[Title2]
Meter=String
Text=Group
MeterStyle=CategoryTitle | RightPanel
W=([#s_RightPanelW] - [CategoryIcon2:W])

[VarGroupShape]
Meter=Shape
X=100r
Y=35r
Shape=Rectangle 0,0,100,35,5 | Fill Color [#s_LeftPanelBackgroundColor]
MeterStyle=RightPanel
MouseOverAction=[!PauseMeasureGroup ScrollCat2]
MouseLeaveAction=[!UnpauseMeasureGroup ScrollCat2]
MouseScrollUpAction=[!WriteKeyValue Variables s_VarGroup "(Clamp([#s_VarGroup]+1, 0,[#GroupCount]-1))" "#ROOTCONFIGPATH#settings\includes\Variables.inc"][!Refresh]
MouseScrollDownAction=[!WriteKeyValue Variables s_VarGroup "(Clamp([#s_VarGroup]-1, 0,[#GroupCount]-1))" "#ROOTCONFIGPATH#settings\includes\Variables.inc"][!Refresh]
LeftMouseUpAction=!CommandMeasure InputTextVarGroup "ExecuteBatch All"

[VarGroupTitle]
Meter=String
X=50r
Y=18r
Padding=0,0,0,0
StringAlign=CenterCenter
Text=[#s_VarGroup]
ClipString=2
FontFace=#s_FontFace#
FontWeight=#s_CategoryTitleFontWeight#
FontSize=#s_FontSize1#
DynamicVariables=1
SolidColor=[#s_DebugCategoryTitleColor[#s_DebugColors]] 
FontColor=[#s_FontColor]
AntiAlias=1
MeterStyle=RightPanel

[InputTextVarGroup]
Measure=Plugin
Plugin=InputText
SolidColor=[#s_LeftPanelBackgroundColor]
FontColor=[#s_FontColor]
FontFace=[#s_FontFace]
FontSize=18
StringAlign=Center
Disabled=
X=([VarGroupShape:X]+5)
Y=([VarGroupShape:Y]+2)
H=([VarGroupShape:H]-5)
W=90
DynamicVariables=1
DefaultValue=[#s_VarGroup]
Command1=[!WriteKeyValue "Variables" "s_VarGroup" "(Clamp($UserInput$,0,[#GroupCount]-1))" "#ROOTCONFIGPATH#settings\includes\Variables.inc"][!Refresh]
InputNumber=1

[CategoryDescription2]
Meter=String
Text=
MeterStyle=VarDescription | ThickDescription | RightPanel

[CategoryTitleSeparator2]
Meter=Image
MeterStyle=CategoryTitleSeparator | RightPanel

[VariableIconX]
Meter=String
Text=
MeterStyle=VariableIcon | RightPanel
Hidden=
[VariableTitleX]
Meter=String
Text=BarCount
Y=-20R
MeterStyle=VarTitle | RightPanel
Hidden=
[VariableDescriptionX]
Meter=String
Text=
MeterStyle=VarDescription | RightPanel
Hidden=
[VariableValueX]
Meter=String
Text=[#BarCountG[#s_VarGroup]]
MeterStyle=VarStringValue | RightPanel
LeftMouseUpAction=[!CommandMeasure "InputTextX" "ExecuteBatch All"][!SetOption #CURRENTSECTION# FontColor "0,0,0,0"][!UpdateMeter #CURRENTSECTION#][!Redraw]
Hidden=
[InputTextX]
Measure=Plugin
Plugin=InputText
SolidColor=[#s_RightPanelBackgroundColor]
FontColor=[#s_FontColor]
FontFace=[#s_FontFace]
FontSize=[#s_InputTextFontSize]
Disabled=
X=([VariableValueX:X])
Y=([VariableValueX:Y] + [#s_ValueYPadding])
H=[VariableValueX:H]
W=([#s_RightPanelW] - ([#s_VariableXPadding] * 2))
DynamicVariables=1
DefaultValue=[#BarCountG[#s_VarGroup]]
Command1=[!SetVariable "BarCountG[#s_VarGroup]" "$UserInput$"][!WriteKeyValue "Variables" "BarCountG[#s_VarGroup]" "[#BarCountG[#s_VarGroup]]" "[#s_SettingsFile]"][!CommandMeasure PSRM Change]
OnDismissAction=[!SetOption VariableValueX FontColor "[#s_FontColor]"][!UpdateMeter VariableValueX][!Redraw]
InputNumber=1

[VariableIconZ]
Meter=String
Text=
MeterStyle=VariableIcon | RightPanel
Hidden=
[VariableTitleZ]
Meter=String
Text=MeasureStart
MeterStyle=VarTitle | RightPanel
Hidden=
[VariableDescriptionZ]
Meter=String
Text=
MeterStyle=VarDescription | RightPanel
Hidden=
[VariableValueZ]
Meter=String
Text=[#MeasureStartG[#s_VarGroup]]
MeterStyle=VarStringValue | RightPanel
LeftMouseUpAction=[!CommandMeasure "InputTextZ" "ExecuteBatch All"][!SetOption #CURRENTSECTION# FontColor "0,0,0,0"][!UpdateMeter #CURRENTSECTION#][!Redraw]
Hidden=
[InputTextZ]
Measure=Plugin
Plugin=InputText
SolidColor=[#s_RightPanelBackgroundColor]
FontColor=[#s_FontColor]
FontFace=[#s_FontFace]
FontSize=[#s_InputTextFontSize]
Disabled=
X=([VariableValueZ:X])
Y=([VariableValueZ:Y] + [#s_ValueYPadding])
H=[VariableValueZ:H]
W=([#s_RightPanelW] - ([#s_VariableXPadding] * 2))
DynamicVariables=1
DefaultValue=[#MeasureStartG[#s_VarGroup]]
Command1=[!SetVariable "MeasureStartG[#s_VarGroup]" "(Max(1,$UserInput$))"][!WriteKeyValue "Variables" "MeasureStartG[#s_VarGroup]" "[#MeasureStartG[#s_VarGroup]]" "[#s_SettingsFile]"][!CommandMeasure PSRM Change]
OnDismissAction=[!SetOption VariableValueZ FontColor "[#s_FontColor]"][!UpdateMeter VariableValueZ][!Redraw]
InputNumber=1


[VariableIcon10]
Meter=String
Text=
MeterStyle=VariableIcon | RightPanel
Hidden=
[VariableTitle10]
Meter=String
Text=X
MeterStyle=VarTitle | RightPanel
Hidden=
[VariableDescription10]
Meter=String
Text=
MeterStyle=VarDescription | RightPanel
Hidden=
[VariableValue10]
Meter=String
Text=[#XG[#s_VarGroup]]
MeterStyle=VarStringValue | RightPanel
LeftMouseUpAction=[!CommandMeasure "InputText10" "ExecuteBatch All"][!SetOption #CURRENTSECTION# FontColor "0,0,0,0"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseOverAction=[!PauseMeasureGroup ScrollCat2]
MouseLeaveAction=[!UnpauseMeasureGroup ScrollCat2]
MouseScrollUpAction=[!SetVariable XG[#s_VarGroup] "([#XG[#s_VarGroup]]+1)"][!WriteKeyValue Variables XG[#s_VarGroup] "[#XG[#s_VarGroup]]" "[#s_SettingsFile]"][!UpdateMeter "#CURRENTSECTION#"][!Redraw][#s_OnChangeAction]
MouseScrollDownAction=[!SetVariable XG[#s_VarGroup] "([#XG[#s_VarGroup]]-1)"][!WriteKeyValue Variables XG[#s_VarGroup] "[#XG[#s_VarGroup]]" "[#s_SettingsFile]"][!UpdateMeter "#CURRENTSECTION#"][!Redraw][#s_OnChangeAction]
Hidden=
[InputText10]
Measure=Plugin
Plugin=InputText
SolidColor=[#s_RightPanelBackgroundColor]
FontColor=[#s_FontColor]
FontFace=[#s_FontFace]
FontSize=[#s_InputTextFontSize]
Disabled=
X=([VariableValue10:X])
Y=([VariableValue10:Y] + [#s_ValueYPadding])
H=[VariableValue10:H]
W=([#s_RightPanelW] - ([#s_VariableXPadding] * 2))
DynamicVariables=1
DefaultValue=[#XG[#s_VarGroup]]
Command1=[!SetVariable "XG[#s_VarGroup]" "$UserInput$"][!WriteKeyValue "Variables" "XG[#s_VarGroup]" "[#XG[#s_VarGroup]]" "[#s_SettingsFile]"][#s_OnChangeAction][!Refresh]
OnDismissAction=[!SetOption VariableValue10 FontColor "[#s_FontColor]"][!UpdateMeter VariableValue10][!Redraw]
InputNumber=1

[VariableIcon11]
Meter=String
Text=
MeterStyle=VariableIcon | RightPanel
Hidden=
[VariableTitle11]
Meter=String
Text=Y
MeterStyle=VarTitle | RightPanel
Hidden=
[VariableDescription11]
Meter=String
Text=
MeterStyle=VarDescription | RightPanel
Hidden=
[VariableValue11]
Meter=String
Text=[#YG[#s_VarGroup]]
MeterStyle=VarStringValue | RightPanel
LeftMouseUpAction=[!CommandMeasure "InputText11" "ExecuteBatch All"][!SetOption #CURRENTSECTION# FontColor "0,0,0,0"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseOverAction=[!PauseMeasureGroup ScrollCat2]
MouseLeaveAction=[!UnpauseMeasureGroup ScrollCat2]
MouseScrollUpAction=[!SetVariable YG[#s_VarGroup] "([#YG[#s_VarGroup]]+1)"][!WriteKeyValue Variables YG[#s_VarGroup] "[#YG[#s_VarGroup]]" "[#s_SettingsFile]"][!UpdateMeter "#CURRENTSECTION#"][!Redraw][#s_OnChangeAction]
MouseScrollDownAction=[!SetVariable YG[#s_VarGroup] "([#YG[#s_VarGroup]]-1)"][!WriteKeyValue Variables YG[#s_VarGroup] "[#YG[#s_VarGroup]]" "[#s_SettingsFile]"][!UpdateMeter "#CURRENTSECTION#"][!Redraw][#s_OnChangeAction]
Hidden=
[InputText11]
Measure=Plugin
Plugin=InputText
SolidColor=[#s_RightPanelBackgroundColor]
FontColor=[#s_FontColor]
FontFace=[#s_FontFace]
FontSize=[#s_InputTextFontSize]
Disabled=
X=([VariableValue11:X])
Y=([VariableValue11:Y] + [#s_ValueYPadding])
H=[VariableValue11:H]
W=([#s_RightPanelW] - ([#s_VariableXPadding] * 2))
DynamicVariables=1
DefaultValue=[#YG[#s_VarGroup]]
Command1=[!SetVariable "YG[#s_VarGroup]" "$UserInput$"][!WriteKeyValue "Variables" "YG[#s_VarGroup]" "[#YG[#s_VarGroup]]" "[#s_SettingsFile]"][#s_OnChangeAction][!Refresh]
OnDismissAction=[!SetOption VariableValue11 FontColor "[#s_FontColor]"][!UpdateMeter VariableValue11][!Redraw]
InputNumber=1

[VariableIconA]
Meter=String
Text=
MeterStyle=VariableIcon | RightPanel
Hidden=
[VariableTitleA]
Meter=String
Text=Height
MeterStyle=VarTitle | RightPanel
Hidden=
[VariableDescriptionA]
Meter=String
Text=
MeterStyle=VarDescription | RightPanel
Hidden=
[VariableValueA]
Meter=String
Text=[#HeightG[#s_VarGroup]]
MeterStyle=VarStringValue | RightPanel
LeftMouseUpAction=[!CommandMeasure "InputTextA" "ExecuteBatch All"][!SetOption #CURRENTSECTION# FontColor "0,0,0,0"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseOverAction=[!PauseMeasureGroup ScrollCat2]
MouseLeaveAction=[!UnpauseMeasureGroup ScrollCat2]
MouseScrollUpAction=[!SetVariable HeightG[#s_VarGroup] "(Clamp([#HeightG[#s_VarGroup]]+1, 0,[#HeightG[#s_VarGroup]]+1))"][!WriteKeyValue Variables HeightG[#s_VarGroup] "[#HeightG[#s_VarGroup]]" "[#s_SettingsFile]"][!UpdateMeter "#CURRENTSECTION#"][!Redraw][#s_OnChangeAction]
MouseScrollDownAction=[!SetVariable HeightG[#s_VarGroup] "(Clamp([#HeightG[#s_VarGroup]]-1, 0,[#HeightG[#s_VarGroup]]-1))"][!WriteKeyValue Variables HeightG[#s_VarGroup] "[#HeightG[#s_VarGroup]]" "[#s_SettingsFile]"][!UpdateMeter "#CURRENTSECTION#"][!Redraw][#s_OnChangeAction]
Hidden=
[InputTextA]
Measure=Plugin
Plugin=InputText
SolidColor=[#s_RightPanelBackgroundColor]
FontColor=[#s_FontColor]
FontFace=[#s_FontFace]
FontSize=[#s_InputTextFontSize]
Disabled=
X=([VariableValueA:X])
Y=([VariableValueA:Y] + [#s_ValueYPadding])
H=[VariableValueA:H]
W=([#s_RightPanelW] - ([#s_VariableXPadding] * 2))
DynamicVariables=1
DefaultValue=[#HeightG[#s_VarGroup]]
Command1=[!SetVariable "HeightG[#s_VarGroup]" "$UserInput$"][!WriteKeyValue "Variables" "HeightG[#s_VarGroup]" "[#HeightG[#s_VarGroup]]" "[#s_SettingsFile]"][#s_OnChangeAction][!Refresh]
OnDismissAction=[!SetOption VariableValueA FontColor "[#s_FontColor]"][!UpdateMeter VariableValueA][!Redraw]
InputNumber=1


[VariableIcon0]
Meter=String
Text=
MeterStyle=VariableIcon | RightPanel
Hidden=
[VariableTitle0]
Meter=String
Text=Width
MeterStyle=VarTitle | RightPanel
Hidden=
[VariableDescription0]
Meter=String
Text=
MeterStyle=VarDescription | RightPanel
Hidden=
[VariableValue0]
Meter=String
Text=[#WidthG[#s_VarGroup]]
MeterStyle=VarStringValue | RightPanel
LeftMouseUpAction=[!CommandMeasure "InputText0" "ExecuteBatch All"][!SetOption #CURRENTSECTION# FontColor "0,0,0,0"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseOverAction=[!PauseMeasureGroup ScrollCat2]
MouseLeaveAction=[!UnpauseMeasureGroup ScrollCat2]
MouseScrollUpAction=[!SetVariable WidthG[#s_VarGroup] "(Clamp([#WidthG[#s_VarGroup]]+1, 0,[#WidthG[#s_VarGroup]]+1))"][!WriteKeyValue Variables WidthG[#s_VarGroup] "[#WidthG[#s_VarGroup]]" "[#s_SettingsFile]"][!UpdateMeter "#CURRENTSECTION#"][!Redraw][#s_OnChangeAction]
MouseScrollDownAction=[!SetVariable WidthG[#s_VarGroup] "(Clamp([#WidthG[#s_VarGroup]]-1, 0,[#WidthG[#s_VarGroup]]-1))"][!WriteKeyValue Variables WidthG[#s_VarGroup] "[#WidthG[#s_VarGroup]]" "[#s_SettingsFile]"][!UpdateMeter "#CURRENTSECTION#"][!Redraw][#s_OnChangeAction]
Hidden=
[InputText0]
Measure=Plugin
Plugin=InputText
SolidColor=[#s_RightPanelBackgroundColor]
FontColor=[#s_FontColor]
FontFace=[#s_FontFace]
FontSize=[#s_InputTextFontSize]
Disabled=
X=([VariableValue0:X])
Y=([VariableValue0:Y] + [#s_ValueYPadding])
H=[VariableValue0:H]
W=([#s_RightPanelW] - ([#s_VariableXPadding] * 2))
DynamicVariables=1
DefaultValue=[#WidthG[#s_VarGroup]]
Command1=[!SetVariable "WidthG[#s_VarGroup]" "$UserInput$"][!WriteKeyValue "Variables" "WidthG[#s_VarGroup]" "[#WidthG[#s_VarGroup]]" "[#s_SettingsFile]"][#s_OnChangeAction][!Refresh]
OnDismissAction=[!SetOption VariableValue0 FontColor "[#s_FontColor]"][!UpdateMeter VariableValue0][!Redraw]
InputNumber=1

[VariableIcon1]
Meter=String
Text=
MeterStyle=VariableIcon | RightPanel
Hidden=
[VariableTitle1]
Meter=String
Text=Gap
MeterStyle=VarTitle | RightPanel
Hidden=
[VariableDescription1]
Meter=String
Text=
MeterStyle=VarDescription | RightPanel
Hidden=
[VariableValue1]
Meter=String
Text=[#GapG[#s_VarGroup]]
MeterStyle=VarStringValue | RightPanel
LeftMouseUpAction=[!CommandMeasure "InputText1" "ExecuteBatch All"][!SetOption #CURRENTSECTION# FontColor "0,0,0,0"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseOverAction=[!PauseMeasureGroup ScrollCat2]
MouseLeaveAction=[!UnpauseMeasureGroup ScrollCat2]
MouseScrollUpAction=[!SetVariable GapG[#s_VarGroup] "(Clamp([#GapG[#s_VarGroup]]+1, 0,[#GapG[#s_VarGroup]]+1))"][!WriteKeyValue Variables GapG[#s_VarGroup] "[#GapG[#s_VarGroup]]" "[#s_SettingsFile]"][!UpdateMeter "#CURRENTSECTION#"][!Redraw][#s_OnChangeAction]
MouseScrollDownAction=[!SetVariable GapG[#s_VarGroup] "(Clamp([#GapG[#s_VarGroup]]-1, 0,[#GapG[#s_VarGroup]]-1))"][!WriteKeyValue Variables GapG[#s_VarGroup] "[#GapG[#s_VarGroup]]" "[#s_SettingsFile]"][!UpdateMeter "#CURRENTSECTION#"][!Redraw][#s_OnChangeAction]
Hidden=
[InputText1]
Measure=Plugin
Plugin=InputText
SolidColor=[#s_RightPanelBackgroundColor]
FontColor=[#s_FontColor]
FontFace=[#s_FontFace]
FontSize=[#s_InputTextFontSize]
Disabled=
X=([VariableValue1:X])
Y=([VariableValue1:Y] + [#s_ValueYPadding])
H=[VariableValue1:H]
W=([#s_RightPanelW] - ([#s_VariableXPadding] * 2))
DynamicVariables=1
DefaultValue=[#GapG[#s_VarGroup]]
Command1=[!SetVariable "GapG[#s_VarGroup]" "$UserInput$"][!WriteKeyValue "Variables" "GapG[#s_VarGroup]" "[#GapG[#s_VarGroup]]" "[#s_SettingsFile]"][#s_OnChangeAction][!Refresh]
OnDismissAction=[!SetOption VariableValue1 FontColor "[#s_FontColor]"][!UpdateMeter VariableValue1][!Redraw]
InputNumber=1

[VariableIcon2]
Meter=String
Text=
MeterStyle=VariableIcon | RightPanel
Hidden=
[VariableTitle2]
Meter=String
Text=StrokeWidth
MeterStyle=VarTitle | RightPanel
Hidden=
[VariableDescription2]
Meter=String
Text=
MeterStyle=VarDescription | RightPanel
Hidden=
[VariableValue2]
Meter=String
Text=[#StrokeWidthG[#s_VarGroup]]
MeterStyle=VarStringValue | RightPanel
LeftMouseUpAction=[!CommandMeasure "InputText2" "ExecuteBatch All"][!SetOption #CURRENTSECTION# FontColor "0,0,0,0"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseOverAction=[!PauseMeasureGroup ScrollCat2]
MouseLeaveAction=[!UnpauseMeasureGroup ScrollCat2]
MouseScrollUpAction=[!SetVariable StrokeWidthG[#s_VarGroup] "(Clamp([#StrokeWidthG[#s_VarGroup]]+1, 0,[#StrokeWidthG[#s_VarGroup]]+1))"][!WriteKeyValue Variables StrokeWidthG[#s_VarGroup] "[#StrokeWidthG[#s_VarGroup]]" "[#s_SettingsFile]"][!UpdateMeter "#CURRENTSECTION#"][!Redraw][#s_OnChangeAction]
MouseScrollDownAction=[!SetVariable StrokeWidthG[#s_VarGroup] "(Clamp([#StrokeWidthG[#s_VarGroup]]-1, 0,[#StrokeWidthG[#s_VarGroup]]-1))"][!WriteKeyValue Variables StrokeWidthG[#s_VarGroup] "[#StrokeWidthG[#s_VarGroup]]" "[#s_SettingsFile]"][!UpdateMeter "#CURRENTSECTION#"][!Redraw][#s_OnChangeAction]
Hidden=
[InputText2]
Measure=Plugin
Plugin=InputText
SolidColor=[#s_RightPanelBackgroundColor]
FontColor=[#s_FontColor]
FontFace=[#s_FontFace]
FontSize=[#s_InputTextFontSize]
Disabled=
X=([VariableValue2:X])
Y=([VariableValue2:Y] + [#s_ValueYPadding])
H=[VariableValue2:H]
W=([#s_RightPanelW] - ([#s_VariableXPadding] * 2))
DynamicVariables=1
DefaultValue=[#StrokeWidthG[#s_VarGroup]]
Command1=[!SetVariable "StrokeWidthG[#s_VarGroup]" "$UserInput$"][!WriteKeyValue "Variables" "StrokeWidthG[#s_VarGroup]" "[#StrokeWidthG[#s_VarGroup]]" "[#s_SettingsFile]"][#s_OnChangeAction][!Refresh]
OnDismissAction=[!SetOption VariableValue2 FontColor "[#s_FontColor]"][!UpdateMeter VariableValue2][!Redraw]
InputNumber=1

[VariableIcon3]
Meter=String
Text=
MeterStyle=VariableIcon | RightPanel
Hidden=
[VariableTitle3]
Meter=String
Text=Rounding
MeterStyle=VarTitle | RightPanel
Hidden=
[VariableDescription3]
Meter=String
Text=
MeterStyle=VarDescription | RightPanel
Hidden=
[VariableValue3]
Meter=String
Text=[#RoundingG[#s_VarGroup]]
MeterStyle=VarStringValue | RightPanel
LeftMouseUpAction=[!CommandMeasure "InputText3" "ExecuteBatch All"][!SetOption #CURRENTSECTION# FontColor "0,0,0,0"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseOverAction=[!PauseMeasureGroup ScrollCat2]
MouseLeaveAction=[!UnpauseMeasureGroup ScrollCat2]
MouseScrollUpAction=[!SetVariable RoundingG[#s_VarGroup] "(Clamp([#RoundingG[#s_VarGroup]]+1, 0,[#RoundingG[#s_VarGroup]]+1))"][!WriteKeyValue Variables RoundingG[#s_VarGroup] "[#RoundingG[#s_VarGroup]]" "[#s_SettingsFile]"][!UpdateMeter "#CURRENTSECTION#"][!Redraw][#s_OnChangeAction]
MouseScrollDownAction=[!SetVariable RoundingG[#s_VarGroup] "(Clamp([#RoundingG[#s_VarGroup]]-1, 0,[#RoundingG[#s_VarGroup]]-1))"][!WriteKeyValue Variables RoundingG[#s_VarGroup] "[#RoundingG[#s_VarGroup]]" "[#s_SettingsFile]"][!UpdateMeter "#CURRENTSECTION#"][!Redraw][#s_OnChangeAction]
Hidden=
[InputText3]
Measure=Plugin
Plugin=InputText
SolidColor=[#s_RightPanelBackgroundColor]
FontColor=[#s_FontColor]
FontFace=[#s_FontFace]
FontSize=[#s_InputTextFontSize]
Disabled=
X=([VariableValue3:X])
Y=([VariableValue3:Y] + [#s_ValueYPadding])
H=[VariableValue3:H]
W=([#s_RightPanelW] - ([#s_VariableXPadding] * 2))
DynamicVariables=1
DefaultValue=[#RoundingG[#s_VarGroup]]
Command1=[!SetVariable "RoundingG[#s_VarGroup]" "$UserInput$"][!WriteKeyValue "Variables" "RoundingG[#s_VarGroup]" "[#RoundingG[#s_VarGroup]]" "[#s_SettingsFile]"][#s_OnChangeAction][!Refresh]
OnDismissAction=[!SetOption VariableValue3 FontColor "[#s_FontColor]"][!UpdateMeter VariableValue3][!Redraw]
InputNumber=1

[VariableIcon5]
Meter=String
Text=
MeterStyle=VariableIcon | RightPanel
Hidden=
[VariableTitle5]
Meter=String
Text=Angle
MeterStyle=VarTitle | RightPanel
Hidden=
[VariableDescription5]
Meter=String
Text=
MeterStyle=VarDescription | RightPanel
Hidden=
[VariableVariableValue5]
Meter=String
Text=[#AngleG[#s_VarGroup]]
MeterStyle=VarStringValue | RightPanel
LeftMouseUpAction=[!CommandMeasure "InputText5" "ExecuteBatch All"][!SetOption #CURRENTSECTION# FontColor "0,0,0,0"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseOverAction=[!PauseMeasureGroup ScrollCat2]
MouseLeaveAction=[!UnpauseMeasureGroup ScrollCat2]
MouseScrollUpAction=[!SetVariable AngleG[#s_VarGroup] "(Clamp([#AngleG[#s_VarGroup]]+1, -360,360))"][!WriteKeyValue Variables AngleG[#s_VarGroup] "[#AngleG[#s_VarGroup]]" "[#s_SettingsFile]"][!UpdateMeter "#CURRENTSECTION#"][!Redraw][#s_OnChangeAction]
MouseScrollDownAction=[!SetVariable AngleG[#s_VarGroup] "(Clamp([#AngleG[#s_VarGroup]]-1, -360,360))"][!WriteKeyValue Variables AngleG[#s_VarGroup] "[#AngleG[#s_VarGroup]]" "[#s_SettingsFile]"][!UpdateMeter "#CURRENTSECTION#"][!Redraw][#s_OnChangeAction]
Hidden=
[InputText5]
Measure=Plugin
Plugin=InputText
SolidColor=[#s_RightPanelBackgroundColor]
FontColor=#s_FontColor#
FontFace=#s_FontFace#
FontSize=#s_InputTextFontSize#
Disabled=
X=([VariableVariableValue5:X])
Y=([VariableVariableValue5:Y] + [#s_ValueYPadding])
H=[VariableVariableValue5:H]
W=([#s_RightPanelW] - ([#s_VariableXPadding] * 2))
DynamicVariables=1
DefaultValue=
Command1=[!SetVariable "AngleG[#s_VarGroup]" "(Clamp($UserInput$, -360, 360))"][!WriteKeyValue "Variables" "AngleG[#s_VarGroup]" "[#AngleG[#s_VarGroup]]" "[#s_SettingsFile]"][#s_OnChangeAction][!Refresh]
OnDismissAction=[!SetOption VariableVariableValue5 FontColor "[#s_FontColor]"][!UpdateMeter VariableVariableValue5][!Redraw]

[VariableIcon6]
Meter=String
Text=
MeterStyle=VariableIcon | RightPanel
Hidden=
[VariableTitle6]
Meter=String
Text=Minimum Height
MeterStyle=VarTitle | RightPanel
Hidden=
[VariableDescription6]
Meter=String
Text=
MeterStyle=VarDescription | RightPanel
Hidden=
[VariableValue6]
Meter=String
Text=[#MinimumHeightG[#s_VarGroup]]
MeterStyle=VarStringValue | RightPanel
LeftMouseUpAction=[!CommandMeasure "InputText6" "ExecuteBatch All"][!SetOption #CURRENTSECTION# FontColor "0,0,0,0"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseOverAction=[!PauseMeasureGroup ScrollCat2]
MouseLeaveAction=[!UnpauseMeasureGroup ScrollCat2]
MouseScrollUpAction=[!SetVariable MinimumHeightG[#s_VarGroup] "(Clamp([#MinimumHeightG[#s_VarGroup]]+1, 0,[#MinimumHeightG[#s_VarGroup]]+1))"][!WriteKeyValue Variables MinimumHeightG[#s_VarGroup] "[#MinimumHeightG[#s_VarGroup]]" "[#s_SettingsFile]"][!UpdateMeter "#CURRENTSECTION#"][!Redraw][#s_OnChangeAction]
MouseScrollDownAction=[!SetVariable MinimumHeightG[#s_VarGroup] "(Clamp([#MinimumHeightG[#s_VarGroup]]-1, 0,[#MinimumHeightG[#s_VarGroup]]-1))"][!WriteKeyValue Variables MinimumHeightG[#s_VarGroup] "[#MinimumHeightG[#s_VarGroup]]" "[#s_SettingsFile]"][!UpdateMeter VariableValue6][!Redraw][#s_OnChangeAction]
Hidden=
[InputText6]
Measure=Plugin
Plugin=InputText
SolidColor=[#s_RightPanelBackgroundColor]
FontColor=[#s_FontColor]
FontFace=[#s_FontFace]
FontSize=[#s_InputTextFontSize]
Disabled=
X=([VariableValue6:X])
Y=([VariableValue6:Y] + [#s_ValueYPadding])
H=[VariableValue6:H]
W=([#s_RightPanelW] - ([#s_VariableXPadding] * 2))
DynamicVariables=1
DefaultValue=[#MinimumHeightG[#s_VarGroup]]
Command1=[!SetVariable "MinimumHeightG[#s_VarGroup]" "$UserInput$"][!WriteKeyValue "Variables" "MinimumHeightG[#s_VarGroup]" "[#MinimumHeightG[#s_VarGroup]]" "[#s_SettingsFile]"][#s_OnChangeAction][!Refresh]
OnDismissAction=[!SetOption VariableValue6 FontColor "[#s_FontColor]"][!UpdateMeter VariableValue6][!Redraw]
InputNumber=1

[VariableIcon4]
Meter=String
Text=
MeterStyle=VariableIcon | RightPanel
Hidden=
[VariableTitle4]
Meter=String
Text=X-Flip 
MeterStyle=VarTitle | RightPanel
[VariableDescription4]
Meter=String
Text=Flips the visualizer wrt Y-axis
MeterStyle=VarDescription | RightPanel

[ToggleOff4]
Meter=Shape
Shape=Line 0,0,([#s_ToggleLength]),0 | Extend Line
Shape2=Ellipse ([#s_TogglePadding]/2),0,(([#s_ToggleSize] - ([#s_TogglePadding] * 2))/2),(([#s_ToggleSize] - ([#s_TogglePadding] * 2))/2) | Extend Circle
Circle=StrokeWidth 0 | Fill Color [#s_RightPanelBackgroundColor]
Line=StrokeWidth [#s_ToggleSize] | Stroke Color [#s_FontColor] | StrokeStartCap Round | StrokeEndCap Round
Hidden=([#XFlipG[#s_VarGroup]])
Y=([VariableDescription4:Y] + [VariableDescription4:H] + ([#s_ToggleSize] / 2) + [#s_ValueYPadding])
MeterStyle=VarToggleValue | RightPanel
LeftMouseUpAction=[!WriteKeyValue Variables "XFlipG[#s_VarGroup]" 1 "[#s_SettingsFile]"][!SetVariable "XFlipG[#s_VarGroup]" 1][!Update][!Redraw][!CommandMeasure PSRM Change]

[ToggleOn4]
Meter=Shape
Shape=Line 0,0,([#s_ToggleLength]),0 | Extend Line
Shape2=Ellipse (([#s_ToggleLength]) - ([#s_TogglePadding]/2)),0,(([#s_ToggleSize] - ([#s_TogglePadding] * 2))/2),(([#s_ToggleSize] - ([#s_TogglePadding] * 2))/2) | Extend Circle
Circle=StrokeWidth 0 | Fill Color [#s_RightPanelBackgroundColor]
Line=StrokeWidth [#s_ToggleSize] | Stroke Color [#s_ToggleActiveColor] | StrokeStartCap Round | StrokeEndCap Round
Hidden=([#XFlipG[#s_VarGroup]] - 1)
Y=([VariableDescription4:Y] + [VariableDescription4:H] + ([#s_ToggleSize] / 2) + [#s_ValueYPadding])
MeterStyle=VarToggleValue | RightPanel
LeftMouseUpAction=[!WriteKeyValue Variables "XFlipG[#s_VarGroup]" 0 "[#s_SettingsFile]"][!SetVariable "XFlipG[#s_VarGroup]" 0][!Update][!Redraw][!CommandMeasure PSRM Change]

[ClearFloat4]
Meter=Image
W=[#s_RightPanelW]
H=([#s_ValueYPadding] + [#s_ToggleSize] + [#s_ValueYPadding])
MeterStyle=RightPanel
Y=([VariableDescription4:Y] + [VariableDescription4:H])
DynamicVariables=1


[VariableIcon9]
Meter=String
Text=
MeterStyle=VariableIcon | RightPanel
Hidden=
[VariableTitle9]
Meter=String
Text=Gradient Toggle
MeterStyle=VarTitle | RightPanel
[VariableDescription9]
Meter=String
Text=Turn on to use gradient**
MeterStyle=VarDescription | RightPanel

[ToggleOff9]
Meter=Shape
Shape=Line 0,0,([#s_ToggleLength]),0 | Extend Line
Shape2=Ellipse ([#s_TogglePadding]/2),0,(([#s_ToggleSize] - ([#s_TogglePadding] * 2))/2),(([#s_ToggleSize] - ([#s_TogglePadding] * 2))/2) | Extend Circle
Circle=StrokeWidth 0 | Fill Color [#s_RightPanelBackgroundColor]
Line=StrokeWidth [#s_ToggleSize] | Stroke Color [#s_FontColor] | StrokeStartCap Round | StrokeEndCap Round
Hidden=([#GradientBoolG[#s_VarGroup]])
Y=([VariableDescription9:Y] + [VariableDescription9:H] + ([#s_ToggleSize] / 2) + [#s_ValueYPadding])
MeterStyle=VarToggleValue | RightPanel
LeftMouseUpAction=[!WriteKeyValue Variables "GradientBoolG[#s_VarGroup]" 1 "[#s_SettingsFile]"][!SetVariable "GradientBoolG[#s_VarGroup]" 1][!Update][!Redraw][#s_OnChangeAction]

[ToggleOn9]
Meter=Shape
Shape=Line 0,0,([#s_ToggleLength]),0 | Extend Line
Shape2=Ellipse (([#s_ToggleLength]) - ([#s_TogglePadding]/2)),0,(([#s_ToggleSize] - ([#s_TogglePadding] * 2))/2),(([#s_ToggleSize] - ([#s_TogglePadding] * 2))/2) | Extend Circle
Circle=StrokeWidth 0 | Fill Color [#s_RightPanelBackgroundColor]
Line=StrokeWidth [#s_ToggleSize] | Stroke Color [#s_ToggleActiveColor] | StrokeStartCap Round | StrokeEndCap Round
Hidden=([#GradientBoolG[#s_VarGroup]] - 1)
Y=([VariableDescription9:Y] + [VariableDescription9:H] + ([#s_ToggleSize] / 2) + [#s_ValueYPadding])
MeterStyle=VarToggleValue | RightPanel
LeftMouseUpAction=[!WriteKeyValue Variables "GradientBoolG[#s_VarGroup]" 0 "[#s_SettingsFile]"][!SetVariable "GradientBoolG[#s_VarGroup]" 0][!Update][!Redraw][#s_OnChangeAction]

[ClearFloat9]
Meter=Image
W=[#s_RightPanelW]
H=([#s_ValueYPadding] + [#s_ToggleSize] + [#s_ValueYPadding])
MeterStyle=RightPanel
Y=([VariableDescription9:Y] + [VariableDescription9:H])
DynamicVariables=1


[VariableIcon7]
Meter=String
Text=
MeterStyle=VariableIcon | RightPanel
Hidden=([#GradientBoolG[#s_VarGroup]])
[VariableTitle7Title]
Meter=String
Text=Color
MeterStyle=VarTitle | RightPanel
Hidden=([#GradientBoolG[#s_VarGroup]])
[VariableDescription7]
Meter=String
Text=
MeterStyle=VarDescription | RightPanel
Hidden=([#GradientBoolG[#s_VarGroup]])
[ColorVariableValue7]
Meter=Shape
Shape=Ellipse [#s_ColorSize],[#s_ColorSize],[#s_ColorSize],[#s_ColorSize] | Fill Color [#ColorG[#s_VarGroup]] | StrokeWidth [#s_ColorStrokeWidth] | Extend Outline
Outline=Stroke Color [#s_ColorStrokeColor]
MeterStyle=VarColorValue | RightPanel
LeftMouseUpAction=[!CommandMeasure "RainRGB7" "Run"]
Hidden=([#GradientBoolG[#s_VarGroup]])
[StringVariableValue7]
Meter=String
Text=[#ColorG[#s_VarGroup]]
MeterStyle=VarStringValue | VarColorString | RightPanel
LeftMouseUpAction=[!CommandMeasure "RainRGB7" "Run"]
Hidden=([#GradientBoolG[#s_VarGroup]])
[RainRGB7]
Measure=Plugin
Plugin=RunCommand
Disabled=
Program=""#CURRENTPATH#addons\RainRGB4RunCommand.exe""
Parameter=""VarName=ColorG[#s_VarGroup]" "FileName=#SKINSPATH#ACustomVisualizer\@Resources\Variables\Variable#s_VarGroup#.inc" "RefreshConfig=-1""
OutputType=ANSI
FinishAction=[!Refresh][#s_OnChangeAction]
[VariableIcon8]
Meter=String
Text=
MeterStyle=VariableIcon | RightPanel
Hidden=([#GradientBoolG[#s_VarGroup]] - 1)
[VariableTitle8]
Meter=String
Text=Gradient 
MeterStyle=VarTitle | RightPanel
Hidden=([#GradientBoolG[#s_VarGroup]] - 1)
[VariableDescription8]
Meter=String
Text=
MeterStyle=VarDescription | RightPanel
Hidden=([#GradientBoolG[#s_VarGroup]] - 1)
[VariableVariableValue8]
Meter=String
Text=[#GradientG[#s_VarGroup]]
MeterStyle=VarStringValue | RightPanel
LeftMouseUpAction=[!CommandMeasure "InputText8" "ExecuteBatch All"][!SetOption #CURRENTSECTION# FontColor "0,0,0,0"][!UpdateMeter #CURRENTSECTION#][!Redraw]
Hidden=([#GradientBoolG[#s_VarGroup]] - 1)
[InputText8]
Measure=Plugin
Plugin=InputText
SolidColor=[#s_RightPanelBackgroundColor]
FontColor=#s_FontColor#
FontFace=#s_FontFace#
FontSize=#s_InputTextFontSize#
Disabled=
X=([VariableVariableValue8:X])
Y=([VariableVariableValue8:Y] + [#s_ValueYPadding])
H=[VariableVariableValue8:H]
W=([#s_RightPanelW] - ([#s_VariableXPadding] * 2))
DynamicVariables=1
DefaultValue=[#GradientG[#s_VarGroup]]
Command1=[!SetVariable "GradientG[#s_VarGroup]" "$UserInput$"][!WriteKeyValue "Variables" "GradientG[#s_VarGroup]" "[#GradientG[#s_VarGroup]]" "[#s_SettingsFile]"][#s_OnChangeAction][!Refresh]
OnDismissAction=[!SetOption VariableVariableValue8 FontColor "[#s_FontColor]"][!UpdateMeter VariableVariableValue8][!Redraw]



[LastRightPanel]
Meter=String
Text=Last
FontColor=255,0,0,0
MeterStyle=LastItem | RightPanel

[ScrollDownRightPanel]
Measure=Calc
Formula=[#s_ScrollRightPanel] - [#s_ScrollSpeed]
IfCondition=([LastRightPanel:Y] > [#s_ScrollTreshold])
IfTrueAction=[!SetVariable "s_ScrollRightPanel" "[&ScrollDownRightPanel]"][!DisableMeasure "ScrollDownRightPanel"][!Update][!Redraw]
IfFalseAction=[!DisableMeasure "ScrollDownRightPanel"]
IfConditionMode=1
Disabled=1
DynamicVariables=1
Group=ScrollCat2

[ScrollUpRightPanel]
Measure=Calc
Formula=[#s_ScrollRightPanel] + [#s_ScrollSpeed]
IfCondition=([FirstRightPanel:Y] < 0)
IfTrueAction=[!SetVariable "s_ScrollRightPanel" "[&ScrollUpRightPanel]"][!DisableMeasure "ScrollUpRightPanel"][!Update][!Redraw]
IfFalseAction=[!DisableMeasure "ScrollUpRightPanel"]
IfConditionMode=1
Disabled=1
DynamicVariables=1
Group=ScrollCat2


