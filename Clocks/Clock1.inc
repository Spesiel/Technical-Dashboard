;------------------------------------------------------------------------------
; Measures

[Clock1_MeasureTime_Hours]
Measure=Time
Timezone=#Clock1_Timezone#
DaylightSavingTime=#Clock1_DST#
Format=%#Clock1_12or24#

[Clock1_MeasureTime_Minutes]
Measure=Time
Timezone=#Clock1_Timezone#
DaylightSavingTime=#Clock1_DST#
Format=%M

;------------------------------------------------------------------------------
; Meters

[Clock1_MeterLabel]
Meter=String
MeterStyle=TextStyle
StringStyle=Normal
StringAlign=Center
X=(#Clock2_Display#?[SkinSizing:W]/4:[SkinSizing:W]/2)
Y=0
Text=#Clock1_Label#
IfMatch=^$
IfMatchAction=[!SetOption MeterTimeSeparator Y "10"]
IfNotMatchAction=[!SetOption MeterTimeSeparator Y "-1R"]
UpdateDivider=-1

[Clock1_MeterTimeSeparator]
Meter=String
MeterStyle=TextStyle
StringAlign=Center
X=[Clock1_MeterLabel:X]
Y=-1R
Text=:
FontSize=28
FontColor=#TextColor#
UpdateDivider=-1

[Clock1_MeterTimeHours]
Meter=String
MeterStyle=TextStyle
StringAlign=Right
X=-1r
Y=0r
MeasureName=Clock1_MeasureTime_Hours
Text=%1
FontSize=28

[Clock1_MeterTimeMinutes]
Meter=String
MeterStyle=TextStyle
StringAlign=Left
X=1r
Y=0r
MeasureName=Clock1_MeasureTime_Minutes
Text=%1
FontSize=28