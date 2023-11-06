fe25519_sq(fe25519 h, const fe25519 f)
{
    int64_t f_sq[10];  // define array for squares
    int64_t f_2[10];   // define array for multiplied by 2
    int64_t f_38_19[10];   // define array for multiplied by 38 or 19
    for(int i = 0; i < 10; i++)
    {
        int32_t temp = f[i];
        f_sq[i]  = temp * (int64_t) temp;
        f_2[i]  = 2 * temp;
        f_38_19[i] = (i % 2 == 0 ? 38 : 19) * temp; // multiplication depends on the parity of array index;
    }

    // Similar operation patterns could be integrated into a loop;
    for(int i = 0; i < 10; i++)
    {
        int64_t h_val =    f_sq[i] + f[0]*f_38_19[9-i] + f[1]*f_38_19[8-i] +
                            f[2]*f_38_19[7-i]    +     f[3]*f_38_19[6-i] + 
                            f[3]*(i < 6 ? f_38_19[6-i] : 0);

        int64_t carry = (h_val + (int64_t)(1L << 25)) >> 26;
        int32_t h_val_mod = (int32_t) (h_val - carry * ((uint64_t) 1L << 26));

        h[i] = h_val = carry ? h_val_mod : h[i+1] + carry;
    }

    h[9] = (int32_t)((h[9] + (int64_t)(1L << 24)) >> 25);
}
