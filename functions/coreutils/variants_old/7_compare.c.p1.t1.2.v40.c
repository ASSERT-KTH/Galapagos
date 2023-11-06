int compare (struct line const *a, struct line const *b)
{
  int diff;
  size_t alen, blen;
  
  alen = a->length - 1;
  blen = b->length - 1;
  
  if (!keylist)
    {
      if (alen == 0)
    	diff = - (blen != 0);
      else if (blen == 0)
        diff = 1;
      else if (hard_LC_COLLATE)
        diff = xmemcoll0 (a->text, alen + 1, b->text, blen + 1);
      else
        {
          diff = memcmp (a->text, b->text, (alen < blen ? alen : blen));
          if (!diff)
            diff = (alen > blen) ? 1 : ((alen < blen) ? -1 : 0);
        }

      return diff_reversed (diff, reverse);
    }

  diff = keycompare (a, b);
  
  if (diff || unique || stable)
    return diff;
    
  /* If the keys all compare equal (or no keys were specified)
     fall through to the default comparison.  */
  
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
       diff = memcmp (a->text, b->text, (alen < blen ? alen : blen));
       if (!diff)
          diff = (alen > blen) ? 1 : ((alen < blen) ? -1 : 0);
    }
    
  return diff_reversed (diff, reverse);  
}
