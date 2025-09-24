[TitleClock2]
Meter=String
MeterStyle=TextStyle
StringAlign=Left
X=310
Y=([Title:Y]+29)
Text=Clock2 - Displayed
UpdateDivider=-1

[MeterOnClock2]
Meter=Image
X=5R
Y=1r
W=14
H=14
SolidColor=#Clock2_OnSelect#
LeftMouseUpAction=[!WriteKeyValue Variables Clock2_Display "1" "#CurrentPath#\clocks.var"][!WriteKeyValue Variables Clock2_OnSelect #ColorOn# "#CurrentPath#\clocks.var"][!WriteKeyValue Variables Clock2_OffSelect #BackdropColor# "#CurrentPath#\clocks.var"][!RefreshGroup TDClocks]

[MeterOffClock2]
Meter=Image
X=20r
Y=0r
W=14
H=14
SolidColor=#Clock2_OffSelect#
LeftMouseUpAction=[!WriteKeyValue Variables Clock2_Display "0" "#CurrentPath#\clocks.var"][!WriteKeyValue Variables Clock2_OffSelect #ColorOff# "#CurrentPath#\clocks.var"][!WriteKeyValue Variables Clock2_OnSelect #BackdropColor# "#CurrentPath#\clocks.var"][!RefreshGroup TDClocks]


;------------------------------------------------------------------------------
; Meters

[LabelMeterTitleClock2]
Meter=String
MeterStyle=TextStyle
StringAlign=Left
X=325
Y=10R
Text=Label
UpdateDivider=-1

[LabelMeterTextClock2]
Meter=String
X=5R
Y=0r
H=16
W=105
FontSize=10
FontColor=#TextColor#
AntiAlias=1
SolidColor=#BackdropColor#
Text=#Clock2_Label#
LeftMouseUpAction=!CommandMeasure "LabelMeasureInputClock2" "ExecuteBatch 1-2"

[LabelMeasureInputClock2]
Measure=Plugin
Plugin=InputText
X=[LabelMeterTextClock2:X]
Y=[LabelMeterTextClock2:Y]
H=[LabelMeterTextClock2:H]
W=[LabelMeterTextClock2:W]
SolidColor=#TextColor#
FontColor=#BackgroundColor#
FontFace=Seqoe UI
FontSize=10
DefaultValue=#Clock2_Label#
Command1=[!WriteKeyValue Variables Clock2_Label "$UserInput$" "#CurrentPath#\clocks.var"]
Command2=!RefreshGroup TDClocks

[TimezoneMeterTitleClock2]
Meter=String
MeterStyle=TextStyle
StringAlign=Left
X=325
Y=5R
Text=Timezone
UpdateDivider=-1

[TimezoneMeterTextClock2]
Meter=String
X=5R
Y=0r
H=16
W=105
FontSize=10
FontColor=#TextColor#
AntiAlias=1
SolidColor=#BackdropColor#
Text=#Clock2_Timezone#
LeftMouseUpAction=!CommandMeasure "TimezoneMeasureInputClock2" "ExecuteBatch 1-2"

[TimezoneMeasureInputClock2]
Measure=Plugin
Plugin=InputText
X=[TimezoneMeterTextClock2:X]
Y=[TimezoneMeterTextClock2:Y]
H=[TimezoneMeterTextClock2:H]
W=[TimezoneMeterTextClock2:W]
SolidColor=#TextColor#
FontColor=#BackgroundColor#
FontFace=Seqoe UI
FontSize=10
DefaultValue=#Clock2_Timezone#
Command1=[!WriteKeyValue Variables Clock2_Timezone "$UserInput$" "#CurrentPath#\clocks.var"]
Command2=!RefreshGroup TDClocks

[FormatMeterTitleClock2]
Meter=String
MeterStyle=TextStyle
StringAlign=Left
X=325
Y=5R
Text=Format
UpdateDivider=-1

[FormatSet12Clock2]
Meter=String
X=40R
Y=9r
W=70
H=22
FontSize=12
FontColor=#TextColor#
SolidColor=#Clock2_12Select#
StringAlign=CenterCenter
AntiAlias=1
Text=12 hour
LeftMouseUpAction=[!WriteKeyValue Variables Clock2_12or24 "I" "#CurrentPath#\clocks.var"][!WriteKeyValue Variables Clock2_24Select #ColorClear# "#CurrentPath#\clocks.var"][!WriteKeyValue Variables  Clock2_12Select #BackdropColor# "#CurrentPath#\clocks.var"][!RefreshGroup TDClocks]
UpdateDivider=-1

[FormatSet24Clock2]
Meter=String
X=80r
Y=0r
W=70
H=22
FontSize=12
FontColor=#TextColor#
SolidColor=#Clock2_24Select#
StringAlign=CenterCenter
AntiAlias=1
Text=24 hour
LeftMouseUpAction=[!WriteKeyValue Variables Clock2_12or24 "H" "#CurrentPath#\clocks.var"][!WriteKeyValue Variables  Clock2_24Select #BackdropColor# "#CurrentPath#\clocks.var"][!WriteKeyValue Variables Clock2_12Select #ColorClear# "#CurrentPath#\clocks.var"][!RefreshGroup TDClocks]
UpdateDivider=-1

[DstMeterTitleClock2]
Meter=String
MeterStyle=TextStyle
StringAlign=Left
X=325
Y=-10R
Text=Daylight Savings Time
UpdateDivider=-1

[DstMeterOnClock2]
Meter=Image
X=5R
Y=1r
W=14
H=14
SolidColor=#Clock2_DSTOnSelect#
LeftMouseUpAction=[!WriteKeyValue Variables Clock2_DST "1" "#CurrentPath#\clocks.var"][!WriteKeyValue Variables Clock2_DSTOnSelect #ColorOn# "#CurrentPath#\clocks.var"][!WriteKeyValue Variables Clock2_DSTOffSelect #BackdropColor# "#CurrentPath#\clocks.var"][!RefreshGroup TDClocks]

[DstMeterOffClock2]
Meter=Image
X=20r
Y=0r
W=14
H=14
SolidColor=#Clock2_DSTOffSelect#
LeftMouseUpAction=[!WriteKeyValue Variables Clock2_DST "0" "#CurrentPath#\clocks.var"][!WriteKeyValue Variables Clock2_DSTOffSelect #ColorOff# "#CurrentPath#\clocks.var"][!WriteKeyValue Variables Clock2_DSTOnSelect #BackdropColor# "#CurrentPath#\clocks.var"][!RefreshGroup TDClocks]
