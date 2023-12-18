struct CliOpts {
	bool ask_size = false;
	bool help = false;
	bool version = false;
	bool author = false;
};

CliOpts parse_opts(int argc, char** argv);
const char* get_usage(const char* name);
