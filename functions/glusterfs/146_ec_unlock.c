void ec_unlock(ec_fop_data_t *fop)
{
    int32_t i;

    for (i = 0; i < fop->lock_count; i++) {
        ec_unlock_timer_add(&fop->locks[i]);
    }
}