#ifndef GGW_KEYCODES_H
#define GGW_KEYCODES_H

#define GGW_SINGLE_CODE1(CODE, VAL) GGW_KEY_ ## CODE = VAL,
#define GGW_SINGLE_CODE0(CODE, VAL) case VAL: \
  return #CODE;
#define GGW_SINGLE_CODE(CODE, VAL, ENUM) GGW_SINGLE_CODE##ENUM(CODE, VAL)

/*
 * Keycodes are defined here, using a name and a ASCII keycode number
 * 
 * ENUM is 1 if we are defining these values in an enum, and 0 if we are defining them in a switch statement mapping values to names
 */
#define GGW_ALL_CODES(ENUM) \
  GGW_SINGLE_CODE(SPACE, 0x20, ENUM) \
  GGW_SINGLE_CODE(EXCLAMATION_MARK, 0x21, ENUM) \
  GGW_SINGLE_CODE(DOUBLE_QUOTATION_MARK, 0x22, ENUM) \
// TODO fill out the rest of these...

typedef enum {
  // Macro, expands from the above
  GGW_ALL_CODES(1)
} GGW_Keycode;

inline const char* GGW_getKeycodeName(GGW_Keycode code) {
  switch(code) {
    // Another macro, once again expands from the above
    GGW_ALL_CODES(0)
  }
  return (const char*) 0;
}

// typedef enum {
//   GGW_KEY_SPACE = ' ',
//   GGW_KEY_EXCLAMATION_MARK = '!',
//   GGW_KEY_DOUBLE_QUOTATION_MARK = '\"',
//   GGW_KEY_HASH = '#',
//   GGW_KEY_DOLLAR_SIGN = '$',
//   GGW_KEY_PERCENT = '%',
//   GGW_KEY_AMPERSAND = '&',
//   GGW_KEY_SINGLE_QUOTATION_MARK = '\'',
//   GGW_KEY_LEFT_PAREN = '(',
//   GGW_KEY_RIGHT_PAREN = ')',
//   GGW_KEY_ASTERISK = '*',
//   GGW_KEY_PLUS = '+',
//   GGW_KEY_COMMA = ',',
//   GGW_KEY_DASH = '-',
//   GGW_KEY_PERIOD = '.',
//   GGW_KEY_SLASH = '/',
//   GGW_KEY_ZERO = '0',
//   GGW_KEY_ONE = '1',
//   GGW_KEY_TWO = '2',
//   GGW_KEY_THREE = '3',
//   GGW_KEY_FOUR = '4',
//   GGW_KEY_FIVE = '5',
//   GGW_KEY_SIX = '6',
//   GGW_KEY_SEVEN = '7',
//   GGW_KEY_EIGHT = '8',
//   GGW_KEY_NINE = '9',
//   GGW_KEY_COLON = ':',
//   GGW_KEY_SEMICOLON = ';',
//   GGW_KEY_LESS_THAN = '<',
//   GGW_KEY_GREATER_THAN = '>',
//   GGW_KEY_
//   GGW_KEY_A = 'A',
//   GGW_KEY_B = 'B',
//   GGW_KEY_C = 'C',
//   GGW_KEY_D = 'D',
//
// } GGW_Keycode;

#endif // GGW_KEYCODES_H
