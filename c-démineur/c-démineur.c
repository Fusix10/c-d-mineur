#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#define n 10
#define m 10


typedef struct Case{
    int visible;
    int bombe;
    int indice;
} Case;

void Color(int couleurDuTexte, int couleurDeFond)
{
    HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H, couleurDeFond * 16 + couleurDuTexte);
}
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
void TryRevel(Case grosTableau[n][m], int i, int j)
{
    if (i < 0 || i >= n)
        return;

    if (j < 0 || j >= m)
        return;

    if (grosTableau[i][j].bombe == 1)
        return;

    if (grosTableau[i][j].visible == 1)
        return;

    if (grosTableau[i][j].indice != 0)
        return;

    grosTableau[i][j].visible = 1;

    if (grosTableau[i][j].indice == 0) {
        TryRevel(grosTableau, i - 1, j - 1);
        TryRevel(grosTableau, i - 1, j);
        TryRevel(grosTableau, i - 1, j + 1);
        TryRevel(grosTableau, i, j - 1);
        TryRevel(grosTableau, i, j + 1);
        TryRevel(grosTableau, i + 1, j - 1);
        TryRevel(grosTableau, i + 1, j + 1);
        TryRevel(grosTableau, i + 1, j);
    }
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
            if (grosTableau[i][j].bombe == 1 && grosTableau[i][j].visible == 0)
            {
                printf("[ ]");
            }
            else if (grosTableau[i][j].bombe == 1 && grosTableau[i][j].visible == 1) {
                printf("[X]");
            }
            else if (grosTableau[i][j].bombe == 0 && grosTableau[i][j].visible == 1) {
                printf("[%d]", grosTableau[i][j].indice);
            }
            else if (grosTableau[i][j].bombe == 0 && grosTableau[i][j].visible == 0) {
                printf("[ ]");
            }
        }
        Color(12, 0);
        printf("[%d]", i);
        Color(15, 0);
        printf("\n");
    }
    for (int i = 0; i < n; i++)
    {
        Color(12, 0);
        printf("[%d]", i);
        Color(15, 0);
    }
    printf("\n");
    
    int winLose;
    winLose = 2;
    while (winLose !=1 || winLose !=0 ) {
        int x; int y;
        x = 0;
        y = 0;
        printf("quel coordonée voulez vous ?\n ");
        printf("x = "); scanf_s("%d", &x);
        printf(" y = "); scanf_s("%d", &y);
        printf("Vous avez choisis x = %d y = %d\n", x, y);
        while (x >= n || y >= m || x < 0 || y < 0) {
            if (x >= n) {
                printf("votre valeur x est supérieur ou égal a %d il doit être inférieur\n", n);
                printf("quel coordonée voulez vous ?\n ");
                printf("x = "); scanf_s("%d", &x);
                printf(" y = "); scanf_s("%d", &y);
                printf("Vous avez choisis x = %d y = %d\n", x, y);
            }
            else if (x < 1) {
                printf("votre valeur x est inférieur a 0 il doit être égal ou supérieur\n");
                printf("quel coordonée voulez vous ?\n ");
                printf("x = "); scanf_s("%d", &x);
                printf(" y = "); scanf_s("%d", &y);
                printf("Vous avez choisis x = %d y = %d\n", x, y);
            }
            else if (y >= m) {
                printf("votre valeur y est supérieur ou égal a %d il doit être inférieur\n", m);
                printf("quel coordonée voulez vous ?\n ");
                printf("x = "); scanf_s("%d", &x);
                printf(" y = "); scanf_s("%d", &y);
                printf("Vous avez choisis x = %d y = %d\n", x, y);
            }
            else if (y < 1) {
                printf("votre valeur y est inférieur a 0 il doit être égal ou supérieur\n");
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
            printf("tu a déja révéler se coup \n");
        }
        else if (grosTableau[x][y].visible == 0) {
            printf("new Revel \n");
            grosTableau[x][y].visible = 1;
            if (grosTableau[x][y].indice == 0){
                TryRevel(grosTableau, x - 1, y - 1);
                TryRevel(grosTableau, x - 1, y);
                TryRevel(grosTableau, x - 1, y + 1);
                TryRevel(grosTableau, x, y - 1);
                TryRevel(grosTableau, x, y + 1);
                TryRevel(grosTableau, x + 1, y - 1);
                TryRevel(grosTableau, x + 1, y + 1);
                TryRevel(grosTableau, x + 1, y);
            }
        }
        if (grosTableau[x][y].bombe == 1) {
            printf("ta perdue CHEEEEEEH, you are dumbass noob (dumdum) \n");
            for (int i = 0; i < n; i++)
            {

                for (int j = 0; j < m; j++)
                {
                    grosTableau[i][j].visible = 1;
                    if (grosTableau[i][j].bombe == 1 && grosTableau[i][j].visible == 0)
                    {
                        printf("[ ]");
                    }
                    else if (grosTableau[i][j].bombe == 1 && grosTableau[i][j].visible == 1) {
                        printf("[X]");
                    }
                    else if (grosTableau[i][j].bombe == 0 && grosTableau[i][j].visible == 1) {
                        printf("[%d]", grosTableau[i][j].indice);
                    }
                    else if (grosTableau[i][j].bombe == 0 && grosTableau[i][j].visible == 0) {
                        printf("[ ]");
                    }
                }
                Color(12, 0);
                printf("[%d]", i);
                Color(15, 0);
                printf("\n");
            }
            for (int i = 0; i < n; i++)
            {
                Color(12, 0);
                printf("[%d]", i);
                Color(15, 0);
            }
            printf("\n");
            winLose = 0;
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
                    printf("[%d]", grosTableau[i][j].indice);
                }
                else if (grosTableau[i][j].bombe == 0 && grosTableau[i][j].visible == 0) {
                    printf("[ ]");
                }
            }
            Color(12, 0);
            printf("[%d]", i);
            Color(15, 0);
            printf("\n");
        }
        for (int i = 0; i < n; i++)
        {
            Color(12, 0);
            printf("[%d]", i);
            Color(15, 0);
        }
        printf("\n");
        if (winLose == 0) {
            printf("\n dommage ta perde");
            return 0;
        }
    }
    return 0;
}
