hexstr (const byte *bytes)
{
  static int i;
  static char bufs[100][7];

  i ++;
  if (i == 100)
    i = 0;

  sprintf (bufs[i], "0x%02X%02X", bytes[0], bytes[1]);
  return bufs[i];
}