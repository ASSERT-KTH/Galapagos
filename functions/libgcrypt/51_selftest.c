selftest(void)
{
  BLOWFISH_context c;
  cipher_bulk_ops_t bulk_ops;
  byte plain[] = "BLOWFISH";
  byte buffer[8];
  static const byte plain3[] =
    { 0xFE, 0xDC, 0xBA, 0x98, 0x76, 0x54, 0x32, 0x10 };
  static const byte key3[] =
    { 0x41, 0x79, 0x6E, 0xA0, 0x52, 0x61, 0x6E, 0xE4 };
  static const byte cipher3[] =
    { 0xE1, 0x13, 0xF4, 0x10, 0x2C, 0xFC, 0xCE, 0x43 };

  bf_setkey( (void *) &c,
             (const unsigned char*)"abcdefghijklmnopqrstuvwxyz", 26,
             &bulk_ops );
  encrypt_block( (void *) &c, buffer, plain );
  if( memcmp( buffer, "\x32\x4E\xD0\xFE\xF4\x13\xA2\x03", 8 ) )
    return "Blowfish selftest failed (1).";
  decrypt_block( (void *) &c, buffer, buffer );
  if( memcmp( buffer, plain, 8 ) )
    return "Blowfish selftest failed (2).";

  bf_setkey( (void *) &c, key3, 8, &bulk_ops );
  encrypt_block( (void *) &c, buffer, plain3 );
  if( memcmp( buffer, cipher3, 8 ) )
    return "Blowfish selftest failed (3).";
  decrypt_block( (void *) &c, buffer, buffer );
  if( memcmp( buffer, plain3, 8 ) )
    return "Blowfish selftest failed (4).";

  return NULL;
}