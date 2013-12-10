using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Runtime.CompilerServices;
using System.Threading.Tasks;
using System.Runtime.Serialization.Formatters.Binary;
using System.IO;

namespace Task3
{
    class Program
    {
        static ClassLibrary1.FooClass pfoo; 

        static void Main(string[] args)
        {
            BinaryFormatter bf = new BinaryFormatter();
            Stream stream = File.OpenRead(@"file.s");
            pfoo = (ClassLibrary1.FooClass)bf.Deserialize(stream);
            Thread[] t = new Thread[4];
            for (int i = 0; i < 4; i++)
            {
                t[i] = new Thread(foo);
                t[i].Start(i);
            }

            while (true) { }
        }

        static void foo(object i)
        {
            int index = (int)i;
         
            //LOL so bad, need to make dictinonary but i am lazy ass
            if (index == 0)
                pfoo.foo1();
            else if (index == 1)
                pfoo.foo2();
            else if (index == 2)
                pfoo.foo3();
            else if (index == 3)
                pfoo.foo4();
            fooDone(index);
        }

      //  [MethodImpl(MethodImplOptions.Synchronized)]
        static void fooDone(int i)
        {
            Console.WriteLine(i + 1);
        }
    }
}
