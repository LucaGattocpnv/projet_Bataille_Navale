#include <stdio.h>
#include <windows.h>
#include <stdlib.h>


int main() {
    SetConsoleOutputCP(CP_UTF8);

    int choix1;
    int coordonnees;
    int choix2;
    int choix3 = 0;



    //création du menu principal

    LOOP:
    printf("\n\n/// Bienvenu sur cette application de bataille navale \\\\\\\n");
    printf("\n\n==========Menu principal==========\n\n");
    printf("Choisissez une des propositions suivantes : ");
    printf("\n1. Jouer");
    printf("\n2. Aide");
    scanf("%d", &choix1);
    SetConsoleTitle("Bataille Navale");


    if (choix1 == 1) {
        //création du menu du jeu
        printf("Vous avez fait le choix 1 --> Jouer\n");
        printf("===================================");
        printf("\n\nCoulez tous les bateaux ennemis et un minimum de tires !");
        printf("\n=================================\n");
        printf("\nBonne chance capitaine ! ");
        printf("\n=================================\n");
        printf("\nVoici la grille de jeu : 10 x 10 cases");
        printf("\n=================================\n");
        printf("\nEntrez ci-dessous vos coordonées (ex : B8):");
        scanf("%d", coordonnees);


    } else if (choix1 == 2) {
        //création du menu d'aide
        printf("\n\nVous avez fait le choix 2 --> Aide");
        printf("\n=================================\n");
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
        goto LOOP;





    }
return 0;

}