
[Shape0]
Meter=Shape
X=[#XG0]
Y=[#YG0]
Shape=Rectangle 0,([#HeightG0]+2*[#StrokeWidthG0]), [#WidthG0],(Clamp((-[#HeightG0]*[Measure0G0]), -[#HeightG0], -[#MinimumHeightG0])), [#RoundingG0] | StrokeWidth #StrokeWidthG0# | Extend Color[#GradientBoolG0]
Shape2=Rectangle (1*([#WidthG0]+[#GapG0])),(#HeightG0#+[#StrokeWidthG0]), #WidthG0#, (Clamp((-[#HeightG0]*[Measure0G1]), -[#HeightG0], -[#MinimumHeightG0])), [#RoundingG0] | StrokeWidth #StrokeWidthG0#
Shape3=Rectangle (2*([#WidthG0]+[#GapG0])),(#HeightG0#+[#StrokeWidthG0]), #WidthG0#, (Clamp((-[#HeightG0]*[Measure0G2]), -[#HeightG0], -[#MinimumHeightG0])), [#RoundingG0] | StrokeWidth #StrokeWidthG0#
Shape4=Rectangle (3*([#WidthG0]+[#GapG0])),(#HeightG0#+[#StrokeWidthG0]), #WidthG0#, (Clamp((-[#HeightG0]*[Measure0G3]), -[#HeightG0], -[#MinimumHeightG0])), [#RoundingG0] | StrokeWidth #StrokeWidthG0#
Shape5=Rectangle (4*([#WidthG0]+[#GapG0])),(#HeightG0#+[#StrokeWidthG0]), #WidthG0#, (Clamp((-[#HeightG0]*[Measure0G4]), -[#HeightG0], -[#MinimumHeightG0])), [#RoundingG0] | StrokeWidth #StrokeWidthG0#
Shape6=Combine Shape | Union Shape2 | Union Shape3 | Union Shape4 | Union Shape5 | Rotate [#AngleG0], 0, (#HeightG0#+[#StrokeWidthG0]) 
Color0=Fill Color [#ColorG0]
Color1=Fill LinearGradient1 MyGradient
MyGradient=[#GradientG0]
DynamicVariables=1
