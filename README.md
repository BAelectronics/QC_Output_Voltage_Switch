[Kapcsolódó videó / Related video](https://youtu.be/jLJ_5dmPatM)

The language of the video is Hungarian, but English subtitles are available.


# USB gyorstöltő kimenő feszültségét beállító eszköz (5/9/12V)
A videóban bemutatott és a projekthez tartozó fájlok, rajzok, kódok stb. megtalálhatóak ezen az oldalon.

A vezérlőpanel kapcsolása és nyákterve KiCad 5.1 programmal készült.

Ezzel a kis adapterrel egyszerűen lehet módosítani egy Quick Charge 2.0 vagy 3.0 képes USB-s gyorstöltő kimenő feszültségét csupán egy ATtiny13A MCU-val és néhány egyéb alkatrésszel. A hardver egyféle, azonban 2 eltérő működésű szoftver van fejlesztve, hogy ha valaki utánépítené akkor ki tudja választani a számára szimpatikus módot. Természetesen lehet kombinálni is vagy másfajta működést kitalálni ha van hozzá affinitásod.


### MODE 1 képességek
- +gomb --> feszültség növelése +0,2Volttal
- -gomb --> feszültség csökkentése -0,2Volttal
- Mindkét gombot egyszerre lenyomva --> 5V beállítás

### MODE 2 képességek
- +gomb --> ugrás 9Voltra 5Voltról vagy 12Voltra 9Voltról
- -gomb --> ugrás 9Voltra 12Voltról vagy 5Voltra 9Voltról
- Egyiket nyomvatartva és megnyomva a másikat --> beállított feszültség mentése EEPROM-ba, következő indításnál magától betöltődik


# USB Quick Charge output voltage switch device (5/9/12V)
You can find here files, schematics, codes, etc. Everything what presented in the video and associated with the project.

The control board schematic and PCB designed with KiCad 5.1.

With this small adapter, you can easily adjust the output voltage of a Quick Charge 2.0 or 3.0 capable USB charger with only an ATtiny13A MCU and few parts. The hardware is one, but the software has 2 different mode, so if you want to rebuild, then you can choose the mode they like. Of course, you can also combine or develop new with a different kind of action if you have an affinity for it.

### MODE 1 features
- +button --> increase the Voltage +0,2V
- -button --> decrease the Voltage -0,2V
- Both button pressed at the same time --> set 5V

### MODE 2 features
- +button --> jump to 9V from 5V or jump to 12V from 9V
- -button --> jump to 9V from 12V or jump to 5V from 9V
- One button hold and press the other --> save set Voltage to the EEPROM (next start auto load)


The device:

![device](https://github.com/BAelectronics/QC_Output_Voltage_Switch/blob/master/Device.jpg)


Thanks to them:
- [Hugatry's HackVlog](https://www.youtube.com/channel/UCHgeChD442K0ah-KxEg0PHw) He came up with the idea and first code to control QC2. 
- [QC2Control](https://github.com/septillion-git/QC2Control) Timo Engelgeer (Septillion) who made a nice wrapper for QC2.
- [QC3Control](https://github.com/vdeconinck/QC3Control) He is the latest developer of the idea for QC3.
