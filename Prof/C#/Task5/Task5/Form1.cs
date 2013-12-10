using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Task5
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            richTextBox1.Clear();
            int i = 1;
            while (i++ < 100)
            {
                if (i % 2 == 0)
                    richTextBox1.Text += i.ToString() + '\n';
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            richTextBox1.Clear();
            int sum = 0;
            int i = 0;
            int N = 10;
            while (i++ < N)
            {
                sum += i * i;
            }
            richTextBox1.Text = sum.ToString();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            richTextBox1.Clear();
            int sum = 0;
            int i = 0;
            while (i++ < 99)
            {
                if (i % 2 == 1)
                 sum += i;
            }
            richTextBox1.Text = sum.ToString();
        }
    }
}
