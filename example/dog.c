/* dog.c */

#include <stdio.h>
#include <stdlib.h>
#include "cat.h"
#include "dog.h"
#include "utils.h"
#include "../observer/observer.h"

Dog *dog_make(const char * const name)
{
  Dog *this = (Dog *)malloc(sizeof(Dog));

  strAllocAndCopy(&(this->name), name);

  this->theObserver = observer_make((void *)this, dog_notify);

	return this;
}

void dog_destroy(Dog *theDog)
{
  if (theDog != NULL) {
    free(theDog->name);
    observer_destroy(theDog->theObserver);
    free(theDog);
    theDog = NULL;
  }
}

void dog_speak(Dog *theDog)
{
  printf("%s the dog says Bauuuu\n", theDog->name);
}

void dog_notify(void *aDog, void *data)
{
  Dog *theDog = (Dog *)aDog;
  Cat *theCat = (Cat *)data;

  printf("%s the Dog just heared %s the Cat saying MEOWS\n", theDog->name, theCat->name);
}
