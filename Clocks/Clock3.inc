;------------------------------------------------------------------------------
; Measures

[Clock3_MeasureTime_Hours]
Measure=Time
Timezone=#Clock3_Timezone#
DaylightSavingTime=#Clock3_DST#
Format=%#Clock3_12or24#

[Clock3_MeasureTime_Minutes]
Measure=Time
Timezone=#Clock3_Timezone#
DaylightSavingTime=#Clock3_DST#
Format=%M

;------------------------------------------------------------------------------
; Meters

[Clock3_MeterLabel]
Meter=String
MeterStyle=TextStyle
StringStyle=Normal
StringAlign=Center
X=(#Clock4_Display#?[SkinSizing:W]/4:[SkinSizing:W]/2)
Y=57
Text=#Clock3_Label#
IfMatch=^$
IfMatchAction=[!SetOption MeterTimeSeparator Y "10"]
IfNotMatchAction=[!SetOption MeterTimeSeparator Y "-1R"]
UpdateDivider=-1
Hidden=(#Clock3_Display#<>1)

[Clock3_MeterTimeSeparator]
Meter=String
MeterStyle=TextStyle
StringAlign=Center
X=[Clock3_MeterLabel:X]
Y=-5R
Text=:
FontSize=26
FontColor=#TextColor#
UpdateDivider=-1
Hidden=(#Clock3_Display#<>1)

[Clock3_MeterTimeHours]
Meter=String
MeterStyle=TextStyle
StringAlign=Right
X=-1r
Y=0r
MeasureName=Clock3_MeasureTime_Hours
Text=%1
FontSize=26
Hidden=(#Clock3_Display#<>1)

[Clock3_MeterTimeMinutes]
Meter=String
MeterStyle=TextStyle
StringAlign=Left
X=1r
Y=0r
MeasureName=Clock3_MeasureTime_Minutes
Text=%1
FontSize=26
Hidden=(#Clock3_Display#<>1)
