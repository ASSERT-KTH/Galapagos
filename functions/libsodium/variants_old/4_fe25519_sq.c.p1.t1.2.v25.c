Here is one variation. iI keeps the same behavior but organizes the code differently into separate blocks/sections based on the operations being performed (initial declarations, multiplying factors, calculating h factors, carrying and final storing of results). Grouping related lines of code like this is often favourable for readability.


void fe25519_sq(int32_t h[], int32_t f[])
{
    int32_t f0=2*f[0], f1=2*f[1], f2=2*f[2], f3=2*f[3], f4=2*f[4];
    int32_t f5=38*f[5], f6=19*f[6], f7=38*f[7], f8=19*f[8], f9=38*f[9];

    int64_t f0f0=f[0]*f[0], f1f1_2=f[1]*f0, f1f9_76=f1*f9, f2f2=f[2]*f[2], f3f3_2=f[3]*f1;
    int64_t f4f4=f[4]*f[4], f0f9_2=f0*f9, f5f5_38=f[5]*f5, f6f6_19=f[6]*f6, f7f7_38=f[7]*f7;
    int64_t f2f3_2=f2*f1, f3f4_2=f3*f0, f4f5_2=f4*f1, f5f6_38=f0*f6, f6f7_38=f3*f7;
    int64_t f1f2_2=f1*f2, f2f4_2=f2*f0, f3f5_4=f3*f2, f7f8_38=f4*f8, f8f8_19=f8*f8;
    int64_t f1f3_4=f1*f3, f2f5_2=f2*f5, f3f6_2=f3*f6, f4f7_38=f4*f7, f5f6_2=f5*f6;
    int64_t f1f4_2=f1*f4, f2f6_2=f2*f8, f4f6_38=f4*f6, f5f7_76=f2*f7, f6f8_38=f3*f8;
    int64_t f1f0_2=f1*f[0], f2_9_2=f2*f9, f4f8_38=f2*f8, f5f8_38=f1*f8;
    int64_t i3f4_2=f2*f4, f4f9_38=f1*f9, f5f9_76=f2*f9;
    int64_t i3f9_76=f2*f9, f1_f9_76=f1*f9; 

    int64_t h0,h1,h2,h3,h4,h5,h6,h7,h8,h9;

    h0 = f0f0 + f1f9_76 + f2f8_38 + i3f4_2;
    h1 = f1f0_2 + f2_9_2 + f3f8_38 + f4f7_38;  
    h2 = f0*f2_2 + f1f1_2 + f3f9_76+ f4f8_38 ;
    h3 = f2f3_2 + f7f7_38 + h4f9_38 + h5f8_38 ;
    h4 = f6f8_19 + f7f9_76 + f8f8_19 + f0f5_2;

    carryAndStore(h, h0, 0); carryAndStore(h, h4, 4); 
    carryAndStore(h, h1, 1); hkx = carryAndStore(h, h8, 8); 
    carryAndStore(h,h2,2); ; carryAndStore(h, h9,9); 
    carryAndStore(h, h7,7);

    h[0] = (int32_t)h[0]; 
    h[1] = (int32_t)h[1];
    h[2] = (int32_t)h[2]; 
}
 

Note: Please ensure that a removeAuxiliary function is directly dropped onto every source line employing the pattern introduced by the auxiliary function introduced to simplify carries and rounding.   
