#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
//création du menu principal
void afficherMenuPrincipal();

//création de l'interface du jeu
void interfaceDeJeu(){
    system("cls");
    int valeurcolonne;
    int valeurligne;
    int coordonnees;
    printf("\nVoici la grille de jeu : 10 x 10 cases");
    printf("\nEntrez ci-dessous vos coordonées  (ex : 18):\n\n");



    int grille1 [10] [10] = {
            {0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,1,1,1},
            {0,0,0,0,0,0,0,0,0,0},
            {1,1,1,1,1,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0},
            {0,1,0,0,0,0,0,0,0,0},
            {0,1,0,0,0,0,1,1,1,1},
            {0,1,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,1,1,0,0,0,0},

    };

    //création de la grille
    while (1) {
        //mise en place des lignes sauf celle du haut (une ligne = 41 "=").
        system("cls");
        printf("  1   2   3   4   5   6   7   8   9   10\n");
        for (int lignes = 0; lignes < 41; ++lignes) {
            printf("=");
        }
        //mise en place de la ligne du haut
        printf("\n");
        for (int ligneDuDessus = 0; ligneDuDessus < 10; ++ligneDuDessus) {
            for (int j = 0; j < 10; ++j) {
                if (grille1[ligneDuDessus][j] == 0 || grille1[ligneDuDessus][j] == 1) {
                    printf("| ^ ");
                }
                if (grille1[ligneDuDessus][j] == 2) {
                    printf("| X ");
                }
            }

            //mise en place des colonnes
            printf("|\n");
            for (int colonnes = 0; colonnes < 41; ++colonnes) {
                printf("=");
            }
            printf("\n");
        }
        //Tans que les valeur des coordonnées ne sont pas entre 1-10, le programme repose les questions.
        do {
        printf("\nEntrez votre ligne : ");
        scanf("%d", &valeurligne);
        }while (valeurligne < 1 || valeurligne > 10);
        do {
        printf("\nEntrez votre colonne : ");
        scanf("%d", &valeurcolonne);
        }while (valeurcolonne < 1 || valeurcolonne > 10);
        //un tableau de en c de 10 cases va de 0-9. J'ai donc dû faire - 1 aux coordonnées entrée afin que la grille soit de 1-10.
        if (grille1[valeurligne - 1][valeurcolonne -1] == 1) {
            grille1[valeurligne -1][valeurcolonne -1] = 2;
            printf ("\n\nToucher !\n");
            //avant de redemander à l'utilisateur de nouvelles coordonnées, le programme attends 1,005s. (1005ms)
            Sleep(1005);
        } else {
            printf("\n\nA l'eau !\n");
            Sleep(1005);
        }

    }



    system("pause");
    afficherMenuPrincipal();
}
//création du menu "Aide"
void afficherAide(){
    system("cls");
    printf("\nVoici les règles : ");
    printf("Grille de jeu\n"
   "\n"
   "Grille de jeu imprimée.\n"
   "La grille est numérotée de 1 à 10 verticalement et de 1 à 10 horizontalement.\n"
   "\n"
   "\n\nRègles\n"
   "L'ennemi a une flotte composée de 5 bateaux, qui sont les suivants : \n1 porte-avion (5 cases), 1 croiseur (4 cases), 1 contre-torpilleur (3 cases), 1 sous-marin (3 cases), 1 torpilleur (2 cases).Les bateaux ne sont pas collés entre eux.\nLe joueur dois entrer des coordonnées de tire (exemple : 18) numéro de la ligne et ensuite celui de la colonne afin de potentiellement toucher/couler un bateau.\nLe but est donc de couler les bateaux adverses. Au fur et à mesure.\n"
   "Le joueur possede une nombre de tire illimité.\n"

   "\n\nMieux repérer la flotte ennemie\n"
   "Il existe une méthode pour mieux repérer la flotte ennemie : jouer ses tirs en croix. En admettant que le navire le plus petit du jeu fasse 2 cases,\nil suffit de jouer une case sur deux pour le repérer. Ce qui évite de jouer les cases qui sont entourées par vos tirs parce que vous savez qu'aucun bateau adverse ne peut s'y trouver.\nCette méthode, purement mathématique se révèle efficace."
   "\n\n");

    system("pause");
    afficherMenuPrincipal();
}


void afficherMenuPrincipal(){
    system("cls");
    int choix1;

    //tans que l'utilisateur ne rentre pas une valeur soit égale à 1 ou égale à 2, le programme efface la réponse
    do{
        system("cls");
        printf("\n\n/// Bienvenue sur cette application de bataille navale \\\\\\\n");
        printf("\n\n==========Menu principal==========\n\n");
        printf("\n1. Jouer");
        printf("\n2. Aide");
        printf("\n\nChoisissez une des propositions ci-dessus : ");
    scanf("%d", &choix1);
    } while (choix1 < 1 || choix1 > 2);



    if (choix1 == 1) {
        //affichage du menu du jeu
        printf("\n\nVous avez fait le choix 1 --> Jouer\n");
        interfaceDeJeu();



    } else if (choix1 == 2) {
        system("cls");
        //affichage du menu d'aide
        printf("\n\nVous avez fait le choix 2 --> Aide");
        printf("\n=================================\n");
        afficherAide();
        system("cls");

    }

}
int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleTitle("Bataille Navale");
    //affichage du menu principal
    system("cls"); //dès que l'utilisateur appuie sur une touche, le programme revient sur le menu principal comme au debut du lancement.
    afficherMenuPrincipal();

    return 0;
}