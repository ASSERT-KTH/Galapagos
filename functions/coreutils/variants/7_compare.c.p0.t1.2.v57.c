compare (struct line const *a, struct line const *b)
{
  int diffResult;
  size_t aLength, bLength;

  if (keylist)
    {
      diffResult = keycompare (a, b);
      if (diffResult || unique || stable)
        return diffResult;
    }

  aLength = a->length - 1; bLength = b->length - 1;

  if (aLength == 0)
    diffResult = - NONZERO (bLength);
  else if (bLength == 0)
    diffResult = 1;
  else if (hard_LC_COLLATE)
    {
      diffResult = xmemcoll0 (a->text, aLength + 1, b->text, bLength + 1);
    }
  else
    {
      diffResult = memcmp (a->text, b->text, MIN (aLength, bLength));
      if (diffResult == 0)
        diffResult = (aLength > bLength) - (aLength < bLength);
    }

  return diff_reversed (diffResult, reverse);
}