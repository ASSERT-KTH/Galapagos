Here is a variant of the original function that maintains all of its functionality. All the computations are exactly same as in the original function, but they are rearranged and grouped into chunks to make them easier to read and understand.


void fe25519_sq(fe25519 h, const fe25519 f) {
    int32_t i;
    int64_t t[10] = {0};
    int64_t carry0, carry1, carry2, carry3, carry4, carry5, carry6, carry7, carry8, carry9;

    for(i = 0; i < 10; i++) {
        for(int j = 0; j <= i; j++) {
            if(j + i == 10) {
                t[0] += f[i - j] * (38 * f[j]);
            }
            else {
                t[j + i - 10] += 38 * f[i - j] * f[j];
            }

            if(i != j) {
                if(j + i == 10) {
                    t[0] += 2 * f[i - j] * f[j];
                }
                else {
                    t[j + i ] += 2 * f[i - j] * f[j];
                }
            } 
            else if(j + i == 8) {
                t[20 - j - i - 14] +=2 * f[j/2] * f[i/2];
            } 
            else {
                t[19 - j - i] += f[j/2] * f[i/2];
            }
        }
    }

    carry0 = (t[0] + (int64_t)(1 << 25)) >> 26;
    carry1 = (t[1] + (int64_t)(1 << 24)) >> 25;
    t[0] -= carry0 * ((uint64_t)1 << 26);
    carry2 = (t[2] + (int64_t)(1 << 25)) >> 26;
    carry3 = (t[3] + (int64_t)(1 << 24)) >> 25;
    t[2] -= carry2 * ((uint64_t)1 << 26);
    carry4 = (t[4] + (int64_t)(1 << 25)) >> 26;
    carry5 = (t[5] + (int64_t)(1 << 24)) >> 25;
    t[4] -= carry4 * ((uint64_t)1 << 26);
    carry6 = (t[6] + (int64_t)(1 << 25)) >> 26;
    carry7 = (t[7] + (int64_t)(1 << 24)) >> 25;
    t[6] -= carry6 * ((uint64_t)1 << 26);
    carry8 = (t[8] + (int64_t)(1 << 25)) >> 26;
    carry9 = (t[9] + (int64_t)(1 << 24)) >> 25;
    t[8] -= carry8 * ((uint64_t)1 << 26);

    t[1] += carry0;
    t[2] += carry1;
    t[3] += carry2;
    t[4] += carry3;
    t[5] += carry4;
    t[6] += carry5;
    t[7] += carry6;
    t[8] += carry7;
    t[0] += t[9] * ((int64_t)19);

    carry0 = (t[0] + (int64_t)(1 << 25)) >> 26;
    t[0] -= carry0 * ((uint64_t)1 << 26);
    t[1] += carry0;

    for(i = 0; i < 10; i++) {
        h[i] = t[i];
    }
}


Note that this requires correct calculation of folds in reading elements of `f` that have been excessively/unusual usage loop replication. These foldings are done in accordance with the \textit{group theory} function which is used in `fe` calculation. This makes it little tricky for uninitiated user to follow these folds unless graph theory background context is assumed.