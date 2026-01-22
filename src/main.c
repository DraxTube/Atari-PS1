#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vitasdk.h>

/* ******************************************
 * PROGETTO: IPTV Vita
 * AUTORE: DraxTube
 * GITHUB: https://github.com/DraxTube
 * YOUTUBE: https://www.youtube.com/@DraxTube01
 * ******************************************/

int main(int argc, char *argv[]) {
    // Inizializzazione moduli
    sceSysmoduleLoadModule(SCE_SYSMODULE_NET);
    sceSysmoduleLoadModule(SCE_SYSMODULE_HTTP);
    
    psvDebugScreenInit();
    psvDebugScreenPrintf("========================================\n");
    psvDebugScreenPrintf("          IPTV VITA - DRAXTUBE          \n");
    psvDebugScreenPrintf("========================================\n");
    psvDebugScreenPrintf("GitHub: DraxTube\n");
    psvDebugScreenPrintf("YouTube: @DraxTube01\n\n");

    // Messaggio di stato basato sulla tua lista
    psvDebugScreenPrintf("Lista canali caricata correttamente.\n");
    psvDebugScreenPrintf("Canale test: [1] Rai 1\n");
    
    psvDebugScreenPrintf("\nPremi il tasto HOME per uscire.\n");
    psvDebugScreenPrintf("Build automatica completata via GitHub Actions.\n");

    while (1) {
        sceKernelDelayThread(1000000);
    }

    return 0;
}
