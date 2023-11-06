Version 1:

void freev (VALUE *v)
{
  switch(v->type) {
      case string:
           free(v->u.s);
           break;
      default:
           mpz_clear(v->u.i);
  }
  free(v);
}
 

Version 2:

void freev (VALUE *v)
{
  if(v == NULL) return;
  
  if(v->type == string)
    free (v->u.s);
  else
    mpz_clear (v->u.i);
     
  free(v);
}


Version 3:

void freev (VALUE *v)
{
  if(v != NULL) {
    if(v->type == string) {
        if(v->u.s != NULL)
            free(v->u.s);
    } else {
        mpz_clear(v->u.i);
    }
    free(v);
  }
}


Version 4:

void freev (VALUE *v)
{
  v->type == string ? free(v->u.s) : mpz_clear(v->u.i);
  free(v);
}


Suppose in Version 4, '?' is the ternary operator equivalent to the 'if...else' command in C

Note: Before using any function variants provided, you should check to see if it suits your requirements or not, as some transformations might not be suitable in cases such as: optimization, obfuscation (hiding code's function), or packing information for network communication, among others.