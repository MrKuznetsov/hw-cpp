using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;
using System.Runtime.CompilerServices;

namespace Task1
{
    class A
    {
        [MethodImpl(MethodImplOptions.Synchronized)]
        static public void method()
        {
        
            Thread.Sleep(1000);
            B.method();
            Console.WriteLine("A has 2 locks");
        }
    }
    class B
    {
        [MethodImpl(MethodImplOptions.Synchronized)]
        static public void method()
        {
            Thread.Sleep(1000);
            A.method();
            Console.WriteLine("B has 2 locks");
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Thread aThread = new Thread(new ThreadStart(A.method));
            Thread bThread = new Thread(new ThreadStart(B.method));
            aThread.Start();
            bThread.Start();
            while (true)
            {

            }
        }
    }
}
