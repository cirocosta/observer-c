/* subject.h */

#ifndef SUBJECT_H
#define SUBJECT_H

#define MAX_OBSERVERS 20

#include "observer.h"

typedef struct subject
{
  Observer *observers[MAX_OBSERVERS];
} Subject;

Subject *subject_make();
void subject_destroy(Subject *theSubject);

void subject_attach(Subject * const theSubject, Observer * const theObserver);
void subject_notify(const Subject * const theSubject, void *data);

#endif
