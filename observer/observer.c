#include "observer.h"

/**
 * Destructor for our Observer
 */
static void _destroy(Observer* this)
{
	if (this != NULL) {
		free(this);
		this = NULL;
	}
}

static void _notify(Observer *this, int type, void * observable)
{
	this->notifyImpl(this->impl, type, observable);
}

Observer * observerNew(void* impl, void (*notifyImpl)(void*, int, void*))
{
	Observer * this = (Observer *) malloc(sizeof(*this));
	this->destroy = _destroy;
	this->notify = _notify;
	this->impl = impl;
	this->notifyImpl = (void (*)(void*, int, void*)) notifyImpl;

	return this;
}
