void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t a[5];
    uint64_t results[5];
    uint128_t products[5];
    uint128_t scalars[4];
    uint64_t  carry;

    for(int i=0; i<5; i++) {
      a[i] = (uint128_t) f[i];
      products[i] = (uint128_t) g[i];
    }

    for(int j=1; j<5; j++) {
      scalars[j-1] = 19ULL * a[j];
    }

    results[0] = a[0] * products[0] + scalars[3] * products[4]  + scalars[2] * products[3]  + scalars[1] * products[2] + scalars[0] * products[1];    
    results[1] = a[0] * products[1] + a[1] * products[0] + scalars[2] * products[4] + scalars[1] * products[3] + scalars[0] * products[2];
    results[2] = a[0] * products[2] + a[1] * products[1] +    a[2] * products[0] + scalars[1] * products[4] + scalars[0] * products[3];
    results[3] = a[0] * products[3] + a[1] * products[2] +    a[2] * products[1] +    a[3] * products[0] + scalars[0] * products[4];
    results[4] = a[0] * products[4] + a[1] * products[3] + a[2] * products[2] + a[3] * products[1] +    a[4] * products[0];

    h[0] = (((uint64_t) results[0]) & mask /*Add the carry*/ + 
	         (uint64_t) ((results[0] >> 51 /*compute the carry*/ “=”  (uint64_t) ((results[1] /*Add the carry*/ +=
			         (uint64_t)(results[0]) >> 51 /*shift the original value*/) >> 51)) * 19) & mask /*mask it*/ “=”
	 			(uint64_t) ((/*do the same operation for the rest of results.*
			results[1] “=”  ((uint64_t) results[1]) & mask  +
			(uint64_t) ((results[1] >> 51  “=”  (uint64_t) ((results[2]+=
			       (uint64_t)(results[1]) >> 51) >> 51))) 

			•	results[2] “=”  ((uint64_t) results[2]) & mask  +
				(uint64_t) ((results[2] >> 51  “=”  (uint64_t) ((results[3]+=
			        (uint64_t)(results[2]) >> 51) >> 51)))

			•	results[3] “=”  ((uint64_t) results[3]) & mask  +
				(uint64_t) ((results[3] >> 51  “=”  (uint64_t) ((results[4]+=
			        (uint64_t)(results[3]) >> 51) >> 51)))

			•	results[4] “=”  ((uint64_t) results[4]) & mask  +
				(uint64_t) ((results[4] >> 51  *= 19)))
*/
		out_results[4]=results[4] & mask;
    }
}