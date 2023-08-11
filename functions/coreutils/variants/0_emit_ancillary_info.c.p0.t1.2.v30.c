Variant 1: Alternative approach to iterate in the `infomap` array


void emit_ancillary_info (char const *program)
{
  struct infomap 
  { 
    char const *program; 
    char const *node; 
  } const infomap[] = 
  { 
    { "[", "test invocation" }, 
    { "coreutils", "Multi-call invocation" }, 
    { "sha224sum", "sha2 utilities" }, 
    { "sha256sum", "sha2 utilities" }, 
    { "sha384sum", "sha2 utilities" }, 
    { "sha512sum", "sha2 utilities" },
    { nullptr, nullptr } 
  };

  char const *node = program;

  for (int i = 0; infomap[i].program != nullptr && ! STREQ (program, infomap[i].program); ++i)
  {
      if (STREQ (program, infomap[i].program)) 
      {
          node = infomap[i].node;
          break;
      }
      else
          continue;
  }

  printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);

  if (lc_messages && STRNCMP_LIT (lc_messages, "en_"))
  {
    fputs (_("Report any translation bugs to "
             "<https://translationproject.org/team/>\n"), stdout);
  }
  
  char const *url_program = STREQ (program, "[") ? "test" : program;
  
  printf (_("Full documentation <%s%s>\n"), 
          PACKAGE_URL, url_program);
  printf (_("or available locally via: info '(coreutils) %s%s'\n"), 
          node, node == program ? " invocation" : "");
}


Variant 2: Do not output the translation errors message for all non-English locales (only do so for 'C' locale)


void emit_ancillary_info (char const *program)
{
  struct infomap 
  { 
    char const *program; 
    char const *node; 
  } const infomap[] = 
  { 
      { "[", "test invocation" }, 
      { "coreutils", "Multi-call invocation" }, 
      { "sha224sum", "sha2 utilities" }, 
      { "sha256sum", "sha2 utilities" }, 
      { "sha384sum", "sha2 utilities" }, 
      { "sha512sum", "sha2 utilities" },
      { nullptr, nullptr } 
  };

  char const *node = program;
  struct infomap const *map_prog = infomap;

  while (map_prog->program && ! STREQ (program, map_prog->program))
    map_prog++;

  if (map_prog->node)
    node = map_prog->node;

  printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);

  if (lc_messages && STREQ (lc_messages, "C"))
  {
      fputs (_("Report any translation bugs to "
               "<https://translationproject.org/team/>\n"), stdout);
  }

  char const *url_program = STREQ (program, "[") ? "test" : program;
  
  printf (_("Full documentation <%s%s>\n"),
          PACKAGE_URL, url_program);
  printf (_("or available locally via: info '(coreutils) %s%s'\n"),
          node, node == program ? " invocation" : "");
}


Each of these variants performs a similar functionality to the original function, but there are minor changes in their logic.