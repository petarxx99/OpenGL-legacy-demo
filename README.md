tic tac toe with legacy OpenGL

When I am on Linux, I compile and link opengl/glfw projects like this: <br>

gcc source_files_and_header_files -lGL -lglfw  <br>

When I am on windows, I compile and link them by writing: <br>
gcc source_files_and_header_files libglfw3.a -lopengl32 -lgdi32 <br>

and I put libglfw3.a file in the same directory where main.c is. <br>
I have read people say that they couldn't link properly before writing -lopengl32 -lgdi32 -luser32 -lkernel32 -lws2_32. <br>
<b>If you are on Windows, make sure that you write #include"glfw3.h" instead of #include<GLFW/glfw3.h>  </b>

Another thing which may be worth mentioning is that I couldn't link glfw libraries when I downloaded 32bit glfw binaries. When I downloaded 64bit glfw binaries everything worked fine. I have a 64 bit machine and a x86_64-w64-mingw32. I have read comments from people with the opposite experience, where they weren't able to link glfw libraries when they downloaded 64bit binaries, but they were able to link them after downloading 32bit binaries. 

If you have followed these instructions and you are on Windows, then write: <br>
#include"glfw3.h" <br> <br>

If you are on Linux then write: <br>
#include<GLFW/glfw3.h> <br>

