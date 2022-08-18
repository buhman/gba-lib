        /* 18 ROM Registration Data */
        .section .rom.start_addr
        b load
        .section .rom.nintendo_logo
        .include "nintendo.s"
        .section .rom.header
        .fill 12,1,0x0 /* Game Title */
        .fill 4,1,0x0  /* Game Code */
        .fill 2,1,0x0  /* Maker Code */
        .byte 0x96
        .byte 0x0      /* Main Unit Code */
        .byte 0x0      /* Device Type */
        .fill 7,1,0x0  /* Reserved Area */
        .byte 0x0      /* Mask ROM Version Number */
        .byte 0x51     /* Complement Check */
        .fill 2,1,0x0  /* Reserved Area */
