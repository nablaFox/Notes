struct CliOpts {
	bool ask_size;
	bool help;
	bool version;
	bool author;
};

CliOpts parse_opts(int argc, char** argv);
const char* get_usage(const char* name);
