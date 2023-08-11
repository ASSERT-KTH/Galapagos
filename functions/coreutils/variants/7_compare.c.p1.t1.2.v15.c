Here is a variant of the code above which retains its original behavior. The code attempts to make better use of conditional control flow structures, reducing the possibility of excessive computation. Duplicated code was removed and the computational steps slightly rearranged.


compare (struct line const *a, struct line const *b)
{  
  int diff;
  size_t alen, blen;

  if (keylist) {
    diff = keycompare (a, b);
    if (diff == 0 && (!unique && !stable)) {
      return diff_reversed(alen == blen ? 0 : ((alen > blen) * 2 - 1), reverse);
    }
    return diff;
  }

  alen = a->length - 1;
  blen = b->length -1;
  
  if( alen!=0 && blen!=0 && hard_LC_COLLATE) {
      diff = xmemcoll0 (a->text, alen + 1, b->text, blen + 1);
  } else {
      diff = memcmp (a->text, b->text, MIN (alen, blen));
      if (diff==0) diff = (alen > blen) - (alen < blen);
  }
  return diff_reversed (diff, reverse);
}
