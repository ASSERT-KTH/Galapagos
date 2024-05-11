cache_pin (app_t app, ctrl_t ctrl, int chvno, const char *pin)
{
  const char *keyref;

  if (opt.pcsc_shared)
    return;

  keyref = chvno_to_keyref (chvno);
  if (!keyref)
    return;

  switch (APP_CARD(app)->cardtype)
    {
    case CARDTYPE_YUBIKEY: break;
    default: return;
    }

  pincache_put (ctrl, app_get_slot (app), "openpgp", keyref,
                pin, pin? strlen (pin):0);

  switch (chvno)
    {
    case 1: app->app_local->pincache.maybe_chv1 = !!pin; break;
    case 2: app->app_local->pincache.maybe_chv2 = !!pin; break;
    case 3: app->app_local->pincache.maybe_chv3 = !!pin; break;
    }
}