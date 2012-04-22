#ifndef VECTOR_H
#define VECTOR_H

template<class T, int SIZE = 3>
class Vector
{
public:
    T val[SIZE];

    Vector()
    {
        for(int i = 0; i < SIZE; i++)
            val[i] = 0;
    }

    bool isNul() const;
    Vector operator+ (const Vector<T,SIZE> &v) const;
    Vector operator+ (const int &v) const;
    Vector operator- (const Vector<T,SIZE> &v) const;
    Vector operator- (const int &v) const;
    Vector operator* (const T &v) const;
    Vector operator/ (const T &v) const;
    Vector operator= (const Vector<T,SIZE> &v);
    T &operator[] (const int index);
    bool operator== (const Vector<T,SIZE> &v) const;
    T scalar(const Vector<T,SIZE> &v) const;
};


template<class T, int SIZE>
Vector<T,SIZE> Vector<T,SIZE>::operator+ (const Vector<T,SIZE> &v) const
{
    Vector<T,SIZE> r;
    for(int i = 0; i < SIZE; i++)
        r.val[i] = this->val[i] + v.val[i];
    return r;
}

template<class T, int SIZE>
T Vector<T, SIZE>::scalar(const Vector<T,SIZE> &v) const
{
    T r = 0;
    for(int i = 0; i < SIZE; i++)
        r += this->val[i] * v.val[i];
    return r;
}

template<class T, int SIZE>
bool Vector<T,SIZE>::isNul () const
{
    for(int i = 0; i < SIZE; i++)
        if (this->val[i] != 0)
            return false;
    return true;
}

template<class T, int SIZE>
Vector<T,SIZE> Vector<T,SIZE>::operator+ (const int &v) const
{
    Vector<T,SIZE> r;
    for(int i = 0; i < SIZE; i++)
        r.val[i] = this->val[i] + v;
    return r;
}

template<class T, int SIZE>
Vector<T,SIZE> Vector<T,SIZE>::operator- (const Vector<T,SIZE> &v) const
{
    Vector<T,SIZE> r;
    for(int i = 0; i < SIZE; i++)
        r.val[i] = this->val[i] - v.val[i];
    return r;
}

template<class T, int SIZE>
Vector<T,SIZE> Vector<T,SIZE>::operator- (const int &v) const
{
    Vector<T,SIZE> r;
    for(int i = 0; i < SIZE; i++)
        r.val[i] = this->val[i] - v;
    return r;
}


template<class T, int SIZE>
Vector<T,SIZE> Vector<T,SIZE>::operator* (const T &v) const
{
    Vector<T,SIZE> r;
    for(int i = 0; i < SIZE; i++)
        r.val[i] = this->val[i] * v;
    return r;
}

template<class T, int SIZE>
Vector<T,SIZE> Vector<T,SIZE>::operator/ (const T &v) const
{
    Vector<T,SIZE> r;
    for(int i = 0; i < SIZE; i++)
        r.val[i] = this->val[i] / v;
    return r;
}

template<class T, int SIZE>
Vector<T,SIZE> Vector<T,SIZE>::operator= (const Vector<T,SIZE> &v)
{
    for(int i = 0; i < SIZE; i++)
        this->val[i] = v.val[i];
    return *this;
}

template<class T, int SIZE>
T &Vector<T,SIZE>::operator[] (const int index)
{
    return this->val[index];
}

template<class T, int SIZE>
bool Vector<T,SIZE>::operator== (const Vector<T,SIZE> &v) const
{
    for(int i = 0; i < SIZE; i++)
        if (this->val[i] != v.val[i])
            return false;
    return true;
}


#endif // VECTOR_H
