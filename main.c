/*
 * ATARI 2600 EMULATOR - BARE METAL PS1
 * Crediti: DraxTube (https://github.com/DraxTube)
 * Canale YT: https://www.youtube.com/@DraxTube01
 */

// Indirizzi hardware PS1
#define GPU_STAT (*(volatile unsigned int*)0x1F801814)
#define GPU_DATA (*(volatile unsigned int*)0x1F801810)

void gpu_send_command(unsigned int cmd) {
    while (!(GPU_STAT & (1 << 26))); // Attendi che la GPU sia pronta
    GPU_DATA = cmd;
}

void init_video() {
    gpu_send_command(0x00000000); // Reset GPU
    gpu_send_command(0x03000000); // Display enable
}

// Funzione per disegnare un pixel (molto semplificata per l'Atari)
void draw_test_pixel(int x, int y, unsigned char r, unsigned char g, unsigned char b) {
    unsigned int color = (b << 16) | (g << 8) | r;
    gpu_send_command(0x20000000 | color); // Comando Fill (Semplificato)
}

int main() {
    init_video();
    
    // Loop Infinito
    while(1) {
        // Qui girerà il core del tuo emulatore Atari
        // Per ora facciamo lampeggiare lo schermo per testare la Action
        for(int i=0; i<100000; i++) __asm__("nop");
        gpu_send_command(0x02000000 | 0x00FF0000); // Pulisci lo schermo con Blu
    }
    
    return 0;
}
