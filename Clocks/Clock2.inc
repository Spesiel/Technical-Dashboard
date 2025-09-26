;------------------------------------------------------------------------------
; Measures

[Clock2_MeasureTime_Hours]
Measure=Time
Timezone=#Clock2_Timezone#
DaylightSavingTime=#Clock2_DST#
Format=%#Clock2_12or24#

[Clock2_MeasureTime_Minutes]
Measure=Time
Timezone=#Clock2_Timezone#
DaylightSavingTime=#Clock2_DST#
Format=%M

;------------------------------------------------------------------------------
; Meters

[Clock2_MeterLabel]
Meter=String
MeterStyle=TextStyle
StringStyle=Normal
StringAlign=Center
X=([SkinSizing:W]/4*3)
Y=[Clock1_MeterLabel:Y]
Text=#Clock2_Label#
IfMatch=^$
IfMatchAction=[!SetOption MeterTimeSeparator Y "10"]
IfNotMatchAction=[!SetOption MeterTimeSeparator Y "-1R"]
UpdateDivider=-1
Hidden=(#Clock2_Display#<>1)

[Clock2_MeterTimeSeparator]
Meter=String
MeterStyle=TextStyle
StringAlign=Center
X=[Clock2_MeterLabel:X]
Y=-5R
Text=:
FontSize=26
FontColor=#TextColor#
UpdateDivider=-1
Hidden=(#Clock2_Display#<>1)

[Clock2_MeterTimeHours]
Meter=String
MeterStyle=TextStyle
StringAlign=Right
X=-1r
Y=0r
MeasureName=Clock2_MeasureTime_Hours
Text=%1
FontSize=26
Hidden=(#Clock2_Display#<>1)

[Clock2_MeterTimeMinutes]
Meter=String
MeterStyle=TextStyle
StringAlign=Left
X=1r
Y=0r
MeasureName=Clock2_MeasureTime_Minutes
Text=%1
FontSize=26
Hidden=(#Clock2_Display#<>1)
