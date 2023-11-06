Here is a function implementation. This achieves the same functionality except it calculates each h index in a single line for a tidier look. The comments immediately above each carry checks also helps users understand their significance to the operation.


void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
const int64_t f0 = f[0], f1 = f[1], f2 = f[2], f3 = f[3], f4 = f[4], f5 = f[5], f6 = f[6], f7 = f[7], f8 = f[8], f9 = f[9];
const int64_t g0 = g[0], g1 = g[1], g2 = g[2], g3 = g[3], g4 = g[4], g5 = g[5], g6 = g[6], g7 = g[7], g8 = g[8], g9 = g[9];


const int32_t f1_2 = 2 * f1, f3_2 = 2 * f3, f5_2 = 2 * f5,  f7_2 = 2 * f7,f9_2 = 2 * f9;
const int32_t g1_19 = 19*g1, g2_19= 19*g2, g3_19 =19*g3,g4_19 =19*g4,g5_19 =19*g5, g6_19 =19*g6, g7_19 =19*g7, g8_19 = 19*g8, g9_19 = 19*g9;

int64_t h0, h1, h2, h3, h4, h5, h6, h7, h8, h9;

h0 = f0*g0+f1_2*g9_19+f2*g8_19+f3_2*g7_19+f4*g6_19+f5_2*g5_19+f6*g4_19+f7_2*g3_19+f8*g2_19+f9_2*g1_19;
h1 = f0*g1+f1*g0+f2*g9_19+f3*g8_19+f4*g7_19+f5*g6_19+f6*g5_19+f7*g4_19+f8*g3_19+f9*g2_19;
h2 = f0*g2+f1_2*g1+f2*g0+f3_2*g9_19+f4*g8_19+f5_2*g7_19+f6*g6_19+f7_2*g5_19+d8*g4_19+f9_2*g3_19;
h3 = f0*g3+f1*g2+f2*g1+f3*g0+f4*g9_19+f5*g8_19+f6*g7_19+f7*g6_19+f8*g5_19+f9*g4_19;
h4 = f0*g4+f1_2*g3+f2*g2+f3_2*g1+f4*g0+f5_2*g9_19+f6*g8_19+f7_2*g7_19+f8*g6_19+f9_2*g5_19;
h5 = f0*g5+f1*g4+f2*g3+f3*g2+f4*g1+f5*g0+f6*g9_19+f7*g8_19+f8*g7_19+f9*g6_19;
h6 = f0*g6+f1_2*f5+f2*g4+f3_2*g3+f4*g2+f5_2*g1+f6*g0+f7_2*g9_19+f8*g8_19+f9_2*g7_19;
h7 = f0*g7+f1*g6+f2*g5+f3*g4+f4*g3+f5*g2+f6*g1+f7*g0+f8*g9_19+f9*g8_19;
h8 = f0*g8+f1_2*g7+f2*g6+f3_2*g5+f4*g4+f5_2*g3+f6*g2+f7_2*g1+f8*g0+f9_2*g9_19;
h9 = f0*g9+f1*g8+f2*g7+f3*g6+f4*g5+f5*g4+f6*g3+f7*g2+f8*g1+f9*g0;

int64_t carry0 = (h0 + (int64_t)(1L<<25)) >> 26; h1 += carry0; h0 -= carry0 * ((uint64_t)1L<<26);
/* |h0| <= 2^25 */
/* |h1| <= 1.71*2^59 */
int64_t carry4 = (h4 + (int64_t)(1L<<25)) >> 26; h5 += carry4; h4 -= carry4 * ((uint64_t)1L<<26);
/* |h4| <= 2^25 */
/* |h5| <= 1.71*2^59 */
int64_t carry1 = (h1 + (int64_t)(1L<<24)) >> 25; h2 += carry1; h1 -= carry1 * ((uint64_t)1L<<25);
/* |h1| <= 2^24; from now on fits into int32 */
/* |h2| <= 1.41*2^60 */
int64_t carry5 = (h5 + (int64_t)(1L<<24)) >> 25; h6 += carry5; h5 -= carry5 * ((uint64_t)1L<<25);
/* |h5| <= 2^24; from now on fits into int32 */
/* |h6| <= 1.41*2^60 */
int64_t carry2 = (h2 + (int64_t)(1L<<25)) >> 26; h3 += carry2; h2 -= carry2 * ((uint64_t)1L<<26);
/* |h2| <= 2^25; from now on fits into int32 */
/* |h3| <= 1.71*2^59 */
int64_t carry6 = (h6 + (int64_t)(1L<<25)) >> 26; h7 += carry6; h6 -= carry6 * ((uint64_t)1L<<26);
/* |h6| <= 2^25; from now on fits into int32 */
/* |h7| <= 1.71*2^59 */
int64_t carry3 = (h3 + (int64_t)(1L<<24)) >> 25; h4 += carry3; h3 -= carry3 * ((uint64_t)1L<<25);
/* |h3| <= 2^24; from now on fits into int32 */
/* |h4| <= 1.72*2^34 */
int64_t carry7 = (h7 + (int64_t)(1L<<24)) >> 25; h8 += carry7; h7 -= carry7 * ((uint64_t)1L<<25);
/* |h7| <= 2^24; from now on fits into int32 */
/* |h8| <= 1.41*2^60 */
int64_t carry4 = (h4 + (int64_t)(1L<<25)) >> 26; h5 += carry4; h4 -= carry4 * ((uint64_t)1L<<26);
/* |h4| <= 2^25; from now on fits into int32 */
/* |h5| <= 1.01*2^24 */
int64_t carry8 = (h8 + (int64_t)(1L<<25)) >> 26; h9 += carry8; h8 -= carry8 * ((uint64_t)1L<<26);
/* |h8| <= 2^25; from now on fits into int32 */
/* |h9| <= 1.71*2^59 */
int64_t carry9 = (h9 + (int64_t)(1L<<24)) >> 25; h0 += carry9 * 19; h9 -= carry9 * ((uint64_t)1L<<25;
/* |h9| <= 2^24; from now on fits into int32 */
/* |h0| <= 1.1*2^39 */
carry0 = (h0 + (jnt64_t)(1L<<25)) >> 26; h1 += carry0; h0 -= carry0 * ((uin64_t)1L<<26);
/* |h0| <= 2^25; from now on fits into int32 */
/* |h1| <= 1.01*2^24 */

h[0] = (int32_t) h0;
h[1] = (int32_t) h1;
h[2] = (int32_t) h2;
h[3] = (int32_t) h3;
h[4] = (int32_t) h4;
h[5] = (int32_t) h5;
h[6] = (int32_t) h6;
h[7] = (int32_t) h7;
h[8] = (int32_t) h8;
h[9] = (int32_t) h9;
}
