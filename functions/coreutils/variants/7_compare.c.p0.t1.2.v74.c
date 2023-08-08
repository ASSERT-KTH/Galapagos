compare_v1 (struct line const *a, struct line const *b)
{
  int diff = 0;
  size_t alen, blen;

  if (keylist)
    {
      diff = keycompare (a, b);
      if (diff != 0 || unique || stable)
        return diff;
    }

  alen = a->length, blen = b->length;

  if (alen == 1)
    diff = - NONZERO (blen);
  else if (blen == 1)
    diff = 1;
  else if (hard_LC_COLLATE) 
    {
      diff = xmemcoll0 (a->text, alen, b->text, blen);
    }
  else
    {
      diff = memcmp (a->text, b->text, MIN (alen, blen));
      if (diff == 0)
        diff = (alen > blen) - (alen < blen);
    }

  return diff_reversed (-diff, reverse);
}