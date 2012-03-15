#ifndef SPIRAL_H
#define SPIRAL_H

class Spiral
{
protected:
    void doSpiral(int *a, int N);

    virtual void print(int a) = 0;
public:
    virtual void Call(int *a, int N) = 0;
};

#endif // SPIRAL_H
