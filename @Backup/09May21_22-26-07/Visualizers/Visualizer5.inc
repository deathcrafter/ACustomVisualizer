
[Shape5]
Meter=Shape
X=[#XG5]
Y=[#YG5]
Shape=Rectangle 0,([#HeightG5]+2*[#StrokeWidthG5]), [#WidthG5],(Clamp((-[#HeightG5]*[Measure4]), -[#HeightG5], -[#MinimumHeightG5])), [#RoundingG5] | StrokeWidth #StrokeWidthG5# | Extend Color[#GradientBoolG5]
Shape2=Rectangle (1*([#WidthG5]+[#GapG5])),(#HeightG5#+[#StrokeWidthG5]), #WidthG5#, (Clamp((-[#HeightG5]*[Measure5]), -[#HeightG5], -[#MinimumHeightG5])), [#RoundingG5] | StrokeWidth #StrokeWidthG5#
Shape3=Rectangle (2*([#WidthG5]+[#GapG5])),(#HeightG5#+[#StrokeWidthG5]), #WidthG5#, (Clamp((-[#HeightG5]*[Measure6]), -[#HeightG5], -[#MinimumHeightG5])), [#RoundingG5] | StrokeWidth #StrokeWidthG5#
Shape4=Combine Shape | Union Shape2 | Union Shape3 | Rotate [#AngleG5], 0, (#HeightG5#+[#StrokeWidthG5]) 
Color0=Fill Color [#ColorG5]
Color1=Fill LinearGradient1 MyGradient
MyGradient=[#GradientG5]
DynamicVariables=1
