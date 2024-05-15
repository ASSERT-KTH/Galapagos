static void time2str(char *r, curl_off_t seconds)
{
  curl_off_t h;
  if(seconds <= 0) {
    strcpy(r, "--:--:--");
    return;
  }
  h = seconds / CURL_OFF_T_C(3600);
  if(h <= CURL_OFF_T_C(99)) {
    curl_off_t m = (seconds - (h*CURL_OFF_T_C(3600))) / CURL_OFF_T_C(60);
    curl_off_t s = (seconds - (h*CURL_OFF_T_C(3600))) - (m*CURL_OFF_T_C(60));
    msnprintf(r, 9, "%2" CURL_FORMAT_CURL_OFF_T ":%02" CURL_FORMAT_CURL_OFF_T
              ":%02" CURL_FORMAT_CURL_OFF_T, h, m, s);
  }
  else {
    /* this equals to more than 99 hours, switch to a more suitable output
       format to fit within the limits. */
    curl_off_t d = seconds / CURL_OFF_T_C(86400);
    h = (seconds - (d*CURL_OFF_T_C(86400))) / CURL_OFF_T_C(3600);
    if(d <= CURL_OFF_T_C(999))
      msnprintf(r, 9, "%3" CURL_FORMAT_CURL_OFF_T
                "d %02" CURL_FORMAT_CURL_OFF_T "h", d, h);
    else
      msnprintf(r, 9, "%7" CURL_FORMAT_CURL_OFF_T "d", d);
  }
}