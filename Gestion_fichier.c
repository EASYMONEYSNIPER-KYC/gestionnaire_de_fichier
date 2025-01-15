#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

FILE* lirefichier(char *fichier_txt){
  FILE* pointeur = fopen("fichier_texte.txt","rb");
  if (pointeur == NULL){
    perror("Erreur d ouverture du fichier");
    return ;
  }
  return pointeur;
}
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
int nbr_caracter(FILE *pointeur){
  fseek(pointeur, 0, SEEK_END);
    long tailleFichier = ftell(pointeur);
    rewind(pointeur);
printf("Nombre de caractère du fichier: %ld\n",tailleFichier);
return tailleFichier;
rewind(pointeur);
}

// Nbr de mot
int nbr_mot(FILE *pointeur){
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
printf("Nombre de caractère du fichier: %d\n",nbr_mot);
return nbr_mot;
rewind(pointeur);
}

//nbr de ligne
int nbr_ligne(FILE *pointeur){
int line = 0;
char ligne[100];
while (fgets(ligne,100,pointeur)!=NULL){
  line++;
}
printf("Nombre de ligne du fichier: %d\n",line);
return line;
rewind(pointeur);
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

// Conversion de la casse en minuscule
void Conv_in_min(char *mot){
    for(int i=0;mot[i]!='\0';i++){
        if(mot[i]>='A' && mot[i]<='Z'){
            mot[i] +=32;
        }
    }
}

//Fonction pour sauvegarder la statistique dans un fichier texte
void sauvegarder_en_texte(Gestionnaire stats[], int n, FILE* fichier){
    if (fichier == NULL) {
        printf("Erreur d'ouverture du fichier.\n");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        fprintf(fichier, "Mot: %s | Frequence: %d\n", stats[i].wrd, stats[i].frequency);
    }
}
//void save(char *fichier,)
//Fonction pour l analyse de texte 

int main(){
// Choix du fichier
char fichier[100];
printf("Entrer le chemin vers le fichier\n(dir/dir/..../filename): ");
fgets(fichier,100,stdin);
int l1 = strlen(fichier);
  if(fichier[l1-1] == '\n'){
      fichier[l1-1] = '\0';
  }
// Ouverture et Détermination du type du fichier
lirefichier(fichier);
FILE *pointeur =fopen(fichier,"rb");
if (pointeur == NULL){
  perror("Erreur d'ouverture du fichier.\n");
  return 1;
}
char c[500];
// caractere_nonimprimable[]={0x00, 0x07, 0x08, 0x1B, 0x7F};
size_t taille;
int binary_or_txt = 0;
while ((taille = fread(c,1,sizeof(c),pointeur)) > 0){
  for (size_t i = 0; i < taille; i++){
    if (c[i] == 0x00 || c[i] == 0x07 || c[i] == 0x08 || c[i] == 0x1B || c[i] == 0x7F){
      binary_or_txt = 1;
      break;
    }
  }
  if(binary_or_txt){
    break;
  }
}
// Analyse du fichier
  if(binary_or_txt == 1){
    printf("Le fichier est binaire\n");
  }else{
    printf("Le fichier est un fichier texte\n");
    //fonction pour l analyse des fichiers texte
  }
  fclose(pointeur);
return 0;
}