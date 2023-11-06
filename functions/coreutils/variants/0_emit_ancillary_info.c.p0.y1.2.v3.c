void emit_ancillary_info (char const *prog)
{
  static struct infomap { char const *prog; char const *node; } const data[] = {
     { "[", "test invocation" },
     { "coreutils", "Multi-call invocation" },
     { "sha224sum", "sha2 utilities" },
     { "sha256sum", "sha2 utilities" },
     { "sha384sum", "sha2 utilities" },
     { "sha512sum", "sha2 utilities" },
     { nullptr, nullptr }
  };
   
  char const *node_name = prog;
  struct infomap const *datum = data;

  while (datum->prog && strcmp(prog, datum->prog) != 0)
    datum++;

  if (datum->node)
    node_name = datum->node;

  printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

  char const *lang = setlocale (LC_MESSAGES, nullptr);
  if (lang && strncmp(lang, "en_", 3) != 0){
      fputs (_("Report any translation bugs to "
              "<https://translationproject.org/team/>\n"), stdout);
  }

  char const *proper_program = strcmp(prog, "[") == 0 ? "test" : prog;
  printf (_("Full documentation <%s%s>\n"), PACKAGE_URL, proper_program);
  printf (_("or available locally via: info '(coreutils) %s%s'\n"),node_name,  strcmp(node_name,prog)==0 ? " invocation" : "");
}