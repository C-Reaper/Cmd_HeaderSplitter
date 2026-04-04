#ifndef TEST_H
#define TEST_H

#include <math.h>
#include <string.h>
#include <stdlib.h>

typedef float F32;
typedef double F64;

#define F32_PI      3.141592654f
#define F32_E       2.718281828f

typedef struct Human {
	unsigned int id;
	unsigned int height;
    void (*do_sth)(struct Human*);
    char name[32];
} Human;

Human Human_New(unsigned int id,unsigned int height,char* name){
	Human h;
    h.id = id;
    h.height = height;
    h.do_sth = NULL;
    memcpy(h.name,name,strlen(name) + 1);
	return h;
}
void Human_Do(Human* h){
	if(h)
        if(h->do_sth)
            h->do_sth(h);
}

#endif