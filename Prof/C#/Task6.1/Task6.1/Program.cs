using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Task6._1
{
    class Program
    {
        static void Main(string[] args)
        {
           // string[] ss = {"aa", "bb", "cv"};
            foreach (string s in args)
                Console.WriteLine(s);

            Console.ReadKey();

        }
    }
}
