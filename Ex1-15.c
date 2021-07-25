#include <stdio.h>

#define LOW 0
#define HIGH 300
#define INTERVAL 20

float convert_to_cel(float fahr);

int main() 
{
	float fahr;

	for (fahr = LOW; fahr <= HIGH; fahr += INTERVAL)
	{
		printf("%3.0f %6.1f\n", fahr, convert_to_cel(fahr));
	}
		
	return 0;
}

float convert_to_cel(float fahr)
{
	return (5.0/9.0) * (fahr - 32);
}

