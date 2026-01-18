/*
 * Progetto: Atari 2600 Emulator for PS1
 * Sviluppatore: DraxTube
 * GitHub: https://github.com/DraxTube
 * YouTube: https://www.youtube.com/@DraxTube01
 */

#include <psxetc.h>
#include <psxgpu.h>
#include <psxpad.h>
#include <stdint.h>

// Memoria Atari 2600
uint8_t ram[128];
uint8_t rom[4096]; // Carica qui la tua ROM
uint16_t pc = 0xF000; // Entry point tipico
uint8_t a, x, y, sp, status;

// Funzione per eseguire un'istruzione 6502 (Esempio base)
void step_6502() {
    uint8_t opcode = rom[pc++ & 0xFFF];
    switch(opcode) {
        case 0xA9: // LDA Immediate
            a = rom[pc++ & 0xFFF];
            status = (a == 0) ? 0x02 : 0x00; // Update Zero Flag
            break;
        case 0x8D: // STA Absolute (Spesso usato per il TIA/Video)
            uint16_t addr = rom[pc++];
            addr |= (rom[pc++] << 8);
            if (addr < 0x80) {
                // Scrittura nei registri TIA (Rendering)
                handle_tia_update(addr, a);
            } else {
                ram[addr & 0x7F] = a;
            }
            break;
        // Aggiungi qui gli altri opcode...
    }
}

void handle_tia_update(uint16_t reg, uint8_t val) {
    // Qui implementerai la logica "Racing the beam"
    // Per ora, visualizziamo un colore di debug sulla PS1
}

int main() {
    // Inizializzazione Hardware PS1
    PSX_Init();
    InitHeap((unsigned long *)0x80010000, 0x10000);
    
    // Mostra crediti a video (Placeholder)
    printf("DraxTube Atari Emulator loading...\n");
    printf("GitHub: https://github.com/DraxTube\n");

    while(1) {
        step_6502(); // Esegue l'emulazione
        
        // Sincronizzazione video PS1
        VSync(0);
    }
    return 0;
}
