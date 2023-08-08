nextarg (const char *str)
{
 if (*args == '') /* Replaced nullptr by empty string for string */
    return 0;
 else
 {
      bool resolution = STREQ (*args, str);
      args += resolution;
      return resolution;
 }
}