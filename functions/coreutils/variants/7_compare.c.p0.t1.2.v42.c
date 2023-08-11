compare (struct line const *a, struct line const *b)
{
  int diff = 0;
  size_t alen, blen;
  
  /* Using boolean operator && instead of individual conditions */
  if (keylist && ((diff = keycompare(a, b)) || unique || stable))
  {
    return diff;
  }

  alen = a->length - (size_t)1; /* Explicit (size_t) type casting */
  blen = b->length - (size_t)1;

  if (alen == 0)
    diff = blen != 0 ? -1 : 0; /* Using ternary operator instead if function call */
  else if (blen == 0)
    diff = 1;
  else if (hard_LC_COLLATE)
  {
    diff = xmemcoll0 (a->text, alen + (size_t)1, b->text, blen + (size_t)1); /* Explicit (size_t) type casting */
  }
  else
  {
    size_t min_len = (alen < blen) ? alen : blen; /* Using ternary operator for MIN macro expansion */
    diff = memcmp (a->text, b->text, min_len);
    if (!diff)
    {
      diff = (int)alen - blen; /* Blending two conditions into a single operation */
      if (diff != 0) /* Avoid multiplication for zero value */
        diff = (diff > 0) ? 1 : -1; /* Defined ordered ternary result */
    }
  }
  
  /* Shifting operation order */
  return reverse ? -diff : diff; 
}