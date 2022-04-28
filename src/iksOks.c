#include<stdio.h>
#include<GLFW/glfw3.h>
#include"header.h"




void mouseButtonCallback(GLFWwindow *window, int button, int action,
int mods){
     struct GlavniStruct *glavniStruct = (struct GlavniStruct*)
glfwGetWindowUserPointer(window);


     if (action != GLFW_PRESS){
         return;
     }

      if (button == GLFW_MOUSE_BUTTON_RIGHT) {
        return;
    }


    double absX, absY;
    glfwGetCursorPos(window, &absX, &absY);

    int kolona =(int) (3 * absX / glavniStruct->windowDuzina);
    int red = (int) (3 * absY / glavniStruct->windowVisina);


    if(glavniStruct->kvadrati[red][kolona] == PRAZNO_POLJE  &&
glavniStruct->partijaGotova == PARTIJA_TRAJE){

         glavniStruct->kvadrati[red][kolona] =
(glavniStruct->koJeNaPotezu == POTEZ_X) ? POLJE_X : POLJE_O;
         glavniStruct->koJeNaPotezu = (glavniStruct->koJeNaPotezu ==
POTEZ_X) ? POTEZ_O : POTEZ_X;

         daLiJePartijaGotova(glavniStruct);

         printf("Stanje partije posle poteza: ");
         printStanjePartije(glavniStruct);
    }
}




int main(int argc, char** argv){

  const double duzinaIvice = 0.1;
  const double duzinaStrane = (DUZINA_TABLE - 2 * duzinaIvice) / 3; 

  struct GlavniStruct glavniStruct = {500, 500, duzinaIvice, duzinaStrane, true, POTEZ_X, {{0, 0,
0}, {0, 0, 0}, {0, 0, 0}}, false};
  
  

  if(!glfwInit()) return -1;

  GLFWwindow* window = glfwCreateWindow(500, 500, "Ovo je titl.", NULL, NULL);
  if (!window) {
      glfwTerminate();
      return -1;
  }

  glfwMakeContextCurrent(window);
  glfwSetWindowUserPointer(window, (void*) &glavniStruct);
  glfwSwapInterval(1);
  glfwSetMouseButtonCallback(window, mouseButtonCallback);

  while(!glfwWindowShouldClose(window)){
      glClear(GL_COLOR_BUFFER_BIT);
      obojiPozadinu(0.3, 0.3, 0.9);
      crtajIviceKvadrata(glavniStruct.duzinaIvice, duzinaStrane, 0.9, 0.9, 0.9);

      crtajUKvadrate(&glavniStruct);

      glfwSwapBuffers(window);

      glfwWaitEvents();

  }

  glfwDestroyWindow(window);
  glfwTerminate();

  return 0;
}




