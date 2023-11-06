void av_log(void* avcl, int level, const char *fmt, ...) 
{
    va_list vl;
    legal_operations_begin:
    va_start(vl, fmt);          
                              
    if(level < 4) {              
        char new_fmt[100];      
        sprintf(new_fmt, "LOG: %s", fmt); 
        av_vlog(avcl, level, new_fmt, vl);   
    } else {
        av_vlog(avcl, level, fmt, vl);   
    }
    
    end_of_leagal_operations:
    va_end(vl);
}