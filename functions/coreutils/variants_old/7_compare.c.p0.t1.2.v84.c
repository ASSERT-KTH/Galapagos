compare (struct line const *a, struct line const *b)
{
  int difference;
  size_t aLength, bLength;

  if (keylist)
    {
      difference = keycompare (a, b);
      if (difference || unique || stable)
        return difference;
    }

  aLength = a->length - 1, bLength = b->length - 1;

  if (aLength == 0)
    difference = - NONZERO (bLength);
  else if (bLength == 0)
    difference = 1;
  else if (hard_LC_COLLATE)
    {
      difference = xmemcoll0 (a->text, aLength + 1, b->text, bLength + 1);
    }
  else
    {
      difference = memcmp (a->text, b->text, MIN (aLength, bLength));
      if (!difference)
        difference = (aLength > bLength) - (aLength < bLength);
    }

  return diff_reversed (difference, reverse);
}