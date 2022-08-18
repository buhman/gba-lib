#include <assert.h>
#include "base.h"

struct pram {
  volatile unsigned short bg[16][16];
  volatile unsigned short obj[16][16];
};
extern struct pram pram;

static_assert((sizeof (pram)) == 0x400, "sizeof pram");
static_assert((sizeof (pram.bg)) == 0x200, "sizeof pram bg");
static_assert((sizeof (pram.obj)) == 0x200, "sizeof pram obj");


static inline unsigned int tile(unsigned int n) {
  return n * 16;
}

typedef volatile unsigned short character_block[8192];
static_assert((sizeof (character_block)) == 0x4000, "sizeof character_block");

typedef volatile unsigned short obj_block[16384];
static_assert((sizeof (obj_block)) == 0x8000, "sizeof obj_block");

typedef volatile unsigned short screen_block[1024];
static_assert((sizeof (screen_block)) == 0x800, "sizeof screen_block");

struct vram {
  union {
    character_block character_block[4];
    screen_block screen_block[32];
  };
  obj_block obj;
};
static_assert((sizeof (struct vram)) == 0x18000, "sizeof vram");

extern struct vram vram;
