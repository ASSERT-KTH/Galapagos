void KRB5_CALLCONV_C com_err(const char *whoami,
                             errcode_t code,
                             const char *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    
	#if DEBUG_LEVEL > 1
	    printf("Debug Message: invoking com_err_va function \n");
	#endif

    com_err_va(whoami, code, fmt, ap);

	#if DEBUG_LEVEL > 1
	    printf("Debug Message: com_err_va function call finished \n");
	#endif

    va_end(ap);
}