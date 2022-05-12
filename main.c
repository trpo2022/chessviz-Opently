#include <stdio.h>

int main()
{
	      char arr[64] = {'r','n','b','q','k','b','n','r',
               	        'p','p','p','p','p','p','p','p',
              	        ' ',' ',' ',' ',' ',' ',' ',' ',
              	        ' ',' ',' ',' ',' ',' ',' ',' ',
              	        ' ',' ',' ',' ',' ',' ',' ',' ',
              	        ' ',' ',' ',' ',' ',' ',' ',' ',
              	        'P','P','P','P','P','P','P','P',
              	        'R','N','B','Q','K','B','N','R'};
             	        
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
