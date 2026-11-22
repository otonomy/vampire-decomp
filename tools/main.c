/* main.c -- vd: the project's command-line tools */

#include <string.h>

#include "vd.h"

int vd_gate_main(int argc, char **argv);
int vd_rules_main(int argc, char **argv);
int vd_rename_main(int argc, char **argv);
int vd_names_main(int argc, char **argv);
int vd_rtti_main(int argc, char **argv);

static void usage(void)
{
	fprintf(stderr,
			"usage: vd <command> [options]\n"
			"  gate   [--root DIR] [--out DIR] [--jobs N] [--no-compile] [--per-block] [-v] [unit.cpp ...]\n"
			"         compile units with VC6 and compare every annotated function with the retail binary\n"
			"  rules  [--root DIR] [--gate build/check.csv] [--out FILE] [--r2 advisory] [unit.cpp ...]\n"
			"         the code-rule checker: [match] findings (MATCH-PENDING) and advisory findings\n"
			"  rename [--root DIR] [--dry-run] MAP\n"
			"         apply a name map (old<TAB>new per line) to src/, include/ and symbols.txt\n"
			"  names  [--root DIR] [--from TEXT] [--min-size N] --matches matches.csv --map OUT.tsv --log OUT.csv\n"
			"         turn symbol-coverage matches into a rename map under fixed evidence rules\n"
			"  rtti   [--root DIR] [--out FILE]\n"
			"         the retail binary's RTTI class hierarchy against the headers' declared bases\n");
}

int main(int argc, char **argv)
{
	if (argc < 2) {
		usage();
		return 2;
	}
	if (strcmp(argv[1], "gate") == 0) {
		return vd_gate_main(argc, argv);
	}
	if (strcmp(argv[1], "rules") == 0) {
		return vd_rules_main(argc, argv);
	}
	if (strcmp(argv[1], "rename") == 0) {
		return vd_rename_main(argc, argv);
	}
	if (strcmp(argv[1], "names") == 0) {
		return vd_names_main(argc, argv);
	}
	if (strcmp(argv[1], "rtti") == 0) {
		return vd_rtti_main(argc, argv);
	}
	usage();
	return 2;
}
