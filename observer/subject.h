/* subject.h */

#ifndef SUBJECT_H
#define SUBJECT_H

#define MAX_OBSERVERS 20

#include "observer.h"

typedef struct subject
{
  Observer *observers[MAX_OBSERVERS];

  /*
		int type;
		void (*destroy)(struct __subject *);
		void * impl;
		int (*registerObserver)(struct __subject*, Observer*);
		int (*unregisterObserver)(struct __subject *, Observer*);
		void (*notifyObservers)(struct __subject*);
    */
} Subject;

Subject *subject_make(/*void*, int*/);
void subject_destroy(Subject *theSubject);

void subject_attach(const Subject * const theSubject, const Observer * const theObserver);

#endif
