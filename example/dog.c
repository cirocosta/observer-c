/* dog.c */

#include <stdio.h>
#include <stdlib.h>
#include "dog.h"
#include "utils.h"

Dog *dog_make(const char * const name)
{
  Dog *this = (Dog *)malloc(sizeof(Dog));

  strAllocAndCopy(&(this->name), name);

  /*
	this->smell = _smell;
	this->observer = observerNew(this, (void (*)(void*, int, void*))_notify);
  */

	return this;
}

void dog_destroy(Dog *theDog)
{
/*	this->observer->destroy(this->observer);*/

  if (theDog != NULL) {
    free(theDog->name);
    free(theDog);
    theDog = NULL;
  }
}

void dog_speak(Dog *theDog)
{
  printf("%s the dog says Bauuuu\n", theDog->name);
}

/*
static void _smell(Dog * this, Cat* cat)
{
	cat->registerObserver(cat, this->observer);
	printf("%s Just smelled %s\n", this->name, cat->name);
}

static void _handleCatEvent(Dog* this, Cat* cat)
{
	printf("%s\n just heared %s", this->name, cat->name);
}
*/

/**
 * Observer Method called upon the receiption of an incoming event.
 * @param type
 * @param subject
 */
/*
static void _notify(Dog* this, int numero, void* subject) {
	_handleCatEvent(this, (Cat*) subject);
}
*/


