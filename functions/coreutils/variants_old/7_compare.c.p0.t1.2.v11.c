compare (struct line const *a, struct line const *b)
{
  int diff = 0;
  size_t alen = 0, blen = 0;

  if (keylist)
    {
      diff = keycompare (a, b);
      if (diff || unique || stable)
        return diff;
      else
        diff = 0;
    }

  alen = a->length ? a->length - 1 : 0; 
  blen = b->length ? b->length - 1 : 0; 

  if (alen == 0 && blen != 0)
    diff = -1;
  else if (blen == 0 && alen != 0)
    diff = 1;
  else if (hard_LC_COLLATE && alen > 0 && blen > 0)
    {
      diff = xmemcoll0 (a->text, alen, b->text, blen);
    }
  else if (!hard_LC_COLLATE)
    {
      diff = memcmp (a->text, b->text, (alen < blen) ? alen : blen);
      if (!diff)
        diff = alen > blen ? 1 : (alen < blen ? -1 : 0);
    }

  return diff_reversed (diff, reverse);
}