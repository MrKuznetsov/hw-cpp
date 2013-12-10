using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Task5
{
    public class Integral
    {
        public float A;
        public float B;
        public int M;
        public Function F;

        public float Medium_Rectangle()
        {
            float h = (B - A) / M;
            float s = 0.0f;
            for (int i = 0; i < M; i++)
                s += F.f(A + h * i + h / 2);
            return h * s;
        }

        public float Trapeze()
        {
            float h = (B - A) / M;
            float s = 0.0f;
            for (int i = 0; i < M - 1; i++)
                s += F.f(A + h * (i + 1));

            s += 0.5f * F.f(A) + 0.5f * F.f(B);
            return h * s;
        }

        public float Simpson()
        {
            float h = (B - A) / M;
            float s = 0.0f;
            for (int i = 0; i < M; i++)
                s += (h / 6) * (F.f(A + h * i) + F.f(A + h * (i + 1)) + 4 * F.f(A + h * i + h * 0.5f));
            
            return s;
        }

    }

}
