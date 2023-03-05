#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int n = 10;
int m = 10;

typedef struct Case Case;

void flag(Case** grosTableau, int x, int y, int* nbBombe, int* winLose, int* winQ);
void draw(Case** grosTableau, Case** grosTableauTroll);

struct Case {
    int visible;
    int bombe;
    int indice;
    int flag;
};

void Color(int couleurDuTexte, int couleurDeFond)
{
    HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H, couleurDeFond * 16 + couleurDuTexte);
}

void TryAdd1(Case** grosTableau, int i, int j)
{
    if (i < 0 || i >= n)
        return;

    if (j < 0 || j >= m)
        return;

    if (grosTableau[i][j].bombe == 1)
        return;

    grosTableau[i][j].indice += 1;
}
void TryRevel(Case** grosTableau, int i, int j)
{
    if (i < 0 || i >= n)
        return;

    if (j < 0 || j >= m)
        return;

    if (grosTableau[i][j].flag == 1)
        return;

    if (grosTableau[i][j].bombe == 1)
        return;

    if (grosTableau[i][j].visible == 1)
        return;

    if (grosTableau[i][j].indice != 0) {
        grosTableau[i][j].visible = 1;
        return;
    }

    grosTableau[i][j].visible = 1;

    TryRevel(grosTableau, i - 1, j - 1);
    TryRevel(grosTableau, i - 1, j);
    TryRevel(grosTableau, i - 1, j + 1);
    TryRevel(grosTableau, i, j - 1);
    TryRevel(grosTableau, i, j + 1);
    TryRevel(grosTableau, i + 1, j - 1);
    TryRevel(grosTableau, i + 1, j + 1);
    TryRevel(grosTableau, i + 1, j);
}


void ClearBuffer() {
    char c = getchar();
    while (c != '\n') {
        c = getchar();
    }
}

int AskNumber(const char* message, int min, int max)
{
    int u = 0;
    int error = scanf_s("%d", &u);
    if (error == 0) {
        ClearBuffer();
    }
    while (error == 0 || u < min || u > max)
    {
        printf("%s", message);
        error = scanf_s("%d", &u);
        if (error == 0) {
            ClearBuffer();
        }
        printf("\n");
    }
    return u;
}

int main()
{
    int dificulte = 0;
    int start = 0;
    printf("Yo ! tu est la pour jouer au demineur ?\n");
    printf("1 = oui, 2 = oui\n");
    printf("votre choix: ");
    const char* message = "Arrete de cherche dla d stp (III)\n1 = oui, 2 = oui\nvotre choix: ";
    start = AskNumber(message, 1, 3);
    if (start == 3) {
        printf("indice : D TO T -> B TO T\n");
        printf("48 49 48 48 49 48 48 49 32 48 49 49 48 49 49 48 48 32 48 48 49 48 48 48 48 48 32 48 49 49 49 49 48 48 49 32 48 48 49 48 48 48 48 48 32 48 49 49 48 48 48 48 49 32 48 48 49 48 48 48 48 48 32 48 48 49 49 48 49 48 49 32 48 48 49 48 48 48 48 48 32 48 49 48 48 48 49 48 49 32 48 49 49 48 48 48 48 49 32 48 49 49 49 48 48 49 49 32 48 49 49 49 48 49 48 48 32 48 49 49 48 48 49 48 49 32 48 49 49 49 48 48 49 48 32 48 48 49 48 48 48 48 48 32 48 49 48 48 48 49 48 49 32 48 49 49 48 48 49 49 49 32 48 49 49 48 48 49 49 49 32 48 49 49 49 48 48 49 49 32 48 48 49 48 48 48 48 48 32 48 49 49 48 48 49 48 48 32 48 49 49 48 48 48 48 49 32 48 49 49 48 49 49 49 48 32 48 49 49 49 48 48 49 49 32 48 48 49 48 48 48 48 48 32 48 49 49 48 49 49 48 48 32 48 49 49 48 48 49 48 49 32 48 48 49 48 48 48 48 48 32 48 49 49 48 49 48 49 48 32 48 49 49 48 48 49 48 49 32 48 49 49 49 48 49 48 49 32 48 48 49 48 48 48 48 48 32 48 49 49 48 48 49 48 48 32 48 49 49 48 49 49 49 49 32 48 49 49 48 49 49 49 48 32 48 49 49 49 48 49 48 48 32 48 48 49 48 48 48 48 48 32 48 49 49 48 48 48 49 49 32 48 49 49 48 48 49 48 49 32 48 49 49 48 49 49 48 48 32 48 49 49 49 48 49 48 49 32 48 49 49 48 49 48 48 49 32 48 48 49 48 49 49 48 49 32 48 49 49 48 49 49 48 48 32 48 49 49 48 48 48 48 49 32 48 48 49 48 48 48 48 48");
        return 0;
    }
    printf("hey huu du-coup vus que j'ai la flemme de le faire pour toi TU vas chosir la taille du du demineur ! (c'est du x * y)\n");
    printf("x = "); scanf_s("%d", &n);
    printf("y = "); scanf_s("%d", &m);
    while (n <= 0 || m <= 0) {
        if (n < 0 || m < 0) {
            printf("mais...MAIS...MON VIER, TU ME MET UNE Valeur 0 OU NEGATIF TA DEJA VUS UN TABLEAU DE X = %d ET DE Y = %d\n", n, m);
        }
        if (n >= 0 && m >= 0) {
            if (n == 0 && m == 0) {
                printf("tu te rend compte que x = 0 et y = 0 c'est un tableau de RIEN genre YA RIEN tu peut meme pas VOIR le tableau je... je.... tu mes soul, pour la peine turn off\n");
                return 0;
            }
            printf("alors huuuu, 0 * n'importe quoi, sa fait 0 donc ya rien... ouai ouai c'est balo =')\n");
        }
        printf("x = "); scanf_s("%d", &n);
        printf("y = "); scanf_s("%d", &m);
    }
    printf("Quelle est ta difficulter ?");
    printf("1 = facile, 2 = normale, 3 = Difficile\n");
    printf("votre choix: ");
    message = "\nArrete de cherche dla d stp\n1 = facile, 2 = normale, 3 = Difficile\nvotre choix: ";
    dificulte = AskNumber(message, 1, 4);
    Case** grosTableau = malloc(sizeof(Case*) * n);
    Case** grosTableauTroll = NULL;
    for (int i = 0; i < n; i++) {
        grosTableau[i] = malloc(sizeof(Case) * m);
    }

    srand(time(NULL));

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
    float DifB = 0;
    if (dificulte == 1) {
        DifB = 15;
    }
    else if (dificulte == 2) {
        DifB = 10;
    }
    else if (dificulte == 3) {
        DifB = 5;
    }
    else if (dificulte == 4) {
        DifB = 5;
    }
    if (dificulte == 4) {
        grosTableauTroll = malloc(sizeof(Case*) * n);
        for (int i = 0; i < n; i++) {
            grosTableauTroll[i] = malloc(sizeof(Case) * m);
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                grosTableauTroll[i][j].bombe = 0;
                grosTableauTroll[i][j].visible = 0;
                grosTableauTroll[i][j].indice = 0;
                grosTableauTroll[i][j].flag = 0;
            }
        }
    }
    int nbBombe = ((n * m) + 5) / DifB;
    if (nbBombe < 1) {
        nbBombe = 1;
    }
    for (int i = 0; i < nbBombe; i++) {
        int a; int b;
        a = rand() % n;
        b = rand() % m;
        while (grosTableau[a][b].bombe == 1) {
            a = rand() % n;
            b = rand() % m;
        }
        grosTableau[a][b].bombe = 1;
        if (dificulte == 4) {
            a = rand() % n;
            b = rand() % m;
            while (grosTableauTroll[a][b].bombe == 1) {
                a = rand() % n;
                b = rand() % m;
            }
            grosTableauTroll[a][b].bombe = 1;
        }
    }
    if (dificulte == 4) {
        nbBombe = nbBombe * 2;
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
            if (dificulte == 4) {
                if (grosTableauTroll[i][j].bombe == 1)
                {
                    TryAdd1(grosTableauTroll, i - 1, j - 1);
                    TryAdd1(grosTableauTroll, i - 1, j);
                    TryAdd1(grosTableauTroll, i - 1, j + 1);
                    TryAdd1(grosTableauTroll, i, j - 1);
                    TryAdd1(grosTableauTroll, i, j + 1);
                    TryAdd1(grosTableauTroll, i + 1, j - 1);
                    TryAdd1(grosTableauTroll, i + 1, j + 1);
                    TryAdd1(grosTableauTroll, i + 1, j);
                }
            }
        }
    }
    int winLose;
    winLose = 2;
    int winQ;
    winQ = 0;
    while (winLose != 1 && winLose != 0) {
        draw(grosTableau, grosTableauTroll);
        int x; int y; int RorF;
        x = 0;
        y = 0;
        RorF = 0;
        printf("tout dabord voulez vous flag ? ou Revel une case ? \n");
        printf("1 = Revel une case, 2 = flag une case \n");
        printf("vous voulez : ");
        message = "ha vous avez missclique peut etre ?\nvous venez de donner un résulta incorrecte ! veuillez recommençais !\n1 = Revel une case, 2 = flag une case \nvous voulez : ";
        RorF = AskNumber(message, 1, 2);
        if (RorF == 1) {
            printf("quel coordonné voulez vous ?\n ");
            printf("x = "); scanf_s("%d", &x);
            printf(" y = "); scanf_s("%d", &y);
            printf("Vous avez choisis x = %d y = %d\n", x, y);
            while (x >= n || y >= m || x < 0 || y < 0) {
                if (x >= n) {
                    printf("votre valeur x est supérieur ou égal a %d il doit etre inférieur\n", n);
                    printf("quel coordonné voulez vous ?\n ");
                    printf("x = "); scanf_s("%d", &x);
                    printf(" y = "); scanf_s("%d", &y);
                    printf("Vous avez choisis x = %d y = %d\n", x, y);
                }
                else if (x < 1) {
                    printf("votre valeur x est inférieur a 0 il doit etre égal ou supérieur\n");
                    printf("quel coordonné voulez vous ?\n ");
                    printf("x = "); scanf_s("%d", &x);
                    printf(" y = "); scanf_s("%d", &y);
                    printf("Vous avez choisis x = %d y = %d\n", x, y);
                }
                else if (y >= m) {
                    printf("votre valeur y est supérieur ou égal a %d il doit etre inférieur\n", m);
                    printf("quel coordonné voulez vous ?\n ");
                    printf("x = "); scanf_s("%d", &x);
                    printf(" y = "); scanf_s("%d", &y);
                    printf("Vous avez choisis x = %d y = %d\n", x, y);
                }
                else if (y < 1) {
                    printf("votre valeur y est inférieur a 0 il doit etre égal ou supérieur\n");
                    printf("quel coordonné voulez vous ?\n ");
                    printf("x = "); scanf_s("%d", &x);
                    printf(" y = "); scanf_s("%d", &y);
                    printf("Vous avez choisis x = %d y = %d\n", x, y);
                }
                else {
                    break;
                }
            }
            if (dificulte != 4) {
                if (grosTableau[x][y].visible == 1) {
                    printf("tu a déja révéler se coup \n");
                }
                else {
                    printf("new Revel \n");
                    TryRevel(grosTableau, x, y);
                }
            }
            if (dificulte == 4) {
                if (grosTableau[x][y].visible == 1 && grosTableauTroll[x][m - 1 - y].visible == 1) {
                    printf("tu a déja révéler se coup \n");
                }
                else {
                    printf("new Revel \n");
                    TryRevel(grosTableau, x, y);
                    TryRevel(grosTableauTroll, x, m - 1 - y);
                }
            }
            if (dificulte != 4) {
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
                    winLose = 0;
                    break;
                }
                else if (grosTableau[x][y].bombe == 0 && grosTableau[x][y].flag != 1) {
                    printf("chanceux je pari ta fait au pif \n");
                }
            }
            else {
                if (grosTableau[x][y].flag == 1 || grosTableauTroll[x][y].flag == 1)
                {
                    printf("vous avez flag cette endroit vous ne pouvez donc pas la revel !");
                }
                else if (grosTableau[x][y].bombe == 1 && grosTableau[x][y].flag != 1 || grosTableauTroll[x][m - 1 - y].bombe == 1 && grosTableauTroll[x][m - 1 - y].flag != 1) {
                    printf("ta perdue CHEEEEEEH, you are dumbass noob (dumdum) \n");
                    for (int i = 0; i < n; i++)
                    {
                        for (int j = 0; j < m; j++)
                        {
                            grosTableau[i][j].visible = 1;
                            grosTableauTroll[i][j].visible = 1;
                        }
                    }
                    winLose = 0;
                    break;
                }
                else if (grosTableau[x][y].bombe == 0 && grosTableau[x][y].flag != 1 || grosTableauTroll[x][m - 1 - y].bombe == 0 && grosTableauTroll[x][m - 1 - y].flag != 1) {
                    printf("chanceux je pari ta fait au pif \n");
                }
            }
        }
        else {
            int GD;
            GD = 0;
            if (dificulte == 4) {

                printf("dans quelle tableau voulez vous flag ?\n");
                printf("1 = gauche, 2 = droite\n ");
                printf("Votre choix: ");
                message = "faut vraimment mais VRAIMMENT que t'arrete de tenter des chiffre impossible quand on te propose des truc\ndans quelle tableau voulez vous flag ?\n1 = gauche, 2 = droite\nVotre choix: ";
                GD = AskNumber(message, 1, 2);
            }
            printf("quelle case voulez vous flag ?\n");
            printf("écriver les coordoner voulu :\n ");
            printf("x = "); scanf_s("%d", &x);
            printf(" y = "); scanf_s("%d", &y);
            printf("Vous avez choisis x = %d y = %d\n", x, y);
            while (x >= n || y >= m || x < 0 || y < 0) {
                if (x >= n) {
                    printf("votre valeur x est supérieur ou égal a %d il doit etre inférieur\n", n);
                    printf("quel coordonné voulez vous ?\n ");
                    printf("x = "); scanf_s("%d", &x);
                    printf(" y = "); scanf_s("%d", &y);
                    printf("Vous avez choisis x = %d y = %d\n", x, y);
                }
                else if (x < 1) {
                    printf("votre valeur x est inférieur a 0 il doit etre égal ou supérieur\n");
                    printf("quel coordonné voulez vous ?\n ");
                    printf("x = "); scanf_s("%d", &x);
                    printf(" y = "); scanf_s("%d", &y);
                    printf("Vous avez choisis x = %d y = %d\n", x, y);
                }
                else if (y >= m) {
                    printf("votre valeur y est supérieur ou égal a %d il doit etre inférieur\n", m);
                    printf("quel coordonné voulez vous ?\n ");
                    printf("x = "); scanf_s("%d", &x);
                    printf(" y = "); scanf_s("%d", &y);
                    printf("Vous avez choisis x = %d y = %d\n", x, y);
                }
                else if (y < 1) {
                    printf("votre valeur y est inférieur a 0 il doit etre égal ou supérieur\n");
                    printf("quel coordonné voulez vous ?\n ");
                    printf("x = "); scanf_s("%d", &x);
                    printf(" y = "); scanf_s("%d", &y);
                    printf("Vous avez choisis x = %d y = %d\n", x, y);
                }
                else {
                    break;
                }
            }
            if (dificulte == 4) {
                if (GD == 2) {
                    flag(grosTableauTroll, x, y, &nbBombe, &winLose, &winQ);
                }
                else {
                    flag(grosTableau, x, y, &nbBombe, &winLose, &winQ);
                }
            }
            else {
                flag(grosTableau, x, y, &nbBombe, &winLose, &winQ);
            }
        }
    }

    int restart = 0;

    if (winLose == 1) {
        for (int i = 0; i < n; i++)
        {

            for (int j = 0; j < m; j++)
            {
                grosTableau[i][j].visible = 1;

                if (dificulte == 4)
                    grosTableauTroll[i][j].visible = 1;

            }
        }
        draw(grosTableau, grosTableauTroll);
        printf("\n\n WOW vous avez réussie a découvrire tout les bombe GG\n\n");
        printf("veux tu rejouer ?\n");
        printf("1 = oui et 2 = non\n");
        printf("Votre choix: ");
        message = "\nMon vier tu te fout de moi ? les réponse sont entre 1 et 2 \nveux tu rejouer ?\n1 = oui et 2 = non\nVotre choix: ";
        restart = AskNumber(message, 1, 2);

        if (restart == 1) {
            for (int i = 0; i < n; i++) {
                free(grosTableau[i]);
            }
            free(grosTableau);
            if (dificulte == 4) {
                for (int i = 0; i < n; i++) {
                    free(grosTableauTroll[i]);
                }
                free(grosTableauTroll);
            }
            main();
        }
        else {
            for (int i = 0; i < n; i++) {
                free(grosTableau[i]);
            }
            free(grosTableau);
            if (dificulte == 4) {
                for (int i = 0; i < n; i++) {
                    free(grosTableauTroll[i]);
                }
                free(grosTableauTroll);
            }
            return 0;
        }
    }
    else if (winLose == 0) {
        for (int i = 0; i < n; i++)
        {

            for (int j = 0; j < m; j++)
            {
                grosTableau[i][j].visible = 1;

                if (dificulte == 4)
                    grosTableauTroll[i][j].visible = 1;

            }
        }
        draw(grosTableau, grosTableauTroll);
        printf("\n\n ha rip tes mort x)\n\n");
        printf("veux tu rejouer ?\n");
        printf("1 = oui et 2 = non\n");
        printf("Votre choix: ");
        message = "\nMon vier tu te fout de moi ? les réponse sont entre 1 et 2 \nveux tu rejouer ?\n1 = oui et 2 = non\nVotre choix: ";
        restart = AskNumber(message, 1, 2);

        if (restart == 1) {
            for (int i = 0; i < n; i++) {
                free(grosTableau[i]);
            }
            free(grosTableau);
            if (dificulte == 4) {
                for (int i = 0; i < n; i++) {
                    free(grosTableauTroll[i]);
                }
                free(grosTableauTroll);
            }
            main();
        }
        else {
            for (int i = 0; i < n; i++) {
                free(grosTableau[i]);
            }
            free(grosTableau);
            if (dificulte == 4) {
                for (int i = 0; i < n; i++) {
                    free(grosTableauTroll[i]);
                }
                free(grosTableauTroll);
            }
            return 0;
        }
    }

}

void draw(Case** grosTableau, Case** grosTableauTroll)
{
    int espacement = m - 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grosTableau[i][j].flag == 1) {
                if (m > 10) {
                    Color(6, 0);
                    printf("[ F ]");
                    Color(15, 0);
                }
                else {
                    Color(6, 0);
                    printf("[F]");
                    Color(15, 0);
                }
            }
            if (grosTableau[i][j].bombe == 1 && grosTableau[i][j].visible == 0 && grosTableau[i][j].flag != 1)
            {
                if (m > 10) {
                    printf("[   ]");
                }
                else {
                    printf("[ ]");
                }
            }
            else if (grosTableau[i][j].bombe == 1 && grosTableau[i][j].visible == 1 && grosTableau[i][j].flag != 1) {
                if (m > 10) {
                    Color(4, 0);
                    printf("[ X ]");
                    Color(15, 0);
                }
                else {
                    Color(4, 0);
                    printf("[X]");
                    Color(15, 0);
                }
            }
            else if (grosTableau[i][j].bombe == 0 && grosTableau[i][j].visible == 1 && grosTableau[i][j].flag != 1) {
                if (m > 10) {
                    printf("[ %d ]", grosTableau[i][j].indice);
                }
                else {
                    printf("[%d]", grosTableau[i][j].indice);
                }
            }
            else if (grosTableau[i][j].bombe == 0 && grosTableau[i][j].visible == 0 && grosTableau[i][j].flag != 1) {
                if (m > 10) {
                    printf("[   ]");
                }
                else {
                    printf("[ ]");
                }
            }
        }
        if (n > 10) {
            if (i >= 10) {
                Color(3, 0);
                printf("[%d ]", i);
                Color(15, 0);
            }
            else {
                Color(3, 0);
                printf("[ %d ]", i);
                Color(15, 0);
            }
        }
        else {
            Color(3, 0);
            printf("[%d]", i);
            Color(15, 0);
        }
        if (grosTableauTroll == NULL) {
            printf("\n");
        }
        if (grosTableauTroll != NULL) {
            for (int j = 0; j < m; j++) {
                if (grosTableauTroll[i][j].flag == 1) {
                    if (m > 10) {
                        Color(6, 0);
                        printf("[ F ]");
                        Color(15, 0);
                    }
                    else {
                        Color(6, 0);
                        printf("[F]");
                        Color(15, 0);
                    }
                }
                if (grosTableauTroll[i][j].bombe == 1 && grosTableauTroll[i][j].visible == 0 && grosTableauTroll[i][j].flag != 1)
                {
                    if (m > 10) {
                        printf("[   ]");
                    }
                    else {
                        printf("[ ]");
                    }
                }
                else if (grosTableauTroll[i][j].bombe == 1 && grosTableauTroll[i][j].visible == 1 && grosTableauTroll[i][j].flag != 1) {
                    if (m > 10) {
                        Color(4, 0);
                        printf("[ X ]");
                        Color(15, 0);
                    }
                    else {
                        Color(4, 0);
                        printf("[X]");
                        Color(15, 0);
                    }
                }
                else if (grosTableauTroll[i][j].bombe == 0 && grosTableauTroll[i][j].visible == 1 && grosTableauTroll[i][j].flag != 1) {
                    if (m > 10) {
                        printf("[ %d ]", grosTableauTroll[i][j].indice);
                    }
                    else {
                        printf("[%d]", grosTableauTroll[i][j].indice);
                    }
                }
                else if (grosTableauTroll[i][j].bombe == 0 && grosTableauTroll[i][j].visible == 0 && grosTableauTroll[i][j].flag != 1) {
                    if (m > 10) {
                        printf("[   ]");
                    }
                    else {
                        printf("[ ]");
                    }
                }
            }
            printf("\n");
        }
    }
    for (int i = 0; i < m; i++)
    {
        Color(3, 0);
        if (m > 10) {
            if (i >= 10) {
                Color(3, 0);
                printf("[%d ]", i);
                Color(15, 0);
            }
            else {
                Color(3, 0);
                printf("[ %d ]", i);
                Color(15, 0);
            }
        }
        else {
            Color(3, 0);
            printf("[%d]", i);
            Color(15, 0);
        }
        Color(15, 0);
    }
    if (grosTableauTroll != NULL) {
        if (espacement >= 10) {
            printf("     ");
        }
        else {
            printf("   ");
        }
        for (int i = 0; i < m; i++)
        {
            Color(3, 0);
            if (m > 10) {
                if (i >= 10) {
                    Color(3, 0);
                    printf("[%d ]", i);
                    Color(15, 0);
                }
                else {
                    Color(3, 0);
                    printf("[ %d ]", i);
                    Color(15, 0);
                }
            }
            else {
                Color(3, 0);
                printf("[%d]", i);
                Color(15, 0);
            }
            Color(15, 0);
        }
    }
    printf("\n");
}
void flag(Case** grosTableau, int x, int y, int* nbBombe, int* winLose, int* winQ) {
    if (grosTableau[x][y].flag == 1) {
        printf("tu a déja mi un flag ici \n");
    }
    else if (grosTableau[x][y].flag == 0) {
        grosTableau[x][y].flag = 1;
    }
    if (grosTableau[x][y].bombe == 0 && grosTableau[x][y].flag == 1) {
        *winLose = 0;
    }
    if (grosTableau[x][y].bombe == 1 && grosTableau[x][y].flag == 1) {
        grosTableau[x][y].visible = 1;
        *winQ += 1;
    }
    if (*winQ == *nbBombe) {
        *winLose = 1;
    }
}