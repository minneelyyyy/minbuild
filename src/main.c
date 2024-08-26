#include <stdio.h>
#include <unistd.h>

#include "subcommands/subcommands.h"

int main(int argc, char **argv) {
	struct subcommand *cmd;

	if (argc < 2)
		return help(argc - 1, argv + 1);

	cmd = get_subcommand(argv[1]);

	if (!cmd) {
		fprintf(stderr, "error: unrecognized subcommand \"%s\"\n", argv[1]);
		return help(argc - 1, argv + 1);
	}

	return cmd->func(argc - 1, argv + 1);
}