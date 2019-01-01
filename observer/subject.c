/* subject.c */

#include <stdio.h>
#include <stdlib.h>
#include "subject.h"
#include "observer.h"

Subject *subject_make()
{
  Subject *this = (Subject *)malloc(sizeof(Subject));

  int i;
  for (i = 0; i < MAX_OBSERVERS; i++) {
    this->observers[i] = NULL;
  }

  return this;
}

void subject_destroy(Subject *theSubject)
{
  int i;

  if (theSubject != NULL) {
    for (i = 0; i < MAX_OBSERVERS; i++) {
      if (theSubject->observers[i] != NULL) {
        theSubject->observers[i] = NULL;
      }
    }
    free(theSubject);
    theSubject = NULL;
  }
}

void subject_attach(Subject * const theSubject, Observer * const theObserver)
{
  int i;
  for (i = 0; i < MAX_OBSERVERS; i++) {
    if (theSubject->observers[i] == NULL) {
      theSubject->observers[i] = theObserver;
      return;
    }
  }

  printf("Error: unable to attach the Observer\n");
}

void subject_notify(const Subject * const theSubject, void *data)
{
  int i;
  for (i = 0; i < MAX_OBSERVERS; i++) {
    if (theSubject->observers[i] != NULL) {
      observer_update(theSubject->observers[i], data);
    }
  }
}
