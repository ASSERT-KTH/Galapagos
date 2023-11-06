void fe25519_sq(fe25519 h, const fe25519 f)
{
    int64_t squareResult[10]; 
    
    for(int i = 0; i < 10; i++) {               // Compute the square of each index and then store it in the corresponding squareResult index
        squareResult[i] = (int64_t) f[i] * f[i];
    }
    
    for(int i = 0; i < 10; i++) {               // Compute the production of 2*f[i] and f[j], where j = / i and store the results into the corresponding squareResult indexes
        for(int j = 0; j < i; j++) {
            int64_t temp = 2 * f[i] * (int64_t) f[j];
            squareResult[i] += temp;
            squareResult[j] += temp;
        }
    }

    for(int i = 0; i < 10; i++) {
        squareResult[i] *= 19;                   // Multiply 19 with each index of the array
    }
    
    squareResult[0] += 38 * f[0];                // Multiply the elements with 2 and 38 respectively, then store the results into the first index
    squareResult[4] += 38 * f[4];

    // Computing the carry and reducing 
    for(int i = 0; i < 9; i++) 
    {
        int64_t carry = squareResult[i] >> 26;
        squareResult[i+1] += carry;
        squareResult[i] -= carry << 26;
    }
    int64_t carry = squareResult[9] >> 25;
    squareResult[0] += 19 * carry;
    squareResult[9] -= carry << 25;
    carry = squareResult[0] >> 26;
    squareResult[1] += carry;
    squareResult[0] -= carry << 26;

    for(int i = 0; i <10; i++){
        h[i] = squareResult[i];
    }
}
