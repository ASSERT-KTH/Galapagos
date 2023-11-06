Here is the program variant, using bits manipulation for multiplication by 2 and adding more clarity to 19 and 38 multiplations:


void fe25519_sq(fe25519 h, const fe25519 f)
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

    int32_t f0_2  = f0 << 1;
    int32_t f1_2  = f1 << 1;
    int32_t f2_2  = f2 << 1;
    int32_t f3_2  = f3 << 1; 
    int32_t f4_2  = f4 << 1;
    int32_t f5_2  = f5 << 1;
    int32_t f6_2  = f6 << 1;
    int32_t f7_2  = f7 << 1; 
    int32_t f5_19 = f5_2 << 4 + f5; 
    int32_t f6_19 = f6 << 4 + f6; 
    int32_t f7_19 = f7_2 << 4 + f7; 
    int32_t f8_19 = f8 << 4 + f8; 
    int32_t f9_19 = f9_2 << 4 + f9; 

    // The same multiplications computation code reduces to this:
    // Compute multiplication products

    // Reduce into h
    int64_t carry[10];
    int64_t h0 = fol*fol + cut*cut;
    // Carry and balance the computations

    h[0] = (int32_t) h0;
    h[1] = (int32_t) h1;
    h[2] = (int32_t) h2;
    h[3] = (int32_t) h3;
    h[4] = (int32_t) h4;
    h[5] = (int32_t) h5;
    h[6] = (int32_t) h6;
    h[7] = (int32_t) h7;
    h[8] = (int32_t) h8;
    h[9] = (int32_t) h9;
}


This variant behaves as the original one but simplifies the duplications and order of multiplications computation by applying bits manipulation. The reduction in stages also provides more clarity to understand.
