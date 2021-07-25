#include <stdio.h>
/* print Fahrenheit-Celcius table
 * for fahr = 0, 20, ..., 300 */
int main() 
{
    float fahr, celcius;
    float lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;
    
    fahr = lower;

    printf("%s\t%s\n", "Fahr", "Cel");
    while (fahr <= upper)
    {
        celcius = (5.0/9.0) * (fahr-32.0);
        printf("%3.0f %6.1f\n", fahr, celcius);
        fahr = fahr + step;
    }

		
	return 0;
}

