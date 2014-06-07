#ifndef OBSERVABLE_H
	#define OBSERVABLE_H
	#include "observer.h"

	typedef struct __observable
	{
		void (*destroy)(struct __observable *);
		void * impl;
		int type;
		Observer * observers[MAX_OBSERVERS];
		int (*registerObserver)(struct __observable*, Observer*);
		int (*unregisterObserver)(struct __observable *, Observer*);
		void (*notifyObservers)(struct __observable*);
	} Observable;

	Observable * observableNew(void*, int);

#endif
