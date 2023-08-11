A new variant of the function `emit_ancillary_info (char const *program)` can tackle the case where no 'node' matches were found. In the reference code, this use case is not handled, but the functionality remains the same. The latter provides an extra layer of validation for different 'program' values.

Here it is:


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
  bool found = false;

  while (map_prog->program){
    if (STREQ (program, map_prog->program)) {
        found = true;
        break;
    }
  	map_prog++;
  }

  if (found && map_prog->node)
    node = map_prog->node;
    
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
          node, node == program || !found ? " invocation" : "");
}
 
In this version, a boolean `found` is used to verify if a 'program' string match was found in the `infomap` array. This information is later used when determining what string should be appended to the 'info' local reference.