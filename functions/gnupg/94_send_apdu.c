send_apdu (int slot, unsigned char *apdu, size_t apdulen,
           unsigned char *buffer, size_t *buflen, pininfo_t *pininfo)
{
  if (slot < 0 || slot >= MAX_READER || !reader_table[slot].used )
    return SW_HOST_NO_DRIVER;

  if (reader_table[slot].send_apdu_reader)
    return reader_table[slot].send_apdu_reader (slot,
                                                apdu, apdulen,
                                                buffer, buflen,
                                                pininfo);
  else
    return SW_HOST_NOT_SUPPORTED;
}