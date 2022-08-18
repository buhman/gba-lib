import sys
from operator import itemgetter

def addresses():
    for line in sys.stdin:
        if not line.startswith('#define'):
            #sys.stdout.write(line)
            continue
        split = line.split()
        if len(split) < 3:
            #sys.stdout.write(line)
            continue
        else:
            _, name, address, *_ = split
            if not (address.startswith('0x')
                    and len(address) == 5):
                #sys.stdout.write(line)
                continue
            else:
                #continue
                yield name, int(address, 16)
    #yield 1, 2

registers = sorted(addresses(), key=itemgetter(1))

sys.stdout.write("#include \"base.h\"\n")
sys.stdout.write("struct io_reg {\n")

counter = 0
reserved = 0
for name, address in registers:
    if name == 'SIOMLT_SEND':
        continue

    if counter != 0 and counter != address:
        res_length = address - counter
        sys.stdout.write(f"  unsigned volatile short _reserved{reserved}[{res_length // 2}];\n")
        counter += res_length
        assert counter == address
        reserved += 1

    if name == 'SIODATA8':
        sys.stdout.write("  union {\n")
        sys.stdout.write("    unsigned volatile short SIODATA8;\n")
        sys.stdout.write("    unsigned volatile short SIOMLT_SEND;\n")
        sys.stdout.write("  };\n")
    elif name == 'HALTCNT':
        sys.stdout.write(f"  unsigned volatile char _reserved{reserved};\n")
        sys.stdout.write(f"  unsigned volatile char {name};\n")
        reserved += 1
    else:
        assert name != 1
        sys.stdout.write(f"  unsigned volatile short {name};\n")
    counter += 2

sys.stdout.write("};\n")

sys.stdout.write("extern struct io_reg io_reg;\n\n")
sys.stdout.write("#include <stddef.h>\n")
sys.stdout.write("#include <assert.h>\n")
for name, address in registers:
    sys.stdout.write(f"static_assert(offsetof(struct io_reg, {name}) == {address});\n")
