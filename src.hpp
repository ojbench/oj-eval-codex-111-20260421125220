// Problem 111 - Cstring Implement III
// Implement a custom strtok without using any standard library and no global variables.

static int is_delim_local(char c, const char *delim) {
    if (!delim) return 0;
    const char *p = delim;
    while (*p) {
        if (*p == c) return 1;
        ++p;
    }
    return 0;
}

char *strtok(char *str, const char *delim) {
    static char *saved = 0;

    if (str) {
        saved = str;
    }

    if (!saved) {
        return 0;
    }

    char *p = saved;

    // Skip leading delimiters
    while (*p && is_delim_local(*p, delim)) {
        ++p;
    }

    if (!*p) {
        saved = 0;
        return 0;
    }

    char *token_start = p;

    // Advance until next delimiter or end of string
    while (*p && !is_delim_local(*p, delim)) {
        ++p;
    }

    if (*p) {
        *p = '\0';
        saved = p + 1;
    } else {
        saved = 0;
    }

    return token_start;
}
