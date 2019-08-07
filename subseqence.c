#include <stdio.h>
#include <string.h>

#define MAX(a,b) ((a < b)? b : a)


int traceback(int* table[], int i, int j)
{
    return MAX(table[i-1][j], table[i][j-1]);
}

int lcs(char* gen1, char* gen2)
{
    register int i, j;
    int table[strlen(gen2)+1][strlen(gen1)+1];
    int match;

    for (i = 0; i < strlen(gen2)+1; i++)
        table[i][0] = 0;
    for (j = 1; j < strlen(gen1)+1; j++)
        table[0][j] = 0;


    for (i = 1; i < strlen(gen2); i++){
        for(j = 1; j < strlen(gen1); j++){
            match = (gen1[j] == gen2[i])? 1 : 0;
            if (match)
                table[i][j] = table[i-1][j-1] + match;
            else
                table[i][j] = MAX(table[i-1][j], table[i][j-1]);
        }
    }
    for (i = 0; i < strlen(gen2); i++){
        for (j = 0; j < strlen(gen1); j++)
            printf("%d ", table[i][j]);
        printf("\n");
    }

    return table[strlen(gen2)][strlen(gen1)];
}

int main()
{

    char* gen1 = " ABCABCBB\0";
    char* gen2 = " ABCABCBB\0";
    printf("%d\n", strlen(gen2));
    printf("%d\n", lcs(gen2, gen1));

    return 0;
}
