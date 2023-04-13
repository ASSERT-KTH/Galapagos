#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <math.h>

#define BLOCK_SIZE 64

typedef uint32_t u32;
typedef uint8_t u8;

typedef struct {
    u32 state[4];
    u32 count[2];
    u8 buffer[BLOCK_SIZE];
} MD5_CTX;

void md5_init(MD5_CTX *ctx);
void md5_update(MD5_CTX *ctx, const u8 *input, size_t input_len);
void md5_final(MD5_CTX *ctx, u8 digest[16]);

static void md5_transform(u32 state[4], const u8 block[BLOCK_SIZE]);
static void encode(const u32 *input, u8 *output, size_t output_len);
static void decode(const u8 *input, u32 *output, size_t output_len);

#define ROL(x, n) (((x) << (n)) | ((x) >> (32 - (n))))
#define F(x, y, z) (((x) & (y)) | (~(x) & (z)))
#define G(x, y, z) (((x) & (z)) | ((y) & ~(z)))
#define H(x, y, z) ((x) ^ (y) ^ (z))
#define I(x, y, z) ((y) ^ ((x) | ~(z)))

#define FF(a, b, c, d, x, s, ac) { \
    (a) += F((b), (c), (d)) + (x) + (u32)(ac); \
    (a) = rotate_left((a), (s)); \
    (a) += (b); \
}

#define GG(a, b, c, d, x, s, ac) { \
    (a) += G((b), (c), (d)) + (x) + (u32)(ac); \
    (a) = rotate_left((a), (s)); \
    (a) += (b); \
}

#define HH(a, b, c, d, x, s, ac) { \
    (a) += H((b), (c), (d)) + (x) + (u32)(ac); \
    (a) = rotate_left((a), (s)); \
    (a) += (b); \
}

#define II(a, b, c, d, x, s, ac) { \
    (a) += I((b), (c), (d)) + (x) + (u32)(ac); \
    (a) = rotate_left((a), (s)); \
    (a) += (b); \
}

static u32 S[64] = {
    7, 12, 17, 22,  7, 12, 17, 22,  7, 12, 17, 22,  7, 12, 17, 22,
    5,  9, 14, 20,  5,  9, 14, 20,  5,  9, 14, 20,  5,  9, 14, 20,
    4, 11, 16, 23,  4, 11, 16, 23,  4, 11, 16, 23,  4, 11, 16, 23,
    6, 10, 15, 21,  6, 10, 15, 21,  6, 10, 15,21,  6, 10, 15, 21,  6, 10, 15, 21
};

static const u32 T[64] = {
    0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
    0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
    0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
    0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
    0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
    0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
    0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
    0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
    0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
    0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
    0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,
    0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
    0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
    0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
    0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
    0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391
};

void md5_init(MD5_CTX *ctx) {
    ctx->state[0] = 0x67452301;
    ctx->state[1] = 0xefcdab89;
    ctx->state[2] = 0x98badcfe;
    ctx->state[3] = 0x10325476;

    ctx->count[0] = 0;
    ctx->count[1] = 0;
}

void md5_update(MD5_CTX *ctx, const u8 *input, size_t input_len) {
    u32 i, index, part_len;

    index = (ctx->count[0] >> 3) & 0x3F;

    ctx->count[0] += (u32)(input_len << 3);
		if (ctx->count[0] < (u32)(input_len << 3)) {
			ctx->count[1]++;
		}
	ctx->count[1] += (u32)(input_len >> 29);
	part_len = BLOCK_SIZE - index;

	if (input_len >= part_len) {
	    memcpy(&ctx->buffer[index], input, part_len);
	    md5_transform(ctx->state, ctx->buffer);

	    for (i = part_len; i + BLOCK_SIZE <= input_len; i += BLOCK_SIZE) {
	        md5_transform(ctx->state, &input[i]);
	    }

	    index = 0;
	} else {
	    i = 0;
	}

	memcpy(&ctx->buffer[index], &input[i], input_len - i);
	}

	void md5_final(MD5_CTX *ctx, u8 digest[16]) {
	u8 bits[8];
	u32 index, pad_len;

	encode(ctx->count, bits, 8);

	index = (ctx->count[0] >> 3) & 0x3f;
	pad_len = (index < 56) ? (56 - index) : (120 - index);

	u8 padding[BLOCK_SIZE] = {0x80};
	md5_update(ctx, padding, pad_len);
	md5_update(ctx, bits, 8);

	encode(ctx->state, digest, 16);

	memset(ctx, 0, sizeof(MD5_CTX));

	}

static void md5_transform(u32 state[4], const u8 block[BLOCK_SIZE]) {
	u32 a = state[0], b = state[1], c = state[2], d = state[3], x[16];

	decode(block, x, BLOCK_SIZE);

	for (int i = 0; i < 64; i++) {
	    u32 t, round_idx = i >> 4;
	    switch (round_idx) {
	    case 0:
        a = b + ROL((a + F(b, c, d) + x[i] + T[i]), S[i]);
        break;
    case 1:
        a = b + ROL((a + G(b, c, d) + x[(5 * i + 1) % 16] + T[i]), S[i]);
        break;
    case 2:
        a = b + ROL((a + H(b, c, d) + x[(3 * i + 5) % 16] + T[i]), S[i]);
        break;
    case 3:
        a = b + ROL((a + I(b, c, d) + x[(7 * i) % 16] + T[i]), S[i]);
        break;
      }

	    u32 tmp = d;
	    d = c;
	    c = b;
	    b = a;
	    a = tmp;
	}

	state[0] += a;
	state[1] += b;
	state[2] += c;
	state[3] += d;

	memset(x, 0, sizeof(x));
}

static void encode(const u32 *input, u8 *output, size_t output_len) {
  for (size_t i = 0, j = 0; j < output_len; i++, j += 4) {
    output[j] = (u8)(input[i] & 0xff);
    output[j + 1] = (u8)((input[i] >> 8) & 0xff);
    output[j + 2] = (u8)((input[i] >> 16) & 0xff);
    output[j + 3] = (u8)((input[i] >> 24) & 0xff);
  }
}

static void decode(const u8 *input, u32 *output, size_t input_len) {
  for (size_t i = 0, j = 0; j < input_len; i++, j += 4) {
  output[i] = ((u32)input[j]) | (((u32)input[j + 1]) << 8) |
  (((u32)input[j + 2]) << 16) | (((u32)input[j + 3]) << 24);
  }
}

int main(int argc, char *argv[]) {
  const char *msg = "The quick brown fox jumps over the lazy dog.";
  u8 digest[16];
  MD5_CTX ctx;

  md5_init(&ctx);
  md5_update(&ctx, (const u8 *)msg, strlen(msg));
  md5_final(&ctx, digest);

  for (int i = 0; i < 16; i++) {
      printf("%02x", digest[i]);
  }
  printf("\n");

  return 0;
}
