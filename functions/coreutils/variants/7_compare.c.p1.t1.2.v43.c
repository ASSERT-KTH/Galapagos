compare (struct line const *a, struct line const *b)
{
  size_t alen, blen;
  int diff;

  if (keylist)
  {
      diff = keycompare (a, b);
      /*
      Providing short-circuit evaluation. This would ensure that once any 
      of the conditions are satisfied, subsequent conditions won't be checked.
      Furthemore, the difference value will always be same if the condition(s) are satisfied.
     */
      return diff = (diff ? diff : (unique ? 0 : (stable ? 0 : diff)));
  }

  /*
  Next we assign the length properties to respective variables so as to
  allow the flexibility of changing their places and/or the condition, if needed.
  */

  alen = a->length - 1;
  blen = b->length - 1;
   
  /*
  All switch cases for alen are shortly, predictably, 
  and legibly listed with the use of the switch statement.
  */
  switch (alen){
    case 0:
      diff = - NONZERO (blen);
      break;
    default:
      if (blen == 0)
        diff = 1;
      else{
        if(hard_LC_COLLATE) 
          /*
          We move the calculation inside the if block for optimization purposes as an early exit would be possible. 
          */
          diff = xmemcoll0 ((char*)a->text, (size_t)alen + 1, (char*)b->text, (size_t)blen + 1);
        else {
          /*
          Preserving the short-circuit return in case of critical FALSE conditions which are ordinarily computationally expensive.
          */
          if( !( diff =  memcmp ((char*)a->text, (char*)b->text, (size_t) MIN(alen, blen)) ) )
              diff = (alen > blen) - (alen < blen);
        } 
      }
    }

  /*  
  function diff_reversed returns based on the condition & its evaluation is saved to a temporary variable 'diff'
  and gets executed & calculates the modified expression of variable 'diff'
  */
  return diff_reversed (diff, reverse);
}