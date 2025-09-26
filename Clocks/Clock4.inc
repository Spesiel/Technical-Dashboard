;------------------------------------------------------------------------------
; Measures

[Clock4_MeasureTime_Hours]
Measure=Time
Timezone=#Clock4_Timezone#
DaylightSavingTime=#Clock4_DST#
Format=%#Clock4_12or24#

[Clock4_MeasureTime_Minutes]
Measure=Time
Timezone=#Clock4_Timezone#
DaylightSavingTime=#Clock4_DST#
Format=%M

;------------------------------------------------------------------------------
; Meters

[Clock4_MeterLabel]
Meter=String
MeterStyle=TextStyle
StringStyle=Normal
StringAlign=Center
X=(#Clock3_Display#<>0?[SkinSizing:W]/4*3:[SkinSizing:W]/2)
Y=[Clock3_MeterLabel:Y]
Text=#Clock4_Label#
IfMatch=^$
IfMatchAction=[!SetOption MeterTimeSeparator Y "10"]
IfNotMatchAction=[!SetOption MeterTimeSeparator Y "-1R"]
UpdateDivider=-1
Hidden=(#Clock4_Display#<>1)

[Clock4_MeterTimeSeparator]
Meter=String
MeterStyle=TextStyle
StringAlign=Center
X=[Clock4_MeterLabel:X]
Y=-5R
Text=:
FontSize=26
FontColor=#TextColor#
UpdateDivider=-1
Hidden=(#Clock4_Display#<>1)

[Clock4_MeterTimeHours]
Meter=String
MeterStyle=TextStyle
StringAlign=Right
X=-1r
Y=0r
MeasureName=Clock4_MeasureTime_Hours
Text=%1
FontSize=26
Hidden=(#Clock4_Display#<>1)

[Clock4_MeterTimeMinutes]
Meter=String
MeterStyle=TextStyle
StringAlign=Left
X=1r
Y=0r
MeasureName=Clock4_MeasureTime_Minutes
Text=%1
FontSize=26
Hidden=(#Clock4_Display#<>1)
