[FirstRightPanel]
Meter=String
Text=First
FontColor=0,0,0,0
MeterStyle=FirstItem | RightPanel
Y=[#s_ScrollRightPanel]
[CategoryIcon4]
Meter=String
Text=[\xE908]
MeterStyle=CategoryIcon | RightPanel

[Title4]
Meter=String
Text=Equalizer Settings 
MeterStyle=CategoryTitle | RightPanel
W=([#s_RightPanelW] - [CategoryIcon4:W])

[CategoryDescription4]
Meter=String
Text=
MeterStyle=VarDescription | ThickDescription | RightPanel

[CategoryTitleSeparator4]
Meter=Image
MeterStyle=CategoryTitleSeparator | RightPanel

[VariableIcon0]
Meter=String
Text=
MeterStyle=VariableIcon | RightPanel
Hidden=
[VariableTitle0]
Meter=String
Text=Attack
MeterStyle=VarTitle | RightPanel
Hidden=
[VariableDescription0]
Meter=String
Text=
MeterStyle=VarDescription | RightPanel
Hidden=
[VariableValue0]
Meter=String
Text=[#Attack]
MeterStyle=VarStringValue | RightPanel
LeftMouseUpAction=[!CommandMeasure "InputText0" "ExecuteBatch All"][!SetOption #CURRENTSECTION# FontColor "0,0,0,0"][!UpdateMeter #CURRENTSECTION#][!Redraw]
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
DefaultValue=[#Attack]
Command1=[!SetVariable "Attack" "$UserInput$"][!WriteKeyValue "Variables" "Attack" "[#Attack]" "#SKINSPATH#ACustomVisualizer\@Resources\GlobalVariables.inc"][#s_OnChangeAction][!Refresh]
OnDismissAction=[!SetOption VariableValue0 FontColor "[#s_FontColor]"][!UpdateMeter VariableValue0][!Redraw]
InputNumber=1

[VariableIcon1]
Meter=String
Text=
MeterStyle=VariableIcon | RightPanel
Hidden=
[VariableTitle1]
Meter=String
Text=Decay
MeterStyle=VarTitle | RightPanel
Hidden=
[VariableDescription1]
Meter=String
Text=
MeterStyle=VarDescription | RightPanel
Hidden=
[VariableValue1]
Meter=String
Text=[#Decay]
MeterStyle=VarStringValue | RightPanel
LeftMouseUpAction=[!CommandMeasure "InputText1" "ExecuteBatch All"][!SetOption #CURRENTSECTION# FontColor "0,0,0,0"][!UpdateMeter #CURRENTSECTION#][!Redraw]
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
DefaultValue=[#Decay]
Command1=[!SetVariable "Decay" "$UserInput$"][!WriteKeyValue "Variables" "Decay" "[#Decay]" "#SKINSPATH#ACustomVisualizer\@Resources\GlobalVariables.inc"][#s_OnChangeAction][!Refresh]
OnDismissAction=[!SetOption VariableValue1 FontColor "[#s_FontColor]"][!UpdateMeter VariableValue1][!Redraw]
InputNumber=1

[VariableIcon2]
Meter=String
Text=
MeterStyle=VariableIcon | RightPanel
Hidden=
[VariableTitle2]
Meter=String
Text=Smoothing
MeterStyle=VarTitle | RightPanel
Hidden=
[VariableDescription2]
Meter=String
Text=
MeterStyle=VarDescription | RightPanel
Hidden=
[VariableValue2]
Meter=String
Text=[#BlurRadius]
MeterStyle=VarStringValue | RightPanel
LeftMouseUpAction=[!CommandMeasure "InputText2" "ExecuteBatch All"][!SetOption #CURRENTSECTION# FontColor "0,0,0,0"][!UpdateMeter #CURRENTSECTION#][!Redraw]
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
DefaultValue=[#BlurRadius]
Command1=[!SetVariable "BlurRadius" "$UserInput$"][!WriteKeyValue "Variables" "BlurRadius" "[#BlurRadius]" "#SKINSPATH#ACustomVisualizer\@Resources\GlobalVariables.inc"][#s_OnChangeAction][!Refresh]
OnDismissAction=[!SetOption VariableValue2 FontColor "[#s_FontColor]"][!UpdateMeter VariableValue2][!Redraw]
InputNumber=1

[VariableIcon3]
Meter=String
Text=
MeterStyle=VariableIcon | RightPanel
Hidden=
[VariableTitle3]
Meter=String
Text=Maximum Sensitivity
MeterStyle=VarTitle | RightPanel
Hidden=
[VariableDescription3]
Meter=String
Text=
MeterStyle=VarDescription | RightPanel
Hidden=
[VariableValue3]
Meter=String
Text=[#MaxSensitivity]
MeterStyle=VarStringValue | RightPanel
LeftMouseUpAction=[!CommandMeasure "InputText3" "ExecuteBatch All"][!SetOption #CURRENTSECTION# FontColor "0,0,0,0"][!UpdateMeter #CURRENTSECTION#][!Redraw]
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
DefaultValue=[#MaxSensitivity]
Command1=[!SetVariable "MaxSensitivity" "$UserInput$"][!WriteKeyValue "Variables" "MaxSensitivity" "[#MaxSensitivity]" "#SKINSPATH#ACustomVisualizer\@Resources\GlobalVariables.inc"][#s_OnChangeAction][!Refresh]
OnDismissAction=[!SetOption VariableValue3 FontColor "[#s_FontColor]"][!UpdateMeter VariableValue3][!Redraw]
InputNumber=1

[VariableIcon4]
Meter=String
Text=
MeterStyle=VariableIcon | RightPanel
Hidden=
[VariableTitle4]
Meter=String
Text=Minimum Sensitivity
MeterStyle=VarTitle | RightPanel
Hidden=
[VariableDescription4]
Meter=String
Text=
MeterStyle=VarDescription | RightPanel
Hidden=
[VariableValue4]
Meter=String
Text=[#MinSensitivity]
MeterStyle=VarStringValue | RightPanel
LeftMouseUpAction=[!CommandMeasure "InputText4" "ExecuteBatch All"][!SetOption #CURRENTSECTION# FontColor "0,0,0,0"][!UpdateMeter #CURRENTSECTION#][!Redraw]
Hidden=
[InputText4]
Measure=Plugin
Plugin=InputText
SolidColor=[#s_RightPanelBackgroundColor]
FontColor=[#s_FontColor]
FontFace=[#s_FontFace]
FontSize=[#s_InputTextFontSize]
Disabled=
X=([VariableValue4:X])
Y=([VariableValue4:Y] + [#s_ValueYPadding])
H=[VariableValue4:H]
W=([#s_RightPanelW] - ([#s_VariableXPadding] * 2))
DynamicVariables=1
DefaultValue=[#MinSensitivity]
Command1=[!SetVariable "MinSensitivity" "$UserInput$"][!WriteKeyValue "Variables" "MinSensitivity" "[#MinSensitivity]" "#SKINSPATH#ACustomVisualizer\@Resources\GlobalVariables.inc"][#s_OnChangeAction][!Refresh]
OnDismissAction=[!SetOption VariableValue4 FontColor "[#s_FontColor]"][!UpdateMeter VariableValue4][!Redraw]
InputNumber=1

[VariableIcon5]
Meter=String
Text=
MeterStyle=VariableIcon | RightPanel
Hidden=
[VariableTitle5]
Meter=String
Text=Window Functions 
MeterStyle=VarTitle | RightPanel
Hidden=
[VariableDescription5]
Meter=String
Text=None : Hann : Kaiser : Hamming : Chebyshev : Exponential
MeterStyle=VarDescription | RightPanel
Hidden=
[VariableVariableValue5]
Meter=String
Text=[#WindowFunction]
MeterStyle=VarStringValue | RightPanel
LeftMouseUpAction=[!CommandMeasure "InputText5" "ExecuteBatch All"][!SetOption #CURRENTSECTION# FontColor "0,0,0,0"][!UpdateMeter #CURRENTSECTION#][!Redraw]
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
DefaultValue=[#WindowFunction]
Command1=[!SetVariable "WindowFunction" "$UserInput$"][!WriteKeyValue "Variables" "WindowFunction" "[#WindowFunction]" "[#s_SettingsFile]"][#s_OnChangeAction][!Refresh]
OnDismissAction=[!SetOption VariableVariableValue5 FontColor "[#s_FontColor]"][!UpdateMeter VariableVariableValue5][!Redraw]

[VariableIcon6]
Meter=String
Text=
MeterStyle=VariableIcon | RightPanel
Hidden=
[VariableTitle6]
Meter=String
Text=Channel
MeterStyle=VarTitle | RightPanel
Hidden=
[VariableDescription6]
Meter=String
Text=
MeterStyle=VarDescription | RightPanel
Hidden=
[VariableVariableValue6]
Meter=String
Text=[#Channel]
MeterStyle=VarStringValue | RightPanel
LeftMouseUpAction=[!CommandMeasure "InputText6" "ExecuteBatch All"][!SetOption #CURRENTSECTION# FontColor "0,0,0,0"][!UpdateMeter #CURRENTSECTION#][!Redraw]
Hidden=
[InputText6]
Measure=Plugin
Plugin=InputText
SolidColor=[#s_RightPanelBackgroundColor]
FontColor=#s_FontColor#
FontFace=#s_FontFace#
FontSize=#s_InputTextFontSize#
Disabled=
X=([VariableVariableValue6:X])
Y=([VariableVariableValue6:Y] + [#s_ValueYPadding])
H=[VariableVariableValue6:H]
W=([#s_RightPanelW] - ([#s_VariableXPadding] * 2))
DynamicVariables=1
DefaultValue=[#Channel]
Command1=[!SetVariable "Channel" "$UserInput$"][!WriteKeyValue "Variables" "Channel" "[#Channel]" "[#s_SettingsFile]"][#s_OnChangeAction][!Refresh]
OnDismissAction=[!SetOption VariableVariableValue6 FontColor "[#s_FontColor]"][!UpdateMeter VariableVariableValue6][!Redraw]

[VariableIcon7]
Meter=String
Text=
MeterStyle=VariableIcon | RightPanel
Hidden=
[VariableTitle7]
Meter=String
Text=UpdateRate
MeterStyle=VarTitle | RightPanel
Hidden=
[VariableDescription7]
Meter=String
Text=
MeterStyle=VarDescription | RightPanel
Hidden=
[VariableValue7]
Meter=String
Text=[#UpdateRate]
MeterStyle=VarStringValue | RightPanel
LeftMouseUpAction=[!CommandMeasure "InputText7" "ExecuteBatch All"][!SetOption #CURRENTSECTION# FontColor "0,0,0,0"][!UpdateMeter #CURRENTSECTION#][!Redraw]
Hidden=
[InputText7]
Measure=Plugin
Plugin=InputText
SolidColor=[#s_RightPanelBackgroundColor]
FontColor=[#s_FontColor]
FontFace=[#s_FontFace]
FontSize=[#s_InputTextFontSize]
Disabled=
X=([VariableValue7:X])
Y=([VariableValue7:Y] + [#s_ValueYPadding])
H=[VariableValue7:H]
W=([#s_RightPanelW] - ([#s_VariableXPadding] * 2))
DynamicVariables=1
DefaultValue=[#UpdateRate]
Command1=[!SetVariable "UpdateRate" "$UserInput$"][!WriteKeyValue "Variables" "UpdateRate" "[#UpdateRate]" "#SKINSPATH#ACustomVisualizer\@Resources\GlobalVariables.inc"][#s_OnChangeAction][!Refresh]
OnDismissAction=[!SetOption VariableValue7 FontColor "[#s_FontColor]"][!UpdateMeter VariableValue7][!Redraw]
InputNumber=1

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

[ScrollUpRightPanel]
Measure=Calc
Formula=[#s_ScrollRightPanel] + [#s_ScrollSpeed]
IfCondition=([FirstRightPanel:Y] < 0)
IfTrueAction=[!SetVariable "s_ScrollRightPanel" "[&ScrollUpRightPanel]"][!DisableMeasure "ScrollUpRightPanel"][!Update][!Redraw]
IfFalseAction=[!DisableMeasure "ScrollUpRightPanel"]
IfConditionMode=1
Disabled=1
DynamicVariables=1


