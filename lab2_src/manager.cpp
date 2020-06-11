#include "headers.h"

//В конструкторе присваиваем дефолтные значеня параметрам вывода
Manager::Manager()
{
    snake_len = 20;          //длина змейки (целое число, > 0)
    snake_frequency = 1;     //частота появлений змеек (от 1 до 30. #3 линии в секунду)
    color_scheme = true;     //цветовая схема (false - все зеленое, иначе все цвета рандомные. Y - yes; N - no)
    char_frequency = 25;     //частота появления символов (от 1 до 30. #скорость линий)

    //Размеры пространства вывода по умолчанию
    width = 60;
    height = 40;

    tic=0;//Инициализация счетчика тиков
    get_console_size();//Устанавливаем действующие размеры консоли
}

//инициализация консоли
void Manager::init_console()
{
    // Получение дескриптора устройства стандартного вывода
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
}


// Делаем курсор консоли невидимым
void Manager::hide_cursor()
{
    CONSOLE_CURSOR_INFO structCursorInfo;
    GetConsoleCursorInfo(hConsole, &structCursorInfo);
    structCursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(hConsole, &structCursorInfo);
}

// Делаем курсор консоли видимым
void Manager::show_cursor()
{
    CONSOLE_CURSOR_INFO structCursorInfo;
    GetConsoleCursorInfo(hConsole, &structCursorInfo);
    structCursorInfo.bVisible = TRUE;
    SetConsoleCursorInfo(hConsole, &structCursorInfo);
}

void Manager::get_console_size()
{
    HANDLE hWndConsole=GetStdHandle(-12);
    if(hWndConsole)
    {
        CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
        if (GetConsoleScreenBufferInfo(hWndConsole, &consoleInfo))
        {
            width = consoleInfo.srWindow.Right - consoleInfo.srWindow.Left + 1;
            height = consoleInfo.srWindow.Bottom - consoleInfo.srWindow.Top + 1;
        }
        else
        {
            cout<<"Error in function <GetConsoleScreenBufferInfo>"<<endl;
            getch();
        }
    }
}




//Затираем всю консоль пробелами
void Manager::clear_console()
{
     setpos(0,0);
     for(int i=0;i<width;i++)
     {
         for(int j=0;j<height;j++)
         {
             std::cout<<" ";
         }
         std::cout<<"\n";
     }
}



//установка курсора в позицию X,Y
void Manager::setpos( short x, short y)
{
    position.X = x;									// Установка координаты X
    position.Y = y ;								// Установка координаты Y
    SetConsoleCursorPosition(hConsole, position);	// Перемещение каретки (курсора текстовой консоли) по заданным координатам
}



//Инициализация начального сдвига времени старта змейки
//Используется деление по модулю на простые числаvoid Snake::mixer()
void Manager::mixer()
{
    for(int i=0;i<300;i++)
    {
        if(!(i%2))
            tic_start[i]=rand()%200;
        else
            tic_start[i]=rand()%2000;
        if(!(i%3))
            tic_start[i]=3000 + rand()%2000;
        if(!(i%5))
            tic_start[i]=6000 + rand()%2000;
        if(!(i%7))
            tic_start[i]=9000 + rand()%2000;
        if(!(i%11))
            tic_start[i]=12000 + rand()%2000;
        if(!(i%13))
            tic_start[i]=15000 + rand()%2000;
        if(!(i%17))
            tic_start[i]=18000 + rand()%2000;
        if(!(i%19))
            tic_start[i]=21000 + rand()%2000;
        if(!(i%4))
            tic_start[i]=9000 + rand()%200;
    }

}


//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//Разбор аргументов командной строки с возможностью генерации исключения
int Manager::try_catch(int argc, char *argv[])
{
    try
    {
        if(argc==1)
        {
            return 0;
        }
        else if(argc==2)
        {
            snake_len = std::atoi(argv[1]);
            if(!snake_len){
                throw invalid_argument("Invalid arg[2]");//генерация исключения
            }
            else if((snake_len>height)||(snake_len<1)){
                throw range_error("Range error arg[2]");//генерация исключения
            }
        }
        else if(argc==3)
        {
            snake_len = std::atoi(argv[1]);
            if(!snake_len){
                throw invalid_argument("Invalid arg[2]");//генерация исключения
            }
            else if((snake_len>height)||(snake_len<1)){
                throw range_error("Range error arg[2]");//генерация исключения
            }

            snake_frequency = std::atoi(argv[2]);
            if(!snake_frequency){
                throw invalid_argument("Invalid arg[3]");//генерация исключения
            }
            else if((snake_frequency>30)||(snake_frequency<1)){
                throw range_error("Range error arg[3]");//генерация исключения
            }
        }
        else if(argc==4)
        {
            snake_len = std::atoi(argv[1]);
            if(!snake_len){
                throw invalid_argument("Invalid arg[2]");//генерация исключения
            }
            else if((snake_len>height)||(snake_len<1)){
                throw range_error("Range error arg[2]");//генерация исключения
            }

            snake_frequency = std::atoi(argv[2]);
            if(!snake_frequency){
                throw invalid_argument("Invalid arg[3]");//генерация исключения
            }
            else if((snake_frequency>30)||(snake_frequency<1)){
                throw range_error("Range error arg[3]");//генерация исключения
            }

            int a = strcmp(argv[3],"Y");
            int b = strcmp(argv[3],"N");
            int c = a*b;

            if(!a)
            {
                color_scheme = false;
            }
            else if(!b)
            {
                color_scheme = true;
            }else if(c)
            {
                throw my_except();//генерация исключения
            }

        }
        else if(argc==5)
        {
            snake_len = std::atoi(argv[1]);
            if(!snake_len){
                throw invalid_argument("Invalid  arg[2]");//генерация исключения
            }
            else if((snake_len>height)||(snake_len<1)){
                throw range_error("Range error arg[2]");//генерация исключения
            }

            snake_frequency = std::atoi(argv[2]);
            if(!snake_frequency){
                throw invalid_argument("Invalid arg[3]");//генерация исключения
            }
            else if((snake_frequency>30)||(snake_frequency<1)){
                throw range_error("Range error arg[3]");//генерация исключения
            }

            int a = strcmp(argv[3],"Y");
            int b = strcmp(argv[3],"N");
            int c = a*b;

            if(!a)
            {
                color_scheme = false;
            }
            else if(!b)
            {
                color_scheme = true;
            }else if(c)
            {
                throw my_except();//генерация исключения
            }


            char_frequency = std::atoi(argv[4]);
            if(!char_frequency){
                throw invalid_argument("Invalid arg[4]");//генерация исключения
            }
            else if((char_frequency>30)||(char_frequency<1)){
                throw range_error("Range error arg[4]");//генерация исключения
            }
        }
    }
    catch(my_except e)//перехват исключения
    {
        cout<<" MY_EXCEPT: INVALID ARG[3] !!!"<<"\n";
        cout<<" Press any key to exit ->";
        getch();
        exit(1);
    }
    catch(invalid_argument err)
    {
        cout<<"EXCEPTION:"<<err.what()<<endl;
        cout<<" Press any key to exit ->";
        getch();
        exit(2);
    }
    catch(range_error err)
    {
        cout<<"EXCEPTION:"<<err.what()<<endl;
        cout<<" Press any key to exit ->";
        getch();
        exit(3);
    }

    return 0;
}

double Manager::delay(int dt)//Функция задержки
{
    double y = 0;
    for(int i=0;i<4000*dt;i++)
    {
        y +=rand();
    }
    return y;
}
