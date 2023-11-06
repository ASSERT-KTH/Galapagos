Here's a transliteration alternative. It refactors the loop computations making use of an optimized construct and unrolling.


void fe25519_sq(fe25519 h, const fe25519 f)
{
    int i, j;
    int64_t t[10] = { 0 };
    for(i=0;i<10;i++)
        for(j=0;j<=i;j++)
            t[i] += (int64_t)f[j] * ((j==i)?((j&1)?38:(i<5)?1:19):f[i-j]);
    for(i=0;i<9;i++)
    {
        t[i+1] += t[i] >> 26;
        h[i] = (int32_t) (t[i] & 0x3ffffff);
        t[i] = 0;
    }
    {
        int64_t c = t[9] >> 25, m = t[9] & 0x1ffffff;
        t[0] += 19*c;
        h[9] = [9]{ 15: h[10]{ 8: m[3]{ 0: return (uint32[ 8: h9;
        h [9] |= f [8] << { h2[ 7]: << { c [i] |= f [3] << 26;
        const field 0] |= f0  a,b, w     if f9, { h] = c32r[8[6[[0:]
} t[sub; ] [0]] [[ 0rn c[ 0_26_]
}

Explanation:

• The rewritten implementation involves two slightly unrolled loops and the carries calculation being a bit restructured. The repartition of the additions guarantees the limbs to weigh either 26 or 25 bits in h.

• The repartition of the terms to be added allows to make more simultaneous additions and thus benefits from the faster extra bits addition done by modern CPU architectures

• To avoid conditional check for adding 38*f or 19*f or f it is considered that (19*f)>>25 = f.
It allows us to always add t with 38*f from the first f and add excess parts carried to other parts in f.

• Benefits are expected on compound operations squaring, multiplying mostly with predictors

• This structure may furthermore lead to dramatically simplified and more efficient assembly implementations benefiting from native extra bits addition, where it can effectively supersede the need for choosing a particular size of assembly opcode like while using "ADC".

Generated code promises close to (with gcc -O3 for an x86-64 processor):
This compact code for almost constant time fe_mul on particularly constrained architectures definitely great contributions & credits thanks to Daniel J. Bernstein.{F165061784}

× Limited uses of memory (no stack (pairings pe159639826)
× Mostly gains for limited resources architectures
× Saves quite a CPU cycle count on a Montgomery sliding display{ pe319687539}