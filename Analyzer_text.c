#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000  // Nombre maximum de mots uniques
#define MAX_WORD_LEN 50 // Longueur maximale d'un mot

typedef struct {
    char mot[100];   // Pour stocker un mot
    int occurences;  // Pour stocker son nombre d'occurrences
} MotFrequence;

    // // Vérifier si le fichier est accessible
    // fseek(file, 0, SEEK_END);
    // long taille = ftell(file);
    // printf("Taille du fichier : %ld octets\n", taille);

    // // Si le fichier est vide, sortir immédiatement
    // if (taille == 0)
    // {
    //     printf("Le fichier est vide.\n");
    //     return;
    // }

    // // Remettre le curseur au début du fichier
    // fseek(file, 0, SEEK_SET);


// Fonction pour rechercher un mot spécifique dans une phrase
int rechercher_mot(const char *phrase, const char *mot) {
    int count = 0;
    const char *pos = phrase;

    while ((pos = strstr(pos, mot)) != NULL) {
        // Vérifier que c'est un mot entier
        if ((pos == phrase || *(pos - 1) == ' ') &&
            (*(pos + strlen(mot)) == ' ' || *(pos + strlen(mot)) == '\0')) {
            count++;
        }
        pos += strlen(mot); // Passer au prochain mot
    }

    return count;
}

//Fonction pour afficher la frequence de façon décroissante
void decroi_freq_mot(const char *phrase){
    char temp_phrase[4096];
    strcpy(temp_phrase, phrase);

    MotFrequence mots[100];
    int nb_mots = 0;

    char *mot = strtok(temp_phrase, " ");
    while (mot) {
        int deja_ajoute = 0;

        // Vérifier si le mot a déjà été compté
        for (int i = 0; i < nb_mots; i++) {
            if (strcmp(mots[i].mot, mot) == 0) {
                deja_ajoute = 1;
                break;
            }
        }

        if (!deja_ajoute) {
            strcpy(mots[nb_mots].mot, mot);
            mots[nb_mots].occurences = rechercher_mot(phrase, mot);
            nb_mots++;
        }

        mot = strtok(NULL, " ");
    }

    // Affichage des fréquences par ordre décroissant
    printf("Fréquences des mots par ordre décroissant:\n");
    int a;
    char b[1000];
    for (int i = 0; i < nb_mots; i++) {
        for (int j = i + 1; j < nb_mots; j++){
            if (mots[i].occurences <= mots[j].occurences){

                a = mots[i].occurences;
                strcpy(b , mots[i].mot);
                b[strlen(b)] = '\0';

                mots[i].occurences = mots[j].occurences;
                strcpy(mots[i].mot , mots[j].mot);
                mots[i].mot[strlen(mots[j].mot)] = '\0';

                mots[j].occurences = a;
                strcpy(mots[j].mot , b);
                mots[j].mot[strlen(b)] = '\0';
            }
        }   
    }

    // Affichage des fréquences par ordre décroissant
    for (int i = 0; i < nb_mots; i++) {
        if (mots[i].occurences )
        printf("'%s' : %d\n", mots[i].mot, mots[i].occurences);
    }

}

// Fonction pour calculer les fréquences de tous les mots dans une phrase
void calculer_frequence(const char *phrase) {
    char temp_phrase[4096];
    strcpy(temp_phrase, phrase);

    MotFrequence mots[100];
    int nb_mots = 0;

    char *mot = strtok(temp_phrase, " ");
    while (mot) {
        int deja_ajoute = 0;

        // Vérifier si le mot a déjà été compté
        for (int i = 0; i < nb_mots; i++) {
            if (strcmp(mots[i].mot, mot) == 0) {
                deja_ajoute = 1;
                break;
            }
        }

        if (!deja_ajoute) {
            strcpy(mots[nb_mots].mot, mot);
            mots[nb_mots].occurences = rechercher_mot(phrase, mot);
            nb_mots++;
        }

        mot = strtok(NULL, " ");
    }

    // Affichage des fréquences
    printf("Fréquences des mots dans la phrase :\n");
    for (int i = 0; i < nb_mots; i++) {
        printf("'%s' : %d\n", mots[i].mot, mots[i].occurences);
    }
}

// Edition
void remplacer_chaine(char *phrase, const char *ancienne_chaine, const char *nouvelle_chaine) {
    char buffer[4096]; // Tampon pour stocker le résultat
    char *pos = phrase;
    int ancienne_longueur = strlen(ancienne_chaine);
    int nouvelle_longueur = strlen(nouvelle_chaine);
    int index = 0;

    // Parcours de la phrase pour rechercher toutes les occurrences
    while ((pos = strstr(pos, ancienne_chaine)) != NULL) {
        // Copier la partie avant l'occurrence trouvée
        strncpy(buffer + index, phrase, pos - phrase);
        index += pos - phrase;

        // Copier la nouvelle chaîne
        strcpy(buffer + index, nouvelle_chaine);
        index += nouvelle_longueur;

        // Avancer après l'occurrence trouvée
        pos += ancienne_longueur;
        phrase = pos;
    }

    // Copier le reste de la phrase
    strcpy(buffer + index, phrase);


    printf("\nRésultat : %s\n", buffer);
}

// Fonction pour afficher le texte
void Afficher_texte(FILE *file)
{

    char ligne[100]; // pour ligne du fichier texte
    int compteur = 0;

    while (fgets(ligne, sizeof(ligne), file))
    {
        compteur++;
        printf("%s", ligne);
    }

    if (compteur == 0)
    {
        printf("Le fichier est vide ou aucune ligne n'a été lue.\n");
    }
}

// Fonction pour donner le nombre de mots, de caractère dans une chaine de caractère 
void Freq_carac_mots_lignes(FILE *file)
{

    // Initialisation des compteurs
    int nb_mots = 0;
    int nb_lignes = 0;
    int nb_carac = 0;
    char a;
    int dans_un_mot = 0;

    // Vérifier si le fichier est accessible
    fseek(file, 0, SEEK_END);
    long taille = ftell(file);
    printf("Taille du fichier : %ld octets\n", taille);

    // Si le fichier est vide, sortir immédiatement
    if (taille == 0)
    {
        printf("Le fichier est vide.\n");
        return;
    }

    // Remettre le curseur au début du fichier
    fseek(file, 0, SEEK_SET);

    // Lecture caractère par caractère
    while ((a = fgetc(file)) != EOF)
    {
        printf("\n\n");
        nb_carac++; // Chaque caractère lu est compté

        // Compter les lignes
        if (a == '\n')
        {
            nb_lignes++;
        }

        // Compter les mots
        if (isspace(a)) // Si c'est un espace, un tab ou un saut de ligne
        {
            dans_un_mot = 0;
        }
        else if (!dans_un_mot) // Début d'un nouveau mot
        {
            dans_un_mot = 1;
            nb_mots++;
        }
    }

    // Si le fichier ne se termine pas par un saut de ligne, ajouter une ligne
    if (nb_carac > 0 && a != '\n')
    {
        nb_lignes++;
    }

    printf("\n\n");

    // Affichage des résultats
    printf("Nombre de mots      : %d\n", nb_mots);
    printf("Nombre de lignes    : %d\n", nb_lignes);
    printf("Nombre de caractères: %d\n", nb_carac);
}

int main(int argc , char *argv[])
{
    // FILE *file = fopen("C:\\Users\\HP\\Desktop\\Informatique\\Nouveau dossier\\Nouveau_document_texte.txt", "r");

    // if (file == NULL)
    // {
    //     perror("Erreur d'ouverture du fichier");
    //     return 1;
    // }
    char filename[1000];
    int r;

    printf("__________________________________________________________________________________________________________________________________________________________");
    printf("\n                                                                       Bienvenue dans l'analyseur de texte.Voici nos fonctionnalites :\n\n");
    printf("1-Nombre de lignes, de mots et de caracteres;\n");
    printf("2-Dictionnaire des mots et calculer de la frequence d'apparition de chaque mot;\n");
    printf("3-Fréquence des mots de façcon décroissante;\n");
    printf("4-Edition(recherche et remplacement personnalisee);\n");
    printf("5-Sauvegarder les statistiques dans un fichier texte(ajouter le contenu a un fichier existant ou le mettre dans un repertoire donne);\n\n");
    printf("NB : Pour votre choix, choissisez un nombre entre 1 et 5.\n");

    do {

        printf("Votre choix (1-5): ");
        scanf("%d", &r);
        printf("\n");

    } while(1 > r || r> 5);


    switch(r) {
        case 1:
            printf("1-Nombre de lignes, de mots et de caracteres : \n");
            printf("Entrez le nom du fichier texte à analyser : ");
            fgets(filename, 1000, stdin);

            filename[strcspn(filename, "\n")] = '\0';

            FILE *file = fopen(filename, "r");
            if (!file) {
                perror("Erreur d'ouverture du fichier");
                return 1;
            }
            else
            {
                printf("Début de l'opération: \n");
            }
            Freq_carac_mots_lignes(file);
            fclose(file);
            break;

        case 2:
            printf("2-Dictionnaire des mots et calculer de la frequence d'apparition de chaque mot : \n");
            char phrase1[4096];
            char mot_recherche1[100];

            // printf("Entrez une phrase : ");
            // fgets(phrase1, sizeof(phrase1), stdin);
            // phrase1[strcspn(phrase1, "\n")] = '\0'; // Supprimer le saut de ligne

            // Calculer les fréquences de tous les mots
            calculer_frequence(phrase1);
            break;

        case 3:
            printf("La frequence des mots de facon decroissante : \n");
            char phrase2[4096];
            char mot_recherche2[100];

            printf("Entrez une phrase : ");
            fgets(phrase2, sizeof(phrase2), stdin);
            phrase2[strcspn(phrase2, "\n")] = '\0'; // Supprimer le saut de ligne

            //Fonction pour afficher la fréquence des mots de manière décorissante
            decroi_freq_mot(phrase2);
            break;

        case 4:
            printf("Edition(recherche et remplacement personnalisee) :\n");
            char phrase3[4096];
            char ancienne_chaine1[1024];
            char nouvelle_chaine1[1024];

            printf("Entrez une phrase : ");
            fgets(phrase3, sizeof(phrase3), stdin);
            phrase3[strcspn(phrase3, "\n")] = '\0'; // Supprimer le saut de ligne

            printf("Entrez l'ancienne chaine (mot ou phrase) : ");
            fgets(ancienne_chaine1, sizeof(ancienne_chaine1), stdin);
            ancienne_chaine1[strcspn(ancienne_chaine1, "\n")] = '\0'; // Supprimer le saut de ligne

            printf("Entrez la nouvelle chaine (mot ou phrase) : ");
            fgets(nouvelle_chaine1, sizeof(nouvelle_chaine1), stdin);
            nouvelle_chaine1[strcspn(nouvelle_chaine1, "\n")] = '\0'; // Supprimer le saut de ligne

            remplacer_chaine(phrase3, ancienne_chaine1, nouvelle_chaine1);
            break;

        case 5:
            printf("Sauvegarder les statistiques dans un fichier texte(ajouter le contenu a un fichier existant ou le mettre dans un repertoire donne).");
            break;

        default :
            printf("Erreur, programme terminé !");
    }

    return 0;
}


