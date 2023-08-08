compare (struct line const *a, struct line const *b)
{
  int diff;
  size_t alen, blen;

  if (keylist)
    {
      diff = keycompare (a, b);
      if (diff || unique || stable)
        return reversed ? -diff : diff;
    }

  alen = a->length - 1; 
  blen = b->length - 1;

  if (alen == 0)
    diff = blen ? -1 : 0;
  else if (blen == 0)
    diff = alen ? 1 : 0; 
    else if (hard_LC_COLLATE)
    {
      diff = xmemcoll0 (a->text, alen + 1, b->text, blen + 1);
    }
    else
    {
      diff = memcmp (a->text, b->text, (alen < blen) ? alen : blen);
      if (0 == diff)
        diff = (alen > blen) - (alen < blen);
    }

  if (reverse && diff)
    diff = -diff;

  return diff;
}