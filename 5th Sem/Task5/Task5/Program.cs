using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Task5
{
    class Program
    {
        static void Main(string[] args)
        {
            System.Console.WriteLine("Simple integral.");
            Integral i = new Integral();
            Function f = new EFunction();
            float a = -100f;
            float b = 1000f;

            int m = 10000;

            i.A = a;
            i.B = b;
            i.M = m;
            i.F = f;

            System.Console.Write("Function: ");
            f.Print();
            System.Console.WriteLine("Segment: [{0}, {1}]", a, b);
            System.Console.WriteLine("Params: m = {0}", m);

//            while (true)
  //          {
           //     System.Console.WriteLine("Input X");
             //   float x = Convert.ToSingle(System.Console.ReadLine(), System.Globalization.CultureInfo.InvariantCulture);
                float J = f.F(b) - f.F(a);
                System.Console.WriteLine("J = {0}", J);
                System.Console.WriteLine("Medium Rectangle");
                System.Console.WriteLine("I = {0} |J - I| = {1}", i.Medium_Rectangle(), Math.Abs(i.Medium_Rectangle() - J));
                System.Console.WriteLine("Trapeze");
                System.Console.WriteLine("I = {0} |J - I| = {1}", i.Trapeze(), Math.Abs(i.Trapeze() - J));
                System.Console.WriteLine("Simpson");
                System.Console.WriteLine("I = {0} |J - I| = {1}", i.Simpson(), Math.Abs(i.Simpson() - J));
    //        }
            Console.ReadKey();
        }
    }
}
