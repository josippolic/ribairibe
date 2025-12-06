#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int simuliraj(char niz[], int n, int x)
{
    int vrijeme = x;
    int ukupno = 0;

    while (1)
    {
        int pomak = vrijeme / 10;
        if (pomak >= n) break;

        int i;
        int prva = -1;
        for (i = pomak; i < n; i++)
        {
            if (niz[i] != '.')
            {
                prva = i;
                break;
            }
        }

        if (prva == -1) break;

        vrijeme = prva * 10;
        ukupno += (niz[prva] - 'A' + 1);

        vrijeme += 30;
    }

    return ukupno;
}

int main()
{
    char niz[500];
    int n;

    scanf("%d", &n);
    scanf("%s", niz);

    int najbolji_x = 0;
    int najbolji_ulov = 0;

    for (int x = 0; x <= n * 10; x += 10)
    {
        int r = simuliraj(niz, n, x);

        if (r > najbolji_ulov)
        {
            najbolji_ulov = r;
            najbolji_x = x;
        }
    }

    printf("Optimalno je baciti udicu nakon %ds, sto donosi %dkg ribe.\n",
        najbolji_x, najbolji_ulov);

    return 0;
}

