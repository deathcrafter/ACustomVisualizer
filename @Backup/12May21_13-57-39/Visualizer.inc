
[Shape]
Meter=Shape
X=0
Y=0
Shape=Rectangle 0,160, 10, (Clamp((-160*[Measure1]), -160, -5)), 2 | StrokeWidth 0 | Fill LinearGradient1 MyGradient0
Shape2=Rectangle 14,160, 10, (Clamp((-160*[Measure2]), -160, -5)), 2 | StrokeWidth 0
Shape3=Rectangle 28,160, 10, (Clamp((-160*[Measure3]), -160, -5)), 2 | StrokeWidth 0
Shape4=Rectangle 42,160, 10, (Clamp((-160*[Measure4]), -160, -5)), 2 | StrokeWidth 0
Shape5=Rectangle 56,160, 10, (Clamp((-160*[Measure5]), -160, -5)), 2 | StrokeWidth 0
Shape6=Rectangle 66,160, 10, (Clamp((-160*[Measure6]), -160, -5)), 2 | StrokeWidth 0 | Fill LinearGradient1 MyGradient1
Shape7=Rectangle 80,160, 10, (Clamp((-160*[Measure7]), -160, -5)), 2 | StrokeWidth 0
Shape8=Rectangle 94,160, 10, (Clamp((-160*[Measure8]), -160, -5)), 2 | StrokeWidth 0
Shape9=Rectangle 108,160, 10, (Clamp((-160*[Measure9]), -160, -5)), 2 | StrokeWidth 0
Shape10=Rectangle 122,160, 10, (Clamp((-160*[Measure10]), -160, -5)), 2 | StrokeWidth 0
Shape11=Rectangle 99,217, 10, (Clamp((-160*[Measure10]), -160, -5)), 2 | StrokeWidth 0 | Fill LinearGradient1 MyGradient2
Shape12=Rectangle 113,217, 10, (Clamp((-160*[Measure9]), -160, -5)), 2 | StrokeWidth 0
Shape13=Rectangle 127,217, 10, (Clamp((-160*[Measure8]), -160, -5)), 2 | StrokeWidth 0
Shape14=Rectangle 141,217, 10, (Clamp((-160*[Measure7]), -160, -5)), 2 | StrokeWidth 0
Shape15=Rectangle 155,217, 10, (Clamp((-160*[Measure6]), -160, -5)), 2 | StrokeWidth 0
Shape16=Rectangle 66,274, 10, (Clamp((-160*[Measure5]), -160, -5)), 2 | StrokeWidth 0 | Fill LinearGradient1 MyGradient3
Shape17=Rectangle 80,274, 10, (Clamp((-160*[Measure4]), -160, -5)), 2 | StrokeWidth 0
Shape18=Rectangle 94,274, 10, (Clamp((-160*[Measure3]), -160, -5)), 2 | StrokeWidth 0
Shape19=Rectangle 108,274, 10, (Clamp((-160*[Measure2]), -160, -5)), 2 | StrokeWidth 0
Shape20=Rectangle 122,274, 10, (Clamp((-160*[Measure1]), -160, -5)), 2 | StrokeWidth 0
Shape21=Rectangle 0,171, 10, (Clamp((-66*[Measure6]), -66, -0)), 2 | StrokeWidth 0 | Fill LinearGradient1 MyGradient4
Shape22=Rectangle 16,171, 10, (Clamp((-66*[Measure5]), -66, -0)), 2 | StrokeWidth 0
Shape23=Rectangle 32,171, 10, (Clamp((-66*[Measure4]), -66, -0)), 2 | StrokeWidth 0
Shape24=Rectangle 0,222, 10, (Clamp((-66*[Measure4]), -66, -0)), 2 | StrokeWidth 0 | Fill LinearGradient1 MyGradient5
Shape25=Rectangle 16,222, 10, (Clamp((-66*[Measure5]), -66, -0)), 2 | StrokeWidth 0
Shape26=Rectangle 32,222, 10, (Clamp((-66*[Measure6]), -66, -0)), 2 | StrokeWidth 0

Shape27=Combine Shape | Union Shape2 | Union Shape3 | Union Shape4 | Union Shape5 | Rotate 0, 0, 160
MyGradient0=180 | 249, 116, 31;0.0 | 242, 75, 59;1.0

Shape28=Combine Shape6 | Union Shape7 | Union Shape8 | Union Shape9 | Union Shape10 | Rotate 60, 66, 160
MyGradient1=0 | 249, 116, 31;0.0 | 242, 75, 59;1.0

Shape29=Combine Shape11 | Union Shape12 | Union Shape13 | Union Shape14 | Union Shape15 | Rotate 120, 99, 217
MyGradient2=180 | 249, 116, 31;0.0 | 242, 75, 59;1.0

Shape30=Combine Shape16 | Union Shape17 | Union Shape18 | Union Shape19 | Union Shape20 | Rotate 180, 66, 274
MyGradient3=0 | 249, 116, 31;0.0 | 242, 75, 59;1.0

Shape31=Combine Shape21 | Union Shape22 | Union Shape23 | Rotate 90, 0, 171
MyGradient4=90 | 249, 116, 31;0.0 | 242, 75, 59;1.0

Shape32=Combine Shape24 | Union Shape25 | Union Shape26 | Rotate 90, 0, 222
MyGradient5=90 | 249, 116, 31;0.0 | 242, 75, 59;1.0

Shape33=Combine Shape27 | Union Shape28 | Union Shape29 | Union Shape30 | Union Shape31 | Union Shape32
DynamicVariables=1
