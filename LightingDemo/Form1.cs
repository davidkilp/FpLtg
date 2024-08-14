using System.Drawing;
using System.Windows.Forms;

namespace LightingDemo
{
    public partial class Form1 : Form
    {
        IntPtr frontStrip;
        IntPtr backStrip;

        public Form1()
        {
            InitializeComponent();
            if (initializeHdwControls())
            {
                // Kill the application.
                System.Environment.Exit(1);
            }
        }

        private bool initializeHdwControls()
        {
            try
            {
                frontStrip = LightCtrl.FpLtg_Instantiate(LightCtrl.RGB_Strip.FRONT);
                backStrip = LightCtrl.FpLtg_Instantiate(LightCtrl.RGB_Strip.BACK);
                // Read current values and configure the GUI accordingly
                byte red = 0;
                byte green = 0;
                byte blue = 0;

                LightCtrl.FpLtg_getRGB(frontStrip, ref red, ref green, ref blue);
                Color color = Color.FromArgb(red, green, blue);
                frontColorBtn.BackColor = color;
                if ((red + green + blue) == 0)
                {
                    frontColorBtn.ForeColor = Color.White;
                }

                LightCtrl.FpLtg_getRGB(backStrip, ref red, ref green, ref blue);
                color = Color.FromArgb(red, green, blue);
                backColorBtn.BackColor = color;
                if ((red + green + blue) == 0)
                    backColorBtn.ForeColor = Color.White;


                byte brightness = LightCtrl.FpLtg_getBrightness(frontStrip);
                frontBrightness.Value = brightness;
                brightness = LightCtrl.FpLtg_getBrightness(backStrip);
                backBrightness.Value = brightness;

                bool blink = LightCtrl.FpLtg_getBlink(frontStrip);
                frontBlinkCheck.ThreeState = blink;
                if (!blink)
                {
                    frontBlinkRate.Enabled = false;
                }
                blink = LightCtrl.FpLtg_getBlink(backStrip);
                backBlinkCheck.ThreeState = blink;
                if (!blink)
                {
                    backBlinkRate.Enabled = false;
                }

                byte blinkrate = LightCtrl.FpLtg_getBlinkRate(frontStrip);
                frontBlinkRate.Value = blinkrate;
                blinkrate = LightCtrl.FpLtg_getBlinkRate(backStrip);
                backBlinkRate.Value = blinkrate;

            }
            catch (Exception ex)
            {
                MessageBox.Show("LED Strip hardware failure.\nRestart application or system\n" + ex.Message);
                textStatus.Text = "LED Strip hardware failure. Check connection or restart system";
                return true;
            }

            return false;
        }

        private void frontBrightness_ValueChanged(object sender, EventArgs e)
        {
            byte brightness = (byte)frontBrightness.Value;
            LightCtrl.FpLtg_setBrightness(frontStrip, brightness);
            textStatus.Text = "Front brightness: " + brightness;
        }
        private void backBrightness_ValueChanged(object sender, EventArgs e)
        {
            byte brightness = (byte)backBrightness.Value;
            LightCtrl.FpLtg_setBrightness(backStrip, brightness);
            textStatus.Text = "Back brightness: " + brightness;
        }

        private void frontColorBtn_Click(object sender, EventArgs e)
        {
            ColorDialog colorDialog = new ColorDialog();

            if (colorDialog.ShowDialog() == DialogResult.OK)
            {
                frontColorBtn.BackColor = colorDialog.Color;
                int r, g, b;
                r = frontColorBtn.BackColor.R;
                g = frontColorBtn.BackColor.G;
                b = frontColorBtn.BackColor.B;

                string hexRBG = "Front(RGB): " + r.ToString("X2") + g.ToString("X2") + b.ToString("X2");
                textStatus.Text = hexRBG;
                LightCtrl.FpLtg_setRGB(frontStrip, (byte)r, (byte)g, (byte)b);

                if (frontColorBtn.BackColor == Color.Black)
                    frontColorBtn.ForeColor = Color.White;
                else
                    frontColorBtn.ForeColor = Color.Black;
            }

        }

        private void backColorBtn_Click(object sender, EventArgs e)
        {
            ColorDialog colorDialog = new ColorDialog();

            if (colorDialog.ShowDialog() == DialogResult.OK)
            {
                backColorBtn.BackColor = colorDialog.Color;
                int r, g, b;
                r = backColorBtn.BackColor.R;
                g = backColorBtn.BackColor.G;
                b = backColorBtn.BackColor.B;

                string hexRBG = "Back(RGB): " + r.ToString("X2") + g.ToString("X2") + b.ToString("X2");
                textStatus.Text = hexRBG;
                LightCtrl.FpLtg_setRGB(backStrip, (byte)r, (byte)g, (byte)b);

                if (backColorBtn.BackColor == Color.Black)
                    backColorBtn.ForeColor = Color.White;
                else 
                    backColorBtn.ForeColor = Color.Black;
            }

        }

        private void frontBlinkCheck_CheckedChanged(object sender, EventArgs e)
        {
            // toggle front global blink mode
            bool blink = frontBlinkCheck.Checked;
            LightCtrl.FpLtg_setBlink(frontStrip, blink);
            frontBlinkRate.Enabled = blink;     // turn on/off blink rate value
            textStatus.Text = "Front blink: " + blink;
        }

        private void backBlinkCheck_CheckedChanged(object sender, EventArgs e)
        {
            // toggle back global blink mode
            bool blink = backBlinkCheck.Checked;
            LightCtrl.FpLtg_setBlink(backStrip, blink);
            backBlinkRate.Enabled = blink;     // turn on/off blink rate value
            textStatus.Text = "Back blink: " + blink;
        }

        private void frontBlinkRate_ValueChanged(object sender, EventArgs e)
        {
            byte rate = (byte)frontBlinkRate.Value;
            LightCtrl.FpLtg_setBlinkRate(frontStrip, rate);
            textStatus.Text = "Front LED blink rate: " + rate;
        }

        private void backBlinkRate_ValueChanged(object sender, EventArgs e)
        {
            byte rate = (byte)backBlinkRate.Value;
            LightCtrl.FpLtg_setBlinkRate(backStrip, rate);
            textStatus.Text = "Back LED blink rate: " + rate;
        }
    }
}
