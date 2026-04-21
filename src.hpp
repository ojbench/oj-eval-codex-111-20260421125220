// Problem 111 - Cstring Implement III
// Implement a custom strtok without using any standard library and no global variables.

extern "C" {
char *strtok(char * __restrict str, const char * __restrict delim);
}

static inline int __is_delim(char c, const char * __restrict delim) {
    if (!delim) return 0;
    const char *p = delim;
    while (*p) {
        if (*p == c) return 1;
        ++p;
    }
    return 0;
}

extern "C" char *strtok(char * __restrict str, const char * __restrict delim) {
    static char *saved = 0;

    // If a new string is provided, start from it; otherwise continue from saved.
    if (str) {
        saved = str;
    }

    if (!saved) {
        return 0;
    }

    char *p = saved;

    // Skip leading delimiters
    while (*p && __is_delim(*p, delim)) {
        ++p;
    }

    if (!*p) {
        // No token found; reset saved to null for subsequent calls
        saved = 0;
        return 0;
    }

    char *token_start = p;

    // Advance until next delimiter or end of string
    while (*p && !__is_delim(*p, delim)) {
        ++p;
    }

    if (*p) {
        // Found a delimiter; terminate the token and set saved to next char
        *p = '\0';
        saved = p + 1;
    } else {
        // Reached end of string; set saved to null to indicate completion
        saved = 0;
    }

    return token_start;
}

