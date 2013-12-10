using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Task6
{
    class Program
    {
        static void Main(string[] args)
        {
            Function F = new EFunction();
            Console.WriteLine("Approximation of solutions of integrals");
            F.Print();
            float a = 0;
            float b = 1.0f; //b > a
            Console.WriteLine("[a,b] = [{0}, {1}]", a, b);
            int M = 100;
            int N = 3;
            Console.WriteLine("M = {0}, N = {1}", M, N);
            float[] m = new float[2 * N];
            for (int i = 0; i < 2 * N; i++)
            {
                m[i] = F.m(i, a, b);
                Console.WriteLine("m[{0}] = {1}", i, m[i]);
            }
            Console.WriteLine("Matrix");
            float[,] matrix = new float[N, N + 1];
            for (int i = 0; i < N; i++)
            {
                Console.Write("(");
                for (int j = 0; j < N; j++)
                {
                    matrix[i, j] = m[N - 1 + i - j];
                    Console.Write(matrix[i, j] + " ");
                }
                Console.Write(") (");
                matrix[i, N] = -m[N + i];
                Console.Write(matrix[i, N] + ")");
                Console.WriteLine("");
            }
            float[] ak = new float[N];
            MatrixRoots.get(matrix, ref ak, N);
            Console.WriteLine("a[i]:");
            for (int i = 0; i < N; i++)
                Console.WriteLine("a[{0}] = {1}", i, ak[i]);

            Polynomial p = new Polynomial(N, ak);
            RootSolution roots = new RootSolution();
            roots.Init(0.0001f, -1, a, b, false);
            roots.Func = p;
            Console.WriteLine("Roots");
            List<float> x = roots.getRoots(new BisectionMethod());
            for (int i = 0; i < x.Count; i++)
                Console.WriteLine("x[{0}] = {1}", i, x[i]);

            float[] A = new float[N];
            // N == 3
            Console.WriteLine("Coefficients");
            float sum = 0;
            float J = 0;
            if (N == 3)
                for (int i = 0; i < N; i++)
                {
                    float wk = (x[i] - x[0]) * (x[i] - x[1]) + (x[i] - x[0]) * (x[i] - x[2]) + (x[i] - x[1]) * (x[i] - x[2]);
                    float integral = m[2] - m[1] * (x[(i + 1) % N] + x[(i + 2) % N]) + m[0] * x[(i + 1) % N] * x[(i + 2) % N];
                    A[i] = integral / wk;
                    sum += A[i];
                    J += A[i] * F.f(x[i]);
                    Console.WriteLine("A[{0}] = {1}", i, A[i]);
                }
            else
            {
                Console.WriteLine("This N({0}) doesnt supported", N);
                Console.ReadKey();
                return;
            }

            Console.WriteLine("RESULT:");
            Console.WriteLine("|m0 - sum A[i]| = {0}", Math.Abs(m[0] - sum));
            Console.WriteLine("J = {0}", J);

            Console.ReadKey();
        }
    }
}
