#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// typedef struct {
//     char mot[200];   // Pour stocker un mot
//     int occurences;  // Pour stocker son nombre d'occurrences
// } MotFrequence;

// // Fonction pour rechercher un mot spécifique dans une phrase
// int rechercher_mot(const char *phrase, const char *mot) {
//     int count = 0;
//     const char *pos = phrase;

//     while ((pos = strstr(pos, mot)) != NULL) {
//         // Vérifier que c'est un mot entier
//         if ((pos == phrase || *(pos - 1) == ' ') &&
//             (*(pos + strlen(mot)) == ' ' || *(pos + strlen(mot)) == '\0')) {
//             count++;
//         }
//         pos += strlen(mot); // Passer au prochain mot
//     }

//     return count;
// }

// // Fonction pour calculer les fréquences de tous les mots dans une phrase
// void calculer_frequence(const char *phrase) {
//     char temp_phrase[10000];
//     strcpy(temp_phrase, phrase);

//     MotFrequence mots[1000];
//     int nb_mots = 0;

//     char *mot = strtok(temp_phrase, " ");
//     while (mot) {
//         int deja_ajoute = 0;

//         // Vérifier si le mot a déjà été compté
//         for (int i = 0; i < nb_mots; i++) {
//             if (strcmp(mots[i].mot, mot) == 0) {
//                 deja_ajoute = 1;
//                 break;
//             }
//         }

//         if (!deja_ajoute) {
//             strcpy(mots[nb_mots].mot, mot);
//             mots[nb_mots].occurences = rechercher_mot(phrase, mot);
//             nb_mots++;
//         }

//         mot = strtok(NULL, " ");
//     }

//     // Affichage des fréquences par ordre décroissant
//     printf("Fréquences des mots:\n");
//     for (int i = 0; i < nb_mots; i++) {
//         if (mots[i].occurences )
//         printf("'%s' : %d\n", mots[i].mot, mots[i].occurences);
//     }

    
// }

// // void decroi_freq_mot(const char *phrase){
// //     char temp_phrase[4096];
// //     strcpy(temp_phrase, phrase);

// //     MotFrequence mots[100];
// //     int nb_mots = 0;

// //     char *mot = strtok(temp_phrase, " ");
// //     while (mot) {
// //         int deja_ajoute = 0;

// //         // Vérifier si le mot a déjà été compté
// //         for (int i = 0; i < nb_mots; i++) {
// //             if (strcmp(mots[i].mot, mot) == 0) {
// //                 deja_ajoute = 1;
// //                 break;
// //             }
// //         }

// //         if (!deja_ajoute) {
// //             strcpy(mots[nb_mots].mot, mot);
// //             mots[nb_mots].occurences = rechercher_mot(phrase, mot);
// //             nb_mots++;
// //         }

// //         mot = strtok(NULL, " ");
// //     }

// //     // Affichage des fréquences par ordre décroissant
// //     printf("Fréquences des mots par ordre décroissant:\n");
// //     int a;
// //     char b[1000];
// //     for (int i = 0; i < nb_mots; i++) {
// //         for (int j = i + 1; j < nb_mots; j++){
// //             if (mots[i].occurences <= mots[j].occurences){

// //                 a = mots[i].occurences;
// //                 strcpy(b , mots[i].mot);
// //                 b[strlen(b)] = '\0';

// //                 mots[i].occurences = mots[j].occurences;
// //                 strcpy(mots[i].mot , mots[j].mot);
// //                 mots[i].mot[strlen(mots[j].mot)] = '\0';

// //                 mots[j].occurences = a;
// //                 strcpy(mots[j].mot , b);
// //                 mots[j].mot[strlen(b)] = '\0';
// //             }
// //         }   
// //     }

// //     // Affichage des fréquences par ordre décroissant
// //     for (int i = 0; i < nb_mots; i++) {
// //         if (mots[i].occurences )
// //         printf("'%s' : %d\n", mots[i].mot, mots[i].occurences);
// //     }

// // }

// int main() {

//     // Nom du fichier
//     const char *nom_fichier = "Nouveau_document_texte.txt";

//     // Ouvrir le fichier en mode lecture
//     FILE *file = fopen(nom_fichier, "r");
//     if (file == NULL)
//     {
//         perror("Erreur lors de l'ouverture du fichier");
//         return 1;
//     }

//     // Déplacer le curseur à la fin pour connaître la taille
//     fseek(file, 0, SEEK_END);
//     long taille_fichier = ftell(file);
//     rewind(file); // Retourner au début du fichier

//     // Allouer une chaîne pour le contenu du fichier (+1 pour '\0')
//     char *contenu = malloc(taille_fichier + 1);
//     if (contenu == NULL)
//     {
//         perror("Erreur d'allocation mémoire");
//         fclose(file);
//         return 1;
//     }

//     // Lire tout le contenu du fichier
//     fread(contenu, 1, taille_fichier, file);
//     contenu[taille_fichier] = '\0'; // Ajouter le terminateur nul

//     // Afficher le contenu
//     printf("Contenu du fichier 2:\n%s\n\n", contenu);

//     char mot_recherche[100];

//     // printf("Entrez une phrase : ");
//     // fgets(phrase, sizeof(phrase), stdin);
//     // phrase[strcspn(phrase, "\n")] = '\0'; // Supprimer le saut de ligne

//     printf("\nEntrez le mot à rechercher : ");
//     scanf("%s", mot_recherche);

//     // Calculer les fréquences de tous les mots
//     calculer_frequence(contenu);

//     // Recherche d'un mot spécifique
//     int frequence = rechercher_mot(contenu, mot_recherche);
//     printf("\nLe mot '%s' revient %d fois dans la phrase.\n", mot_recherche, frequence);

//     // Fermer le fichier
//     fclose(file);

//     // Libérer la mémoire
//     free(contenu);

//     return 0;
// }

// // Fonction pour normaliser le texte
// void normaliser_texte(char *texte) {
//     for (int i = 0; texte[i]; i++) {
//         if (isalpha(texte[i])) {
//             texte[i] = tolower(texte[i]);
//         } else {
//             texte[i] = ' ';
//         }
//     }
// }

// // Fonction pour calculer les fréquences des mots
// void calculer_frequence(char *texte) {
//     char *mot;
//     char *delim = " ";
//     int taille_dico = 100;
//     int nb_mots = 0;
//     char **dico = malloc(taille_dico * sizeof(char *));
//     int *frequences = malloc(taille_dico * sizeof(int));

//     mot = strtok(texte, delim);
//     while (mot != NULL) {
//         int trouve = 0;
//         for (int i = 0; i < nb_mots; i++) {
//             if (strcmp(dico[i], mot) == 0) {
//                 frequences[i]++;
//                 trouve = 1;
//                 break;
//             }
//         }
//         if (!trouve) {
//             if (nb_mots >= taille_dico) {
//                 taille_dico *= 2;
//                 dico = realloc(dico, taille_dico * sizeof(char *));
//                 frequences = realloc(frequences, taille_dico * sizeof(int));
//             }
//             dico[nb_mots] = strdup(mot);
//             frequences[nb_mots] = 1;
//             nb_mots++;
//         }
//         mot = strtok(NULL, delim);
//     }

//     printf("Dictionnaire des mots et leurs fréquences:\n");
//     for (int i = 0; i < nb_mots; i++) {
//         printf("%s: %d\n", dico[i], frequences[i]);
//         free(dico[i]);
//     }
//     free(dico);
//     free(frequences);
// }

// int main() {
//     // Nom du fichier
//     const char *nom_fichier = "Nouveau_document_texte.txt";

//     // Ouvrir le fichier en mode lecture
//     FILE *file = fopen(nom_fichier, "r");
//     if (file == NULL)
//     {
//         perror("Erreur lors de l'ouverture du fichier");
//         return 1;
//     }

//     // Déplacer le curseur à la fin pour connaître la taille
//     fseek(file, 0, SEEK_END);
//     long taille_fichier = ftell(file);
//     rewind(file); // Retourner au début du fichier

//     // Allouer une chaîne pour le contenu du fichier (+1 pour '\0')
//     char *contenu = malloc(taille_fichier + 1);
//     if (contenu == NULL)
//     {
//         perror("Erreur d'allocation mémoire");
//         fclose(file);
//         return 1;
//     }

//     // Lire tout le contenu du fichier
//     fread(contenu, 1, taille_fichier, file);
//     contenu[taille_fichier] = '\0'; // Ajouter le terminateur nul

//     // Faire une copie du contenu pour le normaliser
//     char *contenu_normalise = strdup(contenu);
//     if (contenu_normalise == NULL)
//     {
//         perror("Erreur d'allocation mémoire");
//         free(contenu);
//         fclose(file);
//         return 1;
//     }

//     // Normaliser le texte
//     normaliser_texte(contenu_normalise);

//     // Afficher le contenu original
//     printf("Contenu du fichier 2:\n%s\n\n", contenu);

//     // Calculer les fréquences de tous les mots
//     calculer_frequence(contenu_normalise);

//     free(contenu_normalise);
//     free(contenu);
//     fclose(file);
//     return 0;
// }

// Fonction pour vérifier si un caractère est une lettre accentuée
int est_lettre_accentuee(unsigned char c) {
    return (c >= 192 && c <= 255);
}

// Fonction pour normaliser le texte
void normaliser_texte(char *texte) {
    for (int i = 0; texte[i]; i++) {
        if (isalpha(texte[i]) || est_lettre_accentuee((unsigned char)texte[i])) {
            texte[i] = tolower(texte[i]);
        } else if (ispunct(texte[i])) {
            texte[i] = ' ';
        }
    }
}

// Fonction pour calculer les fréquences des mots
void calculer_frequence(char *texte) {
    char *mot;
    char *delim = " ";
    int taille_dico = 100;
    int nb_mots = 0;
    char **dico = malloc(taille_dico * sizeof(char *));
    int *frequences = malloc(taille_dico * sizeof(int));

    mot = strtok(texte, delim);
    while (mot != NULL) {
        int trouve = 0;
        for (int i = 0; i < nb_mots; i++) {
            if (strcmp(dico[i], mot) == 0) {
                frequences[i]++;
                trouve = 1;
                break;
            }
        }
        if (!trouve) {
            if (nb_mots >= taille_dico) {
                taille_dico = taille_dico * 2;
                dico = realloc(dico, taille_dico * sizeof(char *));
                frequences = realloc(frequences, taille_dico * sizeof(int));
            }
            dico[nb_mots] = strdup(mot);
            frequences[nb_mots] = 1;
            nb_mots++;
        }
        mot = strtok(NULL, delim);
    }

    printf("Dictionnaire des mots et leurs fréquences:\n");
    for (int i = 0; i < nb_mots; i++) {
        printf("%s: %d\n", dico[i], frequences[i]);
        free(dico[i]);
    }
    free(dico);
    free(frequences);
}

int main() {
    // Nom du fichier
    const char *nom_fichier = "Nouveau_document_texte.txt";

    // Ouvrir le fichier en mode lecture
    FILE *file = fopen(nom_fichier, "r");
    if (file == NULL)
    {
        perror("Erreur lors de l'ouverture du fichier");
        return 1;
    }

    // Déplacer le curseur à la fin pour connaître la taille
    fseek(file, 0, SEEK_END);
    long taille_fichier = ftell(file);
    rewind(file); // Retourner au début du fichier

    // Allouer une chaîne pour le contenu du fichier (+1 pour '\0')
    char *contenu = malloc(taille_fichier + 1);
    if (contenu == NULL)
    {
        perror("Erreur d'allocation mémoire");
        fclose(file);
        return 1;
    }

    // Lire tout le contenu du fichier
    fread(contenu, 1, taille_fichier, file);
    contenu[taille_fichier] = '\0'; // Ajouter le terminateur nul

    // Faire une copie du contenu pour le normaliser
    char *contenu_normalise = strdup(contenu);
    if (contenu_normalise == NULL)
    {
        perror("Erreur d'allocation mémoire");
        free(contenu);
        fclose(file);
        return 1;
    }

    // Normaliser le texte
    normaliser_texte(contenu_normalise);

    // Afficher le contenu original
    printf("Contenu du fichier 2:\n%s\n\n", contenu);

    // Calculer les fréquences de tous les mots
    calculer_frequence(contenu_normalise);

    free(contenu_normalise);
    free(contenu);
    fclose(file);
    return 0;
}

