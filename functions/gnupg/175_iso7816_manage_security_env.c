iso7816_manage_security_env (int slot, int p1, int p2,
                             const unsigned char *data, size_t datalen)
{
  int sw;

  if (p1 < 0 || p1 > 255 || p2 < 0 || p2 > 255 )
    return gpg_error (GPG_ERR_INV_VALUE);

  sw = apdu_send_simple (slot, 0, 0x00, CMD_MSE, p1, p2,
                         data? datalen : -1, (const char*)data);
  return map_sw (sw);
}