static unsigned int _booth_recode_w7(unsigned int in)
{
    unsigned int s, d;

    s = ~((in >> 7) - 1);
    d = (1 << 8) - in - 1;
    d = (d & s) | (in & ~s);
    d = (d >> 1) + (d & 1);

    return (d << 1) + (s & 1);
}