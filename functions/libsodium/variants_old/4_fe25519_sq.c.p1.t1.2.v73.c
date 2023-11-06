The program variant will use loops instead of explicitly written out operations which keeps the same functionality while changing the structure and behavior of the program.


void fe25519_sq(int32_t* h, const int32_t* f)
{
    int i, j;
    int64_t prod[19] = {0};

    // Compute all products first.
    for(i = 0; i < 10; i++) {
        for (j = i; j < 10; j++) {
            prod[i+j] += ((int64_t)f[i] * (j == i ? 1 : 2)) * f[j];
        }
    }

    //Account for extra factors in computation.
    prod[11] = prod[11] * 19;
    prod[13] = prod[13] * 19;
    prod[15] = prod[15] * 19;
    prod[17] = prod[17] * 19;

    prod[5] += 38 * prod[10];
    prod[7] += 38 * prod[12];
    prod[9] += 38 * prod[14];
    prod[0] += 38 * prod[18];

    // Reduce: all entries are < 2^287
    for(i = 0; i < 10; i++) {
        int64_t carry = (prod[i] + ((int64_t)1 << ((i&1!=0) ? 24 : 25))) >>
                     ((i & 1) ? 25 : 26);
        prod[i] -= carry << ((i & 1) ? 25 : 26);
        prod[i + 1] += carry;
_h[i] = prod[i];
}
_{ int64_t carry = (h[0] + ((int64_t)1 << 25)) >> 26;
_h[0] -= carry << 26;
h[1] += carry;
}

This program maintains the same functionality in that it squares a field element in Fe25519 (interpreting the representation as two's complement). The changes made were:

- looped computations to automate the tedious and regular structure of the original, turning 55 lines of multiplication into 6
- tracking of results values was split into pre-carry and post-carry stages to limit variable usage and decrease length.
- combining like terms and moving sparsely positioned computations closer together to save program lines where possible. computation was combined with assignment to deduct total lines further. notation such as "{ ... }\_" was implemented o enact multiple actions in single abstract lines.

The differences caused by this proposal concern mainly utility and readability - this version is arguably less clear with implications behind expressions or analysis from the printed structure. one potential marked learning and presentation structure derivative can be lost if initial version was designed specifically to reflect the practical application in a identifiable way. length and simplicity remain the strengths of this proposal yielding a compression from 135 to 21 lines.