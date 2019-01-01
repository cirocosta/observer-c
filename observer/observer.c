/* observer.c */

#include <stdlib.h>
#include "observer.h"

Observer *observer_make(/*void* impl, void (*notifyImpl)(void*, int, void*)*/)
{
  Observer *this = (Observer *)malloc(sizeof(Observer));

  /*
	this->destroy = _destroy;
	this->notify = _notify;
	this->impl = impl;
	this->notifyImpl = (void (*)(void*, int, void*)) notifyImpl;
  */

  return this;
}

void observer_destroy(Observer *theObserver)
{
  if (theObserver != NULL) {
    free(theObserver);
    theObserver = NULL;
  }
}

void observer_update()
{
}

/*
static void _notify(Observer *this, int type, void * subject)
{
	this->notifyImpl(this->impl, type, subject);
}
*/

