int compare (struct line const *a, struct line const *b)
{
  int diff = 0;
  size_t alen = a->length - 1, blen = b->length - 1;

  if (keylist != NULL)
  {
      if((diff = keycompare (a, b)) != 0 || unique || stable)
        return diff;
  }

  if (alen == 0)
    return - NONZERO (blen);
  else if (blen == 0)
    return 1;
  
  if (hard_LC_COLLATE)
  {
      diff = xmemcoll0 (a->text, alen + 1, b->text, blen + 1);
  }
  else
  {
      if((diff = memcmp (a->text, b->text, MIN (alen, blen))) == 0)
        diff = (alen > blen) - (alen < blen);
  }

  return diff_reversed (diff, reverse);
}