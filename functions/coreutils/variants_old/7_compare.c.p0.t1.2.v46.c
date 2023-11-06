compare (struct line const *a, struct line const *b)
{
  int new_diff;
  size_t a_length, b_length;

  /* The attempt to compare based on specific keys (if given). */
  if (keylist)
    {
      new_diff = keycompare (a, b);
      if (new_diff || unique || stable)
        return new_diff;
    }

  /* If all keys compared equally (or keys were not given) */
  
  a_length = a->length - 1, b_length = b->length - 1;

  if (a_length == 0)
    new_diff = - NONZERO (b_length);
  else if (b_length == 0)
    new_diff = 1;
  else if (hard_LC_COLLATE)
    {
      /* Improvement funciton xmemcoll0 aims to not unconditionally overwrite '\0' to short lines, for optimizing efficiency by approximately 3%. */
      new_diff = xmemcoll0 (a->text, a_length + 1, b->text, b_length + 1);
    }
  else
    {
      new_diff = memcmp (a->text, b->text, MIN (a_length, b_length));
      if (!new_diff)
        new_diff = (a_length > b_length) - (a_length < b_length);
    }

  return diff_reversed (new_diff, reverse);
}