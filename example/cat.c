/* cat.c */

#include <stdio.h>
#include <stdlib.h>
#include "cat.h"
#include "utils.h"

/*
 * Whenever a Cat MEOWS, a Dogs listen to it.
 * Cat is the subject, Dog is the Observer.
 */


Cat *cat_make(const char * const name)
{
  Cat *this = (Cat *)malloc(sizeof(Cat));
  
  strAllocAndCopy(&(this->name), name);

	/*
	this->getEvent = _getEvent;

	this->subject = subjectNew(this, 1);
	this->registerObserver = _registerObserver;
	this->unregisterObserver = _unregisterObserver;
  */

	return this;
}

void cat_destroy(Cat *theCat)
{
  /*this->subject->destroy(this->subject);*/

  if (theCat != NULL) {
    free(theCat->name);
    free(theCat);
    theCat = NULL;
  }
}

void cat_speak(const Cat * const theCat)
{
  printf("%s the cat says Meowww\n", theCat->name);

  /*
	this->event = SPEAK;
	this->subject->notifyObservers(this->subject);
  */
}

/*

static CatEvent _getEvent(Cat* this)
{
	return this->event;
}
*/

/**
 * Proxy method for Register an observer for the Cat object.
 * @param this
 * @param observer
 * @return
 */
/*
static int _registerObserver(Cat* this, Observer* observer) {
  return this->subject->registerObserver(this->subject, observer);
}
*/

/**
 * Proxy method for Unregister observer for the Cat object.
 * @param this
 * @param observer
 * @return
 */
/*
static int _unregisterObserver(Cat * this, Observer* observer) {
  return this->subject->unregisterObserver(this->subject, observer);
}
*/

