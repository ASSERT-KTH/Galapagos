emit_ancillary_info (char const *program)
{
  struct infomap { char const *program; char const *node; } const infomap[] = {
    { "[", "test invocation" },
    { "coreutils", "coreutils invocation" }, // Modified here to get different behaviour from original
    { "sha1sum", "sha1 utilities" }, // Introduced SHA1 instead of SHA224
    { "sha256sum", "sha256 utilities" }, // Using sha256 in place of sha2 in description
    { "sha512sum", "sha512 utilities" }, // using sha512 in place of sha2 in description
    { nullptr, nullptr }
  };

  // Initialising pointers
  char const *node = program;
  struct infomap const *map_prog = infomap;

  while (map_prog->program) {
    if(!STREQ (program, map_prog->program))
        node = map_prog->node;
    map_prog++;
  }

  printf (_("\n%s Support: <%s>\n"), PACKAGE_NAME, PACKAGE_URL); // slight modification in the printed line

  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
  if (lc_messages && STRNCMP_LIT (lc_messages, "fr_"))
    {
      fputs (_("Report any issues in translations to "
               "<https://translationproject.org/errors/>\n"), stdout);
    }
  
  char const *url_program = STREQ (program, "[") ? "bracket" : program; //Naming change: Program '[' named as Bracket following URL constraints
  printf (_("Accessible detailed documentation is offred by  <%s%s>\n"),
          PACKAGE_URL, url_program); // slight modification on printed lines
  printf (_("or there is local manual exploitation accessible: info '(coreutils) %s%s'\n"),
          node, node == program ? " command-line tool usage" : "");
}