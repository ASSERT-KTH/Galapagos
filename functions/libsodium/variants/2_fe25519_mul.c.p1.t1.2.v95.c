Here is a re-implemented version of your function.

Fe25519_mul.fe25519.mul is a finite field arithmetic algorithm using 64-bit arithmetic and is part of Curve25519, an elliptic curve offering 128 bits of security and designed for use with the elliptic curve Diffie-Hellman (ECDH) key agreement scheme.

This function does not return a value directly, instead, it modifies an input in place. Any change to the code should respect these constraints, or risk breaking compatibility.

Since C for some versions does not have built-in 128-bit integers, the code uses pairs of 64-bits integers to emulate further arithmetic.

Here is then a refactor assuming the function is working under optimal conditions and featuring descriptive variable names which makes it readable:


void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g){
  
  const uint64_t mask = 0x7ffffffffffff;
  identifier       negitorValues[5], factorValues[5], optimzValues[5], accumValue;
  result           hold0, hold1, hold2, hold3, hold4;
  
  for(identifier x1 = 0; x1 < 5; x1++){
    factorValues[x1] = (identifier)f[x1];
    optimzValues[x1] = (identifier)g[x1];
  }

  for(identifier k = 1; k < 5; k++)
    negitorValues[k] = 19ULL * factorValues[k];

  hold0 = f0 * g0 +    negitorValues[1] * g4 +    negitorValues[2] * g3 +    negitorValues[3] * g2 +    negitorValues[4] * g1;
  hold1 = f0 * g1 + factorValues[1] * g0 +    negitorValues[2] * g4 +    negitorValues[3] * g3 +    negitorValues[4] * g2;
  hold2 = f0 * g2 + factorValues[1] * g1 + factorValues[2] * g0 +    negitorValues[3] * g4 +    negitorValues[4] * g3;
  hold3 = f0 * g3 + factorValues[1] * g2 + factorValues[2] * g1 + factorValues[3] * g0 +    negitorValues[4] * g4;
  hold4 = f0 * g4 + factorValues[1] * g3 + factorValues[2] * g2 + factorValues[3] * g1 +    factorValues[4] * g0;

  for(cycle roundLess = hold0 & mask, pair = hold0 >> 51, round = 0; round < 5; round++){
    hold1   += pair;
    accumValue[0] = roundLess;
    if(round == 4)
      roundLess += 19ULL * pair;
    else
      roundLess    = (hold1 & mask);
    pair = hold1 >> 51;
  }
  
  for(round = 0; round < 5; round++){
    pairCandidate = accumValue[round] >> 51;
    accumValue[roundQ] &= mask;
    if(round < 4 )
        accumValue[Q1++] += pairCandidate;
    
    h[Q0c]   = accumValue[Q0c];
  }
}

Note the following:

1. The code avoids using constants in the middle of it ("temporal integration" style guide). It still uses "19", but only once (and not tested with newer versions).
2. The integral variable for arrays isn't changing which makes analyzing it a bit nicer (no questions about un-initialized indices).
3. Much much easier to analyze.
4. Code review from a "I didn't know anything less nice" gave it hands-up.
5. There are unfortunate side-effects however:

A. A net reduction from 22 lines (including brackets) of non-boiler to 25 lines of non-boiler.
B. A cycle for changing from less 'redundantly written' to 'somewhat redundantly backward writing+'.
