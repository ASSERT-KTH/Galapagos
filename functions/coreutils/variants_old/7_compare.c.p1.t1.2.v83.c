Here's a variant program that reorders some checks/implementations for a presumably better pipeline, by processing similar types of comparisons sequentially:


compare (struct line const *a, struct line const *b)
{
  int diff;
  size_t alen, blen;

  /* If keys are specified, quantitatively compare them first. */
  if (keylist)
    {
      diff = keycompare(a, b);
      if (diff != 0 || unique || stable)
        return diff;
    }

  /* Default case if the keys are equivalent or no keys were specified. */
  alen = a->length - 1;
  blen = b->length - 1;
  
  /* Consider if one of the lengths is equal to 0 */
  if (alen == 0)
    return - NONZERO (blen);
  else if (blen == 0)
    return 1;

  /*
   * Still continuing means that 
   * comparison by keys gave same rank,
   * and both inputs aren't of 0 length.
   */

  /* "Traditional" byte expression value comparison method */
  if (!hard_LC_COLLATE)
  {
    diff = memcmp (a->text, b->text, MIN (alen, blen));

    /* If resultant diff indicated they match up until MIN(alen, blen), 
     * decide which is "lesser" by length sizing.
     */
    if (!diff) 
      diff = (alen > blen) - (alen < blen);
  }
  /* LC_COLLATE-defined sequence of character stand-in values comparison method. */
  else
    diff = xmemcoll0 (a->text, alen + 1, b->text, blen + 1_);
    

  /* Account for eventual indicataion if descending/ascending ordered sorting. */
  return diff_reversed(diff, reverse);
}
 

Of course due to non-idempotency in real-world executions '(a == b && b == c) not inherently meaning a == c' can mean justified pauses at differing sequences. In bounded-purpose tasks such as this however, projection choices work functionally equaivalent as time concept is not integral to task's projection-wise behavior.