#ifndef TEAM_H
#define TEAM_H

typedef struct team Team;

Team *team_create(int id, const char *name);

int team_get_id(const Team *team);
const char *team_get_name(const Team *team);
int team_get_wins(const Team *team);
int team_get_draws(const Team *team);
int team_get_losses(const Team *team);
int team_get_goals_scored(const Team *team);
int team_get_goals_conceded(const Team *team);

void team_free(Team *team);

#endif
