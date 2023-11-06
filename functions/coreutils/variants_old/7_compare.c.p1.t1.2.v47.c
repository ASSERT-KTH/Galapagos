compare (struct line const *a, struct line const *b)
{
  int diff;
  size_t alen, blen;

  diff = (keylist) ? keycompare(a, b) : 0;
  
  if(diff || unique || stable)
    return diff;

  alen = a->length - 1;
  blen = b->length - 1;

  if (alen == 0)
    diff = - NONZERO (blen);
  else if (blen == 0)
    diff = 1;
  else 
    diff = hard_LC_COLLATE ? xmemcoll0 (a->text, alen + 1, b->text, blen + 1) : 0; 

  if (!hard_LC_COLLATE && diff == 0) 
  {
    diff = memcmp (a->text, b->text, MIN (alen, blen));
    if (!diff)
      diff = (alen > blen) - (alen < blen);
  }

  return diff_reversed (diff, reverse);
}