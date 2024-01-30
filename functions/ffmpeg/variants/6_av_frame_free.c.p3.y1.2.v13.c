Unfortunately, this conversion from C to Go isn't possible because Go doesn't have an equivalent for the av_frame_free, av_frame_unref, and av_freep functions which are part of FFmpeg, a collection of libraries to handle multimedia data. 

The conversion from pointers and the use of if conditions, isn't a problem, but we do not have direct access to the data structures and libraries required by the FFmpeg in Go. In particular, we do not have a direct equivalent in Go for `AVFrame` and functions `av_frame_free()`, `av_frame_unref()` and `av_freep()`.

To work with FFmpeg libraries in Go, you have to use cgo to call C code directly. Essentially, the solution would still involve C code.

Go is a statically-typed, compiled programming language while FFmpeg is written in C, a tried-and-true language that has been around for decades. Although it is possible to use Go for working with multimedia applications, extra steps would be involved.

That's why your code is highly specific to C and cannot be converted directly to Go without a corresponding implementation of FFmpeg in Go. For such multimedia related tasks, using FFmpeg or other similar library is a common approach even though it means using a lower level language like C. It would make the resulting application faster and more capable. 

In Go, so far there are efforts to bind FFmpeg libraries such as "goav", but these are still experimental or not stable and would still require developers to be aware of C and its interoperation with Go. 

Remember also that different programming languages have strengths in different areas. One of using Go would be to implement web services or concurrent processing, on account of its ease of use and efficiency, while C and its libraries would be typically used for low level and performant operations such as multimedia processing and systems programming.