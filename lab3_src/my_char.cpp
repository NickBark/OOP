#include "headers.h"

My_Char::My_Char()
{
}

char My_Char::GetRandChar(bool color_scheme)
{
    if(color_scheme)
    {
        SetConsoleTextAttribute(man->hConsole, 10 );//Зеленый цвет символа
    }else{
        SetConsoleTextAttribute(man->hConsole, rand()%5+10 );//Радужный цвет символов
    }
    char ch = rand()%72+48;//Генерим случайный символ
    return ch;
}

int My_Char::DelayChar(int char_frequency)
{
    int delay_char = (30-char_frequency);
    return delay_char;
}
