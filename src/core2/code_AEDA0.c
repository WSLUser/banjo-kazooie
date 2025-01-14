#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern u8 D_80370338[];

/* .bss */
u8 pad_80383610[0x24];
u32 D_80383634;
u32 D_80383638;
s32 D_8038363C;
s32 D_80383640;
s32 D_80383644;

/* .code */
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AEDA0/func_80335D30.s")

void func_8033687C( Gfx **gfx )
 {
     /* Turn off texturing */
     gDPPipeSync((*gfx)++);
     if (D_80370338[0] == 0) {
        gDPSetColorDither((*gfx)++, 0);
        D_80370338[0] = 1;
     }

     if(D_80383634 == 0x0E){
         gDPSetAlphaCompare((*gfx)++, G_AC_NONE);
     }
 }

void func_80336904(Gfx **gfx, Vtx **vtx, BKSprite *sp, u32 frame){
    func_80336924(gfx, vtx, sp, frame, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AEDA0/func_80336924.s")
/*func_80336924(Gfx **gfx, Vtx **vtx, BKSprite *sp, u32 frame, u32 segment){
    u32 chkDataSize_1C0;
    s32 i_1BC;
    Gfx *sp1B4;
    Vtx *sp1B0;
    void *sp1A8;
    BKSpriteFrame *framePtr_18c;
    Vtx *sp184;

    s32 sp48;
    s32 sp44;

    s32 sp_type;
    BKSpriteTextureBlock *chunkPtr;
    u32 chunk_block;
    u32 chunkSize;
    u16* palPtr;
    s32 s2;
    sp184 = *vtx;

    func_80349AD0();
  
    if (sp->type & SPRITE_TYPE_CI4) {
        chkDataSize_1C0 = 1;
    } else if (sp->type & SPRITE_TYPE_CI8) {
        chkDataSize_1C0 = 2;
    } else if (sp->type & 0x40){
        chkDataSize_1C0 = 2;
    } else if (sp->type & 0x100){
        chkDataSize_1C0 = 2;
    } else if (sp->type & SPRITE_TYPE_RGBA16) {
        chkDataSize_1C0 = 4;
    } else if (sp->type & SPRITE_TYPE_RGBA32){
        chkDataSize_1C0 = 8;
    }
  
    func_80335D30(gfx);
    if(D_80383638 || (sp->type & SPRITE_TYPE_CI8)){
        gDPPipelineMode((*gfx)++, G_PM_1PRIMITIVE);
    }

    framePtr_18c = spriteGetFramePtr(sp, frame);

    // //load Palettes for CI4 and CI8
    chunkPtr = ((u32) (framePtr_18c + 1));
    if (sp->type & SPRITE_TYPE_CI4) { //CI4
        gDPSetTextureLUT((*gfx)++, G_TT_RGBA16);
        gDPSetTextureImage((*gfx)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, chunkPtr = (u32)chunkPtr & -8);
        gDPTileSync((*gfx)++);
        gDPSetTile((*gfx)++, G_IM_FMT_RGBA, G_IM_SIZ_4b, 0, 0x0100, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    //     sp1d0 = sp;
        gDPLoadSync((*gfx)++);
        gDPLoadTLUTCmd((*gfx)++, G_TX_LOADTILE, 15);
        gDPPipeSync((*gfx)++);
        chunkPtr = (u32) chunkPtr + 0x10 * sizeof(u16);
    } else if (sp->type & SPRITE_TYPE_CI8) {//CI8
    //     //L80336B28
        gDPSetTextureLUT((*gfx)++, G_TT_RGBA16);
        gDPSetTextureImage((*gfx)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, chunkPtr = (u32)chunkPtr & -8);
        gDPTileSync((*gfx)++);
        gDPSetTile((*gfx)++, G_IM_FMT_RGBA, G_IM_SIZ_4b, 0, 0x0100, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
        gDPLoadSync((*gfx)++);
        gDPLoadTLUTCmd((*gfx)++, G_TX_LOADTILE, 255);
        gDPPipeSync((*gfx)++);
        chunkPtr = (u32) chunkPtr + 0x100 * sizeof(u16);
    }//L80336C0C

    s2 = 0;
    sp1B0 = *vtx;
    sp1B4 = *gfx;
    if(segment){
        gSPVertex((*gfx)++, SEGMENT_ADDR(segment, (s32)sp1B0 - (s32)sp184), 0, 0);
    }else{
        gSPVertex((*gfx)++, sp1B0, 0, 0);
    }

    for(i_1BC = 0; i_1BC < framePtr_18c->chunkCnt; i_1BC++){
        //L80336CA0
        //temp_ra = phi_t2->unk6;
        sp1A8 = ((s32)chunkPtr + 0xF) & ~7;
// //         // temp_a0_3 = arg2->unk2;
// //         // temp_s3 = phi_s2 * 2;

// /    temp_fp = temp_s3 + 2;
        sp1A8 = (((u32) (chunkPtr + 1) + 0xF) & 0xFFFFFFF8);
        if(sp->type & SPRITE_TYPE_RGBA16) { //RGBA16
            gDPLoadTextureBlock((*gfx)++, sp1A8, G_IM_FMT_RGBA, G_IM_SIZ_16b, 
                chunkPtr->w, chunkPtr->h, 0, 0, 0, 0, 0, 0, 0);
        } else if (sp->type & SPRITE_TYPE_RGBA32) { //RGBA32 //L80336E78
            gDPLoadTextureBlock((*gfx)++, sp1A8, G_IM_FMT_RGBA, G_IM_SIZ_32b, 
                chunkPtr->w, chunkPtr->h, 0, 0, 0, 0, 0, 0, 0);
        } else if (sp->type & 1) { //CI4 //L80337020
            gDPLoadTextureBlock((*gfx)++, chunk_block, G_IM_FMT_CI, G_IM_SIZ_16b, 
                chunkPtr->w, chunkPtr->h, 0, 0, 0, 0, 0, 0, 0);
        } else if (sp->type & 4) { //CI8 //L803371C4
            gDPLoadTextureBlock((*gfx)++, chunk_block, G_IM_FMT_CI, G_IM_SIZ_16b, 
                chunkPtr->w, chunkPtr->h, 0, 0, 0, 0, 0, 0, 0);
        } else if (sp->type & 0x100) {
            gDPLoadTextureBlock((*gfx)++, chunk_block, G_IM_FMT_I, G_IM_SIZ_16b, 
                chunkPtr->w, chunkPtr->h, 0, 0, 0, 0, 0, 0, 0);
        } else if (sp->type & 0x40) {
            gDPLoadTextureBlock((*gfx)++, chunk_block, G_IM_FMT_I, G_IM_SIZ_8b, 
                chunkPtr->w, chunkPtr->h, 0, 0, 0, 0, 0, 0, 0);
        }//L803376A8
         gSP2Triangles((*gfx)++, 0, 1, 2, 0, 2, 1, 0, 0);        
        //L803376E4
// // // //         temp_a2 = *arg0;
// // // //         temp_v1_69 = temp_s3 & 0xFF;
// // // //         *arg0 = (void *) (temp_a2 + 8);
// // // //         if (phi_s2 == 0) {
// // // //             temp_t9 = sp48 & 0xFF;
// // // //             phi_a0_7 = (temp_v1_69 << 0x10) | ((temp_fp & 0xFF) << 8) | temp_t9;
// // // //             phi_v1_3 = temp_v1_69;
// // // //             phi_a1 = temp_t9;
// // // //         } else {
// // // //             if (phi_s2 == 1) {
// // // //                 temp_t6 = sp48 & 0xFF;
// // // //                 temp_v1_70 = temp_s3 & 0xFF;
// // // //                 phi_t1_8 = ((temp_fp & 0xFF) << 0x10) | (temp_t6 << 8) | temp_v1_70;
// // // //                 phi_v1_3 = temp_v1_70;
// // // //                 phi_a1 = temp_t6;
// // // //             } else {
// // // //                 temp_t8_5 = sp48 & 0xFF;
// // // //                 temp_v1_71 = temp_s3 & 0xFF;
// // // //                 phi_t1_8 = (temp_t8_5 << 0x10) | (temp_v1_71 << 8) | (temp_fp & 0xFF);
// // // //                 phi_v1_3 = temp_v1_71;
// // // //                 phi_a1 = temp_t8_5;
// // // //             }
// // // //             phi_a0_7 = phi_t1_8;
// // // //         }
// // // //         temp_a2->unk0 = (s32) (phi_a0_7 | 0xB1000000);
// // // //         if (phi_s2 == 0) {
// // // //             temp_a2->unk4 = (s32) ((phi_v1_3 << 0x10) | (phi_a1 << 8) | (sp44 & 0xFF));
// // // //         } else {
// // // //             if (phi_s2 == 1) {
// // // //                 phi_a0_8 = (phi_a1 << 0x10) | ((sp44 & 0xFF) << 8) | phi_v1_3;
// // // //             } else {
// // // //                 phi_a0_8 = ((sp44 & 0xFF) << 0x10) | (phi_v1_3 << 8) | phi_a1;
// // // //             }
// // // //             temp_a2->unk4 = phi_a0_8;
// // // //         }
// // // //         temp_a2_2 = phi_t2->unk0 - temp_v0->unk0;
// // // //         temp_f0 = (f32) D_80383640 / (f32) temp_v0->unk4;
// // // //         phi_t1_7 = temp_v0->unk2 - phi_t2->unk2;
// // // //         phi_t0 = 0;
// // // // loop_95:
// // // //         temp_a1 = ((temp_ra << 6) * phi_t0) - 0x20;
// // // //         temp_f4 = (s32) ((f32) phi_t1_7 * ((f32) D_80383644 / (f32) temp_v0->unk6));
// // // //         temp_t3 = phi_t3 - 1;
// // // //         temp_lo = (phi_t2->unk4 - 1) * 0;
// // // //         phi_a3 = phi_a3_4;
// // // //         phi_lo = temp_lo;
// // // //         phi_v1_4 = 0;
// // // //         phi_a3_2 = phi_a3_4;
// // // //         phi_lo_2 = temp_lo;
// // // //         phi_v1_5 = 0;
// // // //         if (temp_t3 != 0) {
// // // // loop_96:
// // // //             phi_a3->unk2 = (s16) temp_f4;
// // // //             phi_a3->unk4 = (u16)0;
// // // //             temp_a3_2 = phi_a3 + 0x10;
// // // //             temp_a3_2->unk-10 = (s16) (s32) ((f32) (phi_lo + temp_a2_2) * temp_f0);
// // // //             temp_a3_2->unk-6 = temp_a1;
// // // //             temp_a3_2->unk-4 = 0x7F80;
// // // //             temp_v1_72 = phi_v1_4 + 1;
// // // //             temp_a3_2->unk-8 = (s16) (((phi_t2->unk4 << 6) * phi_v1_4) - 0x20);
// // // //             temp_lo_2 = (phi_t2->unk4 - 1) * temp_v1_72;
// // // //             phi_a3 = temp_a3_2;
// // // //             phi_lo = temp_lo_2;
// // // //             phi_v1_4 = temp_v1_72;
// // // //             phi_a3_2 = temp_a3_2;
// // // //             phi_lo_2 = temp_lo_2;
// // // //             phi_v1_5 = temp_v1_72;
// // // //             if (temp_v1_72 != temp_t3) {
// // // //                 goto loop_96;
// // // //             }
// // // //         }
// // // //         phi_a3_2->unk2 = (s16) temp_f4;
// // // //         phi_a3_2->unk4 = (u16)0;
// // // //         temp_t3_2 = temp_t3 + 1;
// // // //         temp_a3_3 = phi_a3_2 + 0x10;
// // // //         temp_a3_3->unk-10 = (s16) (s32) ((f32) (phi_lo_2 + temp_a2_2) * temp_f0);
// // // //         temp_a3_3->unk-6 = temp_a1;
// // // //         temp_a3_3->unk-4 = 0x7F80;
// // // //         temp_a3_3->unk-8 = (s16) (((phi_t2->unk4 << 6) * phi_v1_5) - 0x20);
// // // //         temp_t0 = phi_t0 + 1;
// // // //         phi_t3 = temp_t3_2;
// // // //         phi_t1_7 = (phi_t1_7 - temp_ra) + 1;
// // // //         phi_t0 = temp_t0;
// // // //         phi_a3_4 = temp_a3_3;
// // // //         if (temp_t0 != temp_t3_2) {
// // // //             goto loop_95;
// // // //         }
// // // //         temp_s2_2 = phi_s2 + 4;
// // // //         phi_s2_3 = temp_s2_2;
// // // //         if (temp_s2_2 == 0x10) {
            if (segment != 0) {
                gSPVertex((*gfx)++, SEGMENT_ADDR(segment, *vtx - sp184, 16, 0);
            } else {
                gSPVertex((*gfx)++, 0x80001234, 16, 0);
            }
// // // //             temp_v1_73 = *arg0;
// // // //             sp1B0 = temp_a3_3;
// // // //             sp1B4 = temp_v1_73;
// // //              if (arg4 != 0) {
// // // //                 *arg0 = (void *) (temp_v1_73 + 8);
// // // //                 temp_v1_73->unk0 = 0x400FFFF;
// // // //                 temp_v1_73->unk4 = (void *) ((arg4 << 0x18) + (temp_a3_3 - sp184));
// // // //                 phi_s2_3 = 0;
// // //              } else {
// // // //                 *arg0 = (void *) (temp_v1_73 + 8);
// // // //                 temp_v1_73->unk0 = 0x400FFFF;
// // // //                 temp_v1_73->unk4 = temp_a3_3;
// // // //                 phi_s2_3 = 0;
// // //              }
// // // //         }
           chunkSize = chunkPtr->w * chunkPtr->h * chkDataSize_1C0;
           chunkPtr = (s32)sp1A8 + chunkSize/2;
    }

    gDPPipeSync((*gfx)++);
//     if((sp->type & SPRITE_TYPE_CI4) || (sp->type & SPRITE_TYPE_CI8)){ //CI4 or CI8 //L80337AD8
//         gDPSetTextureLUT((*gfx)++, G_TT_NONE);
//     }
//     if( D_80383638 || sp->type & SPRITE_TYPE_CI8){
//         //L80337B18
//         gDPPipelineMode((*gfx)++, G_PM_NPRIMITIVE);
//     }//L80337B30
//     func_8033687C(gfx);

    if(chkDataSize_1C0);
}//*/

#ifndef NONMATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AEDA0/func_80337B68.s")
#else
void func_80337B68(Gfx **gfx, Vtx **vtx, Struct84s *texture_list, s32 texture_index) {
    s16 temp_a1;
    s32 temp_at;
    s32 temp_lo;
    s32 temp_lo_2;
    s32 temp_t9;
    s32 temp_v1;
    s32 var_a0;
    s32 var_a0_2;
    s32 var_a1;
    s32 v2;
    s32 var_ra;
    s32 var_s1;
    s32 var_s1_2;
    s32 var_t0;
    s32 var_t0_2;
    s32 v0;
    s32 var_t2;
    s32 v1;
    s32 var_t3;
    s32 v3;
    s32 var_t4;
    s32 var_v1;
    s32 var_v1_2;
    s32 var_v1_3;
    s32 var_v1_4;
    s32 var_v1_5;
    s32 var_v1_6;
    s32 var_v1_7;
    void *temp_a0;
    void *temp_a0_2;
    void *temp_a0_3;
    void *temp_a0_4;
    void *temp_a0_5;
    void *temp_a0_6;
    void *temp_a2;
    void *temp_a2_2;
    void *temp_s0;
    Vtx *temp_s3;
    BKSpriteTextureBlock *txtr_ptr;
    u16 *var_t5;

    func_80335D30();
    txtr_ptr = func_8033EFB0(texture_list, texture_index);
    temp_v1 = D_80383644;
    temp_lo = temp_v1 / 3;
    temp_s3 = *vtx;
    var_s1 = 0;
    var_t4 = (s32) (((f32) txtr_ptr->y / (f32) txtr_ptr->h) * (f32) temp_v1);
    for(var_s1 = 0; var_s1 < 3; var_s1++){
        var_a0 = var_t4;
        for(var_t2 = 0; var_t2 < 2; var_t2++){
            for(var_v1 = 0; var_v1 < 2; var_v1++){
                (*vtx)->v.ob[0] = (s16) ((var_v1 * D_80383640) + (s32) (-((f32) txtr_ptr->x / (f32) txtr_ptr->w) * (f32) D_80383640));
                (*vtx)->v.ob[1] = (s16) (-(var_t2 * (D_80383644/3) - (var_s1*(D_80383644/3))) + (s32) (((f32) txtr_ptr->x / (f32) txtr_ptr->w) * (f32) D_80383644));
                (*vtx)->v.ob[2] = 0;
                (*vtx)->v.tc[0] = ((txtr_ptr->w - 1) * var_v1) << 6;
                (*vtx)->n.tc[1] = (0x1A * var_v1) << 6;
                *(u32*)((*vtx)->v.cn) = 0x00007F80;
                (*vtx)++;
            }
            var_a0 += -temp_lo;
        }
        var_t4 -= temp_lo;
    }
    var_t5 = (u16*)(txtr_ptr + 1);
    v0 = 0;
    v1 = 1;
    v3 = 3;
    v2 = 2;
    gSPVertex((*gfx)++, temp_s3, 12, 0);
    for(var_s1 = 0; var_s1 < 3; var_s1++){
        gDPLoadTextureBlock((*gfx)++, var_t5, G_IM_FMT_RGBA, G_IM_SIZ_16b, txtr_ptr->w, ((var_s1 < 2) ? 1 : 0) + 0x1A, NULL, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        gSP2Triangles((gfx++), v0, v1, v3, var_s1,  v2, v0, v3,var_s1);
        var_t5 += txtr_ptr->w * 0x1A;
        v0 += 4;
        v1 += 4;
        v3 += 4;
        v2 += 4;
    }
    func_8033687C(gfx);
}
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AEDA0/func_80338048.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AEDA0/func_803380A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AEDA0/func_803380F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AEDA0/func_803381B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AEDA0/func_80338270.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AEDA0/func_803382B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AEDA0/func_803382D8.s")

void func_803382E4(s32 arg0){
    D_80383634 = arg0;
}

void func_803382F0(s32 arg0){
    D_80383638 = arg0;
}

void func_803382FC(s32 arg0){
    D_8038363C = arg0;
}

void func_80338308(s32 arg0, s32 arg1){
    D_80383640 = arg0;
    D_80383644 = arg1;
}

void func_8033831C(s32 *arg0, s32 *arg1){
    *arg0 = D_80383640;
    *arg1 = D_80383644;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AEDA0/func_80338338.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AEDA0/func_80338354.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AEDA0/func_80338370.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/code_AEDA0/func_8033837C.s")
