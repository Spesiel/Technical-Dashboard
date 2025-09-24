[TitleClock1]
Meter=String
MeterStyle=TextStyle
StringAlign=Left
X=10
Y=10R
Text=Clock1
UpdateDivider=-1

;------------------------------------------------------------------------------
; Meters

[LabelMeterTitleClock1]
Meter=String
MeterStyle=TextStyle
StringAlign=Left
X=25
Y=10R
Text=Label
UpdateDivider=-1

[LabelMeterTextClock1]
Meter=String
X=5R
Y=0r
H=16
W=105
FontSize=10
FontColor=#TextColor#
AntiAlias=1
SolidColor=#BackdropColor#
Text=#Clock1_Label#
LeftMouseUpAction=!CommandMeasure "LabelMeasureInputClock1" "ExecuteBatch 1-2"

[LabelMeasureInputClock1]
Measure=Plugin
Plugin=InputText
X=[LabelMeterTextClock1:X]
Y=[LabelMeterTextClock1:Y]
H=[LabelMeterTextClock1:H]
W=[LabelMeterTextClock1:W]
SolidColor=#TextColor#
FontColor=#BackgroundColor#
FontFace=Seqoe UI
FontSize=10
DefaultValue=#Clock1_Label#
Command1=[!WriteKeyValue Variables Clock1_Label "$UserInput$" "#CurrentPath#\clocks.var"]
Command2=!RefreshGroup TDClocks

[TimezoneMeterTitleClock1]
Meter=String
MeterStyle=TextStyle
StringAlign=Left
X=25
Y=5R
Text=Timezone
UpdateDivider=-1

[TimezoneMeterTextClock1]
Meter=String
X=5R
Y=0r
H=16
W=105
FontSize=10
FontColor=#TextColor#
AntiAlias=1
SolidColor=#BackdropColor#
Text=#Clock1_Timezone#
LeftMouseUpAction=!CommandMeasure "TimezoneMeasureInputClock1" "ExecuteBatch 1-2"

[TimezoneMeasureInputClock1]
Measure=Plugin
Plugin=InputText
X=[TimezoneMeterTextClock1:X]
Y=[TimezoneMeterTextClock1:Y]
H=[TimezoneMeterTextClock1:H]
W=[TimezoneMeterTextClock1:W]
SolidColor=#TextColor#
FontColor=#BackgroundColor#
FontFace=Seqoe UI
FontSize=10
DefaultValue=#Clock1_Timezone#
Command1=[!WriteKeyValue Variables Clock1_Timezone "$UserInput$" "#CurrentPath#\clocks.var"]
Command2=!RefreshGroup TDClocks

[FormatMeterTitleClock1]
Meter=String
MeterStyle=TextStyle
StringAlign=Left
X=25
Y=5R
Text=Format
UpdateDivider=-1

[FormatSet12Clock1]
Meter=String
X=40R
Y=9r
W=70
H=22
FontSize=12
FontColor=#TextColor#
SolidColor=#Clock1_12Select#
StringAlign=CenterCenter
AntiAlias=1
Text=12 hour
LeftMouseUpAction=[!WriteKeyValue Variables Clock1_12or24 "I" "#CurrentPath#\clocks.var"][!WriteKeyValue Variables Clock1_24Select #ColorClear# "#CurrentPath#\clocks.var"][!WriteKeyValue Variables  Clock1_12Select #BackdropColor# "#CurrentPath#\clocks.var"][!RefreshGroup TDClocks]
UpdateDivider=-1

[FormatSet24Clock1]
Meter=String
X=80r
Y=0r
W=70
H=22
FontSize=12
FontColor=#TextColor#
SolidColor=#Clock1_24Select#
StringAlign=CenterCenter
AntiAlias=1
Text=24 hour
LeftMouseUpAction=[!WriteKeyValue Variables Clock1_12or24 "H" "#CurrentPath#\clocks.var"][!WriteKeyValue Variables  Clock1_24Select #BackdropColor# "#CurrentPath#\clocks.var"][!WriteKeyValue Variables Clock1_12Select #ColorClear# "#CurrentPath#\clocks.var"][!RefreshGroup TDClocks]
UpdateDivider=-1

[DstMeterTitleClock1]
Meter=String
MeterStyle=TextStyle
StringAlign=Left
X=25
Y=-10R
Text=Daylight Savings Time
UpdateDivider=-1

[DstMeterOnClock1]
Meter=Image
X=5R
Y=1r
W=14
H=14
SolidColor=#Clock1_DSTOnSelect#
LeftMouseUpAction=[!WriteKeyValue Variables Clock1_DST "1" "#CurrentPath#\clocks.var"][!WriteKeyValue Variables Clock1_DSTOnSelect #ColorOn# "#CurrentPath#\clocks.var"][!WriteKeyValue Variables Clock1_DSTOffSelect #BackdropColor# "#CurrentPath#\clocks.var"][!RefreshGroup TDClocks]

[DstMeterOffClock1]
Meter=Image
X=20r
Y=0r
W=14
H=14
SolidColor=#Clock1_DSTOffSelect#
LeftMouseUpAction=[!WriteKeyValue Variables Clock1_DST "0" "#CurrentPath#\clocks.var"][!WriteKeyValue Variables Clock1_DSTOffSelect #ColorOff# "#CurrentPath#\clocks.var"][!WriteKeyValue Variables Clock1_DSTOnSelect #BackdropColor# "#CurrentPath#\clocks.var"][!RefreshGroup TDClocks]
