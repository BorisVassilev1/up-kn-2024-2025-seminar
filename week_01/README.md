# Седмица 1: Въведение в C++; вход, изход и аритметични изрази

## C++ Installation instructions

Имате няколко опции за софтуер, който да използвате

### 1) Visual Studio (най-лесна инсталация)

Свалете инсталатора на Visual Studio Community от официалната [страница](https://visualstudio.microsoft.com/downloads/). (Може и Visual Studio Professional ако използвате предоставения от СУ microsoft акаунт)
Инсталирайте пакета по подразбиране за C++ и сте готови.

### 2) Компилатор + Текстов редактор

Друга опция е да използвате компилатор заедно със произволен текстов редактор. Компилатори за C++ има много. По-общи инструкции за инсталиране под Windows може да намерите [тук](https://www.freecodecamp.org/news/how-to-install-c-and-cpp-compiler-on-windows/). Практически всеки компилатор ще ви свърши работа. Тук ще дам инструкции за инсталация на Clang тъй като работи на всички платформи и се инсталира лесно.

1) Свалете инсталатора LLVM-17.0.1-win64.exe (или win32) от [тук](https://github.com/llvm/llvm-project/releases/tag/llvmorg-17.0.1)
2) Инсталирайте LLVM - колекция от инструменти за програмиране, включваща компилатора clang.
3) Инсталирайте произволен текстов редактор. Дори и Notepad ще свърши работа, но ето някои редактори, които препоръчваме:

    - [Visual Studio Code](https://code.visualstudio.com/download) (Kalin Georgiev's choise)

    - [Sublime Text 4](https://www.sublimetext.com/download)

    - [Notepad++](https://notepad-plus-plus.org/downloads/v8.5.7/) (Criminally Underrated)

    Vim / NeoVim / Emacs: нямате нужда от линк.
Може да настроите избрания текстов редактор да компилира и пусне програмата Ви при натискане на клавишна комбинация или с бутон в графичния интерфейс. В интернет има много и разнообразни инструкции как да се случи това.

## Задачи


### 1) Hello, FMI!

Напишете програма, която изписва "Hello, FMI" на стандартния изход.

### 2) Сума на две числа

Напишете програма, която получава две цели числа на стандартния вход и извежда сумата им на стандартния изход.

|Вход | Изход |
|:---:|:---:|
| 7 6|13|


### 3) Хипотенуза на правоъгълен триъгълник

Напишете програма, която приена две числа на стандартния вход - катетите на правоъгълен триъгълник. Програмата да извежда дължината на хипотенузата на този триъгълник.

|Вход | Изход |
|:---:|:---:|
|4 5|6.40312|

### 4) Ври ли вода

Напишете програма, която приема едно число на стандартния вход - температура на вода в тенджера, измерена в градуси (по Целзий). Програмата да извежда дали водата ври или не.


|Вход | Изход |
|:---:|:---:|
| 50|false|
|100|true|
|120|true|
