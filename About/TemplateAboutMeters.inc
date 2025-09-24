[|MeasureActive]
Measure=Plugin
Plugin=WebParser.dll
Url=file://#SETTINGSPATH#Rainmeter.ini
RegExp="(?siU)\[#RootConfig#\\|\](.*)Active=(.*)\n"
StringIndex=2
UpdateRate=-1

[|MeasureActive2]
Measure=Calc
Formula=|MeasureActive
IfCondition=(|MeasureActive2=0)
IfTrueAction=[!SetOption |MeterOn SolidColor #BackdropColor#][!SetOption |MeterOff SolidColor #ColorOff#]
IfFalseAction=[!SetOption |MeterOn SolidColor #ColorOn#][!SetOption |MeterOff SolidColor #BackdropColor#]

;------------------------------------------------------------------------------
; Meters

[|Title]
Meter=String
MeterStyle=TextStyle
X=10
Y=5R
Text=|
UpdateDivider=-1

[|MeterOn]
Meter=Image
X=200
Y=1r
W=14
H=14
SolidColor=#ColorClear#
LeftMouseUpAction=[!ActivateConfig "#RootConfig#\|"][!CommandMeasure |MeasureActive Update]

[|MeterOff]
Meter=Image
X=220
Y=0r
W=14
H=14
SolidColor=#ColorClear#
LeftMouseUpAction=[!DeactivateConfig "#RootConfig#\|"][!CommandMeasure |MeasureActive Update]
