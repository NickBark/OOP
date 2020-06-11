#ifndef BANG_H
#define BANG_H
#include "snake.h"
class Bang : public Snake
{
public:
    Bang();
    ~Bang();

    COORD  pos;	//Структура консольных координат X,Y
//    int FLAG_STRIKE;//Знакопеременный Флаг состояния взрыва (если флаг положительный, в змейке вместо символов пишутся пробелы)
    int Pbang;     // вероятность взрыва
    int RMIN;      // минималный радиус взрыва
    int RMAX;     //максимальный радиус взрыва

    int R;//Текущий ралиус взрыва
    int call_counter;

    void Strike();
    void getpos();//Получить от манагера текущие координаты консольного вывода
    void setpos();//Установить текущие координаты консольного вывода
    void setpos(int X, int Y);//Установить координаты консольного вывода
    void out_bang_wave(char ch);//отрисовка  взрыва
    void clear_bang_wave();//Стирание взрыва
    void clear_column();//Стирание всей текущей колонки

};

#endif // BANG_H
