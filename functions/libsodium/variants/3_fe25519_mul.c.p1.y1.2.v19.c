Option 1: Removing intermediate carriers


void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
  int64_t h0,h1,h2,h3,h4,h5,h6,h7,h8,h9;
  int32_t f0,f1,f2,f3,f4,f5,f6,f7,f8,f9;
  int64_t g0,g1,g2,g3,g4,g5,g6,g7,g8,g9;
  
  f0 = f[0];
  f1 = f[1] * 2;
  f2 = f[2] ;
  f3 = f[3] * 2;
  f4 = f[4] ;
  f5 = f[5] * 2;
  f6 = f[6] ;
  f7 = f[7] * 2;
  f8 = f[8] ;
  f9 = f[9] * 2;
  
  g0 = g[0];
  g1 = g[1] * 19;
  g2 = g[2] ;
  g3 = g[3] * 19;
  g4 = g[4] ;
  g5 = g[5] * 19;
  g6 = g[6] ;
  g7 = g[7] * 19;
  g8 = g[8] ;
  g9 = g[9] * 19;
  
  h0 = (f0*g0 + f1*g9 + f2*g8 + f3*g7 + f4*g6 + f5*g5 + f6*g4 + f7*g3 + f8*g2 + f9*g1 ) + (((int64_t)1L<<25)>>26);

  ... (similar calculations omitted for brevity)

  h9 = f0*g9 + f1*g8 + f2*g7 + f3*g6 + f4*g5 + f5*g4 + f6*g3 + f7*g2 + f8*g1 + f9*g0 + (((int64_t)1L<<25)>>26);;
  
  h[0] = (int32_t)h0;
  h[1] = (int32_t)h1;
  h[2] = (int32_t)h2;
  h[3] = (int32_t)h3;
  h[4] = (int32_t)h4;
  h[5] = (int32_t)h5;
  h[6] = (int32_t)h6;
  h[7] = (int32_t)h7;
  h[8] = (int32_t)h8;
  h[9] = (int32_t)h9;
}


Option 2: Inline calculations:


void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
 ...


  h[0] = (int32_t)(f[0]*g[0] + 2*f[1]*19*g[9] + f[2]*19*g[8] + 2*f[3]*19*g[7] + f[4]*19*g[6] + 2*f[5]*19*g[5] + f[6]*19*g[4] + 2*f[7]*g[3]*19 + f[8]*19*g[2] + 2*f[9]*g[1]*19 +  (int64_t)(1L<<25)>>26 );


  ... (similar calculations omitted for brevity)

  h[9] = (int32_t)(f[0] * g[9] + f[1] * g[8] + f[2] * g[7] + f[3] * g[6] + f[4] * g[5] + f[5] * g[4] + f[6] * g[3] + f[7] * g[2] + f[8] * g[1] + 2*f[9]*g[0]*19 +  (int64_t)(1L<<25)>>26 );

}
 

Note: The inlined approach was more readable at first glance but not easy to keep track of changes in the function while the transformations in Option 1 require relatively less text changes and comfortable to debug.
