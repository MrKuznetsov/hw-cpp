using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace Task13
{
    class Program
    {
        public static void Main(string[] args)
        {
            Console.WriteLine("Input path");
            string path = Console.ReadLine();

            Console.WriteLine("Input mask");
            string mask = Console.ReadLine();

            string[] lines = Directory.GetFiles(path, mask, SearchOption.AllDirectories);
            foreach (string s in lines)
                Console.WriteLine(s);

            Console.ReadKey();
        }
    }

}
