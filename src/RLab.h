#ifndef RLab_h
#define RLab_h

#include "Arduino.h"

// пины для разноцветных светодиодов
#define GREEN_LED 5
#define YELLOW_LED 6
#define RED_LED 7

// пины сдвигового регистра
#define DATA 2   // пин данных
#define CLK 4    // пин синхронизации
#define RESET 19 // пин сброса

class RLab
{
public:
    RLab();                   // конструктор
    void ledOn(byte pos);     // включение светодиода под номером pos
    void ledOff(byte pos);    // выключение светодиода под номером pos
    void ledToggle(byte pos); // переключение светодиода
    bool isPressed(byte button);

private:
    byte ledState;         // значения на выходе сдвигового регистра
    void updateShiftReg(); // обновление состояния регистра
};

#endif
