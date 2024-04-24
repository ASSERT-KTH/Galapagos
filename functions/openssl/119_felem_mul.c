static void felem_mul(longfelem out, const felem in1, const felem in2)
{
    smallfelem small1, small2;
    felem_shrink(small1, in1);
    felem_shrink(small2, in2);
    smallfelem_mul(out, small1, small2);
}