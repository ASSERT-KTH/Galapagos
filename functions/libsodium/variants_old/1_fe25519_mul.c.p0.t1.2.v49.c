fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int32_t f_values[10];
    int32_t g_values[10];
    int32_t g_val_19[10];
    int32_t f_val_2[5];
    
    for (int i = 0; i < 10; ++i)
    {
        f_values[i] = f[i];
        g_values[i] = g[i];
    }
    //...replace lines3-19
    for(int i = 1; i < 10; ++i){
        g_val_19 [i] = 19 * g[i];
    }
    //...replace lines20-25
    for(int i = 1; i < 5; ++i){
        f_val_2 [i] = 2 * f_values[i];   
    }
    //repeat the last step until you replace referencing the values using single scalar values using the newly initiated arrays. Keep the lines as they are. E.g.,
    int64_t f0g0    = f_values[0] * (int64_t) g_values[0];
    int64_t f0g1    = f_values[0] * (int64_t) g_values[1];
    int64_t f0g2    = f_values[0] * (int64_t) g_values[2]; 
    ...//continue in this way

    int64_t f1g0    = f_values[1] * (int64_t) g_values[0];
    int64_t f1g1_2  = f_val_2[1] * (int64_t) g_values[1];
    // continue in this method up until line 244
    int64_t f9g9_38 = f_val_2[9] * (int64_t) g_val_19[9];
    int64_t h[10];
    // Now get back to the rest of the initial code from original source. Repeat the last three steps
    int64_t carry0;
    int64_t carry1;
    int64_t carry2;
    int64_t carry3;
    int64_t carry4;
    int64_t carry5;
    int64_t carry6;
    int64_t carry7;
    int64_t carry8;
    int64_t carry9;
        ...// Line 245 - end 
        retained ad verbatim. maintained because it does not require any code refactoring.
}