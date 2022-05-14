#include <stdio.h>

#include "PrintCB.h" //PrintChessBoard
#include "Check.h"
#include "Mate.h"
#include "InputVar.h"

void MoveBlack(char a[],int *varExit,int *isMoveBlack,int *isMoveKingBlack, int *isMoveRookBlack, int *globalCheck)
{
	char finishLetter; int finishNumber; char infoMove; char typeMove;
	char startLetter; int startNumber; char typeFigure;
	int finishCell;  int startCell;
	
	int isCheck = 0; int isMate = 0; 
	char colorW = 'W'; char colorB = 'B';
	
	int cellKingB; int cellKingW;
	char lastFigure; int threatCell = 64; char pawnTransform; 

	printf("(Black)Print letters and numbers of cells to move: ");
InputVar(&finishLetter,&finishNumber,&infoMove,&typeMove,&startLetter,&startNumber,&typeFigure);
	     	  	
	startCell = ((8-startNumber)*8)+(startLetter-'0'-49);
	finishCell = ((8-finishNumber)*8)+(finishLetter-'0'-49);
      	  	
	 if(startLetter == '#' || finishLetter == '#')
	 {
		printf("\n      Exit\n\n");
		*isMoveBlack = 0;
		*varExit = 1;		
	 }
	 else if(finishNumber > 8 || finishNumber < 1 || !(typeFigure  == a[startCell]) 		|| (typeMove == 'x' && !((infoMove - 'A' + 'a') == a[finishCell])) 
		|| (!(typeMove == 'x') && ((infoMove - 'A' + 'a') == a[finishCell])))
	 {
	 	*isMoveBlack = 0;
	 	printf("   Incorrect input\n");
	 }
	 else
	 {
		for(int i = 0; i < 64; i++)
		{
        		if(a[i] == 'k'){cellKingW = i;}
        		if(a[i] == 'K'){cellKingB = i;}
		}
		
		 if(!((startLetter == 'a') || (startLetter == 'b') || (startLetter == 'c') || (startLetter == 'd') || (startLetter == 'e')
        	 || (startLetter == 'f') || (startLetter == 'g') || (startLetter == 'h') ||
        	 (finishLetter == 'a') || (finishLetter == 'b') || (finishLetter == 'c') || 
       	 (finishLetter == 'd') || (finishLetter == 'e') || (finishLetter == 'f') || 
        	 (finishLetter == 'g') || (finishLetter == 'h')))
      	  	 {
        		*isMoveBlack = 0; printf("\n   Error: wrong operation! \n\n"); 
      		 }       	
	  else
	  {
	  switch(a[startCell])
	  { 
/* rook */	case 'R':
			if((a[finishCell] ==' ' || 			   				  a[finishCell] =='p' || a[finishCell] =='r' || 			 			          a[finishCell] =='n' || a[finishCell] == 'b'|| 		           			  	  a[finishCell] =='q' || a[finishCell] =='k'))
			{
				if((finishCell - startCell) % 8 == 0) // verticale - |
				{
					if(finishCell > startCell) // down
					{	for(int i = startCell; i < 64; i += 8)
						{
						if(!(i == finishCell) && !(i ==startCell) && 							   !(a[i] ==' ') && (i < finishCell)){ break;}
							if(i == finishCell)
							{
								a[startCell] = ' ';
								lastFigure = a[finishCell];
								a[finishCell] = 'R';
								(*isMoveRookBlack)++;
								
							Check(a,cellKingB,&isCheck,&threatCell,colorB);
									if(isCheck == 1)
									{
										a[startCell] = 'R';
										a[finishCell] = lastFigure;
										(*isMoveRookBlack)--;
									}
									isCheck = 0;		
							}	
						}
						if(a[startCell] == 'R')
						{
							printf("\n   This move is impossible!\n\n");
							*isMoveBlack = 0;
						}
					}
					else // up
					{	
						for(int i = startCell; i >= 0; i -= 8)
						{
						if(!(i == finishCell) && !(i ==startCell) && 							   !(a[i] ==' ') && (i > finishCell)){ break;}
							if(i == finishCell)
							{
								a[startCell] = ' ';
								lastFigure = a[finishCell];
								a[finishCell] = 'R';
								(*isMoveRookBlack)++;
								
							Check(a,cellKingB,&isCheck,&threatCell,colorB);
									if(isCheck == 1)
									{
										a[startCell] = 'R';
										a[finishCell] = lastFigure;
										(*isMoveRookBlack)--;
									}
									isCheck = 0;
							}	
						}
						if(a[startCell] == 'R')
						{
							printf("\n   This move is impossible!\n\n");
							*isMoveBlack = 0;
						}
					}
				}
				else // gorizontale - ---
				{
					if(finishCell > startCell) // right
					{
						for(int i = startCell; i < (startCell + 						   8-(startCell % 8));i++)
						{
						if(!(i == finishCell) && !(i ==startCell) && 							   !(a[i] ==' ') && (i < finishCell)){ break;}
							if(i == finishCell)
							{
								a[startCell] = ' ';
								lastFigure = a[finishCell];
								a[finishCell] = 'R';
								(*isMoveRookBlack)++;

							Check(a,cellKingB,&isCheck,&threatCell,colorB);
									if(isCheck == 1)
									{
										a[startCell] = 'R';
										a[finishCell] = lastFigure;
										(*isMoveRookBlack)--;
									}
									isCheck = 0;
							}		
						}
						if(a[startCell] == 'R')
						{
							printf("\n   This move is impossible!\n\n");
							*isMoveBlack = 0;
						}
					}
					else // left
					{
						for(int i = startCell; i > (startCell -      							   (startCell % 8 + 1));i--)
						{
						if(!(i == finishCell) && !(i ==startCell) && 							   !(a[i] ==' ') && (i > finishCell)){ break;}
							if(i == finishCell)
							{
								a[startCell] = ' ';
								lastFigure = a[finishCell];
								a[finishCell] = 'r';
								(*isMoveRookBlack)++;

							Check(a,cellKingB,&isCheck,&threatCell,colorB);
									if(isCheck == 1)
									{
										a[startCell] = 'R';
										a[finishCell] = lastFigure;
										(*isMoveRookBlack)--;
									}
									isCheck = 0;
							}		
						}
						if(a[startCell] == 'R')
						{
							printf("\n   This move is impossible!\n\n");
							*isMoveBlack = 0;
						}
					}
				}
			}
			else
			{
					printf("\n   This move is impossible!\n\n");
					*isMoveBlack = 0;
			}
			printf("\n");             
			
		break;
		
/* knight */	case 'N': 
			if((a[finishCell] ==' ' || 			   				  a[finishCell] =='p' || a[finishCell] =='r' || 			 			          a[finishCell] =='n' || a[finishCell] == 'b'|| 		           			  	  a[finishCell] =='q' || a[finishCell] =='k') && 
			  (finishCell - startCell == 15 || finishCell - startCell == 17 || 				  finishCell - startCell == 6 || finishCell - startCell == 10 || 
			  finishCell - startCell == -6 || finishCell - startCell == -10 || 				  finishCell - startCell == -15 || finishCell - startCell == -17) &&
			  !(startCell / 8 ==  finishCell / 8))
			{
				a[startCell] = ' ';
								lastFigure = a[finishCell];
				a[finishCell] = 'N';

					Check(a,cellKingB,&isCheck,&threatCell,colorB);
					if(isCheck == 1)
					{
						a[startCell] = 'N';
						a[finishCell] = lastFigure;
					}
					isCheck = 0;
			}
			else
			{
					printf("\n   This move is impossible!\n\n");
					*isMoveBlack = 0;
			}
			printf("\n");             
			
		break;
		
/* bishop */	case 'B':  
			if((a[finishCell] ==' ' || 			   				  a[finishCell] =='p' || a[finishCell] =='r' || 			 			          a[finishCell] =='n' || a[finishCell] == 'b'|| 		           			  	  a[finishCell] =='q' || a[finishCell] =='k'))
			{
				if((finishCell - startCell) % 9 == 0) /* diagonale - \  */
				{
					if(finishCell > startCell) // right-down
					{	for(int j = startCell; j < 64; j += 9)
						{
						if(!(j == finishCell) && !(j == startCell) && 							   !(a[j] == ' ') && (j < finishCell)){ break;}
							if(j == finishCell)
							{
								a[startCell] = ' ';
								lastFigure = a[finishCell];
								a[finishCell] = 'B';
								
							Check(a,cellKingB,&isCheck,&threatCell,colorB);
									if(isCheck == 1)
									{
										a[startCell] = 'B';
										a[finishCell] = lastFigure;
									}
									isCheck = 0;
							}	
						}
						if(a[startCell] == 'B')
						{
							printf("\n   This move is impossible!\n\n");
							*isMoveBlack = 0;
						}
					}
					else // left-up
					{	
						for(int j = startCell; j > 0; j -= 9)
						{
						if(!(j == finishCell) && !(j == startCell) && 							   !(a[j] == ' ') && (j > finishCell)){ break;}
							if(j == finishCell)
							{
								a[startCell] = ' ';
								lastFigure = a[finishCell];
								a[finishCell] = 'B';

							Check(a,cellKingB,&isCheck,&threatCell,colorB);
									if(isCheck == 1)
									{
										a[startCell] = 'B';
										a[finishCell] = lastFigure;
									}
									isCheck = 0;
							}	
						}
						if(a[startCell] == 'B')
						{
							printf("\n   This move is impossible!\n\n");
							*isMoveBlack = 0;
						}
					}
				}
				else // diagonale - /
				{
					if(finishCell > startCell) // left-down
					{	for(int j = startCell; j < 64; j += 7)
						{
						if(!(j == finishCell) && !(j == startCell) && 							   !(a[j] == ' ') && (j < finishCell)){ break;}
							if(j == finishCell)
							{
								a[startCell] = ' ';
								lastFigure = a[finishCell];
								a[finishCell] = 'B';
								
							Check(a,cellKingB,&isCheck,&threatCell,colorB);
									if(isCheck == 1)
									{
										a[startCell] = 'B';
										a[finishCell] = lastFigure;
									}
									isCheck = 0;
							}	
						}
						if(a[startCell] == 'B')
						{
							printf("\n   This move is impossible!\n\n");
							*isMoveBlack = 0;
						}
					}
					else // right-up
					{
						for(int j = startCell; j > 0; j -= 7)
						{
						if(!(j == finishCell) && !(j == startCell) && 							   !(a[j] == ' ') && (j > finishCell)){ break;}
							if(j == finishCell)
							{
								a[startCell] = ' ';
								lastFigure = a[finishCell];
								a[finishCell] = 'B';
								
							Check(a,cellKingB,&isCheck,&threatCell,colorB);
									if(isCheck == 1)
									{
										a[startCell] = 'B';
										a[finishCell] = lastFigure;
									}
									isCheck = 0;
							}	
						}
						if(a[startCell] == 'B')
						{
							printf("\n   This move is impossible!\n\n");
							*isMoveBlack = 0;
						}
					}
				}
			}
			else
			{
					printf("\n   This move is impossible!\n\n");
					*isMoveBlack = 0;
			}
			printf("\n");             
			
		break;
		
/* queen */	case 'Q':
			if((a[finishCell] ==' ' || 			   				  a[finishCell] =='p' || a[finishCell] =='r' || 			 			          a[finishCell] =='n' || a[finishCell] == 'b'|| 		           			  	  a[finishCell] =='q' || a[finishCell] =='k'))
			{
				if((finishCell - startCell) % 8 == 0) // verticale - |
				{
					if(finishCell > startCell) // down
					{	for(int i = startCell; i < 64; i += 8)
						{
						if(!(i == finishCell) && !(i ==startCell) && 							   !(a[i] ==' ') && (i < finishCell)){ break;}
							if(i == finishCell)
							{
								a[startCell] = ' ';
								lastFigure = a[finishCell];
								a[finishCell] = 'Q';
								
							Check(a,cellKingB,&isCheck,&threatCell,colorB);
									if(isCheck == 1)
									{
										a[startCell] = 'Q';
										a[finishCell] = lastFigure;
									}
									isCheck = 0;
							}	
						}
						if(a[startCell] == 'Q')
						{
							printf("\n   This move is impossible!\n\n");
							*isMoveBlack = 0;
						}
					}
					else // up
					{	
						for(int i = startCell; i >= 0; i -= 8)
						{
						if(!(i == finishCell) && !(i ==startCell) && 
						!(a[i] ==' ') && (i > finishCell)){ break;}
							if(i == finishCell)
							{
								a[startCell] = ' ';
								lastFigure = a[finishCell];
								a[finishCell] = 'Q';
								
							Check(a,cellKingB,&isCheck,&threatCell,colorB);
									if(isCheck == 1)
									{
										a[startCell] = 'Q';
										a[finishCell] = lastFigure;
									}
									isCheck = 0;
							}	
						}
						if(a[startCell] == 'Q')
						{
							printf("\n   This move is impossible!\n\n");
							*isMoveBlack = 0;
						}
					}
				}
				else // gorizontale - ---
				{
				if((finishCell / 8) == (startCell / 8))
				{
					if(finishCell > startCell) // right
					{
						for(int i = startCell; i < (startCell + 						   8-(startCell % 8));i++)
						{
						if(!(i == finishCell) && !(i ==startCell) && 							   !(a[i] ==' ') && (i < finishCell)){ break;}
							if(i == finishCell)
							{
								a[startCell] = ' ';
								lastFigure = a[finishCell];
								a[finishCell] = 'Q';
								
							Check(a,cellKingB,&isCheck,&threatCell,colorB);
									if(isCheck == 1)
									{
										a[startCell] = 'Q';
										a[finishCell] = lastFigure;
									}
									isCheck = 0;
							}		
						}
						if(a[startCell] == 'Q')
						{
							printf("\n   This move is impossible!\n\n");
							*isMoveBlack = 0;
						}
					}
					else // left
					{
						for(int i = startCell; i > (startCell -      							   (startCell % 8 + 1));i--)
						{
						if(!(i == finishCell) && !(i ==startCell) && 							   !(a[i] ==' ') && (i > finishCell)){ break;}
							if(i == finishCell)
							{
								a[startCell] = ' ';
								lastFigure = a[finishCell];
								a[finishCell] = 'Q';
								
							Check(a,cellKingB,&isCheck,&threatCell,colorB);
									if(isCheck == 1)
									{
										a[startCell] = 'Q';
										a[finishCell] = lastFigure;
									}
									isCheck = 0;
							}		
						}
						if(a[startCell] == 'Q')
						{
							printf("\n   This move is impossible!\n\n");
							*isMoveBlack = 0;
						}
					}
				}
				else
				{
					if((finishCell - startCell) % 9 == 0) /* diagonale - \  */
				{
					if(finishCell > startCell) // right-down
					{	for(int j = startCell; j < 64; j += 9)
						{
						if(!(j == finishCell) && !(j == startCell) && 							   !(a[j] == ' ') && (j < finishCell)){ break;}
							if(j == finishCell)
							{
								a[startCell] = ' ';
								lastFigure = a[finishCell];
								a[finishCell] = 'Q';
								
							Check(a,cellKingB,&isCheck,&threatCell,colorB);
									if(isCheck == 1)
									{
										a[startCell] = 'Q';
										a[finishCell] = lastFigure;
									}
									isCheck = 0;
							}	
						}
						if(a[startCell] == 'Q')
						{
							printf("\n   This move is impossible!\n\n");
							*isMoveBlack = 0;
						}
					}
					else // left-up
					{	
						for(int j = startCell; j > 0; j -= 9)
						{
						if(!(j == finishCell) && !(j == startCell) && 							   !(a[j] == ' ') && (j > finishCell)){ break;}
							if(j == finishCell)
							{
								a[startCell] = ' ';
								lastFigure = a[finishCell];
								a[finishCell] = 'Q';
								
							Check(a,cellKingB,&isCheck,&threatCell,colorB);
									if(isCheck == 1)
									{
										a[startCell] = 'Q';
										a[finishCell] = lastFigure;
									}
									isCheck = 0;
							}	
						}
						if(a[startCell] == 'Q')
						{
							printf("\n   This move is impossible!\n\n");
							*isMoveBlack = 0;
						}
					}
				}
				else // diagonale - /
				{
					if(finishCell > startCell) // left-down
					{	for(int j = startCell; j < 64; j += 7)
						{
						if(!(j == finishCell) && !(j == startCell) && 							   !(a[j] == ' ') && (j < finishCell)){ break;}
							if(j == finishCell)
							{
								a[startCell] = ' ';
								lastFigure = a[finishCell];
								a[finishCell] = 'Q';
								
							Check(a,cellKingB,&isCheck,&threatCell,colorB);
									if(isCheck == 1)
									{
										a[startCell] = 'Q';
										a[finishCell] = lastFigure;
									}
									isCheck = 0;
							}	
						}
						if(a[startCell] == 'Q')
						{
							printf("\n   This move is impossible!\n\n");
							*isMoveBlack = 0;
						}
					}
					else // right-up
					{
						for(int j = startCell; j > 0; j -= 7)
						{
						if(!(j == finishCell) && !(j == startCell) && 							   !(a[j] == ' ') && (j > finishCell)){ break;}
							if(j == finishCell)
							{
								a[startCell] = ' ';
								lastFigure = a[finishCell];
								a[finishCell] = 'Q';
								
							Check(a,cellKingB,&isCheck,&threatCell,colorB);
									if(isCheck == 1)
									{
										a[startCell] = 'Q';
										a[finishCell] = lastFigure;
									}
									isCheck = 0;
							}	
						}
						if(a[startCell] == 'Q')
						{
							printf("\n   This move is impossible!\n\n");
							*isMoveBlack = 0;
						}
					}
				}
				}
				}
			}
			else
			{
					printf("\n   This move is impossible!\n\n");
					*isMoveBlack = 0;
			}
			printf("\n");             
			
		break;
		
/* king */	case 'K': 
			if((a[finishCell] ==' ' || 
			a[finishCell] =='p' || a[finishCell] =='r' || 
			a[finishCell] =='n' || a[finishCell] == 'b'|| 
			a[finishCell] =='q') && 
			(finishCell - startCell == 1 || finishCell - startCell == -1 || 
			finishCell - startCell == 8 || finishCell - startCell == -8 || 
			  finishCell - startCell == 9 || finishCell - startCell == -9 || 
			  finishCell - startCell == 7 || finishCell - startCell == -7))
			{
				Check(a,finishCell,&isCheck,&threatCell, colorB);// Check
				
				if(isCheck == 0)
				{
					a[startCell] = ' ';
					a[finishCell] = 'K';
					(*isMoveKingBlack)++;
				}
				else
				{printf("\n   the finish cell is under Check\n");
				isCheck = 0;*isMoveBlack = 0;}
			}
			else if((a[startCell] == 'K') && (a[finishCell] == 'R') && (finishCell == 56 				|| finishCell == 63) && (startCell == 60) && (*isMoveKingBlack == 0) 				&& (*isMoveRookBlack < 2)) 
			{
				if(finishCell == 56)
				{ 
					Check(a,a[58],&isCheck,&threatCell,colorB);// Check
					Check(a,a[59],&isCheck,&threatCell,colorB);
					Check(a,startCell,&isCheck,&threatCell,colorB);
				
					if(isCheck == 0)
					{
						a[startCell] = ' ';
						a[finishCell] = ' ';
						a[59] = 'R';
						a[58] = 'K';
						(*isMoveKingBlack)++;(*isMoveRookBlack)++;
					}
					else{printf("\n  one of the cells is under Check\n");
					isCheck = 0;*isMoveBlack = 0;}
				}
				else
				{
					Check(a,startCell,&isCheck,&threatCell,colorB);
					Check(a,a[61],&isCheck,&threatCell,colorB);// Check
					Check(a,a[62],&isCheck,&threatCell,colorB);
					
					if(isCheck == 0)
					{
						a[startCell] = ' ';
						a[finishCell] = ' ';
						a[61] = 'R';
						a[62] = 'K';
						(*isMoveKingBlack)++;(*isMoveRookBlack)++;	
					}
					else{printf("\n  one of the cells is under Check\n");
					isCheck = 0;*isMoveBlack = 0;}
				}
					
			}
			else
			{
				printf("\n   This move is impossible!\n\n");
				*isMoveBlack = 0;
			}
			printf("\n");             
			          
		break;
		
/* pawn */	case 'P':
			if(((a[finishCell] == ' ') && ((startCell - finishCell == 8) ||   		  		  ((startCell - finishCell == 16) && (startCell > 47)))) ||	         			 	  ((a[finishCell] =='p' || a[finishCell] =='r' || 			 				  a[finishCell] =='n' || a[finishCell] == 'b'|| 		           			  	  a[finishCell] =='q' || a[finishCell] =='k') && 				  ((startCell - finishCell == 7) || (startCell - finishCell==9))))
			{
				if(finishCell < 8)
				{
					for(int i = 0; i<1; i--)
					{	
					printf("Choose a piece(high register):'Q', 'B', 'R', 'N' - ");
						scanf("  %c",&pawnTransform);
						fflush(stdin);
						a[finishCell] = pawnTransform;
						a[startCell] = ' ';
								lastFigure = a[finishCell];
						if(a[finishCell] == 'Q' || a[finishCell] == 'B' ||
						   a[finishCell] == 'R' || a[finishCell] == 'N')
						{
							Check(a,cellKingW,&isCheck,&threatCell,colorW);
								if(isCheck == 1)
								{
								a[startCell] = 'p';
								a[finishCell] = lastFigure;
								}
								isCheck = 0;
							break;
						}
						else{printf("Incorrect choice, please again\n");}
					}
				}
				else
				{
					a[startCell] = ' ';
								lastFigure = a[finishCell];
					a[finishCell] = 'P';

						Check(a,cellKingB,&isCheck,&threatCell,colorB);
						if(isCheck == 1)
						{
							a[startCell] = 'P';
							a[finishCell] = lastFigure;
						}
						isCheck = 0;
				}
			}
			else
			{
				printf("\n   This move is impossible!\n\n");
				*isMoveBlack = 0;
			}
			printf("\n");             
			
		break;
		               
/*empty cell*/	case ' ':
	      	printf("\n   This cell is empty\n\n");
	      	*isMoveBlack = 0;
		
		break;
		
		default:{*isMoveBlack = 0; printf("\n   Error: wrong operation!\n\n"); }
	}
	}
		for(int i = 0; i < 64; i++)
		{
        		if(a[i] == 'k'){cellKingW = i;}
        		if(a[i] == 'K'){cellKingB = i;}
		}
		
		if(*globalCheck == 1)
		{
			isCheck = 0;
			Check(a,cellKingB,&isCheck,&threatCell,colorB);
			
			if(isCheck == 1)
			{
		printf("\n   The black king under the check!\n   You must to make another move\n\n");
			*isMoveBlack = 0;
			}
			else{*globalCheck = 0;}
		}
		if(*globalCheck == 0)
		{ 
	 		isCheck = 0;
			Check(a,cellKingW,&isCheck,&threatCell,colorW);

			if(isCheck == 1)
			{
				Mate(a,threatCell,cellKingW,&isMate,colorW);
				if(isMate == 1)
				{
					printf("\n   CheckMate! Black won!\n\n");
					*globalCheck = 2;
				}
				else
				{
					printf("\n   The white king under the check!\n\n");
					*globalCheck = 1;
					isCheck = 0;
				}
			}
		
		}
		
		PrintCB(a);
	}
}

