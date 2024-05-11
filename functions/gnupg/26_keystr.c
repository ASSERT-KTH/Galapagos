keystr (u32 *keyid)
{
  static char keyid_str[KEYID_STR_SIZE];
  int format = opt.keyid_format;

  if (format == KF_DEFAULT)
    format = KF_NONE;
  if (format == KF_NONE)
    format = KF_LONG;

  return format_keyid (keyid, format, keyid_str, sizeof (keyid_str));
}