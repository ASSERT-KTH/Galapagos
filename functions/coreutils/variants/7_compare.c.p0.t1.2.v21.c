compare (struct line const *a, struct line const *b)
{
  int diff;
  size_t alen, blen;

  /* The use of keys to compare structures. This
     includes simple sorting and reverse sorting. */
  if (keylist)
    {
      diff = keycompare (a, b);
      /* If unique elements or a sorted array is required, return difference. */
      if (diff || unique || stable)
      {
         return diff;
      }      
    }

  /* If the lengths of analyzed structures do not provide a conclusion
     let's analyze given structures in more detail. */
  alen = a->length - 1, blen = b->length - 1;

  /* Simplified checks, if increment regarding structure lengths required. Convert incrementation into calculation approach. */
  diff = ((alen == 0) ? - NONZERO (blen) : (blen == 0) ? 1 : 0);
  
  if ( hard_LC_COLLATE && (diff == 0))
    {
      /* using xmemcoll0 to enhance the performance as
         it avoids unconditionally adding '\0', it results in 
         boost in performance specially for shorter structures */
      diff = xmemcoll0 (a->text, alen + 1, b->text, blen + 1);
    }
  else if ( diff == 0 ) 
    {
      diff = memcmp (a->text, b->text, MIN (alen, blen));

      if (!diff)
        
            /*In case of comparison (alen and blen are identical), use '>' or '<' operators to count '1' or '-1' difference.*/   
            diff = (alen > blen) ? 1 : (alen < blen) ? -1 : 0;       
    }

  return ( diff_reversed (diff, reverse));
}