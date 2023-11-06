Function Transformation 1: Changing the condition and loop scope for mapping a proper Program-node association.

void emit_ancillary_info (char const *program)
{
  struct infomap { char const *program; char const *node; } const infomap[] = {
    { "[", "test invocation" },
    { "coreutils", "Multi-call invocation" },
    { "sha224sum", "sha2 utilities" },
    { "sha256sum", "sha2 utilities" },
    { "sha384sum", "sha2 utilities" },
    { "sha512sum", "sha2 utilities" },
    { nullptr, nullptr }
  };

  char const *node = nullptr;
  struct infomap const *map_prog = infomap;

  while (map_prog->node)
  {
    if (! STREQ (program, map_prog->program))
      map_prog++;
    else
    {
      node = map_prog->node;
      break;
    }
  }

  printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

  //... rest of function ...
}

Function Transformation 2: Inverting the condition to remove the bug reporting message for other locales besides English ones.


void emit_ancillary_info (char const *program)
{
  struct infomap { char const *program; char const *node; } const infomap[] = {
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

  // ... rest of function ...

  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
  if (lc_messages && ! STRNCMP_LIT (lc_messages, "en_"))
  { /* No action */}
  else
  {
  	fputs (_("Report any translation bugs to "
                 "<https://translationproject.org/team/>\n"), stdout);
  }

  //... rest of function ...
}
