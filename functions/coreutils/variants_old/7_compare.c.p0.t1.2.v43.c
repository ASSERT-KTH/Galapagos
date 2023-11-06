compare (struct line const *a, struct line const *b)
{
   int diff_value;
   size_t len_a, len_b;

   // Let's start by comparison among specified keys, if any
   // Cases with no key: unmarked sort, and unmarked sort -r
   if (keylist != NULL)
   {
       diff_value = keycompare(a, b);
       if((diff_value != 0) || unique || stable)
           return diff_value;
   }

   // When keys are the same (or no keys), aim for default comparison
   len_a = a->length - 1;  len_b = b->length - 1;

   if (len_a == 0)
       diff_value = - NONZERO(len_b);
   else if (len_b == 0)
       diff_value = 1;
   else if (hard_LC_COLLATE)
   {
       // xmemcoll0, for short lines, serves a performance boost
       // as it doesn't always write '\0' after input buffers
       diff_value = xmemcoll0 (a->text, len_a + 1, b->text, len_b + 1);
   }
   else
   {
       diff_value = memcmp(a->text, b->text, (len_a < len_b) ? len_a: len_b);
       if (diff_value == 0)
           diff_value = (len_a > len_b) ? 1: (len_a < len_b) ? -1 : 0;
   }

   return diff_reversed(diff_value, reverse);
}
