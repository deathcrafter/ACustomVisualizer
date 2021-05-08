[Variables]
GroupCount=6
EditMode=1
UpdateRate=-1
Bands=32
;@About | Name xxx
;@Topic | Name xxx
;@ | Name xxx
;@Topic | Name Audio Analyzer | Icon [\xF0ED]
;@ | Name Equalizer Settings | Icon [\xE908]

;?Integer | Name Attack
Attack=0

;?Integer | Name Decay
Decay=0

;?Integer | Name Smoothing
BlurRadius=0.5

;?Integer | Name Maximum Sensitivity
MaxSensitivity=40

;?Integer | Name Minimum Sensitivity
MinSensitivity=12

;?String | Name Window Functions | Description None : Hann : Kaiser : Hamming : Chebyshev : Exponential
WindowFunction=Kaiser

;?String | Name Channel
Channel=Auto

;?Integer | Name UpdateRate
UpdateRate=16

;@ | Name Device | Icon [\xE95B]

;?Toggle | Name Use DeviceID
DeviceIDbool=0

;?String | Name DeviceID | Description Click on text to choose device.
DeviceID=

;?String | Name Device Name | 
DeviceName=

;?Toggle | Name Use Input | Description DeviceID overrides this setting
IObool=0

Default0=DefaultOutput
Default1=DefaultInput
Analyzer0=[#Default[#IObool]]
Analyzer1="ID: [#DeviceID]"
AnalyzerPort=[#Analyzer[#DeviceIDbool]]
