Variation 1:

void freev (VALUE *v)
{
  switch( v->type )
  {
     case string:
        free (v->u.s);
        break;
 
     default:
        mpz_clear (v->u.i);
  }

  free (v);
}


Variation 2:

void freev (VALUE *v)
{
  v->type == string ? free (v->u.s) : mpz_clear (v->u.i);
  
  free (v);
}


Variation 3:

void freev (VALUE *v)
{
  if (v->type == string)
  {
    free (v->u.s);
  } 
  else
  {
    mpz_clear (v->u.i);
  }  
  free (v);
}

Variation 4:

void freev (VALUE *v)
{
  if (v == NULL)
    return;
  
  if (v->type == string)
    free (v->u.s);
  else
    mpz_clear (v->u.i);
  
  free (v);
}
