#include <stdio.h>

void Check(char a[], int cell, int *isCheck, int *threatCell, char color)
{ 
	if(color == 'W') //check basic pieces
	{
if(a[cell + 7] =='P' && (cell / 8 == (cell + 7) / 8 - 1))
{
	*isCheck = 1;
	if(!(*threatCell == 999)){*threatCell = cell+7;}
}
if(a[cell+9] =='P' && (cell / 8 == (cell + 9) / 8 - 1))
{
	*isCheck = 1;
	if(!(*threatCell == 999)){*threatCell = cell+9;}
} 
if(a[cell+1] =='K' && (cell / 8 == (cell + 1) / 8))
{
	if(!(*threatCell == 999)){*isCheck = 1;*threatCell = cell+1;}
}      
if(a[cell-1] =='K' && (cell / 8 == (cell - 1) / 8))
{
	if(!(*threatCell == 999)){*isCheck = 1;*threatCell = cell-1;}
}     
if(a[cell+8] =='K')
{
	if(!(*threatCell == 999)){*isCheck = 1;*threatCell = cell+8;}
}  
if(a[cell-8] =='K')
{
	if(!(*threatCell == 999)){*isCheck = 1;*threatCell = cell-8;}
} 
if(a[cell-7] =='K' && (cell / 8 == (cell - 7) / 8 + 1))
{
	if(!(*threatCell == 999)){*isCheck = 1;*threatCell = cell-7;}
}
if(a[cell+7] =='K' && (cell / 8 == (cell + 7) / 8 - 1))
{
	if(!(*threatCell == 999)){*isCheck = 1;*threatCell = cell+7;}
}
if(a[cell-9] =='K' && (cell / 8 == (cell - 9) / 8 + 1))
{
	if(!(*threatCell == 999)){*isCheck = 1;*threatCell = cell-9;}
}
if(a[cell+9] =='K' && (cell / 8 == (cell + 9) / 8 - 1))
{
	if(!(*threatCell == 999)){*isCheck = 1;*threatCell = cell+9;}
} 
if(a[cell-6] =='N' && (cell / 8 == (cell - 6) / 8 + 1))
{
	*isCheck = 1;
	if(!(*threatCell == 999)){*threatCell = cell-6;}
} 
if(a[cell+6] =='N' && (cell / 8 == (cell + 6) / 8 - 1))
{
	*isCheck = 1;
	if(!(*threatCell == 999)){*threatCell = cell+6;}
} 
if(a[cell-10] =='N' && (cell / 8 == (cell - 10) / 8 + 1))
{
	*isCheck = 1;
	if(!(*threatCell == 999)){*threatCell = cell-10;}
} 
if(a[cell+10] =='N' && (cell / 8 == (cell + 10) / 8 - 1))
{
	*isCheck = 1;
	if(!(*threatCell == 999)){*threatCell = cell+10;}
} 
if(a[cell-15] =='N' && (cell / 8 == (cell - 15) / 8 + 2))
{
	*isCheck = 1;
	if(!(*threatCell == 999)){*threatCell = cell-15;}
} 
if(a[cell+15] =='N' && (cell / 8 == (cell + 15) / 8 - 2))
{
	*isCheck = 1;
	if(!(*threatCell == 999)){*threatCell = cell+15;}
} 
if(a[cell-17] =='N' && (cell / 8 == (cell - 17) / 8 + 2))
{
	*isCheck = 1;
	if(!(*threatCell == 999)){*threatCell = cell-17;}
} 
if(a[cell+17] =='N' && (cell / 8 == (cell + 17) / 8 - 2))
{
	*isCheck = 1;
	if(!(*threatCell == 999)){*threatCell = cell+17;}
} 
 	}
	
	if(color == 'W')
	{
		if(*isCheck == 0)
		{
			for(int i = cell; i > (cell - (cell % 8 + 1)); i--) // left
			{
		if(!(a[i] ==' ') && !(a[i] =='R') && !(a[i] =='Q') && !(a[i] =='k') && !(i == cell))
				{break;}
				
				if(((a[i] == 'R') || (a[i] == 'Q')) && !(i == cell))
				{*isCheck = 1;if(!(*threatCell == 999)){*threatCell = i;};break;}
			}
		}
		if(*isCheck == 0)
		{
			for(int i = cell; i < (cell + (8-(cell % 8 + 1))); i++) // right
			{
		if(!(a[i] ==' ') && !(a[i] =='R') && !(a[i] =='Q') && !(a[i] =='k') && !(i == cell))
				{break;}
				if(((a[i] == 'R') || (a[i] == 'Q')) && !(i == cell))
				{*isCheck = 1;if(!(*threatCell == 999)){*threatCell = i;};break;}
			}
		}
		if(*isCheck == 0)
		{
			for(int i = cell; i < 64; i+=8) // down
			{
		if(!(a[i] ==' ') && !(a[i] =='R') && !(a[i] =='Q') && !(a[i] =='k') && !(i == cell))
				{break;}
				
				if(((a[i] == 'R') || (a[i] == 'Q')) && !(i == cell))
				{*isCheck = 1;if(!(*threatCell == 999)){*threatCell = i;};break;}
			}
		}
		if(*isCheck == 0)
		{
			for(int i = cell; i >= 0; i-=8) // up
			{
		if(!(a[i] ==' ') && !(a[i] =='R') && !(a[i] =='Q') && !(a[i] =='k') && !(i == cell))
				{break;}
				
				if(((a[i] == 'R') || (a[i] == 'Q')) && !(i == cell))
				{*isCheck = 1;if(!(*threatCell == 999)){*threatCell = i;};break;}
			}
		}
		if(*isCheck == 0)
		{
			for(int i = cell; i < 64; i+=9) // right-down
			{
		if(!(a[i] ==' ') && !(a[i] =='B') && !(a[i] =='Q') && !(a[i] =='k') && !(i == cell))
				{break;}
				
				if(((a[i] == 'B') || (a[i] == 'Q')) && !(i == cell))
				{*isCheck = 1;if(!(*threatCell == 999)){*threatCell = i;};break;}
			}
		}
		if(*isCheck == 0)
		{
			for(int i = cell; i < 64; i+=7) // left-down
			{
		if(!(a[i] ==' ') && !(a[i] =='B') && !(a[i] =='Q') && !(a[i] =='k') && !(i == cell))
				{break;}
				
				if(((a[i] == 'B') || (a[i] == 'Q')) && !(i == cell))
				{*isCheck = 1;if(!(*threatCell == 999)){*threatCell = i;};break;}
			}
		}
		if(*isCheck == 0)
		{
			for(int i = cell; i > 0; i-=7) // right-up
			{
		if(!(a[i] ==' ') && !(a[i] =='B') && !(a[i] =='Q') && !(a[i] =='k') && !(i == cell))
				{break;}
				
				if(((a[i] == 'B') || (a[i] == 'Q')) && !(i == cell))
				{*isCheck = 1;if(!(*threatCell == 999)){*threatCell = i;};break;}
			}
		}
		if(*isCheck == 0)
		{
			for(int i = cell; i > 0; i-=9) // left-up
			{
		if(!(a[i] ==' ') && !(a[i] =='B') && !(a[i] =='Q') && !(a[i] =='k') && !(i == cell))
				{break;}
				
				if(((a[i] == 'B') || (a[i] == 'Q')) && !(i == cell))
				{*isCheck = 1;if(!(*threatCell == 999)){*threatCell = i;};break;}
			}
		}
	}
	if(color == 'B')
	{
if(a[cell + 7] =='p' && (cell / 8 == (cell - 7) / 8 - 1))
{
	*isCheck = 1;
	if(!(*threatCell == 999)){*threatCell = cell-7;}
}
if(a[cell+9] =='p' && (cell / 8 == (cell - 9) / 8 - 1))
{
	*isCheck = 1;
	if(!(*threatCell == 999)){*threatCell = cell-9;}
} 
if(a[cell+1] =='k' && (cell / 8 == (cell + 1) / 8))
{
	if(!(*threatCell == 999)){*isCheck = 1;*threatCell = cell+1;}
}      
if(a[cell-1] =='k' && (cell / 8 == (cell - 1) / 8))
{
	if(!(*threatCell == 999)){*isCheck = 1;*threatCell = cell-1;}
}     
if(a[cell+8] =='k')
{
	if(!(*threatCell == 999)){*isCheck = 1;*threatCell = cell+8;}
}  
if(a[cell-8] =='k')
{
	if(!(*threatCell == 999)){*isCheck = 1;*threatCell = cell-8;}
} 
if(a[cell-7] =='k' && (cell / 8 == (cell - 7) / 8 + 1))
{
	if(!(*threatCell == 999)){*isCheck = 1;*threatCell = cell-7;}
}
if(a[cell+7] =='k' && (cell / 8 == (cell + 7) / 8 - 1))
{
	if(!(*threatCell == 999)){*isCheck = 1;*threatCell = cell+7;}
}
if(a[cell-9] =='k' && (cell / 8 == (cell - 9) / 8 + 1))
{
	if(!(*threatCell == 999)){*isCheck = 1;*threatCell = cell-9;}
}
if(a[cell+9] =='k' && (cell / 8 == (cell + 9) / 8 - 1))
{
	if(!(*threatCell == 999)){*isCheck = 1;*threatCell = cell+9;}
}
if(a[cell-6] =='n' && (cell / 8 == (cell - 6) / 8 + 1))
{
	if(!(*threatCell == 999)){*isCheck = 1;*threatCell = cell-6;}
} 
if(a[cell+6] =='n' && (cell / 8 == (cell + 6) / 8 - 1))
{
	if(!(*threatCell == 999)){*isCheck = 1;*threatCell = cell+6;}
} 
if(a[cell-10] =='n' && (cell / 8 == (cell - 10) / 8 + 1))
{
	if(!(*threatCell == 999)){*isCheck = 1;*threatCell = cell-10;}
}
if(a[cell+10] =='n' && (cell / 8 == (cell + 10) / 8 - 1))
{
	if(!(*threatCell == 999)){*isCheck = 1;*threatCell = cell+10;}
}
if(a[cell-15] =='n' && (cell / 8 == (cell - 15) / 8 + 2))
{
	if(!(*threatCell == 999)){*isCheck = 1;*threatCell = cell-15;}
}
if(a[cell+15] =='n' && (cell / 8 == (cell + 15) / 8 - 2))
{
	if(!(*threatCell == 999)){*isCheck = 1;*threatCell = cell+15;}
}
if(a[cell-17] =='n' && (cell / 8 == (cell - 17) / 8 + 2))
{
	if(!(*threatCell == 999)){*isCheck = 1;*threatCell = cell-17;}
}
if(a[cell+17] =='n' && (cell / 8 == (cell + 17) / 8 - 2))
{
	if(!(*threatCell == 999)){*isCheck = 1;*threatCell = cell+17;}
}
 	}
	
	if(color == 'B')
	{
		if(*isCheck == 0)
		{
			for(int i = cell; i > (cell - (cell % 8 + 1)); i--) // left
			{
		if(!(a[i] ==' ') && !(a[i] =='r') && !(a[i] =='q') && !(a[i] =='K') && !(i == cell))
				{break;}
				
				if(((a[i] == 'r') || (a[i] == 'q')) && !(i == cell))
				{*isCheck = 1;if(!(*threatCell == 999)){*threatCell = i;};break;}
			}
		}
		if(*isCheck == 0)
		{
			for(int i = cell; i < (cell + (8-(cell % 8 + 1))); i++) // right
			{
		if(!(a[i] ==' ') && !(a[i] =='r') && !(a[i] =='q') && !(a[i] =='K') && !(i == cell))
				{break;}
				
				if(((a[i] == 'r') || (a[i] == 'q')) && !(i == cell))
				{*isCheck = 1;if(!(*threatCell == 999)){*threatCell = i;};break;}
			}
		}
		if(*isCheck == 0)
		{
			for(int i = cell; i < 64; i+=8) // down
			{
		if(!(a[i] ==' ') && !(a[i] =='r') && !(a[i] =='q') && !(a[i] =='K') && !(i == cell))
				{break;}
				if(((a[i] == 'r') || (a[i] == 'q')) && !(i == cell))
				{*isCheck = 1;if(!(*threatCell == 999)){*threatCell = i;};break;}
			}
		}
		if(*isCheck == 0)
		{
			for(int i = cell; i >= 0; i-=8) // up
			{
		if(!(a[i] ==' ') && !(a[i] =='r') && !(a[i] =='q') && !(a[i] =='K') && !(i == cell))
				{break;}
				
				if(((a[i] == 'r') || (a[i] == 'q')) && !(i == cell))
				{*isCheck = 1;if(!(*threatCell == 999)){*threatCell = i;};break;}
			}
		}
		if(*isCheck == 0)
		{
			for(int i = cell; i < 64; i+=9) // right-down
			{
		if(!(a[i] ==' ') && !(a[i] =='b') && !(a[i] =='q') && !(a[i] =='K') && !(i == cell))
				{break;}
				
				if(((a[i] == 'b') || (a[i] == 'q')) && !(i == cell))
				{*isCheck = 1;if(!(*threatCell == 999)){*threatCell = i;};break;}
			}
		}
		if(*isCheck == 0)
		{
			for(int i = cell; i < 64; i+=7) // left-down
			{
		if(!(a[i] ==' ') && !(a[i] =='b') && !(a[i] =='q') && !(a[i] =='K') && !(i == cell))
				{break;}
				
				if(((a[i] == 'b') || (a[i] == 'q')) && !(i == cell))
				{*isCheck = 1;if(!(*threatCell == 999)){*threatCell = i;};break;}
			}
		}
		if(*isCheck == 0)
		{
			for(int i = cell; i > 0; i-=7) // right-up
			{
		if(!(a[i] ==' ') && !(a[i] =='b') && !(a[i] =='q') && !(a[i] =='K') && !(i == cell))
				{break;}
				
				if(((a[i] == 'b') || (a[i] == 'q')) && !(i == cell))
				{*isCheck = 1;if(!(*threatCell == 999)){*threatCell = i;};break;}
			}
		}
		if(*isCheck == 0)
		{
			for(int i = cell; i > 0; i-=9) // left-up
			{
		if(!(a[i] ==' ') && !(a[i] =='b') && !(a[i] =='q') && !(a[i] =='K') && !(i == cell))
				{break;}
					
				if(((a[i] == 'b') || (a[i] == 'q')) && !(i == cell))
				{*isCheck = 1;if(!(*threatCell == 999)){*threatCell = i;};break;}
			}
		}	
	}
}
