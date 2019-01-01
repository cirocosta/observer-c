/* dog.h */

#ifndef DOG_H
#define DOG_H

/*
#include "../../observer/observer.h"
#include "cat.h"
*/

typedef struct dog
{
  char *name;
} Dog;

Dog *dog_make(const char * const name);
void dog_destroy(Dog *theDog);

void dog_speak(Dog *theDog);

/*
		void (*destroy)(struct __dog*);
		void (*smell)(struct __dog*, Cat*);

		Observer* observer;
    */


#endif
