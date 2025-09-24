[Metadata]
Name=Config
Author=Lucky Penny
Information=Meters used on components to access the settings
License=Creative Commons BY-NC-SA 3.0
Version=0.0.1

[SkinSizing]
MouseOverAction=!ShowMeter MeterConfig
MouseLeaveAction=!HideMeter MeterConfig

[MeterConfig]
Meter=Image
X=([SkinSizing:W]-20)
Y=5
W=15
H=15
ImageName=#@#\Icons\Settings.png
ImageTint=#TextColor#
ToolTipText=Settings
LeftMouseUpAction=[!ToggleConfig "#CurrentConfig#\Config" "Config.ini"]
Hidden=1
DynamicVariables=1
UpdateDivider=-1
