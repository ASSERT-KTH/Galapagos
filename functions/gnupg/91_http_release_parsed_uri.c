http_release_parsed_uri (parsed_uri_t uri)
{
  if (uri)
    {
      uri_tuple_t r, r2;

      for (r = uri->params; r; r = r2)
	{
	  r2 = r->next;
	  xfree (r);
	}
      for (r = uri->query; r; r = r2)
	{
	  r2 = r->next;
	  xfree (r);
	}
      xfree (uri);
    }
}