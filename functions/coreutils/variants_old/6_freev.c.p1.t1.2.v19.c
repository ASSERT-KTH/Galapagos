void freev (VALUE *v)
{
  switch(v->type)
  {
    case string: 
        free(v->u.s); 
        break;

    case int:      
    default:       
        mpz_clear(v->u.i); 
        break;
  }
  free(v);
}