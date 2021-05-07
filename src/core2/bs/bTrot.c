#include <ultra64.h>
#include "functions.h"
#include "variables.h"

f32 func_80297AF0(void);
void func_80298D54(f32, f32);
void func_80289EC8(f32, f32, f32, f32);
void func_80289EF8(f32);
int func_80297C04(f32);

extern f32 D_80364ABC;
extern f32 D_80364AC0;

extern f32 D_8037D3A0;
extern u8 D_8037D3A4;

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bTrot/func_802A87C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bTrot/func_802A880C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bTrot/func_802A8850.s")

f32 func_802A88B0(void);
#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bTrot/func_802A88B0.s")

f32 func_802A8900(void);
#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bTrot/func_802A8900.s")

f32 func_802A8934(void);
#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bTrot/func_802A8934.s")

f32 func_802A8984(void);
#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bTrot/func_802A8984.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bTrot/func_802A89D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bTrot/func_802A8A40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bTrot/func_802A8AD8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bTrot/func_802A8BB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bTrot/func_802A8C60.s")

void func_802A8C98(AnimCtrl *aCtrl, enum asset_e arg1){
    if(func_80287790(aCtrl) != arg1){
        animctrl_setIndex(aCtrl, arg1);
        func_8028774C(aCtrl, func_802877D8(aCtrl));
        func_802875AC(aCtrl, "bsbtrot.c", 0x12e);

    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bTrot/func_802A8D00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bTrot/func_802A8D34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bTrot/func_802A8D84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bTrot/func_802A8E3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bTrot/func_802A8EA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bTrot/func_802A8F34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bTrot/func_802A8F60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bTrot/func_802A8FB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bTrot/func_802A9010.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bTrot/func_802A9030.s")

void func_802A9054(void){
    f32 tmp = 1.0f;
    func_80289EC8(func_802A8900(), func_802A88B0(), func_802A8984(), func_802A8934());
    if(func_8028B394()){
        tmp = mlMap_f(func_80297AF0(), 0.0f, 1.0f, 0.6f, 0.9f);
        func_80289EF8(tmp);
    }
    else{
        func_80289EF8(tmp);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bTrot/func_802A90F8.s")

void bsbtrot_walk_update(void){
    enum bs_e sp1C = 0;
    AnimCtrl *aCtrl = player_getAnimCtrlPtr();

    func_802A8850();
    func_802A9054();
    func_802A8AD8();
    func_802A8C98(aCtrl, func_802A9030());
    func_80299628(1);
    func_802A89D4();
    if(func_802878E8(aCtrl, 0.2781f))
        func_802A880C(1);

    func_8029AD28(0.2781f, 4);
    if(func_802878E8(aCtrl, 0.7781f))
        func_802A880C(0);

    func_8029AD28(0.7781f, 3);
    if(func_80291698(3)){
        func_802A87C0();
    }
    else{
        if(func_802878E8(aCtrl, 0.2115f) || func_802878E8(aCtrl, 0.7115f))
            func_802A87C0();
    }
    if(!func_8029B300() && func_80297C04(1.0f))
        sp1C = BS_BTROT_IDLE;

    if(func_8028B094())
        sp1C = BS_BTROT_FALL;

    if(func_802A8C60())
        sp1C = BS_BTROT_EXIT;

    if(button_pressed(BUTTON_A))
        sp1C = func_802A8D34(sp1C);

    if(func_8028B1E0())
        sp1C = BS_BTROT_SLIDE;

    if(player_inWater())
        sp1C = BS_SWIM_IDLE;

    bs_setState(func_8029CA94(sp1C));
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bTrot/func_802A9300.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bTrot/func_802A9320.s")

void bsbtrot_jump_init(void){
    AnimCtrl * aCtrl = player_getAnimCtrlPtr();

    func_802874AC(aCtrl);
    animctrl_setIndex(aCtrl, ANIM_BANJO_BTROT_JUMP);
    animctrl_setDuration(aCtrl, 1.4f);
    func_802876C0(aCtrl, 0.1f);
    func_8028774C(aCtrl, 0.2f);
    func_802876CC(aCtrl, 0.0f,  0.4002f);
    func_80287674(aCtrl, 1);
    func_802875AC(aCtrl, "bsbtrot.c", 0x272);
    func_802A8A40();
    func_80289F10(1);
    func_802991A8(1);
    func_8029957C(3);
    func_802978DC(6);
    if(func_8029B2E8() != 0.0f)
        player_setMovingYaw(func_8029B33C());

    func_8029797C(player_getMovingYaw());
    func_802A89D4();
    func_802979AC(player_getMovingYaw(), func_80297A64());
    func_802979A0(D_80364ABC);
    func_80297BEC(D_80364AC0);
    func_8030E484(0x48);
    D_8037D3A4 = 0;
}

void bsbtrot_jump_update(void){
    enum bs_e sp2C = 0;
    AnimCtrl * aCtrl = player_getAnimCtrlPtr();
    f32 sp1C[3];
    func_802A8AD8();
    if(func_80291698(3))
        func_802A87C0();

    if(func_802933C0(0xF))
        func_802978A4();
    else
        func_802A89D4();

    func_80297A88(sp1C);
    if(func_80295590(8) && 0.0f < sp1C[1])
        func_80297B70();
    
    switch(D_8037D3A4){
        case 0://L802A9530
            if(func_802878C4(aCtrl)){
                func_802876CC(aCtrl, 0.0f, 0.4653f);
                animctrl_setDuration(aCtrl, 10.0f);
                func_80287674(aCtrl, 1);
                D_8037D3A4 = 1;
            }
            break;
        case 1://L802A9578
            if(func_8028B254(0x8C)){
                func_802876CC(aCtrl, 0.0f, 0.7328f);
                animctrl_setDuration(aCtrl, 1.4f);
                func_80287674(aCtrl, 1);
                D_8037D3A4 = 2;
            }
            break;
        case 2://L802A95C4
            func_80299628(1);
            if(func_8028B2E8()){
                func_8029C5E8();
                func_802876CC(aCtrl, 0.0f, 0.8798f);
                animctrl_setDuration(aCtrl, 0.9f);
                func_80287674(aCtrl, 1);
                func_8029957C(1);
                D_8037D3A4 = 3;
                if(220.0f < func_80297A64())
                    func_80299AAC();
                func_8029C22C();
            }
            break;
        case 3://L802A9660
            if(220.0f < func_80297A64())
                func_80299AAC();
            func_802A9320();
            func_80299628(1);
            if(func_802878C4(aCtrl)){
                func_802876CC(aCtrl, 0.0f, 0.8898f);
                animctrl_setDuration(aCtrl, 2.0f);
                func_80287674(aCtrl, 1);
                D_8037D3A4 = 4;
            }
            func_8029C22C();
            break;
        case 4://L802A96F0
            if(220.0f < func_80297A64())
                func_80299AAC();
            
            func_802A9320();
            func_80299628(1);
            if(func_802878C4(aCtrl)){
                func_802876CC(aCtrl, 0.0f, 1.0f);
                animctrl_setDuration(aCtrl, 1.2f);
                func_80287674(aCtrl, 1);
                D_8037D3A4 = 5;
            }
            func_8029C22C();
            break;
        case 5://L802A9780
            if(220.0f < func_80297A64())
                func_80299AAC();
            func_802A9320();
            func_80299628(1);
            if(func_802878C4(aCtrl))
                sp2C = BS_BTROT_IDLE;
            break;
    }//LL802A97D0

    if(func_80295158())
        sp2C = BS_BPECK;

    if(func_8028B424())
        sp2C = BS_FALL_TUMBLING;

    if(player_inWater())
        sp2C = BS_LANDING_IN_WATER;
    
    if(func_8028B2E8()){
        if(button_pressed(BUTTON_A))
            sp2C = func_802A8D34(sp2C);
        
        if(func_8028B1E0())
            sp2C = BS_BTROT_SLIDE;
    }

    bs_setState(sp2C);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bTrot/func_802A9864.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bTrot/func_802A988C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bTrot/func_802A98C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bTrot/func_802A9904.s")

void bsbtrot_slide_init(void){
    AnimCtrl *aCtrl = player_getAnimCtrlPtr();
    func_802874AC(aCtrl);
    animctrl_setIndex(aCtrl, ANIM_BANJO_BTROT_JUMP);
    func_8028774C(aCtrl, 0.069f);
    func_80287674(aCtrl, 3);
    func_802875AC(aCtrl, "bsbtrot.c", 0x382);
    func_802A8A40();
    func_8029C7F4(1,1,3,3);
    func_8029797C(player_getMovingYaw());
    func_802979AC(player_getMovingYaw(), func_80297A64());
    func_8029E070(1);
    func_8029E064(1);
    func_80297FB0(1000.0f, 12.0f);
    func_80298D54(1000.0f, 12.0f);
    func_80297970(0.0f);
    func_80299AAC();
    D_8037D3A0 = 1.0f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bTrot/func_802A9A34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bTrot/func_802A9B78.s")

int bsbtrot_inSet(s32 move_indx){
    return (move_indx == BS_BTROT_IDLE)
    || (move_indx == BS_BTROT_WALK)
    || (move_indx == BS_BTROT_JUMP)
    || (move_indx == BS_BTROT_EXIT)
    || (move_indx == BS_BTROT_SLIDE)
    || (move_indx == BS_BTROT_ENTER)
    || (move_indx == 0x79)
    || (move_indx == BS_BTROT_OW)
    || (move_indx == BS_BTROT_FALL)
    || (move_indx == 0x9a);
}

void bsbtrot_fall_init(void){
    AnimCtrl * aCtrl = player_getAnimCtrlPtr();
    func_802874AC(aCtrl);
    animctrl_setIndex(aCtrl, ANIM_BANJO_BTROT_JUMP);
    animctrl_setDuration(aCtrl, 1.4f);
    func_8028774C(aCtrl, 0.4653f);
    func_80287674(aCtrl, 3);
    func_802875AC(aCtrl, "bsbtrot.c", 0x400);
    func_802A8A40();
    func_8029C7F4(1,1,3,6);
    func_8029797C(player_getMovingYaw());
    func_802A89D4();
    func_802979AC(player_getMovingYaw(), func_80297A64());
    D_8037D3A4 = 0;
}

void bsbtrot_fall_update(void){
    enum bs_e sp2C = 0;
    AnimCtrl *aCtrl = player_getAnimCtrlPtr();
    f32 sp1C[3];
    func_802A8AD8();
    if(func_80291698(3))
        func_802A87C0();

    if(func_802933C0(0xf))
        func_802978A4();
    else
        func_802A89D4();

    func_80297A88(sp1C);
    switch (D_8037D3A4){
    case 0://L802A9D90
        if(func_8028B254(0x8C)){
            func_802876CC(aCtrl, 0.0f, 0.7328f);
            animctrl_setDuration(aCtrl, 1.4f);
            func_80287674(aCtrl, 1);
            D_8037D3A4 = 1;
        }
        break;
    case 1://L802A9DDC
        func_80299628(1);
        if(func_8028B2E8()){
            func_8029C5E8();
            func_802876CC(aCtrl, 0.0f, 0.8798f);
            animctrl_setDuration(aCtrl, 0.9f);
            func_80287674(aCtrl, 1);
            func_8029957C(1);
            if(220.0f < func_80297A64()){
                func_80299AAC();
            }
            func_8029C22C();
            D_8037D3A4 = 2;
        }
        break;
    case 2://L802A9E78
        if(220.0f < func_80297A64())
            func_80299AAC();
        
        func_802A9320();
        func_80299628(1);
        if(func_802878C4(aCtrl)){
            func_802876CC(aCtrl, 0.0f, 0.8898f);
            animctrl_setDuration(aCtrl, 2.0f);
            func_80287674(aCtrl, 1);
            D_8037D3A4 = 3;
        }
        func_8029C22C();
        break;
    case 3://L802A9F08
        if(220.0f < func_80297A64())
            func_80299AAC();

        func_802A9320();
        func_80299628(1);
        if(func_802878C4(aCtrl)){
            func_802876CC(aCtrl, 0.0f, 1.0f);
            animctrl_setDuration(aCtrl, 1.2f);
            func_80287674(aCtrl, 1);
            D_8037D3A4 = 4;
        }
        func_8029C22C();
        break;
    case 4://802A9F98
        if(220.0f < func_80297A64())
            func_80299AAC();
        
        func_802A9320();
        func_80299628(1);
        if(func_802878C4(aCtrl))
            sp2C = BS_BTROT_IDLE;
        break;
    }//LL802A9FE8

    if(player_inWater())
        sp2C = BS_LANDING_IN_WATER;
    
    if(func_8028B424())
        sp2C = BS_FALL_TUMBLING;

    if(func_8028B2E8()){
        if(button_pressed(BUTTON_A))
            sp2C = func_802A8D34(sp2C);

        if(func_8028B1E0())
            sp2C = BS_BTROT_SLIDE;
    }

    bs_setState(sp2C);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bTrot/func_802AA068.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bTrot/func_802AA088.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bTrot/func_802AA0E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bTrot/func_802AA134.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bTrot/func_802AA15C.s")

void bsbtrot_ow_update(void){
    enum bs_e sp1C = 0;
    if(func_802987B4() == 2)
        func_802B6FA8();

    if(func_80289FE8(0.3f))
        func_80292EA4();

    if(func_8028B424())
        sp1C = BS_FALL_TUMBLING;

    if(func_8028B2E8() && func_80289FC4())
        sp1C = BS_BTROT_IDLE;

    if(func_802878C4(player_getAnimCtrlPtr()) && player_inWater())
        sp1C = BS_SWIM_IDLE;

    bs_setState(sp1C);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bTrot/func_802AA338.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bTrot/func_802AA378.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bTrot/func_802AA3A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/bs/bTrot/func_802AA3D0.s")
