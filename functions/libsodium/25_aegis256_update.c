aegis256_update(aes_block_t *const state, const aes_block_t data)
{
    aes_block_t tmp;

    tmp      = AES_BLOCK_XOR(AES_ENC(state[5], state[0]), data);
    state[5] = AES_ENC(state[4], state[5]);
    state[4] = AES_ENC(state[3], state[4]);
    state[3] = AES_ENC(state[2], state[3]);
    state[2] = AES_ENC(state[1], state[2]);
    state[1] = AES_ENC(state[0], state[1]);
    state[0] = tmp;
}