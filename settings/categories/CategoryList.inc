[FirstLeftPanel]
Meter=String
Text=First
FontColor=0,0,0,0
MeterStyle=FirstItem | LeftPanel
Y=[#s_ScrollLeftPanel]
[ListIcon0]
Meter=String
Text=[\xE713]
Y=[#s_ListAboutTopPadding]R
MeterStyle=ListIcon | ListAboutIcon | LeftPanel
LeftMouseUpAction=[!WriteKeyValue Variables s_CurrentCategory 0 "#ROOTCONFIGPATH#settings\includes\Variables.inc"][!Refresh]
[ListItem0]
Meter=String
Text=Settings 
MeterStyle=ListItem | ListAboutItem | LeftPanel
W=([#s_LeftPanelW] - ([ListIcon0:W] + [#s_ListRightPadding]))
FontWeight=([#s_CurrentCategory] = 0) ? [#s_SelectedFontWeight] : [#s_VariableTitleFontWeight]
LeftMouseUpAction=[!WriteKeyValue Variables s_CurrentCategory 0 "#ROOTCONFIGPATH#settings\includes\Variables.inc"][!Refresh]
ToolTipTitle=Settings 
ToolTipText=

[ListIcon1]
Meter=String
Text=[\xF61F]
MeterStyle=ListIcon | ListTopicIcon | LeftPanel
[ListItem1]
Meter=String
Text=Visualizer Settings 
MeterStyle=ListItem | ListTopicItem | LeftPanel
W=([#s_LeftPanelW] - ([ListIcon1:W] + [#s_ListRightPadding]))
FontWeight=([#s_CurrentCategory] = 1) ? [#s_SelectedFontWeight] : [#s_FontWeight]
ToolTipTitle=Visualizer Settings 
ToolTipText=

[ListIcon2]
Meter=String
Text=[\xE98F]
MeterStyle=ListIcon | ListDefaultIcon | LeftPanel
LeftMouseUpAction=[!WriteKeyValue Variables s_CurrentCategory 2 "#ROOTCONFIGPATH#settings\includes\Variables.inc"][!Refresh]
[ListItem2]
Meter=String
Text=Group[#s_VarGroup]
MeterStyle=ListItem | ListDefaultItem | LeftPanel
W=([#s_LeftPanelW] - ([ListIcon2:W] + [#s_ListRightPadding]))
FontWeight=([#s_CurrentCategory] = 2) ? [#s_SelectedFontWeight] : [#s_FontWeight]
LeftMouseUpAction=[!WriteKeyValue Variables s_CurrentCategory 2 "#ROOTCONFIGPATH#settings\includes\Variables.inc"][!Refresh]
ToolTipTitle=Group[#s_VarGroup]
ToolTipText=

[ListIcon3]
Meter=String
Text=[\xF0ED]
MeterStyle=ListIcon | ListTopicIcon | LeftPanel
[ListItem3]
Meter=String
Text=Audio Analyzer 
MeterStyle=ListItem | ListTopicItem | LeftPanel
W=([#s_LeftPanelW] - ([ListIcon3:W] + [#s_ListRightPadding]))
FontWeight=([#s_CurrentCategory] = 3) ? [#s_SelectedFontWeight] : [#s_FontWeight]
ToolTipTitle=Audio Analyzer 
ToolTipText=

[ListIcon4]
Meter=String
Text=[\xF4C3]
MeterStyle=ListIcon | ListDefaultIcon | LeftPanel
LeftMouseUpAction=[!WriteKeyValue Variables s_CurrentCategory 4 "#ROOTCONFIGPATH#settings\includes\Variables.inc"][!Refresh]
[ListItem4]
Meter=String
Text=Equalizer Settings 
MeterStyle=ListItem | ListDefaultItem | LeftPanel
W=([#s_LeftPanelW] - ([ListIcon4:W] + [#s_ListRightPadding]))
FontWeight=([#s_CurrentCategory] = 4) ? [#s_SelectedFontWeight] : [#s_FontWeight]
LeftMouseUpAction=[!WriteKeyValue Variables s_CurrentCategory 4 "#ROOTCONFIGPATH#settings\includes\Variables.inc"][!Refresh]
ToolTipTitle=Equalizer Settings 
ToolTipText=


[ListIcon5]
Meter=String
Text=[\xE95B]
MeterStyle=ListIcon | ListDefaultIcon | LeftPanel
LeftMouseUpAction=[!WriteKeyValue Variables s_CurrentCategory 5 "#ROOTCONFIGPATH#settings\includes\Variables.inc"][!Refresh]
[ListItem5]
Meter=String
Text=Device 
MeterStyle=ListItem | ListDefaultItem | LeftPanel
W=([#s_LeftPanelW] - ([ListIcon5:W] + [#s_ListRightPadding]))
FontWeight=([#s_CurrentCategory] = 5) ? [#s_SelectedFontWeight] : [#s_FontWeight]
LeftMouseUpAction=[!WriteKeyValue Variables s_CurrentCategory 5 "#ROOTCONFIGPATH#settings\includes\Variables.inc"][!Refresh]
ToolTipTitle=Device 
ToolTipText=

[ListIcon6]
Meter=String
Text=[\xE835]
MeterStyle=ListIcon | ListTopicIcon | LeftPanel
[ListItem6]
Meter=String
Text=Generator 
MeterStyle=ListItem | ListTopicItem | LeftPanel
W=([#s_LeftPanelW] - ([ListIcon1:W] + [#s_ListRightPadding]))
FontWeight=([#s_CurrentCategory] = 1) ? [#s_SelectedFontWeight] : [#s_FontWeight]
ToolTipTitle=Visualizer Settings 
ToolTipText=

[ListIcon7]
Meter=String
Text=[\xF159]
MeterStyle=ListIcon | ListDefaultIcon | LeftPanel
LeftMouseUpAction=[!WriteKeyValue Variables s_CurrentCategory 5 "#ROOTCONFIGPATH#settings\includes\Variables.inc"][!Refresh]
[ListItem7]
Meter=String
Text=GroupCount
MeterStyle=ListItem | ListDefaultItem | LeftPanel
W=([#s_LeftPanelW] - ([ListIcon5:W] + [#s_ListRightPadding]))
FontWeight=([#s_CurrentCategory] = 5) ? [#s_SelectedFontWeight] : [#s_FontWeight]
ToolTipTitle=Device 
ToolTipText=


[VariableValueY]
Meter=String
X=r
Y=-10R
Text=[#GroupCount]
FontSize=15
MeterStyle=VarStringValue | LeftPanel
LeftMouseUpAction=[!CommandMeasure "InputTextY" "ExecuteBatch All"][!SetOption #CURRENTSECTION# FontColor "0,0,0,0"][!UpdateMeter #CURRENTSECTION#][!Redraw]
Hidden=
[InputTextY]
Measure=Plugin
Plugin=InputText
SolidColor=[#s_LeftPanelBackgroundColor]
FontColor=[#s_FontColor]
FontFace=[#s_FontFace]
FontSize=14
Disabled=
X=([VariableValueY:X])
Y=([VariableValueY:Y] + [#s_ValueYPadding])
H=[VariableValueY:H]
W=([#s_LeftPanelW]-[VariableValueY:X])
DynamicVariables=1
DefaultValue=[#GroupCount]
Command1=[!SetVariable "GroupCount" "(Max(0,$UserInput$))"][!WriteKeyValue "Variables" "GroupCount" "[#GroupCount]" "#@#GlobalVariables.inc"][!CommandMeasure PSRM Craft]
OnDismissAction=[!SetOption VariableValueY FontColor "[#s_FontColor]"][!UpdateMeter VariableValueY][!Redraw]
InputNumber=1

[ListIcon8]
Meter=String
Text=[\xE70F]
MeterStyle=ListIcon | ListDefaultIcon | LeftPanel
LeftMouseUpAction=[!CommandMeasure PSRM EnterEditMode]
Hidden=[#EditMode]
[ListIcon82]
Meter=String
Text=[\xED2E]
Y=r
MeterStyle=ListIcon | ListDefaultIcon | LeftPanel
Hidden=[#EditMode]
LeftMouseUpAction=[!CommandMeasure PSRM EnterEditMode]
[ListItem8]
Meter=String
Text=EditMode: Off
MeterStyle=ListItem | ListDefaultItem | LeftPanel
W=([#s_LeftPanelW] - ([ListIcon5:W] + [#s_ListRightPadding]))
FontWeight=([#s_CurrentCategory] = 5) ? [#s_SelectedFontWeight] : [#s_FontWeight]
ToolTipTitle=Device 
ToolTipText=
Hidden=[#EditMode]
LeftMouseUpAction=[!CommandMeasure PSRM EnterEditMode]

[ListIcon9]
Meter=String
Text=[\xE70F]
MeterStyle=ListIcon | ListDefaultIcon | LeftPanel
LeftMouseUpAction=[!CommandMeasure PSRM ExitEditMode]
Hidden=(1-[#EditMode])
[ListItem9]
Meter=String
Text=EditMode: On
MeterStyle=ListItem | ListDefaultItem | LeftPanel
W=([#s_LeftPanelW] - ([ListIcon5:W] + [#s_ListRightPadding]))
FontWeight=([#s_CurrentCategory] = 5) ? [#s_SelectedFontWeight] : [#s_FontWeight]
ToolTipTitle=Device 
LeftMouseUpAction=[!CommandMeasure PSRM ExitEditMode]
ToolTipText=
Hidden=(1-[#EditMode])

[LastLeftPanel]
Meter=String
Text=Last
FontColor=255,0,0,0
MeterStyle=LastItem | LeftPanel

[ScrollDownLeftPanel]
Measure=Calc
Formula=[#s_ScrollLeftPanel] - [#s_ScrollSpeed]
IfCondition=([LastLeftPanel:Y] > [#s_ScrollTreshold])
IfTrueAction=[!SetVariable "s_ScrollLeftPanel" "[&ScrollDownLeftPanel]"][!DisableMeasure "ScrollDownLeftPanel"][!Update][!Redraw]
IfFalseAction=[!DisableMeasure "ScrollDownLeftPanel"]
IfConditionMode=1
Disabled=1
DynamicVariables=1

[ScrollUpLeftPanel]
Measure=Calc
Formula=[#s_ScrollLeftPanel] + [#s_ScrollSpeed]
IfCondition=([FirstLeftPanel:Y] < 0)
IfTrueAction=[!SetVariable "s_ScrollLeftPanel" "[&ScrollUpLeftPanel]"][!DisableMeasure "ScrollUpLeftPanel"][!Update][!Redraw]
IfFalseAction=[!DisableMeasure "ScrollUpLeftPanel"]
IfConditionMode=1
Disabled=1
DynamicVariables=1

[CreditIcon]
FontSize=[#s_CreditIconSize]
AntiAlias=1
Meter=String
Text=[\xF259]
FontWeight=400
AccurateText=1
Padding=0,0,0,0
DynamicVariables=1
SolidColor=0,0,0,1
MeterStyle=LeftPanel
FontColor=[#s_FontColor]
X=[#s_CreditIconPadding]
FontWeight=[#s_FontWeight]
FontFace=Segoe MDL2 Assets
ToolTipTitle=Generated by Settings
ToolTipText=https://github.com/sceleri/settings
LeftMouseUpAction=["https://github.com/sceleri/settings"]
Y=([#s_PanelH] - [CreditIcon:H] - [#s_CreditIconPadding])
