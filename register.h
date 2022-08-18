/* 4 LCD Status */
#define DISPSTAT 0x004
#define VCOUNT 0x006

/* 5 Image System */
#define DISPCNT 0x000

/* 6 Rendering Functions */
#define BG0CNT 0x008
#define BG1CNT 0x00a
#define BG2CNT 0x00c
#define BG3CNT 0x00e

#define MOSAIC 0x04c

/* 6.1.7 BG Rotation and Scaling Features */
#define BG2PA 0x020
#define BG2PB 0x022
#define BG2PC 0x024
#define BG2PD 0x026
#define BG2X_L 0x028
#define BG2X_H 0x02a
#define BG2Y_L 0x02c
#define BG2Y_H 0x02e

#define BG3PA 0x030
#define BG3PB 0x032
#define BG3PC 0x034
#define BG3PD 0x036
#define BG3X_L 0x038
#define BG3X_H 0x03a
#define BG3Y_L 0x03c
#define BG3Y_H 0x03e


/* 6.1.8 BG Scrolling */
#define BG0HOFS 0x010
#define BG0VOFS 0x012
#define BG1HOFS 0x014
#define BG1VOFS 0x016
#define BG2HOFS 0x018
#define BG2VOFS 0x01a
#define BG3HOFS 0x01c
#define BG3VOFS 0x01e

/* 8 Window Feature */
#define WIN0H 0x040
#define WIN1H 0x042
#define WIN0V 0x044
#define WIN1V 0x046
#define WININ 0x048
#define WINOUT 0x04a

/* 9 Color Special Effects */
#define BLDCNT 0x050
#define BLD_ALPHA 0x052
#define BLDY 0x054

/* 14 Key Input */
#define KEY_INPUT 0x130

#define KEYCNT 0x132

/* 15 Interrupt Control */
#define IME 0x208

#define IE  0x200

#define IF  0x202

/* sound */

#define SOUND1_CNT_L 0x060

#define SOUND1_CNT_H 0x062

#define SOUND1_CNT_X 0x064

#define SOUND2_CNT_L 0x068

#define SOUND2_CNT_H 0x06c

#define SOUND3_CNT_L 0x070

#define SOUND3_CNT_H 0x072

#define SOUND3_CNT_X 0x074

#define WAVE_RAM0_L 0x090
#define WAVE_RAM0_H 0x092
#define WAVE_RAM1_L 0x094
#define WAVE_RAM1_H 0x096
#define WAVE_RAM2_L 0x098
#define WAVE_RAM2_H 0x09a
#define WAVE_RAM3_L 0x09c
#define WAVE_RAM3_H 0x09e

#define SOUND4_CNT_L 0x078

#define SOUND4_CNT_H 0x07c

#define SOUNDCNT_L 0x080

#define SOUNDCNT_H 0x082

#define SOUNDCNT_X 0x084

#define SOUNDBIAS 0x088

#define FIFO_A_L 0x0a0
#define FIFO_A_H 0x0a2
#define FIFO_B_L 0x0a4
#define FIFO_B_H 0x0a6

/* timers */

#define TM0CNT_L 0x100
#define TM1CNT_L 0x104
#define TM2CNT_L 0x108
#define TM3CNT_L 0x10c

#define TM0CNT_H 0x102
#define TM1CNT_H 0x106
#define TM2CNT_H 0x10a
#define TM3CNT_H 0x10e

/* 12.1 DMA 0 */
#define DMA0_SAD_L 0x0b0 /* source address */
#define DMA0_SAD_H 0x0b2

#define DMA0_DAD_L 0x0b4 /* destination address */
#define DMA0_DAD_H 0x0b6

#define DMA0_CNT_L 0x0b8 /* word count */

#define DMA0_CNT_H 0x0ba /* control */

/* 12.2 DMA 1 */
#define DMA1_SAD_L 0x0bc /* source address */
#define DMA1_SAD_H 0x0be

#define DMA1_DAD_L 0x0c0 /* destination address */
#define DMA1_DAD_H 0x0c2

#define DMA1_CNT_L 0x0c4 /* word count */

#define DMA1_CNT_H 0x0c6 /* control */

/* 12.2 DMA 2 */
#define DMA2_SAD_L 0x0c8 /* source address */
#define DMA2_SAD_H 0x0ca

#define DMA2_DAD_L 0x0cc /* destination address */
#define DMA2_DAD_H 0x0ce

#define DMA2_CNT_L 0x0d0 /* word count */

#define DMA2_CNT_H 0x0d2 /* control */

/* 12.2 DMA 3 */
#define DMA3_SAD_L 0x0d4 /* source address */
#define DMA3_SAD_H 0x0d6

#define DMA3_DAD_L 0x0d8 /* destination address */
#define DMA3_DAD_H 0x0da

#define DMA3_CNT_L 0x0dc /* word count */

#define DMA3_CNT_H 0x0de /* control */

/* 3.2.2 Game Pak Memory */
#define WAITCNT 0x204

/* 16 Power Down */
#define HALTCNT 0x301 /* 1 byte */

/* 13 UART Communication Functions */
#define SIODATA8 0x12a

#define SIOCNT 0x128

/* 13.2 16-Bit Multi-player Communication */
#define SIOMLT_SEND 0x12a
#define SIO_MULTI0 0x120
#define SIO_MULTI1 0x122
#define SIO_MULTI2 0x124
#define SIO_MULTI3 0x126

/* 13.4 General Purpose Communication */
#define RCNT 0x134
