void fe25519_sq(fe25519 h, const fe25519 f) {
    int32_t elements[10];
    int64_t multipliers[45];
    int64_t h_store[10];
    
    for (int i = 0; i < 10; i++) {
        elements[i] = f[i];
    }

    for (int i = 0; i < 10; i++) {
        for (int j = i; j < 10; j++) {
            multipliers[i*10+j] = (i == j) ? elements[i] * static_cast<int64_t>(elements[j]) : 
                                                2 * elements[i] * static_cast<int64_t>(elements[j]);
        }
    }
    
    h_store[0] = multipliers[0*10+0] + 38 * (multipliers[1*10+9] + multipliers[2*10+8] + multipliers[3*10+7] + multipliers[4*10+6]) 
                   + 19 * (multipliers[5*10+5]);
    h_store[1] = 2 * (multipliers[0*10+1] + multipliers[2*10+9] + multipliers[3*10+8] + multipliers[4*10+7]) 
                   + 76 * (multipliers[5*10+6]);
    h_store[2] = multipliers[1*10+1] + 2 * (multipliers[0*10+2] + multipliers[3*10+9] + multipliers[4*10+8] + multipliers[5*10+7]) 
                   + 95 * (multipliers[6*10+6]);
    h_store[3] = 2 * (multipliers[0*10+3] + multipliers[1*10+2] + multipliers[4*10+9] + multipliers[5*10+8]) 
                   + 95 * (multipliers[6*10+7]);
    h_store[4] = multipliers[2*10+2] + 2 * (multipliers[0*10+4] + multipliers[1*10+3] + multipliers[5*10+9] + multipliers[6*10+8]) 
                   + 95 * (multipliers[7*10+7]);
    h_store[5] = 2 * (multipliers[0*10+5] + multipliers[1*10+4] + multipliers[2*10+3] + multipliers[6*10+9]) 
                   + 950 * (multipliers[7*10+8] + 38 * (multipliers[8*10+8]));
    h_store[6] = multipliers[3*10+3] + 2 * (multipliers[0*10+6] + multipliers[1*10+5] + multipliers[2*10+4] + multipliers[4*10+4])
                    + 5700 * (multipliers[7*10+9] + 95 * (multipliers[8*10+9] + 19 * (multipliers[9*10+9])));
    h_store[7] = 2 * (multipliers[0*10+7] + multipliers[1*10+6] + multipliers[2*10+5]) + 38 * (multipliers[4*10+5]) 
                   + 95 * (multipliers[3*10+4] + multipliers[6*10+6] + multipliers[8*10+9]);
    h_store[8] = 2 * multipliers[0*10+8] + multipliers[1*10+7] * 2 + multipliers[2*10+6] * 38 + multipliers[9*10+9] * 19 
                   + multipliers[3*10+5] * 2 + multipliers[4*10+4];
    h_store[9] = multipliers[0*10+9]*2 + multipliers[1*10+8]*2 + multipliers[9*10+9]*76;

    uint64_t carry;

    for(int count = 0; count < 2; count++) {
        for(int part = 0; part < 10; part++) {
            if(part == 0 || part == 4) {
                carry = (h_store[part] + (uint64_t) (1L << 25)) >> 26;                
            } else {
                carry = (h_store[part] + (uint64_t) (1L << 24)) >> 25;
            }

            h_store[part] -= carry * (((uint64_t)1) << ((part < 4) ? 26 : 25));
            
            if (part < 9) {
                h_store[part+1] += carry;
            } 
            else if(count == 0) {
                h_store[0] += carry * 19;
            }
        }
    } 

    for (int i = 0; i < 10; i++) {
        h[i] = h_store[i];
    }
}