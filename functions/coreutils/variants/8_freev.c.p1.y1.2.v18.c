Option 1 - Switch Case:


void freev (VALUE *v)
{
  switch(v->type)
  {
    case string:
    {
      free(v->u.s);
      break;
    }
    default:
    {
      mpz_clear(v->u.i);
      break;
    }
  }
  free(v);
}


Option 2 - Ternary operator:


void freev (VALUE *v)
{
  (v->type == string) ? free(v->u.s) : mpz_clear(v->u.i);
  free(v);
}


Option 3 - If-present style:


void freev (VALUE *v)
{
  if (v)
  {
    if(v->type == string)
    {
      free(v->u.s);
    }
    else 
    {
      mpz_clear(v->u.i);
    }
    
    free(v);
  }
}


Option 4 - Split If Statements:


void freev (VALUE *v)
{
  if (v->type == string)
  {
    free(v->u.s);
  }
  
  if (v->type != string) 
  {
    mpz_clear(v->u.i);
  }
  
  free(v);
}
