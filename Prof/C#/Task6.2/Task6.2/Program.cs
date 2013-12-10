using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Task6._2
{
    class Program
    {
        static void Main(string[] args)
        {
            int N = 5;
            int[,] matrix = new int[N, N];
            Random rnd = new Random();

            for (int i = 0; i < N; i++)
                for (int j = 0; j < N; j++)
                    matrix[i, j] = rnd.Next(-100, 100);

            bool hasNeg = false;
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                    if (matrix[i, j] < 0)
                    {
                        hasNeg = true;
                        break;
                    }
                if (hasNeg)
                    break;
            }

            if (hasNeg)
                Console.WriteLine("Matrix has negative numbers");
            else
                Console.WriteLine("Matrix has not negative numbers");

            Console.ReadKey();

        }
    }
}
