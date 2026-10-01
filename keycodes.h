#ifndef GGW_KEYCODES_H
#define GGW_KEYCODES_H

#define GGW_SINGLE_CODE1(CODE, VAL) GGW_KEY_##CODE = VAL,
#define GGW_SINGLE_CODE0(CODE, VAL)                                            \
    case VAL:                                                                  \
        return #CODE;
#define GGW_SINGLE_CODE(CODE, VAL, ENUM) GGW_SINGLE_CODE##ENUM(CODE, VAL)

/*
 * Keycodes are defined here, using a name and a ASCII keycode number
 *
 * ENUM is 1 if we are defining these values in an enum, and 0 if we are
 * defining them in a switch statement mapping values to names
 */
#define GGW_ALL_CODES(ENUM)                                                    \
    GGW_SINGLE_CODE(SPACE, 0x20, ENUM)                                         \
    GGW_SINGLE_CODE(EXCLAMATION_MARK, 0x21, ENUM)                              \
    GGW_SINGLE_CODE(DOUBLE_QUOTATION_MARK, 0x22, ENUM)                         \
    // TODO fill out the rest of these...

typedef enum {
    // Macro, expands from the above
    GGW_ALL_CODES(1)
} GGW_Keycode;

inline const char *GGW_getKeycodeName(GGW_Keycode code) {
    switch (code) {
        // Another macro, once again expands from the above
        GGW_ALL_CODES(0)
    }
    return (const char *)0;
}

#endif // GGW_KEYCODES_H
