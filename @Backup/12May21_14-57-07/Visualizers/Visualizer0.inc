
[Shape0]
Meter=Shape
X=[#XG0]
Y=[#YG0]
Shape=Rectangle 0,([#HeightG0]+2*[#StrokeWidthG0]), [#WidthG0],(Clamp((-[#HeightG0]*[Measure1]), -[#HeightG0], -[#MinimumHeightG0])), [#RoundingG0] | StrokeWidth #StrokeWidthG0# | Extend Color[#GradientBoolG0]
Shape2=Combine Shape | Rotate [#AngleG0], 0, (#HeightG0#+[#StrokeWidthG0]) 
Color0=Fill Color [#ColorG0]
Color1=Fill LinearGradient1 MyGradient
MyGradient=[#GradientG0]
DynamicVariables=1
