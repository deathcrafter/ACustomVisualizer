
[Shape]
Meter=Shape
X=0
Y=0
Shape=Rectangle 0,160, 10, (Clamp((-160*[Measure1]), -160, -5)), 2 | StrokeWidth 0 | Fill LinearGradient1 MyGradient0
Shape2=Rectangle 14,160, 10, (Clamp((-160*[Measure2]), -160, -5)), 2 | StrokeWidth 0
Shape3=Rectangle 28,160, 10, (Clamp((-160*[Measure3]), -160, -5)), 2 | StrokeWidth 0
Shape4=Rectangle 42,160, 10, (Clamp((-160*[Measure4]), -160, -5)), 2 | StrokeWidth 0
Shape5=Rectangle 56,160, 10, (Clamp((-160*[Measure5]), -160, -5)), 2 | StrokeWidth 0

Shape6=Combine Shape | Union Shape2 | Union Shape3 | Union Shape4 | Union Shape5 | Rotate 0, 0, 160
MyGradient0=180 | 249, 116, 31;0.0 | 242, 75, 59;1.0

Shape7=Combine Shape6
DynamicVariables=1
