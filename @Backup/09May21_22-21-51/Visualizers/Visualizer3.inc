
[Shape3]
Meter=Shape
X=[#XG3]
Y=[#YG3]
Shape=Rectangle 0,([#HeightG3]+2*[#StrokeWidthG3]), [#WidthG3],(Clamp((-[#HeightG3]*[Measure3G0]), -[#HeightG3], -[#MinimumHeightG3])), [#RoundingG3] | StrokeWidth #StrokeWidthG3# | Extend Color[#GradientBoolG3]
Shape2=Rectangle (1*([#WidthG3]+[#GapG3])),(#HeightG3#+[#StrokeWidthG3]), #WidthG3#, (Clamp((-[#HeightG3]*[Measure3G1]), -[#HeightG3], -[#MinimumHeightG3])), [#RoundingG3] | StrokeWidth #StrokeWidthG3#
Shape3=Rectangle (2*([#WidthG3]+[#GapG3])),(#HeightG3#+[#StrokeWidthG3]), #WidthG3#, (Clamp((-[#HeightG3]*[Measure3G2]), -[#HeightG3], -[#MinimumHeightG3])), [#RoundingG3] | StrokeWidth #StrokeWidthG3#
Shape4=Rectangle (3*([#WidthG3]+[#GapG3])),(#HeightG3#+[#StrokeWidthG3]), #WidthG3#, (Clamp((-[#HeightG3]*[Measure3G3]), -[#HeightG3], -[#MinimumHeightG3])), [#RoundingG3] | StrokeWidth #StrokeWidthG3#
Shape5=Rectangle (4*([#WidthG3]+[#GapG3])),(#HeightG3#+[#StrokeWidthG3]), #WidthG3#, (Clamp((-[#HeightG3]*[Measure3G4]), -[#HeightG3], -[#MinimumHeightG3])), [#RoundingG3] | StrokeWidth #StrokeWidthG3#
Shape6=Combine Shape | Union Shape2 | Union Shape3 | Union Shape4 | Union Shape5 | Rotate [#AngleG3], 0, (#HeightG3#+[#StrokeWidthG3]) 
Color0=Fill Color [#ColorG3]
Color1=Fill LinearGradient1 MyGradient
MyGradient=[#GradientG3]
DynamicVariables=1
