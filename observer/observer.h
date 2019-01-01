/* observer.h */

#ifndef OBSERVER_H
#define OBSERVER_H

typedef struct observer {
  /*
		void* impl;
		void (*notify)(struct __observer*, int, void *);
		void (*notifyImpl)(void*, int, void*);
    */
} Observer;

Observer *observer_make(/*void*, void (*)(void*, int, void*)*/);
void observer_destroy(Observer *theObserver);

void observer_update();

#endif
