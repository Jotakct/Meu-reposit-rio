#ifndef TEAMVEC_H
#define TEAMVEC_H

#include "team.h"

typedef struct teamvec TeamVec;

TeamVec *tv_create(void);
int tv_insert(TeamVec *vec, Team *team);
int tv_size(const TeamVec *vec);
Team *tv_get(const TeamVec *vec, int index);
void tv_free(TeamVec *vec);

#endif
