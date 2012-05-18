#ifndef COMPOBJECT_H
#define COMPOBJECT_H

template<class T>
class CompElement
{
public:
    virtual ~CompElement(){}
    virtual bool comp(T a, T b) = 0;
};

#endif // COMPOBJECT_H
