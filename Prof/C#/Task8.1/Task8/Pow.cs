using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Task8
{
    class Pow
    {
        public static int powFor(int a, int n)
        {
            int res = 1;
            for (int i = 0; i < n; i++)
                res *= a;
            return res;
        }
        public static int powWhile(int a, int n)
        {
            int i = 0;
            int res = 1;
            while (i++ < n)
                res *= a;
            return res;
        }
        public static int powRepeat(int a, int n)
        {
            int i = 0;
            int res = 1;
            do
                res *= a;
            while (++i < n);

            return res;
        }
    }
}
