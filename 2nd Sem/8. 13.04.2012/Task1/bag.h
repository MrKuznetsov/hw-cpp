#ifndef BAG_H
#define BAG_H

#include <set>

using namespace std;

/// generic based class of multiset which use STL multiset
template<class T>
class Bag
{
public:
    class Iterator;

    /// return count of elements of set
    int size() const;
    /// return true if empty
    bool isEmpty();
    /// insert element
    void insert(const T &elem);
    /// remove element
    void erase(const T &elem);
    /// remove all elements
    void clear();
    ///  find element
    bool find(const T &elem) const;

    /// return iterator on first element of set
    Iterator begin();
    /// return iterator on last element of set
    Iterator end();

private:
    multiset<T> set;
};

/// generic based iterator class which use STL multiset<T>::iterator
template<class T>
class Bag<T>::Iterator
{
public:
    /// reload copy from Bag::iterator
    Iterator(const typename Bag<T>::Iterator &i) : it(i.it){}
    /// reload copy from STL iterator
    Iterator(const typename multiset<T>::iterator &i) : it(i){}
    /// reload assign
    Iterator &operator= (const typename Bag<T>::Iterator &i);
    /// reload ++
    Iterator &operator++ ();
    /// reload equeal
    bool operator== (const typename Bag<T>::Iterator &i);
    /// reload *
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
