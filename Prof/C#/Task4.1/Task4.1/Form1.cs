using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Task4._1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string msg = "";
            int input = int.Parse(textBox1.Text);
            switch (input)
            {
                case 1:
                    msg = "I";
                    break;
                case 2:
                    msg = "II";
                    break;
                case 3:
                    msg = "III";
                    break;
                case 4:
                    msg = "IV";
                    break;
                case 5:
                    msg = "V";
                    break;
                case 6:
                    msg = "VI";
                    break;
                case 7:
                    msg = "VII";
                    break;
                case 8:
                    msg = "VIII";
                    break;
                case 9:
                    msg = "IX";
                    break;
                case 10:
                    msg = "X";
                    break;
                case 11:
                    msg = "XI";
                    break;
                case 12:
                    msg = "XII";
                    break;
                default:
                    msg = "Wrong number";
                    break;
            }
            MessageBox.Show(msg, "result");
        }
    }
}
