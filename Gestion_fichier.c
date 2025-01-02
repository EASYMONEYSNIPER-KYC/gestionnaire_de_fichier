#include <stdlib.h>
#include <stdio.h>
#include <string.h>
void lire_ligne_fichier(char *fichier_txt, int nbr_ligne){
  FILE *pointeur =fopen("fichier_texte.txt","r");
  if (pointeur == NULL){
    perror("Erreur d ouverture du fichier");
    return ;
  }
char ligne[200];
int compt_ligne = 0;
while (fgets(ligne,sizeof(ligne),pointeur)){
  compt_ligne++;
  if (compt_ligne ==nbr_ligne){
    printf("Ligne numero %d: %s",nbr_ligne,ligne);
    return ;
  }
}
printf("La ligne %d est introuvable",nbr_ligne);
fclose(pointeur);
}

int main(){

// Lecture du fichier
FILE *pointeur = fopen("fichier_texte.txt","r");
if(pointeur == NULL){
  perror("Erreur d'ouverture du fichier.\n");
  return 1;
}
char ligne[100];
while (fgets(ligne,sizeof(ligne),pointeur)){
  printf("%s",ligne);
}
fclose(pointeur);
lire_ligne_fichier("\nfichier_texte.txt",4); //Affichage ligne particulière
// Nombre de caractère
fseek(pointeur, 0, SEEK_END);
    long tailleFichier = ftell(pointeur);
    rewind(pointeur);
printf("Nombre de caractère du fichier: %ld",tailleFichier);

//Nombre de mot

fclose;
return 0;
}
