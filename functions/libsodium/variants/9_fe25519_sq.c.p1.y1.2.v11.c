Variants of the original function preserving its functionality:

Variant 1: 

Inline all the local arithmetic operations to eliminate extra lines of code.


void fe25519_sq(fe25519 h, const fe25519 f)
{
    int64_t h0 = f[0] * (int64_t) f[0] + f[1]*2 * (int64_t) (f[9] * 38) + f[2]*2 * (int64_t) (f[8] *19) + f[3]*2 * (int64_t) (f[7] *38) + f[4]*2 * (int64_t) (f[6] * 19) + f[5] * (int64_t) (38*f[5]);
    int64_t h1 = f[0]*2 * (int64_t) f[1]  + f[2]*2 * (int64_t) (f[9] * 38) + f[3]*2 * (int64_t) (f[8] * 19) + f[4] * (int64_t) (f[7] * 38) + f[5]*2 * (int64_t) (f[6] * 19);
    //Similarly for other operations,
    // Now perform computation for all variables h0-h9

    // Perform assigned operations on the carry variables
    //...

    h[0] = (int32_t) h0;
    h[1] = (int32_t) h1;
    // similarly for other output values 
}


Variant 2: 

Another kind of transformation might involve interleaving computations a bit more.


void fe25519_sq(fe25519 h, const fe25519 f)
{
    int64_t h0, h1, h2, h3, h4;
    int64_t carry0, carry1, carry2, carry3, carry4, carry5, carry6;
    h0 = f[0] * (int64_t)f[0] ;
    h0 += f[1]*2 * (int64_t)(f[9]*38);
    h0 += f[2]*2 * (int64_t)(f[8]*19);
    h0 += f[3]*2 * (int64_t)(f[7]*38);
    h4 = f[0]*2 * (int64_t)f[4];
    h4 += f[4] * (int64_t)f[4];
    h4 += f[0]*2 * (int64_t)f[4];
    h1 = f[1]*2 * (int64_t)f[1];
    h1 += f[1]*f[1];
    // and so on...
}

You could technically make one continuous chain of computations but it might hurt the readability.
Keep in mind that how Compiler optimizes a piece of code for execution can be dependent on various factors and complexities!

Variant 3: 

Use for tables to move the constants to one table.

void fe25519_sq(fe25519 h, const fe25519 f)
{
    int mutl[19];
    for(unsigned int ix = 0; ix < 19; ix+=2){
        mult[ix] = f[ix & 10] * (b % 2 ? 38 : 19) * f[ix % 10];
        mult[ix+1] = ix > 10 ? f[ix] * f[ix] : f[ix]*2 * f[ix > 10 - ix ? 9 : ix + 1]
    }
    h0 = mult[0] + mult[1] + mult[2] + mult[3] + mult[4] + mult[5];
    h1 = mult[6] + mult[7] + mult[8] + mult[9] + mult[10];
    ...
}


Not all variants might perform the same on all hardwares and complier configurations as they have different optimization strategies and requirement.

Examples specifically show that the code uses more clean struct of format style.