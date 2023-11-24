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

#define LAB_POT A7

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
    LIGHT = A4
};

class RLab
{
public:
    RLab();                   // конструктор
    void ledOn(byte pos);     // включение светодиода под номером pos
    void ledOff(byte pos);    // выключение светодиода под номером pos
    void ledToggle(byte pos); // переключение светодиода
    void ledOn(ColoredLED color);
    void ledOff(ColoredLED color);
    bool isPressed(byte button); // состояние кнопок

    int readSensor(Sensor s, bool raw = false);

private:
    byte ledState;         // значения на выходе сдвигового регистра
    void updateShiftReg(); // обновление состояния регистра
};

#endif
