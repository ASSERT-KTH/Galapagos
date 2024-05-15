static void process_pending_handles(struct Curl_multi *multi)
{
  struct Curl_llist_element *e = multi->pending.head;
  if(e) {
    struct Curl_easy *data = e->ptr;
    move_pending_to_connect(multi, data);
  }
}