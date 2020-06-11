#include "headers.h"

int main(int argc, char *argv[])
{
    //Функция фрэймворка - создание консольного приложения
    QCoreApplication a(argc, argv);
    srand(time(NULL));//Инициализация генератора случайных чисел

    //Создаем объект управления приложением и консольной графикой
    Manager * manager = new Manager();
    manager->init_console();//Инициализация консоли
    system("cls");//Cистемная команда - очистка консоли

    //Разбор командной строки с обработкой исключений
    manager->try_catch(argc, argv);
    manager->hide_cursor();

    //Создаем объект для генерации случайных символов случайного цвета
    My_Char * my_char =new My_Char();
    my_char->man = manager;

    //Создакм  массив указателей вертикальных змеек
    Snake * snake[manager->width];
    manager->mixer();//Задаем времена запуска змеек (время измеряется в тиках)

    //Создаем массив объектов змеек
    for(int i=0;i<manager->width;i++)
    {
        snake[i] = new Snake(i, manager->tic_start[i]);//Вызываем конструктор класса с параметрами
        snake[i]->man = manager;//передаем указатель на manager в объект класса snake
        snake[i]->snake_len = manager->snake_len;//Устанавливаем одинаковую длину змеек, заданную в объекте управления (manager)
        snake[i]->my_char = my_char;//передаем змейкам указатель на объект генератор случайныхсимволов
    }

    //Основной цикл
    for(int i,j,k;;)
    {
        j=j;k=k;
        manager->get_console_size();//Получаем и  (на всякий случай) размер консоли
        int dt = my_char->DelayChar(manager->char_frequency);//Пересчитываем параметр командной строки в миллисекунды задержки
        manager->z = manager->delay(dt);//Зачем нужен параметр z?
        manager->tic++;//Счетчик тиков (задает темп вывода)
        i=rand()%manager->width;//Случайное число от 0 до width - это номер змейки, которая будет обновляться
        snake[i]->step();//Обновляем одну змейку, выбранную случайно
        j=rand()%manager->width;//Случайное число от 0 до width
        snake[j]->step();//Обновляем одну змейку, выбранную случайно
    }

    return a.exec();
}

