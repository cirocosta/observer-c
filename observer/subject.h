/* subject.h */

#ifndef SUBJECT_H
#define SUBJECT_H

/*#include "observer.h"
*/

typedef struct subject
{
  /*
		int type;
		void (*destroy)(struct __subject *);
		void * impl;
		Observer * observers[MAX_OBSERVERS];
		int (*registerObserver)(struct __subject*, Observer*);
		int (*unregisterObserver)(struct __subject *, Observer*);
		void (*notifyObservers)(struct __subject*);
    */
} Subject;

Subject *subject_make(/*void*, int*/);
void subject_destroy(Subject *theSubject);

#endif
