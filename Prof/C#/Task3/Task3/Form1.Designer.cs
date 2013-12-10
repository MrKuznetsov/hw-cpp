namespace Task3
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.panel1 = new System.Windows.Forms.Panel();
            this.panel2 = new System.Windows.Forms.Panel();
            this.Red = new System.Windows.Forms.Panel();
            this.Green = new System.Windows.Forms.Panel();
            this.Yellow = new System.Windows.Forms.Panel();
            this.button1 = new System.Windows.Forms.Button();
            this.button2 = new System.Windows.Forms.Button();
            this.button3 = new System.Windows.Forms.Button();
            this.panel1.SuspendLayout();
            this.panel2.SuspendLayout();
            this.SuspendLayout();
            // 
            // panel1
            // 
            this.panel1.BackColor = System.Drawing.SystemColors.GradientInactiveCaption;
            this.panel1.Controls.Add(this.Yellow);
            this.panel1.Controls.Add(this.Green);
            this.panel1.Controls.Add(this.Red);
            this.panel1.Location = new System.Drawing.Point(13, 13);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(124, 224);
            this.panel1.TabIndex = 0;
            // 
            // panel2
            // 
            this.panel2.BackColor = System.Drawing.SystemColors.GradientInactiveCaption;
            this.panel2.Controls.Add(this.button3);
            this.panel2.Controls.Add(this.button2);
            this.panel2.Controls.Add(this.button1);
            this.panel2.Location = new System.Drawing.Point(144, 13);
            this.panel2.Name = "panel2";
            this.panel2.Size = new System.Drawing.Size(105, 224);
            this.panel2.TabIndex = 1;
            // 
            // Red
            // 
            this.Red.BackColor = System.Drawing.Color.Red;
            this.Red.Location = new System.Drawing.Point(33, 20);
            this.Red.Name = "Red";
            this.Red.Size = new System.Drawing.Size(56, 55);
            this.Red.TabIndex = 0;
            // 
            // Green
            // 
            this.Green.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(192)))), ((int)(((byte)(0)))));
            this.Green.Location = new System.Drawing.Point(33, 140);
            this.Green.Name = "Green";
            this.Green.Size = new System.Drawing.Size(56, 55);
            this.Green.TabIndex = 1;
            // 
            // Yellow
            // 
            this.Yellow.BackColor = System.Drawing.Color.Yellow;
            this.Yellow.Location = new System.Drawing.Point(33, 81);
            this.Yellow.Name = "Yellow";
            this.Yellow.Size = new System.Drawing.Size(56, 55);
            this.Yellow.TabIndex = 2;
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(21, 20);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(66, 55);
            this.button1.TabIndex = 0;
            this.button1.Text = "RED";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(21, 82);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(66, 54);
            this.button2.TabIndex = 1;
            this.button2.Text = "YELLOW";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // button3
            // 
            this.button3.Location = new System.Drawing.Point(21, 143);
            this.button3.Name = "button3";
            this.button3.Size = new System.Drawing.Size(66, 52);
            this.button3.TabIndex = 2;
            this.button3.Text = "GREEN";
            this.button3.UseVisualStyleBackColor = true;
            this.button3.Click += new System.EventHandler(this.button3_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(266, 262);
            this.Controls.Add(this.panel2);
            this.Controls.Add(this.panel1);
            this.Name = "Form1";
            this.Text = "Светофор";
            this.panel1.ResumeLayout(false);
            this.panel2.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.Panel Yellow;
        private System.Windows.Forms.Panel Green;
        private System.Windows.Forms.Panel Red;
        private System.Windows.Forms.Panel panel2;
        private System.Windows.Forms.Button button3;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.Button button1;

    }
}

