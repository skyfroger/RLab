#ifndef RLab_h
#define RLab_h

#include "Arduino.h"

// пины для разноцветных светодиодов
#define LAB_GREEN_LED 5
#define LAB_YELLOW_LED 6
#define LAB_RED_LED 7

// пины сдвигового регистра
#define LAB_DATA 2   // пин данных
#define LAB_CLK 4    // пин синхронизации
#define LAB_RESET 19 // пин сброса

#define LAB_BUZZER 3

enum ColoredLED
{
    GREEN = LAB_GREEN_LED,
    YELLOW = LAB_YELLOW_LED,
    RED = LAB_RED_LED
};

enum Sensor
{
    POT = A7,
    MIC = A3,
    LIGHT = A4,
    ANALOG0 = A0,
    ANALOG1 = A1,
    DIGITAL = 13
};

class RLab
{
public:
    RLab();                           // конструктор
    void ledOn(byte pos);             // включение светодиода под номером pos
    void ledOff(byte pos);            // выключение светодиода под номером pos
    void ledToggle(byte pos);         // переключение светодиода
    void ledOn(ColoredLED color);     // включение цветного LED
    void ledOff(ColoredLED color);    // выключение цветного LED
    void ledToggle(ColoredLED color); // переключение цветного LED
    bool isPressed(byte button);      // состояние кнопок

    int readSensor(Sensor s, bool raw = false); // чтение значений с датчиков

    void playNote(byte note, int duration = 300); // проигрывание ноты

private:
    byte ledState;         // значения на выходе сдвигового регистра
    byte colorLedState;    // состояние тройки цветных светодиодов
    void updateShiftReg(); // обновление состояния регистра
    void updateColorLED(); // обновление состояния тройки светодиодов

    // массив нот (частоты в Hz)
    int _notes[25] = {131, 139, 147, 156, 165, 175, 185, 196, 208, 220, 233,
                      247, 262, 277, 294, 311, 330, 349, 370, 392, 415, 440, 466, 494, 523};
};

#endif
