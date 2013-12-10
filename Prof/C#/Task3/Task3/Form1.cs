using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Task3
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            Red.BackColor = Color.Red;
            Yellow.BackColor = Color.Black;
            Green.BackColor = Color.Black;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Red.BackColor = Color.Red;
            Yellow.BackColor = Color.Black;
            Green.BackColor = Color.Black;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Red.BackColor = Color.Black;
            Yellow.BackColor = Color.Yellow;
            Green.BackColor = Color.Black;
        }

        private void button3_Click(object sender, EventArgs e)
        {
            Red.BackColor = Color.Black;
            Yellow.BackColor = Color.Black;
            Green.BackColor = Color.Green;
        }
    }
}
