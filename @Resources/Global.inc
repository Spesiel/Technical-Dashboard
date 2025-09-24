[Rainmeter]
BackgroundMode=2
SolidColor=#BackgroundColor#
BevelType=0
BackgroundMargins=0,0,0,0

;------------------------------------------------------------------------------
; Custom context menu to access different configuration options 

ContextTitle=Configure
ContextAction=[!ToggleConfig "#CurrentConfig#\Config" "Config.ini"]
ContextTitle2=-
ContextTitle3=Refresh
ContextAction3=[!Refresh]

LeftMouseDoubleClickAction=!SkinCustomMenu

[Metadata]
Name=GlobalSettings
Author=Lucky Penny
Information=Default values for every component
License=Creative Commons BY-NC-SA 3.0
Version=0.0.1

;[VarFileInit]
;Measure=Script
;ScriptFile=#@#\VarFileInit.lua

[Variables]

;------------------------------------------------------------------------------
; Color scheme

BackgroundColor=0,0,0,165
TextColor=0,255,0,165
MeterColor=0,128,0,150
BackdropColor=255,255,255,50

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
FontFace=Consolas
FontSize=11
AntiAlias=1
ClipString=1

;------------------------------------------------------------------------------
;------------------------------------------------------------------------------
; Skin sizing

[SkinSizing]
Meter=Image
X=0
Y=0
W=230
H=([DummyEndPoint:Y]-1+[DummyEndPoint:H]+[DummyEndPoint:X])
DynamicVariables=1
UpdateDivider=-1
