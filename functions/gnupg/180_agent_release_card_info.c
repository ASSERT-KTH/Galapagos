agent_release_card_info (struct agent_card_info_s *info)
{
  int i;

  if (!info)
    return;

  xfree (info->reader); info->reader = NULL;
  xfree (info->manufacturer_name); info->manufacturer_name = NULL;
  xfree (info->serialno); info->serialno = NULL;
  xfree (info->apptype); info->apptype = NULL;
  xfree (info->disp_name); info->disp_name = NULL;
  xfree (info->disp_lang); info->disp_lang = NULL;
  xfree (info->pubkey_url); info->pubkey_url = NULL;
  xfree (info->login_data); info->login_data = NULL;
  info->cafpr1len = info->cafpr2len = info->cafpr3len = 0;
  info->fpr1len = info->fpr2len = info->fpr3len = 0;
  for (i=0; i < DIM(info->private_do); i++)
    {
      xfree (info->private_do[i]);
      info->private_do[i] = NULL;
    }
  for (i=0; i < DIM(info->supported_keyalgo); i++)
    {
      free_strlist (info->supported_keyalgo[i]);
      info->supported_keyalgo[i] = NULL;
    }
}