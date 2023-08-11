compare (struct line const *a, struct line const *b)
{
  int diff_result;
  size_t len_a, len_b;
  
  if (keylist != NULL)
    {
      diff_result = keycompare (a, b);
      if (diff_result || unique || stable)
        return diff_result;
    }
  
  len_a = a->length - 1, len_b = b->length - 1;

  if (len_a == 0)
    diff_result = - NONZERO (len_b);
  else if (len_b == 0)
    diff_result = 1;
  else if (hard_LC_COLLATE)
    {
      diff_result = xmemcoll0 (a->text, len_a + 1, b->text, len_b + 1);
    }
  else
    {
      diff_result = memcmp (a->text, b->text, (len_a < len_b) ? len_a : len_b);
      if (diff_result == 0)
        diff_result = (len_a > len_b) ? 1 : -1;
    }

  return diff_reversed (diff_result, reverse);
}