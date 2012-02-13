int prefix_is_exactly(char *, char*);
int prefix_is_delimited_by(char *, char *, char *, int);

#define DECLARE_MATCHER(name) \
int prefix_is_ ## name(char *)

#define DEFINE_SINGLE_CTYPE_MATCHER(type) \
int prefix_is_one_ ## type(char *src) \
  return is ## type(src[0]) ? 1 : 0; \
}

#define DEFINE_CTYPE_SEQUENCE_MATCHER(type) \
int prefix_is_ ## type ## s(char *src) { \
  int p = 0; \
  while (is ## type(src[p++])) ; \
  return p; \
}

#define DEFINE_DELIMITED_MATCHER(name, begin, end, escapable) \
int prefix_is_ ## name(char *src) { \
  return prefix_is_delimited_by(src, begin, end, escapable); \
}

#define DEFINE_TO_EOL_MATCHER(name, prefix) \
int prefix_is_ ## name(char *src) { \
  int p = prefix_is_exactly(src, prefix); \
  while (src[p] && src[p] != '\n') p++; \
  return p; \
}

DECLARE_MATCHER(spaces);
DECLARE_MATCHER(alphas);
DECLARE_MATCHER(digits);
DECLARE_MATCHER(xdigits);
DECLARE_MATCHER(alnums);
DECLARE_MATCHER(line_comment);
DECLARE_MATCHER(block_comment);
DECLARE_MATCHER(dqstring);
DECLARE_MATCHER(sqstring);
DECLARE_MATCHER(interpolant);
DECLARE_MATCHER(string_constant);
