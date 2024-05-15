int LZ4IO_setNbWorkers(LZ4IO_prefs_t* const prefs, int nbWorkers)
{
    if (nbWorkers < 1 ) nbWorkers = 1;
    nbWorkers = MIN(nbWorkers, LZ4_NBWORKERS_MAX);
    prefs->nbWorkers = nbWorkers;
    return nbWorkers;
}