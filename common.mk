ARCH ?= -mthumb-interwork -march=armv4t
CFLAGS ?= -std=gnu2x -g -O0 -Wall -Werror -Wno-error=unused-variable -Wno-error=unused-label -fshort-enums -Wno-error=unused-const-variable -I$(PWD)
CARCH ?= -mtune=arm7tdmi -ffreestanding -nostdlib
AFLAGS ?= -g

TARGET ?= arm-none-eabi-
CC = $(TARGET)gcc
AS = $(TARGET)as
LD = $(TARGET)ld
OBJCOPY = $(TARGET)objcopy
OBJDUMP = $(TARGET)objdump
M4 = m4

define BUILD_BINARY_O
	$(OBJCOPY) \
		-I binary -O elf32-littlearm -B armv4t \
		--rename-section .data=.rodata,alloc,load,readonly,data,contents \
		$< $@
endef

define BUILD_BINARY_IMAGE_O
	$(OBJCOPY) \
		-I binary -O elf32-littlearm -B armv4t \
		--rename-section .data=.image,alloc,load,readonly,data,contents \
		$< $@
endef

define LINK_ELF
	$(LD) --print-memory-usage -Map=$@.map -T $(1) $^ -o $@
endef

%.o: %.S
	$(CC) $(ARCH) $(AFLAGS) -c $< -o $@

%.o: %.s
	$(AS) $(ARCH) $(AFLAGS) $< -o $@

%.o: %.c $(HEADERS)
	$(CC) $(ARCH) $(CARCH) $(CFLAGS) -c $< -o $@

%.elf: %.o
	$(LD) $< -o $@

%.gba: %.elf
	$(OBJCOPY) -O binary $< $@

dump:
	$(OBJDUMP) -D -j .text $(F)

clean:
	find -regextype posix-extended \
		-regex '.*\.(o|out|hex|elf|gba|glyph|binlst|gch)' \
		-exec rm -f {} \;

deploy:
	mount /dev/disk/by-label/GBA /mnt
	cp $< /mnt/$(notdir $<)
	umount /mnt
	sync

.SUFFIXES:
.INTERMEDIATE:
.SECONDARY:
.PHONY: all clean dump
