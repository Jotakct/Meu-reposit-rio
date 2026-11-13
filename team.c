#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "team.h"

struct team {
    int id;
    char *name;
    int wins;
    int draws;
    int losses;
    int goals_scored;
    int goals_conceded;
};

Team *team_create(int id, const char *name) {
    Team *team = malloc(sizeof(Team));

    if (team == NULL) {
        return NULL;
    }

    team->name = malloc(strlen(name) + 1);

    if (team->name == NULL) {
        free(team);
        return NULL;
    }

    strcpy(team->name, name);

    team->id = id;
    team->wins = 0;
    team->draws = 0;
    team->losses = 0;
    team->goals_scored = 0;
    team->goals_conceded = 0;

    return team;
}

int team_get_id(const Team *team) {
    return team->id;
}

const char *team_get_name(const Team *team) {
    return team->name;
}

int team_get_wins(const Team *team) {
    return team->wins;
}

int team_get_draws(const Team *team) {
    return team->draws;
}

int team_get_losses(const Team *team) {
    return team->losses;
}

int team_get_goals_scored(const Team *team) {
    return team->goals_scored;
}

int team_get_goals_conceded(const Team *team) {
    return team->goals_conceded;
}

void team_free(Team *team) {
    if (team != NULL) {
        free(team->name);
        free(team);
    }
}
