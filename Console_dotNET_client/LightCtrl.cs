using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.InteropServices;
using static Console_dotNET_client.LightCtrl;


namespace Console_dotNET_client
{
    internal class LightCtrl
    {
        public enum RGB_Strip
        {
            FRONT,
            BACK
        };

        #region dllImports
        // FpLighting c++ DLL here - needs a project reference to this dll in C# project also
        private const string _dllImportPath = @"FpLtg.dll";

        // External C++ Functions 
        [DllImport(_dllImportPath, CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr FpLtg_Instantiate(RGB_Strip strip);

        [DllImport(_dllImportPath, CallingConvention = CallingConvention.Cdecl)]
        public static extern void FpLtg_setRGB(IntPtr p, byte red, byte green, byte blue);

        [DllImport(_dllImportPath, CallingConvention = CallingConvention.Cdecl)]
        public static extern void FpLtg_getRGB(IntPtr p, ref byte red, ref byte green, ref byte blue);

        [DllImport(_dllImportPath, CallingConvention = CallingConvention.Cdecl)]
        public static extern void FpLtg_setBlink(IntPtr p, bool blink);

        [DllImport(_dllImportPath, CallingConvention = CallingConvention.Cdecl)]
        public static extern bool FpLtg_getBlink(IntPtr p);

        [DllImport(_dllImportPath, CallingConvention = CallingConvention.Cdecl)]
        public static extern void FpLtg_setBrightness(IntPtr p, byte brightness);

        [DllImport(_dllImportPath, CallingConvention = CallingConvention.Cdecl)]
        public static extern byte FpLtg_getBrightness(IntPtr p);

        [DllImport(_dllImportPath, CallingConvention = CallingConvention.Cdecl)]
        public static extern void FpLtg_setBlinkRate(IntPtr p, byte rate);

        [DllImport(_dllImportPath, CallingConvention = CallingConvention.Cdecl)]
        public static extern byte FpLtg_getBlinkRate(IntPtr p);

        [DllImport(_dllImportPath, CallingConvention = CallingConvention.Cdecl)]
        public static extern void FpLtg_setDutyCycle(IntPtr p, byte dutycycle);

        [DllImport(_dllImportPath, CallingConvention = CallingConvention.Cdecl)]
        public static extern byte FpLtg_getDutyCycle(IntPtr p);

        #endregion
    }
}

