unsigned short * const VideoMemory = (unsigned short* const)0xb8000;

void clear() { // 80 cols x 25 rows x 2 bytes
    int pos = 0;
    for (int col = 0; col < 80; col += 1) {
        for (int row = 0; row < 25; row += 1) {
            VideoMemory[pos++] = (0x0A00 | ' ');
        }
    }
}

void printf(const char* str) {
    for (int i = 0; str[i] != '\0'; i += 1) {
        VideoMemory[i] = (VideoMemory[i] & 0xFF00) | str[i];
    }
}

using constructor = void (*)();
extern "C" constructor start_ctors;
extern "C" constructor end_ctors;
extern "C" void callConstructors() {
    for (constructor* p = &start_ctors; p != &end_ctors; p++) {
        (*p)();
    }
}

extern "C" void kernelMain(void* multiboot_structure, unsigned int magicnumber) {
    clear();
    printf("Hello, World!");
    while(true); // spin
}
