modp_R2(uint32_t p, uint32_t p0i) {
    uint32_t z;

    /*
     * Compute z = 2^31 mod p (this is the value 1 in Montgomery
     * representation), then double it with an addition.
     */
    z = modp_R(p);
    z = modp_add(z, z, p);

    /*
     * Square it five times to obtain 2^32 in Montgomery representation
     * (i.e. 2^63 mod p).
     */
    z = modp_montymul(z, z, p, p0i);
    z = modp_montymul(z, z, p, p0i);
    z = modp_montymul(z, z, p, p0i);
    z = modp_montymul(z, z, p, p0i);
    z = modp_montymul(z, z, p, p0i);

    /*
     * Halve the value mod p to get 2^62.
     */
    z = (z + (p & -(z & 1))) >> 1;
    return z;
}