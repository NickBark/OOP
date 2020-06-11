#ifndef MANAGER_H
#define MANAGER_H

#include "headers.h"

class Manager
{
public:
    Manager();

    //параметры запуска приложения
    int snake_len;             //длина змейки (целое число, > 0)
    int snake_frequency;   //частота появлений змеек (от 1 до 30. #3 линии в секунду)
    bool color_scheme;     //цветовая схема (false - все зеленое, иначе все цвета рандомные. Y - yes; N - no)
    int  char_frequency;    //частота появления символов (от 1 до 30. #скорость линий)

     int Pbang;     // вероятность взрыва
     int Rmin;      // минималный радиус взрыва
     int Rmax;     //максимальный радиус взрыва

    int tic;//Счетчик тиков
    int width, height;          //размеры консоли W,H

    COORD  position;	//Структура консольных координат X,Y
    HANDLE hConsole;	//Дескриптор устройства стандартного вывода


    void init_console();//инициализация консоли
    void get_console_size();//Получение размеров консоли, в которой запускается это приложение
    void clear_console();//очистка матрицы
    void hide_cursor();
    void show_cursor();
    void setpos( short x, short y); //перевод курсора в указанную позицию
    int try_catch(int argc, char *argv[]);//парсер командной строки с обработкой исключений

    int tic_start[300];//Начальные смещения времени запуска змеек
    void mixer();//инициализация начальных смещений змеек

    double delay(int dt);//Функция задержки
    double z;

};

#endif // MANAGER_H
