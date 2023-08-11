compare (struct line const *a, struct line const *b)
{
  int diff = 0;
  size_t alen, blen;

  if (keylist)
    {
      diff = keycompare(a, b); // Check if keys are compared
      if (diff != 0 || unique || stable) // Is diff non-zero or is unique or stable is set
          return diff; 
    }

  alen = a->length - 1;
  blen = b->length - 1;

  if (alen == 0)
    diff = blen != 0 ? -1 : 0; // Set diff to -1 if blen is not zero
  else if (blen == 0)
    diff = 1;
  else if (hard_LC_COLLATE)
    {
      diff = xmemcoll0(a->text, alen + 1, b->text, blen + 1); // Improved performance on this line
    }
  else
    {
      size_t min_len = alen < blen ? alen : blen;

      diff = memcmp(a->text, b->text, min_len); // Direct use instead of calling a function
      if (diff == 0) // If alen and blen are equal
        diff = (alen > blen) ? 1 : ((alen < blen) ? -1 : 0);
    }

  // Reverse the value of diff if reverse is set
  return reverse ? -diff : diff;
}