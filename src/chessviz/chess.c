#include <stdio.h>
#include <stdlib.h>

#include "libchessviz/PrintCB.h" //PrintChessBoard
#include "libchessviz/MoveWhite.h"
#include "libchessviz/MoveBlack.h"
// to compile: - gcc -Wall -o main PrintCB.c Check.c Mate.c MoveBlack.c MoveWhite.c chess.c

int main()
{
	printf("\nManual:\n");
	printf("Ладья(rook)  = r\nКонь(knight) = n\nСлон(bishop) = b\nФерзь(queen) = q\nКороль(king) = k\nПешка(pawn)  = p\nПустая клетка(empty cell) = o\nIf you want to exit - write # in letter of cell\n\n");
	
	int globalCheck = 0; int varExit = 0;
	int isMoveWhite = 1; int isMoveBlack = 1;
	int isMoveKingWhite = 0; int isMoveRookWhite = 0;
	int isMoveKingBlack = 0; int isMoveRookBlack = 0;
	
	char arr[64] = {'r','n','b','q','k','b','n','r',
            	        'p','p','p','p','p','p','p','p',
              	        ' ',' ',' ',' ',' ',' ',' ',' ',
              	        ' ',' ',' ',' ',' ',' ',' ',' ',
              	        ' ',' ',' ',' ',' ',' ',' ',' ',
              	        ' ',' ',' ',' ',' ',' ',' ',' ',
              	        'P','P','P','P','P','P','P','P',
              	        'R','N','B','Q','K','B','N','R'};
             	        
        PrintCB(arr);
        		
        do
        {	if(isMoveBlack == 1)
        	{			
		MoveWhite(arr,&varExit,&isMoveWhite,&isMoveKingWhite,&isMoveRookWhite,&globalCheck);
        	}
        	isMoveBlack = 1;
        	
        	if((isMoveWhite == 1) && !(globalCheck == 2))
        	{
		MoveBlack(arr,&varExit,&isMoveBlack,&isMoveKingBlack,&isMoveRookBlack,&globalCheck);
       	}
       	isMoveWhite = 1;	
	}
	while(!(globalCheck == 2) && (varExit == 0));
	
	return 0;
}
