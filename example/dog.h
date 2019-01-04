/* dog.h */

#ifndef DOG_H
#define DOG_H

#include "../observer/observer.h"

typedef struct dog
{
  char *name;
  Observer *theObserver;
} Dog;

Dog *dog_make(const char * const name);
void dog_destroy(Dog *theDog);

void dog_speak(Dog *theDog);
void dog_update(void *aDog, void *data);

#endif
