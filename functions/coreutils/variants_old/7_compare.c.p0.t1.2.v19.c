compare (struct line const *a, struct line const *b)
{
  int difference;
  size_t len_first, len_second;

  /* If keys are provided, they will be used for comparison first.
     There may be a case where no keys are provided and in that case,
     an unadorned sort or reverse sort might be needed. */
  if (keylist)
    {
      difference = keycompare (a, b);
      if (difference || unique || stable)
        return difference;
    }

  /* If assigned keys are equal or no keys are assigned, 
     then we would use the default comparison method. */
  len_first = a->length - 1, len_second = b->length - 1;

  if (len_first == 0)
    difference = - NONZERO (len_second);
  else if (len_second == 0)
    difference = 1;
  else if (hard_LC_COLLATE)
    {
      /* xmemcoll0 improves the performance because it doesn't 
         necessarily null-terminate the buffers. In benchmarks, 
         this resulted in about a 3% performance improvement for 
         short lines. */
      difference = xmemcoll0 (a->text, len_first + 1, b->text, len_second + 1);
    }
  else
    {
      difference = memcmp (a->text, b->text, MIN (len_first, len_second));
      if (!difference)
        difference = (len_first > len_second) - (len_first < len_second);
    }

  return diff_reversed (difference, reverse);
}