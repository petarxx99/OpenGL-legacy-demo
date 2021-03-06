

#define ERROR_VOID(a) {fprintf(stderr, a); return;}
#define true 1
#define false 0
#define PI 3.14
#define DUZINA_TABLE 2
#define POLJE_X 2
#define POLJE_O 1
#define PRAZNO_POLJE 0
#define POBEDA_X 3
#define POBEDA_O 5
#define NERESENO 7
#define PARTIJA_TRAJE 0
#define POTEZ_X 1
#define POTEZ_O 0


struct GlavniStruct {

   int windowDuzina;
   int windowVisina;
   double duzinaIvice;
   double duzinaStrane;
   int traje;
   int koJeNaPotezu;
   int kvadrati[3][3];
   unsigned char partijaGotova;


}__attribute__((packed));


void printStanjePartije(struct GlavniStruct *glavniStruct);
void crtajUKvadrate(struct GlavniStruct* glavniStruct);
void daLiJePartijaGotova(struct GlavniStruct *glavniStruct);

void crtajIviceKvadrata(double duzinaIvice, double duzinaStrane, double crvena, double
zelena, double plava);
void obojiPozadinu(double crvena, double zelena, double plava);
void crtajX(struct GlavniStruct *glavniStruct, int i, int j, double debljina);
void crtajO(struct GlavniStruct *glavniStruct, int i, int j, double
debljina, double tangenta, double duzinaDijagonale, double
ugaoDijagonale);






