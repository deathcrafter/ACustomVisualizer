
[Shape2]
Meter=Shape
X=[#XG2]
Y=[#YG2]
Shape=Rectangle 0,([#HeightG2]+2*[#StrokeWidthG2]), [#WidthG2],(Clamp((-[#HeightG2]*[Measure2G0]), -[#HeightG2], -[#MinimumHeightG2])), [#RoundingG2] | StrokeWidth #StrokeWidthG2# | Extend Color[#GradientBoolG2]
Shape2=Rectangle (1*([#WidthG2]+[#GapG2])),(#HeightG2#+[#StrokeWidthG2]), #WidthG2#, (Clamp((-[#HeightG2]*[Measure2G1]), -[#HeightG2], -[#MinimumHeightG2])), [#RoundingG2] | StrokeWidth #StrokeWidthG2#
Shape3=Rectangle (2*([#WidthG2]+[#GapG2])),(#HeightG2#+[#StrokeWidthG2]), #WidthG2#, (Clamp((-[#HeightG2]*[Measure2G2]), -[#HeightG2], -[#MinimumHeightG2])), [#RoundingG2] | StrokeWidth #StrokeWidthG2#
Shape4=Rectangle (3*([#WidthG2]+[#GapG2])),(#HeightG2#+[#StrokeWidthG2]), #WidthG2#, (Clamp((-[#HeightG2]*[Measure2G3]), -[#HeightG2], -[#MinimumHeightG2])), [#RoundingG2] | StrokeWidth #StrokeWidthG2#
Shape5=Rectangle (4*([#WidthG2]+[#GapG2])),(#HeightG2#+[#StrokeWidthG2]), #WidthG2#, (Clamp((-[#HeightG2]*[Measure2G4]), -[#HeightG2], -[#MinimumHeightG2])), [#RoundingG2] | StrokeWidth #StrokeWidthG2#
Shape6=Combine Shape | Union Shape2 | Union Shape3 | Union Shape4 | Union Shape5 | Rotate [#AngleG2], ((5*([#WidthG2]+[#GapG2]) - [#GapG2])/2), (#HeightG2#+[#StrokeWidthG2]) 
Color0=Fill Color [#ColorG2]
Color1=Fill LinearGradient1 MyGradient
MyGradient=[#GradientG2]
DynamicVariables=1
