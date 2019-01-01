/* utils.c */

#include <stdlib.h>
#include <string.h>
#include "utils.h"

void strAllocAndCopy(char **dst, const char * const src)
{
  int srcSize = strlen(src);
  *dst = (char *)malloc(sizeof(char)*srcSize + 1);
  strncpy(*dst, src, srcSize);
  (*dst)[srcSize] = '\0';
}
