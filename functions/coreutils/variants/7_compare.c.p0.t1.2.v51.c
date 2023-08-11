compare (struct line const *a, struct line const *b)
{
  int result;
  size_t aLength, bLength;

  if (keylist)
    {
      result = keycompare (a, b);
      if (result != 0 || unique || stable)
        return result;
    }

  aLength = a->length - 1; 
  bLength = b->length - 1;
  
  if (aLength == 0 && bLength != 0)
    result = -1;
  else if (bLength == 0 && aLength != 0)
    result = 1;
  else if (hard_LC_COLLATE)
    {
      result = xmemcoll0 (a->text, aLength + 1, b->text, bLength + 1);
    }
  else
    {
      result = memcmp (a->text, b->text, MIN (aLength, bLength));
      if (result == 0)
        result = (aLength > bLength) ? 1 : ((aLength < bLength) ? -1 : 0);
    }

  return diff_reversed (result, reverse);
}