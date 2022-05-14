#include <stdio.h>

void InputVar(char *finishLetter,int *finishNumber,char *infoMove,char *typeMove,char *startLetter,  int *startNumber,char *typeFigure)
{
	char abc[15];
	int var = 0;
	
	for(int i = 0; i > -1; i++)
	{
		abc[i] = getchar();
		fflush(stdin);
		var++;
		
		if(abc[i] == '\n'){break;}
	}
	if(abc[0] == 'N' || abc[0] == 'R' || abc[0] == 'Q' || abc[0] == 'K' || abc[0] == 'B')
	{
		*typeFigure = abc[0];
		
		for(int i = 0; i < var; i++)
		{
			abc[i] = abc[i+1];
		}	
	}
	else{*typeFigure = 'P';}
	
	*startLetter  = abc[0];
	*startNumber  = (abc[1] - '0'); //int
	*typeMove     = abc[2];
	*finishLetter = abc[3];
	*finishNumber = (abc[4] - '0');  //int
	*infoMove = abc[5];
	if(*infoMove == '\n'){*infoMove = 'P';}
}

