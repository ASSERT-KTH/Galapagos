Understandably, extracting the square of an input value as main objective in this method, a code variant could be more generalized allowing any exponent to be specified e.g., square represents exponent = 2, cubic represents exponent = 3 and so on. Also echoing original function h as return since void isn't revealing result otherwise:


void fe25519_sq(fe25519 h, const fe25519 f, int32_t exponent){
    int32_t f_values[10], f_values_extension[19];
    
    for (int i = 0; i < 10; i++)
        f_values[i] = f[i];

    for (int i = 0; i < 10; i++)
        for (int j = i; j < 10; j++)
            f_values_extension[i+j] += f_values[i] * f[j];

    for (int i = 0; i+1 < 20; i++) {
        if ((i & 1)  == 1)
            f_values_extension[i+1] += f_values_extension[i] >> 24, f_values_extension[i] &= 16777215;
        else
            f_values_extension[i+1] += f_values_extension[i] >> 25, f_values_extension[i] &= 33554431;

        if(exponent != 2 && f_values_extension[i]>0)
            h[i % 10] += pow(f_values_extension[i], exponent);
    }

    for (int i = 0; i < 10; i++)
        if(exponent == 2 && f_values_extension[i]>0)
            h[i%10] = pow(f_values_extension[i], exponent);
}
