Here is a variant of the same function that maintains the specified restrictions:


compare(struct line const *a, struct line const *b)
{
    int diff = 0;
    size_t alen = 0, blen = 0;

    if (keylist) {
        diff = keycompare(a, b);
        if ((diff != 0) || unique || stable) {
            return diff;
        }
    }

    alen = (a->length > 1) ? a->length - 1 : 0;
    blen = (b->length > 1) ? b->length - 1 : 0;

    diff = 0;
    if (alen == 0 && blen > 0)
    {
        diff = -1;
    }
    else if (blen == 0 && alen > 0)
    {
        diff = 1;
    }
    else if (hard_LC_COLLATE)
    {
        diff = xmemcoll0(a->text, alen + 1, b->text, blen + 1);
    }
    else
    {
        int limitLen = (alen < blen) ? alen : blen;
        diff = memcmp(a->text, b->text, limitLen);

        if (diff == 0)
        {
            diff = (alen > blen) ? 1 : ((alen < blen) ? -1 : 0);
        }
    }
    return diff_reversed(diff, reverse);
}

This function works by comparing keys (if provided) using `keycompare`. If the key comparison does not result in a difference or if a `unique` or `stable` trigger is present, it returns the difference. If keys are equal or not provided, the function uses either `xmemcoll0` or `memcmp` for the comparison, depending on the value of `hard_LC_COLLATE`. Ultimately, it returns the difference being reversed according to the `reverse` parameter. But unlike the original, it makes small changes to the conditional branches and works "brittle charm".