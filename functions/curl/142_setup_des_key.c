static void setup_des_key(const unsigned char *key_56,
                          struct des_ctx *des)
{
  char key[8];

  /* Expand the 56-bit key to 64-bits */
  extend_key_56_to_64(key_56, key);

  /* Set the key parity to odd */
  Curl_des_set_odd_parity((unsigned char *) key, sizeof(key));

  /* Set the key */
  des_set_key(des, (const uint8_t *) key);
}