/* observer.h */

#ifndef OBSERVER_H
#define OBSERVER_H

typedef struct observer {
  void *parent;
  void (*notify)(void *parent, void *data);
} Observer;

Observer *observer_make(void *parent, void (*notify)(void *, void *));
void observer_destroy(Observer *theObserver);

void observer_update(Observer *theObserver, void *data);

#endif
