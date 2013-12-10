using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Task4
{
    /**********************************************************
    /*   class Method 
    /**********************************************************/

    public abstract class Method
    {
        abstract public float calc(float x, Function f, int n, List<FunctionPoint> p);
        // abstract public void Print();
    }


    public class LagrangeMethod : Method
    {
        override public float calc(float x, Function f, int n, List<FunctionPoint> p)
        {

            float fx = 0;
            for (int i = 0; i < n; i++)
            {
                float li = 1;

                for (int j = 0; j < n; j++)
                    if (i != j)
                        li *= (x - p[j].x) / (p[i].x - p[j].x);

                fx += p[i].fx * li;
            }

            return fx;
        }
    }

    public class NewtonMethod : Method
    {
        override public float calc(float x, Function f, int n, List<FunctionPoint> p)
        {

            float fx = p[0].fx;

            float fi = 0;
            float den = 1;

            for (int i = 1; i < n; i++)
            {
                fi = 0;
                for (int j = 0; j <= i; j++)
                {
                    den = 1;
                    for (int k = 0; k <= i; k++)
                        if (k != j)
                            den *= p[j].x - p[k].x;

                    fi += p[j].fx / den;
                }

                for (int j = 0; j < i; j++)
                    fi *= (x - p[j].x);

                fx += fi;

            }

            return fx;
        }
    }
    /**********************************************************
    /*   class Interpolation 
    /**********************************************************/
    public class Interpolation
    {
        public List<FunctionPoint> mPoints;
        private Function mFunc;

        public int m;
        private int n;
        public float a;
        public float b;
        private bool inv;


        public Interpolation()
        {
            mPoints = new List<FunctionPoint>();
        }

        public void Init(int _m, int _n, float _a, float _b, bool _inv)
        {
            m = _m;
            n = _n;
            a = _a;
            b = _b;
            inv = _inv;

            mPoints.Clear();
            for (int i = 0; i < m + 1; i++)
            {
                float x = a + i * (b - a) / m;
                AddPoint(x);
            }
        }

        public void AddPoint(float x)
        {
            if (!inv)
                mPoints.Add(new FunctionPoint(x, mFunc.f(x)));
            else
                mPoints.Add(new FunctionPoint(mFunc.f(x), x));
            System.Console.Write("x= {0}", mPoints[mPoints.Count - 1].x);
            for (int i = 0; i < 15 - mPoints[mPoints.Count - 1].x.ToString().Length; i++)
                System.Console.Write(" ");
            System.Console.WriteLine("f(x)= {0}", mPoints[mPoints.Count - 1].fx);
        }

        public Function Func
        {
            get
            {
                return mFunc;
            }
            set
            {
                mFunc = value;
            }

        }

        public void Sort(float x)
        {
            for (int i = 0; i < mPoints.Count; i++)
                for (int j = i + 1; j < mPoints.Count; j++)
                {
                    FunctionPoint temp1 = mPoints[i];
                    FunctionPoint temp2 = mPoints[j];

                    if (Math.Abs(temp1.x - x) > Math.Abs(temp2.x - x))
                    {
                        mPoints[i] = temp2;
                        mPoints[j] = temp1;
                    }
                }

            for (int i = 0; i < mPoints.Count; i++)
            {
              //          System.Console.WriteLine("x = {0}  fx = {1}", mPoints[i].x, mPoints[i].fx);

            }
        }

        public float Calc(float x, Method m)
        {
            Sort(x);
            return m.calc(x, mFunc, n, mPoints);
        }

    }
}
