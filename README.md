# tiny-rpg

![Static Badge](https://img.shields.io/badge/Built_with-C-white)
![Static Badge](https://img.shields.io/badge/License-LGPLv2-blue)

*tiny-rpg* is a tiny real-time singleplayer RPG with a clear emphasis on being small. The game world is small, the window is small, the codebase is small\* and in C. The amount of dependencies is small, so on and so forth.

## Dependencies

- [Raylib](https://github.com/raysan5/raylib) <!-- very nice game dev framework -->
- [microui](https://github.com/rxi/microui)   <!-- geez this rxi lad is carrying my game -->

Raylib is honestly one of the best libraries for introductory game development in recent history. All you need are some headers and a library, that's it. It just works and the cheatsheet provided on [the website](https://raylib.com) is massively helpful.

Microui is cool, it's a bit hard to wrangle and make work but once you do, it's magic. All you need is a backend (like Raylib) and a `libc` and you can have a UI anywhere, it's also header/impl only so that removes a very nice linker step.


## Building

CMake is the buildsystem of choice here, there's only one argument you can pass to it.

> `-DCMAKE_BUILD_TYPE= Release / Debug`

That determines what flags are placed into the build. From there you can use Ninja, Make, Meson, even plain Visual Studio if you wanna. I prefer Ninja for lightning fast iteration.
