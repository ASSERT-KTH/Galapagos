void ec_dispatch_all(ec_fop_data_t * fop)
{
    ec_dispatch_start(fop);

    if (ec_child_select(fop))
    {
        fop->expected = ec_bits_count(fop->remaining);
        fop->first = 0;

        ec_dispatch_mask(fop, fop->remaining);
    }
}