using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Task7
{
    class Program
    {
        static string nextOperand(string s, ref int index)
        {
            string r = "";
            while (index < s.Length)
            {
                if (s[index] == ' ')
                {
                    index++;
                    break;
                }
                r += s[index++];
            }
            return r;
        }

        static void Main(string[] args)
        {
            Console.WriteLine("Input sample:");
            string s = Console.ReadLine();
            int i = 0;
            int left = 0;
            try
            {
                left = int.Parse(nextOperand(s, ref i));
                while (i < s.Length)
                {
                    string op = nextOperand(s, ref i);
                    if (op != "+" && op != "-")
                    {
                        throw new Exception("'" + op + "'" + "wrong opperand");
                    }

                    int right = int.Parse(nextOperand(s, ref i));
                    if (op == "+")
                        left += right;
                    else
                        left -= right;
                }
                Console.WriteLine(s + " = " + left.ToString());
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
            }

            Console.ReadKey();
        }
    }
}
