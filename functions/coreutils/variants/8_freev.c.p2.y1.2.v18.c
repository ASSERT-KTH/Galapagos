void freev (VALUE *v)
{  
  if(v == NULL)
    return;
    
  switch(v->type) {
    case string: 
      free(v->u.s); 
      break;
    default: 
      mpz_clear(v->u.i); 
  }
  
  free(v);
  v = NULL;
}