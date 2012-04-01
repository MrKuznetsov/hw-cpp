#ifndef SPIRAL_H
#define SPIRAL_H

/**
@class Spiral
Базовый абстрактный класс обхода массива по спиральке
*/

class Spiral
{
public:
    /// обход массива по спирали
    virtual void сall(int *a, int N) = 0;
protected:
    void doSpiral(int *a, int N);

    virtual void print(int a) = 0;
};

#endif // SPIRAL_H
