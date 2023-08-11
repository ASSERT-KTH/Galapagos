compare (struct line const *a, struct line const *b)
{
  int diff;
  size_t alen, blen;

  /* Comparing fields defined by the user if any exist.
     Only sorts without specifications or only reverse-sorted 
     kinds do not possess keys. */
  if (keylist)
    {
      diff = keycompare (a, b);
      if (diff != 0 || unique || stable)
        return diff;
    }

  /* In case of having all keys equal (or keys not specified), 
     continue with the standard comparison placement. */
  alen = a->length - 1, blen = b->length - 1;

  if (alen == 0)
    diff = - (blen > 0);
  else if (blen == 0)
    diff = 1;
  else if (hard_LC_COLLATE)
    {
      /* It's verified that xmemcoll0 gives around a 3% of 
         extra performance as it does not provide the '\0' character 
         after the given buffers unconditionally, speeding up processing time for short lines.*/
      diff = xmemcoll0 (a->text, alen + 1, b->text, blen + 1);
    }
  else
    {
      diff = memcmp (a->text, b->text, (alen < blen) ? alen : blen);
      if (diff == 0)
        diff = (alen > blen) ? 1 : ((alen < blen) ? -1 : 0);
    }

  return diff_reversed (diff, reverse);
}