void copy_16(void * dest, const void * src, unsigned int n)
{
  while (n > 1) {
    *((unsigned short *)dest) = *((unsigned short *)src);
    dest += 2;
    src += 2;
    n -= 2;
  }
}

void copy_32(void * dest, const void * src, unsigned int n)
{
  while (n > 1) {
    *((unsigned int *)dest) = *((unsigned int *)src);
    dest += 4;
    src += 4;
    n -= 4;
  }
}

void fill_16(void * dest, unsigned short c, unsigned int n)
{
  while (n > 1) {
    *((unsigned short *)dest) = c;
    dest += 2;
    n -= 2;
  }
}

void fill_32(void * dest, unsigned int c, unsigned int n)
{
  while (n > 1) {
    *((unsigned int *)dest) = c;
    dest += 4;
    n -= 4;
  }
}
