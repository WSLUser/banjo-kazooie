#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern f32 func_80323540(struct56s *, f32, f32, f32);
extern void sfxsource_setSampleRate(u8, s32);
extern bool func_80323240(struct56s *, f32, f32[3]);
extern f32  func_803234FC(struct56s *, f32, f32);
extern f32  func_803237E8(struct56s *);
extern f32  func_80323FDC(struct56s *, f32, f32, s32 *);
extern f32  func_803240E0(struct56s *, f32, f32, s32 *);
extern void func_80250530(s32, u16, f32);
extern s32 func_80255D44(s32);

extern struct56s **D_80371E70;
extern void **D_80371E74;
extern s32 D_80371E78;
extern s32 D_80371E7C;
extern s32 D_80371E80;

typedef struct {
    f32 unk0;
    u8 pad4[0x8];
    struct{
        u32 pad_bit31: 9;
        u32 bit22: 11;
        u32 pad_bit11: 12;
    }unkC;
} Struct_glspline_0;

// typedef struct {
//     u8 pad_0[0x4];
//     union {
//         struct{
//             u16 bit63;
//             u16 bit47:12;
//             u16 unk0_3:3;
//             u16 pad0_0:1;
//             u32 bit31:24;
//             u32 pad4_7:8;
//         }t0;
//         struct{
//             u32 pad_bit63: 12;
//             u32 bit51: 2;
//             u32 pad_bit49: 18;
//             u32 bit31: 10;
//             u32 bit21: 11;
//             u32 bit10: 1;
//             u32 pad_bit9: 1;
//             u32 bit8: 1;
//             u32 pad_bit7: 1;
//             u32 bit6: 3;
//             u32 bit3: 3;
//             u32 pad_bit0: 1;
//         }t1;
//         struct{
//             u32 bit63:  1;
//             u32 bit62: 15;
//             u32 bit47:  8;
//             u32 bit39: 4;
//             u32 pad_bit35: 4;
//             u32 pad_bit31: 32;
//         }t2;
//     }unk4;
//     u32 padC_31:8;
//     u32 unkC_23:2;
//     u32 unkC_21:1;
//     u32 unkC_20:8;
//     u32 unkC_12:12;
//     u32 unkC_0 : 1;
//     union {
//         struct {
//             u32 pad_bit31: 24;
//             u32 bit7:7;
//             u32 bit0:1;
//         }t0;
//         struct {
//             u32 pad_bit31: 25;
//             u32 bit6: 1;
//             u32 bit5: 1;
//             u32 bit4: 1;
//             u32 pad_bit3:5;
//         }t1;
//         struct {
//             u32 pad_bit31: 24;
//             u32 bit7:5;
//             u32 pad_bit1:2;
//         }t2;
//     }unk10;
// }Struct_glspline_0;

typedef struct {
    u32 bit31: 16;
    u32 bit15: 12;
    u32 bit3:       3;
    u32 bit0:       1;
}Struct_glspline_t0_unk4_common;

typedef struct {
    u32 bit31:  1;
    u32 bit30: 15;
    u32 bit15:  8;
    u32 bit7: 4;
    u32 bit3:       3;
    u32 bit0:       1;
}Struct_glspline_t0_unk4_t7;

typedef struct{
    u8 pad0[0x4];
    union
    {
        Struct_glspline_t0_unk4_common common;
        Struct_glspline_t0_unk4_t7 t7;
    }unk4;
    struct {
        u32 bit31:24;
        u32 pad4_7:8;
    }unk8;
    struct{
        u32 pad_bit31:8;
        u32 bit23:2;
        u32 bit21:1;
        u32 bit20:8;
        u32 bit12:12;
        u32 bit0:1;
    }unkC;
    union {
        struct {
            u32 pad_bit31: 24;
            u32 bit7:7;
            u32 bit0:1;
        } common;
        struct {
            u32 pad_bit31: 24;
            u32 bit7:6;
            u32 pad_bit1:1;
            u32 bit0:1;
        }t7;
        u32 word;
    } unk10;
}Struct_glspline_t0;

typedef struct{
    f32 unk0;
    struct{
        u32 bit31: 12;
        u32 bit19: 2;
        u32 bit17: 2;
        u32 bit15: 9;
        u32 bit6: 3;
        u32 bit3: 3;
        u32 pad_bit0: 1;
    }unk4;
    struct{
        u32 bit31: 10;
        u32 bit21: 11;
        u32 bit10: 1;
        u32 bit9: 1;
        u32 bit8: 1;
        u32 pad_bit7: 8;
    } unk8;
    struct{
//     u32 padC_31:8;
//     u32 unkC_23:2;
//     u32 unkC_21:1;
//     u32 unkC_20:8;
        u32 bit31:9;
        u32 bit22:11;
        u32 bit11:11;
        u32 bit0 : 1;
    }unkC;
    struct {
        u32 bit31: 12;
        u32 pad_bit19: 13;
        u32 bit6: 1;
        u32 bit5: 1;
        u32 bit4: 1;
        u32 pad_bit3:3;
    }unk10;
}Struct_glspline_t1;

typedef struct{
    u8 pad0[0xC];
    struct{
        u32 pad_bit31:31;
        u32 bit0:1;
    }unkC;
    u8 pad10[0x4];
}Struct_glspline_common;

typedef union{
    Struct_glspline_common common;
    Struct_glspline_t0 t0;
    Struct_glspline_t1 t1;
    /* data */
}Union_glspline;


typedef struct{
    s32 unk0;
    Union_glspline spline[];
}glspline_list;

/* .rodata */
extern char D_80378FF0[];
extern f32 D_8037901C;

/* .bss */
s16 *D_803858A0;

/* .code */
f32 func_80340700(f32 value, f32 min, f32 max) {
    return (value < min) ? min
         : (max < value) ? max
         : value;
}

bool func_80340748(s32 arg0, s32 arg1, s32 arg2, f32 arg3[3], s32 arg4, s32 arg5, s32 arg6){
    return FALSE;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B9770/func_80340760.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B9770/func_80340A4C.s")
// f32 func_80340A4C(f32 arg0, s32 arg1, f32 *arg2){
//     s32 tmp_v1;
//     s32 sp30;
//     f32 sp24[3];
//     f32 f20;

//     sp30 = arg1 - 3;
//     f20 = func_80340700( arg0, 0.0f, 1.0f)*sp30;
//     tmp_v1 = f20;
//     arg1 -= 4;
//     tmp_v1 = MIN(tmp_v1, arg1);
//     arg2 += tmp_v1;
//     f20 -= tmp_v1;
//     sp24[2] = -0.5*arg2[0] +  1.5*arg2[1] + -1.5*arg2[2] +  0.5*arg2[3];
//     sp24[1] =  1.0*arg2[0] + -2.5*arg2[1] +  2.0*arg2[2] + -0.5*arg2[3];
//     sp24[0] = -0.5*arg2[0] +  0.5*arg2[2];
//     return f20*(sp24[0] + f20*(sp24[1] + f20*sp24[2])) + (f64)arg2[1];
// }

void func_80340BE4(f32 arg0, s32 arg1, s32 arg2, s32 arg3, f32 * arg4, f32 arg5[3]);
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B9770/func_80340BE4.s")

void func_80341180(f32 arg0, s32 arg1, s32 arg2, f32 * arg3, f32 arg4[3]){
    func_80340BE4(arg0, arg1, arg2, arg2, arg3, arg4);
}


#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B9770/func_803411B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B9770/func_80341A54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B9770/func_80341BA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B9770/func_80341BC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B9770/func_80341C78.s")

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B9770/func_80341D5C.s")
#else
s32 func_80341D5C(s32 arg0[3], s32 arg1[3]){
    int i, j;
    struct56s *a0;
    f32 (*a2)[3];
    f32 spC[3];
    f32 sp0[3];

    spC[0] = (f32)arg0[0];
    spC[1] = (f32)arg0[1];
    spC[2] = (f32)arg0[2];

    sp0[0] = (f32)arg1[0];
    sp0[1] = (f32)arg1[1];
    sp0[2] = (f32)arg1[2];

    for(i = 0; i < D_80371E78; i++){
        a2 = D_80371E70[i]->unk8;
        for(j = 0; j < D_80371E70[i]->unk0; j++){
            if( spC[0] == a2[j][0]
                && spC[1] == a2[j][1]
                && spC[2] == a2[j][2]
                && sp0[0] == a2[j +1][0]
                && sp0[1] == a2[j +1][1]
                && sp0[2] == a2[j +1][2]
            ){
                return i;
            }
        }
    }
    return -1;
}
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B9770/func_80341EC4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B9770/func_80341EF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B9770/func_80341F2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B9770/func_80341F64.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B9770/func_80341FB0.s")

struct56s *func_80342038(s32 indx){
    if(indx == -1)
        return NULL;
    return D_80371E70[indx];
}

int func_80342064(s32 arg0){
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B9770/func_80342070.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B9770/func_803420BC.s")

s32 func_803421A4(s32, f32);
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B9770/func_803421A4.s")


#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B9770/func_80342244.s")

f32 func_80342260(s32 arg0, f32 arg1, s32 arg2){
    return func_803234FC(func_80342038(arg0), arg1, 1.0f) / ((f32)arg2 /4);
}

void func_803422AC(ActorMarker *caller, enum asset_e text_id, s32 arg2){
    jiggyscore_total();
}

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B9770/func_803422D4.s")
#else
s32 func_803422D4(Actor *arg0, Union_glspline *arg1, glspline_list *arg2) {
    s32 sp84 = 0;
    u8 sp83;
    f32 sp7C;
    s32 sp78;
    s32 sp74;
    u32 sp70;
    s32 sp6C;
    s32 sp68;
    s32 sp64;
    f32 sp60;
    f32 sp54[3];
    f32 sp50;
    f32 sp4C;
    Struct_glspline_t1 *sp48;                                     /* compiler-managed */
    Struct_glspline_t1 *temp_v0_6;

    if (arg1->common.unkC.bit0) {
        if (D_80371E80 == 1) {
            sp84 = 1;
        }
        switch (arg1->t0.unk4.common.bit3) {
            case 1:
                func_80250530(0, arg1->t0.unk4.common.bit31, 3.0f);
                break;

            case 2:
                D_803858A0[arg1->t0.unk10.common.bit7] = arg1->t0.unk4.common.bit31;
                func_8025A6EC(func_80255D30(arg1->t0.unk4.common.bit31), arg1->t0.unk4.common.bit15 * 8);
                break;

            case 3:
                sp78 = arg1->t0.unk4.common.bit31;
                sp7C = arg1->t0.unk8.bit31/8.388608e6f;
                sp74 = arg1->t0.unk4.common.bit15*8;
                sp70 = arg1->t0.unk10.common.bit7;
                if (func_8030ED70(func_80255D44(sp78))) {
                    sp83 = func_8030D90C();
                    if (sp83 == 0){
                        return sp84;
                    }

                    sfxsource_setSfxId(sp83, func_80255D44(sp78));
                    func_8030DBB4(sp83, sp7C);
                    sfxsource_setSampleRate(sp83, sp74);
                    func_8030E2C4(sp83);
                    if (D_803858A0[sp70] != 0) {
                        func_8030DA44(D_803858A0[sp70]);
                    }
                    D_803858A0[sp70] = sp83;

                } else {
                    func_8030E6A4(func_80255D44(sp78), sp7C, sp74);
                }
                break;

            case 7:
                if(((arg1->t0.unk10.word << 0x1e) >>0x1f) == TRUE){
                    arg0->unk124_11 = (arg1->t0.unk4.t7.bit31 == FALSE) ? 2
                                    : (arg1->t0.unk4.t7.bit31 == TRUE)  ? 1
                                    : 0;
                    arg0->unk1C[0] = (arg1->t0.unk4.t7.bit30 != 0) ? (f32)((f32)arg1->t0.unk4.t7.bit30 * 0.25) 
                                   : 0.0f;
                    arg0->unk1C[1] = 0.0f;
                }
                if (arg1->t0.unkC.bit21 == 1) {
                    func_803110F8(arg1->t0.unkC.bit20, arg1->t0.unk10.t7.bit7, arg1->t0.unk4.t7.bit15, arg1->t0.unk4.t7.bit7, func_803422AC);
                }
                if ((arg1->t0.unkC.bit23 == 1) || (arg1->t0.unkC.bit23 == 2)) {
                    D_80371E80 = arg1->t0.unkC.bit23 - 1;
                }
                break;
                
            case 6:
                mapSpecificFlags_set(arg1->t0.unk4.common.bit31, TRUE);
                break;

            case 4:
                if (D_803858A0[arg1->t0.unk10.common.bit7] != 0) {
                    func_8025A7DC(func_80255D30(D_803858A0[arg1->t0.unk10.common.bit7]));
                    D_803858A0[arg1->t0.unk10.common.bit7] = 0;
                }
                break;

            case 5:
                if (D_803858A0[arg1->t0.unk10.common.bit7] != 0) {
                    func_8030DA44(D_803858A0[arg1->t0.unk10.common.bit7]);
                    D_803858A0[arg1->t0.unk10.common.bit7] = 0;
                }
                break;
        }

        if (arg1->t0.unkC.bit12 != 0) {
            sp64 = 0;
            sp68 = func_80340760(arg1->t0.unkC.bit12, &sp6C, &sp60, sp54, arg0->unk44_14, &sp50, &sp4C);
            if (sp68 == 0) {
                sp64 = func_80340748(arg1->t0.unkC.bit12, &sp6C, &sp60, sp54, arg0->unk44_14, &sp50, &sp4C);
            }
            sp84 = 2;
            arg0->unk44_14 = sp6C;
            arg0->unk48 = sp60;
            arg0->position[0] = sp54[0];
            arg0->position[1] = sp54[1];
            arg0->position[2] = sp54[2];
            if (sp68 != 0) {
                if (sp50 != -9999.0f) {
                    arg0->yaw = sp50;
                        if (arg0->marker->unk14_20 == 0x12) {
                            arg0->yaw = (f32) func_80342244((s32) arg0->yaw);
                        }
                    arg0->yaw_moving = arg0->yaw;
                }
                if (sp4C != -9999.0f) {
                    arg0->pitch = sp4C;
                    arg0->unk6C = arg0->pitch;
                }
                if ((sp50 != -9999.0f) || (sp4C != -9999.0f)) {
                    func_802CDAC4(arg0);
                }
            }
            if (sp64) {

            }
        }
        
    } else {
        if (D_80371E80 == 1) {
            sp84 = 1;
        }
        if (arg1->t1.unk8.bit8) {
            if (arg1->t1.unk10.bit5) {
                arg0->unk138_3 = (arg1->t1.unkC.bit11 - 0x69);
            } else {
                arg0->unk54 = (f32)arg1->t1.unkC.bit11 / 4;
            }
        }
        if (arg1->t1.unk8.bit10) {
            arg0->unk5C = (f32)arg1->t1.unk8.bit21 / 4;
            arg0->unk58_31 = func_80255D58(arg1->t1.unk8.bit31);
            if (arg0->animctrl == NULL) {
                arg0->animctrl = animctrl_new(0);
                animctrl_reset(arg0->animctrl);
            }
            animctrl_setIndex(arg0->animctrl, arg0->unk58_31);
            animctrl_setDuration(arg0->animctrl, arg0->unk5C);
            animctrl_setDirection(arg0->animctrl, 1);
            if (arg0->animctrl != NULL) {
                _func_802875AC(arg0->animctrl, "glspline.c"/*&D_80378FF0*/, 0x545);
            }
        }
        switch (arg1->t1.unk4.bit6) {                          /* switch 2 */
            case 1:                                     /* switch 2 */
                arg0->unk10_4 = TRUE;
                arg0->unk10_8 = TRUE;
                arg0->unk10_7 = TRUE;
                break;

            case 2:                                     /* switch 2 */
                arg0->unk10_4 = FALSE;
                arg0->unk10_8 = FALSE;
                break;

            case 3:                                     /* switch 2 */
                arg0->unk10_4 = FALSE;
                arg0->unk10_8 = TRUE;
                break;

            case 4:                                     /* switch 2 */
                arg0->unk10_4 = FALSE;
                arg0->unk10_7 = FALSE;
                break;

            case 5:                                     /* switch 2 */
                arg0->unk10_4 = FALSE;
                arg0->unk10_7 = TRUE;
                break;

            case 6:                                     /* switch 2 */
                arg0->unk10_4 = FALSE;
                arg0->unk10_8 = FALSE;
                arg0->unk10_7 = FALSE;
                break;

            case 7:                                     /* switch 2 */
                arg0->unk10_4 = FALSE;
                arg0->unk10_8 = TRUE;
                arg0->unk10_7 = TRUE;
                break;
        }

        switch (arg1->t1.unk4.bit3) {                        /* switch 3 */
            case 2:                                     /* switch 3 */
                arg0->unk10_6 = 0;
                if (arg0->unk4C < 0.0f) {
                    arg0->unk4C = -arg0->unk4C;
                } else {
                    arg0->unk4C = arg0->unk4C;
                }
                actor_playAnimationOnce(arg0);
               break;

            case 3:                                     /* switch 3 */
                arg0->unk10_6 = 0;
                if (arg0->unk4C < 0.0f) {
                    arg0->unk4C = arg0->unk4C;
                } else {
                    arg0->unk4C = -arg0->unk4C;
                }
                actor_playAnimationOnce(arg0);
                break;

            case 4:                                     /* switch 3 */
                arg0->unk10_6 = 1;
                if (arg0->unk4C < 0.0f) {
                    arg0->unk4C = -arg0->unk4C;
                } else {
                    arg0->unk4C = arg0->unk4C;
                }
                actor_loopAnimation(arg0);
                break;

            case 5:                                     /* switch 3 */
                arg0->unk10_6 = 1;
                if (arg0->unk4C < 0.0f) {
                    arg0->unk4C = arg0->unk4C;
                } else {
                    arg0->unk4C = -arg0->unk4C;
                }
                actor_loopAnimation(arg0);
                break;

            case 6:                                     /* switch 3 */
                arg0->unk10_6 = 2;
                break;
        }

        if (arg1->t1.unk4.bit19 != 0) {
            arg0->unk10_3 = arg1->t1.unk4.bit19;
        }

        if (arg1->t1.unk10.bit6 != arg0->unk138_30) {
            arg0->unk138_30 = arg1->t1.unk10.bit6;
        }

        if (arg1->t1.unk8.bit9) {
            if (!func_802E4A08() && (arg0->modelCacheIndex == ACTOR_123_MAGIC_CARPET_2)) {
                arg0->unk4C = func_80323540(func_80342038(arg0->unk44_14), arg0->unk48, 1.0f, 500.0f) / ((f32)arg1->t1.unkC.bit22 / 4);
            } else {
                arg0->unk4C = func_80342260(arg0->unk44_14, arg0->unk48, arg1->t1.unkC.bit22);
            }
        }
        if (arg1->t1.unk4.bit31 != 0) {
            sp48 = &arg2->spline[0].t1;
            temp_v0_6 = &arg2->spline[arg2->unk0].t1;
            while(sp48->unk10.bit31 != arg1->t1.unk4.bit31 && sp48 < temp_v0_6){
                sp48++;
            }
            arg0->unkF4_24 = arg1->t0.unk4.common.bit31;
            arg0->unk70 = arg1->t1.unk0;
            arg0->unk74 = sp48->unk0;
            if (arg1->t1.unk4.bit17 & 1) {
                arg0->unk38_13 = arg1->t1.unkC.bit31;
                arg0->unk38_21 = sp48->unkC.bit31;
                arg0->unk78_31 = arg1->t1.unk4.bit15;
                arg0->unk78_22 = sp48->unk4.bit15;
                if (arg0->marker->unk14_20 == 0x12) {
                    arg0->unk38_13 = func_80342244(arg0->unk38_13);
                    arg0->unk38_21 = func_80342244(arg0->unk38_21);
                }
                arg0->yaw = arg0->yaw_moving = (f32) arg0->unk38_13;
                arg0->pitch = arg0->unk6C = (f32) arg0->unk78_31;
            }
            if (arg1->t1.unk4.bit17 & 2) {
                arg0->unk140 = arg0->unk4C;
                arg0->unk144 = func_803234FC(func_80342038(arg0->unk44_14), sp48->unk0, 1.0f) / ((f32)sp48->unkC.bit22 / 4);
            }
        }
        if (!arg0->unk10_4) {
            if (arg0->unk10_8) {
                arg0->yaw_moving = (f32)arg1->t1.unkC.bit31;
                if (arg0->marker->unk14_20 == 0x12) {
                    arg0->yaw_moving = (f32) func_80342244((s32) arg0->yaw_moving);
                }
            }
            if (arg0->unk10_7) {
                arg0->unk6C = (f32)arg1->t1.unk4.bit15;
            }
        }
    }
    return sp84;
}
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B9770/func_803430B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B9770/func_803431D0.s")

s32 func_80343654(Actor *this){
    s32 tmp_v1;
    s32 tmp_a0;
    tmp_v1 = this->unk10_8 ? 0x800 : 0x100;
    tmp_a0 = this->unk10_7 ? 0x1000 : 0x200;
    return tmp_a0 + tmp_v1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B9770/func_80343694.s")

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_B9770/func_803438E0.s")
#else
s32 func_803438E0(Actor *actor, s32 arg1, s32 arg2, s32 arg3) {
    s32 sp4C;
    s32 sp48;
    s32 sp44;
    f32 sp40;
    s32 sp3C;
    s32 temp_v0;
    s32 sp28;

    sp44 = 0;
    sp40 = actor->unk4C;
    sp28 = actor->unk44_14;
    if (sp28 == -1) {
        return 0;
    }
    sp4C = func_803421A4(sp28, actor->unk48);
    if ((actor->unk54 == 0.0f) && (actor->unk138_3 == 0)) {
        if (actor->marker->unk14_20 == 0xB0) {
            actor->unk48 = func_803240E0(D_80371E70[actor->unk44_14], actor->unk48, sp40, &sp44);
        } else {
            actor->unk48 = func_80323FDC(D_80371E70[actor->unk44_14], actor->unk48, sp40, &sp44);
        }
        func_80323240(D_80371E70[actor->unk44_14], actor->unk48, actor->position);
    } else {
        if (actor->unk54 != 0.0f) {
            actor->unk54 -= time_getDelta();
            if (actor->unk54 < 0.0f) {
                actor->unk54 = 0.0f;
            }
        }
        if ((actor->unk138_3 != 0) && func_802501A0(0, actor->unk138_3 + 0x69, 0)) {
            func_80250170(0, actor->unk138_3 + 0x69, 0);
            actor->unk138_3 = 0;
        }
    }
    sp48 = func_803421A4(actor->unk44_14, actor->unk48);
    if (!actor->unk44_1) {
        actor->unk44_1 = TRUE;
        actor->yaw = actor->yaw_moving;
        actor->pitch = actor->unk6C;
    }
    if ((sp4C == sp48) && (sp44 == 0)) {
        func_803431D0(actor, arg1, arg2, arg3);
    } else {
        sp3C = func_80343654(actor);
        if (sp40 > 0.0f) {
            if (sp44 == 0) {
                if (func_80343694(actor, actor->unk44_14, sp4C, sp48, 0, 1) == 2) {
                    D_80371E7C = 1;
                }
            } else if (func_80343694(actor, actor->unk44_14, sp4C, -0x270F, 0, 1) == 0) {
                func_80343694(actor, actor->unk44_14, func_803421A4(actor->unk44_14, func_803237E8(func_80342038(actor->unk44_14))), sp48, 0, 1);
            }
        } else if (sp40 < 0.0f) {
            if (sp44 == 0) {
                func_80343694(actor, actor->unk44_14, sp4C - 1, sp48 - 1, 0, -1);
            } else if (!func_80343694(actor, actor->unk44_14, sp4C - 1, -1, 0, -1)) {
                func_80343694(actor, actor->unk44_14, -0x270F, sp48 - 1, 0, -1);
            }
        }
        temp_v0 = func_80343654(actor);
        if ((sp3C == temp_v0) || ((sp3C != temp_v0) && (sp3C != (arg1 & 0x3F00)))) {
            func_803431D0(actor, arg1, arg2, arg3);
        } else {
            func_803431D0(actor, (arg1 & ~0x3F00) | (temp_v0 & 0x3F00), arg2, arg3);
        }
    }
    return 1;
}
#endif

int func_80343D50(Actor *this, s32 arg1, s32 arg2, s32 arg3){
    s32 s0;
    s0 = 0;
    do{
        D_80371E7C = 0; 
        s0 += func_803438E0(this, arg1, arg2, arg3);
    }while(D_80371E7C);
    return s0 ? 1 : 0;
}

void func_80343DEC(Actor *this){
    func_80343D50(this, func_80343654(this), 0x19, 0x19);
}

void func_80343E20(s32 arg0, s32 arg1, f32 arg2, s32 arg3) {
    u8 temp_v0;

    if (func_8030ED70(func_80255D44(arg0)) != 0) {
        temp_v0 = func_8030D90C();
        if (temp_v0 != 0) {
            sfxsource_setSfxId(temp_v0, func_80255D44(arg0));
            func_8030DBB4(temp_v0, arg2);
            sfxsource_setSampleRate(temp_v0, arg1);
            func_8030E2C4(temp_v0);
            if (D_803858A0[arg3] != 0) {
                func_8030DA44(D_803858A0[arg3]);
            }
            D_803858A0[arg3] = temp_v0;
        }
    } else {
        func_8030E6A4(func_80255D44(arg0), arg2, arg1);
    }
}

struct56s *func_80343F00(s32 indx, f32 arg1[3]){
    struct56s *out;

    out = func_80342038(indx);
    out->unk8[0][0] = arg1[0];
    out->unk8[0][1] = arg1[1];
    out->unk8[0][2] = arg1[2];
    return out;
}

void func_80343F3C(void) {
    s32 i;

    if (D_80371E70 != 0) {
        D_80371E70 = (struct56s *)defrag(D_80371E70);
    }
    if (D_80371E74 != 0) {
        D_80371E74 = defrag(D_80371E74);
    }
    if (D_803858A0 != 0) {
        D_803858A0 = defrag(D_803858A0);
    }

    for(i = 0; i < D_80371E78; i++){
        D_80371E74[i] = defrag(D_80371E74[i]);
        D_80371E70[i] = defrag(D_80371E70[i]);
    }
}

bool func_80344040(Actor *this){
    return func_80323240(D_80371E70[this->unk44_14], this->unk48, this->position);
}
