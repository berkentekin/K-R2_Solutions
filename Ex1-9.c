#include <stdio.h>

int main() 
{
    int c, blanks = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
        {
            if (blanks < 1)
            {
                putchar(c);
            }
            blanks++;
        }
        else 
        {
            putchar(c);
        }

    }
		
	return 0;
}

