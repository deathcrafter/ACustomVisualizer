
[Shape0]
Meter=Shape
X=[#XG0]
Y=[#YG0]
Shape=Rectangle 0,([#HeightG0]+2*[#StrokeWidthG0]), [#WidthG0],(Clamp((-[#HeightG0]*[Measure1]), -[#HeightG0], -[#MinimumHeightG0])), [#RoundingG0] | StrokeWidth #StrokeWidthG0# | Extend Color[#GradientBoolG0]
Shape2=Rectangle (1*([#WidthG0]+[#GapG0])),(#HeightG0#+[#StrokeWidthG0]), #WidthG0#, (Clamp((-[#HeightG0]*[Measure2]), -[#HeightG0], -[#MinimumHeightG0])), [#RoundingG0] | StrokeWidth #StrokeWidthG0#
Shape3=Rectangle (2*([#WidthG0]+[#GapG0])),(#HeightG0#+[#StrokeWidthG0]), #WidthG0#, (Clamp((-[#HeightG0]*[Measure3]), -[#HeightG0], -[#MinimumHeightG0])), [#RoundingG0] | StrokeWidth #StrokeWidthG0#
Shape4=Rectangle (3*([#WidthG0]+[#GapG0])),(#HeightG0#+[#StrokeWidthG0]), #WidthG0#, (Clamp((-[#HeightG0]*[Measure4]), -[#HeightG0], -[#MinimumHeightG0])), [#RoundingG0] | StrokeWidth #StrokeWidthG0#
Shape5=Rectangle (4*([#WidthG0]+[#GapG0])),(#HeightG0#+[#StrokeWidthG0]), #WidthG0#, (Clamp((-[#HeightG0]*[Measure5]), -[#HeightG0], -[#MinimumHeightG0])), [#RoundingG0] | StrokeWidth #StrokeWidthG0#
Shape6=Combine Shape | Union Shape2 | Union Shape3 | Union Shape4 | Union Shape5 | Rotate [#AngleG0], 0, (#HeightG0#+[#StrokeWidthG0]) 
Color0=Fill Color [#ColorG0]
Color1=Fill LinearGradient1 MyGradient
MyGradient=[#GradientG0]
LeftMouseDownAction=[!SetVariable CurrentGroup 0][!SetVariable DiffX ([&MouseX]-#CURRENTCONFIGX#-[#XG0])][!SetVariable DiffY ([&MouseY]-#CURRENTCONFIGY#-[#YG0])][!EnableMeasure ShapeMover]
LeftMouseUpAction=[!WriteKeyValue Variables XG0 [#XG0] "#@#Variables\Variable0.inc"][!WriteKeyValue Variables YG0 [#YG0] "#@#Variables\Variable0.inc"][!Refresh]
MouseScrollUpAction=[!WriteKeyValue Variables AngleG0 ([#AngleG0]+1) "#@#Variables\Variable0.inc"][!Refresh]
MouseScrollDownAction=[!WriteKeyValue Variables AngleG0 ([#AngleG0]-1) "#@#Variables\Variable0.inc"][!Refresh]
DynamicVariables=1
