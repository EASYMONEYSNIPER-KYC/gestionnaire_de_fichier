#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

//Lire ligne particulière
void lire_ligne_fichier(char *fichier_txt, int nbr_ligne){
  FILE *pointeur = fopen("fichier_texte.txt","r");
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

//nbr de caractère
int nbr_caracter(char *fichier_txt){
  FILE *pointeur = fopen("fichier_texte.txt","r");
if(pointeur == NULL){
  perror("Erreur d'ouverture du fichier.\n");
  return 1;
}
  fseek(pointeur, 0, SEEK_END);
    long tailleFichier = ftell(pointeur);
    rewind(pointeur);
printf("Nombre de caractère du fichier: %ld\n",tailleFichier);
return tailleFichier;
}

// Nbr de mot
void nbr_mot(char *fichier_txt){
  FILE *pointeur = fopen("fichier_texte.txt","r");
if(pointeur == NULL){
  perror("Erreur d'ouverture du fichier.\n");
  return 1;
}
  char c;
  int nbr_mot=0;
int interieur_du_mot=0;
while ((c=fgetc(pointeur))!=EOF){
  if (isspace(c)){
    interieur_du_mot=0;
  }else if (interieur_du_mot==0){
    interieur_du_mot =1;
    nbr_mot++;
  }  
}
}
//nbr de ligne
void nbr_ligne(char *fichier_txt){
  FILE *pointeur = fopen("fichier_texte.txt","r");
if(pointeur == NULL){
  perror("Erreur d'ouverture du fichier.\n");
  return 1;
}
int line = 0;
char ligne[100];
while (fgets(ligne,100,pointeur)!=NULL){
  line++;
}
}

// fileToStr (Chaine de caractère contenant tout le fichier)
char *fileToStr(char *fichier_txt){
  FILE *pointeur = fopen("fichier_texte.txt","r");
  if(pointeur == NULL){
    perror("Erreur d'ouverture du fichier.\n");
    return NULL;
  }
  int tailleFichier = nbr_caracter(fichier_txt);
    char *str_of_file = malloc(tailleFichier+1);
    if (str_of_file == NULL){
        perror("Erreur d'allocation de mémoire");
        return NULL;
    }
    fread(str_of_file,sizeof(char),tailleFichier,pointeur);
    str_of_file[tailleFichier] = '\0';
    fclose(pointeur);
    return str_of_file;
    free(str_of_file);
}

//Dictionnaire
typedef struct 
{
  char wrd[50];
  int frequency;
}Gestionnaire;

int main(){
// Choix du fichier
char fichier[100];
printf("Entrer le chemin du fichier entre " ": ");
fgets(fichier,100,stdin);
int l1 = strlen(fichier);
  if(fichier[l1-1] == '\n'){
      fichier[l1-1] = '\0';
  }
// Ouverture et Détermination du type du fichier
FILE *pointeur =fopen(fichier,"rb");
if (pointeur == NULL){
  perror("Erreur d'ouverture du fichier.\n");
  return 1;
}
char c[500];
// caractere_nonimprimable[]={0x00, 0x07, 0x08, 0x1B, 0x7F};
size_t taille = fread(c,1,sizeof(c),pointeur);
int binary_or_txt = 0;
while (taille >0){
  for (size_t i = 0; i < taille; i++){
    if (c[i] == 0x00 || c[i] == 0x07 || c[i] == 0x08 || c[i] == 0x1B || c[i] == 0x7F){
      binary_or_txt = 1;
      break;
    }
  }
}
fclose(pointeur);
// Analyse du fichier
  if(binary_or_txt == 1){
    printf("Le fichier est binaire\n");
    //fonction pour l analyse des fichiers binaires
    //(A COMPLETER)
  }else{
    printf("Le fichier est un fichier texte\n");
    //fonction pour l analyse des fichiers texte
    //(A COMPLETER)
  }
    fclose(pointeur);
return 0;
}