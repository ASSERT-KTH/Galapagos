Go doesn't have pointers to pointers like in C. Also, Go is garbage-collected which means it doesn't directly expose low-level functions like free or unref found in C. 

Have a look at this transformation. It demonstrates "freeing" and "unreferencing" as you might see it in Go with `nil`.

go
func avFrameFree(frame **AVFrame) {
    if frame == nil || *frame == nil {
        return
    }

	func (s **AVFrame) avFrameUnref() {
	    **s = nil
	}

    (*frame).avFrameUnref()
    *frame = nil
}


The re-assignment function with `nil` emulates the "unref" behavior. The abstraction for referenced value completely freed removes tied references announcing GC the portion of memory chunk is ready to be collected.

This example implies the usage of method on pointer to AVFrame: 

go
(*frame).avFrameUnref()


It is totally applicable to use for setting value pointed by pointer to nil:
    
go
(**frm) = nil


Expressing the fact that value is clear and memory may be reclaimed within time determined by Go scheduler and GC adjuster. In Go `runtime` gives a set of allowing tuning GC, however those relying more on experts' opinions or experience in tuning GC for an exact project. Fore example one might know that certain records are huge and collected often or a lot of small ones, hence to avoid heap fragmentation it's a useful knowledge that along with other might be applied into tuning GC..

But mostly basics rules apply pretty straightforward:

1. "Whatever is not referenced, to be taken by GC sooner or later".
2. How it is treated depends on memory model awareness, it designed.
These simple rules allow starting of designing an algorithm. Further tuning is a matе of profiling then to reveal timely stuff and consider structuring memory heaps types over operations on data packets. Each language with gc eases these.

To notice some languages auto suggest heap and stacks size independently which allows creativity but obliges care each type treated properly according to its affection to the program memory management ease. Especially if language fails creating it then it might make having user app memory options better and optimize it for sake of long running processes. Re-creation causes memory fragments then a cleaning upon gc leading to segment widening.
