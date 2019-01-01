/* cat.c */

#include <stdio.h>
#include <stdlib.h>
#include "cat.h"
#include "utils.h"
#include "../observer/subject.h"

Cat *cat_make(const char * const name)
{
  Cat *this = (Cat *)malloc(sizeof(Cat));
  
  strAllocAndCopy(&(this->name), name);

	this->theSubject = subject_make();

	return this;
}

void cat_destroy(Cat *theCat)
{
  if (theCat != NULL) {
    free(theCat->name);
    subject_destroy(theCat->theSubject);
    free(theCat);
    theCat = NULL;
  }
}

void cat_speak(const Cat * const theCat)
{
  printf("%s the cat says Meowww\n", theCat->name);

  subject_notify(theCat->theSubject, (void *)theCat);
}
