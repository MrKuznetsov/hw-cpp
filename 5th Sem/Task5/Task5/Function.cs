using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Task5
{
    /**********************************************************
    /*   class Function 
    /**********************************************************/

    public abstract class Function
    {
        abstract public float f(float x);
        abstract public float F(float x);

        abstract public void Print();
    }

    public class EFunction : Function
    {
        override public float f(float x)
        {
            //   return (float)(Math.Exp(x) - x);
           // return (float)(Math.Pow(x, 2) - 2.51);
            return (float)Math.Sin(x);
          //  return x * x * x + x * x;//(float)Math.Sin(x);
            //   return (float)(x * x * x * x - x * x + x - 0.643f);
        }
        override public float F(float x)
        {
            //   return (float)(Math.Exp(x) - x);
            // return (float)(Math.Pow(x, 2) - 2.51);
            return -(float)Math.Cos(x);
           // return x * x * x * x / 4.0f + x * x * x / 3.0f;//-(float)Math.Cos(x);
            //   return (float)(x * x * x * x - x * x + x - 0.643f);
        }
        override public void Print()
        {
            System.Console.WriteLine("sin(x)");
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
