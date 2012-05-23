#ifndef BAG_H
#define BAG_H

#include <set>

using namespace std;

template<class T>
class Bag
{
public:
    class Iterator;

    int size() const;
    bool isEmpty();
    void insert(const T &elem);
    void erase(const T &elem);
    void clear();
    bool find(const T &elem) const;

    Iterator begin();
    Iterator end();

private:
    multiset<T> set;
};

template<class T>
class Bag<T>::Iterator
{
public:
    Iterator(const typename Bag<T>::Iterator &i) : it(i.it){}
    Iterator(const typename multiset<T>::iterator &i) : it(i){}
    Iterator &operator= (const typename Bag<T>::Iterator &i);
    Iterator &operator++ ();
    bool operator== (const typename Bag<T>::Iterator &i);
    T operator* ();
private:
   typename multiset<T>::iterator it;
};


template<class T>
int Bag<T>::size() const
{
    return set.size();
}

template<class T>
bool Bag<T>::isEmpty()
{
    return set.empty();
}

template<class T>
void Bag<T>::insert(const T &elem)
{
    set.insert(elem);
}

template<class T>
void Bag<T>::erase(const T &elem)
{
    set.erase(elem);
}

template<class T>
void Bag<T>::clear()
{
    set.clear();
}

template<class T>
bool Bag<T>::find(const T &elem) const
{
    return set.find(elem) != set.end();
}

template<class T>
typename Bag<T>::Iterator Bag<T>::begin()
{
    return Bag<T>::Iterator(set.begin());
}
template<class T>
typename Bag<T>::Iterator Bag<T>::end()
{
    return Bag<T>::Iterator(set.end());
}


template<class T>
typename Bag<T>::Iterator &Bag<T>::Iterator::operator= (const typename Bag<T>::Iterator &i)
{
    it = i.it;
    return *this;
}
template<class T>
typename Bag<T>::Iterator &Bag<T>::Iterator::operator++ ()
{
    it++;
    return *this;
}
template<class T>
bool Bag<T>::Iterator::operator== (const typename Bag<T>::Iterator &i)
{
    return it == i.it;
}
template<class T>
typename T Bag<T>::Iterator::operator* ()
{
    return *it;
}



#endif // BAG_H
