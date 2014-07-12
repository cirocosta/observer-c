#include "observer.h"

static void _destroy(Observer* this)
{
	if (this != NULL) {
		free(this);
		this = NULL;
	}
}

static void _notify(Observer *this, int type, void * subject)
{
	this->notifyImpl(this->impl, type, subject);
}

Observer* observerNew(void* impl, void (*notifyImpl)(void*, int, void*))
{
	Observer* this = (Observer *) malloc(sizeof(*this));

	this->destroy = _destroy;
	this->notify = _notify;
	this->impl = impl;
	this->notifyImpl = (void (*)(void*, int, void*)) notifyImpl;

	return this;
}
