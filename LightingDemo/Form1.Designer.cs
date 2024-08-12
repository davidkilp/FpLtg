namespace LightingDemo
{
    partial class Form1
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
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
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            frontColorBtn = new Button();
            frontBrightness = new NumericUpDown();
            frontBlinkRate = new NumericUpDown();
            frontBlinkCheck = new CheckBox();
            frontBrightDClabel = new Label();
            frontBlinklabel = new Label();
            frontGroupBox = new GroupBox();
            backBlinklabel = new Label();
            backBrightDClabel = new Label();
            backBlinkCheck = new CheckBox();
            backBlinkRate = new NumericUpDown();
            backBrightness = new NumericUpDown();
            backColorBtn = new Button();
            BackGroupBox = new GroupBox();
            label1 = new Label();
            colorDialog1 = new ColorDialog();
            textStatus = new TextBox();
            ((System.ComponentModel.ISupportInitialize)frontBrightness).BeginInit();
            ((System.ComponentModel.ISupportInitialize)frontBlinkRate).BeginInit();
            ((System.ComponentModel.ISupportInitialize)backBlinkRate).BeginInit();
            ((System.ComponentModel.ISupportInitialize)backBrightness).BeginInit();
            SuspendLayout();
            // 
            // frontColorBtn
            // 
            frontColorBtn.Font = new Font("Segoe UI", 18F, FontStyle.Regular, GraphicsUnit.Point, 0);
            frontColorBtn.Location = new Point(137, 55);
            frontColorBtn.Name = "frontColorBtn";
            frontColorBtn.Size = new Size(96, 55);
            frontColorBtn.TabIndex = 1;
            frontColorBtn.Text = "Color";
            frontColorBtn.UseVisualStyleBackColor = true;
            frontColorBtn.Click += frontColorBtn_Click;
            // 
            // frontBrightness
            // 
            frontBrightness.Font = new Font("Segoe UI", 18F, FontStyle.Regular, GraphicsUnit.Point, 0);
            frontBrightness.Location = new Point(137, 169);
            frontBrightness.Maximum = new decimal(new int[] { 15, 0, 0, 0 });
            frontBrightness.Name = "frontBrightness";
            frontBrightness.Size = new Size(120, 39);
            frontBrightness.TabIndex = 2;
            frontBrightness.ValueChanged += frontBrightness_ValueChanged;
            // 
            // frontBlinkRate
            // 
            frontBlinkRate.Font = new Font("Segoe UI", 18F, FontStyle.Regular, GraphicsUnit.Point, 0);
            frontBlinkRate.Location = new Point(137, 303);
            frontBlinkRate.Maximum = new decimal(new int[] { 255, 0, 0, 0 });
            frontBlinkRate.Name = "frontBlinkRate";
            frontBlinkRate.Size = new Size(120, 39);
            frontBlinkRate.TabIndex = 4;
            frontBlinkRate.ValueChanged += frontBlinkRate_ValueChanged;
            // 
            // frontBlinkCheck
            // 
            frontBlinkCheck.AutoSize = true;
            frontBlinkCheck.Font = new Font("Segoe UI", 15.75F, FontStyle.Regular, GraphicsUnit.Point, 0);
            frontBlinkCheck.Location = new Point(137, 226);
            frontBlinkCheck.Name = "frontBlinkCheck";
            frontBlinkCheck.Size = new Size(76, 34);
            frontBlinkCheck.TabIndex = 3;
            frontBlinkCheck.Text = "Blink";
            frontBlinkCheck.UseVisualStyleBackColor = true;
            frontBlinkCheck.CheckedChanged += frontBlinkCheck_CheckedChanged;
            // 
            // frontBrightDClabel
            // 
            frontBrightDClabel.AutoSize = true;
            frontBrightDClabel.Font = new Font("Segoe UI", 18F, FontStyle.Regular, GraphicsUnit.Point, 0);
            frontBrightDClabel.Location = new Point(135, 134);
            frontBrightDClabel.Name = "frontBrightDClabel";
            frontBrightDClabel.Size = new Size(125, 32);
            frontBrightDClabel.TabIndex = 5;
            frontBrightDClabel.Text = "Brightness";
            // 
            // frontBlinklabel
            // 
            frontBlinklabel.AutoSize = true;
            frontBlinklabel.Font = new Font("Segoe UI", 18F, FontStyle.Regular, GraphicsUnit.Point, 0);
            frontBlinklabel.Location = new Point(137, 268);
            frontBlinklabel.Name = "frontBlinklabel";
            frontBlinklabel.Size = new Size(120, 32);
            frontBlinklabel.TabIndex = 6;
            frontBlinklabel.Text = "Blink Rate";
            // 
            // frontGroupBox
            // 
            frontGroupBox.Font = new Font("Segoe UI", 14.25F, FontStyle.Regular, GraphicsUnit.Point, 0);
            frontGroupBox.Location = new Point(102, 17);
            frontGroupBox.Name = "frontGroupBox";
            frontGroupBox.Size = new Size(201, 352);
            frontGroupBox.TabIndex = 7;
            frontGroupBox.TabStop = false;
            frontGroupBox.Text = "Front LED Strip";
            // 
            // backBlinklabel
            // 
            backBlinklabel.AutoSize = true;
            backBlinklabel.Font = new Font("Segoe UI", 18F, FontStyle.Regular, GraphicsUnit.Point, 0);
            backBlinklabel.Location = new Point(396, 268);
            backBlinklabel.Name = "backBlinklabel";
            backBlinklabel.Size = new Size(120, 32);
            backBlinklabel.TabIndex = 13;
            backBlinklabel.Text = "Blink Rate";
            // 
            // backBrightDClabel
            // 
            backBrightDClabel.AutoSize = true;
            backBrightDClabel.Font = new Font("Segoe UI", 18F, FontStyle.Regular, GraphicsUnit.Point, 0);
            backBrightDClabel.Location = new Point(394, 134);
            backBrightDClabel.Name = "backBrightDClabel";
            backBrightDClabel.Size = new Size(125, 32);
            backBrightDClabel.TabIndex = 12;
            backBrightDClabel.Text = "Brightness";
            // 
            // backBlinkCheck
            // 
            backBlinkCheck.AutoSize = true;
            backBlinkCheck.Font = new Font("Segoe UI", 15.75F, FontStyle.Regular, GraphicsUnit.Point, 0);
            backBlinkCheck.Location = new Point(396, 226);
            backBlinkCheck.Name = "backBlinkCheck";
            backBlinkCheck.Size = new Size(76, 34);
            backBlinkCheck.TabIndex = 10;
            backBlinkCheck.Text = "Blink";
            backBlinkCheck.UseVisualStyleBackColor = true;
            backBlinkCheck.CheckedChanged += backBlinkCheck_CheckedChanged;
            // 
            // backBlinkRate
            // 
            backBlinkRate.Font = new Font("Segoe UI", 18F, FontStyle.Regular, GraphicsUnit.Point, 0);
            backBlinkRate.Location = new Point(396, 303);
            backBlinkRate.Maximum = new decimal(new int[] { 255, 0, 0, 0 });
            backBlinkRate.Name = "backBlinkRate";
            backBlinkRate.Size = new Size(120, 39);
            backBlinkRate.TabIndex = 11;
            backBlinkRate.ValueChanged += backBlinkRate_ValueChanged;
            // 
            // backBrightness
            // 
            backBrightness.Font = new Font("Segoe UI", 18F, FontStyle.Regular, GraphicsUnit.Point, 0);
            backBrightness.Location = new Point(396, 169);
            backBrightness.Maximum = new decimal(new int[] { 15, 0, 0, 0 });
            backBrightness.Name = "backBrightness";
            backBrightness.Size = new Size(120, 39);
            backBrightness.TabIndex = 9;
            backBrightness.ValueChanged += backBrightness_ValueChanged;
            // 
            // backColorBtn
            // 
            backColorBtn.Font = new Font("Segoe UI", 18F, FontStyle.Regular, GraphicsUnit.Point, 0);
            backColorBtn.Location = new Point(396, 55);
            backColorBtn.Name = "backColorBtn";
            backColorBtn.Size = new Size(96, 55);
            backColorBtn.TabIndex = 8;
            backColorBtn.Text = "Color";
            backColorBtn.UseVisualStyleBackColor = true;
            backColorBtn.Click += backColorBtn_Click;
            // 
            // BackGroupBox
            // 
            BackGroupBox.Font = new Font("Segoe UI", 14.25F, FontStyle.Regular, GraphicsUnit.Point, 0);
            BackGroupBox.Location = new Point(361, 17);
            BackGroupBox.Name = "BackGroupBox";
            BackGroupBox.Size = new Size(201, 352);
            BackGroupBox.TabIndex = 14;
            BackGroupBox.TabStop = false;
            BackGroupBox.Text = "Back LED Strip";
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Font = new Font("Segoe UI", 15.75F, FontStyle.Regular, GraphicsUnit.Point, 0);
            label1.Location = new Point(111, 384);
            label1.Name = "label1";
            label1.Size = new Size(74, 30);
            label1.TabIndex = 15;
            label1.Text = "Status:";
            // 
            // textStatus
            // 
            textStatus.Enabled = false;
            textStatus.Font = new Font("Segoe UI", 12F, FontStyle.Regular, GraphicsUnit.Point, 0);
            textStatus.Location = new Point(193, 392);
            textStatus.Multiline = true;
            textStatus.Name = "textStatus";
            textStatus.ScrollBars = ScrollBars.Vertical;
            textStatus.Size = new Size(369, 67);
            textStatus.TabIndex = 16;
            textStatus.Text = "N/A";
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(658, 502);
            Controls.Add(textStatus);
            Controls.Add(label1);
            Controls.Add(backBlinklabel);
            Controls.Add(backBrightDClabel);
            Controls.Add(backBlinkCheck);
            Controls.Add(backBlinkRate);
            Controls.Add(backBrightness);
            Controls.Add(backColorBtn);
            Controls.Add(BackGroupBox);
            Controls.Add(frontBlinklabel);
            Controls.Add(frontBrightDClabel);
            Controls.Add(frontBlinkCheck);
            Controls.Add(frontBlinkRate);
            Controls.Add(frontBrightness);
            Controls.Add(frontColorBtn);
            Controls.Add(frontGroupBox);
            Name = "Form1";
            Text = "Lighting Demo";
            ((System.ComponentModel.ISupportInitialize)frontBrightness).EndInit();
            ((System.ComponentModel.ISupportInitialize)frontBlinkRate).EndInit();
            ((System.ComponentModel.ISupportInitialize)backBlinkRate).EndInit();
            ((System.ComponentModel.ISupportInitialize)backBrightness).EndInit();
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Button frontColorBtn;
        private NumericUpDown frontBrightness;
        private NumericUpDown frontBlinkRate;
        private CheckBox frontBlinkCheck;
        private Label frontBrightDClabel;
        private Label frontBlinklabel;
        private GroupBox frontGroupBox;
        private Label backBlinklabel;
        private Label backBrightDClabel;
        private CheckBox backBlinkCheck;
        private NumericUpDown backBlinkRate;
        private NumericUpDown backBrightness;
        private Button backColorBtn;
        private GroupBox BackGroupBox;
        private Label label1;
        private ColorDialog colorDialog1;
        private TextBox textStatus;
    }
}
