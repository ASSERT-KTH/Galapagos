Here's a slight variant of the function,

void fe25519_sq(fe25519 h, const fe25519 f)
{
    int32_t i = 0;
    int32_t j = 0;
    int64_t h_arr[10] = {0};
    int64_t f_arr[20] = {38 * f[5], 19 * f[6], 38 * f[7], 19 * f[8], 38 * f[9]};

    for (; i < 10; ++i) 
    {
        j = 0;
        for (; j <= i; ++j) 
        {
            f_arr[i] = 2 * f[i];
            f_arr[j] = 2 * f[j];
            h_arr[i] += f[i] * (int64_t)f[j];
            
            if(i != j) 
            {
                h_arr[i] += 2 * f[i] * (int64_t)f[j];
            }
        }
        for (; j < 10; ++j) 
        {
            h_arr[i] += 38 * f[i] * (int64_t)f[j] + 38 * f[i] * (int64_t)f[j];
        }

	h_arr[i] += (h_arr[i] + (int64_t)(1L << (25 + (i&1)))) >> (26 - (i&1));

	if(i < 9) 
        {
	    h_arr[i+1] += h_arr[i] >> (26 - (i&1));
	}
	else 
        {
	    h_arr[0] += 19 * (h_arr[i] >> (26 - (i&1)));
	}
    }

    h_arr[1] += h_arr[0] >> 26;
    h_arr[0] = h_arr[0] & 0x3ffffff;

    for(i = 0; i < 10; ++i) 
    {
        h[i] = (int32_t)h_arr[i];
    }
}