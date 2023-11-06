void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int64_t f0g0_9g2837_78__18_5 = ((int64_t)f[0]*(int64_t)g[0])+((int64_t)f[1]*(int64_t)g[9]*38*2)+(((int64_t)f[2]*g[8]
            + (int64_t)f[3]*g[7])*19*2)+((int64_t)f[4]*g[6]*19)+((int64_t)f[5]*(int64_t)g[5]*38*2)+((int64_t)f[6]*g[4]*19)
            +((int64_t)f[7]*g[3]*38*2)+((int64_t)f[8]*g[2]*19)+((int64_t)f[9]*g[1]*38*2);

    int64_t f1g838g3839_2 = ((int64_t)f[0]*g[1])+((int64_t)f[1]*g[0])+((int64_t)f[2]*g[9]*19)+((int64_t)f[3]*g[8]*19)+((int64_t)f[4]*g[7]
            *19)+((int64_t)f[5]*g[6]*19)+((int64_t)f[6]*g[5]*19)+((int64_t)f[7]*g[4]*19)+((int64_t)f[8]*g[3]*19)+((int64_t)f[9]*g[2]*19);

    int64_t int64_acc_array[10];
    for (size_t i = 0; i < 10; i++){
        if(i % 2 == 0){
            int64_acc_array[i] = (f1g838g3839_2 + 33554432) >> 25;
        }
        else {
            int64_acc_array[i] = (((int64_t)f[0] * (int64_t) g[0]) + 33554432) >> 26;
        }
    }
    for(size_t i = 0; i < 10; i++){
        if(i % 2 == 0){
            int64_acc_array[i+1] += int64_acc_array[i];
            int64_acc_array[i] -= int64_acc_array[i] * (33554432 * 2);
        }
        else if(i != 9){
            int64_acc_array[i+1] += int64_acc_array[i];
            int64_acc_array[i] -= int64_acc_array[i] * 33554432;
        }
    }
    // Overflow handling for the last element
    carry_mulf9_2 = int64_acc_array[0] >> 26;
    // first element of the array
    h[0] = int64_acc_array[9] *= f0g0_9g2837_78__18_5 * carry_mulf9_2;

    for(size_t i = 1; i < 10; i++){
        if(i % 2 == 0){
            h[i] = (int64_acc_array[i-1] + (1 << 24)) >> 25;
            // explicitly calculate the carry for the next iteration
            carry = (int64_acc_array[i] + (1 << 25)) >> 26;
        }
        else{
            h[i] = int64_acc_array[i];
            carry = 0;
        }
    }
}