#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern void func_8028E668(f32[3], f32, f32, f32);

typedef struct {
    s32 unk0;
    s32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    u8  pad18[1];
    u8  unk19;
}ActorLocal_FP_2350;

Actor *func_80388740(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void func_80388F4C(Actor *this);
void func_803896FC(Actor *this);

/* .data */
extern ActorAnimationInfo D_80391C80[];

extern ActorInfo D_80391CE8 = { 0x97, 0xC8, 0x38A, 
    0x1, D_80391C80, 
    func_80388F4C, func_803896FC, func_80388740, 
    { 0x0, 0x0}, 0, 1.4f, { 0x0, 0x0, 0x0, 0x0}
};

extern s32 D_80392F20[3];

/* .code */
#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_2350/func_80388740.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_2350/func_803888E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_2350/func_80388A50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_2350/func_80388A94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_2350/func_80388B18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_2350/func_80388C88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_2350/func_80388CA0.s")

void func_80388D70(ActorMarker *this_marker, ActorMarker *other_marker);
#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_2350/func_80388D70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_2350/func_80388EE8.s")

f32 func_8038BE20(f32 arg0[3]);
#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_2350/func_80388F4C.s")

void func_80388F54(ActorMarker *marker);
#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_2350/func_80388F54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_2350/func_80388F90.s")

bool func_80388FE8(Actor *this, f32, f32);
#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_2350/func_80388FE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_2350/func_803890DC.s")

void func_803893E4(Actor *this, f32, s32);
#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_2350/func_803893E4.s")

void func_803895E0(void);
#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_2350/func_803895E0.s")

void func_803896FC(Actor *this){
    ActorLocal_FP_2350 *local = (ActorLocal_FP_2350 *)&this->local;
    f32 sp58;
    f32 sp54;
    s32 sp3C[6];
    
    sp58 = func_8038BE20(this->position);
    sp54 = time_getDelta();
    func_8024E55C(0, sp3C);
    
    if(!this->unk16C_4){
        this->unk16C_4 = TRUE;
        this->marker->unk40_23 = FALSE;
        this->marker->propPtr->unk8_3 = FALSE;
        this->marker->unk2C_1 = TRUE;
        this->unk44_31 = func_8030ED2C(SFX_18_BIGBUTT_SLIDE, 2);
        D_80392F20[0] = this->position_x;
        D_80392F20[1] = this->position_y;
        D_80392F20[2] = this->position_z;
        this->unk1C[0] = this->yaw;
        local->unk0 = 0;
        local->unk4 = 0;
       local->unk8 = 0.0f;
       local->unkC = 0.0f;
       local->unk10 = 0.0f;
       local->unk8 = 1.0f;
        func_8038B9B0(this->marker);
        this->unk38_31 = 0;
        func_80388C88(this);
        func_802C3BF8(func_803895E0);
        if(jiggyscore_isCollected(JIGGY_30_FP_BOGGY_2)){
            local->unk19 = 2;
            this->unk4C = 900.0f;
        }
        else if(jiggyscore_isSpawned(JIGGY_30_FP_BOGGY_2)){
            local->unk19 = 1;
            this->unk38_31 = 2;
            this->unk4C = 600.0f;
            func_80328B8C(this, 11, 0.0001f, 1);
        }
        else{
            local->unk19  = 1;
            this->unk4C = 600.0f;
            mapSpecificFlags_set(4, TRUE);
        }
    }//L803898CC

    func_8028E668(this->position, 200.0f, -200.0f, 140.0f);
    if(!func_8038A1A0(this->marker)){
        switch(this->unk38_31){
            case 1://L80389920
                func_80328B8C(this, 9, 0.0001f, 1);
                break;
            case 2://L80389938
                func_80328B8C(this, 10, 0.0001f, 1);
                break;
        }
    }//L80389950

    if(0.0 <local->unk10 - sp54)
       local->unk10 =local->unk10 - sp54;
    else
       local->unk10 = 0.0f;

    switch(this->state){
        case 1:// L803899B8
            if(func_80388CA0(this)){
                func_80388B18(this, local->unk19);
            }//L803899DC
            else if(!jiggyscore_isCollected(JIGGY_30_FP_BOGGY_2) && func_8028ECAC() == 12){
                func_803888E4(this);
            }
            else if( func_80329530(this, 0x1C2)
                && !func_8028ECAC()
                && func_8028F20C()
                && func_8028EFC8()
                && sp3C[1] == 1
                && !func_803114B0()
            ){
                if( local->unk19 == 1 
                    && player_getTransformation() != TRANSFORM_4_WALRUS
                    && func_803203FC(0xb3)
                ){
                    func_80311480(0xC01, 0xf, this->position, this->marker, func_80388D70, NULL);
                }
                else if( local->unk19 == 2){
                    if( player_getTransformation() == TRANSFORM_4_WALRUS
                        && func_803203FC(0xb4)
                    ){
                        func_80311480(0xC08, 0xf, this->position, this->marker, func_80388D70, NULL);
                    }
                    else if( player_getTransformation() != TRANSFORM_4_WALRUS){
                        func_80388A94(this);
                    }
                }
            }
            break;

        case 4:// L80389B50
            if(0.0 < local->unk14){
                local->unk14 -= sp54;
            }
            else{
                local->unk14 = 0.0f;
                if( randf() < 0.02 && sp58 < 0.0){
                    if(randf() < 0.5)
                        func_80328B8C(this, 5, 0.0001f, 1);
                    else
                        func_80328B8C(this, 6, 0.0001f, 1);
                }//L80389C18

                func_803893E4(this, sp58, local->unk19);
                func_80388F90(this);
                if(0.0 ==local->unk10 && func_80388FE8(this, sp58,local->unkC)){
                   local->unk10 = 1.5f;
                }
            }//L80389C78
            break;

        case 5:// L80389C80
        case 6:// L80389C80
            if(actor_animationIsAt(this, 0.9999f) || sp58 >= 0.0){
                func_80328B8C(this, 4, 0.0001f, 1);
            }//L80389CC8
            
            func_803893E4(this, sp58, local->unk19);
            func_80388F90(this);
            if(0.0 == local->unk10 && func_80388FE8(this, sp58, local->unkC)){
                local->unk10 = 1.5f;
            }
            break;

        case 7:// L80389D34
            if(actor_animationIsAt(this, 0.9999f)){
                func_80328B8C(this, 4, 0.0001f, 1);
            }//L80389D60
            func_803893E4(this, sp58, local->unk19);
            func_80388F90(this);
            break;

        case 8:// L80389D84
            func_80343DEC(this);
            if(this->unk4C < 740.0f){
                this->unk4C += 10.0f;
            }
            else if(740.0f < this->unk4C) {
                this->unk4C -= 10.0f;
            }
            func_803890DC(this, local->unk19);
            func_80388F90(this);
            if(0.0 == local->unk10 && func_80388FE8(this, sp58, local->unkC)){
                local->unk10 = 1.5f;
            }

            break;

        case 9:// L80389E48
            func_803893E4(this, sp58, local->unk19);
            if(this->unk48 < 0.99999999999){
                func_80388F90(this);
            }
            if(actor_animationIsAt(this, 0.9999f)){
                func_80328B8C(this, 11, 0.0001f, 1);
            }
            break;

        case 10:// L80389EB4
            func_803893E4(this, sp58, local->unk19);
            if(this->unk48 < 0.99999999999){
                func_80388F90(this);
            }

            if(actor_animationIsAt(this, 0.9999f)){
                func_80328B8C(this, 11, 0.0001f, 1);
            }
            break;

        case 11:// L80389F20
            func_803890DC(this, local->unk19);
            
            if(!actor_playerIsWithinDist(this, 2000)
                && !this->marker->unk14_21
            ){
                switch(local->unk19){
                    case 1: //L80389F78
                        if(this->unk38_31 == 2){
                            if(jiggyscore_isCollected(JIGGY_30_FP_BOGGY_2)){
                                func_802C3C88(func_80388F54, this->marker);
                                func_8038B9BC();
                                marker_despawn(this->marker);
                            }
                        }
                        else{
                            func_8038B9BC();
                            marker_despawn(this->marker);
                        }

                        break;

                    case 2: //L80389FDC
                        if(this->unk38_31 == 2){
                            if(jiggyscore_isCollected(JIGGY_2C_FP_BOGGY_3)){
                                func_8038B9BC();
                                marker_despawn(this->marker);
                                mapSpecificFlags_set(0xC, TRUE);
                            }
                        }
                        else{
                            func_8038B9BC();
                            marker_despawn(this->marker);
                        }
                        break;
                }
            }
            break;
    }//L8038A034

    D_80392F20[0] = (s32)this->position[0];
    D_80392F20[1] = (s32)this->position[1];
    D_80392F20[2] = (s32)this->position[2];
    this->unk1C[0] = this->yaw;
    local->unkC = sp58;
}

void func_8038A09C(f32 arg0[3]){
    arg0[0] = (f32)D_80392F20[0];
    arg0[1] = (f32)D_80392F20[1];
    arg0[2] = (f32)D_80392F20[2];
}

void func_8038A0E4(UNK_TYPE(s32) arg0, ActorMarker *marker){
    Actor *actor = marker_getActor(marker);
    
    if(actor){
        if(actor->state != 7){
            func_80328B8C(actor, 7, 0.0001f, 1);
        }
        else{
            func_80328B8C(actor, 4, 0.0001f, 1);
        }
    };
}

void func_8038A150(UNK_TYPE(s32) arg0, ActorMarker *marker){
    Actor *actor = marker_getActor(marker);
    
    if(actor && actor->state != 8){
        func_80328B8C(actor, 8, 0.0001f, 1);
    };
}

bool func_8038A1A0(ActorMarker *marker){
    Actor *actor = marker_getActor(marker);
    switch (actor->state){
        case 9:
        case 10:
        case 11:
            return TRUE;
        default:
            return FALSE;
    }
}
