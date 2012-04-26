#ifndef VECTOR_H
#define VECTOR_H

/// vector class <TYPE, SIZE>
template<class T, int SIZE = 3>
class Vector
{
public:
    Vector()
    {
        for(int i = 0; i < SIZE; i++)
            val[i] = 0;
    }

    /// check nul vector
    bool isNul() const;
    /// sum of 2 vectors
    Vector operator+ (const Vector<T,SIZE> &v) const;
    /// sum vector and const num
    Vector operator+ (const int &v) const;
    /// sub of 2 vectors
    Vector operator- (const Vector<T,SIZE> &v) const;
    /// sub vector and const num
    Vector operator- (const int &v) const;
    /// mul vector and const num
    Vector operator* (const T &v) const;
    /// div vector and const num
    Vector operator/ (const T &v) const;
    /// copy vector
    Vector operator= (const Vector<T,SIZE> &v);
    /// operator access to the values of vector
    T &operator[] (const int index);
    /// check equality of 2 vectors
    bool operator== (const Vector<T,SIZE> &v) const;
    /// scalar mul for 2 vectors
    T scalar(const Vector<T,SIZE> &v) const;
private:
    T val[SIZE];
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
