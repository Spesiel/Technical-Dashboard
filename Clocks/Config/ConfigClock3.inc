[TitleClock3]
Meter=String
MeterStyle=TextStyle
StringAlign=Left
X=10
Y=10R
Text=Clock3 - Displayed
UpdateDivider=-1

[MeterOnClock3]
Meter=Image
X=5R
Y=1r
W=14
H=14
SolidColor=#Clock3_OnSelect#
LeftMouseUpAction=[!WriteKeyValue Variables Clock3_Display "1" "#CurrentPath#\clocks.var"][!WriteKeyValue Variables Clock3_OnSelect #ColorOn# "#CurrentPath#\clocks.var"][!WriteKeyValue Variables Clock3_OffSelect #BackdropColor# "#CurrentPath#\clocks.var"][!RefreshGroup TDClocks]

[MeterOffClock3]
Meter=Image
X=20r
Y=0r
W=14
H=14
SolidColor=#Clock3_OffSelect#
LeftMouseUpAction=[!WriteKeyValue Variables Clock3_Display "0" "#CurrentPath#\clocks.var"][!WriteKeyValue Variables Clock3_OffSelect #ColorOff# "#CurrentPath#\clocks.var"][!WriteKeyValue Variables Clock3_OnSelect #BackdropColor# "#CurrentPath#\clocks.var"][!RefreshGroup TDClocks]


;------------------------------------------------------------------------------
; Meters

[LabelMeterTitleClock3]
Meter=String
MeterStyle=TextStyle
StringAlign=Left
X=25
Y=10R
Text=Label
UpdateDivider=-1

[LabelMeterTextClock3]
Meter=String
X=5R
Y=0r
H=16
W=105
FontSize=10
FontColor=#TextColor#
AntiAlias=1
SolidColor=#BackdropColor#
Text=#Clock3_Label#
LeftMouseUpAction=!CommandMeasure "LabelMeasureInputClock3" "ExecuteBatch 1-2"

[LabelMeasureInputClock3]
Measure=Plugin
Plugin=InputText
X=[LabelMeterTextClock3:X]
Y=[LabelMeterTextClock3:Y]
H=[LabelMeterTextClock3:H]
W=[LabelMeterTextClock3:W]
SolidColor=#TextColor#
FontColor=#BackgroundColor#
FontFace=Seqoe UI
FontSize=10
DefaultValue=#Clock3_Label#
Command1=[!WriteKeyValue Variables Clock3_Label "$UserInput$" "#CurrentPath#\clocks.var"]
Command2=!RefreshGroup TDClocks

[TimezoneMeterTitleClock3]
Meter=String
MeterStyle=TextStyle
StringAlign=Left
X=25
Y=5R
Text=Timezone
UpdateDivider=-1

[TimezoneMeterTextClock3]
Meter=String
X=5R
Y=0r
H=16
W=105
FontSize=10
FontColor=#TextColor#
AntiAlias=1
SolidColor=#BackdropColor#
Text=#Clock3_Timezone#
LeftMouseUpAction=!CommandMeasure "TimezoneMeasureInputClock3" "ExecuteBatch 1-2"

[TimezoneMeasureInputClock3]
Measure=Plugin
Plugin=InputText
X=[TimezoneMeterTextClock3:X]
Y=[TimezoneMeterTextClock3:Y]
H=[TimezoneMeterTextClock3:H]
W=[TimezoneMeterTextClock3:W]
SolidColor=#TextColor#
FontColor=#BackgroundColor#
FontFace=Seqoe UI
FontSize=10
DefaultValue=#Clock3_Timezone#
Command1=[!WriteKeyValue Variables Clock3_Timezone "$UserInput$" "#CurrentPath#\clocks.var"]
Command2=!RefreshGroup TDClocks

[FormatMeterTitleClock3]
Meter=String
MeterStyle=TextStyle
StringAlign=Left
X=25
Y=5R
Text=Format
UpdateDivider=-1

[FormatSet12Clock3]
Meter=String
X=40R
Y=9r
W=70
H=22
FontSize=12
FontColor=#TextColor#
SolidColor=#Clock3_12Select#
StringAlign=CenterCenter
AntiAlias=1
Text=12 hour
LeftMouseUpAction=[!WriteKeyValue Variables Clock3_12or24 "I" "#CurrentPath#\clocks.var"][!WriteKeyValue Variables Clock3_24Select #ColorClear# "#CurrentPath#\clocks.var"][!WriteKeyValue Variables  Clock3_12Select #BackdropColor# "#CurrentPath#\clocks.var"][!RefreshGroup TDClocks]
UpdateDivider=-1

[FormatSet24Clock3]
Meter=String
X=80r
Y=0r
W=70
H=22
FontSize=12
FontColor=#TextColor#
SolidColor=#Clock3_24Select#
StringAlign=CenterCenter
AntiAlias=1
Text=24 hour
LeftMouseUpAction=[!WriteKeyValue Variables Clock3_12or24 "H" "#CurrentPath#\clocks.var"][!WriteKeyValue Variables  Clock3_24Select #BackdropColor# "#CurrentPath#\clocks.var"][!WriteKeyValue Variables Clock3_12Select #ColorClear# "#CurrentPath#\clocks.var"][!RefreshGroup TDClocks]
UpdateDivider=-1

[DstMeterTitleClock3]
Meter=String
MeterStyle=TextStyle
StringAlign=Left
X=25
Y=-10R
Text=Daylight Savings Time
UpdateDivider=-1

[DstMeterOnClock3]
Meter=Image
X=5R
Y=1r
W=14
H=14
SolidColor=#Clock3_DSTOnSelect#
LeftMouseUpAction=[!WriteKeyValue Variables Clock3_DST "1" "#CurrentPath#\clocks.var"][!WriteKeyValue Variables Clock3_DSTOnSelect #ColorOn# "#CurrentPath#\clocks.var"][!WriteKeyValue Variables Clock3_DSTOffSelect #BackdropColor# "#CurrentPath#\clocks.var"][!RefreshGroup TDClocks]

[DstMeterOffClock3]
Meter=Image
X=20r
Y=0r
W=14
H=14
SolidColor=#Clock3_DSTOffSelect#
LeftMouseUpAction=[!WriteKeyValue Variables Clock3_DST "0" "#CurrentPath#\clocks.var"][!WriteKeyValue Variables Clock3_DSTOffSelect #ColorOff# "#CurrentPath#\clocks.var"][!WriteKeyValue Variables Clock3_DSTOnSelect #BackdropColor# "#CurrentPath#\clocks.var"][!RefreshGroup TDClocks]
