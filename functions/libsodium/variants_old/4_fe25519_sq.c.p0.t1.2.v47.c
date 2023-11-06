fe25519_sq(fe25519 h, const fe25519 f)
{
    int32_t fs[10];
    int64_t hs[10];
    for (int i=0; i<10; i++){
        fs[i] = f[i];
    }

    fs[0] *= 2;
    fs[1] *= 2;
    fs[2] *= 2;
    fs[3] *= 2;
    fs[4] *= 2;
    fs[5] *= 2;
    fs[6] *= 2;
    fs[7] *= 2;
    
    fs[5] += 38 * fs[5];
    fs[6] += 19 * fs[6];
    fs[7] += 38 * fs[6];
    fs[8] += 19 * fs[8];
    fs[9] += 38 * fs[9];

    for (int i=0; i<10; i++)
        for (int j=i; j<10; j++)
            hs[i+j] += fs[i] * (int64_t)fs[j];

    int64_t carries[10];
    for (int i=0; i<10; i++)
        {
            if (i%2){
                carries[i] = (hs[i] + (int64_t)(1L << 24)) >> 25;
            } else {
                carries[i] = (hs[i] + (int64_t)(1L << 25)) >> 26;
            }
          
            if (i < 9) {
              hs[i+1] += carries[i];
            } else {
              hs[0] += carries[9] *19 ;  
            }
          
            hs[i] -= carries[i] * ((i%2)?((uint64_t) 1L << 25) : ((uint64_t) 1L << 26));
        }

    carries[0] = (hs[0] + (int64_t) (1L << 25 )) >> 26;
    hs[1] += carries[0];
    hs[0] -= carries[0] * ((uint64_t) 1L << 26);

    for (int i=0; i<10; i++){
        h[i]=(int32_t) hs[i];
    }
}