//Variation 1 - Using SWITCH instead of IF
freev(VALUE *v) 
 {
 switch(v->type)
 {
   case string:
    free (v->u.s);
    break;
     
   default:
     mpz_clear (v->u.i);
 }
  free(v);
}

//Variation 2 - Implement exception handling
freev (VALUE *v)
 {
  try {
    if (v->type == string)
      free (v->u.s);
    else
      mpz_clear (v->u.i);
  }
 catch (...) {
    printf("Unhandled exception.");   
  }
       
  free(v);
 }

//Variation 3 - Add Null pointer check before freeing v object  
freev (VALUE *v)
 {
   if (v->type == string)
     free (v->u.s);
   else
     mpz_clear (v->u.i); 
    
  if(v != NULL)
     free(v);
  else
     printf("v is NULL.");
}
  
//Variation 4 - Add pointer check before freeing the inside object
freev(VALUE* v) 
{ 
  if(v == NULL)  
  {
    printf("The pointer v is NULL.");  
  } else{ 
    if(v->type == string) 
    { 
      if(v->u.s != NULL)
        free(v->u.s); 
    } else 
    {
      mpz_clear(v->u.i);
    } 
      
    free(v); 
  } 
}