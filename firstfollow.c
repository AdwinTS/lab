
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int n, changed;
int L[20];
char R[20][20];
char F[128][20], Fo[128][20];

void add(char *set, char c)
{
    int l = strlen(set);

    if (!strchr(set, c))
    {
        set[l] = c;
        set[l + 1] = '\0';
        changed = 1;
    }
}

void show(char *s)
{
    printf("{ ");
    for (; *s; s++)
        printf("%c%s", *s, s[1] ? ", " : "");
    printf(" }\n");
}

int main()
{
    int i, j, k;
    char s[30], *p;
    int X, B;

    printf("Enter number of productions: ");
    scanf("%d", &n);

    printf("Enter productions (use # for epsilon):\n");

    for (i = 0; i < n; i++)
    {
        scanf("%s", s);
        L[i] = s[0];
        strcpy(R[i], s + 3);
    }

    do
    {
        changed = 0;

        for (i = 0; i < n; i++)
        {
            for (j = 0; R[i][j]; j++)
            {
                X = R[i][j];

                if (!isupper(X))
                {
                    add(F[L[i]], X);
                    break;
                }

                for (p = F[X]; *p; p++)
                    if (*p != '#')
                        add(F[L[i]], *p);

                if (!strchr(F[X], '#'))
                    break;
            }

            if (R[i][j] == '\0')
                add(F[L[i]], '#');
        }
    } while (changed);

    add(Fo[L[0]], '$');

    do
    {
        changed = 0;

        for (i = 0; i < n; i++)
        {
            for (j = 0; R[i][j]; j++)
            {
                B = R[i][j];

                if (!isupper(B))
                    continue;

                for (k = j + 1; R[i][k]; k++)
                {
                    X = R[i][k];

                    if (!isupper(X))
                    {
                        add(Fo[B], X);
                        break;
                    }

                    for (p = F[X]; *p; p++)
                        if (*p != '#')
                            add(Fo[B], *p);

                    if (!strchr(F[X], '#'))
                        break;
                }

                if (R[i][k] == '\0')
                {
                    for (p = Fo[L[i]]; *p; p++)
                        add(Fo[B], *p);
                }
            }
        }
    } while (changed);

    printf("\nFIRST:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < i; j++)
            if (L[j] == L[i])
                break;

        if (j < i)
            continue;

        printf("FIRST(%c) = ", L[i]);
        show(F[L[i]]);
    }

    printf("\nFOLLOW:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < i; j++)
            if (L[j] == L[i])
                break;

        if (j < i)
            continue;

        printf("FOLLOW(%c) = ", L[i]);
        show(Fo[L[i]]);
    }

    return 0;
}
