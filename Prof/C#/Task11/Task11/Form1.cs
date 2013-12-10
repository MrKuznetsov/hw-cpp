using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Task11
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (maskedTextBox1.Text == maskedTextBox2.Text)
                MessageBox.Show("Поздравления!!");
            else
                MessageBox.Show("Ошибка ввода пароля!!");
        }
    }
}
