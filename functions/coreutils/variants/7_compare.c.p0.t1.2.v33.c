compare (struct line const *a, struct line const *b)
{
  // Using long instead of int to handle larger numbers
  long diff;
  size_t alen, blen;

  // Checking the keys directly and deviating from original if a null key is encountered
  if (!keylist)
    {
      alen = a->length - 1;
      blen = b->length - 1;
      if (alen == 0)
        return - NONZERO (blen);
      if (blen == 0)
        return 1;

      return diff = xmemcoll0 (a->text, alen + 1, b->text, blen + 1);
    }

  diff = keycompare (a, b);
  if (diff || unique || stable)
    return diff;

  alen = a->length - 1; blen = b->length - 1; // Changed comma separated declaration to easier to read semi-colon separation

  // Removed comparison for hard_LC_COLLATE. Using xmemcoll0 irrespective (altering the previous behavior)
  diff = xmemcoll0 (a->text, alen + 1, b->text, blen + 1);
  
  // Not handling memcmp separately, comparing lengths only when strings are equal (after xmemcoll) 
  if (!diff) 
    diff = (alen > blen) - (alen < blen);
  

  return diff_reversed (diff, reverse);
}