[Metadata]
Name=Controls
Author=Lucky Penny
Information=Meters used in modal windows
License=Creative Commons BY-NC-SA 3.0
Version=0.0.3

[Header]
Meter=Image
X=0
Y=0
W=[SkinSizing:W]
H=([Title:H]+15)
SolidColor=#BackgroundColor#
DynamicVariables=1
UpdateDivider=-1

[MeterClose]
Meter=Image
X=([SkinSizing:W]-16-10)
Y=10
W=16
H=16
SolidColor=#ColorOff#
ImageName=#@#\Icons\Close.png
LeftMouseUpAction=[!DeactivateConfig]
DynamicVariables=1
UpdateDivider=-1
