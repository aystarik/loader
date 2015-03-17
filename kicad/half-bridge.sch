EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:special
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:hbridge
LIBS:hbridge2
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 3 4
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Connection ~ 3950 3250
Connection ~ 5950 4200
Wire Wire Line
	5950 3300 6000 3300
Wire Wire Line
	4250 3850 4200 3850
Wire Wire Line
	4250 3750 4200 3750
Connection ~ 5200 3850
Wire Wire Line
	5200 3800 5200 3850
Connection ~ 4250 4200
Wire Wire Line
	4250 3950 4250 4200
Wire Wire Line
	3950 4200 3950 3550
Wire Wire Line
	3950 4200 6000 4200
Connection ~ 4250 3250
Wire Wire Line
	4250 3250 4250 3650
Wire Wire Line
	3900 3250 4500 3250
Wire Wire Line
	5050 3550 5200 3550
Wire Wire Line
	5050 3650 5050 3550
Wire Wire Line
	5200 3250 4800 3250
Wire Wire Line
	5200 3550 5200 3250
$Comp
L D_Schottky D1
U 1 1 55083CB4
P 4650 3250
AR Path="/55081AC3/55083CB4" Ref="D1"  Part="1" 
AR Path="/550849D9/55083CB4" Ref="D2"  Part="1" 
F 0 "D2" H 4650 3350 50  0000 C CNN
F 1 "D_Schottky" H 4650 3150 50  0000 C CNN
F 2 "Diodes_ThroughHole:Diode_DO-35_SOD27_Horizontal_RM10" H 4650 3250 60  0001 C CNN
F 3 "" H 4650 3250 60  0000 C CNN
	1    4650 3250
	1    0    0    -1  
$EndComp
$Comp
L C C1
U 1 1 55083CBB
P 3950 3400
AR Path="/55081AC3/55083CBB" Ref="C1"  Part="1" 
AR Path="/550849D9/55083CBB" Ref="C3"  Part="1" 
F 0 "C3" H 3975 3500 50  0000 L CNN
F 1 "C" H 3975 3300 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 3988 3250 30  0001 C CNN
F 3 "" H 3950 3400 60  0000 C CNN
	1    3950 3400
	1    0    0    -1  
$EndComp
$Comp
L C C2
U 1 1 55083CC2
P 5200 3650
AR Path="/55081AC3/55083CC2" Ref="C2"  Part="1" 
AR Path="/550849D9/55083CC2" Ref="C4"  Part="1" 
F 0 "C4" H 5225 3750 50  0000 L CNN
F 1 "C" H 5225 3550 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 5238 3500 30  0001 C CNN
F 3 "" H 5200 3650 60  0000 C CNN
	1    5200 3650
	1    0    0    -1  
$EndComp
Connection ~ 5950 3750
Wire Wire Line
	5750 3750 6000 3750
Wire Wire Line
	5750 3850 5750 3750
Wire Wire Line
	5050 3850 5750 3850
Wire Wire Line
	5950 3700 5950 3800
Wire Wire Line
	5300 3950 5300 4000
Wire Wire Line
	5050 3950 5300 3950
Wire Wire Line
	5300 3750 5300 3500
Wire Wire Line
	5050 3750 5300 3750
Wire Wire Line
	5600 3500 5650 3500
Wire Wire Line
	5600 4000 5650 4000
$Comp
L R R2
U 1 1 55083CD4
P 5450 4000
AR Path="/55081AC3/55083CD4" Ref="R2"  Part="1" 
AR Path="/550849D9/55083CD4" Ref="R4"  Part="1" 
F 0 "R4" V 5530 4000 50  0000 C CNN
F 1 "R" V 5450 4000 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 5380 4000 30  0001 C CNN
F 3 "" H 5450 4000 30  0000 C CNN
	1    5450 4000
	0    1    1    0   
$EndComp
$Comp
L R R1
U 1 1 55083CDB
P 5450 3500
AR Path="/55081AC3/55083CDB" Ref="R1"  Part="1" 
AR Path="/550849D9/55083CDB" Ref="R3"  Part="1" 
F 0 "R3" V 5530 3500 50  0000 C CNN
F 1 "R" V 5450 3500 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 5380 3500 30  0001 C CNN
F 3 "" H 5450 3500 30  0000 C CNN
	1    5450 3500
	0    1    1    0   
$EndComp
$Comp
L Q_NMOS_DGS Q2
U 1 1 55083CE2
P 5850 4000
AR Path="/55081AC3/55083CE2" Ref="Q2"  Part="1" 
AR Path="/550849D9/55083CE2" Ref="Q4"  Part="1" 
F 0 "Q4" H 6150 4050 50  0000 R CNN
F 1 "Q_NMOS_DGS" H 6500 3950 50  0000 R CNN
F 2 "Transistors_TO-220:TO-220_FET-GDS_Vertical" H 6050 4100 29  0001 C CNN
F 3 "" H 5850 4000 60  0000 C CNN
	1    5850 4000
	1    0    0    -1  
$EndComp
$Comp
L Q_NMOS_DGS Q1
U 1 1 55083CE9
P 5850 3500
AR Path="/55081AC3/55083CE9" Ref="Q1"  Part="1" 
AR Path="/550849D9/55083CE9" Ref="Q3"  Part="1" 
F 0 "Q3" H 6150 3550 50  0000 R CNN
F 1 "Q_NMOS_DGS" H 6500 3450 50  0000 R CNN
F 2 "Transistors_TO-220:TO-220_FET-GDS_Vertical" H 6050 3600 29  0001 C CNN
F 3 "" H 5850 3500 60  0000 C CNN
	1    5850 3500
	1    0    0    -1  
$EndComp
$Comp
L IRS2004 U1
U 1 1 55083CF0
P 4650 3800
AR Path="/55081AC3/55083CF0" Ref="U1"  Part="1" 
AR Path="/550849D9/55083CF0" Ref="U2"  Part="1" 
F 0 "U2" H 4650 3550 60  0000 C CNN
F 1 "IRS2004" H 4650 4050 60  0000 C CNN
F 2 "Housings_SOIC:SOIC-8_3.9x4.9mm_Pitch1.27mm" H 4650 3800 60  0001 C CNN
F 3 "" H 4650 3800 60  0000 C CNN
	1    4650 3800
	1    0    0    -1  
$EndComp
Text HLabel 3900 3250 0    60   Input ~ 0
VCC
Text HLabel 6000 4200 2    60   Input ~ 0
GND
Text HLabel 6000 3750 2    60   Input ~ 0
OUT
Text HLabel 6000 3300 2    60   Input ~ 0
VPP
Text HLabel 4200 3750 0    60   Input ~ 0
IN
Text HLabel 4200 3850 0    60   Input ~ 0
~SD
$EndSCHEMATC
