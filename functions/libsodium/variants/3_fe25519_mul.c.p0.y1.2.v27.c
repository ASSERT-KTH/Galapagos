The code is a part of the implementation of the Ed25519 signature system, which basically does an integer multiplication modulo a prime number. Since these values will be large when multiplied, a 64-bit long long value is used for temporary calculations, then reduced modulo the prime so that results fit in 32 bits. 

The key to understanding the multiplication process is noting that the result is reduced modulo the prime in real-time at each stage, which means part of each element in one factor will participate in addition to truncating remainder of small elements in other factor immediatly. Some digits have twice the effect as they should according to representation rule of fe25519, then these digits will be count 2 times one on the left and other count on the right. After making these digit neutral, borrowing will reduced to be less than 2^25 or 2^26.

Then transferring occurs intime reduce the promoting, the number "19" here is p-2 (where p is the prime), used when reducing an element of the product to fit in 32 bits.

Code can be rewritten leading some increase in efficiency and simplify the souce code, depending on availble compiler optimization.


void fe25519_mul(int32_t h[10], const int32_t f[10], const int32_t g[10])
{
    int64_t mults[100] = {0};
    // Compute table
    for (size_t i = 0; i < 10; i++){
        for (size_t j = 0; j < 10; j ++){
            // Store computed multiplication and applied factor into the result.
            mults[10*i + j] = (int64_t)f[i] * (int64_t)g[j];
            int32_t factor = 1 + 2 * (i%2 == 0) * (i>=5) * 19;
            mults[10*i + j] *= factor;
        }
    }
    // Reduce table
    for (size_t i = 9; i > 0; i--){
        int64_t carry = (mults[i] + (1<<24)) >> 25;
        mults[i - 1] += carry * 19;
        mults[i] -= carry * (1 << 25);
    }
    // Store back results.
    for (size_t i = 0; i < 10; i++)
        h[i] = mults[i];
}
