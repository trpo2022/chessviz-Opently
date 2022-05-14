#include <stdio.h>

#include "Check.h"

void CheckKingMove(char a[],int finishCell, int *isMove, char color)
{
	if((color == 'W') && (finishCell >= 0) && (finishCell <= 64) && 
	(a[finishCell] == ' ' || a[finishCell] == 'P' || a[finishCell] == 'R' || 
	a[finishCell] == 'N' || a[finishCell] == 'B' || a[finishCell] == 'Q'))
	{
		*isMove = 1;
	}
	else if((color == 'B') && (finishCell >= 0) && (finishCell <= 64) && 
	(a[finishCell] == ' ' || a[finishCell] == 'p' || a[finishCell] == 'r' || 
	a[finishCell] == 'n' || a[finishCell] == 'b' || a[finishCell] == 'q'))
	{

		*isMove = 1;
	}
}

void Mate(char a[], int threatCell, int cellKing, int *isMate, char color)
{
int isCheck = 0; int saveCell = 64; int checkCount = 0; char anotherColor; int withoutKing = 999;
int isMove = 0;
	anotherColor = (color == 'W') ? 'B' : 'W';

	//check King moves  
	Check(a,(cellKing+1),&isCheck,&saveCell,color); CheckKingMove(a,(cellKing+5),&isMove,color);
	if(isCheck == 1 || isMove == 0){isCheck = 0; isMove = 0; checkCount++;}
 
	Check(a,(cellKing-1),&isCheck,&saveCell,color); CheckKingMove(a,(cellKing-1),&isMove,color);
	if(isCheck == 1 || isMove == 0){isCheck = 0; isMove = 0; checkCount++;}

	Check(a,(cellKing+8),&isCheck,&saveCell,color); CheckKingMove(a,(cellKing+8),&isMove,color);
	if(isCheck == 1 || isMove == 0){isCheck = 0; isMove = 0; checkCount++;}
	
	Check(a,(cellKing-8),&isCheck,&saveCell,color); CheckKingMove(a,(cellKing-8),&isMove,color);
	if(isCheck == 1 || isMove == 0){isCheck = 0; isMove = 0; checkCount++;}
	
	Check(a,(cellKing+9),&isCheck,&saveCell,color); CheckKingMove(a,(cellKing+9),&isMove,color);
	if(isCheck == 1 || isMove == 0){isCheck = 0; isMove = 0; checkCount++;}

	Check(a,(cellKing-9),&isCheck,&saveCell,color); CheckKingMove(a,(cellKing-9),&isMove,color);
	if(isCheck == 1 || isMove == 0){isCheck = 0; isMove = 0; checkCount++;}
	
	Check(a,(cellKing+7),&isCheck,&saveCell,color); CheckKingMove(a,(cellKing+7),&isMove,color);
	if(isCheck == 1 || isMove == 0){isCheck = 0; isMove = 0; checkCount++;}
	
	Check(a,(cellKing-7),&isCheck,&saveCell,color); CheckKingMove(a,(cellKing-7),&isMove,color);
	if(isCheck == 1 || isMove == 0){isCheck = 0; isMove = 0; checkCount++;}
	
	if(checkCount == 8)
	{
		if(threatCell < cellKing)
		{
			if((cellKing - threatCell) % 8 == 0) //verticale - up
			{
				for(int i = cellKing; i >= threatCell; i -= 8)
				{
					Check(a,i,&isCheck,&withoutKing,anotherColor);
					if(isCheck == 1){break;}
					if(i == threatCell){*isMate = 1; break;}
				}
			}
			
			if(threatCell / 8 == cellKing / 8) //horizontale - left
			{
				for(int i = cellKing; i >= threatCell;i--)
				{
					Check(a,i,&isCheck,&withoutKing,anotherColor);
					if(isCheck == 1){break;}
					if(i == threatCell){*isMate = 1; break;}
				}
			}
			
			if((cellKing - threatCell) % 9 == 0) //diagonale - \ - left-up
			{
				for(int i = cellKing; i >= threatCell; i -= 9)
				{
					Check(a,i,&isCheck,&withoutKing,anotherColor);
					printf(" %d %d %c",i,isCheck,anotherColor);
					if(isCheck == 1){break;}
					if(i == threatCell){*isMate = 1; break;}
				}
			}
			
			if((cellKing - threatCell) % 7 == 0) //diagonale - / right-up
			{
				for(int i = cellKing; i >= threatCell; i -= 7)
				{
					Check(a,i,&isCheck,&withoutKing,anotherColor);
					if(isCheck == 1){break;}
					if(i == threatCell){*isMate = 1; break;}
				}
			}
		}
		else
		{
			if((threatCell - cellKing) % 8 == 0) //verticale - down
			{
				for(int i = cellKing; i <= threatCell; i += 8)
				{
					Check(a,i,&isCheck,&withoutKing,anotherColor);
					if(isCheck == 1){break;}
					if(i == threatCell){*isMate = 1; break;}
				}
			}
			
			if(cellKing / 8 == threatCell / 8) //horizontale - right
			{
				for(int i = cellKing; i <= threatCell;i++)
				{
					Check(a,i,&isCheck,&withoutKing,anotherColor);
					if(isCheck == 1){break;}
					if(i == threatCell){*isMate = 1; break;}
				}
			}
			
			if((threatCell - cellKing) % 9 == 0) //diagonale - \ - right-down
			{
				for(int i = cellKing; i <= threatCell; i += 9)
				{
					Check(a,i,&isCheck,&withoutKing,anotherColor);
					if(isCheck == 1){break;}
					if(i == threatCell){*isMate = 1; break;}
				}
			}
			
			if((threatCell - cellKing) % 7 == 0) //diagonale - / left-down
			{
				for(int i = cellKing; i <= threatCell; i += 7)
				{
					Check(a,i,&isCheck,&withoutKing,anotherColor);
					if(isCheck == 1){break;}
					if(i == threatCell){*isMate = 1; break;}
				}
			}
		}
	}
}
