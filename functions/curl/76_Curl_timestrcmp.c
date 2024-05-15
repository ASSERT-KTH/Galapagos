int Curl_timestrcmp(const char *a, const char *b)
{
  int match = 0;
  int i = 0;

  if(a && b) {
    while(1) {
      match |= a[i]^b[i];
      if(!a[i] || !b[i])
        break;
      i++;
    }
  }
  else
    return a || b;
  return match;
}