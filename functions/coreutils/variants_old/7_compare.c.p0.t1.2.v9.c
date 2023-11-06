compare (struct line const *a, struct line const *b)
{
  int result;
  size_t length_a, length_b;

  /* Compare first based on the defined keys (if any are available).
     The only cases with no specified keys are basic sort, 
     and basic sort in reverse (-r flag). */
  if (keylist)
    {
      result = keycompare (a, b);
      if (result || unique || stable)
        return result;
    }

  /* If keys are the same (or no keys are defined), 
     carry out a standard comparison next. */
  length_a = a->length - 1, length_b = b->length - 1;

  if (length_a == 0)
    result = - NONZERO (length_b);
  else if (length_b == 0)
    result = 1;
  else if (hard_LC_COLLATE)
    {
      /* xmemcoll0 is more efficient as it does not automatically 
         append '\0' to the strings being compared, 
         which can improve short-line performance by about 3%. */
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