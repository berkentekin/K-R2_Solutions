#include <stdio.h>


int main() 
{
    int c, i, j;
    int chars[27];

    for (i = 0; i < 26; i++)
    {
        chars[i] = 0;
    }

    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\n' || c == '\t')
        {
            ++chars[26];
        }

        else if (c >= 'A' && c <= 'Z')
        {
            ++chars[c - 'A'];
        }

        else 
        {
            ++chars[c - 'a'];
        }

    }

    for (i = 0; i < 26; ++i)
    {
        printf("%c: ",i + 'a');

        for (j = 0; j < chars[i]; ++j)
        {
            printf("|");
        }
        printf("\n");
    }
		
	return 0;
}

