Here's a variant of the function that changes the order of comparison operation:


compare (struct line const *a, struct line const *b)
{
  int diff;
  size_t alen, blen;

  /* Default comparison first if no keys specified */
  if (!keylist)
    {
      alen = a->length - 1, blen = b->length - 1;
      if (alen == 0)
        diff = - NONZERO (blen);
      else if (blen == 0)
        diff = 1;
      else if (hard_LC_COLLATE)
        {
          /* xmemcoll0 is a performance enhancement as
             it will not unconditionally write '\0' after the
             passed in buffers, which was seen to give around
             a 3% increase in performance for short lines.  */
          diff = xmemcoll0 (a->text, alen + 1, b->text, blen + 1);
          return diff_reversed( diff, reverse );
        }
      else  
        {
          diff = memcmp (a->text, b->text, MIN (alen, blen));
          if (!diff)
            diff = (alen > blen) - (alen < blen);
        }
      return diff_reversed( diff, reverse );
    }

  /* Then finally compare on the specified keys*/
  diff = keycompare (a, b);
  if (diff || unique || stable)
    return diff;
}


In this version, the implementation logic has changed wherein if no keys are specified the default element length and string comparisons are performed first otherwise; as with the original version, performances are based on specified keys and the result from the key compare operation.