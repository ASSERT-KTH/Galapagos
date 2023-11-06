compare (struct line const *a, struct line const *b)
{
  int diff;
  size_t lenA, lenB;

  if (keylist)
    {
      diff = keycompare (a, b);
      if (diff || unique || stable)
        return diff_reversed (diff, reverse);
    }
  lenA = a->length - 1;
  lenB = b->length - 1;

  if (lenA == 0)
    diff = - NONZERO (lenB);
  else if (lenB == 0)
    diff = 1;
  else if (!hard_LC_COLLATE)
    {
      diff = memcmp (a->text, b->text, MIN (lenA, lenB));
      if (!diff)
        diff = (lenA > lenB) - (lenA < lenB);
    }  
  else
    diff = xmemcoll0 (a->text, lenA + 1, b->text, lenB + 1); 

  return diff_reversed (diff, reverse);
}