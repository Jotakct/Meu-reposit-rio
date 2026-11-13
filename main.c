#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "team.h"
#include "teamvec.h"

int main(void) {
    FILE *arquivo;
    char linha[256];
    char *separador;
    char *nome;
    int id;
    int saldo;
    int pontos;
    int i;
    Team *team;
    TeamVec *times;

    times = tv_create();

    if (times == NULL) {
        printf("Erro ao criar o vetor de times.\n");
        return 1;
    }

    arquivo = fopen("teams.csv", "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir teams.csv.\n");
        tv_free(times);
        return 1;
    }

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        linha[strcspn(linha, "\r\n")] = '\0';

        separador = strchr(linha, ',');

        if (separador == NULL) {
            continue;
        }

        *separador = '\0';
        id = atoi(linha);
        nome = separador + 1;

        team = team_create(id, nome);

        if (team == NULL) {
            printf("Erro ao criar um time.\n");
            fclose(arquivo);
            tv_free(times);
            return 1;
        }

        if (!tv_insert(times, team)) {
            printf("Erro ao inserir um time no vetor.\n");
            team_free(team);
            fclose(arquivo);
            tv_free(times);
            return 1;
        }
    }

    fclose(arquivo);

    printf("ID  Time            V   E   D   GM  GS  S   PG\n");

    for (i = 0; i < tv_size(times); i++) {
        team = tv_get(times, i);

        saldo = team_get_goals_scored(team) - team_get_goals_conceded(team);
        pontos = 3 * team_get_wins(team) + team_get_draws(team);

        printf("%-3d %-15s %-3d %-3d %-3d %-3d %-3d %-3d %-3d\n",
               team_get_id(team),
               team_get_name(team),
               team_get_wins(team),
               team_get_draws(team),
               team_get_losses(team),
               team_get_goals_scored(team),
               team_get_goals_conceded(team),
               saldo,
               pontos);
    }

    tv_free(times);

    return 0;
}
