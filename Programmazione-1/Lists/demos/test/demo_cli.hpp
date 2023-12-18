struct CliOpts {
	bool ask_size = false;
	bool help = false;
	bool version = false;
	bool author = false;
};

const char* const options[] = {
	"  --ask-size: ask for the list size",
	"  --help: show this help message",
	"  --version: show the program version",
	"  --author: show the program author",
};

CliOpts parse_opts(int argc, char** argv);
const char* get_usage(const char* name);
