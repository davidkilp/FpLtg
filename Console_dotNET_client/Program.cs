using System.Reflection;

namespace Console_dotNET_client
{
    internal class Program
    {
        void testLedStrips()
        {
            Console.WriteLine("Begin test");
            Console.WriteLine("Current directory: "+
                Path.GetDirectoryName(Assembly.GetExecutingAssembly().Location));

            // must be called to initialize hardware
            IntPtr frontStrip = LightCtrl.FpLtg_Instantiate(LightCtrl.RGB_Strip.FRONT);
            IntPtr backStrip = LightCtrl.FpLtg_Instantiate(LightCtrl.RGB_Strip.FRONT);

            // set colors of both strips
            LightCtrl.FpLtg_setRGB(frontStrip, 0x21, 0xFF, 0xAA);
            LightCtrl.FpLtg_setRGB(backStrip, 0x00, 0x00, 0xFF);

            LightCtrl.FpLtg_setBrightness(frontStrip, 6);
            LightCtrl.FpLtg_setBrightness(backStrip, 6);
            Thread.Sleep(1000);

            Console.WriteLine("Change Brightness on Front and Back");
            for (byte i = 0; i < 16; i++)
            {
                Console.WriteLine("Brightness: " + i);
                LightCtrl.FpLtg_setBrightness(frontStrip, i);
                LightCtrl.FpLtg_setBrightness(backStrip, i);
                Thread.Sleep(1000);
            }

            Console.WriteLine("Make both blink");
            LightCtrl.FpLtg_setBlinkRate(frontStrip, 10);
            LightCtrl.FpLtg_setBlinkRate(backStrip, 20);

            LightCtrl.FpLtg_setDutyCycle(frontStrip, 8);
            LightCtrl.FpLtg_setDutyCycle(backStrip, 8);

            LightCtrl.FpLtg_setBlink(frontStrip, true);
            LightCtrl.FpLtg_setBlink(backStrip, true);

            Thread.Sleep(1500);

            Console.WriteLine("Adjusting Blink Duty Cycle");
            for (byte i = 0; i < 16; i++)
            {
                Console.WriteLine("Brightness: " + i);
                LightCtrl.FpLtg_setDutyCycle(frontStrip, i);
                LightCtrl.FpLtg_setDutyCycle(backStrip, i);
                Thread.Sleep(1000);
            }

            Console.WriteLine("Set duty cycle back to ~50%");
            LightCtrl.FpLtg_setDutyCycle(frontStrip, 8);
            LightCtrl.FpLtg_setDutyCycle(backStrip, 8);
            Thread.Sleep(1500);

            Console.WriteLine("Blink off");
            LightCtrl.FpLtg_setBlink(frontStrip, false);
            LightCtrl.FpLtg_setBlink(backStrip, false);

            Console.WriteLine("Brightness at 6");
            LightCtrl.FpLtg_setBrightness(frontStrip, 6);
            LightCtrl.FpLtg_setBrightness(frontStrip, 6);

            Thread.Sleep(1500);

        }

        static void Main(string[] args)
        {
            Console.WriteLine("Ligthing Test program");
            Program program = new Program();

            try
            {
                //saveLedStrips();
                program.testLedStrips();
                //estoreLedStrips();

            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.ToString());
            }

            Console.WriteLine("Lighting Test ccomplete");

        }
    }
}
