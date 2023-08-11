fe25519_sq(fe25519 h, const fe25519 f)
{
    int32_t local_f[10];
    for(int i = 0; i < 10; i++){
        local_f[i] = f[i];  
    }
    int64_t f0f0 = (int64_t)f[0]*f[0];
    int64_t f1f9_76 = (int64_t)2*f[1]*38*f[9];
    int64_t f2f8_38= (int64_t)2*f[2]*19*f[8];
    int64_t f3f7_76 = (int64_t)2*f[3]*38*f[7];
    int64_t f4f6_38  = (int64_t)2*f[4]*19*f[6];
    int64_t f5f5_38 = (int64_t)f[5]*38*f[5];

    int64_t h0 = f0f0 + f1f9_76 + f2f8_38 + f3f7_76 + f4f6_38 + f5f5_38;
    h0 = (h0 + (int64_t)(1 << 25)) >> 26;
    local_f[1]+= h0;
    h[0] = local_f[1];

    int64_t f0f1_2  = (int64_t)2*f[0]*f[1];
    int64_t f2f9_38 = (int64_t)2*f[2]*38*f[9];
    int64_t f3f8_38 = (int64_t)2*f[3]*19*f[8];
    int64_t f4f7_38 = (int64_t)2*f[4]*38*f[7];
    int64_t f5f6_38 = (int64_t)2*f[5]*19*f[6];
	
    int64_t h1 = f0f1_2 + f2f9_38 + f3f8_38 + f4f7_38 + f5f6_38;
    h1 = (h1 + (int64_t)(1 << 24)) >> 25;
    local_f[2]+= h1;
    h[1] = local_f[2];

    
    //skipping to h5 for length reasons 
    int64_t f0f5_2 = (int64_t)2*f[0]*f[5];
    int64_t f1f4_2 = (int64_t)2*f[1]*f[4];
    int64_t f2f3_2 = (int64_t)2*f[2]*f[3];
    int64_t f6f9_38 = (int64_t)2*f[6]*38*f[9];
    int64_t f7f8_38 = (int64_t)2*f[7]*19*f[8];

    int64_t h5 = f0f5_2 + f1f4_2 + f2f3_2 + f6f9_38 + f7f8_38;
    h5 = (h5 + (int64_t)(1 << 24)) >> 25;
    local_f[6]+= h5;
    h[5] = local_f[6];

    int64_t f0f6_2  = (int64_t)2*f[0]*f[6];
    int64_t f1f5_4 = (int64_t)2*f[1]*2*f[5];
    int64_t f2f4_2 = (int64_t)2*f[2]*f[4];
    int64_t f3f3_2  = (int64_t)2*f[3]*f[3];
    int64_t f7f9_76 = (int64_t)2*f[7]*38*f[9];
    int64_t f8f8_19 = 2*(int64_t)f[8]*19*f[8];
    
    int64_t h6 = f0f6_2 + f1f5_4 + f2f4_2 + f3f3_2 + f7f9_76 + f8f8_19;
    h6 = (h6 + (int64_t)(1 << 25)) >> 26;
    local_f[7]+= h6;
    h[6] = local_f[7];
}