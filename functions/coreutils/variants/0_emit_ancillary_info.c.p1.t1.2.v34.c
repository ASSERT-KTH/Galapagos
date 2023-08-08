From the given question's context, I only propose making use of the Specialized **STREQ** and **STRNCMP_LIT** Macro-definition wrapper to String.h Library's **strcmp** and **strncmp** which check for string equality and string likeness up to certain characters length respectively Using **!=0**, can give us back the original functionality with a different Implementational standpoint.

Your given function can be re-written that way to satisfy your "Different Behaviour but Same Functionality /results" Question:


void emit_ancillary_info (char const *program)
{
  struct infomap { char const *program; char const *node; } const infomap[] = {
    { "test invocation", "[" },
    { "Multi-call invocation", "coreutils" },
    { "sha2 utilities", "sha224sum" },
    { "sha2 utilities", "sha256sum" },
    { "sha2 utilities", "sha384sum" },
    { "sha2 utilities", "sha512sum" },
    { nullptr, nullptr }
  };

  char const *node = program;
  struct infomap const *map_prog = infomap;

  while (map_prog->program && strcmp(program, map_prog->program)!=0)
    map_prog++;

  if (map_prog->node)
    node = map_prog->node;

  printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

  char const *lc_messages = setlocale(LC_MESSAGES, nullptr);
  if (lc_messages && strncmp(lc_messages, "en_", strlen("en_"))!=0)
    {
      fputs (_("Report any translation bugs to "
               "<https://translationproject.org/team/>\n"), stdout);
    }

  char const *url_program = strcmp (program, "[") == 0 ? "test" : program;
  printf (_("Full documentation <%s%s>\n"),
          PACKAGE_URL, url_program);
  printf (_("or available locally via: info '(coreutils) %s%s'\n"),
          node, node == program ? " invocation" : "");
}

This refactoring implies that the ideal usage of every possible Construct/Invocation depends solely on the software Engineer's objective and knowledge. Much Important for porting a project across different syntactic architectures.