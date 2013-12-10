using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Task3
{
    /**********************************************************
    /*   class Function 
    /**********************************************************/

    public abstract class Function
    {
        abstract public double f(double x);
        abstract public void Print();
    }

    public class EFunction : Function
    {
        override public double f(double x)
        {
               return (double)(1 - Math.Exp(-2 * x));
            //return (double)(Math.Pow(x, 2) - 2.51);
            //   return (double)(x * x * x * x - x * x + x - 0.643f);
        }
        override public void Print()
        {
            System.Console.WriteLine("1 - e^-2x");
        }
    }

    public struct FunctionPoint
    {
        public double x;
        public double fx;
        public double[] dx;

        public FunctionPoint(double _x, double _fx, int n)
        {
            x = _x;
            fx = _fx;
            dx = new double[n];
            dx[0] = _fx;
        }
    }
    /**********************************************************
    /*   class Method 
    /**********************************************************/

    public abstract class Method
    {
        abstract public double calc(double x, Function f, int n, List<FunctionPoint> p);
        // abstract public void Print();
    }


    public class NewtonMethod : Method
    {
        override public double calc(double x, Function f, int n, List<FunctionPoint> p)
        {
            System.Console.WriteLine("N");
            double a = p[0].x;
            double b = p[p.Count - 1].x;
            double h = p[1].x - p[0].x;
            double t = t = (x - b) / h;
            int k = -1;
            int index = p.Count - 1;  
            if (x < a + h)
            {
                t = (x - a) / h;
                k = 1;
                index = 0;
            }
            System.Console.WriteLine(a.ToString() + " " + b.ToString() + " " + h.ToString() + " " + t.ToString());

            double pn = p[index].dx[0];

            for (int i = 1; i <= n; i++)
            {
                double den = t;
                for (int j = 2; j <= i; j++)
                    den *= (t - k * (j - 1)) / j;

                if (k == -1)
                    pn += den * p[index - i].dx[i];
                else
                    pn += den * p[index].dx[i];
            }
            return pn;
        }
    }
    public class GaussMethod : Method
    {
        override public double calc(double x, Function f, int n, List<FunctionPoint> p)
        {
            System.Console.WriteLine("G");
            double a = p[0].x;
            double b = p[p.Count - 1].x;
            double h = p[1].x - p[0].x;
            int index = (int)(x / h);
            double t = (x - p[index].x) / h;


            double pn = p[index].fx;

            for (int i = 1; i <= n; i++)
            {
                double den = t;
                for (int j = 2; j <= i; j++)
                    den *= (t - (double)Math.Pow(-1, j) * (int)(j / 2)) / j;
                pn += den * p[index - (int)(i / 2)].dx[i];
            }
            return pn;
        }
    }
    /**********************************************************
    /*   class Interpolation 
    /**********************************************************/
    public class Interpolation
    {
        private List<FunctionPoint> mPoints;
        private Function mFunc;

        private int m;
        private int n;
        private double a;
        private double b;


        public Interpolation()
        {
            mPoints = new List<FunctionPoint>();
        }

        public void Init(int _m, int _n, double _a, double _b)
        {
            m = _m;
            n = _n;
            a = _a;
            b = _b;

            mPoints.Clear();
            for (int i = 0; i < m + 1; i++)
            {
                double x = a + i * (b - a) / m;
                AddPoint(x);
            }
            MakeTable();

        }

        public void AddPoint(double x)
        {
            mPoints.Add(new FunctionPoint(x, mFunc.f(x), m + 1));

            System.Console.Write("x= {0}", x);
            for (int i = 0; i < 15 - x.ToString().Length; i++)
                System.Console.Write(" ");
            System.Console.WriteLine("f(x)= {0}", mFunc.f(x));
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

        public void MakeTable()
        {
            int size = m;
            for (int i = 1; i < mPoints.Count; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    mPoints[j].dx[i] = mPoints[j + 1].dx[i - 1] - mPoints[j].dx[i - 1];
//                    System.Console.Write(mPoints[j].dx[i].ToString() + " ");
                }
//                System.Console.WriteLine();
                size--;
            }
        }

        public double Calc(double x)
        {
            Method met;

            if (x > a + (b - a)/m && x < b - (b - a)/m)
                met = new GaussMethod();
            else
                met = new NewtonMethod(); 
            return met.calc(x, mFunc, n, mPoints);
            //return m.calc(x, mFunc, n, mPoints);
        }

    }

    class Program
    {
        static void Main(string[] args)
        {
            System.Console.WriteLine("The problem of the algebraic interpolation.");
            Interpolation i = new Interpolation();
            Function f = new EFunction();
            double a = 0;
            double b = 1;

            int m = 10;
            int n = 5;// n <= m
            double h = (b-a)/m;

            System.Console.Write("Function: ");
            f.Print();

            System.Console.WriteLine("Segment: [{0}, {1}]", a, b);
            System.Console.WriteLine("Params: m = {0}, n = {1}", m, n);

            i.Func = f;
            i.Init(m, n, a, b);

            double fx;
            while (true)
            {
                System.Console.WriteLine("Input X in ["+a.ToString()+", "+h.ToString()+"]" + " ["+(b-h).ToString()+", "+b.ToString()+"]");
                System.Console.WriteLine("[" + (a + ((int)(n + 1) / 2) * h).ToString() + ", " + (b - ((int)(n + 1) / 2) * h).ToString() + "]");
                double x = Convert.ToSingle(System.Console.ReadLine(), System.Globalization.CultureInfo.InvariantCulture);

                fx = i.Calc(x);

                System.Console.WriteLine("Pn(x) = {0}", (double)fx);
                System.Console.WriteLine("efn(x) = {0}", Math.Abs((double)f.f(x) - (double)fx));
            }


            System.Console.ReadKey();
        }
    }
}
