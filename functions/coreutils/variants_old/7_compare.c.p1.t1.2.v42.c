compare (struct line const *a, struct line const *b)
{
  int compareIndex;
  size_t aLength, bLength;
  
  if (keylist)
  {
    compareIndex = keycompare (a, b);
    if (compareIndex || unique || stable)
        return compareIndex;
  }

  aLength = a->length - 1;
  bLength = b->length - 1;

  if (aLength == 0)
    compareIndex = - NONZERO (bLength);
  else if (bLength == 0)
    compareIndex = 1;
  else if (hard_LC_COLLATE)
  {
      compareIndex = xmemcoll0 (a->text, aLength + 1, b->text, bLength + 1);
  }
  else
  {
      compareIndex = memcmp (a->text, b->text, MIN (aLength, bLength));
      if (!compareIndex)
        compareIndex = (aLength > bLength) - (aLength < bLength);
  }

  return diff_reversed (compareIndex, reverse);
}