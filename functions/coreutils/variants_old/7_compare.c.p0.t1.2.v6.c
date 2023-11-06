compare (struct line const *a, struct line const *b)
{
  int comparison;
  size_t a_length, b_length;

  /* First consider case of comparing the defined keys (if available).
     The only two exceptions with no key at all are simple sort,
     and simple reversed sort. */
  if (keylist)
    {
      comparison = keycompare (a, b);
      if (comparison || unique || stable)
        return comparison;
    }

  /* If the keys all compare the same (or no keys were found)
     proceed to the default comparison.  */
  a_length = a->length - 1, b_length = b->length - 1;

  if (a_length == 0)
    comparison = - NONZERO (b_length);
  else if (b_length == 0)
    comparison = 1;
  else if (hard_LC_COLLATE)
    {
      /* xmemcoll0 is used due to its performance advantage as
         it will not always write '\0' at the end of the
         proceeding buffers, which was seen to speed up performance.
         This is particularly true for shorter lines.  */
      comparison = xmemcoll0 (a->text, a_length + 1, b->text, b_length + 1);
    }
  else
    {
      comparison = memcmp (a->text, b->text, MIN (a_length, b_length));
      if (!comparison)
        comparison = (a_length > b_length) - (a_length < b_length);
    }

  return diff_reversed (comparison, reverse);
}