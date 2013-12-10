using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Task4
{
    public class Differential
    {
        static public void print(Function mFunc, Interpolation mIn)
        {
            Console.WriteLine(" x    | f(x_i) | f'(x_i) | f'(x_i)Т - f'(x_i) |  f''(x_i) | f''(x_i)Т - f''(x_i)");
         //   Console.Write(mFunc.f(x) + " ");
            for (int i = 0; i < mIn.mPoints.Count; i++)
            {
                float x = mIn.mPoints[i].x;
                float h = (mIn.b - mIn.a) / (mIn.mPoints.Count - 1);
                float fx = mFunc.f(x);
                float d1 = 0;
                float d2 = 0;
               // Console.WriteLine(h);
                if (i == 0)
                    d1 = (-3 * mIn.mPoints[i].fx + 4 * mIn.mPoints[i + 1].fx - mIn.mPoints[i + 2].fx) / (2 * h);
                else if (i == mIn.mPoints.Count - 1)
                    d1 = (3 * mIn.mPoints[i].fx - 4 * mIn.mPoints[i - 1].fx + mIn.mPoints[i - 2].fx) / (2 * h);
                else
                    d1 = (mIn.mPoints[i + 1].fx - mIn.mPoints[i - 1].fx) / (2.0f * h);
                if (0 < i && i < mIn.mPoints.Count - 1)
                    d2 = (mIn.mPoints[i + 1].fx - 2 * mIn.mPoints[i].fx + mIn.mPoints[i - 1].fx) / (h * h);

                Console.WriteLine("{0,5} {1,10} {2,10} {3,15} {4,15} {5,10}", x, fx, d1, Math.Abs(mFunc.divf(x) - d1),
                    d2, Math.Abs(mFunc.div2f(x) - d2));
            }
        }
    }
}
