/* observer.c */

#include <stdlib.h>
#include "observer.h"

Observer *observer_make(void *parent, void (*update)(void *, void *))
{
  Observer *this = (Observer *)malloc(sizeof(Observer));

  this->parent = parent;
	this->update = update;

  return this;
}

void observer_destroy(Observer *theObserver)
{
  if (theObserver != NULL) {
    theObserver->parent = NULL;
    theObserver->update = NULL;
    free(theObserver);
    theObserver = NULL;
  }
}

void observer_update(Observer *theObserver, void *data)
{
  theObserver->update(theObserver->parent, data);
}
