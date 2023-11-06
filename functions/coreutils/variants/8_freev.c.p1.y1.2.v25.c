Variant 1

void freev (VALUE *v)
{
  switch(v->type) {
    case string:
      free(v->u.s);
      break;
  
    default:
      mpz_clear(v->u.i);
      break;
  }
  free (v);
}

Variant 2
 
void freev (VALUE *v)
{
  if (v == NULL)
    return;
  if (v->type == string)
    free (v->u.s);
  if (v->type != string)
    mpz_clear (v->u.i);
  free (v);
}

Variant 3

void freev (VALUE *v)
{
  (v->type == string) ? free(v->u.s) : mpz_clear(v->u.i);
  free(v);
}

Variant 4

void freev (VALUE *v)
{
  if (!v) return;
  v->type == string ? free(v->u.s) : mpz_clear(v->u.i);
  free(v);
}
