
[Shape3]
Meter=Shape
X=[#XG3]
Y=[#YG3]
Shape=Rectangle 0,([#HeightG3]+2*[#StrokeWidthG3]), [#WidthG3],(Clamp((-[#HeightG3]*[Measure1]), -[#HeightG3], -[#MinimumHeightG3])), [#RoundingG3] | StrokeWidth #StrokeWidthG3# | Extend Color[#GradientBoolG3]
Shape2=Combine Shape | Rotate [#AngleG3], 0, (#HeightG3#+[#StrokeWidthG3]) 
Color0=Fill Color [#ColorG3]
Color1=Fill LinearGradient1 MyGradient
MyGradient=[#GradientG3]
DynamicVariables=1
