using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace Task15
{
    class Program
    {
        static void Main(string[] args)
        {
            using (StreamReader sr = new StreamReader("1.txt"))
            {
                string line;
                while ((line = sr.ReadLine()) != null)            
                    Console.WriteLine(line);
                
            }
            Console.ReadKey();
        }
    }
}
