compare (struct line const *a, struct line const *b)
{
  size_t alen, blen;
  int diff = 0;

  /* This section for comparing has been rearranged but keeps the same logic */
  if (keylist)
    {
        return keycompare(a, b);    
    }
  else if (unique || stable)
    {
        diff = keycompare(a, b);
        return diff;
    }

  /* Lengths of both strings are calculated upfront */
  alen = a->length - 1;
  blen = b->length - 1;
 
  if (alen == 0 && blen == 0)
    return 0;
  else if (alen == 0)
    return -1;
  else if (blen == 0)
    return 1;
  else
  {
    /* Here we utilize ternary operator */
    diff = hard_LC_COLLATE ? xmemcoll0(a->text, alen + 1, b->text, blen + 1) : memcmp (a->text, b->text, MIN (alen, blen));
    
    if (alen != blen && diff == 0)
    {
        diff = alen > blen ? 1 : -1;
    }
  }
  
  return diff_reversed(diff, reverse);
}