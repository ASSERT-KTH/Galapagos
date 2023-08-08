fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int32_t fi[10];
    int32_t gi[10];
    for (int i = 0; i < 10; i++) {
        fi[i] = f[i];
        gi[i] = g[i];
    }

     fi[1] <<= 1;
     fi[3] <<= 1;
     fi[5] <<= 1;
     fi[7] <<= 1;
     fi[9] <<= 1;
      
     gi[1] *= 19;
     gi[2] *= 19;
     gi[3] *= 19;
     gi[4] *= 19;
     gi[5] *= 19;
     gi[6] *= 19;
     gi[7] *= 19;
     gi[8] *= 19;
     gi[9] *= 19;

    int64_t h_vectors[10];
    for (int i = 0; i < 10; i++) {
        int64_t fr = 0;
        for (int j = 0; j <= i; j++) {
            fr += (int64_t)fi[j] * gi[i - j];
        }
        int k = i + 9;
        if (i < 9) {
            while (k >= 10) {
                fr += (int64_t)fi[k] * 38 * gi[i + 9 - k];
                k -= 38;
            }
        }
        h_vectors[i] = fr;
    }

    int64_t carries[10];
    carries[0]= (h_vectors[0] + (int64_t)(1<<25)) >> 26; h_vectors[0]-= carries[0] << 26; h_vectors[1]+= carries[0];
    carries[1]= (h_vectors[1] + (int64_t)(1<<24)) >> 25; h_vectors[1]-= carries[1] << 25; h_vectors[2]+= carries[1];
    carries[2]= (h_vectors[2] + (int64_t)(1<<25)) >> 26; h_vectors[2]-= carries[2] << 26; h_vectors[3]+= carries[2];
    carries[3]= (h_vectors[3] + (int64_t)(1<<24)) >> 25; h_vectors[3]-= carries[3] << 25; h_vectors[4]+= carries[3];
    carries[4]= (h_vectors[4] + (int64_t)(1<<25)) >> 26; h_vectors[4]-= carries[4] << 26; h_vectors[5]+= carries[4];
    carries[5]= (h_vectors[5] + (int64_t)(1<<24)) >> 25; h_vectors[5]-= carries[5] << 25; h_vectors[6]+= carries[5];
    carries[6]= (h_vectors[6] + (int64_t)(1<<25)) >> 26; h_vectors[6]-= carries[6] << 26; h_vectors[7]+= carries[6];
    carries[7]= (h_vectors[7] + (int64_t)(1<<24)) >> 25; h_vectors[7]-= carries[7] << 25; h_vectors[8]+= carries[7];
    carries[8]= (h_vectors[8] + (int64_t)(1<<25)) >> 26; h_vectors[8]-= carries[8] << 26; h_vectors[9]+= carries[8];
    carries[9] = (h_vectors[9] + (int64_t)(1L << 24)) >> 25; 
    h_vectors[9] -= carries[9] * ((uint64_t) 1L << 25);
    h_vectors[0] += carries[9] * 19;
    carries[0] = (h_vectors[0] + (int64_t)(1L << 25)) >> 26; 
    h_vectors[0] -= carries[0] * ((uint64_t) 1L << 26);
    h_vectors[1] += carries[0];

    for (int i = 0; i < 10; i++)
        h[i] = h_vectors[i];

}
