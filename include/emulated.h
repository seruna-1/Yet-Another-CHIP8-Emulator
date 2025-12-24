#pragma once

#include <stdint.h>

#define STACK_SIZE 12

typedef enum {
  QUIT,
  RUNNING,
  PAUSE,
} emulator_state_t;

typedef struct {
  uint16_t opcode; // 1º half-byte
  uint16_t NNN; // 2º, 3º and 4º half-byte (12-bit memory address)
  uint8_t NN; // 3º and 4º half-byte (8-bit number)
  uint8_t N; // 4º half-byte
  uint8_t X; // 2º half-byte
  uint8_t Y; // 3º half-byte
} instruction_t;

typedef struct {
  emulator_state_t state;
  uint8_t ram[4096]; // 4 kilobytes of fully writable RAM
  bool display[64*32]; // 64x32 pixels, eachc can be on or off (boolean)
  uint32_t pixel_color[64*32];
  uint16_t stack[STACK_SIZE]; // stores 16-bit adresses, used for function call and return
  uint16_t *stack_ptr;
  uint8_t V[16]; // general-purpose registers
  uint16_t I; // points at some location in memory
  uint16_t PC; // points at the current instruction in memory
  uint8_t delay_timer; // decrements at the rate of 60hz (60 times per second until reaches 0)
  uint8_t sound_timer; // like the delay_timer
  bool keypad[16];
  const char *rom_name;
  instruction_t inst;
  bool draw;
} chip8_t;

bool init_chip8(chip8_t *chip8, const config_t config, const char rom_name[]);
bool save_estado_chip(const chip8_t *chip8, const char *filename);
bool carregar_estado_chip(chip8_t *chip8, const char *filename);
bool set_config_from_args(config_t* config, const int argc, char** argv);
void clear_screen(const sdl_t sdl, const config_t config);
void final_cleanup(const sdl_t sdl);
void update_screen(const sdl_t *sdl, const config_t *config, chip8_t *chip8);
void update_timers(const sdl_t *sdl, chip8_t *chip8);
void process_frame(chip8_t *chip8, config_t *config, sdl_t *sdl);