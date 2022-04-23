#include"header.h"
#include<stdio.h>
#include<math.h>




void printStanjePartije(struct GlavniStruct *glavniStruct){

    if (glavniStruct->partijaGotova > 0) {
        printf("Partija je gotova! \n");
    }

    switch (glavniStruct->partijaGotova){

        case PARTIJA_TRAJE: {
            printf("Partija jos uvek traje.\n");
            break;
        }

        case POBEDA_X: {
            printf("X je pobedio! \n");
            break;
        }

        case POBEDA_O: {
            printf("O je pobedio! \n");
            break;
        }

        case NERESENO: {
            printf("Partija je zavrsena nereseno! \n");
            break;
        }
        default: {
            printf("Nesto nepredvidjeno se desilo. \n");
        }
    }
}






void crtajUKvadrate(struct GlavniStruct* glavniStruct){
    double debljina = 0.06;
    double tangenta = debljina;
    double ugaoDijagonale = atan(tangenta / debljina);  /*Govorim o
dijagonali pravougaonika cije su strane tangenta i debljina.*/
    double duzinaDijagonale = sqrt(tangenta * tangenta + debljina * debljina);

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if (glavniStruct->kvadrati[i][j] == 1){
                crtajO(glavniStruct, i, j, debljina, tangenta,
duzinaDijagonale, ugaoDijagonale);
            } else if (glavniStruct->kvadrati[i][j] == 2){
                crtajX(glavniStruct, i, j, debljina);
            }

        }
    }
}



void daLiJePartijaGotova(struct GlavniStruct *glavniStruct){
  unsigned char svaPoljaPopunjena = true;

  char x3DijagonalaGoreLevo = true;
  char x3DijagonalaDoleLevo = true;

  char o3DijagonalaGoreLevo = true;
  char o3DijagonalaDoleLevo = true;

   for(int i=0; i<3; i++){
       char x3Horizontalno = true;
       char o3Horizontalno = true;

       char x3Vertikalno = true;
       char o3Vertikalno = true;


       for(int j=0; j<3; j++){
           if(glavniStruct->kvadrati[i][j] == PRAZNO_POLJE){
               svaPoljaPopunjena = false;
           }

           if (glavniStruct->kvadrati[i][j] != POLJE_X){
               x3Horizontalno = false;
           }

            if (glavniStruct->kvadrati[i][j] != POLJE_O){
               o3Horizontalno = false;
           }

           if (glavniStruct->kvadrati[j][i] != POLJE_X){
               x3Vertikalno = false;
           }

           if (glavniStruct->kvadrati[j][i] != POLJE_O){
               o3Vertikalno = false;
           }

       }

       if(x3Horizontalno || x3Vertikalno) {
              glavniStruct->partijaGotova = POBEDA_X;
       }

       if (o3Horizontalno || o3Vertikalno){
              glavniStruct->partijaGotova = POBEDA_O;
       }



      if (glavniStruct->kvadrati[i][i] != POLJE_X){
          x3DijagonalaGoreLevo = false;
      }
      if (glavniStruct->kvadrati[i][2-i] != POLJE_X){
          x3DijagonalaDoleLevo = false;
      }


      if (glavniStruct->kvadrati[i][i] != POLJE_O){
          o3DijagonalaGoreLevo = false;
      }
      if (glavniStruct->kvadrati[i][2-i] != POLJE_O){
          o3DijagonalaDoleLevo = false;
      }

   }

   if (o3DijagonalaDoleLevo || o3DijagonalaGoreLevo){
       glavniStruct->partijaGotova = POBEDA_O;
   }

   if (x3DijagonalaDoleLevo || x3DijagonalaGoreLevo){
       glavniStruct->partijaGotova = POBEDA_X;
   }


   if (svaPoljaPopunjena && !glavniStruct->partijaGotova){
       glavniStruct->partijaGotova = NERESENO;
   }

}




