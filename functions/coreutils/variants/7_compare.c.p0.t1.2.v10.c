compare (struct line const *a, struct line const *b)
{
  int diff_result;
  int len_diff;
  size_t a_len, b_len;

  if (keylist)
    {
      diff_result = keycompare (a, b);
      if (diff_result || unique || stable)
        return diff_result;
    }

  a_len = a->length - 1, b_len = b->length - 1;
  
  if (a_len == 0)
    diff_result = - NONZERO (b_len);
  else if (b_len == 0)
    diff_result = 1;
  else if (hard_LC_COLLATE)
    {
      diff_result = xmemcoll0 (a->text, a_len + 1, b->text, b_len + 1);
    }
  else
    {
      diff_result = memcmp (a->text, b->text, MIN (a_len, b_len));
      if (diff_result == 0)
      {
          len_diff = (a_len > b_len) - (a_len < b_len); 
          diff_result = len_diff;            
      }
    }

  int reversed_diff = diff_reversed (diff_result, reverse);
  return reversed_diff;
}