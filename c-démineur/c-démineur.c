#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define n 10
#define m 10


typedef struct Case{
    int visible;
    int bombe;
    int indice;
    int choix;
} Case;

void TryAdd1(Case grosTableau[n][m], int i, int j)
{
    if (i < 0 || i >= n)
        return;

    if (j < 0 || j >= m)
        return;

    if (grosTableau[i][j].bombe == 1)
        return;

    grosTableau[i][j].indice += 1;
}

int main()
{   
    srand(time(NULL));

    Case grosTableau[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            grosTableau[i][j].bombe = 0;
            grosTableau[i][j].visible = 0;
            grosTableau[i][j].indice = 0;
            grosTableau[i][j].choix = 0;
        }
    }
    
    int u = 0;
    while (u != n * m / 10) {
        grosTableau[rand() % n][rand() % m].bombe = 1;
        u += 1;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grosTableau[i][j].bombe == 1)
            {
                TryAdd1(grosTableau, i - 1, j - 1);
                TryAdd1(grosTableau, i - 1, j);
                TryAdd1(grosTableau, i - 1, j + 1);
                TryAdd1(grosTableau, i, j - 1);
                TryAdd1(grosTableau, i, j + 1);
                TryAdd1(grosTableau, i + 1, j - 1);
                TryAdd1(grosTableau, i + 1, j + 1);
                TryAdd1(grosTableau, i + 1, j);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grosTableau[i][j].bombe == 1 && grosTableau[i][j].visible == 0 && grosTableau[i][j].choix == 0;)
            {
                printf("[ ]");
            }
            else if (grosTableau[i][j].bombe == 1 && grosTableau[i][j].visible == 1 && grosTableau[i][j].choix == 0;) {
                printf("[X]");
            }
            else if (grosTableau[i][j].bombe == 0 && grosTableau[i][j].visible == 1 && grosTableau[i][j].choix == 0;) {
                printf("[%d]",grosTableau[i][j].indice);
            }
            else if (grosTableau[i][j].bombe == 0 && grosTableau[i][j].visible == 0 && grosTableau[i][j].choix == 0;) {
                printf("[ ]");
            }
            else if (grosTableau[i][j].bombe == 0 && grosTableau[i][j].visible == 0 && grosTableau[i][j].choix == 1;) {
                printf("[#]");
            }
            else if (grosTableau[i][j].bombe == 1 && grosTableau[i][j].visible == 1 && grosTableau[i][j].choix == 1;) {
                printf("[D]");
            }
        }
        printf("\n");
    }
    int winLose;
    int* choix;
    winLose = 0;
    while (winLose !=1 || winLose !=0 ) {
        int x; int y;
        x = 0;
        y = 0;
        printf("quel coordonée voulez vous ?\n ");
        printf("x = "); scanf_s("%d", &x);
        printf(" y = "); scanf_s("%d", &y);
        printf("Vous avez choisis x = %d y = %d\ Que voulez-vous faire ?\n", x, y);
        printf("\t1. Decouvrir une case\n");
        printf("\t2. Placer un drapeau");
        printf("\t\tVotre choix : ");
        scanf_s("%d", &choix);
        


        while (x >= 10 || y >= 10 || x < 0 || y < 0) {
            if (x >= n) {
                printf("votre valeur x est supérieur ou égal a 10 il doit être inférieur");
                printf("quel coordonée voulez vous ?\n ");
                printf("x = "); scanf_s("%d", &x);
                printf(" y = "); scanf_s("%d", &y);
                printf("Vous avez choisis x = %d y = %d\ Que voulez-vous faire ?\n", x, y);
                printf("\t1. Decouvrir une case\n");
                printf("\t2. Placer un drapeau");
                printf("\t\tVotre choix : ");
                scanf_s("%d", &choix);
            }
            else if (x < 0) {
                printf("votre valeur x est inférieur a 0 il doit être égal ou supérieur");
                printf("quel coordonée voulez vous ?\n ");
                printf("x = "); scanf_s("%d", &x);
                printf(" y = "); scanf_s("%d", &y);
                printf("Vous avez choisis x = %d y = %d\ Que voulez-vous faire ?\n", x, y);
                printf("\t1. Decouvrir une case\n");
                printf("\t2. Placer un drapeau");
                printf("\t\tVotre choix : ");
                scanf_s("%d", &choix);
            }
            else if (y >= m) {
                printf("votre valeur y est supérieur ou égal a 10 il doit être inférieur");
                printf("quel coordonée voulez vous ?\n ");
                printf("x = "); scanf_s("%d", &x);
                printf(" y = "); scanf_s("%d", &y);
                printf("Vous avez choisis x = %d y = %d\ Que voulez-vous faire ?\n", x, y);
                printf("\t1. Decouvrir une case\n");
                printf("\t2. Placer un drapeau");
                printf("\t\tVotre choix : ");
                scanf_s("%d", &choix);
            }
            else if (y < 0) {
                printf("votre valeur y est inférieur a 0 il doit être égal ou supérieur");
                printf("quel coordonée voulez vous ?\n ");
                printf("x = "); scanf_s("%d", &x);
                printf(" y = "); scanf_s("%d", &y);
                printf("Vous avez choisis x = %d y = %d\ Que voulez-vous faire ?\n", x, y);
                printf("\t1. Decouvrir une case\n");
                printf("\t2. Placer un drapeau");
                printf("\t\tVotre choix : ");
                scanf_s("%d", &choix);
            }
            else {
                break;
            }
        }
        if (grosTableau[x][y].visible == 1) {
            printf("tu a déja reveler se coup \n");
        }
        else if (grosTableau[x][y].visible == 0) {
            printf("new Revel \n");
            grosTableau[x][y].visible = 1;
        }
        if (grosTableau[x][y].choix == 1) {
             printf("tu place un drapeau ? du coup tu peut etre trouvé une bombe ?\n")
                 for (int i = 0; i < n; i++)
                 {
                     for (int j = 0; j < m; j++)
                     {
                         grosTableau[i][j].visible = 1;
                         if (grosTableau[i][j].bombe == 1 && grosTableau[i][j].visible == 0 && grosTableau[i][j].choix == 0;)
                         {
                             printf("[ ]");
                         }
                         else if (grosTableau[i][j].bombe == 1 && grosTableau[i][j].visible == 1 && grosTableau[i][j].choix == 0;) {
                             printf("[X]");
                         }
                         else if (grosTableau[i][j].bombe == 0 && grosTableau[i][j].visible == 1 && grosTableau[i][j].choix == 0;) {
                             printf("[%d]", grosTableau[i][j].indice);
                         }
                         else if (grosTableau[i][j].bombe == 0 && grosTableau[i][j].visible == 0 && grosTableau[i][j].choix == 0;) {
                             printf("[ ]");
                         }
                         else if (grosTableau[i][j].bombe == 0 && grosTableau[i][j].visible == 0 && grosTableau[i][j].choix == 1;) {
                             printf("[#]");
                         }
                         else if (grosTableau[i][j].bombe == 1 && grosTableau[i][j].visible == 1 && grosTableau[i][j].choix == 1;) {
                             printf("[D]");
                         }

                     }
                 printf("\n");
        }
        if (grosTableau[x][y].bombe == 1) {
            printf("BOOM t'a perdue dommage, \n");
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    grosTableau[i][j].visible = 1;
                    if (grosTableau[i][j].bombe == 1 && grosTableau[i][j].visible == 0 && grosTableau[i][j].choix == 0;)
                    {
                        printf("[ ]");
                    }
                    else if (grosTableau[i][j].bombe == 1 && grosTableau[i][j].visible == 1 && grosTableau[i][j].choix == 0;) {
                        printf("[X]");
                    }
                    else if (grosTableau[i][j].bombe == 0 && grosTableau[i][j].visible == 1 && grosTableau[i][j].choix == 0;) {
                        printf("[%d]", grosTableau[i][j].indice);
                    }
                    else if (grosTableau[i][j].bombe == 0 && grosTableau[i][j].visible == 0 && grosTableau[i][j].choix == 0;) {
                        printf("[ ]");
                    }
                    else if (grosTableau[i][j].bombe == 0 && grosTableau[i][j].visible == 0 && grosTableau[i][j].choix == 1;) {
                        printf("[#]");
                    }
                    else if (grosTableau[i][j].bombe == 1 && grosTableau[i][j].visible == 1 && grosTableau[i][j].choix == 1;) {
                        printf("[D]");
                    }

                }
                printf("\n");
            }
            break;
        }
        else if (grosTableau[x][y].bombe == 0) {
            printf("pas de bombe ici \n");
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grosTableau[i][j].bombe == 1 && grosTableau[i][j].visible == 0 && grosTableau[i][j].choix == 0;)
                {
                    printf("[ ]");
                }
                else if (grosTableau[i][j].bombe == 1 && grosTableau[i][j].visible == 1 && grosTableau[i][j].choix == 0;) {
                    printf("[X]");
                }
                else if (grosTableau[i][j].bombe == 0 && grosTableau[i][j].visible == 1 && grosTableau[i][j].choix == 0;) {
                    printf("[%d]", grosTableau[i][j].indice);
                }
                else if (grosTableau[i][j].bombe == 0 && grosTableau[i][j].visible == 0 && grosTableau[i][j].choix == 0;) {
                    printf("[ ]");
                }
                else if (grosTableau[i][j].bombe == 0 && grosTableau[i][j].visible == 0 && grosTableau[i][j].choix == 1;) {
                    printf("[#]");
                }
                else if (grosTableau[i][j].bombe == 1 && grosTableau[i][j].visible == 1 && grosTableau[i][j].choix == 1;) {
                    printf("[D]");
                }
                
            }
            printf("\n");
        }
    }
    return 0;
}
