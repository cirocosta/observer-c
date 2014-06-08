/**
 * Definition of the CAT class stuff!
 */

#ifndef CAT_H
  #define CAT_H
  #include <stdio.h>
  #include <stdlib.h>
  #include "../../observer/observer.h"
  #include "../../observer/subject.h"

  typedef enum __cat_event
  {
    SPEAK
  } CatEvent;

  typedef struct __cat
  {
    char* name;
    void (*destroy)(struct __cat*);

    CatEvent event;
    CatEvent (*getEvent)(struct __cat*);

    void (*speak)(struct __cat*);

    Subject * subject;
    int (*registerObserver)(struct __cat*, Observer*);
    int (*unregisterObserver)(struct __cat *, Observer*);
  } Cat;

  /**
   * Creates a cat!
   */
  Cat* CAT_create(char *);

#endif
