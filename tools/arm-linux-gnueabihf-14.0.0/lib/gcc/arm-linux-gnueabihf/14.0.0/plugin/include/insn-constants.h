/* Generated automatically by the program `genconstants'
   from the machine description file `md'.  */

#ifndef GCC_INSN_CONSTANTS_H
#define GCC_INSN_CONSTANTS_H

#define WCGR0 96
#define DOM_CC_X_AND_Y 0
#define WCGR1 97
#define SP_REGNUM 13
#define APSRGE_REGNUM 105
#define VFPCC_REGNUM 101
#define CMP_CMN 2
#define CMP_CMP 0
#define NUM_OF_COND_CMP 4
#define R0_REGNUM 0
#define VPR_REGNUM 106
#define RA_AUTH_CODE 107
#define DOM_CC_X_OR_Y 2
#define APSRQ_REGNUM 104
#define CMN_CMN 3
#define CMN_CMP 1
#define FDPIC_REGNUM 9
#define CC_REGNUM 100
#define LAST_ARM_REGNUM 15
#define PC_REGNUM 15
#define R4_REGNUM 4
#define LR_REGNUM 14
#define R1_REGNUM 1
#define DOM_CC_NX_OR_Y 1
#define IP_REGNUM 12
#define WCGR2 98
#define WCGR3 99

enum unspec {
  UNSPEC_PUSH_MULT = 0,
  UNSPEC_PIC_SYM = 1,
  UNSPEC_PIC_BASE = 2,
  UNSPEC_PRLG_STK = 3,
  UNSPEC_REGISTER_USE = 4,
  UNSPEC_CHECK_ARCH = 5,
  UNSPEC_WSHUFH = 6,
  UNSPEC_WACC = 7,
  UNSPEC_TMOVMSK = 8,
  UNSPEC_WSAD = 9,
  UNSPEC_WSADZ = 10,
  UNSPEC_WMACS = 11,
  UNSPEC_WMACU = 12,
  UNSPEC_WMACSZ = 13,
  UNSPEC_WMACUZ = 14,
  UNSPEC_CLRDI = 15,
  UNSPEC_WALIGNI = 16,
  UNSPEC_TLS = 17,
  UNSPEC_PIC_LABEL = 18,
  UNSPEC_PIC_OFFSET = 19,
  UNSPEC_GOTSYM_OFF = 20,
  UNSPEC_THUMB1_CASESI = 21,
  UNSPEC_RBIT = 22,
  UNSPEC_SYMBOL_OFFSET = 23,
  UNSPEC_MEMORY_BARRIER = 24,
  UNSPEC_UNALIGNED_LOAD = 25,
  UNSPEC_UNALIGNED_STORE = 26,
  UNSPEC_PIC_UNIFIED = 27,
  UNSPEC_Q_SET = 28,
  UNSPEC_GE_SET = 29,
  UNSPEC_APSR_READ = 30,
  UNSPEC_LL = 31,
  UNSPEC_VRINTZ = 32,
  UNSPEC_VRINTP = 33,
  UNSPEC_VRINTM = 34,
  UNSPEC_VRINTR = 35,
  UNSPEC_VRINTX = 36,
  UNSPEC_VRINTA = 37,
  UNSPEC_PROBE_STACK = 38,
  UNSPEC_NONSECURE_MEM = 39,
  UNSPEC_SP_SET = 40,
  UNSPEC_SP_TEST = 41,
  UNSPEC_PIC_RESTORE = 42,
  UNSPEC_SXTAB16 = 43,
  UNSPEC_UXTAB16 = 44,
  UNSPEC_SXTB16 = 45,
  UNSPEC_UXTB16 = 46,
  UNSPEC_QADD8 = 47,
  UNSPEC_QSUB8 = 48,
  UNSPEC_SHADD8 = 49,
  UNSPEC_SHSUB8 = 50,
  UNSPEC_UHADD8 = 51,
  UNSPEC_UHSUB8 = 52,
  UNSPEC_UQADD8 = 53,
  UNSPEC_UQSUB8 = 54,
  UNSPEC_QADD16 = 55,
  UNSPEC_QASX = 56,
  UNSPEC_QSAX = 57,
  UNSPEC_QSUB16 = 58,
  UNSPEC_SHADD16 = 59,
  UNSPEC_SHASX = 60,
  UNSPEC_SHSAX = 61,
  UNSPEC_SHSUB16 = 62,
  UNSPEC_UHADD16 = 63,
  UNSPEC_UHASX = 64,
  UNSPEC_UHSAX = 65,
  UNSPEC_UHSUB16 = 66,
  UNSPEC_UQADD16 = 67,
  UNSPEC_UQASX = 68,
  UNSPEC_UQSAX = 69,
  UNSPEC_UQSUB16 = 70,
  UNSPEC_SMUSD = 71,
  UNSPEC_SMUSDX = 72,
  UNSPEC_USAD8 = 73,
  UNSPEC_USADA8 = 74,
  UNSPEC_SMLALD = 75,
  UNSPEC_SMLALDX = 76,
  UNSPEC_SMLSLD = 77,
  UNSPEC_SMLSLDX = 78,
  UNSPEC_SMLAWB = 79,
  UNSPEC_SMLAWT = 80,
  UNSPEC_SEL = 81,
  UNSPEC_SADD8 = 82,
  UNSPEC_SSUB8 = 83,
  UNSPEC_UADD8 = 84,
  UNSPEC_USUB8 = 85,
  UNSPEC_SADD16 = 86,
  UNSPEC_SASX = 87,
  UNSPEC_SSAX = 88,
  UNSPEC_SSUB16 = 89,
  UNSPEC_UADD16 = 90,
  UNSPEC_UASX = 91,
  UNSPEC_USAX = 92,
  UNSPEC_USUB16 = 93,
  UNSPEC_SMLAD = 94,
  UNSPEC_SMLADX = 95,
  UNSPEC_SMLSD = 96,
  UNSPEC_SMLSDX = 97,
  UNSPEC_SMUAD = 98,
  UNSPEC_SMUADX = 99,
  UNSPEC_SSAT16 = 100,
  UNSPEC_USAT16 = 101,
  UNSPEC_CDE = 102,
  UNSPEC_CDEA = 103,
  UNSPEC_VCDE = 104,
  UNSPEC_VCDEA = 105,
  UNSPEC_DLS = 106,
  UNSPEC_PAC_NOP = 107,
  UNSPEC_WADDC = 108,
  UNSPEC_WABS = 109,
  UNSPEC_WQMULWMR = 110,
  UNSPEC_WQMULMR = 111,
  UNSPEC_WQMULWM = 112,
  UNSPEC_WQMULM = 113,
  UNSPEC_WQMIAxyn = 114,
  UNSPEC_WQMIAxy = 115,
  UNSPEC_TANDC = 116,
  UNSPEC_TORC = 117,
  UNSPEC_TORVSC = 118,
  UNSPEC_TEXTRC = 119,
  UNSPEC_GET_FPSCR_NZCVQC = 120,
  UNSPEC_ASHIFT_SIGNED = 121,
  UNSPEC_ASHIFT_UNSIGNED = 122,
  UNSPEC_CRC32B = 123,
  UNSPEC_CRC32H = 124,
  UNSPEC_CRC32W = 125,
  UNSPEC_CRC32CB = 126,
  UNSPEC_CRC32CH = 127,
  UNSPEC_CRC32CW = 128,
  UNSPEC_AESD = 129,
  UNSPEC_AESE = 130,
  UNSPEC_AESIMC = 131,
  UNSPEC_AESMC = 132,
  UNSPEC_AES_PROTECT = 133,
  UNSPEC_SHA1C = 134,
  UNSPEC_SHA1M = 135,
  UNSPEC_SHA1P = 136,
  UNSPEC_SHA1H = 137,
  UNSPEC_SHA1SU0 = 138,
  UNSPEC_SHA1SU1 = 139,
  UNSPEC_SHA256H = 140,
  UNSPEC_SHA256H2 = 141,
  UNSPEC_SHA256SU0 = 142,
  UNSPEC_SHA256SU1 = 143,
  UNSPEC_VMULLP64 = 144,
  UNSPEC_LOAD_COUNT = 145,
  UNSPEC_VABAL_S = 146,
  UNSPEC_VABAL_U = 147,
  UNSPEC_VABD_F = 148,
  UNSPEC_VABD_S = 149,
  UNSPEC_VABD_U = 150,
  UNSPEC_VABDL_S = 151,
  UNSPEC_VABDL_U = 152,
  UNSPEC_VADD = 153,
  UNSPEC_VADDHN = 154,
  UNSPEC_VRADDHN = 155,
  UNSPEC_VADDL_S = 156,
  UNSPEC_VADDL_U = 157,
  UNSPEC_VADDW_S = 158,
  UNSPEC_VADDW_U = 159,
  UNSPEC_VBSL = 160,
  UNSPEC_VCAGE = 161,
  UNSPEC_VCAGT = 162,
  UNSPEC_VCALE = 163,
  UNSPEC_VCALT = 164,
  UNSPEC_VCEQ = 165,
  UNSPEC_VCGE = 166,
  UNSPEC_VCGEU = 167,
  UNSPEC_VCGT = 168,
  UNSPEC_VCGTU = 169,
  UNSPEC_VCLS = 170,
  UNSPEC_VCONCAT = 171,
  UNSPEC_VCVT = 172,
  UNSPEC_VCVT_S = 173,
  UNSPEC_VCVT_U = 174,
  UNSPEC_VCVT_S_N = 175,
  UNSPEC_VCVT_U_N = 176,
  UNSPEC_VCVT_HF_S_N = 177,
  UNSPEC_VCVT_HF_U_N = 178,
  UNSPEC_VCVT_SI_S_N = 179,
  UNSPEC_VCVT_SI_U_N = 180,
  UNSPEC_VCVTH_S = 181,
  UNSPEC_VCVTH_U = 182,
  UNSPEC_VCVTA_S = 183,
  UNSPEC_VCVTA_U = 184,
  UNSPEC_VCVTM_S = 185,
  UNSPEC_VCVTM_U = 186,
  UNSPEC_VCVTN_S = 187,
  UNSPEC_VCVTN_U = 188,
  UNSPEC_VCVTP_S = 189,
  UNSPEC_VCVTP_U = 190,
  UNSPEC_VEXT = 191,
  UNSPEC_VHADD_S = 192,
  UNSPEC_VHADD_U = 193,
  UNSPEC_VRHADD_S = 194,
  UNSPEC_VRHADD_U = 195,
  UNSPEC_VHSUB_S = 196,
  UNSPEC_VHSUB_U = 197,
  UNSPEC_VLD1 = 198,
  UNSPEC_VLD1_LANE = 199,
  UNSPEC_VLD2 = 200,
  UNSPEC_VLD2_DUP = 201,
  UNSPEC_VLD2_LANE = 202,
  UNSPEC_VLD3 = 203,
  UNSPEC_VLD3A = 204,
  UNSPEC_VLD3B = 205,
  UNSPEC_VLD3_DUP = 206,
  UNSPEC_VLD3_LANE = 207,
  UNSPEC_VLD4 = 208,
  UNSPEC_VLD4A = 209,
  UNSPEC_VLD4B = 210,
  UNSPEC_VLD4_DUP = 211,
  UNSPEC_VLD4_LANE = 212,
  UNSPEC_VMAX = 213,
  UNSPEC_VMAX_U = 214,
  UNSPEC_VMAXNM = 215,
  UNSPEC_VMIN = 216,
  UNSPEC_VMIN_U = 217,
  UNSPEC_VMINNM = 218,
  UNSPEC_VMLA = 219,
  UNSPEC_VMLA_LANE = 220,
  UNSPEC_VMLAL_S = 221,
  UNSPEC_VMLAL_U = 222,
  UNSPEC_VMLAL_S_LANE = 223,
  UNSPEC_VMLAL_U_LANE = 224,
  UNSPEC_VMLS = 225,
  UNSPEC_VMLS_LANE = 226,
  UNSPEC_VMLSL_S = 227,
  UNSPEC_VMLSL_U = 228,
  UNSPEC_VMLSL_S_LANE = 229,
  UNSPEC_VMLSL_U_LANE = 230,
  UNSPEC_VMLSL_LANE = 231,
  UNSPEC_VFMA_LANE = 232,
  UNSPEC_VFMS_LANE = 233,
  UNSPEC_VMOVL_S = 234,
  UNSPEC_VMOVL_U = 235,
  UNSPEC_VMOVN = 236,
  UNSPEC_VMUL = 237,
  UNSPEC_VMULL_P = 238,
  UNSPEC_VMULL_S = 239,
  UNSPEC_VMULL_U = 240,
  UNSPEC_VMUL_LANE = 241,
  UNSPEC_VMULL_S_LANE = 242,
  UNSPEC_VMULL_U_LANE = 243,
  UNSPEC_VPADAL_S = 244,
  UNSPEC_VPADAL_U = 245,
  UNSPEC_VPADD = 246,
  UNSPEC_VPADDL_S = 247,
  UNSPEC_VPADDL_U = 248,
  UNSPEC_VPMAX = 249,
  UNSPEC_VPMAX_U = 250,
  UNSPEC_VPMIN = 251,
  UNSPEC_VPMIN_U = 252,
  UNSPEC_VPSMAX = 253,
  UNSPEC_VPSMIN = 254,
  UNSPEC_VPUMAX = 255,
  UNSPEC_VPUMIN = 256,
  UNSPEC_VQABS = 257,
  UNSPEC_VQADD_S = 258,
  UNSPEC_VQADD_U = 259,
  UNSPEC_VQDMLAL = 260,
  UNSPEC_VQDMLAL_LANE = 261,
  UNSPEC_VQDMLSL = 262,
  UNSPEC_VQDMLSL_LANE = 263,
  UNSPEC_VQDMULH = 264,
  UNSPEC_VQDMULH_LANE = 265,
  UNSPEC_VQRDMULH = 266,
  UNSPEC_VQRDMULH_LANE = 267,
  UNSPEC_VQDMULL = 268,
  UNSPEC_VQDMULL_LANE = 269,
  UNSPEC_VQMOVN_S = 270,
  UNSPEC_VQMOVN_U = 271,
  UNSPEC_VQMOVUN = 272,
  UNSPEC_VQNEG = 273,
  UNSPEC_VQSHL_S = 274,
  UNSPEC_VQSHL_U = 275,
  UNSPEC_VQRSHL_S = 276,
  UNSPEC_VQRSHL_U = 277,
  UNSPEC_VQSHL_S_N = 278,
  UNSPEC_VQSHL_U_N = 279,
  UNSPEC_VQSHLU_N = 280,
  UNSPEC_VQSHRN_S_N = 281,
  UNSPEC_VQSHRN_U_N = 282,
  UNSPEC_VQRSHRN_S_N = 283,
  UNSPEC_VQRSHRN_U_N = 284,
  UNSPEC_VQSHRUN_N = 285,
  UNSPEC_VQRSHRUN_N = 286,
  UNSPEC_VQSUB_S = 287,
  UNSPEC_VQSUB_U = 288,
  UNSPEC_VRECPE = 289,
  UNSPEC_VRECPS = 290,
  UNSPEC_VREV16 = 291,
  UNSPEC_VREV32 = 292,
  UNSPEC_VREV64 = 293,
  UNSPEC_VRSQRTE = 294,
  UNSPEC_VRSQRTS = 295,
  UNSPEC_VSHL_S = 296,
  UNSPEC_VSHL_U = 297,
  UNSPEC_VRSHL_S = 298,
  UNSPEC_VRSHL_U = 299,
  UNSPEC_VSHLL_S_N = 300,
  UNSPEC_VSHLL_U_N = 301,
  UNSPEC_VSHL_N = 302,
  UNSPEC_VSHR_S_N = 303,
  UNSPEC_VSHR_U_N = 304,
  UNSPEC_VRSHR_S_N = 305,
  UNSPEC_VRSHR_U_N = 306,
  UNSPEC_VSHRN_N = 307,
  UNSPEC_VRSHRN_N = 308,
  UNSPEC_VSLI = 309,
  UNSPEC_VSRA_S_N = 310,
  UNSPEC_VSRA_U_N = 311,
  UNSPEC_VRSRA_S_N = 312,
  UNSPEC_VRSRA_U_N = 313,
  UNSPEC_VSRI = 314,
  UNSPEC_VST1 = 315,
  UNSPEC_VST1_LANE = 316,
  UNSPEC_VST2 = 317,
  UNSPEC_VST2_LANE = 318,
  UNSPEC_VST3 = 319,
  UNSPEC_VST3A = 320,
  UNSPEC_VST3B = 321,
  UNSPEC_VST3_LANE = 322,
  UNSPEC_VST4 = 323,
  UNSPEC_VST4A = 324,
  UNSPEC_VST4B = 325,
  UNSPEC_VST4_LANE = 326,
  UNSPEC_VSTRUCTDUMMY = 327,
  UNSPEC_VSUB = 328,
  UNSPEC_VSUBHN = 329,
  UNSPEC_VRSUBHN = 330,
  UNSPEC_VSUBL_S = 331,
  UNSPEC_VSUBL_U = 332,
  UNSPEC_VSUBW_S = 333,
  UNSPEC_VSUBW_U = 334,
  UNSPEC_VTBL = 335,
  UNSPEC_VTBX = 336,
  UNSPEC_VTRN1 = 337,
  UNSPEC_VTRN2 = 338,
  UNSPEC_VTST = 339,
  UNSPEC_VUZP1 = 340,
  UNSPEC_VUZP2 = 341,
  UNSPEC_VZIP1 = 342,
  UNSPEC_VZIP2 = 343,
  UNSPEC_MISALIGNED_ACCESS = 344,
  UNSPEC_VCLE = 345,
  UNSPEC_VCLT = 346,
  UNSPEC_NVRINTZ = 347,
  UNSPEC_NVRINTP = 348,
  UNSPEC_NVRINTM = 349,
  UNSPEC_NVRINTX = 350,
  UNSPEC_NVRINTA = 351,
  UNSPEC_NVRINTN = 352,
  UNSPEC_VQRDMLAH = 353,
  UNSPEC_VQRDMLSH = 354,
  UNSPEC_VRND = 355,
  UNSPEC_VRNDA = 356,
  UNSPEC_VRNDI = 357,
  UNSPEC_VRNDM = 358,
  UNSPEC_VRNDN = 359,
  UNSPEC_VRNDP = 360,
  UNSPEC_VRNDX = 361,
  UNSPEC_DOT_S = 362,
  UNSPEC_DOT_U = 363,
  UNSPEC_DOT_US = 364,
  UNSPEC_DOT_SU = 365,
  UNSPEC_VFML_LO = 366,
  UNSPEC_VFML_HI = 367,
  UNSPEC_VCADD90 = 368,
  UNSPEC_VCADD270 = 369,
  UNSPEC_VCMLA = 370,
  UNSPEC_VCMLA90 = 371,
  UNSPEC_VCMLA180 = 372,
  UNSPEC_VCMLA270 = 373,
  UNSPEC_VCMLA_CONJ = 374,
  UNSPEC_VCMLA180_CONJ = 375,
  UNSPEC_VCMUL = 376,
  UNSPEC_VCMUL90 = 377,
  UNSPEC_VCMUL180 = 378,
  UNSPEC_VCMUL270 = 379,
  UNSPEC_VCMUL_CONJ = 380,
  UNSPEC_MATMUL_S = 381,
  UNSPEC_MATMUL_U = 382,
  UNSPEC_MATMUL_US = 383,
  UNSPEC_BFCVT = 384,
  UNSPEC_BFCVT_HIGH = 385,
  UNSPEC_BFMMLA = 386,
  UNSPEC_BFMAB = 387,
  UNSPEC_BFMAT = 388,
  VST4Q = 389,
  VRNDXQ_F = 390,
  VRNDQ_F = 391,
  VRNDPQ_F = 392,
  VRNDNQ_F = 393,
  VRNDMQ_F = 394,
  VRNDAQ_F = 395,
  VREV64Q_F = 396,
  VDUPQ_N_F = 397,
  VREV32Q_F = 398,
  VCVTTQ_F32_F16 = 399,
  VCVTBQ_F32_F16 = 400,
  VCVTQ_TO_F_S = 401,
  VQNEGQ_S = 402,
  VCVTQ_TO_F_U = 403,
  VREV16Q_S = 404,
  VREV16Q_U = 405,
  VADDLVQ_S = 406,
  VMVNQ_N_S = 407,
  VMVNQ_N_U = 408,
  VCVTAQ_S = 409,
  VCVTAQ_U = 410,
  VREV64Q_S = 411,
  VREV64Q_U = 412,
  VQABSQ_S = 413,
  VDUPQ_N_U = 414,
  VDUPQ_N_S = 415,
  VCLSQ_S = 416,
  VADDVQ_S = 417,
  VADDVQ_U = 418,
  VREV32Q_U = 419,
  VREV32Q_S = 420,
  VMOVLTQ_U = 421,
  VMOVLTQ_S = 422,
  VMOVLBQ_S = 423,
  VMOVLBQ_U = 424,
  VCVTQ_FROM_F_S = 425,
  VCVTQ_FROM_F_U = 426,
  VCVTPQ_S = 427,
  VCVTPQ_U = 428,
  VCVTNQ_S = 429,
  VCVTNQ_U = 430,
  VCVTMQ_S = 431,
  VCVTMQ_U = 432,
  VADDLVQ_U = 433,
  VCTP = 434,
  VCTP_M = 435,
  VPNOT = 436,
  VCREATEQ_F = 437,
  VCVTQ_N_TO_F_S = 438,
  VCVTQ_N_TO_F_U = 439,
  VBRSRQ_N_F = 440,
  VSUBQ_N_F = 441,
  VCREATEQ_U = 442,
  VCREATEQ_S = 443,
  VSHRQ_N_S = 444,
  VSHRQ_N_U = 445,
  VCVTQ_N_FROM_F_S = 446,
  VCVTQ_N_FROM_F_U = 447,
  VADDLVQ_P_S = 448,
  VADDLVQ_P_U = 449,
  VSHLQ_S = 450,
  VSHLQ_U = 451,
  VABDQ_S = 452,
  VADDQ_N_S = 453,
  VADDVAQ_S = 454,
  VADDVQ_P_S = 455,
  VBRSRQ_N_S = 456,
  VHADDQ_S = 457,
  VHADDQ_N_S = 458,
  VHSUBQ_S = 459,
  VHSUBQ_N_S = 460,
  VMAXQ_S = 461,
  VMAXVQ_S = 462,
  VMINQ_S = 463,
  VMINVQ_S = 464,
  VMLADAVQ_S = 465,
  VMULHQ_S = 466,
  VMULLBQ_INT_S = 467,
  VMULLTQ_INT_S = 468,
  VMULQ_S = 469,
  VMULQ_N_S = 470,
  VQADDQ_S = 471,
  VQADDQ_N_S = 472,
  VQRSHLQ_S = 473,
  VQRSHLQ_N_S = 474,
  VQSHLQ_S = 475,
  VQSHLQ_N_S = 476,
  VQSHLQ_R_S = 477,
  VQSUBQ_S = 478,
  VQSUBQ_N_S = 479,
  VRHADDQ_S = 480,
  VRMULHQ_S = 481,
  VRSHLQ_S = 482,
  VRSHLQ_N_S = 483,
  VRSHRQ_N_S = 484,
  VSHLQ_N_S = 485,
  VSHLQ_R_S = 486,
  VSUBQ_S = 487,
  VSUBQ_N_S = 488,
  VABDQ_U = 489,
  VADDQ_N_U = 490,
  VADDVAQ_U = 491,
  VADDVQ_P_U = 492,
  VBRSRQ_N_U = 493,
  VHADDQ_U = 494,
  VHADDQ_N_U = 495,
  VHSUBQ_U = 496,
  VHSUBQ_N_U = 497,
  VMAXQ_U = 498,
  VMAXVQ_U = 499,
  VMINQ_U = 500,
  VMINVQ_U = 501,
  VMLADAVQ_U = 502,
  VMULHQ_U = 503,
  VMULLBQ_INT_U = 504,
  VMULLTQ_INT_U = 505,
  VMULQ_U = 506,
  VMULQ_N_U = 507,
  VQADDQ_U = 508,
  VQADDQ_N_U = 509,
  VQRSHLQ_U = 510,
  VQRSHLQ_N_U = 511,
  VQSHLQ_U = 512,
  VQSHLQ_N_U = 513,
  VQSHLQ_R_U = 514,
  VQSUBQ_U = 515,
  VQSUBQ_N_U = 516,
  VRHADDQ_U = 517,
  VRMULHQ_U = 518,
  VRSHLQ_U = 519,
  VRSHLQ_N_U = 520,
  VRSHRQ_N_U = 521,
  VSHLQ_N_U = 522,
  VSHLQ_R_U = 523,
  VSUBQ_U = 524,
  VSUBQ_N_U = 525,
  VHCADDQ_ROT270_S = 526,
  VHCADDQ_ROT90_S = 527,
  VMAXAQ_S = 528,
  VMAXAVQ_S = 529,
  VMINAQ_S = 530,
  VMINAVQ_S = 531,
  VMLADAVXQ_S = 532,
  VMLSDAVQ_S = 533,
  VMLSDAVXQ_S = 534,
  VQDMULHQ_N_S = 535,
  VQDMULHQ_S = 536,
  VQRDMULHQ_N_S = 537,
  VQRDMULHQ_S = 538,
  VQSHLUQ_N_S = 539,
  VABDQ_M_S = 540,
  VABDQ_M_U = 541,
  VABDQ_F = 542,
  VADDQ_N_F = 543,
  VMAXNMAQ_F = 544,
  VMAXNMAVQ_F = 545,
  VMAXNMQ_F = 546,
  VMAXNMVQ_F = 547,
  VMINNMAQ_F = 548,
  VMINNMAVQ_F = 549,
  VMINNMQ_F = 550,
  VMINNMVQ_F = 551,
  VMULQ_F = 552,
  VMULQ_N_F = 553,
  VSUBQ_F = 554,
  VADDLVAQ_U = 555,
  VADDLVAQ_S = 556,
  VBICQ_N_U = 557,
  VBICQ_N_S = 558,
  VCVTBQ_F16_F32 = 559,
  VCVTTQ_F16_F32 = 560,
  VMLALDAVQ_U = 561,
  VMLALDAVXQ_U = 562,
  VMLALDAVXQ_S = 563,
  VMLALDAVQ_S = 564,
  VMLSLDAVQ_S = 565,
  VMLSLDAVXQ_S = 566,
  VMOVNBQ_U = 567,
  VMOVNBQ_S = 568,
  VMOVNTQ_U = 569,
  VMOVNTQ_S = 570,
  VORRQ_N_S = 571,
  VORRQ_N_U = 572,
  VQDMULLBQ_N_S = 573,
  VQDMULLBQ_S = 574,
  VQDMULLTQ_N_S = 575,
  VQDMULLTQ_S = 576,
  VQMOVNBQ_U = 577,
  VQMOVNBQ_S = 578,
  VQMOVUNBQ_S = 579,
  VQMOVUNTQ_S = 580,
  VRMLALDAVHXQ_S = 581,
  VRMLSLDAVHQ_S = 582,
  VRMLSLDAVHXQ_S = 583,
  VSHLLBQ_S = 584,
  VSHLLBQ_U = 585,
  VSHLLTQ_U = 586,
  VSHLLTQ_S = 587,
  VQMOVNTQ_U = 588,
  VQMOVNTQ_S = 589,
  VSHLLBQ_N_S = 590,
  VSHLLBQ_N_U = 591,
  VSHLLTQ_N_U = 592,
  VSHLLTQ_N_S = 593,
  VRMLALDAVHQ_U = 594,
  VRMLALDAVHQ_S = 595,
  VMULLTQ_POLY_P = 596,
  VMULLBQ_POLY_P = 597,
  VBICQ_M_N_S = 598,
  VBICQ_M_N_U = 599,
  VCMPEQQ_M_F = 600,
  VCVTAQ_M_S = 601,
  VCVTAQ_M_U = 602,
  VCVTQ_M_TO_F_S = 603,
  VCVTQ_M_TO_F_U = 604,
  VQRSHRNBQ_N_U = 605,
  VQRSHRNBQ_N_S = 606,
  VQRSHRUNBQ_N_S = 607,
  VRMLALDAVHAQ_S = 608,
  VABAVQ_S = 609,
  VABAVQ_U = 610,
  VSHLCQ_S = 611,
  VSHLCQ_U = 612,
  VRMLALDAVHAQ_U = 613,
  VABSQ_M_S = 614,
  VADDVAQ_P_S = 615,
  VADDVAQ_P_U = 616,
  VCLSQ_M_S = 617,
  VCLZQ_M_S = 618,
  VCLZQ_M_U = 619,
  VCMPCSQ_M_N_U = 620,
  VCMPCSQ_M_U = 621,
  VCMPEQQ_M_N_S = 622,
  VCMPEQQ_M_N_U = 623,
  VCMPEQQ_M_S = 624,
  VCMPEQQ_M_U = 625,
  VCMPGEQ_M_N_S = 626,
  VCMPGEQ_M_S = 627,
  VCMPGTQ_M_N_S = 628,
  VCMPGTQ_M_S = 629,
  VCMPHIQ_M_N_U = 630,
  VCMPHIQ_M_U = 631,
  VCMPLEQ_M_N_S = 632,
  VCMPLEQ_M_S = 633,
  VCMPLTQ_M_N_S = 634,
  VCMPLTQ_M_S = 635,
  VCMPNEQ_M_N_S = 636,
  VCMPNEQ_M_N_U = 637,
  VCMPNEQ_M_S = 638,
  VCMPNEQ_M_U = 639,
  VDUPQ_M_N_S = 640,
  VDUPQ_M_N_U = 641,
  VDWDUPQ_N_U = 642,
  VDWDUPQ_WB_U = 643,
  VIWDUPQ_N_U = 644,
  VIWDUPQ_WB_U = 645,
  VMAXAQ_M_S = 646,
  VMAXAVQ_P_S = 647,
  VMAXVQ_P_S = 648,
  VMAXVQ_P_U = 649,
  VMINAQ_M_S = 650,
  VMINAVQ_P_S = 651,
  VMINVQ_P_S = 652,
  VMINVQ_P_U = 653,
  VMLADAVAQ_S = 654,
  VMLADAVAQ_U = 655,
  VMLADAVQ_P_S = 656,
  VMLADAVQ_P_U = 657,
  VMLADAVXQ_P_S = 658,
  VMLAQ_N_S = 659,
  VMLAQ_N_U = 660,
  VMLASQ_N_S = 661,
  VMLASQ_N_U = 662,
  VMLSDAVQ_P_S = 663,
  VMLSDAVXQ_P_S = 664,
  VMVNQ_M_S = 665,
  VMVNQ_M_U = 666,
  VNEGQ_M_S = 667,
  VPSELQ_S = 668,
  VPSELQ_U = 669,
  VQABSQ_M_S = 670,
  VQDMLAHQ_N_S = 671,
  VQDMLASHQ_N_S = 672,
  VQNEGQ_M_S = 673,
  VQRDMLADHQ_S = 674,
  VQRDMLADHXQ_S = 675,
  VQRDMLAHQ_N_S = 676,
  VQRDMLASHQ_N_S = 677,
  VQRDMLSDHQ_S = 678,
  VQRDMLSDHXQ_S = 679,
  VQRSHLQ_M_N_S = 680,
  VQRSHLQ_M_N_U = 681,
  VQSHLQ_M_R_S = 682,
  VQSHLQ_M_R_U = 683,
  VREV64Q_M_S = 684,
  VREV64Q_M_U = 685,
  VRSHLQ_M_N_S = 686,
  VRSHLQ_M_N_U = 687,
  VSHLQ_M_R_S = 688,
  VSHLQ_M_R_U = 689,
  VSLIQ_N_S = 690,
  VSLIQ_N_U = 691,
  VSRIQ_N_S = 692,
  VSRIQ_N_U = 693,
  VQDMLSDHXQ_S = 694,
  VQDMLSDHQ_S = 695,
  VQDMLADHXQ_S = 696,
  VQDMLADHQ_S = 697,
  VMLSDAVAXQ_S = 698,
  VMLSDAVAQ_S = 699,
  VMLADAVAXQ_S = 700,
  VCMPGEQ_M_F = 701,
  VCMPGTQ_M_N_F = 702,
  VMLSLDAVQ_P_S = 703,
  VRMLALDAVHAXQ_S = 704,
  VMLSLDAVXQ_P_S = 705,
  VFMAQ_F = 706,
  VMLSLDAVAQ_S = 707,
  VQSHRUNBQ_N_S = 708,
  VQRSHRUNTQ_N_S = 709,
  VMINNMAQ_M_F = 710,
  VFMASQ_N_F = 711,
  VDUPQ_M_N_F = 712,
  VCMPGTQ_M_F = 713,
  VCMPLTQ_M_F = 714,
  VRMLSLDAVHQ_P_S = 715,
  VQSHRUNTQ_N_S = 716,
  VABSQ_M_F = 717,
  VMAXNMAVQ_P_F = 718,
  VFMAQ_N_F = 719,
  VRMLSLDAVHXQ_P_S = 720,
  VREV32Q_M_F = 721,
  VRMLSLDAVHAQ_S = 722,
  VRMLSLDAVHAXQ_S = 723,
  VCMPLTQ_M_N_F = 724,
  VCMPNEQ_M_F = 725,
  VRNDAQ_M_F = 726,
  VRNDPQ_M_F = 727,
  VADDLVAQ_P_S = 728,
  VQMOVUNBQ_M_S = 729,
  VCMPLEQ_M_F = 730,
  VMLSLDAVAXQ_S = 731,
  VRNDXQ_M_F = 732,
  VFMSQ_F = 733,
  VMINNMVQ_P_F = 734,
  VMAXNMVQ_P_F = 735,
  VPSELQ_F = 736,
  VQMOVUNTQ_M_S = 737,
  VREV64Q_M_F = 738,
  VNEGQ_M_F = 739,
  VRNDMQ_M_F = 740,
  VCMPLEQ_M_N_F = 741,
  VCMPGEQ_M_N_F = 742,
  VRNDNQ_M_F = 743,
  VMINNMAVQ_P_F = 744,
  VCMPNEQ_M_N_F = 745,
  VRMLALDAVHQ_P_S = 746,
  VRMLALDAVHXQ_P_S = 747,
  VCMPEQQ_M_N_F = 748,
  VMAXNMAQ_M_F = 749,
  VRNDQ_M_F = 750,
  VMLALDAVQ_P_U = 751,
  VMLALDAVQ_P_S = 752,
  VQMOVNBQ_M_S = 753,
  VQMOVNBQ_M_U = 754,
  VMOVLTQ_M_U = 755,
  VMOVLTQ_M_S = 756,
  VMOVNBQ_M_U = 757,
  VMOVNBQ_M_S = 758,
  VRSHRNTQ_N_U = 759,
  VRSHRNTQ_N_S = 760,
  VORRQ_M_N_S = 761,
  VORRQ_M_N_U = 762,
  VREV32Q_M_S = 763,
  VREV32Q_M_U = 764,
  VQRSHRNTQ_N_U = 765,
  VQRSHRNTQ_N_S = 766,
  VMOVNTQ_M_U = 767,
  VMOVNTQ_M_S = 768,
  VMOVLBQ_M_U = 769,
  VMOVLBQ_M_S = 770,
  VMLALDAVAQ_S = 771,
  VMLALDAVAQ_U = 772,
  VQSHRNBQ_N_U = 773,
  VQSHRNBQ_N_S = 774,
  VSHRNBQ_N_U = 775,
  VSHRNBQ_N_S = 776,
  VRSHRNBQ_N_S = 777,
  VRSHRNBQ_N_U = 778,
  VMLALDAVXQ_P_U = 779,
  VMLALDAVXQ_P_S = 780,
  VQMOVNTQ_M_U = 781,
  VQMOVNTQ_M_S = 782,
  VMVNQ_M_N_U = 783,
  VMVNQ_M_N_S = 784,
  VQSHRNTQ_N_U = 785,
  VQSHRNTQ_N_S = 786,
  VMLALDAVAXQ_S = 787,
  VMLALDAVAXQ_U = 788,
  VSHRNTQ_N_S = 789,
  VSHRNTQ_N_U = 790,
  VCVTBQ_M_F16_F32 = 791,
  VCVTBQ_M_F32_F16 = 792,
  VCVTTQ_M_F16_F32 = 793,
  VCVTTQ_M_F32_F16 = 794,
  VCVTMQ_M_S = 795,
  VCVTMQ_M_U = 796,
  VCVTNQ_M_S = 797,
  VCVTPQ_M_S = 798,
  VCVTPQ_M_U = 799,
  VCVTQ_M_N_FROM_F_S = 800,
  VCVTNQ_M_U = 801,
  VREV16Q_M_S = 802,
  VREV16Q_M_U = 803,
  VREV32Q_M = 804,
  VCVTQ_M_FROM_F_U = 805,
  VCVTQ_M_FROM_F_S = 806,
  VRMLALDAVHQ_P_U = 807,
  VADDLVAQ_P_U = 808,
  VCVTQ_M_N_FROM_F_U = 809,
  VQSHLUQ_M_N_S = 810,
  VABAVQ_P_S = 811,
  VABAVQ_P_U = 812,
  VSHLQ_M_S = 813,
  VSHLQ_M_U = 814,
  VSRIQ_M_N_S = 815,
  VSRIQ_M_N_U = 816,
  VSUBQ_M_U = 817,
  VSUBQ_M_S = 818,
  VCVTQ_M_N_TO_F_U = 819,
  VCVTQ_M_N_TO_F_S = 820,
  VQADDQ_M_U = 821,
  VQADDQ_M_S = 822,
  VRSHRQ_M_N_S = 823,
  VSUBQ_M_N_S = 824,
  VSUBQ_M_N_U = 825,
  VBRSRQ_M_N_S = 826,
  VSUBQ_M_N_F = 827,
  VBICQ_M_F = 828,
  VHADDQ_M_U = 829,
  VBICQ_M_U = 830,
  VBICQ_M_S = 831,
  VMULQ_M_N_U = 832,
  VHADDQ_M_S = 833,
  VORNQ_M_F = 834,
  VMLAQ_M_N_S = 835,
  VQSUBQ_M_U = 836,
  VQSUBQ_M_S = 837,
  VMLAQ_M_N_U = 838,
  VQSUBQ_M_N_U = 839,
  VQSUBQ_M_N_S = 840,
  VMULLTQ_INT_M_S = 841,
  VMULLTQ_INT_M_U = 842,
  VMULQ_M_N_S = 843,
  VMULQ_M_N_F = 844,
  VMLASQ_M_N_U = 845,
  VMLASQ_M_N_S = 846,
  VMAXQ_M_U = 847,
  VQRDMLAHQ_M_N_U = 848,
  VCADDQ_ROT270_M_F = 849,
  VCADDQ_ROT270_M_U = 850,
  VCADDQ_ROT270_M_S = 851,
  VQRSHLQ_M_S = 852,
  VMULQ_M_F = 853,
  VRHADDQ_M_U = 854,
  VSHRQ_M_N_U = 855,
  VRHADDQ_M_S = 856,
  VMULQ_M_S = 857,
  VMULQ_M_U = 858,
  VQDMLASHQ_M_N_S = 859,
  VQRDMLASHQ_M_N_S = 860,
  VRSHLQ_M_S = 861,
  VRSHLQ_M_U = 862,
  VRSHRQ_M_N_U = 863,
  VADDQ_M_N_F = 864,
  VADDQ_M_N_S = 865,
  VADDQ_M_N_U = 866,
  VQRDMLASHQ_M_N_U = 867,
  VMAXQ_M_S = 868,
  VQRDMLAHQ_M_N_S = 869,
  VORRQ_M_S = 870,
  VORRQ_M_U = 871,
  VORRQ_M_F = 872,
  VQRSHLQ_M_U = 873,
  VRMULHQ_M_U = 874,
  VRMULHQ_M_S = 875,
  VMINQ_M_S = 876,
  VMINQ_M_U = 877,
  VANDQ_M_F = 878,
  VANDQ_M_U = 879,
  VANDQ_M_S = 880,
  VHSUBQ_M_N_S = 881,
  VHSUBQ_M_N_U = 882,
  VMULHQ_M_S = 883,
  VMULHQ_M_U = 884,
  VMULLBQ_INT_M_U = 885,
  VMULLBQ_INT_M_S = 886,
  VCADDQ_ROT90_M_F = 887,
  VSHRQ_M_N_S = 888,
  VADDQ_M_U = 889,
  VSLIQ_M_N_U = 890,
  VQADDQ_M_N_S = 891,
  VBRSRQ_M_N_F = 892,
  VABDQ_M_F = 893,
  VBRSRQ_M_N_U = 894,
  VEORQ_M_F = 895,
  VSHLQ_M_N_S = 896,
  VQDMLAHQ_M_N_U = 897,
  VQDMLAHQ_M_N_S = 898,
  VSHLQ_M_N_U = 899,
  VMLADAVAQ_P_U = 900,
  VMLADAVAQ_P_S = 901,
  VSLIQ_M_N_S = 902,
  VQSHLQ_M_U = 903,
  VQSHLQ_M_S = 904,
  VCADDQ_ROT90_M_U = 905,
  VCADDQ_ROT90_M_S = 906,
  VORNQ_M_U = 907,
  VORNQ_M_S = 908,
  VQSHLQ_M_N_S = 909,
  VQSHLQ_M_N_U = 910,
  VADDQ_M_S = 911,
  VHADDQ_M_N_S = 912,
  VADDQ_M_F = 913,
  VQADDQ_M_N_U = 914,
  VEORQ_M_S = 915,
  VEORQ_M_U = 916,
  VHSUBQ_M_S = 917,
  VHSUBQ_M_U = 918,
  VHADDQ_M_N_U = 919,
  VHCADDQ_ROT90_M_S = 920,
  VQRDMLSDHQ_M_S = 921,
  VQRDMLSDHXQ_M_S = 922,
  VQRDMLADHXQ_M_S = 923,
  VQDMULHQ_M_S = 924,
  VMLADAVAXQ_P_S = 925,
  VQDMLADHXQ_M_S = 926,
  VQRDMULHQ_M_S = 927,
  VMLSDAVAXQ_P_S = 928,
  VQDMULHQ_M_N_S = 929,
  VHCADDQ_ROT270_M_S = 930,
  VQDMLSDHQ_M_S = 931,
  VQDMLSDHXQ_M_S = 932,
  VMLSDAVAQ_P_S = 933,
  VQRDMLADHQ_M_S = 934,
  VQDMLADHQ_M_S = 935,
  VMLALDAVAQ_P_U = 936,
  VMLALDAVAQ_P_S = 937,
  VQRSHRNBQ_M_N_U = 938,
  VQRSHRNBQ_M_N_S = 939,
  VQRSHRNTQ_M_N_S = 940,
  VQSHRNBQ_M_N_U = 941,
  VQSHRNBQ_M_N_S = 942,
  VQSHRNTQ_M_N_S = 943,
  VRSHRNBQ_M_N_U = 944,
  VRSHRNBQ_M_N_S = 945,
  VRSHRNTQ_M_N_U = 946,
  VSHLLBQ_M_N_U = 947,
  VSHLLBQ_M_N_S = 948,
  VSHLLTQ_M_N_U = 949,
  VSHLLTQ_M_N_S = 950,
  VSHRNBQ_M_N_S = 951,
  VSHRNBQ_M_N_U = 952,
  VSHRNTQ_M_N_S = 953,
  VSHRNTQ_M_N_U = 954,
  VMLALDAVAXQ_P_S = 955,
  VQRSHRNTQ_M_N_U = 956,
  VQSHRNTQ_M_N_U = 957,
  VRSHRNTQ_M_N_S = 958,
  VQRDMULHQ_M_N_S = 959,
  VRMLALDAVHAQ_P_S = 960,
  VMLSLDAVAQ_P_S = 961,
  VMLSLDAVAXQ_P_S = 962,
  VMULLBQ_POLY_M_P = 963,
  VMULLTQ_POLY_M_P = 964,
  VQDMULLBQ_M_N_S = 965,
  VQDMULLBQ_M_S = 966,
  VQDMULLTQ_M_N_S = 967,
  VQDMULLTQ_M_S = 968,
  VQRSHRUNBQ_M_N_S = 969,
  VQSHRUNBQ_M_N_S = 970,
  VQSHRUNTQ_M_N_S = 971,
  VRMLALDAVHAQ_P_U = 972,
  VRMLALDAVHAXQ_P_S = 973,
  VRMLSLDAVHAQ_P_S = 974,
  VRMLSLDAVHAXQ_P_S = 975,
  VQRSHRUNTQ_M_N_S = 976,
  VCMLAQ_M_F = 977,
  VCMLAQ_ROT180_M_F = 978,
  VCMLAQ_ROT270_M_F = 979,
  VCMLAQ_ROT90_M_F = 980,
  VCMULQ_M_F = 981,
  VCMULQ_ROT180_M_F = 982,
  VCMULQ_ROT270_M_F = 983,
  VCMULQ_ROT90_M_F = 984,
  VFMAQ_M_F = 985,
  VFMAQ_M_N_F = 986,
  VFMASQ_M_N_F = 987,
  VFMSQ_M_F = 988,
  VMAXNMQ_M_F = 989,
  VMINNMQ_M_F = 990,
  VSUBQ_M_F = 991,
  VSTRWQSB_S = 992,
  VSTRWQSB_U = 993,
  VSTRBQSO_S = 994,
  VSTRBQSO_U = 995,
  VSTRBQ_S = 996,
  VSTRBQ_U = 997,
  VLDRBQGO_S = 998,
  VLDRBQGO_U = 999,
  VLDRBQ_S = 1000,
  VLDRBQ_U = 1001,
  VLDRWQGB_S = 1002,
  VLDRWQGB_U = 1003,
  VLD1Q_F = 1004,
  VLD1Q_S = 1005,
  VLD1Q_U = 1006,
  VLDRHQ_F = 1007,
  VLDRHQGO_S = 1008,
  VLDRHQGO_U = 1009,
  VLDRHQGSO_S = 1010,
  VLDRHQGSO_U = 1011,
  VLDRHQ_S = 1012,
  VLDRHQ_U = 1013,
  VLDRWQ_F = 1014,
  VLDRWQ_S = 1015,
  VLDRWQ_U = 1016,
  VLDRDQGB_S = 1017,
  VLDRDQGB_U = 1018,
  VLDRDQGO_S = 1019,
  VLDRDQGO_U = 1020,
  VLDRDQGSO_S = 1021,
  VLDRDQGSO_U = 1022,
  VLDRHQGO_F = 1023,
  VLDRHQGSO_F = 1024,
  VLDRWQGB_F = 1025,
  VLDRWQGO_F = 1026,
  VLDRWQGO_S = 1027,
  VLDRWQGO_U = 1028,
  VLDRWQGSO_F = 1029,
  VLDRWQGSO_S = 1030,
  VLDRWQGSO_U = 1031,
  VSTRHQ_F = 1032,
  VST1Q_S = 1033,
  VST1Q_U = 1034,
  VSTRHQSO_S = 1035,
  VSTRHQ_U = 1036,
  VSTRWQ_S = 1037,
  VSTRWQ_U = 1038,
  VSTRWQ_F = 1039,
  VST1Q_F = 1040,
  VSTRDQSB_S = 1041,
  VSTRDQSB_U = 1042,
  VSTRDQSO_S = 1043,
  VSTRDQSO_U = 1044,
  VSTRDQSSO_S = 1045,
  VSTRDQSSO_U = 1046,
  VSTRWQSO_S = 1047,
  VSTRWQSO_U = 1048,
  VSTRWQSSO_S = 1049,
  VSTRWQSSO_U = 1050,
  VSTRHQSO_F = 1051,
  VSTRHQSSO_F = 1052,
  VSTRWQSB_F = 1053,
  VSTRWQSO_F = 1054,
  VSTRWQSSO_F = 1055,
  VDDUPQ = 1056,
  VDDUPQ_M = 1057,
  VDWDUPQ = 1058,
  VDWDUPQ_M = 1059,
  VIDUPQ = 1060,
  VIDUPQ_M = 1061,
  VIWDUPQ = 1062,
  VIWDUPQ_M = 1063,
  VSTRWQSBWB_S = 1064,
  VSTRWQSBWB_U = 1065,
  VLDRWQGBWB_S = 1066,
  VLDRWQGBWB_U = 1067,
  VSTRWQSBWB_F = 1068,
  VLDRWQGBWB_F = 1069,
  VSTRDQSBWB_S = 1070,
  VSTRDQSBWB_U = 1071,
  VLDRDQGBWB_S = 1072,
  VLDRDQGBWB_U = 1073,
  VADCQ_U = 1074,
  VADCQ_M_U = 1075,
  VADCQ_S = 1076,
  VADCQ_M_S = 1077,
  VSBCIQ_U = 1078,
  VSBCIQ_S = 1079,
  VSBCIQ_M_U = 1080,
  VSBCIQ_M_S = 1081,
  VSBCQ_U = 1082,
  VSBCQ_S = 1083,
  VSBCQ_M_U = 1084,
  VSBCQ_M_S = 1085,
  VADCIQ_U = 1086,
  VADCIQ_M_U = 1087,
  VADCIQ_S = 1088,
  VADCIQ_M_S = 1089,
  VLD2Q = 1090,
  VLD4Q = 1091,
  VST2Q = 1092,
  VSHLCQ_M_U = 1093,
  VSHLCQ_M_S = 1094,
  VSTRHQSO_U = 1095,
  VSTRHQSSO_S = 1096,
  VSTRHQSSO_U = 1097,
  VSTRHQ_S = 1098,
  SRSHRL = 1099,
  SRSHR = 1100,
  URSHR = 1101,
  URSHRL = 1102,
  SQRSHR = 1103,
  UQRSHL = 1104,
  UQRSHLL_64 = 1105,
  UQRSHLL_48 = 1106,
  SQRSHRL_64 = 1107,
  SQRSHRL_48 = 1108,
  VSHLCQ_M_ = 1109,
  REINTERPRET = 1110
};
#define NUM_UNSPEC_VALUES 1111
extern const char *const unspec_strings[];

enum unspecv {
  VUNSPEC_BLOCKAGE = 0,
  VUNSPEC_EPILOGUE = 1,
  VUNSPEC_THUMB1_INTERWORK = 2,
  VUNSPEC_ALIGN = 3,
  VUNSPEC_POOL_END = 4,
  VUNSPEC_POOL_1 = 5,
  VUNSPEC_POOL_2 = 6,
  VUNSPEC_POOL_4 = 7,
  VUNSPEC_POOL_8 = 8,
  VUNSPEC_POOL_16 = 9,
  VUNSPEC_TMRC = 10,
  VUNSPEC_TMCR = 11,
  VUNSPEC_ALIGN8 = 12,
  VUNSPEC_WCMP_EQ = 13,
  VUNSPEC_WCMP_GTU = 14,
  VUNSPEC_WCMP_GT = 15,
  VUNSPEC_EH_RETURN = 16,
  VUNSPEC_ATOMIC_CAS = 17,
  VUNSPEC_ATOMIC_XCHG = 18,
  VUNSPEC_ATOMIC_OP = 19,
  VUNSPEC_LL = 20,
  VUNSPEC_LDRD_ATOMIC = 21,
  VUNSPEC_SC = 22,
  VUNSPEC_LAX = 23,
  VUNSPEC_SLX = 24,
  VUNSPEC_LDA = 25,
  VUNSPEC_STL = 26,
  VUNSPEC_GET_FPSCR = 27,
  VUNSPEC_SET_FPSCR = 28,
  VUNSPEC_SET_FPSCR_NZCVQC = 29,
  VUNSPEC_PROBE_STACK_RANGE = 30,
  VUNSPEC_CDP = 31,
  VUNSPEC_CDP2 = 32,
  VUNSPEC_LDC = 33,
  VUNSPEC_LDC2 = 34,
  VUNSPEC_LDCL = 35,
  VUNSPEC_LDC2L = 36,
  VUNSPEC_STC = 37,
  VUNSPEC_STC2 = 38,
  VUNSPEC_STCL = 39,
  VUNSPEC_STC2L = 40,
  VUNSPEC_MCR = 41,
  VUNSPEC_MCR2 = 42,
  VUNSPEC_MRC = 43,
  VUNSPEC_MRC2 = 44,
  VUNSPEC_MCRR = 45,
  VUNSPEC_MCRR2 = 46,
  VUNSPEC_MRRC = 47,
  VUNSPEC_MRRC2 = 48,
  VUNSPEC_SPECULATION_BARRIER = 49,
  VUNSPEC_APSR_WRITE = 50,
  VUNSPEC_VSTR_VLDR = 51,
  VUNSPEC_CLRM_APSR = 52,
  VUNSPEC_VSCCLRM_VPR = 53,
  VUNSPEC_VLSTM = 54,
  VUNSPEC_VLLDM = 55,
  VUNSPEC_PACBTI_NOP = 56,
  VUNSPEC_AUT_NOP = 57,
  VUNSPEC_BTI_NOP = 58
};
#define NUM_UNSPECV_VALUES 59
extern const char *const unspecv_strings[];

#endif /* GCC_INSN_CONSTANTS_H */
