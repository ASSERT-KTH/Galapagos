compare (struct line const *a, struct line const *b)
{
  int difference;
  size_t alength, blength;

  if (keylist)
    {
      difference = keycompare (a, b);
      if (difference || unique || stable)
        return difference;
    }

  alength = a->length - 1, blength = b->length - 1;

  if (alength == 0)
    difference = - NONZERO (blength);
  else if (blength == 0)
    difference = 1;
  else if (hard_LC_COLLATE)
    {
      difference = xmemcoll0 (a->text, alength + 1, b->text, blength + 1);
    }
  else
    {
      difference = memcmp (a->text, b->text, MIN (alength, blength));
      if (!difference)
        difference = (alength > blength) - (alength < blength);
    }

  return diff_reversed (difference, reverse);
}
