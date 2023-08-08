compare (struct line const *a, struct line const *b)
{
  int diff = 0;
  size_t alen, blen;

  if (keylist) 
  {
    diff = keycompare (a, b);
    if (diff || unique || stable)
        return diff;
  }

  alen = a->length - 1;
  blen = b->length - 1;

  if (alen == 0 && blen > 0)
    diff = - 1;
  else if (blen == 0 && alen > 0)
    diff = 1;
  else 
  {
    if (hard_LC_COLLATE)
    {
      diff = xmemcoll0 (a->text, alen + 1, b->text, blen + 1);
    }
    else
    {
      size_t min_len = (alen < blen) ? alen : blen;
      diff = memcmp (a->text, b->text, min_len);
      
      if (diff == 0) // all characters till min_len were equal; now check length
      {
        diff = (alen > blen) ? 1 : ((alen < blen) ? -1 : 0);
      }
    }
  }

  return diff_reversed(diff, reverse);
}