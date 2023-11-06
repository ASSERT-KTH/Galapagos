I have made some changes with regards to the arrangement of your original code in regards to comparison but the functionality would still remain the same. It still does key comparison first and non-key next,  it checks alen and blen to decide how to do the memoery comparison(updated to memcmp).

compare(struct line const *a, struct line const *b)
{
  int diff;
  size_t alen, blen;

  /*unadorned sort or unadorned sort -r checks*/
  
  if(keylist) {
    diff = keycompare(a, b);
    if(diff || unique || stable) {
      return diff * (!reverse ? 1 : -1);
    } 
  }
  
  /*Comparison for equal keys or where no keys are specified */

  alen = a->length - 1, blen = b->length - 1;

  if(alen == 0)
    diff = b->length > 0 ? 1 * (!reverse ? 1 : -1) : 0; /*checking for blen > 0 */
  else if(blen == 0)
    diff = -1 * (!reverse ? 1 : -1);
  else {
    if(alen == blen)
      diff = memcmp(a->text, b->text, alen);
    else {
      size_t l_diff = (alen > blen) ? alen - blen : -(alen < blen); //0 limit means !
      if(l_diff)    
        diff = l_diff > 0 ? 1 * (!reverse ? 1 : -1) : 0;   
      else 
        diff = memcmp(a->text, b->text, l_diff);
    }
  }
    
  return diff;
}
