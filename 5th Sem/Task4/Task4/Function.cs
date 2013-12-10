using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Task4
{
    /**********************************************************
    /*   class Function 
    /**********************************************************/

    public abstract class Function
    {
        abstract public float f(float x);
        abstract public float divf(float x);
        abstract public float div2f(float x);

        abstract public void Print();
        abstract public float invf(float x);
    }

    public class EFunction : Function
    {
        override public float f(float x)
        {
            //   return (float)(Math.Exp(x) - x);
           // return (float)(Math.Pow(x, 2) - 2.51);
            return (float)Math.Sin(x) + x * x / 2;
            //   return (float)(x * x * x * x - x * x + x - 0.643f);
        }
        override  public float divf(float x)
        {
            return (float)Math.Cos(x) + x;
        }
        override public float div2f(float x)
        {
            return -(float)Math.Sin(x) + 1;
        }
        override public float invf(float x)
        {
            return (float)Math.Asin(x);
        }
        override public void Print()
        {
            System.Console.WriteLine("e^x - x");
        }
    }

    public struct FunctionPoint
    {
        public float x;
        public float fx;

        public FunctionPoint(float _x, float _fx)
        {
            x = _x;
            fx = _fx;
        }
    }
}
