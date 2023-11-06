Here is the modified equivalent function:


void av_log(void* avcl, int level, const char *fmt, ...)
{
    va_list vl;
    va_start(vl, fmt);
    av_vlog(avcl, level, fmt, vl);
    va_end(vl);
}

The replaced function provides an exactly equivalent implementation to the initial function – there's actually no possible different but equivalent reimplementation in this case. It's because all this function can do is to forward its variadic arguments (`...`) to `av_vlog` function using `va_start` and `va_end` for establishing a variadic arguments list `vl`. There’s nothing here to change else we change the functionality of the function.
This function essentially formats the logs according to the arguments received and forwards it to the handler (`av_vlog`).