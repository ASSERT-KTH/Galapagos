send_apdu (const char *hexapdu, const char *desc, unsigned int ignore,
           unsigned char **r_data, size_t *r_datalen)
{
  gpg_error_t err;
  unsigned int sw;

  err = scd_apdu (hexapdu, NULL, &sw, r_data, r_datalen);
  if (err)
    log_error ("sending card command %s failed: %s\n", desc,
               gpg_strerror (err));
  else if (!hexapdu
           || !strcmp (hexapdu, "undefined")
           || !strcmp (hexapdu, "reset-keep-lock")
           || !strcmp (hexapdu, "lock")
           || !strcmp (hexapdu, "trylock")
           || !strcmp (hexapdu, "unlock"))
    ; /* Ignore pseudo APDUs.  */
  else if (ignore == 0xffff)
    ; /* Ignore all status words.  */
  else if (sw != 0x9000)
    {
      switch (sw)
        {
        case 0x6285: err = gpg_error (GPG_ERR_OBJ_TERM_STATE); break;
        case 0x6982: err = gpg_error (GPG_ERR_BAD_PIN); break;
        case 0x6985: err = gpg_error (GPG_ERR_USE_CONDITIONS); break;
        default: err = gpg_error (GPG_ERR_CARD);
        }
      if (!(ignore && ignore == sw))
        log_error ("card command %s failed: %s (0x%04x)\n", desc,
                   gpg_strerror (err),  sw);
    }
  return err;
}