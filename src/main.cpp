#include <stdio.h>
#include "core/Core.h"

void ParseArgs(const int argc, const char* argv[]);

int main(const int argc, const char* argv[]) {
    ParseArgs(argc, argv);

    Core app;
    app.Run();

    return 0;
}

void ParseArgs(const int argc, const char* argv[]) {
    for (int i = 0; i < argc; ++i) {
        printf("%s ", argv[i]);
    }
    printf("\n\n");
}