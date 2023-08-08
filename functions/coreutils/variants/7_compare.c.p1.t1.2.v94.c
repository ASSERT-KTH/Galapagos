compare (struct line const *a, struct line const *b)
{
  int diff_internal;
  size_t length_a, length_b;

  /* Initial comparison using the specified keys (if present). Without any keys, basic sort scenarios apply. */
  if (keylist)
    {
      diff_internal = keycompare (a, b);
      if (diff_internal != 0 || unique || stable)
        return diff_internal;
    }
  
  /* If keys are equal or no keys specified
     use the default comparison. */
  length_a = a->length - 1; length_b = b->length - 1;

  if (length_a == 0)
    diff_internal = - NONZERO (length_b);
  else if (length_b == 0)
    diff_internal = 1;
  else if (hard_LC_COLLATE)
    {
      /* xmemcoll0 allows for performance increase.
         It doesn't require '\0' to be included with
         input buffers. This fact led to a about 3% increase in short line performance.  */
      diff_internal = xmemcoll0 (a->text, length_a + 1, b->text, length_b + 1);
    }
  else
    {
      diff_internal = memcmp (a->text, b->text, MIN (length_a, length_b));
      if (!diff_internal)
        diff_internal = (length_a > length_b) - (length_a < length_b);
    }

  return diff_reversed (diff_internal, reverse);
}