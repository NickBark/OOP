
#include "headers.h"

int main(int argc, char *argv[])
{
    //Функция фрэймворка - создание консольного приложения
    QCoreApplication a(argc, argv);
    srand(time(NULL));//Инициализация генератора случайных чисел

//    //Создаем объект управления приложением и консольной графикой
    Manager * manager = new Manager();
    manager->init_console();//Инициализация консоли
    system("cls");//Cистемная команда - очистка консоли
//
    //Разбор командной строки с обработкой исключений
    manager->try_catch(argc, argv);
    manager->hide_cursor();

//    //Создаем объект для генерации случайных символов случайного цвета
    My_Char * my_char =new My_Char();
    my_char->man = manager;

    //Создакм  массив указателей вертикальных змеек
    manager->mixer();//Задаем времена запуска змеек (время измеряется в тиках)

    MyVector<Bang> v;//Вектор взрывающихся змеек
    for(int i=0;i<manager->width;i++)
    {
        Bang * snake = new Bang();//Созаем новый объект змейки
        v.addLastElement(snake);//Добавляем элемент вектора
        //Определяем параметры добавленного элемента
        v.Element(i)->man = manager;//передаем указатель на manager в объект класса snake
        v.Element(i)->snake_len = manager->snake_len;//Устанавливаем одинаковую длину змеек, заданную в объекте управления (manager)
        v.Element(i)->my_char = my_char;//передаем змейкам указатель на объект генератор случайных символов
        v.Element(i)->X = i;   //Коордмната консоли Х, в которой будет выводиться змейка
        v.Element(i)->tic0 =  manager->tic_start[i];//Тик момента рождения змейки
    }

    //Основной цикл
    int i;
    while(1)
    {
        manager->get_console_size();//Обновляем на всякий случай размер консоли
        manager->tic++;//Счетчик тиков (участвует в определении темпа вывода)
        i=rand()%(manager->width);//Случайное число от 0 до width - это номер змейки, которая будет обновляться
        v.Element(i)->Strike();//Отрисовка змейки или взрыва
    }

    return a.exec();
}

