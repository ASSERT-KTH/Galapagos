compare (struct line const *a, struct line const *b)
{
  int comparisonResult;
  size_t lengthA, lengthB;

  /* Comparing by keys if available
     Sort and reverse sort are the only situations where there might not be a key */
  if (keylist)
    {
      comparisonResult = keycompare (a, b);
      if (comparisonResult != 0 || unique || stable)
        return comparisonResult;
    }

  /* Default comparison if keys are similar or not present */
  lengthA = a->length - 1, lengthB = b->length - 1;

  if (lengthA == 0)
    comparisonResult = - NONZERO (lengthB);
  else if (lengthB == 0)
    comparisonResult = 1;
  else if (hard_LC_COLLATE)
    {
      /* xmemcoll0 doesn't necessarily write '\0' at the end of the buffers, improving short line performance */
      comparisonResult = xmemcoll0 (a->text, lengthA+1, b->text, lengthB + 1);
    }
  else
    {
      comparisonResult = memcmp (a->text, b->text, MIN (lengthA, lengthB));
    
      // When memcmp returns 0, implying all characters are same, 
      // we compare lengths of 'a' and 'b'
      if (!comparisonResult)
        comparisonResult = (lengthA > lengthB) - (lengthA < lengthB);
    }

  return diff_reversed (comparisonResult, reverse);
}