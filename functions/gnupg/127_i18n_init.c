i18n_init (void)
{
#ifdef USE_SIMPLE_GETTEXT
  bindtextdomain (PACKAGE_GT, gnupg_localedir ());
  textdomain (PACKAGE_GT);
#else
# ifdef ENABLE_NLS
  setlocale (LC_ALL, "" );
  bindtextdomain (PACKAGE_GT, gnupg_localedir ());
  textdomain (PACKAGE_GT);
# endif
#endif
}