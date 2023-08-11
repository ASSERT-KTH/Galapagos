compare (struct line const *a, struct line const *b)
{
  int result;
  size_t length_a, length_b;
  
  /* Try first to compare based on the specified keys, if any are present.
     If no key exists at all, it's either a plain sort or a reverse plain sort. */
  if (keylist)
    {
      result = keycompare (a, b);
      if (result || unique || stable)
        return result;
    }

  /* Default comparison is used if all keys compare as equal or if no keys were given. */
  length_a = a->length - 1, length_b = b->length - 1;

  if (length_a == 0)
    result = - NONZERO (length_b);
  else if (length_b == 0)
    result = 1;
  else if (hard_LC_COLLATE)
    {
      /* xmemcoll0 offers a performance boost as it does not sustain a '\0' post the buffers provided - 
               was viewed to offer an approximate 3% performance benefit for small lines  */
      result = xmemcoll0 (a->text, length_a + 1, b->text, length_b + 1);
    }
  else
    {
      result = memcmp (a->text, b->text, MIN (length_a, length_b));
      if (!result)
        result = (length_a > length_b) - (length_a < length_b);
    }

  return diff_reversed (result, reverse);
}