#include <stdio.h>

int main() 
{
    int c, wl, wc, i;
    wl = wc = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\n' || c == '\t')
        {
            ++wc;
            printf("%d'st word: ",wc);

            for (i = 0; i < wl; ++i)
            {
                printf("|");
            }
            printf("\n");
            wl = 0;

        }

        else 
        {
            ++wl;
        }

    }
		
	return 0;
}

