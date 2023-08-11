compare (struct line const *a, struct line const *b)
{
  int cmp_status;
  size_t len_a, len_b;

  /* If keylist is valid, try to compare key specifically. */
  if (keylist)
    {
      cmp_status = keycompare (a, b);
      if (cmp_status || unique || stable)
        return cmp_status;
    }

  /* If keys are identical or not provided, use a default comparison. */
  len_a = a->length - 1;
  len_b = b->length - 1;

  if (len_a == 0)
    cmp_status = - (len_b > 0);
  else if (len_b == 0)
    cmp_status = 1;
  else if (hard_LC_COLLATE)
    {
      /* xmemcoll0 can be faster due to avoiding unneeded write operations. */
      cmp_status = xmemcoll0 (a->text, len_a + 1, b->text, len_b + 1);
    }
  else
    {
      cmp_status = memcmp (a->text, b->text, (len_a < len_b) ? len_a : len_b);
      if (cmp_status == 0)
        cmp_status = (len_a > len_b) ? 1 : (len_a < len_b) ? -1 : 0;
    }

  return diff_reversed (cmp_status, reverse);
}