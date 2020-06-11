#include "headers.h"

Bang::Bang(): Snake()
{

    FLAG_STRIKE=false;//Флаг состояния взрыва
    call_counter=0;

    Pbang = 20;      // вероятность взрыва
    RMIN =  3;   // минималный радиус взрыва
    RMAX =  7;   //максимальный радиус взрыва

}

Bang::~Bang()
{
}

void Bang::Strike()
{
    step();
    while(man->tic<10000) return;
    int res = man->tic%200;//Чем больше целочисленный делитель, тем реже  взрывается змейка [997, ]
    if(res)
    {
        call_counter++;
        return;
    }
    FLAG_STRIKE = true;
    call_counter++;

    if(call_counter>snake_len+50)
    {
        FLAG_STRIKE = false;
        call_counter = 0;
    }


    pos.X=X;
    pos.Y=Y_current;
    setpos();

    RMAX = man->tic%13;//Максимальный диаметр взрыва
    out_bang_wave('x');
    Sleep(200);
    clear_bang_wave();
    clear_column();


    return;
}

void Bang::getpos()//Получить от манагера текущие координаты консольного вывода
{
    pos.X = man->position.X;
    pos.Y = man->position.Y;
    return;
}
void Bang::setpos()//Установить текущие координаты консольного вывода
{
    man->setpos( pos.X, pos.Y);
    return;
}
void Bang::setpos(int X, int Y)//Установить координаты консольного вывода
{
    man->setpos(X,Y);
    return;
}

void Bang::out_bang_wave(char ch)//отрисовка волнового фронта взрыва
{
    SetConsoleTextAttribute(man->hConsole, rand()%5+10);//Белый цвет символа
    for(R=1;R<RMAX;R++)
    {
        if((pos.X-R<5)||(pos.X+R>man->width-5)||(pos.Y-R<5)||(pos.Y+R>man->height-5)) continue;
        setpos(pos.X-R,pos.Y-R); cout<<ch; setpos(pos.X,pos.Y-R); cout<<ch; setpos(pos.X+R,pos.Y-R); cout<<ch;
        setpos(pos.X-R,pos.Y); cout<<ch;   setpos(pos.X,pos.Y);   cout<<ch; setpos(pos.X+R,pos.Y); cout<<ch;
        setpos(pos.X-R,pos.Y+R); cout<<ch;   setpos(pos.X,pos.Y+R); cout<<ch; setpos(pos.X+R,pos.Y+R); cout<<ch;
//        Sleep(100);
    }
    SetConsoleTextAttribute(man->hConsole, 10 );//Зеленый цвет символа
    return;
}

void Bang::clear_bang_wave()
{
    char ch = ' ';
    for(R=1;R<RMAX;R++)
    {
        if((pos.X-R<5)||(pos.X+R>man->width-5)||(pos.Y-R<5)||(pos.Y+R>man->height-5)) continue;
        setpos(pos.X-R,pos.Y-R); cout<<ch; setpos(pos.X,pos.Y-R); cout<<ch; setpos(pos.X+R,pos.Y-R); cout<<ch;
        setpos(pos.X-R,pos.Y); cout<<ch;   setpos(pos.X,pos.Y);   cout<<ch; setpos(pos.X+R,pos.Y); cout<<ch;
        setpos(pos.X-R,pos.Y+R); cout<<ch;   setpos(pos.X,pos.Y+R); cout<<ch; setpos(pos.X+R,pos.Y+R); cout<<ch;
    }
//    Sleep(10);
    return;
}
void Bang::clear_column()//Стирание всей  текущей колонки
{
        for(int i=0;i<man->height;i++)
        {
            setpos(pos.X,i);
            cout<<' ';
        }
        return;
}
