
[Shape3]
Meter=Shape
X=[#XG3]
Y=[#YG3]
Shape=Rectangle 0,([#HeightG3]+2*[#StrokeWidthG3]), [#WidthG3],(Clamp((-[#HeightG3]*[Measure1]), -[#HeightG3], -[#MinimumHeightG3])), [#RoundingG3] | StrokeWidth #StrokeWidthG3# | Extend Color[#GradientBoolG3]
Shape2=Rectangle (1*([#WidthG3]+[#GapG3])),(#HeightG3#+[#StrokeWidthG3]), #WidthG3#, (Clamp((-[#HeightG3]*[Measure2]), -[#HeightG3], -[#MinimumHeightG3])), [#RoundingG3] | StrokeWidth #StrokeWidthG3#
Shape3=Rectangle (2*([#WidthG3]+[#GapG3])),(#HeightG3#+[#StrokeWidthG3]), #WidthG3#, (Clamp((-[#HeightG3]*[Measure3]), -[#HeightG3], -[#MinimumHeightG3])), [#RoundingG3] | StrokeWidth #StrokeWidthG3#
Shape4=Rectangle (3*([#WidthG3]+[#GapG3])),(#HeightG3#+[#StrokeWidthG3]), #WidthG3#, (Clamp((-[#HeightG3]*[Measure4]), -[#HeightG3], -[#MinimumHeightG3])), [#RoundingG3] | StrokeWidth #StrokeWidthG3#
Shape5=Rectangle (4*([#WidthG3]+[#GapG3])),(#HeightG3#+[#StrokeWidthG3]), #WidthG3#, (Clamp((-[#HeightG3]*[Measure5]), -[#HeightG3], -[#MinimumHeightG3])), [#RoundingG3] | StrokeWidth #StrokeWidthG3#
Shape6=Combine Shape | Union Shape2 | Union Shape3 | Union Shape4 | Union Shape5 | Rotate [#AngleG3], 0, (#HeightG3#+[#StrokeWidthG3]) 
Color0=Fill Color [#ColorG3]
Color1=Fill LinearGradient1 MyGradient
MyGradient=[#GradientG3]
LeftMouseDownAction=[!SetVariable CurrentGroup 3][!SetVariable DiffX ([&MouseX]-#CURRENTCONFIGX#-[#XG3])][!SetVariable DiffY ([&MouseY]-#CURRENTCONFIGY#-[#YG3])][!EnableMeasure ShapeMover]
LeftMouseUpAction=[!WriteKeyValue Variables XG3 [#XG3] "#@#Variables\Variable3.inc"][!WriteKeyValue Variables YG3 [#YG3] "#@#Variables\Variable3.inc"][!Refresh]
MouseScrollUpAction=[!WriteKeyValue Variables AngleG3 ([#AngleG3]+1) "#@#Variables\Variable3.inc"][!Refresh]
MouseScrollDownAction=[!WriteKeyValue Variables AngleG3 ([#AngleG3]-1) "#@#Variables\Variable3.inc"][!Refresh]
DynamicVariables=1
