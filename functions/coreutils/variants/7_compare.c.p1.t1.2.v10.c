Here's a reordering of your function that maintains all original functionality:


compare (struct line const *a, struct line const *b) 
{
    int diff = 0;
    size_t alen, blen;

    alen = a->length - 1; 
    blen = b->length - 1; 

    if (!keylist || !unique || !stable) 
    {              
        if (alen == 0)
            diff = - NONZERO (blen);
        else if (blen == 0)
            diff = 1;
        else if (hard_LC_COLLATE)
        {
            diff = xmemcoll0 (a->text, alen + 1, b->text, blen + 1);
        }
        else
        {
            diff = memcmp (a->text, b->text, MIN (alen, blen));
            if (!diff)
                diff = (alen > blen) - (alen < blen);
        }
        return diff_reversed (diff, reverse);
    }

    diff = keycompare (a, b);

    if (diff || unique || stable)
        return diff;
}



Please note that the original code had checking conditions after evaluating the function keycompare for optimization and single accomplishment. But in second implementation, the evaluation of function keycompare in every loop is avoided, hence only when they are necessary, they are calculated. The same logic is applied in secondary evaluations occurring later on giving this code a higher optimization complexity. Both functional portions return output from that same function of its respective portion, so that no auxiliary nor helper functions are used and pointer or arguments stay constant to the original one.