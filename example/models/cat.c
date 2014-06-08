#include "cat.h"

/**
 * Whenever a cat MEOWS, Dogs listen to it. CAT is the Subject.
 */

static void _speak(Cat* this)
{
  printf("%s\n", "My name is:");
  printf("%s\n", this->name);
  printf("%s\n", "Miaaaau");

	this->event = SPEAK;
	this->subject->notifyObservers(this->subject);
}

static void _destroy(Cat* this)
{
	this->subject->destroy(this->subject);

  if (NULL != this) {
    free(this);
    this = NULL;
  }
}

static CatEvent _getEvent(Cat* this)
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
  return this->subject->registerObserver(this->subject, observer);
}

/**
 * Proxy method for Unregister observer for the Cat object.
 * @param this
 * @param observer
 * @return
 */
static int _unregisterObserver(Cat * this, Observer* observer) {
  return this->subject->unregisterObserver(this->subject, observer);
}
/**
 * Creates a cat!
 */
Cat* CAT_create(char * name)
{
	Cat* this = (Cat *) malloc(sizeof(*this));
	this->name = name;
	this->destroy = _destroy;
	this->getEvent = _getEvent;
	this->speak = _speak;

	this->subject = subjectNew(this, 1);
	this->registerObserver = _registerObserver;
	this->unregisterObserver = _unregisterObserver;

	return this;
}
