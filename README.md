[Kapcsolódó videó / Related video](https://youtu.be/jLJ_5dmPatM)

The language of the video is Hungarian, but English subtitles are available.


# USB gyorstöltő kimenő feszültségét beállító eszköz (5/9/12V)
A videóban bemutatott és a projekthez tartozó fájlok, rajzok, kódok stb. megtalálható ezen az oldalon.

A vezérlőpanel kapcsolása és nyákterve KiCad 5.1 programmal készült.

Ezzel a kis adapterrel egyszerűen lehet módosítani egy Quick Charge 2.0 vagy 3.0 képes USB-s gyorstöltő kimenő feszültségét. A hardver egyféle, azonban 2 eltérő működésű szoftver van fejlesztve, hogy ha valaki utánépítené akkor ki tudja választani a számára szimpatikus módot. Természetesen lehet kombinálni is vagy másfajta működést kitalálni ha van hozzá affinitásod.

aaa

## MODE 1 Képességek

## MODE 2 Képességek



# USB Quick Charge output voltage switch device (5/9/12V)
Files, schematics, codes, etc. You can find hereEverything what presented in the video and associated with the project.

The control board schematic and PCB designed with KiCad 5.1.

## MODE 1 Features
+button --> increase the Voltage +0,2V

-button --> decrease the Voltage -0,2V

Both button pressed at the same time --> set 5V

## MODE 2 Features
+button --> jump to 9V from 5V or jump to 12V from 9V

-button --> jump to 9V from 12V or jump to 5V from 9V

One button hold and press the other --> save set Voltage to the EEPROM (next start auto load)




All credits go to :
- [Hugatry's HackVlog](https://www.youtube.com/channel/UCHgeChD442K0ah-KxEg0PHw) He came up with the idea and first code to control QC2. 
- [QC2Control](https://github.com/septillion-git/QC2Control) Timo Engelgeer (Septillion) who made a nice wrapper for Quick Charge 2.0.
- [QC2Control](https://github.com/vdeconinck/QC3Control) He is the latest developer of the idea.
