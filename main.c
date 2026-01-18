/*
 * PROJECT: Atari 2600 Emulator for PlayStation 1
 * CREDITS: DraxTube
 * GITHUB: https://github.com/DraxTube
 * YOUTUBE: https://www.youtube.com/@DraxTube01
 */

// --- INDIRIZZI HARDWARE PS1 ---
#define GPU_STAT (*(volatile unsigned int*)0x1F801814)
#define GPU_DATA (*(volatile unsigned int*)0x1F801810)

// --- MEMORIA ATARI 2600 ---
unsigned char ram[128];         // 128 bytes di RAM (6532 RIOT)
unsigned char rom[4096];        // 4KB di ROM
unsigned char registers[64];    // Registri TIA (Video)

// --- REGISTRI CPU 6502 ---
unsigned short pc = 0xF000;     // Program Counter
unsigned char a = 0, x = 0, y = 0, sp = 0xFD, status = 0x20;

// --- FUNZIONI GPU PS1 ---
void gpu_wait() { while (!(GPU_STAT & (1 << 26))); }
void gpu_cmd(unsigned int cmd) { gpu_wait(); GPU_DATA = cmd; }

void init_ps1() {
    gpu_cmd(0x00000000); // Reset GPU
    gpu_cmd(0x03000000); // Display Enable
    gpu_cmd(0x01000000); // Reset VRAM
}

// Disegna un rettangolo (usato per i pixel giganti dell'Atari)
void draw_rect(int x, int y, int w, int h, unsigned char r, unsigned char g, unsigned char b) {
    unsigned int color = (b << 16) | (g << 8) | r;
    gpu_cmd(0x60000000 | color); // Comando: Fill Rectangle
    gpu_cmd((y << 16) | (x & 0xFFFF));
    gpu_cmd((h << 16) | (w & 0xFFFF));
}

// --- CORE EMULAZIONE ---
void step_6502() {
    unsigned char opcode = rom[pc++ & 0x0FFF];
    
    switch(opcode) {
        case 0xA9: // LDA Immediate
            a = rom[pc++ & 0x0FFF];
            status = (a == 0) ? (status | 0x02) : (status & ~0x02);
            break;
        case 0x85: // STA Zero Page
            unsigned char addr = rom[pc++ & 0x0FFF];
            if(addr < 0x80) registers[addr] = a; // Scrittura nel TIA
            else ram[addr - 0x80] = a;           // Scrittura in RAM
            break;
        case 0x4C: // JMP Absolute
            unsigned short low = rom[pc++ & 0x0FFF];
            unsigned short high = rom[pc++ & 0x0FFF];
            pc = (high << 8) | low;
            break;
        default:
            // Istruzione non supportata (per ora)
            break;
    }
}

int main() {
    init_ps1();
    
    // Inizializzazione fittizia della ROM (per test)
    // LDA #$0F, STA $80 (RAM), JMP $F000
    rom[0x000] = 0xA9; rom[0x001] = 0x0F;
    rom[0x002] = 0x85; rom[0x003] = 0x80;
    rom[0x004] = 0x4C; rom[0x005] = 0x00; rom[0x006] = 0xF0;

    while(1) {
        // 1. Eseguiamo un ciclo di istruzioni
        for(int i = 0; i < 100; i++) {
            step_6502();
        }

        // 2. Rendering grafico dell'Atari (Playfield)
        // Disegniamo una riga di test per confermare che l'emulatore "vive"
        draw_rect(0, 0, 320, 240, 0, 0, 0); // Pulisci schermo
        draw_rect(20, 20, 280, 20, 0, 255, 0); // Barra verde (DraxTube Engine)
        
        // Attesa per il VSync per non bruciare la CPU
        for(int delay = 0; delay < 50000; delay++) __asm__("nop");
    }
    
    return 0;
}
