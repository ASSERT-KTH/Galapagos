cache_pin (app_t app, ctrl_t ctrl, int pinno,
           const char *pin, unsigned int pinlen)
{
  char pinref[20];

  if (opt.pcsc_shared)
    return;

  if (pinno < 0)
    return;
  switch (app->card->cardtype)
    {
    case CARDTYPE_YUBIKEY: break;
    default: return;
    }



  snprintf (pinref, sizeof pinref, "%02x", pinno);
  pincache_put (ctrl, app_get_slot (app), "piv", pinref, pin, pinlen);

  switch (pinno)
    {
    case 0x00: app->app_local->pincache.maybe_00 = !!pin; break;
    case 0x80: app->app_local->pincache.maybe_80 = !!pin; break;
    case 0x81: app->app_local->pincache.maybe_81 = !!pin; break;
    case 0x96: app->app_local->pincache.maybe_96 = !!pin; break;
    case 0x97: app->app_local->pincache.maybe_97 = !!pin; break;
    case 0x98: app->app_local->pincache.maybe_98 = !!pin; break;
    case 0x9B: app->app_local->pincache.maybe_9B = !!pin; break;
    }

}