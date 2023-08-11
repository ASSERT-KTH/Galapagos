The requirement is a bit trickier as retaining 100% ideal replacement of the function with introduced change seems almost redundant as we only could introduce different small optimizations and modify ways of accessing data etc. Best try is:


emit_ancillary_info (char const *program)
{
  static const struct { 
    char const *program; 
    char const *node; 
  } infomap[] = {
    { "[", "test invocation" },
    { "coreutils", "Multi-call invocation" },
    { "sha224sum", "sha2 utilities" },
    { "sha256sum", "sha2 utilities" },
    { "sha384sum", "sha2 utilities" },
    { "sha512sum", "sha2 utilities" },
    { nullptr, nullptr }
  }; 

  char const *node = program;
  size_t i;

  for (i = 0; infomap[i].program && !STREQ (program, infomap[i].program); i++);
  if (infomap[i].node)
    node = infomap[i].node;

  printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

  if (char const *lc_messages = setlocale (LC_MESSAGES, nullptr); lc_messages && STRNCMP_LIT (lc_messages, "en_"))
  {
    fputs (_("Report translation bugs to "
             "<https://translationproject.org/team/>\n"), stdout);
  }

  char const *url_program = STREQ (program, "[") ? "test" : program;
  printf (_("Full documentation <%s%s>\n"), PACKAGE_URL, url_program);
  printf (_("or available locally via: info '(coreutils) %s%s'\n"), node, node == program ? " invocation" : "");
}


The changes are:
- Using a `for` loop instead of a `while` loop to simplify and optimize code.
- Placing the setlocale function inside if conditional to limit its scope and make sure it gets initialized only when it is used.
- Made static the `infomap` array to not reinitialized at each function call.