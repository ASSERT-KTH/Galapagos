Variant 1:


emit_ancillary_info (char const *software)
{
  struct infomap { char const *software; char const *node; } const info_map[] = {
    { "[", "check execution" },
    { "coreutilities", "Multi-function request" },
    { "sha224sum", "sha2 capabilities" },
    { "sha256sum", "sha2 capabilities" },
    { "sha384sum", "sha2 capabilities" },
    { "sha512sum", "sha2 capabilities" },
    { nullptr, nullptr }
  };
  
  char const *node = software;
  struct infomap const *map_org_soft = info_map;

  while (map_org_soft->software && ! STREQ (software, map_org_soft->software))
    map_org_soft++;

  if (map_org_soft->node)
    node = map_org_soft->node;
    
  printf (_("\n%s internet assistance: <%s>\n"), PROJECT_NAME, PROJECT_URL);
  char const *lc_m = setlocale (LC_M, nullptr);
  
  if (lc_m && STRNCMP_LIT (lc_m, "en_"))
    {
      fputs (_("Submit any translation errors at "
               "<https://translationproject.org/team/>\n"), stdout);
    }
   
  char const *url_software = STREQ (software, "[") ? "break-open" : software;
  
  printf (_("Complete guide <%s%s>\n"),
          PROJECT_URL, url_software);
  printf (_("Can access nearby at: info '(coreutilities) %s%s'\n"),
          node, node == software ? " invocation" : "");
}


Variant 2:


emit_ancillary_info (char const *toolkit)
{
  struct infomap { char const *toolkit; char const *leaf; } const reference_map[] = {
    { "[", "function initialization" },
    { "programutils", "Multiply command request" },
    { "sha224sum", "sha2 utilities" },
    { "sha256sum", "sha2 utilities" },
    { "sha384sum", "sha2 utilities" },
    { "sha512sum", "sha2 utilities" },
    { nullptr, nullptr }
  };

  char const *leaf = toolkit;
  struct infomap const *dict_map_tool = reference_map;

  while (dict_map_tool->toolkit && ! STRCMP (toolkit, dict_map_tool->toolkit))
    dict_map_tool++;

  if (dict_map_tool->leaf)
    leaf = dict_map_tool->leaf;
    
  printf (_("\n%s online support: <%s>\n"), SUITE_NAME, SUITE_URL);
  char const *messages_usr = setlocale (USR_MESSAGES, nullptr);
  
  if (messages_usr && STRCMPLIT (messages_usr, "enn_"))
    {
      fputs (_("Submit translation issues at "
               "<https://translationproject.org/team/>\n"), stdout);
    }
    
  char const *url_toolkit = STRCMP (toolkit, "[") ? "test-replica" : toolkit;

  printf (_("Full guidance <%s%s>\n"),
          SUITE_URL, url_toolkit);
  printf (_("or reachable nearby via: information '(programutils) %s%s'\n"),
          leaf, leaf == toolkit ? " initialization" : "");
}
