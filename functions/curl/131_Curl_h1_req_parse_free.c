void Curl_h1_req_parse_free(struct h1_req_parser *parser)
{
  if(parser) {
    Curl_http_req_free(parser->req);
    Curl_dyn_free(&parser->scratch);
    parser->req = NULL;
    parser->done = FALSE;
  }
}