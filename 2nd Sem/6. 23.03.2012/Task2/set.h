#ifndef SET_H
#define SET_H

/// base abstract set class
template<class T>
class Set
{
public:
    virtual ~Set(){}
    /// add element to set
    virtual void add(T elem) = 0;
    /// remove element from set
    virtual void remove(T elem) = 0;
    /// check elemnt in set
    virtual bool in(T elem) = 0;
    /// intersection 2 sets
    virtual void intersection(Set<T> *s) = 0;
    /// combine 2 sets
    virtual void combine(Set<T> *s) = 0;
//protected:
    /// check curent elemnt is last
    virtual bool isEnd() = 0;
    /// get next elemnt in set
    virtual T getNext() = 0;
    /// set position of elemnt to beginning
    virtual void setBegin() = 0;
};

#endif // SET_H
