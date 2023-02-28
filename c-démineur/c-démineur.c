#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int n = 10;
int m = 10;

void draw(t3);
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
void TryAdd1(Case **grosTableau, int i, int j)
{
    if (i < 0 || i >= n)
        return;

    if (j < 0 || j >= m)
        return;

    if (grosTableau[i][j].bombe == 1)
        return;

    grosTableau[i][j].indice += 1;
}
void TryRevel(Case **grosTableau, int i, int j)
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
    int dificulte = 0;
    int start = 0;
    printf("Yo ! tu est la pour jouer ho démineur ?");
    printf("1 = oui, 2 = oui\n");
    printf("votre choix: "); scanf_s("%d", &start);
    while(start !=1 && start != 2 && start != 3){
        printf("Arrête de cherche dla d stp (III)\n");
        printf("1 = oui, 2 = oui");
        printf("votre choix: "); scanf_s("%d", &start);
    }
    if (start == 3) {
        printf("indice : D TO B -> B TO T -> B TO T\n");
        printf("11355697606988287594799323879791150804541232104347921866306692444090823645661768807697387094130483725659339837670733736882471196601955693525550440478587842499211871936989718351760352633522631235209079544958860288103480452207853820861395966375701996320215673920305342770881089551936212615749993072854248455881669153726689852346870949170993232419544974686353482939653157200903451353632250256807160932050113722312020085396976938959809052622557924166687332840864904175125660039183585429591964976803426949745734813800804657");
        return 0;
    }
    printf("hey huu du-coup vus que j'ai la flèmme de le faire pour toi TU vas chosir la taille du du démineur ! (c'est du x * y)\n");
    printf("x = "); scanf_s("%d", &n);
    printf("y = "); scanf_s("%d", &m);
    while (n <= 0 || m <= 0) {
        if (n < 0 || m < 0) {
            printf("mais...MAIS...MON VIER, TU ME MET UNE Valeur 0 OU NEGATIF TA DEJA VUS UN TABLEAU DE X = %d ET DE Y = %d\n", n ,m);
        }
        if (n >= 0 && m >= 0) {
            if (n == 0 && m == 0) {
                printf("tu te rend compte que x = 0 et y = 0 c'est un tableau de RIEN genre YA RIEN tu peut même pas VOIR le tableau je... je.... tu mes soul, pour la peine turn off\n");
                return 0;
            }
            printf("alors huuuu, 0 * n'importe quoi, sa fait 0 donc ya rien... ouai ouai c'est balo =')\n");
        }
        printf("x = "); scanf_s("%d", &n);
        printf("y = "); scanf_s("%d", &m);
    }
    printf("quelle difficulter ?");
    printf("1 = facile, 2 = normale, 3 = Difficile\n");
    printf("votre choix: "); scanf_s("%d", &dificulte);
    while (dificulte != 1 && dificulte != 2 && dificulte != 3) {
        printf("\nArrête de cherche dla d stp\n");
        printf("1 = facile, 2 = normale, 3 = Difficile\n");
        printf("votre choix: "); scanf_s("%d", &dificulte);
    }
    Case ** grosTableau = malloc(sizeof(Case*) * n);
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
    int DifB = 0;
    if (dificulte == 1) {
        DifB = 15;
    }else if (dificulte == 2) {
        DifB = 10;
    }else if (dificulte == 3) {
        DifB = 5;
    }
    int nbBombe = ((n * m) +5) / DifB;
    if (nbBombe < 1) {
        nbBombe = 1;
    }
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
            printf("vous voulez : "); scanf_s("%d", &RorF);
        }
        if (RorF == 1) {
            printf("quel coordonné voulez vous ?\n ");
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
            for (int i = 0; i < n; i++) {
                free(grosTableau[i]);
            }
            free(grosTableau);
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
            for (int i = 0; i < n; i++) {
                free(grosTableau[i]);
            }
            free(grosTableau);
            return 0;
        }
    }
}
void draw(Case **grosTableau)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
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

