void emit_ancillary_info (char const *software_name)
{
  const struct infomap { const char *software_name; const char *node_name; } compInfomap[] = {
    { "[", "test invocation" },
    { "coreutils", "Multi-call invocation" },
    { "sha224sum", "sha2 utilities" },
    { "sha256sum", "sha2 utilities" },
    { "sha384sum", "sha2 utilities" },
    { "sha512sum", "sha2 utilities" },
    { nullptr, nullptr }
  };

  const char *nord = software_name;
  const struct infomap *map_cp = compInfomap;

  while (map_cp->software_name && ! STREQ (software_name, map_cp->software_name))
    map_cp++;

  if (map_cp->node_name)
    nord = map_cp->node_name;
  
  printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

  const char *lc_information = setlocale (LC_MESSAGES, nullptr);
  if (lc_information && STRNCMP_LIT (lc_information, "en_"))
    { 
      fputs (_("Report any translation bugs to "
               "<https://translationproject.org/team/>\n"), stdout);
    }
  
  const char *url_software_name = STREQ (software_name, "[") ? "test" : software_name;
  printf (_("Full documentation <%s%s>\n"),
          PACKAGE_URL, url_software_name);
  printf (_("or available locally via: info '(coreutils) %s%s'\n"),
          nord, nord == software_name ? " invocation" : "");
}