#ifndef RLab_h
#define RLab_h

#include "Arduino.h"

// пины для кнопок
#define BUTTON1 8
#define BUTTON2 9
#define BUTTON3 10
#define BUTTON4 12
#define BUTTON5 11

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
    RLab();                  // конструктор
    void ledOn(int pos);     // включение светодиода под номером pos
    void ledOff(int pos);    // выключение светодиода под номером pos
    void ledToggle(int pos); // переключение светодиода

private:
    byte ledState;         // значения на выходе сдвигового регистра
    void updateShiftReg(); // обновление состояния регистра
};

#endif
