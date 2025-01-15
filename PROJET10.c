#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define MAX_WORDS 10000

typedef struct {
    char mot[MAX_WORD_LENGTH];
    int compt;
} motcompt;

int findWord(motcompt mots[], int size, const char *mot) {
    for (int i = 0; i < size; i++) {
        if (strcmp(mots[i].mot, mot) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    char filename[100];
    char mott[MAX_WORD_LENGTH];
    motcompt mots[MAX_WORDS];
    int motcompt = 0;

    // Demander le nom du fichier à l'utilisateur
    printf("Entrez le nom du fichier : ");
    scanf("%s", filename);

    // Ouvrir le fichier en mode lecture
    FILE *fichier = fopen(filename, "r");
    if (fichier == NULL) {
        // Afficher l'erreur et quitter si le fichier ne peut pas être ouvert
        printf("Erreur d'ouverture du fichier texte %s\n", filename);
        return 1;
    }

    // Lire les mots du fichier un par un
    while (fscanf(fichier, "%49s", mott) == 1) {
        int index = findWord(mots, motcompt, mott);
        if (index != -1) {
            mots[index].compt++;
        } else {
            strcpy(mots[motcompt].mot, mott);
            mots[motcompt].compt = 1;
            motcompt++;
        }
    }

    // Fermer le fichier
    fclose(fichier);

    // Afficher les fréquences des mots
    for (int i = 0; i < motcompt; i++) {
        printf("Le mot '%s' apparaît %d fois.\n", mots[i].mot, mots[i].compt);
    }

    return 0;
}