#include "configargs.h"

#define GCCPLUGIN_VERSION_MAJOR   14
#define GCCPLUGIN_VERSION_MINOR   0
#define GCCPLUGIN_VERSION_PATCHLEVEL   0
#define GCCPLUGIN_VERSION  (GCCPLUGIN_VERSION_MAJOR*1000 + GCCPLUGIN_VERSION_MINOR)

static char basever[] = "14.0.0";
static char datestamp[] = "20230605";
static char devphase[] = "experimental";
static char revision[] = "[master revision c7fe7ad612bb6aac1d078d215d5700ec4ef70e3c]";

/* FIXME plugins: We should make the version information more precise.
   One way to do is to add a checksum. */

static struct plugin_gcc_version gcc_version = {basever, datestamp,
						devphase, revision,
						configuration_arguments};
