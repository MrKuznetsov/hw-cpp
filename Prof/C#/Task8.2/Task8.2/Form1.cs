using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Task8._2
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

            int a = int.Parse(textBox1.Text);
            List<int> d = Divisior.div(a);

            for (int i = 0; i < d.Count; i++)
                richTextBox1.Text += d[i].ToString() + "\n";
        }
    }
}
