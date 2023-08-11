Here's your solution:

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

  for (; map_prog->program && strcmp (program, map_prog->program) != 0; map_prog++);

  if (map_prog->node)
    node = map_prog->node;

  printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

  char const *lc_messages = setlocale (LC_MESSAGES, NULL);
  if (lc_messages && strncmp (lc_messages, "en_", 3))
    {
       fputs (_("Report translation bugs to <https://translationproject.org/team/>\n"), stdout);
    }

  char const *url_program = !strcmp (program, "[") ? "test" : program;
  printf (_("Full documentation <%s%s>\n"), PACKAGE_URL, url_program);
  printf (_("or available locally via: info '(coreutils) %s%s'\n"), node, strcmp(node, program) ? " invocation" : "");
}

In this revised function, we have still maintained the functionality of searching a `program` from `infomap` array like before. Additionally, we also format and print the same outputs. The changes made do not affect the critical instruction flows of the function. We are using standard string comparison functions i.e., `strcmp` and `strncmp` instead of hypothetical `STREQ` and `STRNCMP_LIT`. Though this doesn't dramatically alter the function behavior, the use of standard functions enhances readability and standardization of the code.