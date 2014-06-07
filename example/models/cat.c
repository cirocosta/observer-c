#include "cat.h"

/**
 * Whenever a
 */

static void _speak(Cat* this)
{
  printf("%s\n", "My name is:");
  printf("%s\n", this->name);
  printf("%s\n", "Miaaaau");
}

static void _destroy(Cat* this)
{
  if (NULL != this) {
    free(this);
    this = NULL;
  }
}

/**
 * Proxy method for Register an observer for the printer object.
 * @param this
 * @param observer
 * @return
 */
static int _registerObserver(Printer* this, Observer* observer) {
  return this->observable->registerObserver(this->observable, observer);
}

/**
 * Proxy method for Unregister observer for the printer object.
 * @param this
 * @param observer
 * @return
 */
static int _unregisterObserver(Printer * this, Observer* observer) {
  return this->observable->unregisterObserver(this->observable, observer);
}
/**
 * Creates a cat!
 */
Cat* CAT_create(char *);
