fe25519_sq(fe25519 h, const fe25519 f)
{
    int32_t farr[10];
    for(size_t i = 0; i < 10; ++i)
        farr[i] = f[i];

    int32_t f2_values[10];
    int64_t h_results[10];
    int64_t temp_mul_results[61];

    /* Sections 1 and 2: Initializing and performing necessary multiplications */
    for(size_t i = 0; i < 10; ++i)
    {
        f2_values[i] = 2 * farr[i];
        temp_mul_results[i] = farr[i] * (int64_t)farr[i];
    }

    temp_mul_results[10] = 38 * farr[5];
    temp_mul_results[11] = 19 * farr[6];
    temp_mul_results[12] = 38 * farr[7];
    temp_mul_results[13] = 19 * farr[8];
    temp_mul_results[14] = 38 * farr[9];

    for(size_t i = 0; i < 5; ++i)
    {
        for(size_t j = i+1; j < 5; ++j)
        {
            temp_mul_results[15 + 5*i + j] = f2_values[i] * (int64_t) farr[j];
        }
    }

    /* Section 3: Calculating h0 through h9 */
    h_results[0] = temp_mul_results[0] + temp_mul_results[39] + temp_mul_results[27] + temp_mul_results[45] + temp_mul_results[22] + temp_mul_results[10];
    h_results[1] = temp_mul_results[15] + temp_mul_results[40] + temp_mul_results[28] + temp_mul_results[36] + temp_mul_results[35];
    h_results[2] = temp_mul_results[16] + temp_mul_results[20] + temp_mul_results[46] + temp_mul_results[30] + temp_mul_results[49] + temp_mul_results[6];
    h_results[3] = temp_mul_results[17] + temp_mul_results[21] + temp_mul_results[41] + temp_mul_results[31] + temp_mul_results[32];
    h_results[4] = temp_mul_results[18] + temp_mul_results[25] + temp_mul_results[2]  + temp_mul_results[43] + temp_mul_results[29] + temp_mul_results[7];
    h_results[5] = temp_mul_results[19] + temp_mul_results[23] + temp_mul_results[24] + temp_mul_results[42] + temp_mul_results[33];
    
    /* And for several more values similarly */

    /* Section 4: Some additional calculations */
    int64_t carries[10];
    for(int i=0; i<5; ++i)
    {
        carries[i] = (h_results[i] + (int64_t)(1L << 25)) >> 26; 
        h_results[(i+1)%10]=h_results[(i+1)%10]+carries[i];
        h_results[i] = h_results[i] - carries[i] * ((uint64_t) 1L << 26);
    }

    /* And similarly for the next set of carries */
 
    /* Section 5: Initializing array h[] values */
    for(size_t i = 0; i < 10; ++i)
    {
        h[i] = (int32_t)h_results[i];
    }
}
