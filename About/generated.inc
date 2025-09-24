[FortuneMeasureActive]
Measure=Plugin
Plugin=WebParser.dll
Url=file://#SETTINGSPATH#Rainmeter.ini
RegExp="(?siU)\[#RootConfig#\\Fortune\](.*)Active=(.*)\n"
StringIndex=2
UpdateRate=-1

[FortuneMeasureActive2]
Measure=Calc
Formula=FortuneMeasureActive
IfCondition=(FortuneMeasureActive2=0)
IfTrueAction=[!SetOption FortuneMeterOn SolidColor #BackdropColor#][!SetOption FortuneMeterOff SolidColor #ColorOff#]
IfFalseAction=[!SetOption FortuneMeterOn SolidColor #ColorOn#][!SetOption FortuneMeterOff SolidColor #BackdropColor#]

;------------------------------------------------------------------------------
; Meters

[FortuneTitle]
Meter=String
MeterStyle=TextStyle
X=10
Y=40
Text=Fortune
UpdateDivider=-1

[FortuneMeterOn]
Meter=Image
X=200
Y=40
W=14
H=14
SolidColor=#ColorClear#
LeftMouseUpAction=[!ActivateConfig "#RootConfig#\Fortune"][!CommandMeasure FortuneMeasureActive Update]

[FortuneMeterOff]
Meter=Image
X=220
Y=40
W=14
H=14
SolidColor=#ColorClear#
LeftMouseUpAction=[!DeactivateConfig "#RootConfig#\Fortune"][!CommandMeasure FortuneMeasureActive Update]
[UptimeMeasureActive]
Measure=Plugin
Plugin=WebParser.dll
Url=file://#SETTINGSPATH#Rainmeter.ini
RegExp="(?siU)\[#RootConfig#\\Uptime\](.*)Active=(.*)\n"
StringIndex=2
UpdateRate=-1

[UptimeMeasureActive2]
Measure=Calc
Formula=UptimeMeasureActive
IfCondition=(UptimeMeasureActive2=0)
IfTrueAction=[!SetOption UptimeMeterOn SolidColor #BackdropColor#][!SetOption UptimeMeterOff SolidColor #ColorOff#]
IfFalseAction=[!SetOption UptimeMeterOn SolidColor #ColorOn#][!SetOption UptimeMeterOff SolidColor #BackdropColor#]

;------------------------------------------------------------------------------
; Meters

[UptimeTitle]
Meter=String
MeterStyle=TextStyle
X=10
Y=5R
Text=Uptime
UpdateDivider=-1

[UptimeMeterOn]
Meter=Image
X=200
Y=1r
W=14
H=14
SolidColor=#ColorClear#
LeftMouseUpAction=[!ActivateConfig "#RootConfig#\Uptime"][!CommandMeasure UptimeMeasureActive Update]

[UptimeMeterOff]
Meter=Image
X=220
Y=0r
W=14
H=14
SolidColor=#ColorClear#
LeftMouseUpAction=[!DeactivateConfig "#RootConfig#\Uptime"][!CommandMeasure UptimeMeasureActive Update]