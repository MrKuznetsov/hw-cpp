using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Task6._3
{
    class Program
    {
        static void Main(string[] args)
        {
            int N = 1000;
            for (int i = 2; i <= N; i++)
            {
                int j = 0;
                for (j = 2; j <= (i / j); j++)
                    if (i % j == 0)
                        break;
                if (j > (i / j))
                    Console.WriteLine(i.ToString());
            }
            Console.ReadKey();
        }
    }
}
