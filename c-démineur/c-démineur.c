#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int n = 10;
int m = 10;

typedef struct Case Case;

void flag(Case** Tableau, int x, int y, int* nbBombe, int* winLose, int* winQ);
void draw(Case** Tableau, Case** TableauMiroire);

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

void TryAdd1(Case** Tableau, int i, int j)
{
    if (i < 0 || i >= n)
        return;

    if (j < 0 || j >= m)
        return;

    if (Tableau[i][j].bombe == 1)
        return;

    Tableau[i][j].indice += 1;
}
void TryRevel(Case** Tableau, int i, int j)
{
    if (i < 0 || i >= n)
        return;

    if (j < 0 || j >= m)
        return;

    if (Tableau[i][j].flag == 1)
        return;

    if (Tableau[i][j].bombe == 1)
        return;

    if (Tableau[i][j].visible == 1)
        return;

    if (Tableau[i][j].indice != 0) {
        Tableau[i][j].visible = 1;
        return;
    }

    Tableau[i][j].visible = 1;

    TryRevel(Tableau, i - 1, j - 1);
    TryRevel(Tableau, i - 1, j);
    TryRevel(Tableau, i - 1, j + 1);
    TryRevel(Tableau, i, j - 1);
    TryRevel(Tableau, i, j + 1);
    TryRevel(Tableau, i + 1, j - 1);
    TryRevel(Tableau, i + 1, j + 1);
    TryRevel(Tableau, i + 1, j);
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
    printf("Yo ! Tu es là pour jouer au démineur ?\n");
    printf("1 = oui, 2 = oui\n");
    printf("votre choix: ");
    const char* message = "Arrête de chercher la petite bête s'il te plaît (III)\n1 = oui, 2 = oui\nvotre choix: ";
    start = AskNumber(message, 1, 3);
    if (start == 3) {
        printf("indice : D TO T -> B TO T\n");
        printf("48 49 48 48 49 48 48 49 32 48 49 49 48 49 49 48 48 32 48 48 49 48 48 48 48 48 32 48 49 49 49 49 48 48 49 32 48 48 49 48 48 48 48 48 32 48 49 49 48 48 48 48 49 32 48 48 49 48 48 48 48 48 32 48 48 49 49 48 49 48 49 32 48 48 49 48 48 48 48 48 32 48 49 48 48 48 49 48 49 32 48 49 49 48 48 48 48 49 32 48 49 49 49 48 48 49 49 32 48 49 49 49 48 49 48 48 32 48 49 49 48 48 49 48 49 32 48 49 49 49 48 48 49 48 32 48 48 49 48 48 48 48 48 32 48 49 48 48 48 49 48 49 32 48 49 49 48 48 49 49 49 32 48 49 49 48 48 49 49 49 32 48 49 49 49 48 48 49 49 32 48 48 49 48 48 48 48 48 32 48 49 49 48 48 49 48 48 32 48 49 49 48 48 48 48 49 32 48 49 49 48 49 49 49 48 32 48 49 49 49 48 48 49 49 32 48 48 49 48 48 48 48 48 32 48 49 49 48 49 49 48 48 32 48 49 49 48 48 49 48 49 32 48 48 49 48 48 48 48 48 32 48 49 49 48 49 48 49 48 32 48 49 49 48 48 49 48 49 32 48 49 49 49 48 49 48 49 32 48 48 49 48 48 48 48 48 32 48 49 49 48 48 49 48 48 32 48 49 49 48 49 49 49 49 32 48 49 49 48 49 49 49 48 32 48 49 49 49 48 49 48 48 32 48 48 49 48 48 48 48 48 32 48 49 49 48 48 48 49 49 32 48 49 49 48 48 49 48 49 32 48 49 49 48 49 49 48 48 32 48 49 49 49 48 49 48 49 32 48 49 49 48 49 48 48 49 32 48 48 49 48 49 49 48 49 32 48 49 49 48 49 49 48 48 32 48 49 49 48 48 48 48 49 32 48 48 49 48 48 48 48 48");
        return 0;
    }
    printf("Hey, du coup vu que j'ai la flemme de le faire pour toi, TU vas choisir la taille du démineur ! (c'est du x * y)\n");
    printf("x = "); scanf_s("%d", &n);
    printf("y = "); scanf_s("%d", &m);
    while (n <= 0 || m <= 0) {
        if (n < 0 || m < 0) {
            printf("Mais... MAIS... MON VIER, TU ME METS UNE VALEUR 0 OU NÉGATIVE ?! TU AS DÉJÀ VU UN TABLEAU DE X = %d ET DE Y = %d ?!\n", n, m);
        }
        if (n >= 0 && m >= 0) {
            if (n == 0 && m == 0) {
                printf("Tu te rends compte que X = 0 et Y = 0 ? C'est un tableau de RIEN ! Genre, YA RIEN. Tu ne peux même pas VOIR le tableau. Je... JE... TU ME SOULES. Pour la peine, turn off.\n");
                return 0;
            }
            printf("alors huuuu, 0 * n'importe quoi, sa fait 0 donc ya rien... ouai ouai c'est balo =')\n");
        }
        printf("x = "); scanf_s("%d", &n);
        printf("y = "); scanf_s("%d", &m);
    }
    printf("Quelle est ta difficulté ?");
    printf("1 = facile, 2 = normale, 3 = Difficile\n");
    printf("votre choix: ");
    message = "\nArrête de chercher la petite bête s'il te plaît\n1 = facile, 2 = normale, 3 = Difficile\nvotre choix: ";
    dificulte = AskNumber(message, 1, 4);
    Case** Tableau = malloc(sizeof(Case*) * n);
    Case** TableauMiroire = NULL;
    for (int i = 0; i < n; i++) {
        Tableau[i] = malloc(sizeof(Case) * m);
    }

    srand(time(NULL));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            Tableau[i][j].bombe = 0;
            Tableau[i][j].visible = 0;
            Tableau[i][j].indice = 0;
            Tableau[i][j].flag = 0;
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
        TableauMiroire = malloc(sizeof(Case*) * n);
        for (int i = 0; i < n; i++) {
            TableauMiroire[i] = malloc(sizeof(Case) * m);
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                TableauMiroire[i][j].bombe = 0;
                TableauMiroire[i][j].visible = 0;
                TableauMiroire[i][j].indice = 0;
                TableauMiroire[i][j].flag = 0;
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
        while (Tableau[a][b].bombe == 1) {
            a = rand() % n;
            b = rand() % m;
        }
        Tableau[a][b].bombe = 1;
        if (dificulte == 4) {
            a = rand() % n;
            b = rand() % m;
            while (TableauMiroire[a][b].bombe == 1) {
                a = rand() % n;
                b = rand() % m;
            }
            TableauMiroire[a][b].bombe = 1;
        }
    }
    if (dificulte == 4) {
        nbBombe = nbBombe * 2;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (Tableau[i][j].bombe == 1)
            {
                TryAdd1(Tableau, i - 1, j - 1);
                TryAdd1(Tableau, i - 1, j);
                TryAdd1(Tableau, i - 1, j + 1);
                TryAdd1(Tableau, i, j - 1);
                TryAdd1(Tableau, i, j + 1);
                TryAdd1(Tableau, i + 1, j - 1);
                TryAdd1(Tableau, i + 1, j + 1);
                TryAdd1(Tableau, i + 1, j);
            }
            if (dificulte == 4) {
                if (TableauMiroire[i][j].bombe == 1)
                {
                    TryAdd1(TableauMiroire, i - 1, j - 1);
                    TryAdd1(TableauMiroire, i - 1, j);
                    TryAdd1(TableauMiroire, i - 1, j + 1);
                    TryAdd1(TableauMiroire, i, j - 1);
                    TryAdd1(TableauMiroire, i, j + 1);
                    TryAdd1(TableauMiroire, i + 1, j - 1);
                    TryAdd1(TableauMiroire, i + 1, j + 1);
                    TryAdd1(TableauMiroire, i + 1, j);
                }
            }
        }
    }
    int winLose;
    winLose = 2;
    int winQ;
    winQ = 0;
    while (winLose != 1 && winLose != 0) {
        draw(Tableau, TableauMiroire);
        int x; int y; int RorF;
        x = 0;
        y = 0;
        RorF = 0;
        printf("Tout d'abord, voulez-vous flag ou Revel une case ?\n");
        printf("1 = Revel une case, 2 = flag une case \n");
        printf("vous voulez : ");
        message = "Ha, vous avez peut-être fait un missclick ?\nVous venez de donner un résultat incorrect ! Veuillez recommencer !\n1 = Revel une case, 2 = flag une case \nvous voulez : ";
        RorF = AskNumber(message, 1, 2);
        if (RorF == 1) {
            printf("Quelles coordonnées voulez-vous ?\n ");
            printf("x = "); scanf_s("%d", &x);
            printf(" y = "); scanf_s("%d", &y);
            printf("Vous avez choisi X = %d, Y = %d.\n", x, y);
            while (x >= n || y >= m || x < 0 || y < 0) {
                if (x >= n) {
                    printf("Votre valeur X est supérieure ou égale à %d. Elle doit être inférieure.\n", n);
                    printf("Quelles coordonnées voulez-vous ?\n ");
                    printf("x = "); scanf_s("%d", &x);
                    printf(" y = "); scanf_s("%d", &y);
                    printf("Vous avez choisi X = %d, Y = %d.\n", x, y);
                }
                else if (x < 1) {
                    printf("Votre valeur X est inférieure à 0. Elle doit être égale ou supérieure.\n");
                    printf("Quelles coordonnées voulez-vous ?\n ");
                    printf("x = "); scanf_s("%d", &x);
                    printf(" y = "); scanf_s("%d", &y);
                    printf("Vous avez choisi X = %d, Y = %d.\n", x, y);
                }
                else if (y >= m) {
                    printf("Votre valeur Y est supérieure ou égale à %d. Elle doit être inférieure.\n", m);
                    printf("Quelles coordonnées voulez-vous ?\n ");
                    printf("x = "); scanf_s("%d", &x);
                    printf(" y = "); scanf_s("%d", &y);
                    printf("Vous avez choisi X = %d, Y = %d.\n", x, y);
                }
                else if (y < 1) {
                    printf("Votre valeur Y est inférieure à 0. Elle doit être égale ou supérieure.\n");
                    printf("Quelles coordonnées voulez-vous ?\n ");
                    printf("x = "); scanf_s("%d", &x);
                    printf(" y = "); scanf_s("%d", &y);
                    printf("Vous avez choisi X = %d, Y = %d.\n", x, y);
                }
                else {
                    break;
                }
            }
            if (dificulte != 4) {
                if (Tableau[x][y].visible == 1) {
                    printf("tu a déja révéler se coup \n");
                } 
                else {
                    printf("new Revel \n");
                    TryRevel(Tableau, x, y);
                }
            }
            if (dificulte == 4) {
                if (Tableau[x][y].visible == 1 && TableauMiroire[x][m - 1 - y].visible == 1) {
                    printf("tu a déja révéler se coup \n");
                }
                else {
                    printf("new Revel \n");
                    TryRevel(Tableau, x, y);
                    TryRevel(TableauMiroire, x, m - 1 - y);
                }
            }
            if (dificulte != 4) {
                if (Tableau[x][y].flag == 1)
                {
                    printf("vous avez flag cette endroit vous ne pouvez donc pas la revel !");
                }
                else if (Tableau[x][y].bombe == 1 && Tableau[x][y].flag != 1) {
                    printf("ta perdue CHEEEEEEH, you are dumbass noob (dumdum) \n");
                    for (int i = 0; i < n; i++)
                    {
                        for (int j = 0; j < m; j++)
                        {
                            Tableau[i][j].visible = 1;
                        }
                    }
                    winLose = 0;
                    break;
                }
                else if (Tableau[x][y].bombe == 0 && Tableau[x][y].flag != 1) {
                    printf("chanceux je pari ta fait au pif \n");
                }
            }
            else{
                if (Tableau[x][y].flag == 1 || TableauMiroire[x][y].flag == 1)
                {
                    printf("vous avez flag cette endroit vous ne pouvez donc pas la revel !");
                }
                else if (Tableau[x][y].bombe == 1 && Tableau[x][y].flag != 1 || TableauMiroire[x][m - 1 - y].bombe == 1 && TableauMiroire[x][m - 1 - y].flag != 1) {
                    printf("ta perdue CHEEEEEEH, you are dumbass noob (dumdum) \n");
                    for (int i = 0; i < n; i++)
                    {
                        for (int j = 0; j < m; j++)
                        {
                            Tableau[i][j].visible = 1;
                            TableauMiroire[i][j].visible = 1;
                        }
                    }
                    winLose = 0;
                    break;
                }
                else if (Tableau[x][y].bombe == 0 && Tableau[x][y].flag != 1 || TableauMiroire[x][m - 1 - y].bombe == 0 && TableauMiroire[x][m - 1 - y].flag != 1) {
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
                message = "faut vraimment mais VRAIMMENT que t'arrête de tenter des chiffre impossible quand on te propose des truc\ndans quelle tableau voulez vous flag ?\n1 = gauche, 2 = droite\nVotre choix: ";
                GD = AskNumber(message, 1, 2);
            }
            printf("Quelles coordonnées voulez-vous ?\n");
            printf("écriver les coordoner voulu :\n ");
            printf("x = "); scanf_s("%d", &x);
            printf(" y = "); scanf_s("%d", &y);
            printf("Vous avez choisi X = %d, Y = %d.\n", x, y);
            while (x >= n || y >= m || x < 0 || y < 0) {
                if (x >= n) {
                    printf("Votre valeur X est supérieure ou égale à %d. Elle doit être inférieure.\n", n);
                    printf("Quelles coordonnées voulez-vous ?\n ");
                    printf("x = "); scanf_s("%d", &x);
                    printf(" y = "); scanf_s("%d", &y);
                    printf("Vous avez choisi X = %d, Y = %d.\n", x, y);
                }
                else if (x < 1) {
                    printf("Votre valeur X est inférieure à 0. Elle doit être égale ou supérieure.\n");
                    printf("Quelles coordonnées voulez-vous ?\n ");
                    printf("x = "); scanf_s("%d", &x);
                    printf(" y = "); scanf_s("%d", &y);
                    printf("Vous avez choisi X = %d, Y = %d.\n", x, y);
                }
                else if (y >= m) {
                    printf("Votre valeur Y est supérieure ou égale à %d. Elle doit être inférieure.\n", m);
                    printf("Quelles coordonnées voulez-vous ?\n ");
                    printf("x = "); scanf_s("%d", &x);
                    printf(" y = "); scanf_s("%d", &y);
                    printf("Vous avez choisi X = %d, Y = %d.\n", x, y);
                }
                else if (y < 1) {
                    printf("Votre valeur Y est inférieure à 0. Elle doit être égale ou supérieure.\n");
                    printf("Quelles coordonnées voulez-vous ?\n ");
                    printf("x = "); scanf_s("%d", &x);
                    printf(" y = "); scanf_s("%d", &y);
                    printf("Vous avez choisi X = %d, Y = %d.\n", x, y);
                }
                else {
                    break;
                }
            }
            if (dificulte == 4) {
                if (GD == 2) {
                    flag(TableauMiroire, x, y, &nbBombe, &winLose, &winQ);
                }
                else {
                    flag(Tableau, x, y, &nbBombe, &winLose, &winQ);
                }
            }
            else {
                flag(Tableau, x, y, &nbBombe, &winLose, &winQ);
            }
        }
    }

    int restart = 0;

    if (winLose == 1) {
        for (int i = 0; i < n; i++)
        {

            for (int j = 0; j < m; j++)
            {
                Tableau[i][j].visible = 1;

                if (dificulte == 4)
                    TableauMiroire[i][j].visible = 1;

            }
        }
        draw(Tableau, TableauMiroire);
        printf("\n\n Waouh, vous avez réussi à découvrir toutes les bombes ! Félicitations !\n\n");
        printf("Veux tu rejouer ?\n");
        printf("1 = oui et 2 = non\n");
        printf("Votre choix: ");
        message = "\nMon vier, tu te fiches de moi ? Les réponses sont entre 1 et 2.\nveux tu rejouer ?\n1 = oui et 2 = non\nVotre choix: ";
        restart = AskNumber(message, 1, 2);

        if (restart == 1) {
            for (int i = 0; i < n; i++) {
                free(Tableau[i]);
            }
            free(Tableau);
            if (dificulte == 4) {
                for (int i = 0; i < n; i++) {
                    free(TableauMiroire[i]);
                }
                free(TableauMiroire);
            }
            main();
        }
        else {
            for (int i = 0; i < n; i++) {
                free(Tableau[i]);
            }
            free(Tableau);
            if (dificulte == 4) {
                for (int i = 0; i < n; i++) {
                    free(TableauMiroire[i]);
                }
                free(TableauMiroire);
            }
            return 0;
        }
    }
    else if (winLose == 0) {
        for (int i = 0; i < n; i++)
        {

            for (int j = 0; j < m; j++)
            {
                Tableau[i][j].visible = 1;

                if (dificulte == 4)
                    TableauMiroire[i][j].visible = 1;

            }
        }
        draw(Tableau, TableauMiroire);
        printf("\n\n  Ha rip tes mort x).\n\n");
        printf("veux tu rejouer ?\n");
        printf("1 = oui et 2 = non\n");
        printf("Votre choix: ");
        message = "\nMon vier, tu te fiches de moi ? Les réponses sont entre 1 et 2.\nveux tu rejouer ?\n1 = oui et 2 = non\nVotre choix: ";
        restart = AskNumber(message, 1, 2);

        if (restart == 1) {
            for (int i = 0; i < n; i++) {
                free(Tableau[i]);
            }
            free(Tableau);
            if (dificulte == 4) {
                for (int i = 0; i < n; i++) {
                    free(TableauMiroire[i]);
                }
                free(TableauMiroire);
            }
            main();
        }
        else {
            for (int i = 0; i < n; i++) {
                free(Tableau[i]);
            }
            free(Tableau);
            if (dificulte == 4) {
                for (int i = 0; i < n; i++) {
                    free(TableauMiroire[i]);
                }
                free(TableauMiroire);
            }
            return 0;
        }
    }

}

void draw(Case** Tableau, Case** TableauMiroire)
{
    int espacement = m - 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (Tableau[i][j].flag == 1) {
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
            if (Tableau[i][j].bombe == 1 && Tableau[i][j].visible == 0 && Tableau[i][j].flag != 1)
            {
                if (m > 10) {
                    printf("[   ]");
                }
                else {
                    printf("[ ]");
                }
            }
            else if (Tableau[i][j].bombe == 1 && Tableau[i][j].visible == 1 && Tableau[i][j].flag != 1) {
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
            else if (Tableau[i][j].bombe == 0 && Tableau[i][j].visible == 1 && Tableau[i][j].flag != 1) {
                if (m > 10) {
                    printf("[ %d ]", Tableau[i][j].indice);
                }
                else {
                    printf("[%d]", Tableau[i][j].indice);
                }
            }
            else if (Tableau[i][j].bombe == 0 && Tableau[i][j].visible == 0 && Tableau[i][j].flag != 1) {
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
        if (TableauMiroire == NULL) {
            printf("\n");
        }
        if (TableauMiroire != NULL) {
            for (int j = 0; j < m; j++) {
                if (TableauMiroire[i][j].flag == 1) {
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
                if (TableauMiroire[i][j].bombe == 1 && TableauMiroire[i][j].visible == 0 && TableauMiroire[i][j].flag != 1)
                {
                    if (m > 10) {
                        printf("[   ]");
                    }
                    else {
                        printf("[ ]");
                    }
                }
                else if (TableauMiroire[i][j].bombe == 1 && TableauMiroire[i][j].visible == 1 && TableauMiroire[i][j].flag != 1) {
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
                else if (TableauMiroire[i][j].bombe == 0 && TableauMiroire[i][j].visible == 1 && TableauMiroire[i][j].flag != 1) {
                    if (m > 10) {
                        printf("[ %d ]", TableauMiroire[i][j].indice);
                    }
                    else {
                        printf("[%d]", TableauMiroire[i][j].indice);
                    }   
                }
                else if (TableauMiroire[i][j].bombe == 0 && TableauMiroire[i][j].visible == 0 && TableauMiroire[i][j].flag != 1) {
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
    if (TableauMiroire != NULL) {
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
void flag(Case** Tableau, int x, int y, int* nbBombe, int* winLose, int* winQ) {
    if (Tableau[x][y].flag == 1) {
        printf("Tu as déjà mis un flag ici. \n");
    }
    else if (Tableau[x][y].flag == 0) {
        Tableau[x][y].flag = 1;
    }
    if (Tableau[x][y].bombe == 0 && Tableau[x][y].flag == 1) {
        *winLose = 0;
    }
    if (Tableau[x][y].bombe == 1 && Tableau[x][y].flag == 1) {
        Tableau[x][y].visible = 1;
        *winQ += 1;
    }
    if (*winQ == *nbBombe) {
        *winLose = 1;
    }
}