/* SPDX-License-Identifier: GPL-2.0
 * SEP Index values mapped to awinic chipset index based on group type.
 */

static unsigned short sep_to_aw8622x_index_mapping[128] = {
	/* 0 */		0,   /* None Mapped         */
	/* 1 */		1,   /* aw8622x_haptic.bin  */
	/* 2 */		112, /* RTP107_RTP.bin      */
	/* 3 */		6,   /* RTP1_RTP.bin        */
	/* 4 */		7,   /* RTP2_RTP.bin        */
	/* 5 */		8,   /* RTP3_RTP.bin        */
	/* 6 */		1,   /* aw8622x_haptic.bin  */
	/* 7 */		9,   /* RTP4_RTP.bin        */
	/* 8 */		10,  /* RTP5_RTP.bin        */
	/* 9 */		11,  /* RTP6_RTP.bin        */
	/* 10 */	12,  /* RTP7_RTP.bin        */
	/* 11 */	13,  /* RTP8_RTP.bin        */
	/* 12 */	14,  /* RTP9_RTP.bin        */
	/* 13 */	15,  /* RTP10_RTP.bin       */
	/* 14 */	4,   /* aw8622x_haptic.bin  */
	/* 15 */	4,   /* aw8622x_haptic.bin  */
	/* 16 */	4,   /* aw8622x_haptic.bin  */
	/* 17 */	16,  /* RTP11_RTP.bin       */
	/* 18 */	17,  /* RTP12_RTP.bin       */
	/* 19 */	18,  /* RTP13_RTP.bin       */
	/* 20 */	19,  /* RTP14_RTP.bin       */
	/* 21 */	20,  /* RTP15_RTP.bin       */
	/* 22 */	21,  /* RTP16_RTP.bin       */
	/* 23 */	22,  /* RTP17_RTP.bin       */
	/* 24 */	1,   /* aw8622x_haptic.bin  */
	/* 25 */	23,  /* RESERVED_RTP.bin    */
	/* 26 */	1,   /* aw8622x_haptic.bin  */
	/* 27 */	24,  /* RTP19_RTP.bin       */
	/* 28 */	25,  /* RESERVED_RTP.bin    */
	/* 29 */	26,  /* RESERVED_RTP.bin    */
	/* 30 */	27,  /* RESERVED_RTP.bin    */
	/* 31 */	28,  /* RESERVED_RTP.bin    */
	/* 32 */	29,  /* RTP24_RTP.bin       */
	/* 33 */	1,   /* aw8622x_haptic.bin  */
	/* 34 */	30,  /* RTP25_RTP.bin       */
	/* 35 */	31,  /* RESERVED_RTP.bin    */
	/* 36 */	32,  /* RESERVED_RTP.bin    */
	/* 37 */	1,   /* aw8622x_haptic.bin  */
	/* 38 */	1,   /* aw8622x_haptic.bin  */
	/* 39 */	33,  /* RTP28_RTP.bin       */
	/* 40 */	1,   /* aw8622x_haptic.bin  */
	/* 41 */	2,   /* aw8622x_haptic.bin  */
	/* 42 */	1,   /* aw8622x_haptic.bin  */
	/* 43 */	1,   /* aw8622x_haptic.bin  */
	/* 44 */	1,   /* aw8622x_haptic.bin  */
	/* 45 */	34,  /* RTP29_RTP.bin       */
	/* 46 */	35,  /* RTP30_RTP.bin       */
	/* 47 */	36,  /* RTP31_RTP.bin       */
	/* 48 */	37,  /* RTP32_RTP.bin       */
	/* 49 */	38,  /* RTP33_RTP.bin       */
	/* 50 */	39,  /* RTP34_RTP.bin       */
	/* 51 */	4,   /* aw8622x_haptic.bin  */
	/* 52 */	40,  /* RTP35_RTP.bin       */
	/* 53 */	41,  /* RESERVED_RTP.bin    */
	/* 54 */	42,  /* RESERVED_RTP.bin    */
	/* 55 */	43,  /* RESERVED_RTP.bin    */
	/* 56 */	44,  /* RTP39_RTP.bin       */
	/* 57 */	45,  /* RTP40_RTP.bin       */
	/* 58 */	46,  /* RTP41_RTP.bin       */
	/* 59 */	47,  /* RTP42_RTP.bin       */
	/* 60 */	48,  /* RESERVED_RTP.bin    */
	/* 61 */	49,  /* RESERVED_RTP.bin    */
	/* 62 */	50,  /* RESERVED_RTP.bin    */
	/* 63 */	51,  /* RESERVED_RTP.bin    */
	/* 64 */	52,  /* RTP47_RTP.bin       */
	/* 65 */	53,  /* RTP48_RTP.bin       */
	/* 66 */	4,   /* aw8622x_haptic.bin  */
	/* 67 */	54,  /* RESERVED_RTP.bin    */
	/* 68 */	55,  /* RTP50_RTP.bin       */
	/* 69 */	56,  /* RTP51_RTP.bin       */
	/* 70 */	57,  /* RTP52_RTP.bin       */
	/* 71 */	58,  /* RTP53_RTP.bin       */
	/* 72 */	59,  /* RTP54_RTP.bin       */
	/* 73 */	60,  /* RTP55_RTP.bin       */
	/* 74 */	61,  /* RTP56_RTP.bin       */
	/* 75 */	62,  /* RTP57_RTP.bin       */
	/* 76 */	63,  /* RTP58_RTP.bin       */
	/* 77 */	64,  /* RTP59_RTP.bin       */
	/* 78 */	65,  /* RTP60_RTP.bin       */
	/* 79 */	66,  /* RTP61_RTP.bin       */
	/* 80 */	67,  /* RTP62_RTP.bin       */
	/* 81 */	68,  /* RTP63_RTP.bin       */
	/* 82 */	69,  /* RTP64_RTP.bin       */
	/* 83 */	4,   /* aw8622x_haptic.bin  */
	/* 84 */	70,  /* RTP65_RTP.bin       */
	/* 85 */	71,  /* RTP66_RTP.bin       */
	/* 86 */	72,  /* RTP67_RTP.bin       */
	/* 87 */	73,  /* RTP68_RTP.bin       */
	/* 88 */	74,  /* RTP69_RTP.bin       */
	/* 89 */	75,  /* RTP70_RTP.bin       */
	/* 90 */	76,  /* RTP71_RTP.bin       */
	/* 91 */	77,  /* RTP72_RTP.bin       */
	/* 92 */	78,  /* RTP73_RTP.bin       */
	/* 93 */	79,  /* RTP74_RTP.bin       */
	/* 94 */	80,  /* RTP75_RTP.bin       */
	/* 95 */	81,  /* RTP76_RTP.bin       */
	/* 96 */	82,  /* RTP77_RTP.bin       */
	/* 97 */	83,  /* RTP78_RTP.bin       */
	/* 98 */	84,  /* RTP79_RTP.bin       */
	/* 99 */	85,  /* RTP80_RTP.bin       */
	/* 100 */	86,  /* RESERVED_RTP.bin    */
	/* 101 */	87,  /* RTP82_RTP.bin       */
	/* 102 */	88,  /* RTP83_RTP.bin       */
	/* 103 */	89,  /* RTP84_RTP.bin       */
	/* 104 */	90,  /* RTP85_RTP.bin       */
	/* 105 */	91,  /* RTP86_RTP.bin       */
	/* 106 */	92,  /* RTP87_RTP.bin       */
	/* 107 */	93,  /* RTP88_RTP.bin       */
	/* 108 */	94,  /* RTP89_RTP.bin       */
	/* 109 */	95,  /* RTP90_RTP.bin       */
	/* 110 */	96,  /* RTP91_RTP.bin       */
	/* 111 */	97,  /* RTP92_RTP.bin       */
	/* 112 */	98,  /* RTP93_RTP.bin       */
	/* 113 */	99,  /* RTP94_RTP.bin       */
	/* 114 */	100, /* RTP95_RTP.bin       */
	/* 115 */	101, /* RTP96_RTP.bin       */
	/* 116 */	102, /* RTP97_RTP.bin       */
	/* 117 */	103, /* RTP98_RTP.bin       */
	/* 118 */	104, /* RTP99_RTP.bin       */
	/* 119 */	105, /* RTP100_RTP.bin      */
	/* 120 */	106, /* RTP101_RTP.bin      */
	/* 121 */	107, /* RTP102_RTP.bin      */
	/* 122 */	108, /* RTP103_RTP.bin      */
	/* 123 */	109, /* RTP104_RTP.bin      */
	/* 124 */	110, /* RTP105_RTP.bin      */
	/* 125 */	111, /* RTP106_RTP.bin      */
	/* 126 */	113, /* RTP108_RTP.bin      */
	/* 127 */	114, /* RTP109_RTP.bin      */
};
