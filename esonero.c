//LIBRERIE UTILIZZATE
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
int main()
{

  //DICHIARAZIONE VARIABILI
  char M[129];
  char C[129];
  char K[129];
  char KR[129];
  char M2[129];
  int scelta=0;
  int ritorno=0;
  
  //INSERIMENTO STRINGA DI PARTENZA
  printf("--INSERIRE UNA STRINGA: --\n");
  fgets(M,129,stdin);
  
  //SELEZIONE OPZIONE DEL MENÙ
  printf("####COME DESIDERI PROCEDERE ORA?####\n");
  printf("1. Utilizzare una chiave di cifratura personalizzata\n");
  printf("2. Utilizzare una chiave di cifratura generata casualmente\n");
  scanf("%d",&scelta);
  int ch;
  while((ch = getchar()) != '\n' && ch != EOF);
  
  switch(scelta)
  {

    //CIFRATURA CON CHIAVE PERSONALIZZATA
    case 1:

      //INSERIMENTO CHIAVE     
      printf("--INSERIRE CHIAVE DI CIFRATURA: --\n");
      fgets(K,129,stdin);
     
      //OPERAZIONE XOR SULLA STRINGA ORIGINALE
      for(int c=0;c<strlen(M);c++)
      {
        C[c] = M[c]^K[c];
      }
      
      //OUTPUT STRINGA
      printf("--STRINGA CIFRATA: --\n");
      printf("%s\n",C);

      //RISTAMPA STRINGA ORIGINALE CON PROCEDIMENTO INVERSO
      printf("--DESIDERA TORNARE ALLA STRINGA ORIGINALE? [0=SI,1=NO]--\n");
      scanf("%d",&ritorno);

      //OPERAZIONE XOR SU STRINGA CIFRATA      
      if(ritorno==0)
      {
        for(int x=0;x<strlen(M);x++)
        {
          M2[x] = C[x]^K[x];
        }
        printf("--STRINGA ORIGINALE: --\n");
        printf("%s",M2);
      }
      break;

    //CIFRATURA CON CHIAVE RANDOMICA
    case 2:

      //GENERAZIONE CHIAVE DI CIFRATURA
      for (int i=0;i<strlen(M);i++)
      {
        KR[i] = rand()%(127)+32;
      }
      printf("--CHIAVE GENERATA: --\n");
      printf("%s\n",KR);

      //OPERAZIONE XOR SULLA STRINGA ORIGINALE
      for(int e=0;e<strlen(M);e++)
      {
        C[e] = M[e]^KR[e];
      }

      //OUTPUT STRINGA
      printf("--STRINGA CIFRATA: --\n");
      printf("%s\n",C);

      //RISTAMPA STRINGA ORIGINALE CON PROCEDIMENTO INVERSO
      printf("--DESIDERA TORNARE ALLA STRINGA ORIGINALE? [0=SI,1=NO]--\n");
      scanf("%d",&ritorno);

      //OPERAZIONE XOR SU STRINGA CIFRATA
      if(ritorno==0)
      {
        for(int f=0;f<strlen(C);f++)
        {
          M2[f] = C[f]^KR[f];
        }
        printf("--STRINGA ORIGINALE: --\n");
        printf("%s",M2);
      }
      break;
  }
  return 0;
}
