OUTPUT_FORMAT("elf32-littlearm", "elf32-littlearm", "elf32-littlearm")
OUTPUT_ARCH(arm)
MEMORY
{
  sram  : ORIGIN = 0xe000000, LENGTH = 64K
  gprom : ORIGIN = 0x8000000, LENGTH = 32M
  iwram : ORIGIN = 0x3000000, LENGTH = 32K
  ewram : ORIGIN = 0x2000000, LENGTH = 256K
}
SECTIONS
{
  . = 0x8000000;

  .text ALIGN(4) : SUBALIGN(1)
  {
    KEEP(*(.rom.start_addr))
    KEEP(*(.rom.nintendo_logo))
    KEEP(*(.rom.header))
    *(.text.load)
  } >gprom AT> gprom

  /* text */

  . = 0x3000000;

  rom.text ALIGN(32) : SUBALIGN(4)
  {
    *(.text*)
    . = (. + 0x1f) & ~0x1f;
  } >iwram AT> gprom

  __text_link_start = ADDR(rom.text);
  __text_link_end = ADDR(rom.text) + SIZEOF(rom.text);
  __text_load_start = LOADADDR(rom.text);

  /* data */

  rom.data ALIGN(32) : SUBALIGN(4)
  {
    *(.data)
    . = (. + 0x1f) & ~0x1f;
  } >iwram AT> gprom

  __data_link_start = ADDR(rom.data);
  __data_link_end = ADDR(rom.data) + SIZEOF(rom.data);
  __data_load_start = LOADADDR(rom.data);

  /* rodata */

  rom.rodata ALIGN(32) : SUBALIGN(4)
  {
    *(.rodata)
    . = (. + 0x1f) & ~0x1f;
  } >iwram AT> gprom

  __rodata_link_start = ADDR(rom.rodata);
  __rodata_link_end = ADDR(rom.rodata) + SIZEOF(rom.rodata);
  __rodata_load_start = LOADADDR(rom.rodata);

  /* bss */

  bss ALIGN(32) (NOLOAD) : SUBALIGN(4)
  {
    *(.bss)
    . = (. + 0x1f) & ~0x1f;
  } >iwram

  __bss_link_start = ADDR(bss);
  __bss_link_end = ADDR(bss) + SIZEOF(bss);

  . = 0xe000000;

  sram ALIGN(32) (NOLOAD) : SUBALIGN(4)
  {
    *(.sram)
    . = (. + 0x1f) & ~0x1f;
  } >sram

  __sram_link_start = ADDR(sram);
  __sram_link_end = ADDR(sram) + SIZEOF(sram);

  . = 0x2000000;

  /* ewram */
  ewram ALIGN(32) (NOLOAD) : SUBALIGN(4)
  {
    KEEP(*(.ewram))
    . = (. + 0x1f) & ~0x1f;
  } >ewram

  __ewram_link_start = ADDR(ewram);
  __ewram_link_end = ADDR(ewram) + SIZEOF(ewram);

  rom.image : ALIGN(4) SUBALIGN(4)
  {
    *(.image*)
  } > gprom

  io_reg = 0x4000000;
  pram = 0x5000000;
  vram = 0x6000000;
  oam = 0x7000000;
}
