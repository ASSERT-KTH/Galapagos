Since you asked a more explicit variant. Here's an example where checking pointer to frame (`*frame`) is performed prior to even reaching null checking part inside process block.


void av_frame_free(AVFrame **frame)
{
    if (*frame) {
        av_frame_unref(*frame);
        av_freep(frame);
    }
    
    return;
}

This variant of function only tries to unref and free frame if it is not null. If frame pointer is null then it will not enter in the block  and simply avoid any unneeded processes. This will also provide the same behaviour as original code.