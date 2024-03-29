
[Shape1]
Meter=Shape
X=[#XG1]
Y=[#YG1]
Shape=Rectangle 0,([#HeightG1]+2*[#StrokeWidthG1]), [#WidthG1],(Clamp((-[#HeightG1]*[Measure1]), -[#HeightG1], -[#MinimumHeightG1])), [#RoundingG1] | StrokeWidth #StrokeWidthG1# | Extend Color[#GradientBoolG1]
Shape2=Rectangle (1*([#WidthG1]+[#GapG1])),(#HeightG1#+[#StrokeWidthG1]), #WidthG1#, (Clamp((-[#HeightG1]*[Measure2]), -[#HeightG1], -[#MinimumHeightG1])), [#RoundingG1] | StrokeWidth #StrokeWidthG1#
Shape3=Rectangle (2*([#WidthG1]+[#GapG1])),(#HeightG1#+[#StrokeWidthG1]), #WidthG1#, (Clamp((-[#HeightG1]*[Measure3]), -[#HeightG1], -[#MinimumHeightG1])), [#RoundingG1] | StrokeWidth #StrokeWidthG1#
Shape4=Rectangle (3*([#WidthG1]+[#GapG1])),(#HeightG1#+[#StrokeWidthG1]), #WidthG1#, (Clamp((-[#HeightG1]*[Measure4]), -[#HeightG1], -[#MinimumHeightG1])), [#RoundingG1] | StrokeWidth #StrokeWidthG1#
Shape5=Rectangle (4*([#WidthG1]+[#GapG1])),(#HeightG1#+[#StrokeWidthG1]), #WidthG1#, (Clamp((-[#HeightG1]*[Measure5]), -[#HeightG1], -[#MinimumHeightG1])), [#RoundingG1] | StrokeWidth #StrokeWidthG1#
Shape6=Combine Shape | Union Shape2 | Union Shape3 | Union Shape4 | Union Shape5 | Rotate [#AngleG1], 0, (#HeightG1#+[#StrokeWidthG1]) 
Color0=Fill Color [#ColorG1]
Color1=Fill LinearGradient1 MyGradient
MyGradient=[#GradientG1]
LeftMouseDownAction=[!SetVariable CurrentGroup 1][!SetVariable DiffX ([&MouseX]-#CURRENTCONFIGX#-[#XG1])][!SetVariable DiffY ([&MouseY]-#CURRENTCONFIGY#-[#YG1])][!EnableMeasure ShapeMover]
LeftMouseUpAction=[!WriteKeyValue Variables XG1 [#XG1] "#@#Variables\Variable1.inc"][!WriteKeyValue Variables YG1 [#YG1] "#@#Variables\Variable1.inc"][!Refresh]
DynamicVariables=1
