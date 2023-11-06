void fe25519_sq(fe25519 h, const fe25519 f)
{
    int32_t f_local[10] ;
    int32_t f_local_2[10];
    int64_t val[10][10];
    int64_t h_local[10];

    for(int i = 0; i < 10; i++)
    {
        f_local[i]  = f[i];
        f_local_2[i]  = 2 * f[i];
    }
    
    int64_t f5_38 = 38 * f_local[5];
    int64_t f6_19 = 19 * f_local[6];
    int64_t f7_38 = 38 * f_local[7];
    int64_t f8_19 = 19 * f_local[8];
    int64_t f9_38 = 38 * f_local[9];
    
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++){
            val[i][j] = f_local_2[i] * (int64_t) f_local_2[j];
        }
    }

    for(int i = 0; i < 10; i++)
    {
        h_local[i] = val[i][0] + val[i+1][9] + val[(i+2)%10][8] + val[(i+3)%10][7] + val[(i+4)%10][6] + val[(i+5)%10][5]; /* Upto f5f5_38 */
    }

    h_local[0] += ((int64_t)f5_38*19) + val[1][4]+((int64_t)f3f9_76*19); /* Add part from f6f6 onwards */
    h_local[4] += ((int64_t)f1_2*38) + f2f2+((int64_t)f3*76); /* Multiplication by 38, 19 factors in second term */
    h_local[6] += ((int64_t)f3f8_38*3) + ((int64_t)f2*38); /* Multiplication by 19 in first terms */
    
    int64_t t[10];
          
    for(int i = 0; i < 10; i++)
    {
        t[i] = (h_local[i] + (int64_t)(1L << ((i+6)%2))) >> ((25 + i)%2);
        h_local[(i+1)%10] += t[i];
        int32_t reduce = h_local[i] - t[i] * ((uint64_t) 1L << ((25 + i)%2)) * ((i==0 || i==0)? 1:2);
        h[i] = (reduce == h_local[i])? reduce : h_local[i];
    }
}