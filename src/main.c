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
    // Caricamento moduli di rete
    sceSysmoduleLoadModule(SCE_SYSMODULE_NET);
    
    // Inizializzazione schermo di debug
    psvDebugScreenInit();
    psvDebugScreenPrintf("========================================\n");
    psvDebugScreenPrintf("          IPTV VITA - DRAXTUBE          \n");
    psvDebugScreenPrintf("========================================\n");
    psvDebugScreenPrintf("GitHub: github.com/DraxTube\n");
    psvDebugScreenPrintf("YouTube: @DraxTube01\n\n");
    
    // Inizializzazione Rete
    SceNetInitParam netInitParam;
    int size = 1 * 1024 * 1024; 
    netInitParam.memory = malloc(size);
    netInitParam.size = size;
    netInitParam.flags = 0;
    
    if (sceNetInit(&netInitParam) < 0) {
        psvDebugScreenPrintf("Errore inizializzazione rete!\n");
    } else {
        sceNetCtlInit();
        psvDebugScreenPrintf("Rete pronta. In attesa di caricare la lista...\n");
    }

    psvDebugScreenPrintf("\nPremi il tasto HOME per uscire.\n");

    // Loop principale
    while (1) {
        sceKernelDelayThread(1000000);
    }

    // Pulizia finale (mai raggiunta in questo loop)
    sceNetCtlTerm();
    sceNetTerm();
    free(netInitParam.memory);
    return 0;
}
