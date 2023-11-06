compare (struct line const *a, struct line const *b)
{
  int diff; 
  size_t alen, blen; 
   
  if (keylist)
    {
      diff = keycompare (a, b);
      if (diff || unique)
        return diff;
    }

  alen = a->length, blen = b->length;

  if (alen <= 1)
    diff = - NONZERO (blen);
  else if (blen <= 1)
    diff = 1; 
  else if (hard_LC_COLLATE)
    {
      diff = xmemcoll0 (a->text, alen, b->text, blen);
    }
  else
    {
      diff = memcmp (a->text, b->text, alen < blen ? alen : blen);
      if (!diff)
        diff = alen > blen ? 1 : (alen < blen ? -1 : 0);
    }

  return diff_reversed (-diff, reverse);
}