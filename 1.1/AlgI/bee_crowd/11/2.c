#include <stdio.h>
#include <string.h>

int main (){

	char texto[110];
	unsigned short tam, metadeTam;
	unsigned casos, i;

	scanf("%u", &casos);

	setbuf(stdin, NULL);

	while (casos)
	{	
		scanf("%[^\n]", texto);

		setbuf(stdin, NULL);
		
		tam = strlen(texto);
		metadeTam = tam/2;

		for (i = metadeTam-1; i < -1; i--)
			printf("%c", texto[i]);

		for (i = tam-1; i >= metadeTam; i--)
			printf("%c", texto[i]);


		printf("\n");
		
	casos--;
	}
	return 0;
}