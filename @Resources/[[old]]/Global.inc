[Rainmeter]
BackgroundMode=2
SolidColor=#BackgroundColor#
BackgroundMargins=0,0,0,0

;------------------------------------------------------------------------------
; Custom context menu to access different configuration options 

ContextTitle=Configure
ContextAction=[!ToggleConfig "#CurrentConfig#\Config" "Config.ini"]
ContextTitle2=-
ContextTitle3=Configure Scale settings
ContextAction3=[!ActivateConfig "#RootConfig#\ScaleSettings" "ScaleSettings.ini"]
ContextTitle4=Configure Themes
ContextAction4=[!ActivateConfig "#RootConfig#\Themes" "Themes.ini"]
ContextTitle5=-
ContextTitle6=Refresh
ContextAction6=[!Refresh]

LeftMouseDoubleClickAction=!SkinCustomMenu

[Metadata]
Name=GlobalSettings
Author=Lucky Penny
Information=Default values for every component
License=Creative Commons BY-NC-SA 3.0
Version=0.0.3

[VarFileInit]
Measure=Script
ScriptFile=#@#\VarFileInit.lua

@includeVariables=variables.var

[Variables]

;------------------------------------------------------------------------------
; Default scale for every window

Scale=1
Scaling=#Scale#;0;0;#Scale#;#Scale#;#Scale#

;------------------------------------------------------------------------------
; Colors

ColorClear=0,0,0,0
ColorOn=100,250,100
ColorOff=250,100,100

;------------------------------------------------------------------------------
; Measures Styling

[BarStyle]
BarOrientation=Horizontal
BarColor=#MeterColor#
SolidColor=#BackdropColor#

[HistogramStyle]
PrimaryColor=#MeterColor#
SolidColor=#BackdropColor#
AntiAlias=1
AutoScale=1

;------------------------------------------------------------------------------
; Text Styling

[TextStyle]
StringStyle=Bold
StringEffect=Shadow
FontEffectColor=0,0,0,20
FontColor=#TextColor#
FontFace=Trebuchet MS
FontSize=12
AntiAlias=1
ClipString=1

;------------------------------------------------------------------------------
;------------------------------------------------------------------------------
; Skin sizing

[SkinSizing]
Meter=Image
X=0
Y=0
W=(250*#Scale#)
H=(([DummyEndPoint:Y]-1+[DummyEndPoint:H]+[DummyEndPoint:X])*#Scale#)
DynamicVariables=1
UpdateDivider=-1
