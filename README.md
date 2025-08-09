# snake
A simple re-implementation of the classic snake game, made for educational purposes. It is written in C (C23 standard), and uses the SDL for window creation, input handling, and rendering.

## Building & Running
This project was developed on Linux, and it uses GNU Make as its build system. Because it relies on SDL (specifically version 3), be sure to have the proper shared objects/DLLs installed where the linker can locate them. If using Arch Linux, installing the `sdl3` package from the `extra` repository should suffice.
```
$ git clone https://github.com/ashmerit/snake.git
$ cd snake
$ make run
```

## Screenshots
![Screenshot 1](https://github.com/ashmerit/snake/blob/main/screenshots/1.png)
