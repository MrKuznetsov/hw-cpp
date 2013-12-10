using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Task17
{
    interface IDimensions
    {
        float getLength();
        float getWidth();
    }

    class Box : IDimensions
    {
        private float l = 0;
        private float w = 0;

        public Box(float length, float width)
        {
            l = length;
            w = width;
        }

        public float getLength()
        {
            return l;
        }
        public float getWidth()
        {
            return w;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            IDimensions box = new Box(10, 20);

            Console.WriteLine(box.getLength());
            Console.WriteLine(box.getWidth());

            Console.ReadKey();
        }
    }
}
