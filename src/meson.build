src = files(
	'main.c',
	'emulated.c',
	'emulation.c',
	'interaction/sdl/input.c',
)

executable('tracua-chip8',
	src,
	dependencies : [sdl2_dep],
	install : false,
	include_directories: [
		'../include'
	],
)