fe25519_sq(fe25519 h, const fe25519 f)
{
    int32_t f0 = f[0];
    int32_t f1 = f[1];
    int32_t f2 = f[2];
    int32_t f3 = f[3];
    int32_t f4 = f[4];
    int32_t f5 = f[5];
    int32_t f6 = f[6];
    int32_t f7 = f[7];
    int32_t f8 = f[8];
    int32_t f9 = f[9];

    int32_t f0_2 = 2 * f0;
    int32_t f1_2 = 2 * f1;
    int32_t f2_2 = 2 * f2;
    int32_t f3_2 = 2 * f3;
    int32_t f4_2 = 2 * f4;
    int32_t f5_38 = 38 * f5; 
    int32_t f6_19 = 19 * f6;
    int32_t f7_38 = 38 * f7; 
    int32_t f8_19 = 19 * f8;
    int32_t f9_38 = 38 * f9; 

    // Reformat square computation for lesser lines, still regular code reduce.
    int64_t f0_4s = f0_2 * (int64_t) f0_2;
    int64_t f1_4s = f1_2 * (int64_t) f1_2;
    int64_t f3_4s = f3_2 * (int64_t) f3_2;
    int64_t f4_4s = f4_2 * (int64_t) f4_2;
    int64_t f5_f5_stand = f5 * (int64_t) f5_38;
    int64_t f6_6_stand = f6 * (int64_t) f6_19;
    int64_t f7_7_stand = f7 * (int64_t) f7_38;
    int64_t f8_8_stand = f8 * (int64_t) f8_19;
    int64_t f9_9_stand = f9 * (int64_t) f9_38;

    // Multiply by 2, for reduction of lines.
    int64_t f1_2f9 = f1_2 * (int64_t) f9_38;
    int64_t f1_2f0 = f1_2 * (int64_t) f0;
    int64_t f3_2f7 = f3_2 * (int64_t) f7_38;
    int64_t f3_2f0 = f3_2 * (int64_t) f0;
    int64_t f5_2f8 = f5*2 * (int64_t) f8_19;
    int64_t f5_2f0 = f5*2 * (int64_t) f0;
    int64_t f7_7_complete = f7_2 * (int64_t) f8_19;
    int64_t f7_2f0 = f7_2 * (int64_t) f0;

    // Reduce calculation by h_ and removing former computation.
    int64_t h0 = f0_4s + f1_2f9 + f2_2 * (int64_t) f8_19 + f3_2f7 + f4_2 * (int64_t) f6_19  + f5_f5_stand;
    int64_t h1 = f0f1_2 + f2_2 * (int64_t) f9_38+ f3_2 * (int64_t) f8_19  + f4 * (int64_t) f7_38  + f5*2 * (int64_t) f6_19;
    int64_t h2 = f0f2_2+f1_4s+f3_2f9+2*f1_2* (int64_t) f8_19+2*f1_2* (int64_t) f7_38 + f6_6_stand;
    int64_t h3 = f0f3_2+f1f2_2+2*f1_2*(int64_t) f9_38 + f5_2f8 + 2*f2_2*(int64_t) f7_38;
    int64_t h4 = f0f4_2 + f1_2f3+f2_2 * (int64_t) f2+f5_2f9+2 * f3_2 * (int64_t) f6+c7_7_complete;
    int64_t h5 = f1_2f4+2 * f2 * (int64_t) f3+f6_2 * (int64_t) f9 + f7_7_complete;
    int64_t h6 = 2*f2f4_2+f3_4s+f7_2f9 + 2*f8*19*(int64_t) f6;
    int64_t h7 = 2*f2f5+f3_2f4+2*f1f7_4+f8*19*(int64_t)f7;
    int64_t h8 = 2*f2f6+f3f5_4+f4_4s+2*f9_38*(int64_t)f9;
    int64_t h9 = 2*f2f7 + 2*f3f6+f1f8_2+2*f4_2 * (int64_t) f5;

   //Conversion into code for easier functioning.
    _fe25519_sq_reduce_and_pack(h,h0,h1,h2,h3,h4,h5,h6,h7,h8,h9);
}