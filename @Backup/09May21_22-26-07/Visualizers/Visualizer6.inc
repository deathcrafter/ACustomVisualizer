
[Shape6]
Meter=Shape
X=[#XG6]
Y=[#YG6]
Shape=Rectangle 0,([#HeightG6]+2*[#StrokeWidthG6]), [#WidthG6],(Clamp((-[#HeightG6]*[Measure1]), -[#HeightG6], -[#MinimumHeightG6])), [#RoundingG6] | StrokeWidth #StrokeWidthG6# | Extend Color[#GradientBoolG6]
Shape2=Rectangle (1*([#WidthG6]+[#GapG6])),(#HeightG6#+[#StrokeWidthG6]), #WidthG6#, (Clamp((-[#HeightG6]*[Measure2]), -[#HeightG6], -[#MinimumHeightG6])), [#RoundingG6] | StrokeWidth #StrokeWidthG6#
Shape3=Rectangle (2*([#WidthG6]+[#GapG6])),(#HeightG6#+[#StrokeWidthG6]), #WidthG6#, (Clamp((-[#HeightG6]*[Measure3]), -[#HeightG6], -[#MinimumHeightG6])), [#RoundingG6] | StrokeWidth #StrokeWidthG6#
Shape4=Rectangle (3*([#WidthG6]+[#GapG6])),(#HeightG6#+[#StrokeWidthG6]), #WidthG6#, (Clamp((-[#HeightG6]*[Measure4]), -[#HeightG6], -[#MinimumHeightG6])), [#RoundingG6] | StrokeWidth #StrokeWidthG6#
Shape5=Rectangle (4*([#WidthG6]+[#GapG6])),(#HeightG6#+[#StrokeWidthG6]), #WidthG6#, (Clamp((-[#HeightG6]*[Measure5]), -[#HeightG6], -[#MinimumHeightG6])), [#RoundingG6] | StrokeWidth #StrokeWidthG6#
Shape6=Combine Shape | Union Shape2 | Union Shape3 | Union Shape4 | Union Shape5 | Rotate [#AngleG6], 0, (#HeightG6#+[#StrokeWidthG6]) 
Color0=Fill Color [#ColorG6]
Color1=Fill LinearGradient1 MyGradient
MyGradient=[#GradientG6]
DynamicVariables=1
