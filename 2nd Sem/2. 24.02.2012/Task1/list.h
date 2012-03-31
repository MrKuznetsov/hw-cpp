#ifndef LIST_H
#define LIST_H


/**
@class List
Базовый абстрактный класс списков
*/
class List
{
public:
    virtual ~List(){};
    /// Метод добавляет значение в конец списка
    virtual void addValue(int val) = 0;
    /// Метод удаляет значение из списка
    virtual void removeValue(int val) = 0;
    /// Поиск значения в списке
    virtual bool find(int val) = 0;
    /// Размер списка
    virtual int size() = 0;
    /// Значение списка на определенной позиции
    virtual int get(int pos = 0) = 0;
};

#endif // LIST_H
