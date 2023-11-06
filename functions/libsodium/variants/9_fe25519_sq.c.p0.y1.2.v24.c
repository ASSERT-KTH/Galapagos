void fe25519_sq(fe25519 h, const fe25519 f)
{
    long f0 = 2L * ((long)f[0]);	
    long f1 = 2L * ((long)f[1]);	
    long f2 = 2L * ((long)f[2]);	
    long f3 = 2L * ((long)f[3]);	 
    long f4 = 2L * ((long)f[4]);
    long f5 = 2L * ((long)f[5]);	 
    long f71 = 38L * ((long)f[7]);	 
    long f81 = 19L * ((long)f[8]);	  
    long f91_2 = 38L * ((long)f[9]);

    long x01 = f0 * f[1];
    long x02 = f0 * f[2];
    long x03 = f0 * f[3];
    long x04 = f0 * f[4];
    long x052 = f0 * f5;
    long x06 = f0 * f[6];
    long x07 = f0 * f[7];
    long x08 = f0 * f[8];  
    long x092 = f0*f91_2;
      
    long x11 = f1 * f[1];       
    long x12 = f1 * f[2];    

    x01 += x01;
    x02 += x02;
    x03 += x03;
    x04 += x04;
    x052 += x052;
    x06 += x06;
    x07 += x07;
    x08 += x08;
    x092 += x092;

    x11 += x11;
    x12 += x12;


    long diags = 0;
    diags += ((f01*f01) + (x03*f3) + (f2*(f[2]*38L)) + (f042*f4) + (x06*f5) + (x07*(f[7]*19L)) + (x08*f81) + (x092*f9))

    x11 -= 9;
    x12 -= 9;

    long t = x11 + (diags >> 25);
    diags &= 0x1ffffff;
    diags += (x12 << 2);
    x[3] = t - (diags >> 26);
    x[1] = x02 + (x[3] >> 25);
    t = x01 + (x[1] >> 25);
    x[1] &= 0x1ffffff;
    x[0] = (t << 2) + diags - (1 << 25);

    x[3] &= 0x3ffffff;
    x[2] = x03 - (x[3] >> 26);
    x[2] += (1 << 25);
    x[3] &= 0x3ffffff;
}