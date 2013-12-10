using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;


namespace Task8
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            int a = int.Parse(textBox1.Text);
            int n = int.Parse(textBox2.Text);
            string msg = "for(" + Pow.powFor(a, n) + "), while(" + Pow.powWhile(a, n) + "), repeat(" + Pow.powRepeat(a, n) + ")";
            MessageBox.Show(msg, "result");
        }
    }

}
