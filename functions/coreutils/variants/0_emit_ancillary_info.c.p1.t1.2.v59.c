The following C code variant adds an additional functionality to make a case-independent comparison between the "program" variable and the "program" property of the "infomap" struct. The strcasecmp function is used for this purpose.


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

  while (map_prog->program && strcasecmp (program, map_prog->program))
    map_prog++;

  if (map_prog->node)
    node = map_prog->node;

  printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
  if (lc_messages && STRNCMP_LIT (lc_messages, "en_")) {
    fputs (_("Report any translation bugs to "
             "<https://translationproject.org/team/>\n"), stdout);
  }
  
  char const *url_program = STREQ (program, "[") ? "test" : program;
  
  printf (_("Full documentation <%s%s>\n"), PACKAGE_URL, url_program);
  printf (_("or available locally via: info '(coreutils) %s%s'\n"), node, node == program ? " invocation" : "");
}


By using strcasecmp instead of STRCMP, the comparison will be case-independent. This change makes the function accept input irrespective of the case of the characters in the "program" variable. So, "SHA224SUM", "Sha224Sum", "sha224sum" will all be considered as equal. This modification expands the versatility of the original functionality to be case-insensitive.