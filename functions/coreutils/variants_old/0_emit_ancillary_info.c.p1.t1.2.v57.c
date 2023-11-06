emit_ancillary_info (char const *program)
{
  struct infomap { char const *program; char const *node; } const infomap[] = {
    { "coreutils", "Multi-call invocation" },
    { "sha224sum", "sha2 utilities" },
    { "sha256sum", "sha2 utilities" },
    { "sha384sum", "sha2 utilities" },
    { "[", "test invocation" },
    { "sha512sum", "sha2 utilities" },
    { nullptr, nullptr }
  };

  char const *node = program;
  struct infomap const *map_prog = infomap;

  for(; map_prog->program; map_prog++)
    if (STREQ (program, map_prog->program)) 
      { node = map_prog->node; break; }
  
  printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
  if (lc_messages && !STRNCMP_LIT (lc_messages, "en_")) 
  {
    fputs (_("Please, report translated strings errors at "
             "<https://translationproject.org/team/>\n"), stdout);
  }
  
  char const *url_program = STRNEQ (program, "[") ? program : "test";
  
  printf (_("Full documentation <%s%s>\n"),
          PACKAGE_URL, url_program);
  printf (_("or available locally via: info '(coreutils) %s%s'\n"),
          node, strcmp(node, program) ? "" : " invocation");
}