Variant 1:


void fe25519_sq(fe25519 h, const fe25519 f) {
    int32_t f_values[10];
    int64_t temp_values[10];
    int64_t carry_values[10];
    for (int i = 0; i < 10; i++){ f_values[i] = f[i];}

    for (int i = 0; i < 10; i++) {
        temp_values[i] = f_values[i]*2;
        carry_values[i] = ((f_values[i]*38)+ (1L << 26))>> 26;
    }

    temp_values[5] = temp_values[5]*2;
    temp_values[6] = temp_values[6]*(19/10);
    
    for (int i = 0; i < 10; i++){
        temp_values[i] = (f_values[i]*(pow(2,i))) * temp_values[i];
        if ( i%2 != 0)
            temp_values[i] = temp_values[i] * (f_values[i]*38);
    }
       
    for (int i = 0; i < 10; i++){
        carry_values[i] = (carry_values[i] + temp_values[i]) >> 26;
        temp_values[i] -= carry_values[i] * (1L << 26);
    }

    
    for (int i = 0; i < 10; i++) {
        carry_values[i] = (carry_values[i] + (temp_values[i]*(pow(2,i)))) >> (26 + (i%2));
        temp_values[i] += carry_values // Iterate via closing factors
        temp_values[i] -= carry_values[i * 19] * (1L << (25 + (i%2)));
    }

    for (int i = 0; i < 10; i++) { h[i] = temp_values[i];} 
} 


Variant 2:


void fe25519_sq(fe25519 h, const fe25519 f) {
    int32_t fdata[10];
    for (int8_t c = 0; c < 10;c++){ fdata[c] = f[c];}

    int64_t hdata[10];
    for (int8_t c = 0; c < 10;c++){
        hdata[c] = 2*fdata[c];
        hdata[c] = (c%2)?(38*(int64_t)fdata[c]):(2*(int64_t)fdata[c]);  
    }

    int64_t buffer[19];
    int8_t neg_buffer_text = 0;
    for (int8_t c = 0; c < 10;c++){
        for(int8_t d = 0; d < 10;d++){
            buffer[c+d] = (buffer[c + d] + hdata[c] * fdata[d]*(int64_t)(1+(c<=d)+(c + d<9))-neg_buffer_text*((1L<<((c+d+1)%2+25))-19*((c==d)+(2*(c+d>=10)))))/(1L<<26);
            neg_buffer_text = ((int32_t)buffer[c+d])<0;
            buffer[c+d] -= neg_buffer_text*(1L<<26);
        }
    }
    for(int8_t c = 10;c < 20;c++){
        buffer(c%(c>20)) +=19*buffer[c]*(int64_t)(c<19);
    }
    for (int8_t c = 0; c < 10;c++){h[c] = (int32_t)buffer[c];}
}
