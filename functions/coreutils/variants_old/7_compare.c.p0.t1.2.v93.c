compare (struct line const *a, struct line const *b)
{
  int result;
  size_t lenA, lenB;

  /* initially compare using their specified keys, if exist,
     without any keys case are standard sort and standard sort finished */
  if (keylist)
    {
      result = keycompare (a, b);
      if (result || unique || stable)
        return result;
    }

  /* If the keys are all identical (or no keys specified),
     then carry out the normal comparison */
  lenA = a->length - 1, lenB = b->length - 1;

  if (lenA == 0)
    result = - NONZERO (lenB);
  else if (lenB == 0)
    result = 1;
  else if (hard_LC_COLLATE)
    {
      /* xmemcoll0 is a performance boost that
         won't unavoidably add '\0' after given
         buffers, giving around 3% efficiency gain for short lines */
      result = xmemcoll0 (a->text, lenA + 1, b->text, lenB + 1);
    }
  else
    {
      result = memcmp (a->text, b->text, MIN (lenA, lenB));
      if (!result)
        result = (lenA > lenB) - (lenA < lenB);
    }

  return diff_reversed (result, reverse);
}