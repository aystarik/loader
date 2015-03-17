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
Sheet 4 4
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L ACS711 U3
U 1 1 55086909
P 5750 3750
F 0 "U3" H 5750 3500 60  0000 C CNN
F 1 "ACS711" H 5750 4000 60  0000 C CNN
F 2 "Housings_SOIC:SOIC-8_3.9x4.9mm_Pitch1.27mm" H 5750 3750 60  0001 C CNN
F 3 "" H 5750 3750 60  0000 C CNN
	1    5750 3750
	1    0    0    -1  
$EndComp
$Comp
L C C5
U 1 1 550869E6
P 6400 3400
F 0 "C5" H 6425 3500 50  0000 L CNN
F 1 "C" H 6425 3300 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 6438 3250 30  0001 C CNN
F 3 "" H 6400 3400 60  0000 C CNN
	1    6400 3400
	1    0    0    -1  
$EndComp
$Comp
L C C6
U 1 1 55086A19
P 6650 3400
F 0 "C6" H 6675 3500 50  0000 L CNN
F 1 "C" H 6675 3300 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 6688 3250 30  0001 C CNN
F 3 "" H 6650 3400 60  0000 C CNN
	1    6650 3400
	1    0    0    -1  
$EndComp
$Comp
L C C7
U 1 1 55086A55
P 7100 3900
F 0 "C7" H 7125 4000 50  0000 L CNN
F 1 "C" H 7125 3800 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 7138 3750 30  0001 C CNN
F 3 "" H 7100 3900 60  0000 C CNN
	1    7100 3900
	1    0    0    -1  
$EndComp
$Comp
L R R5
U 1 1 55086A70
P 6500 3700
F 0 "R5" V 6580 3700 50  0000 C CNN
F 1 "R" V 6500 3700 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 6430 3700 30  0001 C CNN
F 3 "" H 6500 3700 30  0000 C CNN
	1    6500 3700
	0    1    1    0   
$EndComp
$Comp
L R R6
U 1 1 55086B00
P 6900 3400
F 0 "R6" V 6980 3400 50  0000 C CNN
F 1 "R" V 6900 3400 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 6830 3400 30  0001 C CNN
F 3 "" H 6900 3400 30  0000 C CNN
	1    6900 3400
	1    0    0    -1  
$EndComp
$Comp
L GNDA #PWR01
U 1 1 55086B98
P 6200 4000
F 0 "#PWR01" H 6200 3750 60  0001 C CNN
F 1 "GNDA" H 6200 3850 60  0000 C CNN
F 2 "" H 6200 4000 60  0000 C CNN
F 3 "" H 6200 4000 60  0000 C CNN
	1    6200 4000
	1    0    0    -1  
$EndComp
Wire Wire Line
	6200 3700 6350 3700
Wire Wire Line
	6650 3700 7300 3700
Wire Wire Line
	7100 3700 7100 3750
Wire Wire Line
	6200 3900 6200 4000
Wire Wire Line
	6200 3800 6900 3800
Wire Wire Line
	6900 3800 6900 3550
Wire Wire Line
	6250 3250 7300 3250
Connection ~ 6650 3250
Wire Wire Line
	6300 3550 6650 3550
Wire Wire Line
	6250 3250 6250 3600
Wire Wire Line
	6250 3600 6200 3600
Connection ~ 6400 3250
Wire Wire Line
	6300 3550 6300 4050
Wire Wire Line
	6300 3900 6200 3900
Connection ~ 6400 3550
Wire Wire Line
	6300 4050 7300 4050
Connection ~ 6300 3900
Wire Wire Line
	5300 3700 5250 3700
Wire Wire Line
	5250 3700 5250 3600
Wire Wire Line
	5100 3600 5300 3600
Connection ~ 5250 3600
Wire Wire Line
	5300 3800 5100 3800
Wire Wire Line
	5300 3900 5250 3900
Wire Wire Line
	5250 3900 5250 3800
Connection ~ 5250 3800
Connection ~ 7100 4050
Connection ~ 7100 3700
Connection ~ 6900 3250
Wire Wire Line
	6900 3600 7300 3600
Connection ~ 6900 3600
Text HLabel 5100 3600 0    60   Input ~ 0
IP+
Text HLabel 5100 3800 0    60   Input ~ 0
IP-
Text HLabel 7300 3250 2    60   Input ~ 0
AVCC
Text HLabel 7300 3600 2    60   Input ~ 0
~FAULT
Text HLabel 7300 3700 2    60   Input ~ 0
VOUT
Text HLabel 7300 4050 2    60   Input ~ 0
AGND
$EndSCHEMATC
