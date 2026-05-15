# Iwanna C Final Project

A small SDL2 platform game written in C for a final course project. The player
clears six levels by moving, jumping, avoiding spikes, and reaching the yellow
destination block.

## Gameplay

- `A` / `D`: move left and right
- `Space`: jump
- `Esc`: return from a level to the main menu
- White blocks are spikes and reset the player
- Brown blocks are obstacles
- Green blocks are ground
- Yellow blocks are level destinations

## Project Layout

```text
Iwanna/
  *.c, *.h       game source code
  maps/          six level definition files
  assets/Font/   place a local TTF font here as arial.ttf before running
```

The original hand-in document, generated binaries, object files, vendored SDL
SDK files, and font files are intentionally not included in the repository.

## Dependencies

- C compiler, such as GCC or MinGW-w64
- SDL2
- SDL2_ttf
- A local TrueType font copied to `Iwanna/assets/Font/arial.ttf`

On MSYS2/MinGW64, one typical setup is:

```sh
pacman -S mingw-w64-x86_64-gcc mingw-w64-x86_64-SDL2 mingw-w64-x86_64-SDL2_ttf pkgconf
```

## Build

From the project root:

```sh
cd Iwanna
make
./Iwanna
```

On Windows, run `Iwanna.exe` from inside the `Iwanna` directory so the relative
`maps/` and `assets/Font/` paths resolve correctly.

## Changelog

- v1.01: split initialization logic out of `main`.
- v1.0: implemented the menu, movement/jumping, collision handling, and level
  switching.

## License

This project is released under the MIT License. Third-party dependencies and
fonts are not redistributed here and remain under their own licenses.

