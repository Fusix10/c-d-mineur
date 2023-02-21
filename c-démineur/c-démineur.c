#include <stdio.h>

#define n 10
#define m 10


typedef struct Case{
    int visible;
    int bombe;
} Case;

int main()
{
    Case grosTableau[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            grosTableau[i][j].bombe = 0;
            grosTableau[i][j].visible = 0;
        }
    }
    
    grosTableau[0][0].bombe = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grosTableau[i][j].bombe == 1 && grosTableau[i][j].visible == 0)
            {
                printf("[ ]");
            }
            else if (grosTableau[i][j].bombe == 1 && grosTableau[i][j].visible == 1) {
                printf("[X]");
            }
            else if (grosTableau[i][j].bombe == 0 && grosTableau[i][j].visible == 1) {
                printf("[0]");
            }
            else if (grosTableau[i][j].bombe == 0 && grosTableau[i][j].visible == 0) {
                printf("[ ]");
            }
        }
        printf("\n");
    }
    int winLose;
    winLose = 0;
    while (winLose !=1 || winLose !=0 ) {
        int x; int y;
        x = 0;
        y = 0;
        printf("quel coordonée voulez vous ?\n ");
        printf("x = "); scanf_s("%d", &x);
        printf(" y = "); scanf_s("%d", &y);
        printf("Vous avez choisis x = %d y = %d\n", x, y);
        while (x >= 10 || y >= 10 || x < 0 || y < 0) {
            if (x >= 10) {
                printf("votre valeur x est supérieur ou égal a 10 il doit être inférieur");
                printf("quel coordonée voulez vous ?\n ");
                printf("x = "); scanf_s("%d", &x);
                printf(" y = "); scanf_s("%d", &y);
                printf("Vous avez choisis x = %d y = %d\n", x, y);
            }
            else if (x < 0) {
                printf("votre valeur x est inférieur a 0 il doit être égal ou supérieur");
                printf("quel coordonée voulez vous ?\n ");
                printf("x = "); scanf_s("%d", &x);
                printf(" y = "); scanf_s("%d", &y);
                printf("Vous avez choisis x = %d y = %d\n", x, y);
            }
            else if (y >= 10) {
                printf("votre valeur y est supérieur ou égal a 10 il doit être inférieur");
                printf("quel coordonée voulez vous ?\n ");
                printf("x = "); scanf_s("%d", &x);
                printf(" y = "); scanf_s("%d", &y);
                printf("Vous avez choisis x = %d y = %d\n", x, y);
            }
            else if (y < 0) {
                printf("votre valeur y est inférieur a 0 il doit être égal ou supérieur");
                printf("quel coordonée voulez vous ?\n ");
                printf("x = "); scanf_s("%d", &x);
                printf(" y = "); scanf_s("%d", &y);
                printf("Vous avez choisis x = %d y = %d\n", x, y);
            }
            else {
                break;
            }
        }
        if (grosTableau[x][y].visible == 1) {
            printf("tu a déja révéler se coup");
        }
        else if (grosTableau[x][y].visible == 0) {
            printf("new Revel");
            grosTableau[x][y].visible == 1;
        }
        if (grosTableau[x][y].bombe == 1) {
            printf("ta perdue CHEEEEEEH \n");
            break;
        }
        else if (grosTableau[x][y].bombe == 0) {
            printf("chanceux je pari ta fait au pif \n");
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grosTableau[i][j].bombe == 1 && grosTableau[i][j].visible == 0)
                {
                    printf("[ ]");
                }
                else if (grosTableau[i][j].bombe == 1 && grosTableau[i][j].visible == 1) {
                    printf("[X]");
                }
                else if (grosTableau[i][j].bombe == 0 && grosTableau[i][j].visible == 1) {
                    printf("[0]");
                }
                else if (grosTableau[i][j].bombe == 0 && grosTableau[i][j].visible == 0) {
                    printf("[ ]");
                }
                printf("$d", grosTableau[i][j].visible);
            }
            printf("\n");
        }
    }
    return 0;
}
