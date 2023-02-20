#include <stdio.h>

#define n 10
#define m 10

int main()
{
    int grosTableau[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            grosTableau[i][j] = 0;
        }
    }

    grosTableau[5][3] = 1;
    grosTableau[7][8] = 1;
    grosTableau[0][0] = 1;
   
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grosTableau[i][j] == 1)
            {
                printf("[x]");
            }
            else {
                printf("[]");
            }
        }
        printf("\n");
    }

}
