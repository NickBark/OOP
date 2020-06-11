#include "headers.h"

Snake::Snake()
{
}

Snake::Snake(int posx, int tic_start)
{
    tic0 = tic_start;//Тик момента рождения змейки
    X = posx;   //Коордмната консоли Х, в которой будет выводиться змейка
    Y_current = 0;
    Y_tail = -1;
    snake_len = 5;
    flag_out_char_enable = true;
}

void Snake::step()
{
    char tmp;
//    int dt = DelaySnake(man->snake_frequency);

    //Змейка ещё не родилась, выходим из функции
    if(man->tic<tic0) return;

    man->setpos(X,Y_current);//Устанавливаем курсор консоли в текущую позицию
    tmp = my_char->GetRandChar(man->color_scheme);//Генерим случайный символ в заданной цветовой схеме
    //Печатаем случайный символ
    if((flag_out_char_enable)&&(Y_current>=0))//
        cout<<tmp;//===============================================================

    //Хвост показался, можно поставить условие его затиранмя
    if(Y_current==snake_len){
        Y_tail = 0;//Устанавливаем условие разрешения затирания
    }

    if(Y_tail>=0)//Выполняется условие разрешения затирания? (Хвост змейки показался на экране)
    {
        man->setpos(X,Y_tail);
        cout<<" ";//================================================================
        Y_tail++;
    }

    Y_current++;
    if(Y_tail>=(man->height-snake_len))//Условие: "хвост змейки ещё торчит на экране, а голова уже скрылась"
    {
        Y_current=-1;
        flag_out_char_enable=false;
    }else{
        flag_out_char_enable=true;
    }
    if(Y_tail>=man->height)
    {
        Y_tail = -1;//Устанавливаем условие запрета затирания (хвост змейки скрылся под экран)
        Y_current = -1;
        return;
    }
    if(Y_current>=man->height) Y_current = 0;//Голова змейки скрылась под экран

    return;
}

int Snake::DelaySnake(int snake_frequency)
{
    int delay_snake = (30-snake_frequency);
    return delay_snake;
}



