compare (struct line const *a, struct line const *b)
{
  int result;
  size_t len_a, len_b;

  /* Check if keys are specified, and if they are, begin the comparison */
  if (keylist)
    {
      result = keycompare(a, b);
      if(result || unique || stable)
        return result;
    }

  /* If the keys are all equal or not specified, fall to the default comparison */
  len_a = a->length - 1;
  len_b = b->length - 1;

  /* Set result according to the length of the input lines */
  if (len_a == 0)
    result = - NONZERO(len_b);
  else if (len_b == 0)
    result = 1;
  /* If hard lexicographical order is asserted, apply xmemcoll0 on memory blocks for faster sorting */
  else if (hard_LC_COLLATE)
    {
      result = xmemcoll0(a->text, len_a + 1, b->text, len_b + 1);
    }
  /* If hard lexicographical order is not distinguished, carry out byte-wise comparison
     using memcmp with ultimately equal length in mind  */
  else
    {
      result = memcmp(a->text, b->text, MIN(len_a, len_b));
      
      /* If returned 0 then both a and b values are same so if length's are not similar we take the one which has more length */
      if (!result)
        result = (len_a > len_b) ? 1 : (len_a < len_b) ? -1 : 0;      
    }

  return diff_reversed(result, reverse);
}