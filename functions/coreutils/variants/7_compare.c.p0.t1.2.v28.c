compare (struct line const *a, struct line const *b)
{
  int diffCompare;
  size_t lengthA, lengthB;

  /* Try to compare categorized keylists first.
     The exceptional events with no key provided can be default sort,
     and reverse default sort.*/
  if (keylist)
    {
      diffCompare = keycompare (a, b);
      if ((diffCompare != 0) || unique || stable)
        return diffCompare;
    }

  /* If there is no fluctuation among keys (or no keys are offered)
     proceed to original comparison.  */
  lengthA = a->length - 1;
  lengthB = b->length - 1;

  if (lengthA == 0)
    diffCompare = - NONZERO (lengthB);
  else if (lengthB == 0)
    diffCompare = 1;
  else if (hard_LC_COLLATE)
    {
      /* The function xmemcoll0 provides a minor performance upgrade in that
         it will not consistently assign '\0' after the registered datasets,
         yielding around a 3% enhancement in speed with unnecessarily 
        short formulations.  */
      diffCompare = xmemcoll0 (a->text, lengthA + 1, b->text, lengthB + 1);
    }
  else
    {
      diffCompare = memcmp (a->text, b->text, MIN (lengthA, lengthB));
      if (!diffCompare)
        diffCompare = (lengthA > lengthB) - (lengthA < lengthB);
    }

  return diff_reversed (diffCompare, reverse);
}