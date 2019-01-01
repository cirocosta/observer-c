/* subject.c */

#include <stdlib.h>
#include "subject.h"

Subject *subject_make(/*void* impl, int type*/)
{
  Subject *this = (Subject *)malloc(sizeof(Subject));

  /*
	this->destroy = _destroy;
	this->impl = impl;
	this->type = type;
	this->registerObserver = _registerObserver;
	this->unregisterObserver = _unregisterObserver;
	this->notifyObservers = _notifyObservers;
  */

  return this;
}

void subject_destroy(Subject *theSubject)
{
  if (theSubject != NULL) {
    free(theSubject);
    theSubject = NULL;
  }
}

/*
static int _registerObserver(Subject* this, Observer* observer)
{
	int i = 0;

	for (; i < MAX_OBSERVERS; i++) {
		if (this->observers[i] == NULL) {
			this->observers[i] = observer;

			return OK;
		}
	}

	printf("[INF] [SUBJECT] we have rush the max number of observers\n");
	return KO;
}
*/

/*
static int _unregisterObserver(Subject *this, Observer* observer)
{
	int i = 0;

	for (; i < MAX_OBSERVERS; i++) {
		void* pObserver = this->observers[i];

		if (observer == pObserver) {
			pObserver = NULL;
			return OK;
		}
	}

	return KO;
}
*/


/*
static void _notifyObservers(Subject* this)
{
	int i = 0;

	for (; i < MAX_OBSERVERS; i++) {
		if (this->observers[i] != NULL) {
			this->observers[i]->notify(this->observers[i], this->type, this->impl);
		}
	}
}
*/

