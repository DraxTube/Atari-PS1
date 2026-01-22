#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vitasdk.h>

/* * PROGRAMMA: IPTV Vita
 * CREDITI: DraxTube 
 * GitHub: https://github.com/DraxTube 
 * YouTube: https://www.youtube.com/@DraxTube01 
 */

int main(int argc, char *argv[]) {
    sceSysmoduleLoadModule(SCE_SYSMODULE_NET);
    
    psvDebugScreenInit();
    psvDebugScreenPrintf("========================================\n");
    psvDebugScreenPrintf("          IPTV VITA - DRAXTUBE          \n");
    psvDebugScreenPrintf("========================================\n");
    psvDebugScreenPrintf("GitHub: DraxTube\n");
    psvDebugScreenPrintf("YouTube: @DraxTube01\n\n");
    
    psvDebugScreenPrintf("Build completata con successo!\n");
    psvDebugScreenPrintf("Premi il tasto HOME per uscire.\n");

    while (1) {
        sceKernelDelayThread(1000000);
    }

    return 0;
}
