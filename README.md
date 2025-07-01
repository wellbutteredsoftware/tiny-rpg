# tiny-rpg

![Static Badge](https://img.shields.io/badge/Built_with-C-white)
![Static Badge](https://img.shields.io/badge/License-LGPLv2-blue)

*tiny-rpg* is a fun turn-based RPG with a clear emphasis on being small. The game world is small, the window is small, the codebase is small\* and in C. The amount of dependencies is small, so on and so forth.

## Dependencies

- [Raylib](https://github.com/raysan5/raylib) <!-- very nice game dev framework -->
- [miniz](https://github.com/richgel999/miniz) <!-- we love zip compression -->
- [microui](https://github.com/rxi/microui)   <!-- geez this rxi lad is carrying my game -->

Each dependency here is carefully chosen for a large amount of factors. Those boiling down to portability and general ease of use or implementation. Raylib was the best choice since it offers everything I could want for this project in a single monolithic library. Microtar was chosen since it's a simple `header/impl` file combo that allows me to use the efficient `tar` compression scheme for game assets and save data without needing to build my own tooling, very awesome. Microui was chosen for a similar reason, it's small, `header/impl` and it doesn't need much glue between it and Raylib to make UI happen.

## Building

### Linux
<!-- todo: deal with -->

### MacOS
* Install homebrew
* `brew install make`
* `brew install raylib`
* `make mac`

### Windows
* Install w64devkit - add it to PATH
* Download Raylib, install - modify vars in Makefile
* `make win`
