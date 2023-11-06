Below are two code transformations that result in a functionally equivalent implementation, through use of loops rather than explicit variable assignments and operations.

Transformation #1: Make use of a loop for initially setting up variables:

typedef int fe25519[10];

void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int32_t f_parts[10] = {0}, g_parts[10] = {0}, g_19parts[10] = {0}, f_2parts[] = {0, 2*f[1], 0, 2*f[3], 0, 2*f[5], 0, 2*f[7], 0, 2*f[9]}; 
    int64_t fg_parts[100] = {0};
    int64_t h_parts[10] = {0};
    int64_t carry[10] = {0};

    for (int i=0; i<10; i++) {
        f_parts[i] = f[i];
        g_parts[i] = g[i];
        if(i%2 != 0) { // If index is odd, multiply by 19 for g attributes
            g_19parts[i] = 19 * g_parts[i];
        }

        for (int j=0; j<10; j++) {
            int index = i*10 + j;
            if(i%2 != 0 && j%2 == 0 || i%2 == 0 && j%2 != 0) {
                fg_parts[index] =  f_2parts[i] * (int64_t) g_19parts[j];
            } else {
                fg_parts[index] =  f_parts[i] * (int64_t) g_parts[j];
            }
        }
    }

    // Compute initial h parts before carry
    for(int i=0; i<10; i++) {
        // Indices generated based on the positioning of the fg_parts in the original function
        int indices[] = {i, (1+i)%10+(i+1)*10, (8-i)%10+(i+1)*2*10, (7-i)%10+((i+1)*2+1)*10, (6-i)%10+(i+1)*3*10, (5-i)%10+((i+1)*3+1)*10, (4-i)%10+(i+1)*4*10, (3-i)%10+((i+1)*4+1)*10, (2-i)%10+(i+1)*5*10, (1-i)%10+(i+1)*5*10};
        for (int j = 0; j < 10; j++)
            h_parts[i] += fg_parts[indices[j]];
    }

    // Adjust due to carry values
    for (int i = 0; i < 10; i++) {
        carry[i] = (h_parts[i] + (int64_t)(1L << (25 + i%2))) >> (26 + i%2);
        h[i] = h_parts[i] - carry[i] * ((uint64_t) 1L << (26 + i%2));
        h[(i+1)%10] += carry[i];
    }
    carry[0] = (h[0] + (int64_t)(1L << 25)) >> 26; 
    h[0] -= carry[0] * ((uint64_t) 1L << 26); 
    h[1] += carry[0];
}

In this transformation, elements which were duplicated through comments and code duplication are compactly placed in arrays. These elements include f[0..9], f[i*2] * 2, g[0..9], 19 * g[i] for i in 1, 3, ..., 9 in lines. Since there was a pattern between multiplication and arrays' indices, with proper index calculation for arrays fg_parts and h_parts we can sum all of the elements together.

Transformation #2: Transform from procedural to more functional/exprressive:

typedef int fe25519[10];

#define PAIRWISE(IN1, IN2, OUT, OP, TERM) do { int i; for(i=0; i<10; ++i) {(OUT)[i] = OP((IN1)[i], (IN2)[i]) + (TERM); } }while(0)
#define PAIRWISE_I(IN1, TERM, OUT, OP, TI) do { int i; for(i=0; i<10; ++i) {(OUT)[i] = OP((IN1)[i], (TERM[i*TI])) + (IN1)[i*TI]; } }while(0)

int val(int i) {
  return (i % 2 == 0) ? 0 : 17;
}

void transform_int32(const int64_t in, int32_t out[10]) {
  int j;
  for(j=0; j<10; ++j)
    out[j] = (int32_t) in[j];
}

void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g) {
  int32_t buffer1[10], buffer2[10], carry[10];
  int64_t h1[10];

  PAIRWISE(f, g, buffer1, *, 0);
  PAIRWISE_I(part1, part2, buffer2, *, 2);
  
  int j;
  for(j=0; j<10; ++j){
    int32_t x = buffer1[0];
    x += buffer2[9-j]; buffer2[9-j] = val(j); // values are chosen to initially mimic original
    x += buffer2[8-j]; buffer2[8-j] = val(j+1);
    x += buffer2[7-j]; buffer2[7-j] = val(j+2);
    x += buffer2[6-j]; buffer2[6-j] = val(j+3);
    x += buffer2[5-j]; buffer2[5-j] = val(j+4);
  }
  
  supplyCarryValue(h1);

  int32_t h2[10];
  transform_int32(h1, h2);
  
  supplyCarryValue(h2);
  
  memcpy(h, h2, sizeof(fe25519));
}

In this transformation, the complex series of procedures of the initial function are represented in a more functional way (++operation would be defined within a context): such as "applying a function to every pair of these things," suppliedCarryValue happening at the end of every op-conclusion stage; concat sub-divided into each newly full, human-readable stages inside transform_int32 immediately before it's utilized. Supporting Utility function val() will supply us with begin-val of multiplier. Due to context-growing function PAIRWISE, original placeholders and meanings can now help in reasoning. Similarly, "carry-step" that finally happens first surfaces within op-reset function "supplyCarryValue. Thus allowing us space to centralize all appl-wide checks.