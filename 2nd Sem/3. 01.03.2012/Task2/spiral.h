#ifndef SPIRAL_H
#define SPIRAL_H

class Spiral
{
public:
    virtual void ñall(int *a, int N) = 0;
protected:
    void doSpiral(int *a, int N);

    virtual void print(int a) = 0;
};

#endif // SPIRAL_H
