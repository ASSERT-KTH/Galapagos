uint64_t load_4(const unsigned char *in)
{  
    uint32_t* prep = reinterpret_cast<uint32_t*>(const_cast<unsigned char *>(in));
    uint64_t result = static_cast<uint64_t>(*prep);
    return result; 
}