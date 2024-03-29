
[Shape2]
Meter=Shape
X=[#XG2]
Y=[#YG2]
Shape=Rectangle 0,([#HeightG2]+2*[#StrokeWidthG2]), [#WidthG2],(Clamp((-[#HeightG2]*[Measure1]), -[#HeightG2], -[#MinimumHeightG2])), [#RoundingG2] | StrokeWidth #StrokeWidthG2# | Extend Color[#GradientBoolG2]
Shape2=Rectangle (1*([#WidthG2]+[#GapG2])),(#HeightG2#+[#StrokeWidthG2]), #WidthG2#, (Clamp((-[#HeightG2]*[Measure2]), -[#HeightG2], -[#MinimumHeightG2])), [#RoundingG2] | StrokeWidth #StrokeWidthG2#
Shape3=Rectangle (2*([#WidthG2]+[#GapG2])),(#HeightG2#+[#StrokeWidthG2]), #WidthG2#, (Clamp((-[#HeightG2]*[Measure3]), -[#HeightG2], -[#MinimumHeightG2])), [#RoundingG2] | StrokeWidth #StrokeWidthG2#
Shape4=Rectangle (3*([#WidthG2]+[#GapG2])),(#HeightG2#+[#StrokeWidthG2]), #WidthG2#, (Clamp((-[#HeightG2]*[Measure4]), -[#HeightG2], -[#MinimumHeightG2])), [#RoundingG2] | StrokeWidth #StrokeWidthG2#
Shape5=Rectangle (4*([#WidthG2]+[#GapG2])),(#HeightG2#+[#StrokeWidthG2]), #WidthG2#, (Clamp((-[#HeightG2]*[Measure5]), -[#HeightG2], -[#MinimumHeightG2])), [#RoundingG2] | StrokeWidth #StrokeWidthG2#
Shape6=Combine Shape | Union Shape2 | Union Shape3 | Union Shape4 | Union Shape5 | Rotate [#AngleG2], 0, (#HeightG2#+[#StrokeWidthG2]) 
Color0=Fill Color [#ColorG2]
Color1=Fill LinearGradient1 MyGradient
MyGradient=[#GradientG2]
MouseOverAction=[!SetVariable CurrentGroup 2]
LeftMouseDownAction=[!SetVariable DiffX ([&MouseX]-#CURRENTCONFIGX#-[#XG2])][!SetVariable DiffY ([&MouseY]-#CURRENTCONFIGY#-[#YG2])][!EnableMeasure ShapeMover]
LeftMouseUpAction=[!WriteKeyValue Variables XG2 [#XG2] "#@#Variables\Variable2.inc"][!WriteKeyValue Variables YG2 [#YG2] "#@#Variables\Variable2.inc"][!Refresh]
DynamicVariables=1
