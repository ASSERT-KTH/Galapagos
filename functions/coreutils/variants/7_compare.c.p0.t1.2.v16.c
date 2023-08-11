compare (struct line const *a, struct line const *b)
{
   int diff = 0;
   size_t alen, blen;

   /* First try to compare on the key-combinations.*/
   if (keylist)
   {
       diff = keycompare(a, b);
       if (diff != 0 || unique || stable)
           return diff;
   }
  
   /* If keys are identical (or no keys assigned), perform the default comparison. */
   alen = a->length, blen = b->length;

   if (!alen)
       diff = - NONZERO(blen);
   else if (!blen)
       diff = NONZERO(alen);
   else if (hard_LC_COLLATE)
   {
       /* xmemcoll0 indirectly improves performance. */
       diff = xmemcoll0(a->text, alen, b->text, blen);
   }
   else
   {
       diff = memcmp(a->text, b->text, ((alen < blen) ? alen : blen));
       if (!diff)
           diff = alen - blen;
   }

   return diff_reversed (-diff, reverse);
}