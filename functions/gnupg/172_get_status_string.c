get_status_string ( int no )
{
  int idx = statusstr_msgidxof (no);
  if (idx == -1)
    return "?";
  else
    return statusstr_msgstr + statusstr_msgidx[idx];
}