#ifndef MY_CHAR_H
#define MY_CHAR_H
#include "headers.h"

class My_Char
{
public:
    My_Char();
    char GetRandChar(bool color_scheme);
    int DelayChar(int char_frequency);

    Manager * man;//указатель на объект manager приложения
    char ch;
    int color;
};

#endif // MY_CHAR_H
