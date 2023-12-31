# RLab

## Установка

### Через менеджер библиотек

Этот способ предпочтительнее, потому что Arduino IDE самостоятельно будет следить за обновлениями библиотеки и предложит их загрузить.

Откройте **Arduino IDE**. Откройте **Менеджер библиотек**. Для этого выберите пункт меню **Инструменты - Управлять библиотеками** или нажмите комбинацию клавиш <kbd>Ctrl</kbd> + <kbd>Shift</kbd> + <kbd>I</kbd>. В появившемся окне наберите в строке поиска название библиотеки и нажмите кнопку **Установка**. Через некоторое время последняя версии библиотеки будет загружена и установлена.

### Установка с помощью zip-архива

Если на компьютере нет доступа в интернет, нужно использовать этот способ.

По ссылке перейдите на [страницу релиза последней версии](https://github.com/skyfroger/RLab/releases/latest). В разделе **Assets** скачайте архив с названием **Source code (zip)**. Файл будет называться **RLab-[версия].zip**.

> Перед установкой новой версии библиотеки из zip-файла, удалите предыдущую версию!

Откройте **Arduino IDE**. Выберите пункт меню **Скетч - Подключить библиотеку - Добавить .ZIP библиотеку...** . В появившемся диалоговом окне выберите сохранённый ранее архив.

Перезапустите **Arduino IDE**.

Библиотека установлена.

## Примеры скетчей

Примеры можно найти в меню **Файл - Примеры - RLab**.

## Подключение

Для импорта библиотеки в скетч, нужно добавить в начале следующую строку:

```cpp
#include <RLab.h>
```

Добавить эту строку можно вручную или с помощью меню **Скетч - Подключить библиотеку - RLab**.

## Документация

Перед тем, как обращаться к методам, нужно создать объект класса `RLab`:

```cpp
#include <RLab.h> // подключение библиотеки

// объект класса RLab создаётся вне функции setup() и loop()
RLab lab;

void setup(){
    // начальная настройка
}

void loop(){
    // главыный цикл Arduino-скетча
}
```

### Управление светодиодами

Для включения светодиодов используется функция `ledOn()`:

```cpp
void ledOn(byte pos);
void ledOn(ColoredLED color);
```

В качестве аргумента можно передать целое число от 0 до 7, чтобы включить номерные светодиоды, либо название цвета: `RED`, `YELLOW` или `GREEN`.

Пример:

```cpp
lab.ledOn(3); // включение 4-го по счёту светодиода
lab.ledOn(GREEN); // включение зелёного светодиода
```

Для выключения светодиодов используется функция `ledOff()`:

```cpp
void ledOff(byte pos);
void ledOff(ColoredLED color);
```

В качестве аргумента можно передать целое число от 0 до 7, чтобы выключить номерные светодиоды, либо название цвета: `RED`, `YELLOW` или `GREEN`.

Пример:

```cpp
lab.ledOff(0); // выключение 1-го по счёту светодиода
lab.ledOff(YELLOW); // выключение желтого светодиода
```

С помощью функции `ledToggle()` можно переключить состояние светодиода на противоположное.

Пример:

```cpp
lab.ledOn(1); // включить 2-й по счёту светодиод
lab.ledToggle(1); // 2-й светодиод выключится
lab.ledToggle(1); // 2-й светодиод опять включится
```

### Кнопки

Функция `isPressed()` возвращает состояние выбранной кнопки.

```cpp
bool isPressed(byte button);
```

Аргумент `button` - номер кнопки от 1 до 5.

Пример:

```cpp
// state == true, если кнопка 1 нажата, иначе - false
bool state = lab.isPressed(1);

if (lab.isPressed(5)){
    // кнопка 5 нажата
} else {
    // кнопка 5 не нажата
}
```

### Чтение показаний датчиков

Функция `readSensor()` возвращает показания датчика:

```cpp
int readSensor(Sensor s, bool raw = false);
```

`s` - название сенсора:

- `POT` - потенциометр (рычажок),

- `MIC` - микрофон,

- `LIGHT` - фототранзистор,

- `ANALOG0` - первый аналоговый разъём для датчиков из набора расширений,

- `ANALOG1` - второй аналоговый разъём для датчиков из набора расширений,

- `DIGITAL` - цифровой разъём для датчиков из набора расширений.

По умолчанию, функция возвращает целое число в диапазоне от 0 до 100. Если вторым аргументом указан `true`, функция вернёт "сырое" значение от 0 до 1023.

Пример:

```cpp
// значение с потенциометра от 0 до 100
int pos = lab.readSensor(POT);

// значение с микрофона от 0 до 1023
int level = lab.readSensor(MIC, true);

// значение с фототранзистора от 0 до 100
int l = lab.readSensor(LIGHT);
```

### Динамик

Чтобы воспроизвести звук, используется функция `playNote`:

```cpp
void playNote(byte note, int duration = 300);
```

где `note` - номер ноты (**от 48 до 72**), `duration` - продолжительность в миллисекундах (по умолчанию 300 мс). Подробнее о соответствии номеров нот частотам можно почитать [тут](https://en.scratch-wiki.info/wiki/Composing_Music).

Пример:

```cpp
// сыграть ноту 54 длительностью 300 мс
lab.playNote(54);
// сыграть ноту 48, длительностью 100 мс
lab.playNote(48, 100);
```

В текущей реализации, Лаборатория воспроизведёт ноту и только потом программа продолжит работу. `playNote` не выполняется параллельно с остальной программой.

## Загрузка скетча через Arduino IDE

Подключите Лабораторию к компьютеру и запустите Arduino IDE. В меню **Инструменты** - **Плата** выберите _Arduino Nano_.

В меню **Порт** выберите последовательный порт, к которому подключена Лаборатория (один из COM-портов).

Выберите пункт _ATmega328P (Old bootloader)_ в меню **Инструменты** - **Процессор**.

Теперь скетч можно загрузить в Лабораторию. Программа начнёт выполняться почти сразу после подачи питания. Чтобы запускать программу по нажатию на одну из кнопок, поместите в функции `setup()` цикл `while`, который прекратит работу после нажатия кнопки и позволит программе выполняться дальше.

```cpp
setup(){
    // цикл выполняется, пока не нажата кнопка 1
    while(!lab.isPressed(1)){}
    delay(3000); // задержка 3 секунды
}
```
