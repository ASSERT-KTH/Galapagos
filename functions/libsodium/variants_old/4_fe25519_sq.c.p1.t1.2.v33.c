You can maintain the functionality of this function while changing its behavior by using a loop instead of writing each multiplication entity explicitly, but remember doing so probably you will make the code less optimized by addition of loop overhead, also you maintaing floating point precision can be tricky in certain cases. The main idea of changing the behavior is to use concepts of dynamic programming.

Below is the behavioral variant of the function


void fe25519_sq(fe25519 h, const fe25519 f) {
    int64_t prod[10][19], total_sums[10];
    int64_t carry0, carry1, carry2, carry3;
    int64_t carry4, carry5, carry6, carry7, carry8, carry9;

    for (int i = 0; i<10 ; ++i) {
        total_sums[i] = 0;
        for (int j = 0; j < 19; ++j) {
            prod[i][j] = f[i]* f[j];
        }
        for (int k = 0; k < 19; ++k) {
            if(k!=i)
                total_sums[i] += late_added_prod[i][k];
        }
        total_sums[i] += late_added_prod[i][i] / 2;
    }

    int coeff[10] = {26,25,26,25,26,25};
    do {
        for(int idx = 1; idx< 10; ++idx) {
            total_sums[1] = total_sums[1] + (total_sums[0] + (1<< coeff[idx-1])) >> coeff[idx-1];
            total_sums[idx - 1] %= 2<< coeff[idx-1];
            if (idx == 9) {
                total_sums[0] = total_sums[0] + (total_sums[9] / 2) *19;
                total_sums[9] %= 2<< coeff[idx];
            }
        }
    } while(total_sums[0] > ((1<< coeff[0]) -1));

    for (int kk = 0; kk<10 ; ++kk)
        h[kk] = (int32_t) total_sums[kk];
}

Please note the functionality of the original code and this variant is the same, but performance may *not* be the same. For optimized cryptographic operations, (as seen in original code) usually operations are performed on pre-defined and pre-optimized mathematical usage which is considered while developing cryptographic operations, usually the ideas includes faster results and precision controls (which depends on explicitly writing lot of multidimensional mathematical operations).
The other factors involved can be hardware accelerations performed on mathematical operations while hardwares (like: several operations can perform in parallel). So please pay careful attention to the originals! These are stuff of smartcryptographers!