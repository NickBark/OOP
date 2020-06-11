#ifndef SNAKE_H
#define SNAKE_H
#include "headers.h"

class Snake
{
public:
    Snake();
    Snake(int posx, int tic_start);

    Manager * man;//указатель на объект manager приложения
    My_Char * my_char;
    int X;//колонка, в которой живет змейка
    int tic0;//тик, начиная с которого начинает отображаться змейка
    int Y_current;//Позиция для вывода головы змейки
    int snake_len;//Длина змейки
    int Y_tail;//Хвост змейки
    bool flag_out_char_enable;

    void step();
    int DelaySnake(int snake_frequency);

};

#endif // SNAKE_H
