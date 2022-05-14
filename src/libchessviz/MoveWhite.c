#include <stdio.h>

#include "PrintCB.h" //PrintChessBoard
#include "Check.h"
#include "Mate.h" 
#include "InputVar.h"

void MoveWhite(char a[],int *varExit,int *isMoveWhite,int *isMoveKingWhite,int *isMoveRookWhite, int *globalCheck)
{
	char finishLetter; int finishNumber; char infoMove; char typeMove;
	char startLetter; int startNumber; char typeFigure;
	int finishCell;  int startCell;
	
	int isCheck = 0; int isMate = 0; 
	char colorW = 'W'; char colorB = 'B';
	
	int cellKingB; int cellKingW;
	char lastFigure; int threatCell = 64; char pawnTransform; 

	printf("(White)Print letters and numbers of cells to move: ");
InputVar(&finishLetter,&finishNumber,&infoMove,&typeMove,&startLetter,&startNumber,&typeFigure);
        	 
	startCell = ((8-startNumber)*8)+(startLetter-'0'-49);
	finishCell = ((8-finishNumber)*8)+(finishLetter-'0'-49); 
	
	 if(startLetter == '#' || finishLetter == '#')
	 {
		printf("\n      Exit\n\n");
		*isMoveWhite = 0;
		*varExit = 1;		
	 }
	 else if(finishNumber > 8 || finishNumber < 1 || !((typeFigure - 'A' + 'a') == a[startCell]) 		|| (typeMove == 'x' && !(infoMove == a[finishCell])) 
		|| (!(typeMove == 'x') && (infoMove == a[finishCell])))
	 {
	 	*isMoveWhite = 0;
	printf("  Incorrect input %c.%d.%c.%d\n",startLetter,startNumber,finishLetter,finishNumber);
	 }
	 else
	 {
	 	for(int i = 0; i < 64; i++)
		{
        		if(a[i] == 'K'){cellKingB = i;}
        		if(a[i] == 'k'){cellKingW = i;}
		}

         	 if(!((startLetter == 'a') || (startLetter == 'b') || (startLetter == 'c') || (startLetter == 'd') || (startLetter == 'e')
           	 || (startLetter == 'f') || (startLetter == 'g') || (startLetter == 'h') ||
           	 (finishLetter == 'a') || (finishLetter == 'b') || (finishLetter == 'c') || 
           	 (finishLetter == 'd') || (finishLetter == 'e') || (finishLetter == 'f') || 
           	 (finishLetter == 'g') || (finishLetter == 'h')))
        	 {
         	 	*isMoveWhite = 0; printf("\n   Error: wrong operation! \n\n"); 
       	 }       	
	  else
	  {
	  switch(a[startCell])
	  { 
/* rook */	case 'r':
			if((a[finishCell] ==' ' || 			   				  a[finishCell] =='P' || a[finishCell] =='R' || 			 			          a[finishCell] =='N' || a[finishCell] == 'B'|| 		           			  	  a[finishCell] =='Q' || a[finishCell] =='K'))
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
								a[finishCell] = 'r';
								(*isMoveRookWhite)++;
								
							Check(a,cellKingW,&isCheck,&threatCell,colorW);
									if(isCheck == 1)
									{
										a[startCell] = 'r';
										a[finishCell] = lastFigure;
										(*isMoveRookWhite)--;
									}
									isCheck = 0;
							}	
						}
						if(a[startCell] == 'r')
						{
							printf("\n   This move is impossible!\n\n");
							*isMoveWhite = 0;
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
								a[finishCell] = 'r';
								(*isMoveRookWhite)++;

							Check(a,cellKingW,&isCheck,&threatCell,colorW);
									if(isCheck == 1)
									{
										a[startCell] = 'r';
										a[finishCell] = lastFigure;
										(*isMoveRookWhite)--;
									}
									isCheck = 0;
							}	
						}
						if(a[startCell] == 'r')
						{
							printf("\n   This move is impossible!\n\n");
							*isMoveWhite = 0;
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
								a[finishCell] = 'r';
								(*isMoveRookWhite)++;

							Check(a,cellKingW,&isCheck,&threatCell,colorW);
									if(isCheck == 1)
									{
										a[startCell] = 'r';
										a[finishCell] = lastFigure;
										(*isMoveRookWhite)--;
									}
									isCheck = 0;
							}		
						}
						if(a[startCell] == 'r')
						{
							printf("\n   This move is impossible!\n\n");
							*isMoveWhite = 0;
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
								(*isMoveRookWhite)++;

							Check(a,cellKingW,&isCheck,&threatCell,colorW);
									if(isCheck == 1)
									{
										a[startCell] = 'r';
										a[finishCell] = lastFigure;
										(*isMoveRookWhite)--;
									}
									isCheck = 0;
							}		
						}
						if(a[startCell] == 'r')
						{
							printf("\n   This move is impossible!\n\n");
							*isMoveWhite = 0;
						}
					}
				}
			}
			else
			{
				printf("\n   This move is impossible!\n\n");
				*isMoveWhite = 0;	
			}
			printf("\n");             
			
		break;
		
/* knight */	case 'n': 
			if((a[finishCell] ==' ' || a[finishCell] =='P' || a[finishCell] =='R' || 			 	  a[finishCell] =='N' || a[finishCell] == 'B' || a[finishCell] =='Q' || 			  a[finishCell] =='K') && 
			  (finishCell - startCell == 15 || finishCell - startCell == 17 || 				  finishCell - startCell == 6 || finishCell - startCell == 10 || 
			  finishCell - startCell == -6 || finishCell - startCell == -10 || 				  finishCell - startCell == -15 || finishCell - startCell == -17) &&
			  !(startCell / 8 ==  finishCell / 8))
			{
				a[startCell] = ' ';
				lastFigure = a[finishCell];
				a[finishCell] = 'n';

			Check(a,cellKingW,&isCheck,&threatCell,colorW);
					if(isCheck == 1)
					{
						a[startCell] = 'n';
						a[finishCell] = lastFigure;
					}
					isCheck = 0;
			}
			else
			{
				printf("\n   This move is impossible!\n\n");
				*isMoveWhite = 0;
			}
			printf("\n");             
			
		break;
		
/* bishop */	case 'b':  
			if((a[finishCell] ==' ' || 			   				  a[finishCell] =='P' || a[finishCell] =='R' || 			 			          a[finishCell] =='N' || a[finishCell] == 'B'|| 		           			  	  a[finishCell] =='Q' || a[finishCell] =='K'))
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
								a[finishCell] = 'b';

							Check(a,cellKingW,&isCheck,&threatCell,colorW);
									if(isCheck == 1)
									{
										a[startCell] = 'b';
										a[finishCell] = lastFigure;
									}
									isCheck = 0;
							}	
						}
						if(a[startCell] == 'b')
						{
							printf("\n   This move is impossible!\n\n");
							*isMoveWhite = 0;
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
								a[finishCell] = 'b';

							Check(a,cellKingW,&isCheck,&threatCell,colorW);
									if(isCheck == 1)
									{
										a[startCell] = 'b';
										a[finishCell] = lastFigure;
									}
									isCheck = 0;
							}	
						}
						if(a[startCell] == 'b')
						{
							printf("\n   This move is impossible!\n\n");
							*isMoveWhite = 0;
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
								a[finishCell] = 'b';

							Check(a,cellKingW,&isCheck,&threatCell,colorW);
									if(isCheck == 1)
									{
										a[startCell] = 'b';
										a[finishCell] = lastFigure;
									}
									isCheck = 0;
							}	
						}
						if(a[startCell] == 'b')
						{
							printf("\n   This move is impossible!\n\n");
							*isMoveWhite = 0;
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
								a[finishCell] = 'b';

							Check(a,cellKingW,&isCheck,&threatCell,colorW);
									if(isCheck == 1)
									{
										a[startCell] = 'b';
										a[finishCell] = lastFigure;
									}
									isCheck = 0;
							}	
						}
						if(a[startCell] == 'b')
						{
							printf("\n   This move is impossible!\n\n");
							*isMoveWhite = 0;
						}
					}
				}
			}
			else
			{
				printf("\n   This move is impossible!\n\n");	
				*isMoveWhite = 0;
			}
			printf("\n");             
			
		break;
		
/* queen */	case 'q':
			if((a[finishCell] ==' ' || 			   				  a[finishCell] =='P' || a[finishCell] =='R' || 			 			          a[finishCell] =='N' || a[finishCell] == 'B'|| 		           			  	  a[finishCell] =='Q' || a[finishCell] =='K'))
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
								a[finishCell] = 'q';

							Check(a,cellKingW,&isCheck,&threatCell,colorW);
									if(isCheck == 1)
									{
										a[startCell] = 'q';
										a[finishCell] = lastFigure;
									}
									isCheck = 0;
							}	
						}
						if(a[startCell] == 'q')
						{
							printf("\n   This move is impossible!\n\n");
							*isMoveWhite = 0;
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
								a[finishCell] = 'q';

							Check(a,cellKingW,&isCheck,&threatCell,colorW);
									if(isCheck == 1)
									{
										a[startCell] = 'q';
										a[finishCell] = lastFigure;
									}
									isCheck = 0;
							}	
						}
						if(a[startCell] == 'q')
						{
							printf("\n   This move is impossible!\n\n");
							*isMoveWhite = 0;
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
								a[finishCell] = 'q';

							Check(a,cellKingW,&isCheck,&threatCell,colorW);
									if(isCheck == 1)
									{
										a[startCell] = 'q';
										a[finishCell] = lastFigure;
									}
									isCheck = 0;
							}		
						}
						if(a[startCell] == 'q')
						{
							printf("\n   This move is impossible!\n\n");
							*isMoveWhite = 0;
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
								a[finishCell] = 'q';

							Check(a,cellKingW,&isCheck,&threatCell,colorW);
									if(isCheck == 1)
									{
										a[startCell] = 'q';
										a[finishCell] = lastFigure;
									}
									isCheck = 0;
							}		
						}
						if(a[startCell] == 'q')
						{
							printf("\n   This move is impossible!\n\n");
							*isMoveWhite = 0;
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
								a[finishCell] = 'q';

							Check(a,cellKingW,&isCheck,&threatCell,colorW);
									if(isCheck == 1)
									{
										a[startCell] = 'q';
										a[finishCell] = lastFigure;
									}
									isCheck = 0;
							}	
						}
						if(a[startCell] == 'q')
						{
							printf("\n   This move is impossible!\n\n");
							*isMoveWhite = 0;
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
								a[finishCell] = 'q';

							Check(a,cellKingW,&isCheck,&threatCell,colorW);
									if(isCheck == 1)
									{
										a[startCell] = 'q';
										a[finishCell] = lastFigure;
									}
									isCheck = 0;
							}	
						}
						if(a[startCell] == 'q')
						{
							printf("\n   This move is impossible!\n\n");
							*isMoveWhite = 0;
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
								a[finishCell] = 'q';

							Check(a,cellKingW,&isCheck,&threatCell,colorW);
									if(isCheck == 1)
									{
										a[startCell] = 'q';
										a[finishCell] = lastFigure;
									}
									isCheck = 0;
							}	
						}
						if(a[startCell] == 'q')
						{
							printf("\n   This move is impossible!\n\n");
							*isMoveWhite = 0;
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
								a[finishCell] = 'q';

							Check(a,cellKingW,&isCheck,&threatCell,colorW);
								if(isCheck == 1)
								{
									a[startCell] = 'q';
									a[finishCell] = lastFigure;
								}
								isCheck = 0;
							}	
						}
						if(a[startCell] == 'q')
						{
							printf("\n   This move is impossible!\n\n");
							*isMoveWhite = 0;
						}
					}
				}
				}
				}
			}
			else
			{
				printf("\n   This move is impossible!\n\n");
				*isMoveWhite = 0;	
			}
			printf("\n");             
			
		break;
		
/* king */	case 'k':
			if((a[finishCell] == ' ' || 
			a[finishCell] == 'P' || a[finishCell] == 'R' || 
			a[finishCell] == 'N' || a[finishCell] == 'B' || 
			a[finishCell] == 'Q') &&
			  (finishCell - startCell == 1 || finishCell - startCell == -1 || 
			  finishCell - startCell == 8 || finishCell - startCell == -8 || 
			  finishCell - startCell == 9 || finishCell - startCell == -9 || 
			  finishCell - startCell == 7 || finishCell - startCell == -7))
			{
				Check(a,finishCell,&isCheck,&threatCell,colorW);// Check
				
				if(isCheck == 0)
				{
					a[startCell] = ' ';
					a[finishCell] = 'k';
					(*isMoveKingWhite)++;
				}
				else
				{printf("\n   the finish cell is under Check\n");
				isCheck = 0;*isMoveWhite = 0;}
			}
			else if((a[startCell] == 'k') && (a[finishCell] == 'r') && (finishCell == 0 					|| finishCell == 7) && (startCell == 4) && (*isMoveKingWhite == 0) && 				(*isMoveRookWhite < 2)) 
			{
				if(finishCell == 0)
				{
					Check(a,a[2],&isCheck,&threatCell,colorW);// Check
					Check(a,a[3],&isCheck,&threatCell,colorW);
					Check(a,startCell,&isCheck,&threatCell,colorW);
					
					if(isCheck == 0)
					{
						a[startCell] = ' ';
						a[finishCell] = ' ';
						a[3] = 'r';
						a[2] = 'k';
						(*isMoveKingWhite)++;(*isMoveRookWhite)++;
					}
					else{printf("\n  one of the cells is under Check\n");
					isCheck = 0;*isMoveWhite = 0;}
				}
				else
				{
					Check(a,startCell,&isCheck,&threatCell,colorW);
					Check(a,a[5],&isCheck,&threatCell,colorW);// Check
					Check(a,a[6],&isCheck,&threatCell,colorW);
					
					if(isCheck == 0)
					{
						a[startCell] = ' ';
						a[finishCell] = ' ';
						a[5] = 'r';
						a[6] = 'k';
						(*isMoveKingWhite)++;(*isMoveRookWhite)++;
					}
					else{printf("\n  one of the cells is under Check\n");
					isCheck = 0;*isMoveWhite = 0;}
				}
			
			}
			else
			{
				printf("\n   This move is impossible!\n\n");
				*isMoveWhite = 0;
			}
			printf("\n");             
			         
		break;
		
/* pawn */	case 'p':		
			if(((a[finishCell] == ' ') && ((finishCell - startCell == 8) ||   		  		  ((finishCell - startCell == 16) && (startCell < 16)))) ||	         			 	  ((a[finishCell] == 'P' || a[finishCell] == 'R' || a[finishCell] == 'N' || 				  a[finishCell] == 'B' || a[finishCell] == 'Q' || a[finishCell] == 'K') && 				  ((finishCell - startCell == 7) || (finishCell - startCell==9))))
			{
				if(finishCell > 55)
				{
					for(int i = 0; i<1; i--)
					{	
						printf("Choose a piece: 'q', 'b', 'r', 'n' - ");
						scanf("  %c",&pawnTransform);
						fflush(stdin);
						a[finishCell] = pawnTransform;
						a[startCell] = ' ';
								lastFigure = a[finishCell];
						if(a[finishCell] == 'q' || a[finishCell] == 'b' ||
						   a[finishCell] == 'r' || a[finishCell] == 'n')
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
					a[finishCell] = 'p';

						Check(a,cellKingW,&isCheck,&threatCell,colorW);
						if(isCheck == 1)
						{
							a[startCell] = 'p';
							a[finishCell] = lastFigure;
						}
						isCheck = 0;
				}	
			}
			else
			{
				printf("\n   This move is impossible!\n\n");
				*isMoveWhite = 0;
			}
			printf("\n");             

		break;
		               
/*empty cell*/	case ' ':
	      	printf("\n   This cell is empty\n\n");
	      	*isMoveWhite = 0;
		
		break;
		
		default:{*isMoveWhite = 0; printf("\n   Error: wrong operation! \n\n");}
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
			Check(a,cellKingW,&isCheck,&threatCell,colorW);
			
			if(isCheck == 1)
			{
		printf("\n   The white king under the check!\n   You must to make another move\n\n");
			*isMoveWhite = 0;
			}
			else{*globalCheck = 0;}
		}
		if(*globalCheck == 0)
		{
			isCheck = 0;
			Check(a,cellKingB,&isCheck,&threatCell,colorB);
			
			if(isCheck == 1)
			{	
				Mate(a,threatCell,cellKingB,&isMate,colorB);
				if(isMate == 1)
				{
					printf("\n   CheckMate! White won!\n\n");
					*globalCheck = 2;
				}
				else
				{
					printf("\n   The black king under the check!\n\n");
					*globalCheck = 1;
					isCheck = 0;
				}
			}

		}
		
		PrintCB(a);
	}
}
			
