using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Task6
{
    /**********************************************************
    /*   class Function 
    /**********************************************************/

    public abstract class Function
    {
        abstract public float f(float x);
        abstract public float w(float x);
        abstract public float m(int k, float a, float b);

        abstract public void Print();
    }

    public class EFunction : Function
    {
        override public float f(float x)
        {
            return (float)Math.Sin(x);
        }
        override public float w(float x)
        {
            return 1.0f / (float)Math.Sqrt(x);
        }
        override public float m(int k, float a, float b)
        {
            return (float)Math.Pow(b, k + 0.5f) / (k + 0.5f) - (float)Math.Pow(a, k + 0.5f) / (k + 0.5f);
        }
        override public void Print()
        {
            System.Console.WriteLine("f(x) = sin(x), w(x) = 1 / x^1/2");
        }
    }

    public class Polynomial
    {
        public float[] a;
        public int N;
        public Polynomial(int n, float[] k)
        {
            N = n;
            a = new float[N];
            for (int i = 0; i < N; i++)
                a[i] = k[i];
        }
        public float f(float x)
        {
            float res = 0;
            for (int i = 0; i < N; i++)
                res += a[N - i - 1] * (float)Math.Pow(x, i);
            res += (float)Math.Pow(x, N);
            return res;
        }

    }

}
