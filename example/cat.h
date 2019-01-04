/* cat.h */

#ifndef CAT_H
#define CAT_H

#include "../observer/subject.h"

typedef struct cat
{
  char* name;
  Subject *theSubject;
} Cat;

Cat *cat_make(const char * const name);
void cat_destroy(Cat *theCat);

void cat_speak(const Cat * const theCat);

#endif
