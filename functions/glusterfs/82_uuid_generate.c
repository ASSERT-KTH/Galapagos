void uuid_generate(uuid_t out)
{
	if(Nt5())
	{
		unsigned char seed[6];
		((NtAllocateUuids_2000)NtAllocateUuids)(out, ((char*)out)+8, ((char*)out)+12, &seed[0] );
	}
	else
	{
		NtAllocateUuids(out, ((char*)out)+8, ((char*)out)+12);
	}
}