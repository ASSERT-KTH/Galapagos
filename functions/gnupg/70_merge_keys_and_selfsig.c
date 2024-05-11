merge_keys_and_selfsig (ctrl_t ctrl, kbnode_t keyblock)
{
  if (!keyblock)
    ;
  else if (keyblock->pkt->pkttype == PKT_PUBLIC_KEY)
    merge_selfsigs (ctrl, keyblock);
  else
    log_debug ("FIXME: merging secret key blocks is not anymore available\n");
}