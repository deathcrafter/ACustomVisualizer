
[Shape1]
Meter=Shape
X=[#XG1]
Y=[#YG1]
Shape=Rectangle 0,([#HeightG1]+2*[#StrokeWidthG1]), [#WidthG1],(Clamp((-[#HeightG1]*[Measure1G0]), -[#HeightG1], -[#MinimumHeightG1])), [#RoundingG1] | StrokeWidth #StrokeWidthG1# | Extend Color[#GradientBoolG1]
Shape2=Rectangle (1*([#WidthG1]+[#GapG1])),(#HeightG1#+[#StrokeWidthG1]), #WidthG1#, (Clamp((-[#HeightG1]*[Measure1G1]), -[#HeightG1], -[#MinimumHeightG1])), [#RoundingG1] | StrokeWidth #StrokeWidthG1#
Shape3=Rectangle (2*([#WidthG1]+[#GapG1])),(#HeightG1#+[#StrokeWidthG1]), #WidthG1#, (Clamp((-[#HeightG1]*[Measure1G2]), -[#HeightG1], -[#MinimumHeightG1])), [#RoundingG1] | StrokeWidth #StrokeWidthG1#
Shape4=Rectangle (3*([#WidthG1]+[#GapG1])),(#HeightG1#+[#StrokeWidthG1]), #WidthG1#, (Clamp((-[#HeightG1]*[Measure1G3]), -[#HeightG1], -[#MinimumHeightG1])), [#RoundingG1] | StrokeWidth #StrokeWidthG1#
Shape5=Rectangle (4*([#WidthG1]+[#GapG1])),(#HeightG1#+[#StrokeWidthG1]), #WidthG1#, (Clamp((-[#HeightG1]*[Measure1G4]), -[#HeightG1], -[#MinimumHeightG1])), [#RoundingG1] | StrokeWidth #StrokeWidthG1#
Shape6=Combine Shape | Union Shape2 | Union Shape3 | Union Shape4 | Union Shape5 | Rotate [#AngleG1], 0, (#HeightG1#+[#StrokeWidthG1]) 
Color0=Fill Color [#ColorG1]
Color1=Fill LinearGradient1 MyGradient
MyGradient=[#GradientG1]
DynamicVariables=1
