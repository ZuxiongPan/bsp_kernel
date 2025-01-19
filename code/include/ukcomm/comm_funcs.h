#ifndef __COMM_FUNCS__
#define __COMM_FUNCS__

#define PTR_INVALID(p) (!p)

static inline const char* ptrstr(const char* s)
{
	return (s ? s : "NULL");
}

static inline unsigned long long ptr_to_hex(void* p)
{
	return (unsigned long long)p;
}

#endif