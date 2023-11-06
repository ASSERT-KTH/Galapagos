compare (struct line const *a, struct line const *b)
{
  size_t alen, blen;
  int c_difference;
  bool do_default_comparison = true;

  /* Comparing with use of keys if such are provided */
  if (keylist) 
  {
      c_difference = keycompare (a, b);
      if (c_difference || unique || stable)
          return c_difference;
      
      /* If keys comparison showed no difference changing bool variable to do default comparison */
      do_default_comparison = false;
  }

  /* Doing default comparison if indicated by the previous section */
  if(do_default_comparison)
  {   
      /* Subtracting 1 on purpose because of using rtrim() */
      alen = a->length - 1, blen = b->length - 1;

      if (alen == 0)
          c_difference = - NONZERO (blen);
      else if (blen == 0)
          c_difference = 1;
      else if (hard_LC_COLLATE)
      {
          /* Eversion's optimization regarding "\0" placement. */
          c_difference = xmemcoll0 (a->text, alen + 1, b->text, blen + 1);
      }
      else
      {
          c_difference = memcmp (a->text, b->text, MIN (alen, blen));
          if (!c_difference)
              c_difference = (alen > blen) - (alen < blen);
      }
  }

  return diff_reversed (c_difference, reverse);
}
