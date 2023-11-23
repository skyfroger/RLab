#include "Arduino.h"
#include "RLab.h"

/**
 * @brief Конструктор класса RPulse
 */
RLab::RLab()
{
    pinMode(GREEN_LED, OUTPUT);
    pinMode(YELLOW_LED, OUTPUT);
    pinMode(RED_LED, OUTPUT);

    pinMode(DATA, OUTPUT);
    pinMode(CLK, OUTPUT);
    pinMode(RESET, OUTPUT);

    // контакт сброса у регистра инвертирован,
    // значит нужно подавать 1, чтобы регистр
    // постоянно не обнулялся
    digitalWrite(RESET, HIGH);

    // изначально все номерные светодиоды выключены
    this->ledState = 0b00000000;
}

/**
 * @brief Включение номерного светодиода
 *
 * @param pos номер светодиода
 */
void RLab::ledOn(int pos)
{
    if (pos >= 0 && pos <= 8)
    {
        bitSet(this->ledState, pos);
        this->updateShiftReg();
    }
}

/**
 * @brief Выключение номерного светодиода
 *
 * @param pos номер светодиода
 */
void RLab::ledOff(int pos)
{
    if (pos >= 0 && pos <= 8)
    {
        bitClear(this->ledState, pos);
        this->updateShiftReg();
    }
}

/**
 * @brief Переключение состояния номерного светодиода
 *
 * @param pos номер светодиода
 */
void RLab::ledToggle(int pos)
{
    if (pos >= 0 && pos <= 8)
    {
        this->ledState ^= 1 << pos;
        this->updateShiftReg();
    }
}

void RLab::updateShiftReg()
{
    shiftOut(DATA, CLK, MSBFIRST, this->ledState);
}