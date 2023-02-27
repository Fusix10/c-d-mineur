#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#define n 5
#define m 5

void draw(grosTableau);
typedef struct Case{
    int visible;
    int bombe;
    int indice;
    int flag;
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
    int n;
    int m;
    scanf("%d", n);
    scanf("%d", m);
    int* tab1 = malloc(sizeof(int) * n);
    int** tab2 = malloc(sizeof(int*) * m);
    tab2[]
    srand(time(NULL));

    Case grosTableau[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            grosTableau[i][j].bombe = 0;
            grosTableau[i][j].visible = 0;
            grosTableau[i][j].indice = 0;
            grosTableau[i][j].flag = 0;
        }
    }

    int nbBombe = (n * m) / 10;
    for (int i = 0; i < nbBombe; i++){
        int a; int b;
        a = rand() % n;
        b = rand() % m;
        while (grosTableau[a][b].bombe == 1) {
            a = rand() % n;
            b = rand() % m;
        }
        grosTableau[a][b].bombe = 1;
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
    draw(grosTableau);
    int winLose;
    winLose = 2;
    int winQ;
    winQ = 0;
    while (winLose !=1 && winLose !=0 ) {
        int x; int y; int RorF;
        x = 0;
        y = 0;
        RorF = 0;
        printf("tout dabord voulez vous flag ? ou Revel une case ? \n");
        printf("1 = Revel une case, 2 = flag une case \n");
        printf("vous voulez : "); scanf_s("%d", &RorF);
        while (RorF != 1 && RorF != 2) {
            printf("ha vous avez missclique peut être ?\n");
            printf("vous venez de donner un résulta incorrecte ! veuillez recommençais !\n");
            printf("1 = Revel une case, 2 = flag une case \n");
            printf("vous voulez : "); scanf_s("%d ", &RorF);
        }
        if (RorF == 1) {
            printf("\nquel coordonné voulez vous ?\n ");
            printf("x = "); scanf_s("%d", &x);
            printf(" y = "); scanf_s("%d", &y);
            printf("Vous avez choisis x = %d y = %d\n", x, y);
            while (x >= n || y >= m || x < 0 || y < 0) {
                if (x >= n) {
                    printf("votre valeur x est supérieur ou égal a %d il doit être inférieur\n", n);
                    printf("quel coordonné voulez vous ?\n ");
                    printf("x = "); scanf_s("%d", &x);
                    printf(" y = "); scanf_s("%d", &y);
                    printf("Vous avez choisis x = %d y = %d\n", x, y);
                }
                else if (x < 1) {
                    printf("votre valeur x est inférieur a 0 il doit être égal ou supérieur\n");
                    printf("quel coordonné voulez vous ?\n ");
                    printf("x = "); scanf_s("%d", &x);
                    printf(" y = "); scanf_s("%d", &y);
                    printf("Vous avez choisis x = %d y = %d\n", x, y);
                }
                else if (y >= m) {
                    printf("votre valeur y est supérieur ou égal a %d il doit être inférieur\n", m);
                    printf("quel coordonné voulez vous ?\n ");
                    printf("x = "); scanf_s("%d", &x);
                    printf(" y = "); scanf_s("%d", &y);
                    printf("Vous avez choisis x = %d y = %d\n", x, y);
                }
                else if (y < 1) {
                    printf("votre valeur y est inférieur a 0 il doit être égal ou supérieur\n");
                    printf("quel coordonné voulez vous ?\n ");
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
                if (grosTableau[x][y].indice == 0) {
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
            if (grosTableau[x][y].flag == 1)
            {
                printf("vous avez flag cette endroit vous ne pouvez donc pas la revel !");
            }
            else if (grosTableau[x][y].bombe == 1 && grosTableau[x][y].flag != 1) {
                printf("ta perdue CHEEEEEEH, you are dumbass noob (dumdum) \n");
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < m; j++)
                    {
                        grosTableau[i][j].visible = 1;
                    }
                }
                draw(grosTableau);
                winLose = 0;
                break;
            }
            else if (grosTableau[x][y].bombe == 0 && grosTableau[x][y].flag != 1) {
                printf("chanceux je pari ta fait au pif \n");
            }
            draw(grosTableau);
            if (winLose == 0) {
                printf("\n dommage ta perde");
                return 0;
            }
        }
        else{
            printf("quelle case voulez vous flag ?\n");
            printf("écriver les coordoner voulu :\n ");
            printf("x = "); scanf_s("%d", &x);
            printf(" y = "); scanf_s("%d", &y);
            printf("Vous avez choisis x = %d y = %d\n", x, y);
            while (x >= n || y >= m || x < 0 || y < 0) {
                if (x >= n) {
                    printf("votre valeur x est supérieur ou égal a %d il doit être inférieur\n", n);
                    printf("quel coordonné voulez vous ?\n ");
                    printf("x = "); scanf_s("%d", &x);
                    printf(" y = "); scanf_s("%d", &y);
                    printf("Vous avez choisis x = %d y = %d\n", x, y);
                }
                else if (x < 1) {
                    printf("votre valeur x est inférieur a 0 il doit être égal ou supérieur\n");
                    printf("quel coordonné voulez vous ?\n ");
                    printf("x = "); scanf_s("%d", &x);
                    printf(" y = "); scanf_s("%d", &y);
                    printf("Vous avez choisis x = %d y = %d\n", x, y);
                }
                else if (y >= m) {
                    printf("votre valeur y est supérieur ou égal a %d il doit être inférieur\n", m);
                    printf("quel coordonné voulez vous ?\n ");
                    printf("x = "); scanf_s("%d", &x);
                    printf(" y = "); scanf_s("%d", &y);
                    printf("Vous avez choisis x = %d y = %d\n", x, y);
                }
                else if (y < 1) {
                    printf("votre valeur y est inférieur a 0 il doit être égal ou supérieur\n");
                    printf("quel coordonné voulez vous ?\n ");
                    printf("x = "); scanf_s("%d", &x);
                    printf(" y = "); scanf_s("%d", &y);
                    printf("Vous avez choisis x = %d y = %d\n", x, y);
                }
                else {
                    break;
                }
            }
            if (grosTableau[x][y].flag == 1) {
                printf("tu a déja mi un flag ici \n");
            }
            else if (grosTableau[x][y].flag == 0) {
                grosTableau[x][y].flag = 1;
            }
            if (grosTableau[x][y].bombe == 0 && grosTableau[x][y].flag == 1) {
                for (int i = 0; i < n; i++)
                {

                    for (int j = 0; j < m; j++)
                    {
                        grosTableau[i][j].visible = 1;
                    }
                }
                draw(grosTableau);
                winLose = 0;
                break;
            }
            if (grosTableau[x][y].bombe == 1 && grosTableau[x][y].flag == 1) {
                draw (grosTableau);
                winQ += 1;
            }
            printf("winQ = %d, nbBombe = %d", winQ, nbBombe);
            if (winQ == nbBombe) {
                for (int i = 0; i < n; i++)
                {

                    for (int j = 0; j < m; j++)
                    {
                        grosTableau[i][j].visible = 1;
                    }
                }
                draw(grosTableau);
                winLose = 1;
                break;
            }
        }
    }
    int restart = 0;
    if (winLose == 1) {
        printf("\n\n WOW vous avez réussie a découvrire tout les bombe GG\n\n");
        printf("veux tu rejouer ?\n");
        printf("1 = oui et 2 = non\n");
        printf("Votre choix: "); scanf_s("%d", &restart);
        while (restart != 1 && restart != 2) {
            printf("\nMon vier tu te fout de moi ? les réponse sont entre 1 et 2 d'ou tu me sort un %d\n", restart);
            printf("veux tu rejouer ?\n");
            printf("1 = oui et 2 = non\n");
            printf("Votre choix: "); scanf_s("%d", &restart);
        }
        if (restart == 1) {
            main();
        }
        else {
            return 0;
        }
    }
    else if (winLose == 0) {
        printf("\n\n ha rip tes mort x)\n\n");
        printf("veux tu rejouer ?\n");
        printf("1 = oui et 2 = non\n");
        printf("Votre choix: "); scanf_s("%d", &restart);
        while (restart != 1 && restart != 2) {
            printf("\nMon vier tu te fout de moi ? les réponse sont entre 1 et 2 d'ou tu me sort un %d\n", restart);
            printf("veux tu rejouer ?\n");
            printf("1 = oui et 2 = non\n");
            printf("Votre choix: "); scanf_s("%d", &restart);
        }
        if (restart == 1) {
            main();
        }
        else {
            return 0;
        }
    }
}
void draw(Case grosTableau[n][m])
{
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < m; j++)
        {
            if (grosTableau[i][j].flag == 1) {
                printf("[F]");
            }
            if (grosTableau[i][j].bombe == 1 && grosTableau[i][j].visible == 0 && grosTableau[i][j].flag != 1)
            {
                printf("[ ]");
            }
            else if (grosTableau[i][j].bombe == 1 && grosTableau[i][j].visible == 1 && grosTableau[i][j].flag != 1) {
                Color(4, 0);
                printf("[X]");
                Color(15, 0);
            }
            else if (grosTableau[i][j].bombe == 0 && grosTableau[i][j].visible == 1 && grosTableau[i][j].flag != 1) {
                printf("[%d]", grosTableau[i][j].indice);
            }
            else if (grosTableau[i][j].bombe == 0 && grosTableau[i][j].visible == 0 && grosTableau[i][j].flag != 1) {
                printf("[ ]");
            }
        }
        Color(3, 0);
        printf("[%d]", i);
        Color(15, 0);
        printf("\n");
    }
    for (int i = 0; i < m; i++)
    {
        Color(3, 0);
        printf("[%d]", i);
        Color(15, 0);
    }
    printf("\n");
}
/*int tg()
{
    int m = 10;
    int n = 10;

    int** t3 = malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++) {
        t3[i] = malloc(sizeof(int) * m);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            t3[i][j] = 0;
            printf("%d", t3[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        free(t3[i])
    }
    free(t3)

        return 0;
}*/
