using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Globalization;

namespace Task18
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Input angle");as
            float rad = Convert.ToSingle(Console.ReadLine(), CultureInfo.InvariantCulture);
            double deg    = Math.PI * rad / 180.0;

            Console.WriteLine("cos({0}) in rad is {1}, in deg is {2}", rad, Math.Cos(deg), Math.Cos(rad));

            Console.WriteLine("Input a, b, c of trinagle");
            float a = Convert.ToSingle(Console.ReadLine(), CultureInfo.InvariantCulture);
            float b = Convert.ToSingle(Console.ReadLine(), CultureInfo.InvariantCulture);
            float c = Convert.ToSingle(Console.ReadLine(), CultureInfo.InvariantCulture);

            float s = (a + b + c) / 2;
            float area = (float)Math.Sqrt(s * (s - a) * (s - b) * (s - c));
            Console.WriteLine("Area of triangle is {0}", area);

            Console.ReadKey();
        }
    }
}
