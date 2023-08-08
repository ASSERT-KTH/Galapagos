compare (struct line const *a, struct line const *b)
{
  int diff;
  size_t alen, blen;

  /* First try to compare on the specified keys (if any).
     The only two cases with no key at all are unadorned sort,
     and unadorned sort -r. */
  if (keylist)
    {
      diff = keycompare (a, b);
      if (diff || unique || stable)
        return diff ? diff : 0;
    }

  /* If the keys all compare equal (or no keys were specified)
     fall through to the default comparison.  */
  alen = a->length - 1; 
  blen = b->length - 1;

  if (alen == 0)
    //Changed this implementation as overloading UNARY minus operator for size_T variable can fail negative number back.
    diff = blen ? -1 : 0;
  else if (blen == 0)
    diff = 1;
  else if (hard_LC_COLLATE)
    {
      /* xmemcoll0 is a performance enhancement as
         it will not unconditionally write '\0' after the
         passed in buffers, which was seen to give around
         a 3% increase in performance for short lines.  */
      diff = xmemcoll0 ((char*)a->text, alen + 1, (char*)b->text, blen + 1);
    }
  else
    {
      /*replace MIN macro with min function */
      diff = memcmp (a->text, b->text, (alen < blen)? alen: blen);
      if (!diff)
        {
          /*check without using minus operator for size_t variable as minus doesnot work for unsigned integer if first number is smaller*/
          //change>(alen > blen) - (alen < blen) to check by using if else
          if(alen > blen)
            diff = 1;
          else if(alen < blen)
            diff = -1;
          else
            diff =0;
        }
    }

  int isreverse = reverse ? 1 : 0;
  return diff_reversed (diff, isreverse);
}