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
    GGW_SINGLE_CODE(POUND_SIGN, 0x23, ENUM)                                    \
    GGW_SINGLE_CODE(DOLLAR_SIGN, 0x24, ENUM)                                   \
    GGW_SINGLE_CODE(PERCENT_SYMBOL, 0x25, ENUM)                                \
    GGW_SINGLE_CODE(AMPERSAND, 0x26, ENUM)                                     \
    GGW_SINGLE_CODE(SINGLE_QUOTATION_MARK, 0x27, ENUM)                         \
    GGW_SINGLE_CODE(LEFT_PARENTHESIS, 0x28, ENUM)                              \
    GGW_SINGLE_CODE(RIGHT_PARENTHESIS, 0x29, ENUM)                             \
    GGW_SINGLE_CODE(ASTERISK, 0x2A, ENUM)                                      \
    GGW_SINGLE_CODE(PLUS_SIGN, 0x2B, ENUM)                                     \
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
    GGW_SINGLE_CODE(COLON, 0x3A, ENUM)                                         \
    GGW_SINGLE_CODE(SEMICOLON, 0x3B, ENUM)                                     \
    GGW_SINGLE_CODE(LESS_THAN_SIGN, 0x3C, ENUM)                                \
    GGW_SINGLE_CODE(EQUALS_SIGN, 0x3D, ENUM)                                   \
    GGW_SINGLE_CODE(GREATER_THAN_SIGN, 0x3E, ENUM)                             \
    GGW_SINGLE_CODE(QUESTION_MARK, 0x3F, ENUM)                                 \
    GGW_SINGLE_CODE(AT_SYMBOL, 0x40, ENUM)                                     \
    GGW_SINGLE_CODE(A_CAPITAL, 0x41, ENUM)                                     \
    GGW_SINGLE_CODE(B_CAPITAL, 0x42, ENUM)                                     \
    GGW_SINGLE_CODE(C_CAPITAL, 0x43, ENUM)                                     \
    GGW_SINGLE_CODE(D_CAPITAL, 0x44, ENUM)                                     \
    GGW_SINGLE_CODE(E_CAPITAL, 0x45, ENUM)                                     \
    GGW_SINGLE_CODE(F_CAPITAL, 0x46, ENUM)                                     \
    GGW_SINGLE_CODE(G_CAPITAL, 0x47, ENUM)                                     \
    GGW_SINGLE_CODE(H_CAPITAL, 0x48, ENUM)                                     \
    GGW_SINGLE_CODE(I_CAPITAL, 0x49, ENUM)                                     \
    GGW_SINGLE_CODE(J_CAPITAL, 0x4A, ENUM)                                     \
    GGW_SINGLE_CODE(K_CAPITAL, 0x4B, ENUM)                                     \
    GGW_SINGLE_CODE(L_CAPITAL, 0x4C, ENUM)                                     \
    GGW_SINGLE_CODE(M_CAPITAL, 0x4D, ENUM)                                     \
    GGW_SINGLE_CODE(N_CAPITAL, 0x4E, ENUM)                                     \
    GGW_SINGLE_CODE(O_CAPITAL, 0x4F, ENUM)                                     \
    GGW_SINGLE_CODE(P_CAPITAL, 0x50, ENUM)                                     \
    GGW_SINGLE_CODE(Q_CAPITAL, 0x51, ENUM)                                     \
    GGW_SINGLE_CODE(R_CAPITAL, 0x52, ENUM)                                     \
    GGW_SINGLE_CODE(S_CAPITAL, 0x53, ENUM)                                     \
    GGW_SINGLE_CODE(T_CAPITAL, 0x54, ENUM)                                     \
    GGW_SINGLE_CODE(U_CAPITAL, 0x55, ENUM)                                     \
    GGW_SINGLE_CODE(V_CAPITAL, 0x56, ENUM)                                     \
    GGW_SINGLE_CODE(W_CAPITAL, 0x57, ENUM)                                     \
    GGW_SINGLE_CODE(X_CAPITAL, 0x58, ENUM)                                     \
    GGW_SINGLE_CODE(Y_CAPITAL, 0x59, ENUM)                                     \
    GGW_SINGLE_CODE(Z_CAPITAL, 0x5A, ENUM)                                     \
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
    GGW_SINGLE_CODE(Z_LOWERCASE, 0x7A, ENUM)                                   \
    GGW_SINGLE_CODE(LEFT_CURLY_BRACE, 0x7B, ENUM)                              \
    GGW_SINGLE_CODE(UNIX_PIPE, 0x7C, ENUM)                                     \
    GGW_SINGLE_CODE(RIGHT_CURLY_BRACE, 0x7D, ENUM)                             \
    GGW_SINGLE_CODE(TILDE, 0x7E, ENUM)                                         \
    GGW_SINGLE_CODE(DELETE, 0x7F, ENUM)

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
