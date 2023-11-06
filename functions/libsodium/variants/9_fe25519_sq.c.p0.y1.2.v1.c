void fe25519_sq(fe25519 h, const fe25519 f)
{
    int32_t element;
    int64_t two_multiple, thrice_multiple, product, carry;
    int64_t products_output[10];

    /* calculate two multiples, thrice multiples and product of every element in f */
    for(int32_t i=0; i < 10; ++i){
        element = f[i];
        two_multiple = 2 * element;
        thrice_multiple = 3 * element;

        if( i % 2 == 1)
            product = thrice_multiple * ((int64_t) element);
        else
            product = two_multiple * ((int64_t) element);

        products_output[i] = product;
    }

    /* Assign products by referenced index access */
    h[0] = (int32_t)products_output[0];
    h[1] = (int32_t)products_output[1];
    h[2] = (int32_t)products_output[3];
    h[3] = (int32_t)products_output[4];
    h[4] = (int32_t)products_output[0];
    h[5] = (int32_t)products_output[8];
    h[6] = (int32_t)products_output[9];
    h[7] = (int32_t)products_output[1];
    h[8] = (int32_t)products_output[2];
    h[9] = (int32_t)products_output[7];

    /* Calculate and handle any carry cases */
    for(int32_t i=0; i < 10; i++){
        carry = (products_output[i] + (int64_t)(1L << ((i % 2 == 1)?24:25))) >> ((i % 2 == 0)?26:25);

        if(i < 9){
            products_output[i+1] += carry;
        } else {
            products_output[0] += carry * 19;
        }

        products_output[i] -= carry * ((uint64_t) 1L << ((i % 2 == 1)?24:26));
        
        h[i] = (int32_t)products_output[i];
    }
}