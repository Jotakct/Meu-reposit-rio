#include <stdlib.h>
#include "teamvec.h"

struct teamvec {
    int size;
    int capacity;
    Team **data;
};

TeamVec *tv_create(void) {
    TeamVec *vec = malloc(sizeof(TeamVec));

    if (vec == NULL) {
        return NULL;
    }

    vec->size = 0;
    vec->capacity = 2;
    vec->data = malloc(vec->capacity * sizeof(Team *));

    if (vec->data == NULL) {
        free(vec);
        return NULL;
    }

    return vec;
}

int tv_insert(TeamVec *vec, Team *team) {
    Team **temp;

    if (vec == NULL || team == NULL) {
        return 0;
    }

    if (vec->size == vec->capacity) {
        vec->capacity = vec->capacity * 2;

        temp = realloc(vec->data, vec->capacity * sizeof(Team *));

        if (temp == NULL) {
            vec->capacity = vec->capacity / 2;
            return 0;
        }

        vec->data = temp;
    }

    vec->data[vec->size] = team;
    vec->size++;

    return 1;
}

int tv_size(const TeamVec *vec) {
    if (vec == NULL) {
        return 0;
    }

    return vec->size;
}

Team *tv_get(const TeamVec *vec, int index) {
    if (vec == NULL || index < 0 || index >= vec->size) {
        return NULL;
    }

    return vec->data[index];
}

void tv_free(TeamVec *vec) {
    int i;

    if (vec != NULL) {
        for (i = 0; i < vec->size; i++) {
            team_free(vec->data[i]);
        }

        free(vec->data);
        free(vec);
    }
}
