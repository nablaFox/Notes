#include "demo_cli.hpp"
#include <iostream>
#include <cstring>

static bool there_is(char* arg, const char* opt) { return strcmp(arg, opt) == 0; }

static void check(const char* opt, bool& flag, char* arg) {
	if (flag)
		return;

	flag = there_is(arg, opt);
}

const char* get_usage(const char* name) {
	const char* options[] = {
		"  --ask-size: ask for the list size",
		"  --help: show this help message",
		"  --version: show the program version",
		"  --author: show the program author",
	};

	const int size = sizeof(options) / sizeof(options[0]);
	char* usage = new char[1000];
	strcpy(usage, "Usage: ");
	strcat(usage, name);
	strcat(usage, " [options]\nOptions:\n");

	for (int i = 0; i < size; i++) {
		strcat(usage, options[i]);
		strcat(usage, "\n");
	}

	return usage;
}

CliOpts parse_opts(int argc, char** argv) {
	CliOpts opts;

	for (int i = 1; i < argc; i++) {
		char* arg = argv[i];
		check("--version", opts.version, arg);
		check("--author", opts.author, arg);
		check("--help", opts.help, arg);
		check("--ask-size", opts.ask_size, arg);
	}

	return opts;
}
