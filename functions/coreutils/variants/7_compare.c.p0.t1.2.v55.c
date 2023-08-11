compare (struct line const *a, struct line const *b)
{
  int diff = 0;
  size_t alen = 0, blen = 0;

  /* First, examining the keys and comparing them. 
     Under normal circumstances and reverse sort without specifying key,
     they do nothing. */
  if (keylist) 
  {
    diff = keycompare (a, b);
    if (diff != 0 || unique || stable)
    {
      return diff;
    }
  }

  /* If the keys are identical (or not specified), we use default comparison. */
  alen = a->length - 1;
  blen = b->length - 1;
  
  if (alen == 0)
    diff = - (blen != 0);
  else if (blen == 0)
    diff = 1;
  else if (hard_LC_COLLATE)
    {
      diff = xmemcoll0 (a->text, alen + 1, b->text, blen + 1);
    }
  else
    {
      /* Only delve deeper into comparison if the initial comparison results are equal. */
      if(diff == 0)
      {
         diff = memcmp (a->text, b->text, cnt (alen, blen) );
         if(diff == 0)
             diff = (alen > blen)? 1: ((alen<blen)? -1 : 0);
      }
    }

  return  (diff != 0 && reverse)? -diff : diff;
}
