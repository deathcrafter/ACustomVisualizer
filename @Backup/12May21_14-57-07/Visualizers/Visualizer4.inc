
[Shape4]
Meter=Shape
X=[#XG4]
Y=[#YG4]
Shape=Rectangle 0,([#HeightG4]+2*[#StrokeWidthG4]), [#WidthG4],(Clamp((-[#HeightG4]*[Measure1]), -[#HeightG4], -[#MinimumHeightG4])), [#RoundingG4] | StrokeWidth #StrokeWidthG4# | Extend Color[#GradientBoolG4]
Shape2=Combine Shape | Rotate [#AngleG4], 0, (#HeightG4#+[#StrokeWidthG4]) 
Color0=Fill Color [#ColorG4]
Color1=Fill LinearGradient1 MyGradient
MyGradient=[#GradientG4]
DynamicVariables=1
