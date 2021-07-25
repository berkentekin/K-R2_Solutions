#include <stdio.h>
/* print Celcius-Fahrenheit table
 * for celcius = 0, 20, ..., 300 */
int main() 
{
    float fahr, celcius;
    float lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;
    
    celcius = lower;

    printf("%s\t%s\n", "Cel", "Fahr");
    while (celcius <= upper)
    {
        fahr = (9.0/5.0) * celcius + 32.0;
        printf("%3.0f %6.0f\n", celcius, fahr);
        celcius = celcius + step;
    }

		
	return 0;
}

