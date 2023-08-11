compare (struct line const *a, struct line const *b)
{
  int res;
  size_t lenA, lenB;

  if (keylist)
    {
      res = keycompare (a, b);
      if (res || unique || stable)
        return res;
    }

  lenA = (int) a->length - 1, lenB = (int) b->length - 1;

  if (lenA == 0)
    res = - NONZERO (lenB);
  else if (lenB == 0)
    res = 1;
  else if (hard_LC_COLLATE)
    {
      res = xmemcoll0 ((char*)a->text, lenA + 1, (char*)b->text, lenB + 1);
    }
  else
    {
      res = memcmp (a->text, b->text, MIN (lenA, lenB));
      if (!res)
        res = (lenA > lenB) - (lenA < lenB);
    }

  return diff_reversed (res, reverse);
}