#include <stdio.h>
/* print Fahrenheit-Celcius table
 * for fahr = 0, 20, ..., 300 */
int main() 
{
    int fahr, celcius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;
    
    fahr = lower;

    printf("%s\t%s\n", "Fahr", "Cel");
    while (fahr <= upper)
    {
        celcius = 5 * (fahr-32) / 9;
        printf("%3d %6d\n", fahr, celcius);
        fahr = fahr + step;
    }

		
	return 0;
}

