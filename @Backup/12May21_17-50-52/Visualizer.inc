
[Shape]
Meter=Shape
X=0
Y=0
Shape=Rectangle 0,300, 12, (Clamp((-300*[Measure1]), -300, -10)), 3 | StrokeWidth 0 | Fill LinearGradient1 MyGradient0
Shape2=Rectangle 18,300, 12, (Clamp((-300*[Measure2]), -300, -10)), 3 | StrokeWidth 0
Shape3=Rectangle 36,300, 12, (Clamp((-300*[Measure3]), -300, -10)), 3 | StrokeWidth 0
Shape4=Rectangle 54,300, 12, (Clamp((-300*[Measure4]), -300, -10)), 3 | StrokeWidth 0
Shape5=Rectangle 72,300, 12, (Clamp((-300*[Measure5]), -300, -10)), 3 | StrokeWidth 0
Shape6=Rectangle 0,300, 12, (Clamp((-300*[Measure1]), -300, -10)), 3 | StrokeWidth 0 | Fill LinearGradient1 MyGradient1
Shape7=Rectangle 18,300, 12, (Clamp((-300*[Measure2]), -300, -10)), 3 | StrokeWidth 0
Shape8=Rectangle 36,300, 12, (Clamp((-300*[Measure3]), -300, -10)), 3 | StrokeWidth 0
Shape9=Rectangle 54,300, 12, (Clamp((-300*[Measure4]), -300, -10)), 3 | StrokeWidth 0
Shape10=Rectangle 72,300, 12, (Clamp((-300*[Measure5]), -300, -10)), 3 | StrokeWidth 0
Shape11=Rectangle 0,300, 12, (Clamp((-300*[Measure1]), -300, -10)), 3 | StrokeWidth 0 | Fill LinearGradient1 MyGradient2
Shape12=Rectangle 18,300, 12, (Clamp((-300*[Measure2]), -300, -10)), 3 | StrokeWidth 0
Shape13=Rectangle 36,300, 12, (Clamp((-300*[Measure3]), -300, -10)), 3 | StrokeWidth 0
Shape14=Rectangle 54,300, 12, (Clamp((-300*[Measure4]), -300, -10)), 3 | StrokeWidth 0
Shape15=Rectangle 72,300, 12, (Clamp((-300*[Measure5]), -300, -10)), 3 | StrokeWidth 0
Shape16=Rectangle 0,300, 12, (Clamp((-300*[Measure1]), -300, -10)), 3 | StrokeWidth 0 | Fill LinearGradient1 MyGradient3
Shape17=Rectangle 18,300, 12, (Clamp((-300*[Measure2]), -300, -10)), 3 | StrokeWidth 0
Shape18=Rectangle 36,300, 12, (Clamp((-300*[Measure3]), -300, -10)), 3 | StrokeWidth 0
Shape19=Rectangle 54,300, 12, (Clamp((-300*[Measure4]), -300, -10)), 3 | StrokeWidth 0
Shape20=Rectangle 72,300, 12, (Clamp((-300*[Measure5]), -300, -10)), 3 | StrokeWidth 0

Shape21=Combine Shape | Union Shape2 | Union Shape3 | Union Shape4 | Union Shape5 | Rotate 0, 0, 300
MyGradient0=180 | 255,0,0;0.0 | 150,200,250;1.0

Shape22=Combine Shape6 | Union Shape7 | Union Shape8 | Union Shape9 | Union Shape10 | Rotate 0, 0, 300
MyGradient1=180 | 255,0,0;0.0 | 150,200,250;1.0

Shape23=Combine Shape11 | Union Shape12 | Union Shape13 | Union Shape14 | Union Shape15 | Rotate 0, 0, 300
MyGradient2=180 | 255,0,0;0.0 | 150,200,250;1.0

Shape24=Combine Shape16 | Union Shape17 | Union Shape18 | Union Shape19 | Union Shape20 | Rotate 0, 0, 300
MyGradient3=180 | 255,0,0;0.0 | 150,200,250;1.0

DynamicVariables=1
