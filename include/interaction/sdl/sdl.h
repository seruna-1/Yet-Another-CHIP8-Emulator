#include <stdbool.h>

#include <SDL2/SDL.h>

#include "chip8.h"
#include "emulator_configuration.h"

typedef struct {
  SDL_Window *window;
  SDL_Renderer *renderer;
  SDL_AudioSpec want, have;
  SDL_AudioDeviceID dev;
} sdl_t;

void sdl_cleanup(const sdl_t sdl);
void update_timers(const sdl_t *sdl, chip8_t *chip8);
void clear_screen(const sdl_t sdl, const config_t config);
void audio_callback(void *userdata, uint8_t *stream, int len);
bool init_sdl(sdl_t *sdl, config_t *config);