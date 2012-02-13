enum sss_type {
  ATOM,
  SEQUENCE,
  CHOICE,
  OPTION,
  AT_LEAST_ZERO,
  AT_LEAST_ONE,
  AT_LEAST_N,
  AT_MOST_N,
  EXACTLY_N,
  END
};
  

typedef struct {
  sss_type tag;
  int (*matcher)(char *);
} sss_component;

typedef struct {
  int length;
  sss_component *body;
} sss_pattern;

