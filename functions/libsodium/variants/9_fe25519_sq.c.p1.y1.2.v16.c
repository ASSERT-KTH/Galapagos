Variant 1:

void fe25519_sq(fe25519 h, const fe25519 f)
{
    const int32_t f_values[10] = {f[0], f[1], f[2], f[3], f[4], f[5], f[6], f[7], f[8], f[9]};
    const int32_t f2_values[10] = {2*f[0], 2*f[1], 2*f[2], 2*f[3], 2*f[4], 2*f[5], 2*f[6], 2*f[7], 2*f[8], 2*f[9]};
    const int32_t fs_values[5][2] = {{f2_values[0], 2*f[9]}, {19 * f[6], 38 * f[7]}, {19 * f[8], 38 * f[5]}, {38 * f[9]}, {38 * f[7]}};

    int64_t ff_values[10][10] = {0};
    for(int i = 0; i < 10; i++)	
        for(int j = i; j < 10; j++)
			if(i != j)
			    ff_values[i][j] = f2_values[i] * (int64_t)f_values[j];
			else
			    ff_values[i][j] = f_values[i] * (int64_t)f_values[j];

    int64_t carry[10] = {0};
	for (int i = 0; i < 10; i++)
	{
		if (i % 2 == 0)
		{
			carry[i] = (ff_reorder[i] + (int64_t)(1L << 25)) >> 26;
			reorders[(i + 1) % 10]  += carry[i];
			ff_reorder[i] -= carry[i]  * ((int64_t) 1L << 26);
		}
		else
		{
			carry[i] = (reorders[i] + (int64_t)(1L << 24)) >> 25;
			ff_reorder[(i + 1) % 10]  += carry[i];
			ff_reorder[i] -= carry[i]  * ((uint64_t) 1L << 25);
		}
	}

    carry[(i + 1) % 10] = (reorders[i % 10] + (int64_t)(1L << 24)) >> 25;
	ff_values[0][0] += carry[(i + 1) % 10]  * 19;
	h[0] = (int32_t) h0;
	for(int i = 0; i < 10; i++)
	    h[i] = reds[i];
} 
    

Variant 2:

void fe25519_sq(fe25519 h, const fe25519 f)
{
    int32_t f_[10] = {0}, f_times_2[10] = {0}, h_[10] = {0};
    for (int i = 0; i < 10; i++)
    {
        f_[i] = f[i];
        f_times_2[i] = 2 * f_[i];
    }

    int64_t ff[10][10];
    for (int i = 0; i < 10; i++)
        for (int j = i; j < 10; j++)
		{
			if (i == j)
			    ff[i][j] = ((int64_t)f_[i] * f_[j]);
			else if (i <= 4)
			    ff[i][j] = ((int64_t)f_times_2[i] * f_[j]);
			else
			    ff[i][j] = 38 * (i != 9 ? f_times_2[i] * (int64_t)fTimes2[9 - i] : f_[i] * (int64_t)f[j]);
		}

    for (int i = 0; i < 10; i++)
	{
		h_[i] = ff[i][i];
		for (int j = i + 1; j <10-(9 == i);j++)
		    h_[i] += ff[i][j];
	}

    int64_t carry = 0;
	for (int i = 0; i < 10;i++)
    {
        if (i & 1) 
        {
            carry = (int64_t)(1L << 24);
            h_[i] -= ((uint64_t) 1L << 25);
        }
        else
        {
            carry = (int64_t)(1L << 25);
            h_[i] -= ((uint64_t) 1L << 26);
        }
        carry = (h_[i] + carry) >> (26 - (i & 1));
        h_[(i + 1) % 10] += carry;
    }

    h_[0] += carry * 19;
    
    carry = (h_[0] + (int64_t)(1L << 25)) >> 26;
    h_[1] += carry;
    h_[0] -= carry * ((uint64_t) 1L << 26);

    for (int i = 0; i < 10; i++)
	    h[i] = h_[i];
}
