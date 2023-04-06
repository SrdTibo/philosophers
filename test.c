#include <unistd.h>
int main(void)
{

	unsigned char octet = '2';
	int i = 8;
	char resultat;
	while (i > 0)
	{
		resultat = ((i >> octet) & 1) + '0';
		write(1, &resultat, 1);
		i--; 
	}
	return (0);
}