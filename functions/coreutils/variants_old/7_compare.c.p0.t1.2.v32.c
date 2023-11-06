compare (struct line const *a, struct line const *b)
{  
  int diff = 0;
  size_t alen = a->length - 1; 
  size_t blen = b->length - 1;

  if (keylist)
    {
      diff = keycompare (a, b);
      if (diff || unique || stable)
          return diff;
    }
  else
  {
    if (alen == 0)
      diff = - (blen!=0);
    else if (blen == 0)
      diff = 1;
      
    if(diff!=0) 
      return diff_reversed (diff, reverse);
  }

    if (hard_LC_COLLATE)
    {
      diff = xmemcoll0 (a->text, alen + 1, b->text, blen + 1);
    }
    else
    {
      size_t length = (alen < blen) ? alen : blen;
      diff = memcmp (a->text, b->text, length);
      
      if (!diff)
        diff = (alen > blen) ? 1 : ((alen < blen) ? -1 : 0);
    }

  return diff_reversed (diff, reverse);
}
