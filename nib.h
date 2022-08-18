static inline unsigned int nib_32(unsigned int n)
{
  return
    ( (n << 28)
    | (n << 24)
    | (n << 20)
    | (n << 16)
    | (n << 12)
    | (n <<  8)
    | (n <<  4)
    | (n      )
    );
}

static inline unsigned int nib_16(unsigned int n)
{
  return
    ( (n << 12)
    | (n <<  8)
    | (n <<  4)
    | (n      )
    );
}

static inline unsigned int byte_32(unsigned int n)
{
  return
    ( (n << 24)
    | (n << 16)
    | (n <<  8)
    | (n      )
    );
}

static inline unsigned int half_32(unsigned int n)
{
  return
    ( (n << 16)
    | (n      )
    );
}
