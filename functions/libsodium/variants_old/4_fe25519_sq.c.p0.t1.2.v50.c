fe25519_sq(fe25519 h, const fe25519 f)
{
    int32_t f_elements[10];
    for (int i = 0; i < 10; i++)
    {
        f_elements[i] = f[i];
    }

    int32_t f_twice[10], f_carry38[3], f_carry19[3];
    for (int i = 0; i < 10; i++)
    {
        if(i < 5) f_twice[i]   = f_elements[i] * 2;
        if(i > 4 && i < 8) f_carry19[i-5] = f_elements[i] * 19; 
        if(i > 4) f_carry38[i-5] = f_elements[i] * 38;        
    }

    int64_t f_array[35] = { f_elements[0] * (int64_t)f_elements[0], \
                            f_twice[0] * (int64_t)f_elements[1], 
                            f_twice[0] * (int64_t)f_elements[2],
                            f_twice[0] * (int64_t)f_elements[3],
                            f_twice[0] * (int64_t)f_elements[4],
                            f_twice[0] * (int64_t)f_elements[5],
                            f_twice[0] * (int64_t)f_elements[6],
                            f_twice[0] * (int64_t)f_elements[7],
                            f_twice[0] * (int64_t)f_elements[8],
                            f_twice[0] * (int64_t)f_elements[9],
                            f_twice[1] * (int64_t)f_elements[1],
                            f_twice[1] * (int64_t)f_elements[2],
                            f_twice[1] * (int64_t)f_twice[3],
                            f_twice[1] * (int64_t)f_elements[4],
                            f_twice[1] * (int64_t)f_twice[5],
                            f_twice[1] * (int64_t)f_elements[6],
                            f_twice[1] * (int64_t)f_twice[7],
                            f_twice[1] * (int64_t)f_elements[8],
                            f_twice[1] * (int64_t)f_carry38[2],
                            f_elements[2] * (int64_t)f_elements[2],
                            f_twice[2] * (int64_t)f_elements[3],
                            f_twice[2] * (int64_t)f_elements[4],
                            f_twice[2] * (int64_t)f_elements[5],
                            f_twice[2] * (int64_t)f_elements[6],
                            f_twice[2] * (int64_t)f_carry38[0],
                            f_elements[2] * (int64_t)f_carry38[2],
                            f_twice[3] * (int64_t)f_elements[3],
                            f_twice[3] * (int64_t)f_elements[4],              
                            f_twice[3] * (int64_t)f_twice[5],            
                            f_twice[3] * (int64_t)f_carry38[1],
                            f_twice[3] * (int64_t)f_carry38[2],    
                            f_elements[4] * (int64_t)f_elements[4],               
                            f_twice[4] * (int64_t)f_completion[5],
                            f_completion[4] * (int64_t)f_38[0],           
                            f_completion[4] * (int64_t)f_38[1],};

    int64_t h_elements[10] = { f_array[0] + f_array[18]\
                             +f_array[24] + f_array[30]\
                             + f_array[34] + f_elements[5] * (int64_t)f_completion[0] };
    for(int i = 0; i< 6; i++) h_elements[i] = f_array[i+1] + f_array[i] + f_sqlCaster

    ….

    for (int i = 0; i < 9; i++) 
    {
    	int64_t carry;
		carry = (h_elements[i] + (int64_t)(1 << (25 + i%2))) >> (26 - i%2);
        h_elements[i+1]     += carry;
        h_elements[i]   -= carry * ((int64_t) 1 << (26 - i%2));
    }
    int64_t lastElement;
    lastElement = (h_elements[9] + (int64_t)(1 << 24)) >> 25;
    h_elements[0]    += lastElement * 19;
    h_elements[9] -= lastElement * (1 << 25);

    // Method Starts
    int64_t carry;
    carry = (h_elements[0] + (int64_t)(1 << 25)) >> 26; 
    h_elements[1] += carry;
    h_elements[0] -= carry << 26;

    for(int i = 0 ; i<10; i++)h[i] = (int32_t)h_elements[i];
}
