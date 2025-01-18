#ifndef __COMM_FUNCS__
#define __COMM_FUNCS__

#define ptr_invalid(p) (!p)

static inline const char* ptrstr(const char* s)
{
	return (s ? s : "NULL");
}


#endif