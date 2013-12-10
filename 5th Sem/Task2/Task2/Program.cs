using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Task2
{

    class Program
    {
        static void Main(string[] args)
        {
            System.Console.WriteLine("The problem of the algebraic interpolation.");          
            Interpolation i = new Interpolation();
            Function f = new EFunction();
            float a = 0.4f;
            float b = 1;

            int m = 15;
            int n = 5;

            System.Console.Write("Function: ");
            f.Print();

            System.Console.WriteLine("Segment: [{0}, {1}]", a, b);
            System.Console.WriteLine("Params: m = {0}, n = {1}", m, n);

            i.Func = f;
            i.Init(m, n, a, b);

            float fx;
            while (true)
            {
                System.Console.WriteLine("What method you wanna use? (0 - Lagrange, 1 - Newton)");
                string val = System.Console.ReadLine();

                System.Console.WriteLine("Input X");
                float x = Convert.ToSingle(System.Console.ReadLine(), System.Globalization.CultureInfo.InvariantCulture);

                if (Convert.ToInt32(val) == 0)
                {
                    fx = i.Calc(x, new LagrangeMethod());
                }
                else
                {
                    fx = i.Calc(x, new NewtonMethod());
                }
                

                System.Console.WriteLine("Pn(x) = {0}", (double)fx);
                System.Console.WriteLine("efn(x) = {0}", Math.Abs((float)f.f(x) - (float)fx));
            }
            

            System.Console.ReadKey();
        }
    }
}
