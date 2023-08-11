You can adjust the variable mapping array `infomap[]` where you add more data or change existing one, or introduce conditional statements, breaking the `while` loop early for certain programs. Please ensure that changes abide your exact requirements.

Below is an example of slightly variant version:


void emit_ancillary_info (char const *program)
{
  struct infomap { char const *program; char const *node; } const infomap[] = {
    { "[", "chosen test invocation" },           // changed the value of presenting node
    { "coreutils", "Alternative Multi-call invocation" }, // edited the data presented for 'coreutils'
    { "sha224sum", "sha2 utilities" },
    { "sha256sum", "sha2 utilities" },
    { "sha384sum", "sha2 utilities" },
    { "special125", "conditional special util" },  // included a new entry 'special125'
    { "sha512sum", "sha2 utilities" },
    { nullptr, nullptr }
  };

  char const *node = program;
  struct infomap const *map_prog = infomap;

  while (map_prog->program && ! STREQ (program, map_prog->program)) {
    if(STREQ (program, "special125")) // early break when program input is 'special125'
      break;
    map_prog++;
  }

  if (map_prog->node)
    node = map_prog->node;

  printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL); 

  char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
  if (lc_messages && STRNCMP_LIT (lc_messages, "en_"))
    {
      fputs (_("Report any translation bugs to "
               "<https://translationproject.org/team/>\n"), stdout);
    }

  char const *url_program = STREQ (program, "[") ? "our special test" : program; // changed formatting for '[' case
  
  printf (_("Full documentation <%s%s>\n"),
          PACKAGE_URL, url_program);
  printf (_("or available locally via: info '(coreutils) %s%s'\n"),
          node, node == program ? " extended invocation" : ""); // added "extended" in format
}

The above code spends little time to locate 'special125' and presents customized formatting for the '[' condition.