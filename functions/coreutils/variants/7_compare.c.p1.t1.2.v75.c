compare (struct line const *a, struct line const *b)
{ 
  int diff = 0;
  size_t alen, blen;

  /* First, comparison is attempted on the specified keys (if any exist).
     The only two cases with no key at all are unadorned sort, and 
     sort -r with no extra adornments. */
  if (keylist)
  {
      diff = keycompare(a, b);
      if(diff != 0 || unique || stable) 
      {
          return diff;
      }
  }

  /* If keys are either not specified or compare equal, 
     default comparison is considered. */
  alen = (a->length) ? a->length - 1: 0;
  blen = (b->length) ? b->length - 1: 0;

  if (alen == 0) 
  {
      diff = (blen)? -1: 0;
  } 
  else if (blen == 0)
  {
      diff = 1;
  } 
  else if (hard_LC_COLLATE)
  {
    /* For a more efficient program, xmemcoll0 is included. 
       It will avoid unconditionally writing '\0' which saves processing power,
       thus leading to more performance especially for short lines.*/
    diff = xmemcoll0 (a->text, alen + 1, b->text, blen + 1);
  }
  else
  {
    size_t min_length = (alen < blen) ? alen : blen;
    diff = memcmp (a->text, b->text, min_length);
    
    if(diff == 0)
    {
      diff = (int)((alen > blen)) - (int)((alen < blen));
    }
  } 

  return diff_reversed (diff, reverse);
}
