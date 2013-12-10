using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Task6
{
    static public class MatrixRoots
    {
        static public void get(float[,] matrix, ref float[] output, int N)
        {
            for (int i = 0; i < N; i++)
            {
                float div = 1.0f / matrix[i,i];
                matrix[i, i] = 0.0f;
                for (int j = i + 1; j < N + 1; j++)
                    matrix[i, j] *= div;
                for (int j = i + 1; j < N; j++)
                {
                    float tmp = matrix[j, i];
                    for (int k = i + 1; k < N + 1; k++)
                        matrix[j, k] -= tmp * matrix[i, k];
                }
            }

            for (int i = N - 1; i > -1; i--)
            {
                output[i] = matrix[i, N];
                for (int j = 0; j < i; j++)
                    matrix[j, N] -= matrix[j, i] * output[i];
            }

        }
    }
}
