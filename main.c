#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
//création du menu principal
void afficherMenuPrincipal();

//création de l'interface du jeu
void interfaceDeJeu(){
    system("cls");
    int coordonnees;
    printf("\nVoici la grille de jeu : 10 x 10 cases");
    printf("\nEntrez ci-dessous vos coordonées  (ex : 18):\n\n");
    printf("  1   2   3   4   5   6   7   8   9   10\n");
    int grille1 [10] [10] = {
            {0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,1,1,1},
            {0,0,0,0,0,0,0,0,0,0},
            {1,1,1,1,1,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,1,1,1,1},
            {0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,1,1,0,0,0,0},

    };
    //création de la grille

    //mise en place des lignes sauf celle du haut (une ligne = 41 "=").
    for (int lignes = 0; lignes < 41; ++lignes) {
        printf("=");
    }
    //mise en place de la ligne du haut
    printf("\n");
    for (int ligneDuDessus = 0; ligneDuDessus < 10; ++ligneDuDessus) {
        for (int j = 0; j < 10; ++j) {
            printf("| %d ", grille1[ligneDuDessus][j]);
        }
        //mise en place des colonnes
        printf("|\n");
        for (int colonnes = 0; colonnes < 41; ++colonnes) {
            printf("=");
        }
        printf("\n");
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
   "Qu'elle soit en version électronique ou non, la grille de jeu est toujours la même, numérotée de 1 à 10 verticalement et de A à J horizontalement.\n"
   "\n"
   "Conventionnellement, les joueurs placent des pions blancs sur la grille lorsque les coordonnées n'ont pas touché de bateau adverse, et rouge lorsqu'une\n touche a été faite."
   "\n"
   "\n\nMieux repérer la flotte ennemie\n"
   "Il existe une méthode pour mieux repérer la flotte ennemie : jouer ses tirs en croix. En admettant que le navire le plus petit du jeu fasse 2 cases,\n il suffit de jouer une case sur deux pour le repérer. Ce qui évite de jouer les cases qui sont entourées par vos tirs parce que vous savez qu'aucun bateau adverse ne peut s'y trouver.\n Cette méthode, purement mathématique se révèle efficace."
   "\n"
   "\n\nRègles\n"
   "La bataille navale oppose deux joueurs qui s'affrontent. Chacun a une flotte composée de 5 bateaux, qui sont, en général les suivants : 1 porte-avion (5 cases), 1 croiseur (4 cases), 1 contre-torpilleur (3 cases), 1 sous-marin (3 cases), 1 torpilleur (2 cases).Les bateaux ne doivent pas être collés entre eux. Au début du jeu, chaque joueur place ses bateaux sur sa grille. Celle-ci est toujours numérotée de 1 à 10 verticalement et de A à J horizontalement. Un à un, les joueurs vont \"tirer\" sur une case de l'adversaire : par exemple, B.3 ou encore H.8. Le but est donc de couler les bateaux \nadverses. Au fur et à mesure, il faut mettre les pions sur sa propre grille afin de se souvenir de ses tirs passés.\n"
   "\n"
   "\nUn fonctionnement plus sophistiqué mettant en œuvre de la stratégie est de tirer une salve (trois coups par exemple) et de donner le résultat global de la salve.\n\n");
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