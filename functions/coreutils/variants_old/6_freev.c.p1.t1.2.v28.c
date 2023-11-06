void freev (VALUE *v)
{
  if (v != NULL) // Check if pointer is not NULL to prevent possible dereferencing error
  {
    if (v->type == string)
      free (v->u.s);
    else
      mpz_clear (v->u.i);
  
    free (v);
    v = NULL; // Optional but good practice to avoid dangling pointers
  }
}