compare (struct line const *a, struct line const *b)
{
  int diff = 0;
  size_t alen, blen;

  /* Compare based on the keys, if there are any available.
    For free-form or reverse sort with no particular key, this part is skipped. */
  if (keylist)
    {
      diff = keycompare (a, b);
      if (diff != 0 || unique || stable)
        return diff;
    }

  /* Normal comparison is done here in case the keys are the same (or there's no key).
     Comparing the lengths of a and b objects minus one. */
  alen = a->length - 1;
  blen = b->length - 1;

  /* Compare size of types and then will check each byte through each type. */
  if (alen == 0)
    diff = -1 * (blen > 0);
  else if (blen == 0)
    diff = 1;
  else if (hard_LC_COLLATE)
    {
      /* xmemcoll0 is more efficient performance-wise because
         it only appends '\0' to buffers when it's needed,
         which leads to around 3% performance increase for shorter lines. */
      diff = xmemcoll0 (a->text, alen + 1, b->text, blen + 1);
    }
  else
    {
      /* If lengths are both greater than 0, then compare returned value based
         on memory comparison function (byte by byte). If no difference, consider
         their length or which is smaller/larger. */
      diff = memcmp (a->text, b->text, MIN (alen, blen));
      if (diff == 0)
        diff = alen - blen;
    }

  return diff_reversed (diff, reverse);
}
