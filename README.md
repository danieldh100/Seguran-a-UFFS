#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 12345

int main(){
  int i=0;
  char text[MAX],chave[MAX],cont[MAX];

  FILE *leia;
  FILE *Vigenere;
  leia = fopen("leia.txt","r");
  Vigenere = fopen("Cifrado.txt","w");
   
  fread(text,sizeof (char),MAX,leia);
  text[strlen(text)-1]='\0';
  printf("%s\n",text);// só para ver se vai puxar do arquivo corretamente
  
  printf("Digite a chave: ");
  fgets(chave, MAX, stdin);
  chave[strlen(chave)-1]='\0';   
   
  while((int)strlen(chave)<(int)strlen(text)){ // Replica a chave no tamanho do texto
       chave[strlen(chave)]=chave[i];
       i++;
  }
  printf("%s\n",chave);
  
  for(i=0;i<strlen(text);i++){
     cont[i]=(text[i]+chave[i%strlen(chave)])%256;
  }
 
    
  fwrite(cont,sizeof(char),strlen(text),Vigenere);

  fclose(leia);
  fclose(Vigenere);

  return 0;
}
