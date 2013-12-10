using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Task8._2
{
    class Divisior
    {
        public static List<int> div(int a)
        {
            List<int> d = new List<int>();
            for (int i = a; i > 0; i--)
                if (a % i == 0)
                    d.Add(i);
            return d;
        }
    }
}
