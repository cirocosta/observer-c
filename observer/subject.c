/* subject.c */

#include <stdio.h>
#include <stdlib.h>
#include "subject.h"
#include "observer.h"

Subject *subject_make(/*void* impl, int type*/)
{
  Subject *this = (Subject *)malloc(sizeof(Subject));

  int i;
  for (i = 0; i < MAX_OBSERVERS; i++) {
    this->observers[i] = NULL;
  }

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
  int i;

  if (theSubject != NULL) {
    for (i = 0; i < MAX_OBSERVERS; i++) {
      if (theSubject->observers[i] != NULL) {
        observer_destroy(theSubject->observers[i]);
        theSubject->observers[i] = NULL;
      }
    }
    free(theSubject);
    theSubject = NULL;
  }
}

void subject_attach(const Subject * const theSubject, const Observer * const theObserver)
{
  int i;
  for (i = 0; i < MAX_OBSERVERS; i++) {
    if (theSubject->observers[i] == NULL) {
      theSubject->observers[i] = theObserver;
      return;
    }
  }

  printf("Error: impossible to attach the Observer\n");
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

