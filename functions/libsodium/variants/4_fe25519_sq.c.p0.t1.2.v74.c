fe25519_sq(fe25519 h, const fe25519 f)
{
    int32_t f_val[10], f_val_2[10], crossed_product_val[10];
    int64_t f_squares[10], carry[10];

    int32_t crossed_values[] = { 38, 19, 38, 19, 38 };
    for(int i=0; i<10; i++){
        f_val[i] = f[i];
        f_val_2[i] = 2 * f[i];

        if(i >4 ){
            crossed_product_val[i] = crossed_values[i-5] * f[i]; 
        }       
    }
    
    for(int i=0; i<10; i++){
     for(int j=0; j<10; j++){
      if((i==j) || (i+j)==9){
         f_squares[i] = f_val[i] * (int64_t)f_val[j];
       }

      else if(i>j){
          f_squares[i] = f_val_2[i] * (int64_t) f_val[j];
      }
      
      else{
          f_squares[i] = f_val_2[i] * (int64_t) crossed_product_val[j];
       }
     }
    }
     
     for (int i = 0; i <9; i = i+2) {
        carry[i] = (f_squares[i] + (int64_t)(1L<<( 25 - (i % 2)))) >> ( 26 - (i % 2));
        f_squares[i+1] += carry[i];
        f_squares[i] -= carry[i] * ((uint64_t) 1L << (26-(i%2)));
     }

    carry[9] = (f_squares[9] + (int64_t)(1L << 24)) >> 25;
    f_squares[0] += carry[9] * 19;
    f_squares[9] -= carry[9] * ((uint64_t) 1L << 25);

    carry[0] = (f_squares[0] + (int64_t)(1L << 25)) >> 26;
    f_squares[1] += carry[0];
    f_squares[0] -= carry[0] * ((uint64_t) 1L << 26);

    for (int i = 0; i < 10; i++) {
        h[i] = (int32_t) f_squares[i];
    }
}
