#include"header.h"
#include<GLFW/glfw3.h>
#include<math.h>


void crtajIviceKvadrata(double duzinaIvice, double duzinaStrane, double crvena, double
zelena, double plava){
    
    glColor3f(crvena, zelena, plava);
    glBegin(GL_POLYGON);
        glVertex2f(-1 + duzinaStrane, 1);
        glVertex2f(-1 + duzinaStrane + duzinaIvice, 1);
        glVertex2f(-1 + duzinaStrane + duzinaIvice, -1);
        glVertex2f(-1 + duzinaStrane, -1);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f(1 - duzinaStrane - duzinaIvice, 1);
        glVertex2f(1 - duzinaStrane, 1);
        glVertex2f(1 - duzinaStrane, -1);
        glVertex2f(1 - duzinaStrane - duzinaIvice, -1);
    glEnd();


    glBegin(GL_POLYGON);
        glVertex2f(1, -1 + duzinaStrane);
        glVertex2f(1, -1 + duzinaStrane + duzinaIvice);
        glVertex2f(-1,-1 + duzinaStrane + duzinaIvice);
        glVertex2f(-1, -1 + duzinaStrane);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f(1, 1 - duzinaStrane);
        glVertex2f(1, 1 - duzinaStrane - duzinaIvice);
        glVertex2f(-1,1 - duzinaStrane - duzinaIvice);
        glVertex2f(-1, 1 - duzinaStrane);
    glEnd();

    glFlush();


}


void obojiPozadinu(double crvena, double zelena, double plava){
    glColor3f(crvena, zelena, plava);
    glBegin(GL_POLYGON);
        glVertex2f(-1, -1);
        glVertex2f(-1, 1);
        glVertex2f(1, 1);
        glVertex2f(1, -1);
    glEnd();
    glFlush();
}


void crtajX(struct GlavniStruct *glavniStruct, int i, int j, double debljina){
         /*   double x = DUZINA_TABLE * (double)j / 3 - 1;
            double y = 1 - DUZINA_TABLE * (double)i / 3;  */

            double x = -1 + j*(glavniStruct->duzinaStrane + glavniStruct->duzinaIvice);
            double y = 1 - i * (glavniStruct->duzinaStrane + glavniStruct->duzinaIvice);   /* trazim gornju levu ivicu kvadrata. y raste na dole kad je float/double. */
 
            glColor3f(0.3, 1, 0.7);
            const double stranaKvadrata = glavniStruct->duzinaStrane; /* Malo manje od 2/3 */
            glBegin(GL_POLYGON);
                 glVertex2f(x, y);
                 glVertex2f(x + debljina, y);
                 glVertex2f(x + stranaKvadrata, y - stranaKvadrata);
                 glVertex2f(x + stranaKvadrata - debljina, y - stranaKvadrata);
            glEnd();

            glBegin(GL_POLYGON);
                glVertex2f(x, y - stranaKvadrata);
                glVertex2f(x + debljina, y - stranaKvadrata);
                glVertex2f(x + stranaKvadrata, y);
                glVertex2f(x + stranaKvadrata - debljina, y);
            glEnd();
            glFlush();
}


void crtajO(struct GlavniStruct *glavniStruct, int i, int j, double
debljina, double tangenta, double duzinaDijagonale, double
ugaoDijagonale){
            
            const double VRH_TABLE = 1;

            double x = -1 + j*(glavniStruct->duzinaStrane + glavniStruct->duzinaIvice);   /* -1 da
promenim raspon sa 0 do 2 na -1 do +1. */
            double y = VRH_TABLE - i * (glavniStruct->duzinaStrane + glavniStruct->duzinaIvice);

            

             double centarX = x + glavniStruct->duzinaStrane / 2;   /* Mreza ima 3 kvadrata po
redu/koloni, svaki kvadrat je 0.67 duzine. Centar je u 0.67/ 2 */
             double centarY = y - glavniStruct->duzinaStrane / 2;   /* y raste na gore, pada
na dole. x i y cuvaju koordinate gornjeg levog vrha kvadrata. */


            glColor3f(0.8, 0.6, 0.3);
            const double poluprecnik = glavniStruct->duzinaStrane /2 - debljina;  /* Kvadrat u
mrezi je 2/3, poluprecnik je duplo manji */
            for(double ugao=0; ugao<2*PI; ugao+=0.01){
             
                double deltaX = cos(ugao) * poluprecnik;
                double deltaY = sin(ugao) * poluprecnik;

                double xTacke = centarX + deltaX;
                double yTacke = centarY + deltaY;

/*Crtam pravougaonik, 1. tacka na kruznici, 2. tacka na istoj pravoj
kao r, 3. tacka na tangenti, 4. poslednja tacka pravougaonika. */
                glBegin(GL_POLYGON);
                    glVertex2f(xTacke, yTacke);
                    glVertex2f(xTacke + debljina * cos(ugao), yTacke + debljina * sin(ugao));/* Tacka na istoj pravoj kao poluprecnik.*/
                    glVertex2f(xTacke + tangenta * cos(ugao+PI/2), yTacke + tangenta * sin(ugao + PI / 2));
                    glVertex2f(xTacke + duzinaDijagonale * cos(ugao +
ugaoDijagonale), yTacke + duzinaDijagonale * sin(ugao + ugaoDijagonale));
                glEnd();
                glFlush();
            }

}




