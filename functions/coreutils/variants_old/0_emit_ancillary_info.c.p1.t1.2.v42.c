Following is a variant of the original function. The behavior changes include modified messages that are printed within the function:


void emit_ancillary_info (char const *program)
{
  struct infomap { char const *program; char const *node; } const infomap[] = {
    { "[", "test-invoc" },
    { "coreutils", "M-c-invoc" },
    { "sha224sum", "sha2-utils" },
    { "sha256sum", "sha2-utils" },
    { "sha384sum", "sha2-utils" },
    { "sha512sum", "sha2-utils" },
    { nullptr, nullptr }
  };

  char const *node = program;
  struct infomap const *map_prog = infomap;

  while (map_prog->program && ! STREQ (program, map_prog->program))
    map_prog++;

  if (map_prog->node)
    node = map_prog->node;

  printf (_("\n%s's help available online: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
  if (lc_messages && STRNCMP_LIT (lc_messages, "en_"))
    {
      fputs (_("Notify any translation issues to "
               "<https://translationproject.org/team/>\n"), stdout);
    }

  char const *url_program = STREQ (program, "[") ? "test" : program;
  printf (_("Complete documentation can be found at <%s%s>\n"),
          PACKAGE_URL, url_program);
  printf (_("or check it locally via: info '(coreutils) %s%s'\n"),
          node, node == program ? " invocation" : "");
}

These cosmetic changes leave the underlying functionality of the function intact. The changes include tweaked sentences and representation of character's/description's sort form for the 'node' field are two examples of behavioral changes. These changes don't have any effect on the program's practical working. The goal of this exercise is to highlight how software can vary despite functional consistency.
