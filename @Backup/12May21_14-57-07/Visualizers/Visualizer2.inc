
[Shape2]
Meter=Shape
X=[#XG2]
Y=[#YG2]
Shape=Rectangle 0,([#HeightG2]+2*[#StrokeWidthG2]), [#WidthG2],(Clamp((-[#HeightG2]*[Measure1]), -[#HeightG2], -[#MinimumHeightG2])), [#RoundingG2] | StrokeWidth #StrokeWidthG2# | Extend Color[#GradientBoolG2]
Shape2=Combine Shape | Rotate [#AngleG2], 0, (#HeightG2#+[#StrokeWidthG2]) 
Color0=Fill Color [#ColorG2]
Color1=Fill LinearGradient1 MyGradient
MyGradient=[#GradientG2]
DynamicVariables=1
