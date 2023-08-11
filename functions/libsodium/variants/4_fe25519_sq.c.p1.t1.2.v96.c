The goal here is the same: to perform the same calculations and create the same results, using a slightly different approach to programming – in this case. One way to modify the code while maintaining functionality would be to loop through arrays rather than manually assigning and calculating variables for each array index:


void fe25519_sq(fe25519 h, const fe25519 f)
{
    int64_t prods[45] = {0}, carries[10] = {0};
    int32_t f_[10] = {0}, f_2[10], f_38[5];
    int muls[45][2] = {{0, 0}, {0, 9}, {0, 8}, {0, 7}, {0, 6}, {0, 5},
                       {1, 9}, {1, 8}, {1, 7}, {1, 6}, {1, 1}, {2, 9}, 
                       {2, 8}, {2, 7}, {2, 2}, {3, 9}, {3, 8}, {2, 7}, 
                       {3, 3}, {4, 9}, {4, 8}, {4, 7}, {2, 2}, {4, 5}, 
                       {0, 0}, {0, 4}, {1, 1}, {1, 3}, {2, 2}};

    for(int i = 0; i < 10; i++)
        f_[i] = f[i];

    for(int i = 0; i < 10; i++)
        f_2[i] = f_[i] * 2;

    for(int i = 0; i < 5; i++)
        f_38[i] = f_[i + 5] * 38;

    for(int i = 0; i < 29; i++)
    {
        int64_t a1, a2, prod;

        if(muls[i][1] < 5)
            a1 = (i < 15 || muls[i][1] % 2 == 0)?f_[muls[i][1]]:f_2[muls[i][1]];
        else
            a1 = (i < 25||(muls[i][1] - 5) % 2 == 0)?f_[muls[i][1]]:f_38[muls[i][1] - 5];
        
        a2 = (i < 20 || muls[i][0] % 2 == 0)?f_[muls[i][0]]:f_2[muls[i][0]];

        prods[i] = a1 * (int64_t) a2;
    }

    for(int i = 0; i < 10; i++)
    {   /* 417 computation  */
        h[i] = prods[i] + prods[i + 8] + prods[i + 3] + prods[i + 5] * 19
             + (i % 2 == 0 ? prods[i + 28] * 38: 0);

        carries[i] = (h[i] + (int64_t)(1L << (25 - (i % 2)))) >> (26 - (i % 2));
        int y = (i + 1) % 10;
        h[y] += carries[i];

        int y_adj = (y < 5 || i < 4)?y:y - 5;
        h[i] -= carries[i] * ((uint64_t) 1L << (26 - (y_adj % 2 + (y / 5 != (i + 1) / 5))));
    }

    h[0] += 19 * ((h[9] + (int64_t)(1L << 24)) >> 25);
    h[9] -= ((h[9] + (int64_t)(1L << 24)) >> 25) * ((uint64_t) 1L << 25);
    h[1] += (h[0] + (int64_t)(1L << 25)) >> 26;
    h[0] -= ((h[0] + (int64_t)(1L << 25)) >> 26) * ((uint64_t) 1L << 26);

    for(int i = 0; i < 10; i++)
        h[i] = (int32_t) h[i];
}
