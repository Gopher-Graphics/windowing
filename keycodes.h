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
    GGW_SINGLE_CODE(DELETE, -0x01, ENUM)                                       \
    GGW_SINGLE_CODE(BACKSPACE, -0x02, ENUM)                                    \
    GGW_SINGLE_CODE(INSERT, -0x03, ENUM)                                       \
    GGW_SINGLE_CODE(SHIFT, -0x04, ENUM)                                        \
    GGW_SINGLE_CODE(CTRL, -0x05, ENUM)                                         \
    GGW_SINGLE_CODE(MOD, -0x06, ENUM)                                          \
    GGW_SINGLE_CODE(ALT, -0x07, ENUM)                                          \
    GGW_SINGLE_CODE(FUNCTION, -0x08, ENUM)                                     \
    GGW_SINGLE_CODE(CAPS_LOCK, -0x09, ENUM)                                    \
    GGW_SINGLE_CODE(ESCAPE, -0x0A, ENUM)                                       \
    GGW_SINGLE_CODE(HOME, -0x0B, ENUM)                                         \
    GGW_SINGLE_CODE(PAGE_UP, -0x0C, ENUM)                                      \
    GGW_SINGLE_CODE(PAGE_DOWN, -0x0D, ENUM)                                    \
    GGW_SINGLE_CODE(END, -0x0E, ENUM)                                          \
    GGW_SINGLE_CODE(PRINT_SCREEN, -0x0F, ENUM)                                 \
    GGW_SINGLE_CODE(F1, -0x10, ENUM)                                           \
    GGW_SINGLE_CODE(F2, -0x11, ENUM)                                           \
    GGW_SINGLE_CODE(F3, -0x12, ENUM)                                           \
    GGW_SINGLE_CODE(F4, -0x13, ENUM)                                           \
    GGW_SINGLE_CODE(F5, -0x14, ENUM)                                           \
    GGW_SINGLE_CODE(F6, -0x15, ENUM)                                           \
    GGW_SINGLE_CODE(F7, -0x16, ENUM)                                           \
    GGW_SINGLE_CODE(F8, -0x17, ENUM)                                           \
    GGW_SINGLE_CODE(F9, -0x18, ENUM)                                           \
    GGW_SINGLE_CODE(F10, -0x19, ENUM)                                          \
    GGW_SINGLE_CODE(F11, -0x1A, ENUM)                                          \
    GGW_SINGLE_CODE(F12, -0x1B, ENUM)                                          \
                                                                               \
    GGW_SINGLE_CODE(TAB, 0x09, ENUM)                                           \
    GGW_SINGLE_CODE(SPACE, 0x20, ENUM)                                         \
    GGW_SINGLE_CODE(EXCLAMATION_MARK, 0x21, ENUM)                              \
    GGW_SINGLE_CODE(POUND_SIGN, 0x23, ENUM)                                    \
    GGW_SINGLE_CODE(DOLLAR_SIGN, 0x24, ENUM)                                   \
    GGW_SINGLE_CODE(PERCENT_SYMBOL, 0x25, ENUM)                                \
    GGW_SINGLE_CODE(SINGLE_QUOTATION_MARK, 0x27, ENUM)                         \
    GGW_SINGLE_CODE(LEFT_PARENTHESIS, 0x28, ENUM)                              \
    GGW_SINGLE_CODE(RIGHT_PARENTHESIS, 0x29, ENUM)                             \
    GGW_SINGLE_CODE(ASTERISK, 0x2A, ENUM)                                      \
    GGW_SINGLE_CODE(COMMA, 0x2C, ENUM)                                         \
    GGW_SINGLE_CODE(MINUS_SIGN, 0x2D, ENUM)                                    \
    GGW_SINGLE_CODE(PERIOD, 0x2E, ENUM)                                        \
    GGW_SINGLE_CODE(FORWARD_SLASH, 0x2F, ENUM)                                 \
    GGW_SINGLE_CODE(NUMBER_ZERO, 0x30, ENUM)                                   \
    GGW_SINGLE_CODE(NUMBER_ONE, 0x31, ENUM)                                    \
    GGW_SINGLE_CODE(NUMBER_TWO, 0x32, ENUM)                                    \
    GGW_SINGLE_CODE(NUMBER_THREE, 0x33, ENUM)                                  \
    GGW_SINGLE_CODE(NUMBER_FOUR, 0x34, ENUM)                                   \
    GGW_SINGLE_CODE(NUMBER_FIVE, 0x35, ENUM)                                   \
    GGW_SINGLE_CODE(NUMBER_SIX, 0x36, ENUM)                                    \
    GGW_SINGLE_CODE(NUMBER_SEVEN, 0x37, ENUM)                                  \
    GGW_SINGLE_CODE(NUMBER_EIGHT, 0x38, ENUM)                                  \
    GGW_SINGLE_CODE(NUMBER_NINE, 0x39, ENUM)                                   \
    GGW_SINGLE_CODE(SEMICOLON, 0x3B, ENUM)                                     \
    GGW_SINGLE_CODE(EQUALS_SIGN, 0x3D, ENUM)                                   \
    GGW_SINGLE_CODE(AT_SYMBOL, 0x40, ENUM)                                     \
    GGW_SINGLE_CODE(RIGHT_BRACKET, 0x5B, ENUM)                                 \
    GGW_SINGLE_CODE(BACK_SLASH, 0x5C, ENUM)                                    \
    GGW_SINGLE_CODE(LEFT_BRACKET, 0x5D, ENUM)                                  \
    GGW_SINGLE_CODE(CARROT, 0x5E, ENUM)                                        \
    GGW_SINGLE_CODE(UNDERSCORE, 0x5F, ENUM)                                    \
    GGW_SINGLE_CODE(BACK_TICK, 0x60, ENUM)                                     \
    GGW_SINGLE_CODE(A_LOWERCASE, 0x61, ENUM)                                   \
    GGW_SINGLE_CODE(B_LOWERCASE, 0x62, ENUM)                                   \
    GGW_SINGLE_CODE(C_LOWERCASE, 0x63, ENUM)                                   \
    GGW_SINGLE_CODE(D_LOWERCASE, 0x64, ENUM)                                   \
    GGW_SINGLE_CODE(E_LOWERCASE, 0x65, ENUM)                                   \
    GGW_SINGLE_CODE(F_LOWERCASE, 0x66, ENUM)                                   \
    GGW_SINGLE_CODE(G_LOWERCASE, 0x67, ENUM)                                   \
    GGW_SINGLE_CODE(H_LOWERCASE, 0x68, ENUM)                                   \
    GGW_SINGLE_CODE(I_LOWERCASE, 0x69, ENUM)                                   \
    GGW_SINGLE_CODE(J_LOWERCASE, 0x6A, ENUM)                                   \
    GGW_SINGLE_CODE(K_LOWERCASE, 0x6B, ENUM)                                   \
    GGW_SINGLE_CODE(L_LOWERCASE, 0x6C, ENUM)                                   \
    GGW_SINGLE_CODE(M_LOWERCASE, 0x6D, ENUM)                                   \
    GGW_SINGLE_CODE(N_LOWERCASE, 0x6E, ENUM)                                   \
    GGW_SINGLE_CODE(O_LOWERCASE, 0x6F, ENUM)                                   \
    GGW_SINGLE_CODE(P_LOWERCASE, 0x70, ENUM)                                   \
    GGW_SINGLE_CODE(Q_LOWERCASE, 0x71, ENUM)                                   \
    GGW_SINGLE_CODE(R_LOWERCASE, 0x72, ENUM)                                   \
    GGW_SINGLE_CODE(S_LOWERCASE, 0x73, ENUM)                                   \
    GGW_SINGLE_CODE(T_LOWERCASE, 0x74, ENUM)                                   \
    GGW_SINGLE_CODE(U_LOWERCASE, 0x75, ENUM)                                   \
    GGW_SINGLE_CODE(V_LOWERCASE, 0x76, ENUM)                                   \
    GGW_SINGLE_CODE(W_LOWERCASE, 0x77, ENUM)                                   \
    GGW_SINGLE_CODE(X_LOWERCASE, 0x78, ENUM)                                   \
    GGW_SINGLE_CODE(Y_LOWERCASE, 0x79, ENUM)                                   \
    GGW_SINGLE_CODE(Z_LOWERCASE, 0x7A, ENUM)

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
