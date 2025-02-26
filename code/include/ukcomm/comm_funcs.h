#ifndef __COMM_FUNCS__
#define __COMM_FUNCS__

#define PTR_INVALID(p) (!p)

static inline const char* ptrstr(const char* s)
{
	return (s ? s : "null");
}

#endif