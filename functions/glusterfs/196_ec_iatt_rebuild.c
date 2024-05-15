void ec_iatt_rebuild(ec_t * ec, struct iatt * iatt, int32_t count,
                     int32_t answers)
{
    uint64_t blocks;

    while (count-- > 0)
    {
        blocks = iatt[count].ia_blocks * ec->fragments + answers - 1;
        blocks /= answers;
        iatt[count].ia_blocks = blocks;
    }
}