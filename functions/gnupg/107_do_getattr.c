do_getattr (app_t app, ctrl_t ctrl, const char *name)
{
  if (!strcmp (name, "$AUTHKEYID"))
    {
      char *buf, *p;
      prkdf_object_t prkdf;

      /* We return the ID of the first private key capable of
         signing. */
      for (prkdf = app->app_local->private_key_info; prkdf;
           prkdf = prkdf->next)
        if (prkdf->usageflags.sign)
          break;
      if (prkdf)
        {
          buf = xtrymalloc (4 + prkdf->objidlen*2 + 1);
          if (!buf)
            return gpg_error_from_syserror ();
          p = stpcpy (buf, "HSM.");
          bin2hex (prkdf->objid, prkdf->objidlen, p);

          send_status_info (ctrl, name, buf, strlen (buf), NULL, 0);
          xfree (buf);
          return 0;
        }
    }
  else if (!strcmp (name, "$DISPSERIALNO"))
    {
      send_status_info (ctrl, name,
                        app->card->serialno, app->card->serialnolen, NULL, 0);
      return 0;
    }

  return gpg_error (GPG_ERR_INV_NAME);
}