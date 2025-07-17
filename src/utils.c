#include <stdlib.h>
#include <string.h>

char *mem_strdup(const char *src)
{
	if (!src) return NULL;
	char *dup = malloc(strlen(src)+1);
	if (dup) strcpy(dup, src);
	return dup;
}
