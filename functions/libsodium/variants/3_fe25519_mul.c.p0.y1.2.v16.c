
void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g) {
    int64_t h0,h1,h2,h3,h4,h5,h6,h7,h8,h9;
    int64_t f0,f1,f2,f3,f4,f5,f6,f7,f8,f9;
    int64_t g0,g1,g2,g3,g4,g5,g6,g7,g8,g9;
    int64_t r0,r1,r2,r3,r4,r5,r6,r7,r8,r9,k;
    
    k = load_3(f);
    f0=k; k=load_4(f+2); f1=k; k=load_3(f+5); f2=k;
    k=load_4(f+7); f3=k; k=load_3(f+10); f4=k;
    k=load_4(f+12); f5=k; k=load_3(f+15); f6=k;
    k=load_4(f+17); f7=k; k=load_3(f+20); f8=k;
    k=load_4(f+22); f9=k;

    k = load_3(g);
    g0=k; k=load_4(g+2); g1=k; k=load_3(g+5); g2=k;
    k=load_4(g+7); g3=k; k=load_3(g+10); g4=k;
    k=load_4(g+12); g5=k; k=load_3(g+15); g6=k;
    k=load_4(g+17); g7=k; k=load_3(g+20); g8=k;
    k=load_4(g+22); g9=k;
    
    r0 = g0*f0+2*(g1*f9+g2*f8+g3*f7+g4*f6+g5*f5)+383*(g6*f4+g7*f3+g8*f2+g9*f1);
    r1 = g0*f1+g1*f0+2*(g2*f9+g3*f8+g4*f7+g5*f6+g6*f5)+38*(g7*f4+g8*f3+g9*f2);
    r2 = g0*f2+g1*f1+g2*f0+2*(g3*f9 +g4*f8 +g5*f7+g6*f6 +g7*f5)+19*g8*f4+38*g9*f3;
    r3 = g0*f3+g1*f2+g2*f1+g3*f0 +2*(g4*f9 +g5*f8 +g6*f7 +g7*f6 +g8*f5)+19*g9*f4;
    r4 = g0*f4+g1*f3+g2*f2+g3*f1+g4*f0 +2*(g5*f9 +g6*f8 +g7*f7 +g8*f6 +g9*f5);
    r5 = g0*f5+g1*f4+g2*f3+g3*f2+g4*f1+g5*f0 +2*(g6*f9 +g7*f8 +g8*f7 +g9*f6);
    r6 = g0*f6+g1*f5+g2*f4+g3*f3+g4*f2+g5*f1+g6*f0 +2*(g7*f9 +g8*f8 +g9*f7);
    r7 = g0*f7+g1*f6+g2*f5+g3*f4+g4*f3+g5*f2+g6*f1+g7*f0 +2*(g8*f9 +g9*f8);
    r8 = g0*f8+g1*f7+g2*f6+g3*f5+g4*f4+g5*f3+g6*f2+g7*f1+g8*f0 +2*g9*f9;
    r9 = g0*f9+g1*f8+g2*f7+g3*f6+g4*f5+g5*f4+g6*f3+g7*f2+g8*f1+g9*f0;
    
    carry(&r0, &r1, 26, kp0);
    carry(&r1, &r2, 25, kp1);
    carry(&r2, &r3, 26, kp2);
    carry(&r3, &r4, 25, kp1);
    carry(&r4, &r5, 26, kp1);
    carry(&r5, &r6, 25, kp1);
    carry(&r6, &r7, 26, kp2);
    carry(&r7, &r8, 25, kp1);
    carry(&r8, &r9, 26, kp2);
    carry(&r9, &r0, 25, kp1);
    
    store_4(&h[0],&h[2],&h[4],&h[6],&h[8]);
    store_3(&h[1],&h[3],&h[5],&h[7],&h[9]);
    recve(&h[0],&h[2],&h[4],&h[6],&h[8],&h[1],&h[3],&h[5],&h[7],&h[9],&r3,&r4,&r1,&r9);
}
