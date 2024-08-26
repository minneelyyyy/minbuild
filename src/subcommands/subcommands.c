#include <stdio.h>
#include <string.h>

#include <common.h>

#include "subcommands.h"

#define SUBCOMMAND(name, desc) { name, #name, desc }

const static struct subcommand subcommands[] = {
	SUBCOMMAND(build, "build the current project"),
    SUBCOMMAND(clean, "clean objects for the current project"),
    SUBCOMMAND(help, "display help message"),
};

const struct subcommand *get_subcommand(const char *name) {
    size_t i;

    for (i = 0; i < sizeof_arr(subcommands); i++)
        if (!strcmp(name, subcommands[i].name))
            return &subcommands[i];

    return NULL;
}

int help(int argc, char **argv) {
    size_t i;

    printf("USAGE: minbuild <subcommand> [args...]\n\n");

    for (i = 0; i < sizeof_arr(subcommands); i++) {
        printf("    %s\t%s\n", subcommands[i].name, subcommands[i].description);
    }

    return 0;
}