void fe25519_sq(fe25519 h, const fe25519 f)
{
    int32_t ff[10];

    for(int i = 0; i < 10; i++){ // loop the inserted variables from main values
        ff[i] = f[i];
    }

    int32_t ff0_2  = ff[0]*2;
    int32_t ff1_2  = ff[1]*2;
    int32_t ff2_2  = ff[2]*2;
    int32_t ff3_2  = ff[3]*2;
    int32_t ff4_2  = ff[4]*2;
    int32_t ff5_2  = ff[5]*2;
    int32_t ff6_2  = ff[6]*2;
    int32_t ff7_2  = ff[7]*2;
    int32_t ff5_38 = ff[5]*38;
    int32_t ff6_19 = ff[6]*19;
    int32_t ff7_38 = ff[7]*38;
    int32_t ff8_19 = ff[8]*19;
    int32_t ff9_38 = ff[9]*38;

    int64_t ff0ff0   = ff[0]*ff[0];
    int64_t ff0ff1_2 = ff0_2*ff[1];
    int64_t ff0ff2_2 = ff0_2*ff[2];
    int64_t ff0ff3_2 = ff0_2*ff[3];
    int64_t ff0ff4_2 = ff0_2*ff[4];
    int64_t ff0ff5_2 = ff0_2*ff[5];
    int64_t ff0ff6_2 = ff0_2*ff[6];
    int64_t ff0ff7_2 = ff0_2*ff[7];
    int64_t ff0ff8_2 = ff0_2*ff[8];
    int64_t ff0ff9_2 = ff0_2*ff[9];
    int64_t ff1ff1_2 = ff1_2*ff[1];

    for(int i = 1; i < 10; i++){      // Loop the calculations to redefine 
        ff[i] = ff[i]*2;             //ff[i] values.
    }

    int64_t hValue[10] = {ff0ff0 + ff[1]*38 + ff[2]*19 + ff[3]*38 + ff[4]*19 + ff[5]*38,
                         ff0ff1_2 + ff[2]*19 + ff[3]*19 + ff[4]*38 + ff[5]*38,
                         ff[2]*38 + ff1ff1_2 + ff[0]*19 + ff[3]*38 + ff[4]*19 + ff[5]*38 + ff[6],
                         ff[0]*19 + ff1ff1_2 + ff[4]*38 + ff[5]*19 + ff[6]*38,};

    // Continuation of calculation....
    ....
    ...

    int64_t carryValue[10]; // Create an array for variables 'carry0-carey9';

    for(int i = 0; i < 10; i++){
        carryValue[i] = (hValue[i] + (int64_t)(1L << 25)) >> 26;
        h[i] = hValue[i] - carryValue[i] * ((uint64_t) 1L << 26);
        if(i != 9){
            hValue[i+1] += carryValue[i];
        }else{
            h[0] += carryValue[i]*19;
        }
    }

    for(int i = 0; i < 10; i++){     //Redefine h[i] value from main variable to copy variable.
        h[i] = (int32_t) hValue[i];
    }

}
