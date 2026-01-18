/*
 * ATARI 2600 EMULATOR FOR PS1
 * Sviluppato per: DraxTube
 * GitHub: https://github.com/DraxTube
 * YouTube: https://www.youtube.com/@DraxTube01
 */

#include <sys/types.h>
#include <stdio.h>
#include <libgte.h>
#include <libgpu.h>
#include <libetc.h>

// --- CONFIGURAZIONE SISTEMA ---
DISPENV disp[2];
DRAWENV draw[2];
int db = 0; // Double buffer index

// --- EMULAZIONE ATARI 2600 ---
// Memoria Atari: 128 byte RAM + 4KB ROM
unsigned char ram[128];
unsigned char rom[4096]; 
unsigned short pc = 0xF000; // Program Counter
unsigned char a = 0, x = 0, y = 0, sp = 0xFF; // Registri

// Inizializza la grafica PS1 (320x240)
void init_ps1_video() {
    ResetGraph(0);
    SetDefDispEnv(&disp[0], 0, 0, 320, 240);
    SetDefDispEnv(&disp[1], 0, 240, 320, 240);
    SetDefDrawEnv(&draw[0], 0, 240, 320, 240);
    SetDefDrawEnv(&draw[1], 0, 0, 320, 240);
    
    draw[0].isbg = 1; draw[1].isbg = 1;
    setRGB0(&draw[0], 0, 0, 0); // Sfondo nero
    setRGB0(&draw[1], 0, 0, 0);
    
    PutDispEnv(&disp[0]);
    PutDrawEnv(&draw[0]);
    SetDispMask(1);
    
    // Carica Font di base
    FntLoad(960, 256);
    FntOpen(16, 16, 280, 200, 0, 512);
}

// Funzione per scambiare i buffer video
void display() {
    db = !db;
    PutDispEnv(&disp[db]);
    PutDrawEnv(&draw[db]);
    // Attendi VSync (per non andare troppo veloce rispetto all'Atari)
    VSync(0); 
}

// --- CORE CPU 6502 (Semplificato per demo) ---
void cpu_step() {
    // Simuliamo un'istruzione NOP per ora
    pc++;
}

// --- RENDERER EMULATORE ---
// Disegna lo stato dell'emulatore sulla PS1
void render_emulator_screen() {
    // Qui disegneremmo il framebuffer Atari.
    // Per ora mostriamo i dati di debug e i crediti.
    FntPrint("\n  ATARI 2600 EMULATOR - PS1\n");
    FntPrint("  -------------------------\n");
    FntPrint("  DEV: DraxTube\n");
    FntPrint("  YT:  @DraxTube01\n");
    FntPrint("  GITHUB: github.com/DraxTube\n\n");
    
    FntPrint("  CPU STATE:\n");
    FntPrint("  PC: %04X  A: %02X  X: %02X\n", pc, a, x);
    FntPrint("  STATUS: RUNNING\n");
    
    FntFlush(-1);
}

int main() {
    init_ps1_video();

    // Loop Principale
    while(1) {
        // 1. Esegui istruzioni CPU Atari
        cpu_step();
        
        // 2. Disegna la scena
        render_emulator_screen();
        
        // 3. Aggiorna schermo
        display();
    }
    return 0;
}
