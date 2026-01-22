#include <stdio.h>
#include <string.h>
#include <vitasdk.h>

/* Crediti richiesti */
// Sviluppato da DraxTube
// GitHub: https://github.com/DraxTube
// YouTube: https://www.youtube.com/@DraxTube01

int main(int argc, char *argv[]) {
    // Inizializza la grafica base per vedere qualcosa a schermo
    sceSysmoduleLoadModule(SCE_SYSMODULE_NET);
    
    // Inizializzazione Rete
    SceNetInitParam netInitParam;
    int size = 1 * 1024 * 1024; // 1MB di memoria per la rete
    netInitParam.memory = malloc(size);
    netInitParam.size = size;
    netInitParam.flags = 0;
    sceNetInit(&netInitParam);
    sceNetCtlInit();

    // Setup debug screen
    psvDebugScreenInit();
    psvDebugScreenPrintf("IPTV Vita by DraxTube\n");
    psvDebugScreenPrintf("Canale YouTube: @DraxTube01\n");
    psvDebugScreenPrintf("----------------------------\n");
    psvDebugScreenPrintf("Caricamento lista canali...\n");

    // QUI andrà la logica per leggere il file M3U che hai postato
    // Per ora teniamo il loop infinito per non far crashare l'app
    while (1) {
        sceKernelDelayThread(1000000);
    }

    // Pulizia (teorica, non ci arriva mai per ora)
    sceNetCtlTerm();
    sceNetTerm();
    free(netInitParam.memory);
    return 0;
}
