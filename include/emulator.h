typedef enum {
  CHIP8,
  SUPERCHIP,
  XOCHIP,
} extension_t;

typedef struct {
  uint32_t window_width;
  uint32_t window_height;
  uint32_t fg_color;
  uint32_t bg_color;
  uint32_t scale_factor;
  bool pixel_outlines;
  uint32_t insts_per_second;
  uint32_t square_wave_freq;
  uint32_t audio_sample_rate;
  int16_t volume;
  float color_lerp_rate;
  extension_t current_extension;
} config_t;
