#include <stdio.h>
#include <string.h>
#include<time.h>
#include<stdlib.h>
#include<windows.h>
#define MAXLEN 601

void LCSLength(int m, int n, char *x, char *y, int c[][MAXLEN], int b[][MAXLEN])
{
    int i, j;

    for (i = 0; i <= m; i++)
        c[i][0] = 0;
    for (j = 1; j <= n; j++)
        c[0][j] = 0;
    for (i = 1; i <= m; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (x[i - 1] == y[j - 1])
            {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = 1;
            }
            else if (c[i - 1][j] >= c[i][j - 1])
            {
                c[i][j] = c[i - 1][j];
                b[i][j] = 3;
            }
            else
            {
                c[i][j] = c[i][j - 1];
                b[i][j] = 2;
            }
        }
    }
}

void LCS(int i, int j, char *x, int b[][MAXLEN])
{
    if (i == 0 || j == 0)
        return;
    if (b[i][j] == 1)
    {
        LCS(i - 1, j - 1, x, b);
        printf("%c ", x[i - 1]);
    }
    else if (b[i][j] == 3)
    {
        LCS(i - 1, j, x, b);
    }
    else
    {
        LCS(i, j - 1, x, b);
    }
}

void genRandomString(char* buff, int length)
{
    char metachar[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    int i = 0;
    srand((unsigned) time(NULL));   //用时间做种，每次产生随机 数不一样
    for (i = 0; i < length; i++)
    {
        buff[i] = metachar[rand() % 62];
    }

    buff[length] = '\0';

}


int main()
{
    char x[600]={0};
    genRandomString(x,600);
    printf("%s",x);
    printf("\n============================\n");
    Sleep(1000);
    char y[600]={0};
    genRandomString(y,600);
    printf("%s",y);
    printf("\n============================\n");

    //char x[MAXLEN] = {"ABCBDAB"};
    //char y[MAXLEN] = {"BDCABA"};

    int c[MAXLEN][MAXLEN];
    int b[MAXLEN][MAXLEN];

    int len_x, len_y;

    len_x = strlen(x);
    len_y = strlen(y);

    //time test
    clock_t stime1 = clock();
    LCSLength(len_x, len_y, x, y, c, b);
    clock_t etime1 = clock();

    clock_t stime2=clock();
    LCS(len_x, len_y, x, b);
    clock_t etime2=clock();

    printf("\nLCSLength time is %d ms\n",etime1-stime1);
    printf("LCS time is %d ms",etime2-stime2);

    return 0;
}