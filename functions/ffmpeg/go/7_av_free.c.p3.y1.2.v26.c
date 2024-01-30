Go does not allow the freedom given in C to directly manipulate memory like you can with malloc() and free(). As such, there is no direct equivalent in Go for free(). The garbage collector automatically takes care of freeing memory.

It's worth pointing out that by designing with "RAII" (Resource Acquisition is Initialization) in mind, you will often not ever need to call free(), since your resources are automatically correctly freed when the object controlling their lifetime is destroyed. 

This doesn't mean you can ignore the topic of resource management in Go, but it simplifies the situation quite a bit. In terms of C, it works more like `shared_ptr<T>` or `unique_ptr<T>` - i.e. it respects ownership semantics.