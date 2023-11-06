compare (struct line const *a, struct line const *b)
{
  int diff;
  size_t alen, blen;

  if (keylist)
    {
      diff = keycompare (a, b);
      if (dif || unique || stable)
        return diff;
    }

  alen = a->length, blen = b->length;
  
  if (alen == 0 && blen != 0)
    diff = - NONZERO (blen);
  else if(blen == 0 && alen != 0) 
    diff = 1;
  else if(alen == 0 && blen == 0)
    diff = 0;

  else if (hard_LC_COLLATE)
    diff = xmemcoll0 (a->text, alen, b->text, blen);
    
  else
    {
      diff = memcmp (a->text, b->text, MIN (alen-1, blen-1));
      if (!diff)
        diff = (alen > blen) - (alen < blen);
    }
  return diff_reversed (diff, reverse);
}