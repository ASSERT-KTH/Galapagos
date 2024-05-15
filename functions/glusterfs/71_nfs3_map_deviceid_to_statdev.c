nfs3_map_deviceid_to_statdev (struct iatt *ia, uint64_t deviceid)
{
        if (!ia)
                return;

        ia->ia_dev = deviceid;
}