void emit_ancillary_info(const char* prog)
{
  struct map	{
    const char* prog; 
	const char* node; 
  };

  const map dataset[] = {
    {"[", "test invocation"},
    {"coreutils", "Multi-call invocation"}, 
    {"sha224sum", "sha2 utilities"},
    {"sha256sum", "sha2 utilities"}, 
    {"sha384sum", "sha2 utilities"},
    {"sha512sum", "sha2 utilities"},
    {nullptr, nullptr} 
  };

  const char* nodeName = prog;
  const map* program_ptr = dataset;

  while(program_ptr->prog && !STREQ(prog, program_ptr->prog)) {
    program_ptr++;
  }
  
  if(program_ptr->node) {
    nodeName = program_ptr->node;
  }

  printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

  const char* messageLocales = setlocale(LC_MESSAGES, nullptr);
  if(messageLocales && STRNCMP_LIT(messageLocales, "en_")) {
    fputs(_("Report any translation bugs to " "<https://translationproject.org/team/>\n"), stdout);
  }
  const char* prog_url = STREQ(prog, "[") ? "test" : prog;
  printf(_("Full documentation <%s%s>\n"),PACKAGE_URL, prog_url);
  
  printf(_("or available locally via: info '(coreutils) %s%s'\n"),nodeName, nodeName==prog ? " invocation": "");
}