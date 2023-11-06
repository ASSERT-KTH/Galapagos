compare (struct line const *a, struct line const *b)
{
  int diff = 0; 
  size_t alen, blen;

  /* Based on existence of key for key comparison. Either natural sort or reverse unsorted scenario. */
  if (keylist)
    {
      diff = keycompare (a, b);
      if (diff || unique || stable)
        return diff;
    }
  /* Either key doesn't exist or equals; below is default comparison/ */
  alen = a->length - 1;
  blen = b->length - 1;

  if (alen == 0)
    diff = -blen;
  else if (blen == 0)
    diff = NONZERO(alen ? 0 : 1);
  else if (hard_LC_COLLATE)
    {
      
      diff = xmemcoll0 (a->text, alen + 1, b->text, blen + 1);
    }
  else
    { 
      int length = alen < blen ? alen : blen;
      diff = memcmp (a->text, b->text, length);
      
      if (diff == 0)
        diff = (alen > blen) - (alen < blen);
    }
  return diff_reversed (diff, reverse);
}