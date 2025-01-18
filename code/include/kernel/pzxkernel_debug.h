#ifndef __BEARKERNEL_DEBUG__
#define __BEARKERNEL_DEBUG__

typedef void (*print_object)(void *pobj);

extern print_object pr_filesystem;

#endif