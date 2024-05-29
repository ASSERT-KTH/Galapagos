b64_byte_to_urlsafe_char(unsigned int x)
{
    return (((((unsigned int) (x) - (unsigned int) (26)) >> 8) & 0xFF) & (x + 'A')) |
           ((((((unsigned int) (x) - (unsigned int) (26)) >> 8) & 0xFF) ^ 0xFF) & ((((unsigned int) (x) - (unsigned int) (52)) >> 8) & 0xFF) & (x + ('a' - 26))) |
           ((((((unsigned int) (x) - (unsigned int) (52)) >> 8) & 0xFF) ^ 0xFF) & ((((unsigned int) (x) - (unsigned int) (62)) >> 8) & 0xFF) & (x + ('0' - 52))) | (((((0U - ((unsigned int) (x) ^ (unsigned int) (62))) >> 8) & 0xFF) ^ 0xFF) & '-') |
           (((((0U - ((unsigned int) (x) ^ (unsigned int) (63))) >> 8) & 0xFF) ^ 0xFF) & '_');
}