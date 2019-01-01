/* utils.c */

#include <stdlib.h>
#include <string.h>
#include "utils.h"

void strAllocAndCopy(char **dst, const char * const src)
{
  int dstSize = strlen(src) + 1;
  *dst = (char *)malloc(sizeof(char)*dstSize);
  strncpy(*dst, src, dstSize);
  (*dst)[dstSize-1] = '\0';
}
