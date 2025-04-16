#define NOB_IMPLEMENTATION
#include "nob.h"

#define CFLAGS "-Wall",            \
               "-Wextra",          \
               "-L./raylib/linux", \
               "-lraylib",         \
               "-lm"

int main(int argc, char **argv) {

    NOB_GO_REBUILD_URSELF(argc, argv);

    Nob_Cmd cmd = {0};

    nob_cmd_append(&cmd, "cc", "src/main.c", CFLAGS, "-o", "main");

    if (!nob_cmd_run_sync_and_reset(&cmd))
        return 1;

    return 0;
}
