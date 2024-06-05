static unsigned int b64_urlsafe_char_to_byte(int c)
{
    const unsigned x =
        ((((((unsigned int) (c) - (unsigned int) ('A')) >> 8) & 0xFF) ^ 0xFF) & (((((unsigned int) ('Z') - (unsigned int) (c)) >> 8) & 0xFF) ^ 0xFF) & (c - 'A')) |
        ((((((unsigned int) (c) - (unsigned int) ('a')) >> 8) & 0xFF) ^ 0xFF) & (((((unsigned int) ('z') - (unsigned int) (c)) >> 8) & 0xFF) ^ 0xFF) & (c - ('a' - 26))) |
        ((((((unsigned int) (c) - (unsigned int) ('0')) >> 8) & 0xFF) ^ 0xFF) & (((((unsigned int) ('9') - (unsigned int) (c)) >> 8) & 0xFF) ^ 0xFF) & (c - ('0' - 52))) | (((((0U - ((unsigned int) (c) ^ (unsigned int) ('-'))) >> 8) & 0xFF) ^ 0xFF) & 62) |
        (((((0U - ((unsigned int) (c) ^ (unsigned int) ('_'))) >> 8) & 0xFF) ^ 0xFF) & 63);

    return x | (((((0U - ((unsigned int) (x) ^ (unsigned int) (0))) >> 8) & 0xFF) ^ 0xFF) & (((((0U - ((unsigned int) (c) ^ (unsigned int) ('A'))) >> 8) & 0xFF) ^ 0xFF) ^ 0xFF));
}