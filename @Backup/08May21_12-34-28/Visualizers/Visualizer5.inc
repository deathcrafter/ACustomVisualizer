
[Shape5]
Meter=Shape
X=[#XG5]
Y=[#YG5]
Shape=Rectangle 0,([#HeightG5]+2*[#StrokeWidthG5]), [#WidthG5],(Clamp((-[#HeightG5]*[Measure5G0]), -[#HeightG5], -[#MinimumHeightG5])), [#RoundingG5] | StrokeWidth #StrokeWidthG5# | Extend Color[#GradientBoolG5]
Shape2=Combine Shape | Rotate [#AngleG5], ((1*([#WidthG5]+[#GapG5]) - [#GapG5])/2), (#HeightG5#+[#StrokeWidthG5]) 
Color0=Fill Color [#ColorG5]
Color1=Fill LinearGradient1 MyGradient
MyGradient=[#GradientG5]
DynamicVariables=1
