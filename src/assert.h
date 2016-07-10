#include <stdio.h>
#include <stdlib.h>

#define assert(e) ((void) ((e) ? 0 : __assert (#e, __FILE__, __LINE__)))
#define __assert(e, file, line) ((void)printf ("%s:%u: failed assertion `%s'\n", file, line, e), exit(1), 0)

