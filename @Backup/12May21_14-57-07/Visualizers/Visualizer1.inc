
[Shape1]
Meter=Shape
X=[#XG1]
Y=[#YG1]
Shape=Rectangle 0,([#HeightG1]+2*[#StrokeWidthG1]), [#WidthG1],(Clamp((-[#HeightG1]*[Measure1]), -[#HeightG1], -[#MinimumHeightG1])), [#RoundingG1] | StrokeWidth #StrokeWidthG1# | Extend Color[#GradientBoolG1]
Shape2=Combine Shape | Rotate [#AngleG1], 0, (#HeightG1#+[#StrokeWidthG1]) 
Color0=Fill Color [#ColorG1]
Color1=Fill LinearGradient1 MyGradient
MyGradient=[#GradientG1]
DynamicVariables=1
