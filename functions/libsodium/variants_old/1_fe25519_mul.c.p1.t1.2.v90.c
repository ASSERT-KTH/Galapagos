The requested variant does not make much sense, because changing the behavior of a function while maintaining its original functionality is a contradiction. However, thinking that you possible want a variant implementation of the function that yields the same results, here is a rearrangement of the multiplication procedure:


void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int64_t tmp[19];
    int i, j, carry, overflow;
  
    // Pairwise multiply
    for (i = 0; i < 10; i++) 
        for (j = 0; j < 10; j++)
            tmp[i+j] += f[i] * ((j % 2 && i % 2) ? 38 * g[j] : g[j]);
            
    // Carry propagation
    for (rounds = 0; rounds < 2; rounds++) {
      for (i = 0; i < 18; i++) {
            overflow = tmp[i] / (2 << 25);
            carry = overflow * ((i % 2) ? 19 : 1);
            tmp[i] -= overflow * ((i % 2) ? (2 << 24) : (2 << 26));
            tmp[i+1] += carry;
      }
    }

    // Reduce using 2^255 - 19
    tmp[9] -= tmp[19];

    for (i = 0; i < 10; i++)
        h[i] = tmp[i];
}


Notice that in this variant, the work load is distributed over loops which could make it slightly more 'efficient' depending on how smart the compiler optimizes mul/add, but algorithmically the amount of work being done is more or less the same. 

If performance is your number one priority the variances between the two implementations will most likely be device specific in which case benchmarking is your friend.

Make sure the test suite covers single pass as well as carry case.

This piece of code also only reinvents the carry part of the original program count leaving in a +32 bit context also casting appropriately which may further differ potential latency/bandwidth/dutycycle benefits on your piece of gear.

Its a balanced approach that balances pros and cons of each technique (looping for multiplications, unrolling slightly for carry propagation) across phases each capitalized on particular data shape conditions.