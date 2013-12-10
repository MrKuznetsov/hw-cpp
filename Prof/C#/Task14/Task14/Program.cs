using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Task14
{
    class Program
    {
        static void Main(string[] args)
        {
            string infn = "1.txt";//args[0];
            string outfn = "2.txt";//args[1];
            string[] lines = System.IO.File.ReadAllLines(infn);
            Array.Sort(lines, StringComparer.InvariantCulture);
            using (System.IO.StreamWriter file = new System.IO.StreamWriter(outfn))
            {
                for (int i = 0; i < lines.Length; i++)
                    if (i % 2 == 0)
                        file.WriteLine(lines[i]);
            }
            Console.ReadKey();
        }
    }
}
