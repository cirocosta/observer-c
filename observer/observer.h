/* observer.h */

#ifndef OBSERVER_H
#define OBSERVER_H

typedef struct observer {
  void *parent;
  void (*update)(void *parent, void *data);
} Observer;

Observer *observer_make(void *parent, void (*update)(void *, void *));
void observer_destroy(Observer *theObserver);

void observer_update(Observer *theObserver, void *data);

#endif
