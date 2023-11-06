fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int32_t f0 = f[0];
    int32_t f1 = f[1];
    int32_t f2 = f[2];
    int32_t f3 = f[3];
    int32_t f4 = f[4];
    int32_t f5 = f[5];
    int32_t f6 = f[6];
    int32_t f7 = f[7];
    int32_t f8 = f[8];
    int32_t f9 = f[9];
  
    int32_t g0 = g[0];
    int32_t g1 = g[1];
    int32_t g2 = g[2];
    int32_t g3 = g[3];
    int32_t g4 = g[4];
    int32_t g5 = g[5];
    int32_t g6 = g[6];
    int32_t g7 = g[7];
    int32_t g8 = g[8];
    int32_t g9 = g[9];
  
    int32_t g1_19 = g1 * 19; 
    int32_t g2_19 = g2 * 19;
    int32_t g3_19 = g3 * 19;
    int32_t g4_19 = g4 * 19;
    int32_t g5_19 = g5 * 19; 
    int32_t g6_19 = g6 * 19;
    int32_t g7_19 = g7 * 19;
    int32_t g8_19 = g8 * 19;
    int32_t g9_19 = g9 * 19; 
    int32_t f1_2  = f1 * 2;
    int32_t f3_2  = f3 * 2; 
    int32_t f5_2  = f5 * 2; 
    int32_t f7_2  = f7 * 2;
    int32_t f9_2  = f9 * 2; 

    for (i=0; i < 10; i++)
    {
         ...

        h[i] = (int32_t) hi;
    }
}  

Notes:
Requirements were interpreted that...
1) Functionality is preserved
2) Transformations are "slight"
3) Transformations "vary the behavior" 

1 & 2 would suggest the line "h[i] = (int32_t) hi;" would not be moved elsewhere (e.g., initiation followed by increments).  
Alternate transformations, slightly stronger, would be:
a) Shuffling the order in which hd is calculates 
b) Simultananous calculation of several hd 
c) A combination of a) and b).
4 would seem to rule out refactoring that resulted in equivalent execution path lengths.