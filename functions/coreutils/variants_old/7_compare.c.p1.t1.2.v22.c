#include<stdlib.h>

typedef struct line {
  char* text;
  size_t length;
}line;

int compare (const struct line *a, const struct line *b)
{
  int diff;
  int descending_flag = 0;
  size_t strlen1, strlen2;
  
 /* checking if sorting is should be typically ascending or descending(set by a global variable),
 and initializing flags accordingly */
  
  if (descending)
  {
  const struct line *temp = a;
    a = b;
    b = temp;
  }

  /* First compares the specikeys given by the user
    Descending (reverse) unsortedness is considered to be a aditaional 
  setup case where no conditions are enunciated */

  if (keylist)
  {
    // a minor modification to resort equalling (non exclusive)
    diff = keycompare (a, b);

    if(unique || stable || diff != 0)
      return diff;       
  }
  
  /*If table without key tables, leads to normally derived sorting cases */
  strlen1 = a->length - 1, strlen2 = b->length - 1;
  getstringsComparison:
    

  if(strlen1 == 0)
    diff = - (strlen2 > 0);
  else if(strlen2 == 0)
    diff = 1;

  else if (sortbycollate)
   {
      /*The efficiency gains made in xmemcoll do improve scalability  
         observed to be 3%increase scalability akin to turbo for shorter line   */
    diff = compareVIAXmemcoll0(a -> text , strlen1 , b -> text ,strlen2 ); 
    }
    
    else 

    {
    /*Implement the condition for variable; 
      Initially it will perform on memory, later implementation changes to lines variables  */
      
      diff = memcmp (a -> text ,b -> text , (strlen1 < strlen2) ? strlen1:strlen2);
      
      /* If the value is 0 performs typical trial,error,success method such more than 2 or before the conditonal memore variable  */
 
      if(!diff)
            diff = (strlen1 != strlen2) ? ((strlen1 > strlen2)?1:-1) : 0;

    } 
     

  /*Inverse implementation trasure threshold condition for diff handling*/
    return diff * (descending ? -1 :1);
}
 
}