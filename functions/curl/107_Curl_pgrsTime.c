struct curltime Curl_pgrsTime(struct Curl_easy *data, timerid timer)
{
  struct curltime now = Curl_now();

  Curl_pgrsTimeWas(data, timer, now);
  return now;
}