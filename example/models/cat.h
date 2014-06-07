/**
 * Definition of the CAT class stuff!
 */

#ifndef DOG_H
  #define DOG_H
  #include <stdio.h>
  #include <stdlib.h>
  #include "../../observer/observer.h"
  #include "../../observer/observable.h"

  typedef struct __cat
  {
    char* name;
    void (*speak)(struct __cat*);
    void (*destroy)(struct __cat*);

    Observable * observable;
    int (*registerObserver)(struct __cat*, Observer*);
    int (*unregisterObserver)(struct __cat *, Observer*);
  } Cat;

  /**
   * Creates a cat!
   */
  Cat* CAT_create(char *);

#endif
