#include "cat.h"

/**
 * Whenever a cat MEOWS, Dogs listen to it
 */

static void _speak(Cat* this)
{
  printf("%s\n", "My name is:");
  printf("%s\n", this->name);
  printf("%s\n", "Miaaaau");

	this->event = SPEAK;
	this->observable->notifyObservers(this->observable);
}

static void _destroy(Cat* this)
{
  if (NULL != this) {
    free(this);
    this = NULL;
  }
}

static void _getEvent(Cat* this)
{
	return this->event;
}

/**
 * Proxy method for Register an observer for the Cat object.
 * @param this
 * @param observer
 * @return
 */
static int _registerObserver(Cat* this, Observer* observer) {
  return this->observable->registerObserver(this->observable, observer);
}

/**
 * Proxy method for Unregister observer for the Cat object.
 * @param this
 * @param observer
 * @return
 */
static int _unregisterObserver(Cat * this, Observer* observer) {
  return this->observable->unregisterObserver(this->observable, observer);
}
/**
 * Creates a cat!
 */
Cat* CAT_create(char * name)
{
	Cat* this = (Cat *) malloc(sizeof(this));
	this->name = name;
	this->destroy = _destroy;
	this->getEvent = _getEvent;
	this->speak = _speak;

	this->observable = observableNew(this, 1);
	this->registerObserver = _registerObserver;
	this->unregisterObserver = _unregisterObserver;

	return this;
}
