compare (struct line const *a, struct line const *b)
{
  int difference;
  size_t lenA, lenB;

  if (keylist)
    {
      difference = keycompare (a, b);
      if (difference || unique || stable)
        return difference;
    }

  lenA = a->length - 1; 
  lenB = b->length - 1;

  if (lenA == 0)
    difference = - NONZERO (lenB);
  else if (lenB == 0)
    difference = 1;
  else if (hard_LC_COLLATE)
    {
      difference = xmemcoll0 (a->text, lenA + 1, b->text, lenB + 1);
    }
  else
    {
      difference = memcmp (a->text, b->text, (lenA < lenB) ? lenA : lenB);
      if (!difference)
        difference = (lenA > lenB) ? 1 : ((lenA < lenB) ? -1 : 0);
    }

  return diff_reversed (difference, reverse);
}