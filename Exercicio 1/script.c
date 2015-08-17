#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//Aluno:Eduardo Felipe da Silva Kreve
int main(){
   FILE *leia;
   char string[100];
   int chave=0,opc=0,i=0;

   leia = fopen("leia.txt","r");
  
  while(string[i]!=EOF) {
        fscanf(leia,"%c",&string[i]);
        i++; 
  }
  
   
   printf("Digite 1 para Cifrar e 2 para Descifrar: ");
   scanf("%d",&opc);
   printf("Digite o valor da chave: ");
   scanf("%d",&chave);

   if(opc==1){
      FILE *cezar;
      cezar = fopen("Cifrado_cezar.txt","w");

      for(i=0;i<strlen(string);i++){
          putc((string[i]+chave)%256,cezar);
      }
      fclose(cezar);
  }

  if(opc==2){
     FILE *arq;
     arq = fopen("Descifrado.txt","w");

     for(i=0;i<strlen(string);i++){ // Descriptografia
     	putc((string[i]-chave)%256,arq);
     }
     fclose(arq);
  }

  fclose(leia);
  return 0;
}
