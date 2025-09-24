[TitleClock4]
Meter=String
MeterStyle=TextStyle
StringAlign=Left
X=310
Y=([Title:Y]+142)
Text=Clock4 - Displayed
UpdateDivider=-1

[MeterOnClock4]
Meter=Image
X=5R
Y=1r
W=14
H=14
SolidColor=#Clock4_OnSelect#
LeftMouseUpAction=[!WriteKeyValue Variables Clock4_Display "1" "#CurrentPath#\clocks.var"][!WriteKeyValue Variables Clock4_OnSelect #ColorOn# "#CurrentPath#\clocks.var"][!WriteKeyValue Variables Clock4_OffSelect #BackdropColor# "#CurrentPath#\clocks.var"][!RefreshGroup TDClocks]

[MeterOffClock4]
Meter=Image
X=20r
Y=0r
W=14
H=14
SolidColor=#Clock4_OffSelect#
LeftMouseUpAction=[!WriteKeyValue Variables Clock4_Display "0" "#CurrentPath#\clocks.var"][!WriteKeyValue Variables Clock4_OffSelect #ColorOff# "#CurrentPath#\clocks.var"][!WriteKeyValue Variables Clock4_OnSelect #BackdropColor# "#CurrentPath#\clocks.var"][!RefreshGroup TDClocks]


;------------------------------------------------------------------------------
; Meters

[LabelMeterTitleClock4]
Meter=String
MeterStyle=TextStyle
StringAlign=Left
X=325
Y=10R
Text=Label
UpdateDivider=-1

[LabelMeterTextClock4]
Meter=String
X=5R
Y=0r
H=16
W=105
FontSize=10
FontColor=#TextColor#
AntiAlias=1
SolidColor=#BackdropColor#
Text=#Clock4_Label#
LeftMouseUpAction=!CommandMeasure "LabelMeasureInputClock4" "ExecuteBatch 1-2"

[LabelMeasureInputClock4]
Measure=Plugin
Plugin=InputText
X=[LabelMeterTextClock4:X]
Y=[LabelMeterTextClock4:Y]
H=[LabelMeterTextClock4:H]
W=[LabelMeterTextClock4:W]
SolidColor=#TextColor#
FontColor=#BackgroundColor#
FontFace=Seqoe UI
FontSize=10
DefaultValue=#Clock4_Label#
Command1=[!WriteKeyValue Variables Clock4_Label "$UserInput$" "#CurrentPath#\clocks.var"]
Command2=!RefreshGroup TDClocks

[TimezoneMeterTitleClock4]
Meter=String
MeterStyle=TextStyle
StringAlign=Left
X=325
Y=5R
Text=Timezone
UpdateDivider=-1

[TimezoneMeterTextClock4]
Meter=String
X=5R
Y=0r
H=16
W=105
FontSize=10
FontColor=#TextColor#
AntiAlias=1
SolidColor=#BackdropColor#
Text=#Clock4_Timezone#
LeftMouseUpAction=!CommandMeasure "TimezoneMeasureInputClock4" "ExecuteBatch 1-2"

[TimezoneMeasureInputClock4]
Measure=Plugin
Plugin=InputText
X=[TimezoneMeterTextClock4:X]
Y=[TimezoneMeterTextClock4:Y]
H=[TimezoneMeterTextClock4:H]
W=[TimezoneMeterTextClock4:W]
SolidColor=#TextColor#
FontColor=#BackgroundColor#
FontFace=Seqoe UI
FontSize=10
DefaultValue=#Clock4_Timezone#
Command1=[!WriteKeyValue Variables Clock4_Timezone "$UserInput$" "#CurrentPath#\clocks.var"]
Command2=!RefreshGroup TDClocks

[FormatMeterTitleClock4]
Meter=String
MeterStyle=TextStyle
StringAlign=Left
X=325
Y=5R
Text=Format
UpdateDivider=-1

[FormatSet12Clock4]
Meter=String
X=40R
Y=9r
W=70
H=22
FontSize=12
FontColor=#TextColor#
SolidColor=#Clock4_12Select#
StringAlign=CenterCenter
AntiAlias=1
Text=12 hour
LeftMouseUpAction=[!WriteKeyValue Variables Clock4_12or24 "I" "#CurrentPath#\clocks.var"][!WriteKeyValue Variables Clock4_24Select #ColorClear# "#CurrentPath#\clocks.var"][!WriteKeyValue Variables  Clock4_12Select #BackdropColor# "#CurrentPath#\clocks.var"][!RefreshGroup TDClocks]
UpdateDivider=-1

[FormatSet24Clock4]
Meter=String
X=80r
Y=0r
W=70
H=22
FontSize=12
FontColor=#TextColor#
SolidColor=#Clock4_24Select#
StringAlign=CenterCenter
AntiAlias=1
Text=24 hour
LeftMouseUpAction=[!WriteKeyValue Variables Clock4_12or24 "H" "#CurrentPath#\clocks.var"][!WriteKeyValue Variables  Clock4_24Select #BackdropColor# "#CurrentPath#\clocks.var"][!WriteKeyValue Variables Clock4_12Select #ColorClear# "#CurrentPath#\clocks.var"][!RefreshGroup TDClocks]
UpdateDivider=-1

[DstMeterTitleClock4]
Meter=String
MeterStyle=TextStyle
StringAlign=Left
X=325
Y=-10R
Text=Daylight Savings Time
UpdateDivider=-1

[DstMeterOnClock4]
Meter=Image
X=5R
Y=1r
W=14
H=14
SolidColor=#Clock4_DSTOnSelect#
LeftMouseUpAction=[!WriteKeyValue Variables Clock4_DST "1" "#CurrentPath#\clocks.var"][!WriteKeyValue Variables Clock4_DSTOnSelect #ColorOn# "#CurrentPath#\clocks.var"][!WriteKeyValue Variables Clock4_DSTOffSelect #BackdropColor# "#CurrentPath#\clocks.var"][!RefreshGroup TDClocks]

[DstMeterOffClock4]
Meter=Image
X=20r
Y=0r
W=14
H=14
SolidColor=#Clock4_DSTOffSelect#
LeftMouseUpAction=[!WriteKeyValue Variables Clock4_DST "0" "#CurrentPath#\clocks.var"][!WriteKeyValue Variables Clock4_DSTOffSelect #ColorOff# "#CurrentPath#\clocks.var"][!WriteKeyValue Variables Clock4_DSTOnSelect #BackdropColor# "#CurrentPath#\clocks.var"][!RefreshGroup TDClocks]
