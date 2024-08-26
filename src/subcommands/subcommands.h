#ifndef __SUBCOMMANDS_H
#define __SUBCOMMANDS_H

typedef int (*subcommand_t)(int, char**);

struct subcommand {
	subcommand_t func;
	const char *name;
	const char *description;
};

extern int build(int, char**);
extern int clean(int, char**);
extern int help(int, char**);

const struct subcommand *get_subcommand(const char *name);

#endif /* __SUBCOMMANDS_H */