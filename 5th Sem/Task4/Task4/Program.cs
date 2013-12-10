using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Task4
{

    class Program
    {
        static void Main(string[] args)
        {
            System.Console.WriteLine("The problem of the algebraic interpolation.");
            Interpolation i1 = new Interpolation();
            Interpolation i2 = new Interpolation();
            Function f = new EFunction();
            float a = 0.0f;
            float b = 1.0f;

            int m = 10;
            int n = 10;

            System.Console.Write("Function: ");
            f.Print();

            System.Console.WriteLine("Segment: [{0}, {1}]", a, b);
            System.Console.WriteLine("Params: m = {0}, n = {1}", m, n);

            System.Console.WriteLine("Inverse:");
            i1.Func = f;
            i1.Init(m, n, a, b, true);
            System.Console.WriteLine("Normal:");
            i2.Func = f;
            i2.Init(m, n, a, b, false);

            RootSolution rs = new RootSolution();
            rs.Init(0.000001f, 0.05f, a, b, false);
            rs.Func = i2;

            Differential.print(f, i2);

            float fx;
            while (true)
            {
                
                System.Console.WriteLine("Input F");
                float x = Convert.ToSingle(System.Console.ReadLine(), System.Globalization.CultureInfo.InvariantCulture);

                System.Console.WriteLine("First Solution");
                fx = i1.Calc(x, new LagrangeMethod());

                System.Console.WriteLine("Pn(x) = {0}", (float)fx);
                System.Console.WriteLine("efn(x) = {0}", Math.Abs((float)f.f(fx) - x));

                System.Console.WriteLine("Second Solution");
                rs.X = x;
                List<float> roots = rs.getRoots(new BisectionMethod());
                for (int i = 0; i < roots.Count(); i++)
                {
                    fx = roots[i];
                    System.Console.WriteLine("Pn(x) = {0}", (float)fx);
                    System.Console.WriteLine("efn(x) = {0}", Math.Abs((float)f.f(fx) - x));
                }
                
            }


            System.Console.ReadKey();
        }
    }
}
