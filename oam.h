#include <assert.h>

struct obj {
  volatile unsigned short attr[3];
  volatile unsigned short _0;
};
static_assert((sizeof (struct obj)) == 8, "sizeof obj");

struct param {
  volatile unsigned short _0[3];
  volatile unsigned short pa;
  volatile unsigned short _1[3];
  volatile unsigned short pb;
  volatile unsigned short _2[3];
  volatile unsigned short pc;
  volatile unsigned short _3[3];
  volatile unsigned short pd;
};
static_assert((sizeof (struct param)) == 32, "sizeof param");

union oam {
  struct obj obj[128];
  struct param param[32];
};

extern union oam oam;
static_assert((sizeof (union oam)) == 1024, "sizeof oam");
static_assert((sizeof (oam.obj)) == 1024, "sizeof oam");
static_assert((sizeof (oam.param)) == 1024, "sizeof oam");
