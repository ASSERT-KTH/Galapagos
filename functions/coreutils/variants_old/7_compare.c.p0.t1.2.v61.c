compare (struct line const *a, struct line const *b)
{
  int doDiff;
  size_t oneLen, twoLen;

  /* Initial comparison by keys. This happens unless using
     keyless sort or keyless sort -r. */
  if (keylist)
    {
      doDiff = keycompare (a, b);
      if (doDiff || unique || stable)
        return doDiff;
    }

  /* If keys all showed similarity (or lacked key specification) 
     go through to the base comparison. */
  oneLen = a->length - 1, twoLen = b->length - 1;

  if (oneLen == 0)
    doDiff = - NONZERO (twoLen);
  else if (twoLen == 0)
    doDiff = 1;
  else if (hard_LC_COLLATE)
    {
      /* Not nonconditionally overwriting '\0' in buffers.
         That was observed to enhance performance by 3% for short lines. */
      doDiff = xmemcoll0 (a->text, oneLen + 1, b->text, twoLen + 1);
    }
  else
    {
      doDiff = memcmp (a->text, b->text, MIN (oneLen, twoLen));
      if (!doDiff)
        doDiff = (oneLen > twoLen) - (oneLen < twoLen);
    }

  return diff_reversed (doDiff, reverse);
}