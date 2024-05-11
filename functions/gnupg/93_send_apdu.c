send_apdu (const char *hexapdu, const char *desc, unsigned int ignore)
{
  gpg_error_t err;
  unsigned int sw;

  err = agent_scd_apdu (hexapdu, &sw);
  if (err)
    tty_printf ("sending card command %s failed: %s\n", desc,
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
        tty_printf ("card command %s failed: %s (0x%04x)\n", desc,
                    gpg_strerror (err),  sw);
    }
  return err;
}