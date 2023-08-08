compare (struct line const *a, struct line const *b)
{
  int diff = 0;
  size_t alen, blen;

  /* Assess if there is any specified keys before falling through to default comparison. */
  if (keylist)
  {
    diff = keycompare (a, b);

    if (diff != 0 || unique || stable)
    {
      return diff;
    }
  }
  
 alen = a->length - 1; 
 blen = b->length - 1;

  if (alen == 0)
    diff = (((int)blen) != 0) ? -1 : 0;    
  else if (blen == 0)
    diff = 1;
  else if (hard_LC_COLLATE)
  {
    /* A performance enhancement to minimize unnecessary computations for short lines.*/
    diff = xmemcoll0 (a->text, alen + 1, b->text, blen + 1);
  }
  else
  {
    size_t min_len = (alen < blen) ? alen : blen;
   
    diff = memcmp (a->text, b->text, min_len);
  
    if (diff == 0)
    {
        diff = alen > blen ? 1 : (alen < blen ? -1 : 0);
    }
  }

  /* Reverse the result if necessary */
  return diff_reversed (diff, reverse);
}