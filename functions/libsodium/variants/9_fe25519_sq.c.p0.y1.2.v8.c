void fe25519_sq(fe25519 h, const fe25519 f)
{
    int32_t temp[10];
    int64_t product[10];
    int i;

    for(i = 0; i < 10; i++) {
        temp[i] = f[i];
    }

    for(i = 0; i < 10; i++){
        product[i] = 0;
        for(int j = 0; j < i+1; j++) {
            product[i] = product[i] + (int64_t)temp[j]*(temp[i-j]);
        }
        if(i%2==0){
            product[i] = product[i] - 2 * ((int64_t)temp[(i/2)+1]*temp[(i/2)+1]);
        }
    }

    product[0] = product[0] + 38 * product[9];
    for(i = 1; i < 10; i++) {
        product[i-1] = product[i-1] + 19*(product[i]>>25);
        product[i] = product[i] & 33554431;
        product[i-1] = product[i-1] + 2 * (product[i]>>25);
        product[i] = product[i] & 33554431;
        product[i-1] = product[i-1] + 38 * (product[i-1]>>27);
        product[i].product[i] & 134217727;          
   }

   for(i = 0; i < 9; i++) {
        product[i+1] = product[i+1] + 19*(product[i]>>25);
        h[i] = (unsigned int) (product[i] & 33554431);
   }
       h[9] = (unsigned int) (product[9] & 134217727);
 }