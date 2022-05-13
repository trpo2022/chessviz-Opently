#include <stdio.h>

void PrintCB(char a[])
{
	int j = 8;
	for (int i = 0; i < 64 ; ++i) 
 	{
 		if( i % 8 == 0)
 		{	
 		 	printf("%d", j);
 			printf("  ");
 			j--;
 		}
 		
		printf("%c ", a[i]);
	
		if(i % 8 == 7)
		{
			printf("\n");
		}
 	}
 	printf("\n   a b c d e f g h\n");
 	printf("\n");
}
