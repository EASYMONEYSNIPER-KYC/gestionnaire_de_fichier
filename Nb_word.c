// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <ctype.h>

// #define MAX_WORDS 1000  // Nombre maximum de mots uniques
// #define MAX_WORD_LEN 50 // Longueur maximale d'un mot

// // Fonction pour afficher le texte
// void Afficher_texte(FILE *file)
// {

//     char ligne[100]; // pour ligne du fichier texte
//     int compteur = 0;

//     while (fgets(ligne, sizeof(ligne), file))
//     {
//         compteur++;
//         printf("%s", ligne);
//     }

//     if (compteur == 0)
//     {
//         printf("Le fichier est vide ou aucune ligne n'a été lue.\n");
//     }
// }

// void Freq_carac_mots_lignes(FILE *file)
// {

//     // Initialisation des compteurs
//     int nb_mots = 0;
//     int nb_lignes = 0;
//     int nb_carac = 0;
//     char a;
//     int dans_un_mot = 0;

//     // Vérifier si le fichier est accessible
//     fseek(file, 0, SEEK_END);
//     long taille = ftell(file);
//     printf("Taille du fichier : %ld octets\n", taille);

//     // Si le fichier est vide, sortir immédiatement
//     if (taille == 0)
//     {
//         printf("Le fichier est vide.\n");
//         return;
//     }

//     // Remettre le curseur au début du fichier
//     fseek(file, 0, SEEK_SET);

//     // Lecture caractère par caractère
//     while ((a = fgetc(file)) != EOF)
//     {
    
//         nb_carac++; // Chaque caractère lu est compté

//         // Compter les lignes
//         if (a == '\n')
//         {
//             nb_lignes++;
//         }

//         // Compter les mots
//         if (isspace(a)) // Si c'est un espace, un tab ou un saut de ligne
//         {
//             dans_un_mot = 0;
//         }
//         else if (!dans_un_mot && !isspace(a)) // Début d'un nouveau mot
//         {
//             dans_un_mot = 1;
//             nb_mots++;
//         }
//     }

//     // Si le fichier ne se termine pas par un saut de ligne, ajouter une ligne
//     if (nb_carac > 0 && a != '\n')
//     {
//         nb_lignes++;
//     }

//     // Affichage des résultats
//     printf("Nombre de mots      : %d\n", nb_mots);
//     printf("Nombre de lignes    : %d\n", nb_lignes);
//     printf("Nombre de caracteres: %d\n", nb_carac);
// }


// int main(int argc , char *argv[]){

//     char filename[1000];
//     int r;

//     printf("1-Nombre de lignes, de mots et de caracteres : \n");
//     printf("Entrez le nom du fichier texte à analyser : ");
//     fgets(filename, 1000, stdin);

//     filename[strcspn(filename, "\n")] = '\0';

//     FILE *file = fopen(filename, "r");

//     if (!file) {
//         perror("Erreur d'ouverture du fichier");
//         return 1;
//     }
//     else
//     {
//         printf("Début de l'opération: \n");
//     }

//     Afficher_texte(file);

//     Freq_carac_mots_lignes(file);

//     fclose(file);
           
    
//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000 // Nombre maximum de mots uniques
#define MAX_WORD_LEN 50 // Longueur maximale d'un mot

// Fonction pour afficher le texte
void Afficher_texte(FILE *file) {
    char ligne[100]; // pour ligne du fichier texte
    int compteur = 0;

    printf("\n--- Contenu du fichier ---\n");
    while (fgets(ligne, sizeof(ligne), file)) {
        compteur++;
        printf("%s", ligne);
    }
    printf("\n---------------------------\n");

    if (compteur == 0) {
        printf("Le fichier est vide ou aucune ligne n'a été lue.\n");
    }
}

// Fonction pour analyser les statistiques du texte
void Analyser_texte(FILE *file) {
    // Initialisation des compteurs
    int nb_mots = 0;
    int nb_lignes = 0;
    int nb_paragraphes = 0;
    int nb_carac_avec_ponct = 0; // Nombre de caractères avec ponctuation
    int nb_carac_sans_ponct = 0; // Nombre de caractères sans ponctuation

    char a;
    int dans_un_mot = 0; // Indique si on est dans un mot

    // Vérifier si le fichier est accessible
    fseek(file, 0, SEEK_END);
    long taille = ftell(file);
    printf("Taille du fichier : %ld octets\n", taille);

    // Si le fichier est vide, sortir immédiatement
    if (taille == 0) {
        printf("Le fichier est vide.\n");
        return;
    }

    // Remettre le curseur au début du fichier
    fseek(file, 0, SEEK_SET);

    // Lecture caractère par caractère
    while ((a = fgetc(file)) != EOF) {
        nb_carac_avec_ponct++; // Chaque caractère lu est compté

        // Compter les lignes
        if (a == '\n') {
            nb_lignes++;
        }

        // Compter les paragraphes
        if (a == '\n') {
            // Si deux sauts de ligne consécutifs
            char b = fgetc(file);
            if (b == '\n') {
                nb_paragraphes++;
            }
            ungetc(b, file); // Remettre le caractère dans le flux
        }

        // Compter les caractères sans ponctuation
        if (!ispunct(a)) {
            nb_carac_sans_ponct++;
        }

        // Compter les mots
        if (isspace(a)) { // Si c'est un espace, un tab ou un saut de ligne
            dans_un_mot = 0;
        } else if (!dans_un_mot) { // Début d'un nouveau mot
            dans_un_mot = 1;
            nb_mots++;
        }
    }

    // Si le fichier ne se termine pas par un saut de ligne, ajouter une ligne
    if (nb_carac_avec_ponct > 0 && a != '\n') {
        nb_lignes++;
    }

    // Si le fichier contient du texte, il y a au moins un paragraphe
    if (taille > 0 && nb_paragraphes == 0) {
        nb_paragraphes = 1;
    }

    // Affichage des résultats
    printf("\n--- Statistiques du texte ---\n");
    printf("Nombre de mots : %d\n", nb_mots);
    printf("Nombre de lignes : %d\n", nb_lignes);
    printf("Nombre de paragraphes : %d\n", nb_paragraphes);
    printf("Nombre de caractères (avec ponctuation) : %d\n", nb_carac_avec_ponct);
    printf("Nombre de caractères (sans ponctuation) : %d\n", nb_carac_sans_ponct);
    printf("-----------------------------\n");
}

int main(int argc, char *argv[]) {
    char filename[1000];

    printf("1 - Analyse de texte : Nombre de lignes, de mots, de caractères et de paragraphes.\n");
    printf("Entrez le nom du fichier texte à analyser : ");
    fgets(filename, 1000, stdin);
    filename[strcspn(filename, "\n")] = '\0'; // Supprimer le saut de ligne de l'entrée utilisateur

    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Erreur d'ouverture du fichier");
        return 1;
    } else {
        printf("Début de l'opération :\n");
    }

    // Affichage du texte
    Afficher_texte(file);

    // Analyse du texte
    fseek(file, 0, SEEK_SET); // Remettre le curseur au début du fichier
    Analyser_texte(file);

    fclose(file);
    return 0;
}

