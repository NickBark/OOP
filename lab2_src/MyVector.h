#ifndef MYVECTOR_H
#define MYVECTOR_H
#include <iostream>

using namespace std;

//Шаблон двухсвязного списка
template <class T>
class MyVector
{
public:
    MyVector();//Конструктор
    ~MyVector();//Деструктор

    int size();//Получение размера контейнера
    void resize(int newsize);//Изменение размера контейнера


    void addElement(int i,T* var);//Добавление элемента по индексу
    void addFirstElement(T* var);//Добавление первого элемента
    void addLastElement(T* var);//Добавление последнего элемента

    T*  Element(int i);//Взятие элемента по индексу
    T* FirstElement();//Взятие первого элемента
    T*  LastElement();//Взятие последнего элемента

    void removeElement(int i);//Удаление элемента по индексу
    void removeFirstElement();//Удаление первого элемента
    void removeLastElement();//Удаление последнего элемента

    void printAT();//Распечатка  адресов элементов вектора

    int count_element;
    int position;
    T** AT;
    static const int DefaultSize = 300;
    int Size;
};
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
template <class T>
MyVector<T>::MyVector()
{
    AT = new T*[DefaultSize];
    for(int i=0;i<DefaultSize;i++){
        AT[i]=NULL;//инициализация вектора нулевыми адресами
    }
    Size = DefaultSize;
    count_element = 0;
}

template <class T>
MyVector<T>::~MyVector()
{
    delete AT;
}

template <class T>
int MyVector<T>::size()//Получение размера контейнера
{
    return Size;
}

template <class T>
void MyVector<T>::resize(int newsize)//Изменение размера контейнера
{
    if(Size>=newsize) Size=newsize;
    else
    {
        T** tmp = new T*[Size];
        for(int i=0;i<DefaultSize;i++)
            tmp[i]=NULL;//инициализация вектора нулевыми адресами
        for(int i=0;i<Size;i++)
        {
            tmp[i] = AT[i];//Копирование элементов массива AT[] в массив tmp[]
        }
        AT = tmp;//Массив tmp[] становится массивом AT[]
    }
    return;
}
//=================================================
//ДОБАВЛЕНИЕ
template <class T>
void MyVector<T>:: addElement(int i, T* var)//Добавление элемента по индексу
{
//    T* tmp;
    if(i>Size-2)
    {
        cout<<"Range error"<<endl;
        return;
    }
    for(int pos = count_element; pos>=i; pos--)
    {
        AT[pos+1]= AT[pos];//Перемещаем элементы с позиции k в позицию k+1
    }
    AT[i]=var;//Вставляем элемент в позицию i
    count_element++;//Инкрементируем счетчик элементов
//    cout<<"count_element="<<count_element<<endl;
    return;
}

template <class T>
void MyVector<T>:: addFirstElement(T* var)//Добавление первого элемента
{
    addElement(0,var);
    return;
}

template <class T>
void MyVector<T>:: addLastElement(T* var)//Добавление последнего элемента
{
    addElement(count_element,var);
    return;
}
//=================================================
//ВЗЯТИЕ
template <class T>
T* MyVector<T>::Element(int i)//Взятие элемента по индексу
{
    if(i>=Size)
    {
        cout<<"Выход за границу массива";
        return NULL;
    }
    return AT[i];
}

template <class T>
T* MyVector<T>::FirstElement()//Взятие первого элемента
{
    return Element(AT[0]);
}

template <class T>
T* MyVector<T>::LastElement()//Взятие последнего элемента
{
    return Element(AT[count_element-1]);
}
//=================================================
//УДАЛЕНИЕ
template <class T>
void MyVector<T>::removeElement(int i)//Удаление элемента по индексу
{
    for(int pos = i; pos<count_element; pos++)
    {
        AT[pos]= AT[pos+1];//Перемещаем элементы с позиции k+1 в позицию k
    }
    count_element--;//Декрементируем счетчик элементов
    return;

}

template <class T>
void MyVector<T>::removeFirstElement()//Удаление первого элемента
{
    removeElement(0);
    return;
}

template <class T>
void MyVector<T>::removeLastElement()//Удаление последнего элемента
{
    AT[count_element-1]=NULL;
    count_element--;
}
//=================================================
template <class T>
void MyVector<T>::printAT()//Распечатка адресов элементов вектора
{
    cout<<endl<<"count_element = "<<count_element<<endl;
    for(int i=0;i<count_element;i++)
    {
        cout<<"AT["<<i<<"]="<<AT[i]<<endl;
    }
}








#endif // MYVECTOR_H
