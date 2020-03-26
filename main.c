/*
 * projet : bataille navale
 * version : 1.0
 * auteur : Luca Gatto
 * desciption : Projet bataille navale dans le cadre d'un test.
 * Date : 23.03.2020
 */
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
//création du menu principal
void afficherMenuPrincipal();
void afficherPlanJeu ( int tableau [10] [10]);
void interfaceDeJeu();
void afficherAide();
void nettoieScanf ();


int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleTitle("Bataille Navale");
    //affichage du menu principal
    system("cls"); //dès que l'utilisateur appuie sur une touche, le programme revient sur le menu principal comme au debut du lancement.
    afficherMenuPrincipal();

    return 0;
}

//création de l'interface du jeu
void interfaceDeJeu(){
    system("cls");
    char valeurcolonne = 0;
    int valeurligne;
    int coordonnees;
    int sousmarin1Coule = 0, sousmarin2Coule = 0, torpilleurCoule = 0, porteAvionCoule = 0, croiseurCoule = 0;
   

    //création du tableau et positionnement des bateaux.
    int grille1 [10] [10]= {0};
    //sous-marin 1
    grille1 [2][3] = 1;
    grille1 [2][4] = 1;
    grille1 [2][5] = 1;
    //sous-marin 2
    grille1 [4][7] = 1;
    grille1 [5][7] = 1;
    grille1 [6][7] = 1;
    //Croiseur
    grille1 [1][1] = 1;
    grille1 [1][2] = 1;
    grille1 [1][3] = 1;
    grille1 [1][4] = 1;

    //porte-avion
    grille1 [9] [1] = 1;
    grille1 [9] [2] = 1;
    grille1 [9] [3] = 1;
    grille1 [9] [4] = 1;
    grille1 [9] [5] = 1;

    //torpilleur
    grille1 [1] [9] = 1;
    grille1 [2] [9] = 1;


    do{
        afficherPlanJeu(grille1);
        //Tans que les valeur des coordonnées ne sont pas entre 1-10, le programme repose les questions.
        do {
            printf("\n\nEntrez ci-dessous vos coordonées  (ex : 1A)\n\nEntrez votre ligne (1 - 10): ");
            scanf("%d", &valeurligne);
            nettoieScanf();
        } while (valeurligne < 1 || valeurligne > 10);
        do {
            printf("\nEntrez votre colonne (A - J) : ");
            scanf("%c", &valeurcolonne);
            nettoieScanf();
        } while (valeurcolonne < 65 || valeurcolonne > (65 + 10));

//un tableau de en c de 10 cases va de 0-9. J'ai donc dû faire - 1 aux coordonnées entrée afin que la grille soit de 1-10.
        if (grille1[valeurligne - 1][valeurcolonne - 65] == 1) {
            grille1[valeurligne - 1][valeurcolonne - 65] = 2;
            printf("\n\nToucher !\n");
//avant de redemander à l'utilisateur de nouvelles coordonnées, le programme attends 1,005s. (1005ms)
            Sleep(1005);
        }
        if (grille1[valeurligne - 1][valeurcolonne - 65] == 0) {
            grille1[valeurligne - 1][valeurcolonne - 65] = 3;
            printf("\n\nA l'eau !\n");
            Sleep(1005);
        }
        if (grille1 [2][3] = 2 && grille1 [2][4] == 2 && grille1 [2][5] == 2)
        {
            //sous-marin 1
            grille1 [2][3] = 4;
            grille1 [2][4] = 4;
            grille1 [2][5] = 4;
            sousmarin1Coule = 1;
        }
        if (grille1 [4][7] == 2 && grille1 [5][7] == 2 && grille1 [6][7] == 2)
        {
            //sous-marin 2
            grille1 [4][7] = 4;
            grille1 [5][7] = 4;
            grille1 [6][7] = 4;
            sousmarin2Coule = 1;
        }
        if (grille1 [1][1] == 2 && grille1 [1][2] == 2 && grille1 [1][3] == 2 && grille1 [1][4] == 2)
        {
            //croiseur
            grille1 [1][1] = 4;
            grille1 [1][2] = 4;
            grille1 [1][3] = 4;
            grille1 [1][4] = 4;
            croiseurCoule = 1;
        }
        if (grille1 [9] [1] == 2 && grille1 [9] [2] == 2 && grille1 [9] [3] == 2 && grille1 [9] [4] == 2 && grille1 [9] [5] == 2)
        {
            //porte-avion
            grille1 [9] [1] = 4;
            grille1 [9] [2] = 4;
            grille1 [9] [3] = 4;
            grille1 [9] [4] = 4;
            grille1 [9] [5] = 4;
            porteAvionCoule = 1;
        }
        if (grille1 [1] [9] == 2 && grille1 [2] [9] == 2)
        {
            //torpilleur
            grille1 [1] [9] = 4;
            grille1 [2] [9] = 4;
            torpilleurCoule = 1;
        }
    }
    while (!(torpilleurCoule == 1 && croiseurCoule ==1 && sousmarin1Coule == 1 && sousmarin2Coule == 1 && porteAvionCoule == 1));
    printf ("Tous les bateaux sont coulés, Gagné\n\n");


    system("pause");







}


void afficherMenuPrincipal() {

    system("cls");
    int choix1;

    //tans que l'utilisateur ne rentre pas une valeur soit égale à 1 ou égale à 2, le programme efface la réponse
    do {
        system("cls");
        printf("\n\n/// Bienvenue sur cette application de bataille navale \\\\\\\n");
        printf("\n\n======================Menu principal======================\n\n");
        printf("\n\n1. Jouer");
        printf("\n2. Aide");
        printf("\n\nChoisissez une des propositions ci-dessus : ");
        scanf("%d", &choix1);
        nettoieScanf();
    } while (choix1 < 1 || choix1 > 2);


    switch (choix1)
    {
        case 1:
            //affichage du menu du jeu
            printf("\n\nVous avez fait le choix 1 --> Jouer\n");
            interfaceDeJeu();
            break;
        case 2:
            system("cls");
            //affichage du menu d'aide
            printf("\n\nVous avez fait le choix 2 --> Aide");
            printf("\n=================================\n");
            afficherAide();
            system("cls");
            break;
        default:
            printf("Aïe, il y a eu une erreur, veuillez redémarrer le programme !");
            break;
    }
}

//création du menu "Aide"
void afficherAide()
{
    system("cls");
    printf("\nVoici les règles : ");
    printf("Grille de jeu\n"
           "\n"
           "Grille de jeu imprimée.\n"
           "La grille est numérotée de 1 à 10 verticalement et de A à J horizontalement.\n"
           "\n"
           "\n\nRègles\n"
           "L'ennemi a une flotte composée de 5 bateaux, qui sont les suivants : \n1 porte-avion (5 cases), 1 croiseur (4 cases), 1 contre-torpilleur (3 cases), 1 sous-marin (3 cases), 1 torpilleur (2 cases).Les bateaux ne sont pas collés entre eux.\nLe joueur dois entrer des coordonnées de tire (exemple : 1A) numéro de la ligne et ensuite celui de la colonne afin de potentiellement toucher/couler un bateau.\nLe but est donc de couler les bateaux adverses. Au fur et à mesure.\n"
           "Le joueur possede une nombre de tire illimité. "
           "Quand le joueur parviens à toucher un bateau ennemi, la case affichera un X. Si le tire tombe à l'eau, la case affichera un 0.\nDès que un bâteau est coulé, les cases où est positionné le bâteau afficheront ◙. \n"

           "\n\nMieux repérer la flotte ennemie\n"
           "Il existe une méthode pour mieux repérer la flotte ennemie : jouer ses tirs en croix. En admettant que le navire le plus petit du jeu fasse 2 cases,\nil suffit de jouer une case sur deux pour le repérer. Ce qui évite de jouer les cases qui sont entourées par vos tirs parce que vous savez qu'aucun bateau adverse ne peut s'y trouver.\nCette méthode, purement mathématique se révèle efficace."
           "\n\n");

    system("pause");
    afficherMenuPrincipal();
}
void afficherPlanJeu ( int  tableau [10] [10])
{
    //mise en place des lignes sauf celle du haut (une ligne = 41 "=").
    system("cls");
    printf("     A   B   C   D   E   F   G   H   I   J\n");
    printf("   ");
    for (int lignes = 0; lignes < 41; ++lignes) {
        printf("=");
    }
    //mise en place de la ligne du haut
    printf("\n");
    for (int ligneDuDessus = 0; ligneDuDessus < 10; ++ligneDuDessus) {
        printf("%3d", ligneDuDessus + 1);
        for (int j = 0; j < 10; ++j) {
            switch (tableau[ligneDuDessus][j])
            {
                case 0:
                    printf("|   ");
                    break;
                case 1:
                    printf("|   ");
                    break;
                case 2:
                    printf("| X ");
                    break;
                case 3:
                    printf("| 0 ");
                    break;
                case 4 :
                    printf("| ◙ ");
                    break;
            }

        }
        printf("|\n");
        printf("   ");
        for (int colonnes = 0; colonnes < 41; ++colonnes) printf("=");
        printf("\n");
    }
    printf("\n");
}
void nettoieScanf ()
{
    //variable uniquement temporaire, aucune autre utilité
    int voider;
    //stocke ce qui se trouve dans le scanf et remplace son contenu par "rien"
    while((voider=getchar()) != EOF && voider != '\n');
}