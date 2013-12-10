using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Task4._2
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            float height = float.Parse(textBox1.Text);
            float weight = float.Parse(textBox2.Text);
            float k = weight / (height * height);
            string msg = ""; 
            if (k >= 36)
                msg = "Клиническое ожирение, опасное для здоровья";
            else if (k >= 31)
                msg = "Умеренное ожирение";
            else if (k >= 26)
                msg = "Избыточный вес";
            else if (k >= 19)
                msg = "Норма";
            else
                msg = "Недостаточный вес";
            MessageBox.Show(k.ToString() + " " + msg, "result");
        }
    }
}
