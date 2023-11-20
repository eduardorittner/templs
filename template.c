#define _GNU_SOURCE
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define _DEBUG 1

#ifdef _DEBUG
#define DEBUG_PRINT(x) printf(x);
#else
#define DEBUG_PRINT(x)
#endif

bool create_daily(size_t day, size_t month, size_t year, char *pathname) {

    char filename[1024];
    memcpy(filename, pathname, strnlen(pathname, 1024 - 32) + 1);

    char month_day_str[32];
    snprintf(month_day_str, 32, "/%ld/%ld/%ld.md", year, month, day);
    strncat(filename, month_day_str, 32);

    if (access(filename, F_OK) == 0) {
        DEBUG_PRINT("FILE ALREADY EXISTS\n")
        return false;
    }

    FILE *file = fopen(filename, "a");

    if (file == NULL) {
        DEBUG_PRINT("ERROR OPENING FILE\n")
        return false;
    }

    char *time_str = malloc(128 * sizeof(char));
    sprintf(time_str, "%ld-%ld-%ld", year, month, day);
    struct tm *time = malloc(sizeof(struct tm));
    int error = getdate_r(time_str, time);

    if (error) {
        return false;
    }

    char weekday[64];

    switch (time->tm_wday) {
    case 0:
        memcpy(weekday, "Domingo", 8);
        break;
    case 1:
        memcpy(weekday, "Segunda", 8);
        break;
    case 2:
        memcpy(weekday, "Terça", 6);
        break;
    case 3:
        memcpy(weekday, "Quarta", 7);
        break;
    case 4:
        memcpy(weekday, "Quinta", 7);
        break;
    case 5:
        memcpy(weekday, "Sexta", 6);
        break;
    case 6:
        memcpy(weekday, "Sábado", 7);
        break;
    }

    fprintf(file, "# %ld/%ld/%ld - %s\n\n\n", day, month, year, weekday);
    fprintf(file, "## Compromissos\n\n\n");
    fprintf(file, "## Tarefas\n\n\n");
    fprintf(file, "## Log\n");

    fclose(file);
    free(time_str);
    free(time);

    return true;
}
