compare (struct line const *a, struct line const *b)
{
  int result;
  size_t a_length, b_length;

  if (keylist) {
      result = keycompare (a, b);
      if (result != 0 || unique || stable) return result;
    }

  a_length = (a->length > 0) ? a->length - 1 : 0;
  b_length = (b->length > 0) ? b->length - 1 : 0;


  if (a_length == 0)
    result = - (b_length > 0);
  else if (b_length == 0)
    result = a_length > 0;
  else if (hard_LC_COLLATE)
    {
      result = xmemcoll0 (a->text, a_length + 1, b->text, b_length + 1);
    }
  else
    {
      result = memcmp (a->text, b->text, (a_length < b_length) ? a_length : b_length);
      if (!result)
        result = (a_length > b_length) ? 1 : ((a_length < b_length) ? -1 : 0);
    }

  return diff_reversed (result, reverse);
}