EESchema Schematic File Version 4
LIBS:Magnetometer_A-cache
EELAYER 29 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
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
L Connector:Conn_01x19_Female J3
U 1 1 60608B31
P 1600 1650
F 0 "J3" H 1628 1676 50  0000 L CNN
F 1 "Conn_01x19_Female" H 1628 1585 50  0000 L CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x19_Pitch2.54mm" H 1600 1650 50  0001 C CNN
F 3 "~" H 1600 1650 50  0001 C CNN
	1    1600 1650
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x19_Female J6
U 1 1 6060B9B4
P 2450 1650
F 0 "J6" H 2342 525 50  0000 C CNN
F 1 "Conn_01x19_Female" H 2342 616 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x19_Pitch2.54mm" H 2450 1650 50  0001 C CNN
F 3 "~" H 2450 1650 50  0001 C CNN
	1    2450 1650
	-1   0    0    1   
$EndComp
$Comp
L Connector:Conn_01x06_Female J27
U 1 1 6061982B
P 6950 2200
F 0 "J27" H 6800 2550 50  0000 L CNN
F 1 "Conn_01x06_Female" H 6250 1750 50  0000 L CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x06_Pitch2.54mm" H 6950 2200 50  0001 C CNN
F 3 "~" H 6950 2200 50  0001 C CNN
	1    6950 2200
	1    0    0    -1  
$EndComp
Wire Notes Line
	7050 500  7050 3000
$Comp
L Connector:Conn_01x04_Male J35
U 1 1 6061CD57
P 8050 1100
F 0 "J35" H 7942 675 50  0000 C CNN
F 1 "Conn_01x04_Male" H 7942 766 50  0000 C CNN
F 2 "Connectors_Molex:Molex_PicoBlade_53047-0410_04x1.25mm_Straight" H 8050 1100 50  0001 C CNN
F 3 "~" H 8050 1100 50  0001 C CNN
	1    8050 1100
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x04_Male J36
U 1 1 6061E290
P 8050 2550
F 0 "J36" H 7942 2125 50  0000 C CNN
F 1 "Conn_01x04_Male" H 7942 2216 50  0000 C CNN
F 2 "Connectors_Molex:Molex_PicoBlade_53047-0410_04x1.25mm_Straight" H 8050 2550 50  0001 C CNN
F 3 "~" H 8050 2550 50  0001 C CNN
	1    8050 2550
	1    0    0    -1  
$EndComp
$Comp
L Device:Microphone_Condenser MK1
U 1 1 60633093
P 10350 2350
F 0 "MK1" H 10250 2000 50  0000 L CNN
F 1 "Microphone_Condenser" V 10150 1950 50  0000 L CNN
F 2 "Jumper:SolderJumper-2_P1.3mm_Open_Pad1.0x1.5mm" V 10350 2450 50  0001 C CNN
F 3 "~" V 10350 2450 50  0001 C CNN
	1    10350 2350
	1    0    0    -1  
$EndComp
$Comp
L Device:R R11
U 1 1 606354FF
P 10650 2300
F 0 "R11" H 10720 2346 50  0000 L CNN
F 1 "2K2R" H 10720 2255 50  0000 L CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 10580 2300 50  0001 C CNN
F 3 "~" H 10650 2300 50  0001 C CNN
	1    10650 2300
	1    0    0    -1  
$EndComp
$Comp
L Device:C C2
U 1 1 60636605
P 10800 2150
F 0 "C2" V 10548 2150 50  0000 C CNN
F 1 "1uF" V 10639 2150 50  0000 C CNN
F 2 "Capacitors_SMD:C_0402" H 10838 2000 50  0001 C CNN
F 3 "~" H 10800 2150 50  0001 C CNN
	1    10800 2150
	0    1    1    0   
$EndComp
Connection ~ 10650 2150
Wire Wire Line
	10650 2450 10950 2450
Wire Wire Line
	10350 2150 10650 2150
Wire Wire Line
	10350 2550 10950 2550
$Comp
L Connector:Conn_01x06_Male J28
U 1 1 60648CAD
P 6850 3450
F 0 "J28" V 6696 3698 50  0000 L CNN
F 1 "Conn_01x06_Male" V 6787 3698 50  0000 L CNN
F 2 "Connectors_Molex:Molex_PicoBlade_53048-0610_06x1.25mm_Angled" H 6850 3450 50  0001 C CNN
F 3 "~" H 6850 3450 50  0001 C CNN
	1    6850 3450
	0    -1   -1   0   
$EndComp
$Comp
L Connector:Conn_01x04_Male J1
U 1 1 60653CE4
P 800 5150
F 0 "J1" V 954 4962 50  0000 R CNN
F 1 "Conn_01x04_Male" V 863 4962 50  0000 R CNN
F 2 "Connectors_Molex:Molex_PicoBlade_53047-0410_04x1.25mm_Straight" H 800 5150 50  0001 C CNN
F 3 "~" H 800 5150 50  0001 C CNN
	1    800  5150
	0    -1   -1   0   
$EndComp
$Comp
L Connector:Conn_01x04_Male J2
U 1 1 60654F53
P 800 4550
F 0 "J2" V 850 4250 50  0000 L CNN
F 1 "Conn_01x04_Male" V 750 3700 50  0000 L CNN
F 2 "Connectors_Molex:Molex_PicoBlade_53047-0410_04x1.25mm_Straight" H 800 4550 50  0001 C CNN
F 3 "~" H 800 4550 50  0001 C CNN
	1    800  4550
	0    -1   -1   0   
$EndComp
$Comp
L Connector:Conn_01x04_Male J37
U 1 1 60656C91
P 8500 3450
F 0 "J37" V 8346 3598 50  0000 L CNN
F 1 "Conn_01x04_Male" V 8437 3598 50  0000 L CNN
F 2 "Connectors_Molex:Molex_PicoBlade_53047-0410_04x1.25mm_Straight" H 8500 3450 50  0001 C CNN
F 3 "~" H 8500 3450 50  0001 C CNN
	1    8500 3450
	0    -1   -1   0   
$EndComp
$Comp
L Connector:Conn_01x04_Male J38
U 1 1 60658900
P 8500 4000
F 0 "J38" V 8346 4148 50  0000 L CNN
F 1 "Conn_01x04_Male" V 8437 4148 50  0000 L CNN
F 2 "Connectors_Molex:Molex_PicoBlade_53047-0410_04x1.25mm_Straight" H 8500 4000 50  0001 C CNN
F 3 "~" H 8500 4000 50  0001 C CNN
	1    8500 4000
	0    -1   -1   0   
$EndComp
$Comp
L Connector:Conn_01x04_Male J39
U 1 1 60659E55
P 8500 4550
F 0 "J39" V 8346 4698 50  0000 L CNN
F 1 "Conn_01x04_Male" V 8437 4698 50  0000 L CNN
F 2 "Connectors_Molex:Molex_PicoBlade_53048-0410_04x1.25mm_Angled" H 8500 4550 50  0001 C CNN
F 3 "~" H 8500 4550 50  0001 C CNN
	1    8500 4550
	0    -1   -1   0   
$EndComp
$Comp
L Connector:Conn_01x04_Male J40
U 1 1 6065B383
P 8500 5200
F 0 "J40" V 8346 5348 50  0000 L CNN
F 1 "Conn_01x04_Male" V 8437 5348 50  0000 L CNN
F 2 "Connectors_Molex:Molex_PicoBlade_53048-0410_04x1.25mm_Angled" H 8500 5200 50  0001 C CNN
F 3 "~" H 8500 5200 50  0001 C CNN
	1    8500 5200
	0    -1   -1   0   
$EndComp
$Comp
L Connector:Conn_01x04_Male J41
U 1 1 6065C269
P 9900 3500
F 0 "J41" V 10054 3212 50  0000 R CNN
F 1 "Conn_01x04_Male" V 9963 3212 50  0000 R CNN
F 2 "Connectors_Molex:Molex_PicoBlade_53048-0410_04x1.25mm_Angled" H 9900 3500 50  0001 C CNN
F 3 "~" H 9900 3500 50  0001 C CNN
	1    9900 3500
	0    -1   -1   0   
$EndComp
$Comp
L Connector:Conn_01x04_Male J42
U 1 1 6065C929
P 9900 4000
F 0 "J42" V 10054 3712 50  0000 R CNN
F 1 "Conn_01x04_Male" V 9963 3712 50  0000 R CNN
F 2 "Connectors_Molex:Molex_PicoBlade_53048-0410_04x1.25mm_Angled" H 9900 4000 50  0001 C CNN
F 3 "~" H 9900 4000 50  0001 C CNN
	1    9900 4000
	0    -1   -1   0   
$EndComp
$Comp
L Connector:Conn_01x04_Male J43
U 1 1 6065D3F4
P 9900 4500
F 0 "J43" V 10054 4212 50  0000 R CNN
F 1 "Conn_01x04_Male" V 9963 4212 50  0000 R CNN
F 2 "Connectors_Molex:Molex_PicoBlade_53048-0410_04x1.25mm_Angled" H 9900 4500 50  0001 C CNN
F 3 "~" H 9900 4500 50  0001 C CNN
	1    9900 4500
	0    -1   -1   0   
$EndComp
$Comp
L Connector:Conn_01x04_Male J44
U 1 1 6065DCEA
P 9900 5150
F 0 "J44" V 10054 4862 50  0000 R CNN
F 1 "Conn_01x04_Male" V 9963 4862 50  0000 R CNN
F 2 "Connectors_Molex:Molex_PicoBlade_53048-0410_04x1.25mm_Angled" H 9900 5150 50  0001 C CNN
F 3 "~" H 9900 5150 50  0001 C CNN
	1    9900 5150
	0    -1   -1   0   
$EndComp
Wire Notes Line
	3400 5300 500  5300
Wire Notes Line
	3400 500  3400 5700
$Comp
L Connector:Conn_01x04_Male J5
U 1 1 606C2D28
P 1900 4450
F 0 "J5" V 1950 4150 50  0000 L CNN
F 1 "Conn_01x04_Male" V 1850 3600 50  0000 L CNN
F 2 "Connectors_Molex:Molex_PicoBlade_53047-0410_04x1.25mm_Straight" H 1900 4450 50  0001 C CNN
F 3 "~" H 1900 4450 50  0001 C CNN
	1    1900 4450
	0    -1   -1   0   
$EndComp
Text GLabel 1400 750  0    50   Input ~ 0
3V3
$Comp
L Device:C C1
U 1 1 606CEDAA
P 850 1950
F 0 "C1" H 965 1996 50  0000 L CNN
F 1 "10uF" H 965 1905 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 888 1800 50  0001 C CNN
F 3 "~" H 850 1950 50  0001 C CNN
	1    850  1950
	1    0    0    -1  
$EndComp
Text GLabel 1400 850  0    50   Input ~ 0
EN
Text GLabel 1400 1150 0    50   Input ~ 0
34
Text GLabel 1400 1350 0    50   Input ~ 0
32
Text GLabel 1400 1450 0    50   Input ~ 0
33
Text GLabel 1400 1750 0    50   Input ~ 0
27
Text GLabel 1400 2050 0    50   Input ~ 0
GND
Text GLabel 850  2100 3    50   Input ~ 0
GND
Text GLabel 1400 2250 0    50   Input ~ 0
D2
Text GLabel 1400 2450 0    50   Input ~ 0
CD_CMD
Text GLabel 1400 2550 0    50   Input ~ 0
5V
Text GLabel 850  1800 1    50   Input ~ 0
EN
Text GLabel 2650 750  2    50   Input ~ 0
GND
Text GLabel 2650 850  2    50   Input ~ 0
23
Text GLabel 2650 950  2    50   Input ~ 0
22
Text GLabel 2650 1050 2    50   Input ~ 0
TX
Text GLabel 2650 1150 2    50   Input ~ 0
RX
Text GLabel 2650 1250 2    50   Input ~ 0
21
Text GLabel 2650 1350 2    50   Input ~ 0
GND
Text GLabel 1400 2350 0    50   Input ~ 0
D3
Text GLabel 2650 1450 2    50   Input ~ 0
19
Text GLabel 2650 1550 2    50   Input ~ 0
18
Text GLabel 2650 1650 2    50   Input ~ 0
5
Text GLabel 2650 1750 2    50   Input ~ 0
17
Text GLabel 2650 1850 2    50   Input ~ 0
16
Text GLabel 2650 2150 2    50   Input ~ 0
2
Text GLabel 2650 2350 2    50   Input ~ 0
SD_SATA_1
Text GLabel 2650 2450 2    50   Input ~ 0
SD_DATA_0
Text GLabel 2650 2550 2    50   Input ~ 0
CD_CLK
$Comp
L Connector:Conn_01x06_Female J32
U 1 1 6070A8E8
P 7000 900
F 0 "J32" H 6850 1250 50  0000 L CNN
F 1 "Conn_01x06_Female" H 6250 500 50  0000 L CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x06_Pitch2.54mm" H 7000 900 50  0001 C CNN
F 3 "~" H 7000 900 50  0001 C CNN
	1    7000 900 
	1    0    0    -1  
$EndComp
Wire Notes Line
	8050 5700 8050 3000
Text GLabel 5700 1700 2    50   Input ~ 0
3V3
Text GLabel 5700 1600 2    50   Input ~ 0
3V3
Text GLabel 5700 1500 2    50   Input ~ 0
GND
Text GLabel 4750 2100 0    50   Input ~ 0
GND
NoConn ~ 5700 1800
NoConn ~ 5700 2000
NoConn ~ 5700 2100
NoConn ~ 4750 2000
$Comp
L Connector:Conn_01x07_Female J23
U 1 1 60611D6F
P 5500 1800
F 0 "J23" H 5392 1275 50  0000 C CNN
F 1 "Conn_01x07_Female" H 5392 1366 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x07_Pitch2.54mm" H 5500 1800 50  0001 C CNN
F 3 "~" H 5500 1800 50  0001 C CNN
	1    5500 1800
	-1   0    0    1   
$EndComp
$Comp
L Connector:Conn_01x03_Male J15
U 1 1 6073969A
P 4350 1150
F 0 "J15" V 4504 962 50  0000 R CNN
F 1 "Conn_01x03_Male" V 4300 1450 50  0000 R CNN
F 2 "Jumper:SolderJumper-3_P1.3mm_Open_Pad1.0x1.5mm" H 4350 1150 50  0001 C CNN
F 3 "~" H 4350 1150 50  0001 C CNN
	1    4350 1150
	0    -1   -1   0   
$EndComp
Wire Notes Line
	6100 500  6100 5700
$Comp
L Connector:Conn_01x03_Male J13
U 1 1 607A348F
P 3850 2700
F 0 "J13" V 4004 2512 50  0000 R CNN
F 1 "Conn_01x03_Male" V 3800 3000 50  0000 R CNN
F 2 "Jumper:SolderJumper-3_P1.3mm_Open_Pad1.0x1.5mm" H 3850 2700 50  0001 C CNN
F 3 "~" H 3850 2700 50  0001 C CNN
	1    3850 2700
	0    -1   -1   0   
$EndComp
$Comp
L Connector:Conn_01x03_Male J21
U 1 1 607A3DAD
P 5400 2700
F 0 "J21" V 5554 2512 50  0000 R CNN
F 1 "Conn_01x03_Male" V 5350 3000 50  0000 R CNN
F 2 "Jumper:SolderJumper-3_P1.3mm_Open_Pad1.0x1.5mm" H 5400 2700 50  0001 C CNN
F 3 "~" H 5400 2700 50  0001 C CNN
	1    5400 2700
	0    -1   -1   0   
$EndComp
Text GLabel 4750 1500 0    50   Input ~ 0
RM1CLK
Text GLabel 4350 950  1    50   Input ~ 0
RM1CLK
Text GLabel 4450 950  1    50   Input ~ 0
18
Text GLabel 4250 950  1    50   Input ~ 0
22
Text GLabel 4750 1600 0    50   Input ~ 0
RM1MISO
Text GLabel 3750 1100 1    50   Input ~ 0
RM1MISO
Text GLabel 3850 1100 1    50   Input ~ 0
19
$Comp
L Connector:Conn_01x02_Male J9
U 1 1 607C746A
P 3750 1300
F 0 "J9" V 3904 1112 50  0000 R CNN
F 1 "Conn_01x02_Male" V 3700 1600 50  0000 R CNN
F 2 "Jumper:SolderJumper-2_P1.3mm_Open_Pad1.0x1.5mm" H 3750 1300 50  0001 C CNN
F 3 "~" H 3750 1300 50  0001 C CNN
	1    3750 1300
	0    -1   -1   0   
$EndComp
$Comp
L Connector:Conn_01x03_Male J10
U 1 1 607CA4A7
P 3750 2000
F 0 "J10" V 3904 1812 50  0000 R CNN
F 1 "Conn_01x03_Male" V 3700 2300 50  0000 R CNN
F 2 "Jumper:SolderJumper-3_P1.3mm_Open_Pad1.0x1.5mm" H 3750 2000 50  0001 C CNN
F 3 "~" H 3750 2000 50  0001 C CNN
	1    3750 2000
	0    -1   -1   0   
$EndComp
Text GLabel 3750 1800 1    50   Input ~ 0
RM1MISO
Text GLabel 3850 1800 1    50   Input ~ 0
3V3
Text GLabel 3650 1800 1    50   Input ~ 0
GND
Text GLabel 4750 1700 0    50   Input ~ 0
RM1MOSI
Text GLabel 3950 2500 1    50   Input ~ 0
23
Text GLabel 3750 2500 1    50   Input ~ 0
21
Text GLabel 4750 1800 0    50   Input ~ 0
RM1SS
Text GLabel 4600 2500 1    50   Input ~ 0
RM1SS
$Comp
L Connector:Conn_01x02_Male J17
U 1 1 607FA186
P 4600 2700
F 0 "J17" V 4754 2512 50  0000 R CNN
F 1 "Conn_01x02_Male" V 4550 3000 50  0000 R CNN
F 2 "Jumper:SolderJumper-2_P1.3mm_Open_Pad1.0x1.5mm" H 4600 2700 50  0001 C CNN
F 3 "~" H 4600 2700 50  0001 C CNN
	1    4600 2700
	0    -1   -1   0   
$EndComp
$Comp
L Connector:Conn_01x07_Female J19
U 1 1 60611472
P 4950 1800
F 0 "J19" H 4850 2350 50  0000 L CNN
F 1 "Conn_01x07_Female" H 4550 2250 50  0000 L CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x07_Pitch2.54mm" H 4950 1800 50  0001 C CNN
F 3 "~" H 4950 1800 50  0001 C CNN
	1    4950 1800
	1    0    0    -1  
$EndComp
Text GLabel 4700 2500 1    50   Input ~ 0
5
Text GLabel 5400 2500 1    50   Input ~ 0
RM1SS
Text GLabel 5750 900  1    50   Input ~ 0
3V3
Text GLabel 5300 2500 1    50   Input ~ 0
GND
Text GLabel 3850 2500 1    50   Input ~ 0
RM1MOSI
Text GLabel 5700 1900 2    50   Input ~ 0
RM1EN
$Comp
L Connector:Conn_01x03_Male J25
U 1 1 60813101
P 5650 1100
F 0 "J25" V 5804 912 50  0000 R CNN
F 1 "Conn_01x03_Male" V 5600 1400 50  0000 R CNN
F 2 "Jumper:SolderJumper-3_P1.3mm_Open_Pad1.0x1.5mm" H 5650 1100 50  0001 C CNN
F 3 "~" H 5650 1100 50  0001 C CNN
	1    5650 1100
	0    -1   -1   0   
$EndComp
Text GLabel 5650 900  1    50   Input ~ 0
RM1EN
Text GLabel 5500 2500 1    50   Input ~ 0
3V3
Text GLabel 5550 900  1    50   Input ~ 0
GND
Wire Notes Line
	500  3000 11200 3000
Text GLabel 900  4350 1    50   Input ~ 0
16
Text GLabel 900  4950 1    50   Input ~ 0
16
Text GLabel 800  4350 1    50   Input ~ 0
5V
Text GLabel 800  4950 1    50   Input ~ 0
5V
Text GLabel 2000 4250 1    50   Input ~ 0
RX
Text GLabel 1900 4250 1    50   Input ~ 0
3V3
Text GLabel 5700 4200 2    50   Input ~ 0
3V3
Text GLabel 5700 4100 2    50   Input ~ 0
3V3
Text GLabel 5700 4000 2    50   Input ~ 0
GND
Text GLabel 4750 4600 0    50   Input ~ 0
GND
NoConn ~ 5700 4300
NoConn ~ 5700 4500
NoConn ~ 5700 4600
NoConn ~ 4750 4500
$Comp
L Connector:Conn_01x07_Female J24
U 1 1 608C8094
P 5500 4300
F 0 "J24" H 5392 3775 50  0000 C CNN
F 1 "Conn_01x07_Female" H 5392 3866 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x07_Pitch2.54mm" H 5500 4300 50  0001 C CNN
F 3 "~" H 5500 4300 50  0001 C CNN
	1    5500 4300
	-1   0    0    1   
$EndComp
$Comp
L Connector:Conn_01x03_Male J16
U 1 1 608C809E
P 4350 3650
F 0 "J16" V 4504 3462 50  0000 R CNN
F 1 "Conn_01x03_Male" V 4300 3950 50  0000 R CNN
F 2 "Jumper:SolderJumper-3_P1.3mm_Open_Pad1.0x1.5mm" H 4350 3650 50  0001 C CNN
F 3 "~" H 4350 3650 50  0001 C CNN
	1    4350 3650
	0    -1   -1   0   
$EndComp
$Comp
L Connector:Conn_01x03_Male J14
U 1 1 608C80A8
P 3850 5200
F 0 "J14" V 4004 5012 50  0000 R CNN
F 1 "Conn_01x03_Male" V 3800 5500 50  0000 R CNN
F 2 "Jumper:SolderJumper-3_P1.3mm_Open_Pad1.0x1.5mm" H 3850 5200 50  0001 C CNN
F 3 "~" H 3850 5200 50  0001 C CNN
	1    3850 5200
	0    -1   -1   0   
$EndComp
$Comp
L Connector:Conn_01x03_Male J22
U 1 1 608C80B2
P 5400 5200
F 0 "J22" V 5554 5012 50  0000 R CNN
F 1 "Conn_01x03_Male" V 5350 5500 50  0000 R CNN
F 2 "Jumper:SolderJumper-3_P1.3mm_Open_Pad1.0x1.5mm" H 5400 5200 50  0001 C CNN
F 3 "~" H 5400 5200 50  0001 C CNN
	1    5400 5200
	0    -1   -1   0   
$EndComp
Text GLabel 4750 4000 0    50   Input ~ 0
RM2CLK
Text GLabel 4350 3450 1    50   Input ~ 0
RM2CLK
Text GLabel 4450 3450 1    50   Input ~ 0
18
Text GLabel 4250 3450 1    50   Input ~ 0
22
Text GLabel 4750 4100 0    50   Input ~ 0
RM2MISO
Text GLabel 3750 3600 1    50   Input ~ 0
RM2MISO
Text GLabel 3850 3600 1    50   Input ~ 0
19
$Comp
L Connector:Conn_01x02_Male J11
U 1 1 608C80C3
P 3750 3800
F 0 "J11" V 3904 3612 50  0000 R CNN
F 1 "Conn_01x02_Male" V 3700 4100 50  0000 R CNN
F 2 "Jumper:SolderJumper-2_P1.3mm_Open_Pad1.0x1.5mm" H 3750 3800 50  0001 C CNN
F 3 "~" H 3750 3800 50  0001 C CNN
	1    3750 3800
	0    -1   -1   0   
$EndComp
$Comp
L Connector:Conn_01x03_Male J12
U 1 1 608C80CD
P 3750 4500
F 0 "J12" V 3904 4312 50  0000 R CNN
F 1 "Conn_01x03_Male" V 3700 4800 50  0000 R CNN
F 2 "Jumper:SolderJumper-3_P1.3mm_Open_Pad1.0x1.5mm" H 3750 4500 50  0001 C CNN
F 3 "~" H 3750 4500 50  0001 C CNN
	1    3750 4500
	0    -1   -1   0   
$EndComp
Text GLabel 3750 4300 1    50   Input ~ 0
RM2MISO
Text GLabel 3850 4300 1    50   Input ~ 0
3V3
Text GLabel 3650 4300 1    50   Input ~ 0
GND
Text GLabel 4750 4200 0    50   Input ~ 0
RM2MOSI
Text GLabel 3950 5000 1    50   Input ~ 0
23
Text GLabel 3750 5000 1    50   Input ~ 0
21
Text GLabel 4750 4300 0    50   Input ~ 0
RM2SS
Text GLabel 4600 5000 1    50   Input ~ 0
RM2SS
$Comp
L Connector:Conn_01x02_Male J18
U 1 1 608C80DF
P 4600 5200
F 0 "J18" V 4754 5012 50  0000 R CNN
F 1 "Conn_01x02_Male" V 4550 5500 50  0000 R CNN
F 2 "Jumper:SolderJumper-2_P1.3mm_Open_Pad1.0x1.5mm" H 4600 5200 50  0001 C CNN
F 3 "~" H 4600 5200 50  0001 C CNN
	1    4600 5200
	0    -1   -1   0   
$EndComp
$Comp
L Connector:Conn_01x07_Female J20
U 1 1 608C80E9
P 4950 4300
F 0 "J20" H 4850 4850 50  0000 L CNN
F 1 "Conn_01x07_Female" H 4550 4750 50  0000 L CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x07_Pitch2.54mm" H 4950 4300 50  0001 C CNN
F 3 "~" H 4950 4300 50  0001 C CNN
	1    4950 4300
	1    0    0    -1  
$EndComp
Text GLabel 4700 5000 1    50   Input ~ 0
2
Text GLabel 5400 5000 1    50   Input ~ 0
RM2SS
Text GLabel 5750 3400 1    50   Input ~ 0
3V3
Text GLabel 5300 5000 1    50   Input ~ 0
GND
Text GLabel 3850 5000 1    50   Input ~ 0
RM2MOSI
Text GLabel 5700 4400 2    50   Input ~ 0
RM2EN
$Comp
L Connector:Conn_01x03_Male J26
U 1 1 608C80F9
P 5650 3600
F 0 "J26" V 5804 3412 50  0000 R CNN
F 1 "Conn_01x03_Male" V 5600 3900 50  0000 R CNN
F 2 "Jumper:SolderJumper-3_P1.3mm_Open_Pad1.0x1.5mm" H 5650 3600 50  0001 C CNN
F 3 "~" H 5650 3600 50  0001 C CNN
	1    5650 3600
	0    -1   -1   0   
$EndComp
Text GLabel 5650 3400 1    50   Input ~ 0
RM2EN
Text GLabel 5500 5000 1    50   Input ~ 0
3V3
Text GLabel 5550 3400 1    50   Input ~ 0
GND
Wire Notes Line
	3400 5700 11200 5700
NoConn ~ 4750 1900
NoConn ~ 4750 4400
Text GLabel 6650 3250 1    50   Input ~ 0
18
Text GLabel 6750 3250 1    50   Input ~ 0
19
Text GLabel 6850 3250 1    50   Input ~ 0
23
Text GLabel 6950 3250 1    50   Input ~ 0
5
Text GLabel 7050 3250 1    50   Input ~ 0
3V3
Text GLabel 7150 3250 1    50   Input ~ 0
GND
$Comp
L Connector:Conn_01x06_Male J29
U 1 1 608F9596
P 6850 4100
F 0 "J29" V 6696 4348 50  0000 L CNN
F 1 "Conn_01x06_Male" V 6787 4348 50  0000 L CNN
F 2 "Connectors_Molex:Molex_PicoBlade_53047-0610_06x1.25mm_Straight" H 6850 4100 50  0001 C CNN
F 3 "~" H 6850 4100 50  0001 C CNN
	1    6850 4100
	0    -1   -1   0   
$EndComp
Text GLabel 6650 3900 1    50   Input ~ 0
18
Text GLabel 6750 3900 1    50   Input ~ 0
19
Text GLabel 6850 3900 1    50   Input ~ 0
23
Text GLabel 6950 3900 1    50   Input ~ 0
5
Text GLabel 7050 3900 1    50   Input ~ 0
3V3
Text GLabel 7150 3900 1    50   Input ~ 0
GND
$Comp
L Connector:Conn_01x06_Male J30
U 1 1 6090511D
P 6850 4750
F 0 "J30" V 6696 4998 50  0000 L CNN
F 1 "Conn_01x06_Male" V 6787 4998 50  0000 L CNN
F 2 "Connectors_Molex:Molex_PicoBlade_53047-0610_06x1.25mm_Straight" H 6850 4750 50  0001 C CNN
F 3 "~" H 6850 4750 50  0001 C CNN
	1    6850 4750
	0    -1   -1   0   
$EndComp
Text GLabel 6650 4550 1    50   Input ~ 0
18
Text GLabel 6750 4550 1    50   Input ~ 0
19
Text GLabel 6850 4550 1    50   Input ~ 0
23
Text GLabel 6950 4550 1    50   Input ~ 0
2
Text GLabel 7050 4550 1    50   Input ~ 0
3V3
Text GLabel 7150 4550 1    50   Input ~ 0
GND
$Comp
L Connector:Conn_01x06_Male J31
U 1 1 609101A6
P 6850 5400
F 0 "J31" V 6696 5648 50  0000 L CNN
F 1 "Conn_01x06_Male" V 6787 5648 50  0000 L CNN
F 2 "Connectors_Molex:Molex_PicoBlade_53048-0610_06x1.25mm_Angled" H 6850 5400 50  0001 C CNN
F 3 "~" H 6850 5400 50  0001 C CNN
	1    6850 5400
	0    -1   -1   0   
$EndComp
Text GLabel 6650 5200 1    50   Input ~ 0
18
Text GLabel 6750 5200 1    50   Input ~ 0
19
Text GLabel 6850 5200 1    50   Input ~ 0
23
Text GLabel 6950 5200 1    50   Input ~ 0
2
Text GLabel 7050 5200 1    50   Input ~ 0
3V3
Text GLabel 7150 5200 1    50   Input ~ 0
GND
NoConn ~ 6800 1100
NoConn ~ 6800 1200
NoConn ~ 6750 2400
NoConn ~ 6750 2500
Text GLabel 6750 2000 0    50   Input ~ 0
3V3
Text GLabel 6750 2100 0    50   Input ~ 0
GND
Text GLabel 6750 2200 0    50   Input ~ 0
21
Text GLabel 6750 2300 0    50   Input ~ 0
22
Text GLabel 6800 700  0    50   Input ~ 0
3V3
Text GLabel 6800 800  0    50   Input ~ 0
GND
Text GLabel 6800 900  0    50   Input ~ 0
21
Text GLabel 6800 1000 0    50   Input ~ 0
22
Text Notes 7950 6850 0    50   ~ 0
Magnetometer Panel A
Text Notes 3100 2950 0    50   ~ 0
ESP32
Text Notes 5650 2950 0    50   ~ 0
RM3100-1\n
Text Notes 3150 5250 0    50   ~ 0
Power\n
Text Notes 5650 5650 0    50   ~ 0
RM3100-2\n
Text Notes 6650 1550 0    50   ~ 0
TMP102-1\n
Text Notes 6600 2950 0    50   ~ 0
TMP102-2\n
Text GLabel 10950 2150 2    50   Input ~ 0
34
Text GLabel 10950 2450 2    50   Input ~ 0
3V3
Text GLabel 10950 2550 2    50   Input ~ 0
GND
Text GLabel 8500 3250 1    50   Input ~ 0
3V3
Text GLabel 8400 3250 1    50   Input ~ 0
GND
Text GLabel 8600 3250 1    50   Input ~ 0
22
Text GLabel 8700 3250 1    50   Input ~ 0
21
Text GLabel 9800 3300 1    50   Input ~ 0
GND
Text GLabel 9900 3300 1    50   Input ~ 0
3V3
Text GLabel 10100 3300 1    50   Input ~ 0
21
Text GLabel 10000 3300 1    50   Input ~ 0
22
Text GLabel 10000 3800 1    50   Input ~ 0
22
Text GLabel 10100 3800 1    50   Input ~ 0
21
Text GLabel 9900 3800 1    50   Input ~ 0
3V3
Text GLabel 9800 3800 1    50   Input ~ 0
GND
Text GLabel 8700 3800 1    50   Input ~ 0
21
Text GLabel 8600 3800 1    50   Input ~ 0
22
Text GLabel 8500 3800 1    50   Input ~ 0
3V3
Text GLabel 8400 3800 1    50   Input ~ 0
GND
Text GLabel 8600 4350 1    50   Input ~ 0
22
Text GLabel 8700 4350 1    50   Input ~ 0
21
Text GLabel 8500 4350 1    50   Input ~ 0
3V3
Text GLabel 8400 4350 1    50   Input ~ 0
GND
Text GLabel 8400 5000 1    50   Input ~ 0
GND
Text GLabel 8500 5000 1    50   Input ~ 0
3V3
Text GLabel 8700 5000 1    50   Input ~ 0
21
Text GLabel 8600 5000 1    50   Input ~ 0
22
Text GLabel 10000 4950 1    50   Input ~ 0
32
Text GLabel 10100 4300 1    50   Input ~ 0
33
Text GLabel 10000 4300 1    50   Input ~ 0
32
Text GLabel 10100 4950 1    50   Input ~ 0
33
Text GLabel 9800 4300 1    50   Input ~ 0
3V3
Text GLabel 9800 4950 1    50   Input ~ 0
3V3
Text GLabel 9900 4300 1    50   Input ~ 0
GND
Text GLabel 9900 4950 1    50   Input ~ 0
GND
$Comp
L Connector:Conn_01x04_Male J8
U 1 1 60950AD7
P 800 3950
F 0 "J8" V 850 3600 50  0000 L CNN
F 1 "Conn_01x04_male" V 750 3050 50  0000 L CNN
F 2 "Connectors_Molex:Molex_PicoBlade_53047-0410_04x1.25mm_Straight" H 800 3950 50  0001 C CNN
F 3 "~" H 800 3950 50  0001 C CNN
	1    800  3950
	0    -1   -1   0   
$EndComp
Text GLabel 900  3750 1    50   Input ~ 0
16
Text GLabel 2000 3750 1    50   Input ~ 0
RX
Text GLabel 800  3750 1    50   Input ~ 0
5V
Text GLabel 1900 3750 1    50   Input ~ 0
3V3
Text Notes 10900 1800 0    50   ~ 0
Digital\n
Text Notes 10750 2950 0    50   ~ 0
Microphone\n
Text GLabel 8250 1000 2    50   Input ~ 0
GND
Text GLabel 8250 2450 2    50   Input ~ 0
GND
Text GLabel 8250 1200 2    50   Input ~ 0
34
Text GLabel 8250 2650 2    50   Input ~ 0
34
Text GLabel 8250 2550 2    50   Input ~ 0
3V3
Text GLabel 8250 2750 2    50   Input ~ 0
27
Text GLabel 8250 1100 2    50   Input ~ 0
3V3
Text GLabel 8250 1300 2    50   Input ~ 0
27
Text Notes 7200 2950 0    50   ~ 0
TCS3200-2\n
Text Notes 7200 1650 0    50   ~ 0
TCS3200-3\n
Wire Notes Line
	10100 3000 10100 1850
Wire Notes Line
	10400 1850 10400 500 
Wire Notes Line
	11200 5700 11200 500 
Text Notes 11050 5650 0    50   ~ 0
I2C\n
Text Notes 7900 5650 0    50   ~ 0
SPI
$Comp
L Connector:Conn_01x06_Male J46
U 1 1 60620EC1
P 1900 6200
F 0 "J46" V 2054 5812 50  0000 R CNN
F 1 "Conn_01x06_Male" V 1963 5812 50  0000 R CNN
F 2 "Connectors_Molex:Molex_PicoBlade_53047-0610_06x1.25mm_Straight" H 1900 6200 50  0001 C CNN
F 3 "~" H 1900 6200 50  0001 C CNN
	1    1900 6200
	0    -1   -1   0   
$EndComp
Text GLabel 1700 6000 1    50   Input ~ 0
D2
Text GLabel 1800 6000 1    50   Input ~ 0
D3
Text GLabel 1900 6000 1    50   Input ~ 0
CD_CMD
Text GLabel 2000 6000 1    50   Input ~ 0
CD_CLK
Text GLabel 2100 6000 1    50   Input ~ 0
SD_DATA_0
Text GLabel 2200 6000 1    50   Input ~ 0
SD_SATA_1
$Comp
L Connector:Conn_01x07_Male J47
U 1 1 606387D0
P 4650 6250
F 0 "J47" V 4577 6228 50  0000 C CNN
F 1 "Conn_01x07_Male" V 4486 6228 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x07_Pitch2.54mm" H 4650 6250 50  0001 C CNN
F 3 "~" H 4650 6250 50  0001 C CNN
	1    4650 6250
	0    -1   -1   0   
$EndComp
NoConn ~ 4350 6050
Text GLabel 4450 6050 1    50   Input ~ 0
19
Text GLabel 4550 6050 1    50   Input ~ 0
GND
Text GLabel 4650 6050 1    50   Input ~ 0
18
Text GLabel 4750 6050 1    50   Input ~ 0
3V3
Text GLabel 4850 6050 1    50   Input ~ 0
23
Text GLabel 4950 6050 1    50   Input ~ 0
4
$Comp
L Connector:Conn_01x06_Male J48
U 1 1 6063F600
P 4650 6950
F 0 "J48" V 4577 6928 50  0000 C CNN
F 1 "Conn_01x06_Male" V 4486 6928 50  0000 C CNN
F 2 "Connectors_Molex:Molex_PicoBlade_53047-0610_06x1.25mm_Straight" H 4650 6950 50  0001 C CNN
F 3 "~" H 4650 6950 50  0001 C CNN
	1    4650 6950
	0    -1   -1   0   
$EndComp
Text GLabel 4450 6750 1    50   Input ~ 0
19
Text GLabel 4550 6750 1    50   Input ~ 0
GND
Text GLabel 4650 6750 1    50   Input ~ 0
18
Text GLabel 4750 6750 1    50   Input ~ 0
3V3
Text GLabel 4850 6750 1    50   Input ~ 0
23
Text GLabel 4950 6750 1    50   Input ~ 0
4
$Comp
L Connector:Conn_01x04_Male J50
U 1 1 6064D621
P 800 3450
F 0 "J50" V 954 3262 50  0000 R CNN
F 1 "Conn_01x04_Male" V 863 3262 50  0000 R CNN
F 2 "Connectors_Molex:Molex_PicoBlade_53048-0410_04x1.25mm_Angled" H 800 3450 50  0001 C CNN
F 3 "~" H 800 3450 50  0001 C CNN
	1    800  3450
	0    -1   -1   0   
$EndComp
$Comp
L Connector:Conn_01x04_Male J51
U 1 1 6064E5EB
P 1900 3450
F 0 "J51" V 2054 3262 50  0000 R CNN
F 1 "Conn_01x04_Male" V 1963 3262 50  0000 R CNN
F 2 "Connectors_Molex:Molex_PicoBlade_53048-0410_04x1.25mm_Angled" H 1900 3450 50  0001 C CNN
F 3 "~" H 1900 3450 50  0001 C CNN
	1    1900 3450
	0    -1   -1   0   
$EndComp
Text GLabel 800  3250 1    50   Input ~ 0
5V
Text GLabel 900  3250 1    50   Input ~ 0
16
Text GLabel 1900 3250 1    50   Input ~ 0
3V3
Text GLabel 700  4350 1    50   Input ~ 0
GND
Text GLabel 1000 4350 1    50   Input ~ 0
17
Text GLabel 1000 3750 1    50   Input ~ 0
17
Text GLabel 700  3750 1    50   Input ~ 0
GND
Text GLabel 1000 4950 1    50   Input ~ 0
17
Text GLabel 700  4950 1    50   Input ~ 0
GND
Text GLabel 2100 4250 1    50   Input ~ 0
TX
Text GLabel 1800 4250 1    50   Input ~ 0
GND
Text GLabel 2100 3750 1    50   Input ~ 0
TX
Text GLabel 1800 3750 1    50   Input ~ 0
GND
Text GLabel 1000 3250 1    50   Input ~ 0
17
Text GLabel 700  3250 1    50   Input ~ 0
GND
Text GLabel 2100 3250 1    50   Input ~ 0
TX
Text GLabel 1800 3250 1    50   Input ~ 0
GND
Text GLabel 2000 3250 1    50   Input ~ 0
RX
Text GLabel 1800 4850 1    50   Input ~ 0
GND
Text GLabel 2100 4850 1    50   Input ~ 0
TX
$Comp
L Connector:Conn_01x04_Male J7
U 1 1 60950AE1
P 1900 3950
F 0 "J7" V 2054 3762 50  0000 R CNN
F 1 "Conn_01x04_Male" V 1963 3762 50  0000 R CNN
F 2 "Connectors_Molex:Molex_PicoBlade_53047-0410_04x1.25mm_Straight" H 1900 3950 50  0001 C CNN
F 3 "~" H 1900 3950 50  0001 C CNN
	1    1900 3950
	0    -1   -1   0   
$EndComp
Text GLabel 1900 4850 1    50   Input ~ 0
3V3
Text GLabel 2000 4850 1    50   Input ~ 0
RX
$Comp
L Connector:Conn_01x04_Male J4
U 1 1 606C35B6
P 1900 5050
F 0 "J4" V 2054 4862 50  0000 R CNN
F 1 "Conn_01x04_Male" V 1963 4862 50  0000 R CNN
F 2 "Connectors_Molex:Molex_PicoBlade_53047-0410_04x1.25mm_Straight" H 1900 5050 50  0001 C CNN
F 3 "~" H 1900 5050 50  0001 C CNN
	1    1900 5050
	0    -1   -1   0   
$EndComp
$Comp
L Connector:Conn_01x04_Male J52
U 1 1 6095B552
P 2800 3450
F 0 "J52" V 2954 3262 50  0000 R CNN
F 1 "Conn_01x04_Male" V 2863 3262 50  0000 R CNN
F 2 "Connectors_Molex:Molex_PicoBlade_53048-0410_04x1.25mm_Angled" H 2800 3450 50  0001 C CNN
F 3 "~" H 2800 3450 50  0001 C CNN
	1    2800 3450
	0    -1   -1   0   
$EndComp
$Comp
L Connector:Conn_01x04_Male J53
U 1 1 6095C2E1
P 2800 4200
F 0 "J53" V 2954 4012 50  0000 R CNN
F 1 "Conn_01x04_Male" V 2863 4012 50  0000 R CNN
F 2 "Connectors_Molex:Molex_PicoBlade_53048-0410_04x1.25mm_Angled" H 2800 4200 50  0001 C CNN
F 3 "~" H 2800 4200 50  0001 C CNN
	1    2800 4200
	0    -1   -1   0   
$EndComp
Text GLabel 2700 3250 1    50   Input ~ 0
GND
Text GLabel 2800 3250 1    50   Input ~ 0
GND
Text GLabel 2900 3250 1    50   Input ~ 0
5V
Text GLabel 3000 3250 1    50   Input ~ 0
5V
Text GLabel 2700 4000 1    50   Input ~ 0
GND
Text GLabel 2800 4000 1    50   Input ~ 0
GND
Text GLabel 2900 4000 1    50   Input ~ 0
3V3
Text GLabel 3000 4000 1    50   Input ~ 0
3V3
$Comp
L Connector:Conn_01x04_Male J45
U 1 1 609B2A16
P 10750 1200
F 0 "J45" V 10596 1348 50  0000 L CNN
F 1 "Conn_01x04_Male" V 10687 1348 50  0000 L CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x04_Pitch2.54mm" H 10750 1200 50  0001 C CNN
F 3 "~" H 10750 1200 50  0001 C CNN
	1    10750 1200
	0    -1   -1   0   
$EndComp
Text GLabel 10750 1000 1    50   Input ~ 0
3V3
Text GLabel 10650 1000 1    50   Input ~ 0
GND
Text GLabel 10950 1000 1    50   Input ~ 0
22
Text GLabel 10850 1000 1    50   Input ~ 0
21
NoConn ~ 1400 2150
NoConn ~ 1400 1950
NoConn ~ 1400 1850
NoConn ~ 1400 1650
NoConn ~ 1400 1550
NoConn ~ 1400 1250
NoConn ~ 1400 1050
NoConn ~ 1400 950 
NoConn ~ 2650 2050
Text GLabel 2650 1950 2    50   Input ~ 0
4
NoConn ~ 2650 2250
$EndSCHEMATC
