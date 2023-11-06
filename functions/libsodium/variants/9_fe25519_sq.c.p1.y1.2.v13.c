Variant 1:

void fe25519_sq(fe25519 h, const fe25519 f)
{
    int32_t fValues[10];
    for(int i = 0; i < 10; i++){
        fValues[i] = f[i];
    }
    
    int32_t fTwos[8], fMult[5];
    for(int i = 0; i < 8; i++){
        fTwos[i] = 2 * fValues[i];
    }
    for(int i = 0; i < 5; i++){
        fMult[i] = (i%2 == 0)? 19 * fValues[i+5] : 38 * fValues[i+5];
    }
    
    int64_t fSq[45];
    for(int i = 0; i < 10; i++){
        for(int j = i; j < 10; j++){
            fSq[i * 10 + j - i * (i + 1) / 2] = (i != j)? fValues[i] * (int64_t) fValues[j] : fValues[i] * (int64_t) fTwos[j-1];
        }
    }
    
    int64_t hValues[10];
    for(int i = 0; i < 10; i++){
        hValues[i] = 0;
        for(int j = 0; j < 10 - i; j++){
            hValues[i] += (j < i)? fSq[i * 10 + j - i * (i + 1) / 2] * 2 * ((j % 2 == 0)? 38 : 19)
                        : fSq[i * 10 + j - i * (i + 1) / 2];
        }
        for(int j = 10 - i; j < 5; j++){
            hValues[i] += fSq[i * 10 + j - i * (i + 1) / 2] * fMult[j];
        }
    }
    
    int64_t carry;
    for(int i = 0; i < 10; i++){
        if(i == 9){
            carry = (hValues[9] + (int64_t)(1<<24)) >> 25;
            hValues[0] += carry * 19;
            hValues[9] -= carry * ((uint64_t) 1<<25);
            i = -1; // existing loop will +1 to become 0, so do another loop for carry from h9 to h0
        }
        carry = (hValues[i] + (int64_t)(1<<24)) >> 25;
        hValues[i+1] += carry;
        hValues[i] -= carry * ((uint64_t) 1<<26);
    }
    
    for(int i = 0; i < 10; i++){
        h[i] = (int32_t)hValues[i];
    }
}


Variant 2:

void fe25519_sq(fe25519 h, const fe25519 f)
{
    int32_t fValues[10];
    int64_t temp_fi, tmp_m;
    for(int i = 0; i < 10; i++) {fValues[i] = f[i];}
    
    for(int i = 0; i < 10; i++)
    {
        tmp_m = i < 5 ? 38 : 19; 
        for(int j = i; j < 10; j++)
        {
            if (i == j) { temp_fi = fValues[i] * (int64_t) fValues[i]; }
            else if (j < 5 || (i < 5 && j == 5)) { temp_fi = 2 * fValues[i] * (int64_t) fValues[j]; }
            else { temp_fi = fValues[i] * tmp_m * (int64_t) fValues[j]; }
            h[i+j] += temp_fi; 
        }
    }

    int64_t carry;
    for(int i = 0; i <= 9; i++)
    {
        carry = (h[i] + (1<<24) - (i == 9 ? (1<<24) : 0)) >> 25;
        h[i] -= carry << 25;
        h[i+1] += carry * (i < 9 ? 1 : 19);
    }
    
    for(int i = 0; i <= 9; i++) h[i] = (int32_t)h[i];
}
