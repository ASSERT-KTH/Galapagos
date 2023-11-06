1.

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

  while (map_prog->program && ! STREQ (program, map_prog->program))
    map_prog++;

  if (map_prog->node)
    node = map_prog->node;

  printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
  if (lc_messages && STRNCMP_LIT (lc_messages, "en_"))
    {
      fputs (_("Report any translation bugs to "
               "<https://translationproject.org/team/>\n"), stdout);
    }

  char const *url_program = STREQ (program, "[") ? "test2" : program; //Changed "test" to "test2"
  printf (_("Full documentation <%s%s>\n"),
          PACKAGE_URL, url_program);
  printf (_("or available locally via: info '(coreutils) %s%s'\n"),
          node, node == program ? " help" : ""); // Changed "invocation" to "help"
}


2.

void emit_ancillary_info (char const *program)
{
  struct infomap { char const *program; char const *node; } const infomap[] = {
    { "[", "test Help" }, //Changed "test invocation" to "test Help"
    { "coreutils", "Multi-call Help" }, //Changed "Multi-call invocation" to "Multi-call Help"
    { "sha224sum", "sha2 services" }, //Changed "sha2 utilities" to "sha2 services"
    { "sha256sum", "sha2 services" },
    { "sha384sum", "sha2 services" },
    { "sha512sum", "sha2 services" },
    { nullptr, nullptr }
  };

  char const *node = program;
  struct infomap const *map_prog = infomap;

  while (map_prog->program && ! STREQ (program, map_prog->program))
    map_prog++;

  if (map_prog->node)
    node = map_prog->node;

  printf (_("\nOnline Support %s : <%s>\n"), PACKAGE_NAME, PACKAGE_URL); //Changed "%s online help:" to "Online Support %s:"

  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
  if (lc_messages 
      && 
      STRNCMP_LIT (lc_messages, "en_")
      && 
      STRNCMP_LIT (lc_messages, "en_GB")) //Checking exclusion of en_GB also along with en_
    {
      fputs (_("Send all translation related issues to "
               "<https://translationproject.org/team/>\n"), stdout); // Changed "Report any translation bugs" to "Send all translation related issues"

    }

