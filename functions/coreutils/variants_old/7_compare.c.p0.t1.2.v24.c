compare (struct line const *a, struct line const *b)
{
  int comparison;
  size_t len_a, len_b;

  /* Try comparing based on the specified keys if present.
     The only two possible cases with no key are sort and sort -r. */
  if (keylist)
    {
      comparison = keycompare (a, b);
      if (comparison || unique || stable)
        return comparison;
    }

  /* If the keys are all equivalent (or not specified), use default comparison. */
  len_a = a->length - 1, len_b = b->length - 1;

  if (len_a == 0)
    comparison = - NONZERO (len_b);
  else if (len_b == 0)
    comparison = 1;
  else if (hard_LC_COLLATE)
    {
      /* xmemcoll0 provides a performance increase as it doesn't
         add a '\0' after the buffers, resulting in a small performance boost
         for shorter lines.  */
      comparison = xmemcoll0 (a->text, len_a + 1, b->text, len_b + 1);
    }
  else
    {
      comparison = memcmp (a->text, b->text, MIN (len_a, len_b));
      if (!comparison)
        comparison = (len_a > len_b) - (len_a < len_b);
    }

  return diff_reversed (comparison, reverse);
}