tic tac toe with legacy OpenGL

When I am on Linux, I compile opengl/glfw projects like this:

gcc main.c -lGL -lglfw

When I am on windows, I compile them by writing:
gcc main.c libglfw3.a -lopengl32 -lgdi32

and I put libglfw3.a file in the same directory where main.c is. I have read people say that they couldn't link properly before writing -lopengl32 -lgdi32 -luser32 -lkernel32 -lws2_32. Another thing which may be worth mentioning is that I couldn't link glfw libraries when I downloaded 32bit glfw binaries. When I downloaded 64bit glfw binaries everything worked fine. I have a 64 bit machine and a x86_64-w64-mingw32. I have read comments from people with the opposite experience, where they weren't able to link glfw libraries when they downloaded 64bit binaries, but they were able to link them after downloading 32bit binaries. 

If you have followed these instructions and you are on Windows, then write:
#include<stdio.h>
#include"glfw3.h"
#include<math.h>

If you are on Linux then write:
#include<stdio.h>
#include<GLFW/glfw3.h>
#include<math.h>

