
[Shape]
Meter=Shape
X=0
Y=0
Shape=Rectangle 17,343, 12, (Clamp((-300*[Measure1]), -300, -10)), 3 | StrokeWidth 0 | Fill LinearGradient1 MyGradient0
Shape2=Rectangle 35,343, 12, (Clamp((-300*[Measure2]), -300, -10)), 3 | StrokeWidth 0
Shape3=Rectangle 53,343, 12, (Clamp((-300*[Measure3]), -300, -10)), 3 | StrokeWidth 0
Shape4=Rectangle 71,343, 12, (Clamp((-300*[Measure4]), -300, -10)), 3 | StrokeWidth 0
Shape5=Rectangle 89,343, 12, (Clamp((-300*[Measure5]), -300, -10)), 3 | StrokeWidth 0
Shape6=Rectangle 90,300, 12, (Clamp((-300*[Measure1]), -300, -10)), 3 | StrokeWidth 0 | Fill LinearGradient1 MyGradient1
Shape7=Rectangle 108,300, 12, (Clamp((-300*[Measure2]), -300, -10)), 3 | StrokeWidth 0
Shape8=Rectangle 126,300, 12, (Clamp((-300*[Measure3]), -300, -10)), 3 | StrokeWidth 0
Shape9=Rectangle 144,300, 12, (Clamp((-300*[Measure4]), -300, -10)), 3 | StrokeWidth 0
Shape10=Rectangle 162,300, 12, (Clamp((-300*[Measure5]), -300, -10)), 3 | StrokeWidth 0
Shape11=Rectangle 175,300, 12, (Clamp((-300*[Measure1]), -300, -10)), 3 | StrokeWidth 0 | Fill LinearGradient1 MyGradient2
Shape12=Rectangle 193,300, 12, (Clamp((-300*[Measure2]), -300, -10)), 3 | StrokeWidth 0
Shape13=Rectangle 211,300, 12, (Clamp((-300*[Measure3]), -300, -10)), 3 | StrokeWidth 0
Shape14=Rectangle 229,300, 12, (Clamp((-300*[Measure4]), -300, -10)), 3 | StrokeWidth 0
Shape15=Rectangle 247,300, 12, (Clamp((-300*[Measure5]), -300, -10)), 3 | StrokeWidth 0
Shape16=Rectangle 270,300, 12, (Clamp((-300*[Measure1]), -300, -10)), 3 | StrokeWidth 0 | Fill LinearGradient1 MyGradient3
Shape17=Rectangle 288,300, 12, (Clamp((-300*[Measure2]), -300, -10)), 3 | StrokeWidth 0
Shape18=Rectangle 306,300, 12, (Clamp((-300*[Measure3]), -300, -10)), 3 | StrokeWidth 0
Shape19=Rectangle 324,300, 12, (Clamp((-300*[Measure4]), -300, -10)), 3 | StrokeWidth 0
Shape20=Rectangle 342,300, 12, (Clamp((-300*[Measure5]), -300, -10)), 3 | StrokeWidth 0

Shape21=Combine Shape | Union Shape2 | Union Shape3 | Union Shape4 | Union Shape5 | Rotate -31, 17, 343
MyGradient0=180 | 255,0,0;0.0 | 150,200,250;1.0

Shape22=Combine Shape6 | Union Shape7 | Union Shape8 | Union Shape9 | Union Shape10 | Rotate 0, 90, 300
MyGradient1=180 | 255,0,0;0.0 | 150,200,250;1.0

Shape23=Combine Shape11 | Union Shape12 | Union Shape13 | Union Shape14 | Union Shape15 | Rotate 30, 175, 300
MyGradient2=180 | 255,0,0;0.0 | 150,200,250;1.0

Shape24=Combine Shape16 | Union Shape17 | Union Shape18 | Union Shape19 | Union Shape20 | Rotate 0, 270, 300
MyGradient3=180 | 255,0,0;0.0 | 150,200,250;1.0

DynamicVariables=1
