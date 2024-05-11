gnupg_compliance_option_string (enum gnupg_compliance_mode compliance)
{
  switch (compliance)
    {
    case CO_GNUPG:   return "--compliance=gnupg";
    case CO_RFC4880: return "--compliance=openpgp";
    case CO_RFC2440: return "--compliance=rfc2440";
    case CO_PGP7:    return "--compliance=pgp7";
    case CO_PGP8:    return "--compliance=pgp8";
    case CO_DE_VS:   return "--compliance=de-vs";
    }

  log_assert (!"invalid compliance mode");
}