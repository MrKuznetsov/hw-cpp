using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Task12
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            String s = textBox1.Text;
            String ss = "";
            for (int i = 0; i < s.Length; i++)
                if (s[i] != ' ')
                    ss += s[i] + " ";
                else
                    ss += " ";
            String rs = "";
            for (int i = s.Length - 1; i > -1; i--)
                rs += s[i];
            label2.Text = ss + "\n" + rs;
  
        }
    }
}
