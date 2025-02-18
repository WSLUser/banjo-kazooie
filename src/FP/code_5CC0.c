#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern Actor *func_802EBAE0(UNK_TYPE(s32), f32 position[3], f32 rotation[3], f32 scale, UNK_TYPE(s32), UNK_TYPE(s32), UNK_TYPE(s32), f32, UNK_TYPE(s32));

Actor *func_8038C1F8(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx);
void func_8038C9A0(Actor *this);

/* .data */
extern ActorAnimationInfo D_80391F50[];

extern ActorInfo D_80391F88 = { MARKER_200_TWINKLY_BLUE, ACTOR_332_TWINKLY_BLUE, ASSET_448_MODEL_TWINKLY_BLUE,
    0x1, D_80391F50,
    func_8038C9A0, func_80326224, func_8038C1F8,
    0, 0, 1.0f, 0
};

extern ActorInfo D_80391FAC = { MARKER_201_TWINKLY_GREEN, ACTOR_333_TWINKLY_GREEN, ASSET_449_MODEL_TWINKLY_GREEN,
    0x1, D_80391F50,
    func_8038C9A0, func_80326224, func_8038C1F8,
    0, 0, 1.0f, 0
};

extern ActorInfo D_80391FD0 = { MARKER_202_TWINKLY_ORANGE, ACTOR_334_TWINKLY_ORANGE, ASSET_44A_MODEL_TWINKLY_ORANGE,
    0x1, D_80391F50,
    func_8038C9A0, func_80326224, func_8038C1F8,
    0, 0, 1.0f, 0
};

extern ActorInfo D_80391FF4 = { MARKER_203_TWINKLY_RED, ACTOR_335_TWINKLY_RED, ASSET_44B_MODEL_TWINKLY_RED,
    0x1, D_80391F50,
    func_8038C9A0, func_80326224, func_8038C1F8,
    0, 0, 1.0f, 0
};

extern s32 D_80392018[4];
extern struct43s D_80392028;
extern f32 D_80392070[3];
extern f32 D_8039207C[3];
extern f32 D_80392088[3];
extern f32 D_80392094[3];
extern s32 D_803920A0[4];
extern s32 D_803920B0[4];

extern f64 D_80392D80;
extern f64 D_80392D88;
extern f64 D_80392D90;
extern f32 D_80392D98;
extern f32 D_80392D9C;
extern f32 D_80392DA0;
extern f32 D_80392DA4;
extern f32 D_80392DA8;
extern f32 D_80392DAC;
extern f32 D_80392DB0;
extern f64 D_80392DB8;
extern f64 D_80392DC0;
extern f64 D_80392DC8;

// C00999999999999A 
// C00999999999999A
// 3FEFFFEB074A771D 
// 3F99999A 
// 3FA66666
// 44DAC000
// 455AC000
// 3FB33333
// 44DAC000
// 455AC000
// C00999999999999A
// 3FEFFF2E48E8A71E
// 3FEFFFFDE7210BE9

/* .code */
Actor *func_8038C0B0(ActorMarker *marker, UNK_TYPE(s32) arg1, f32 arg2, UNK_TYPE(s32) arg3){
    UNK_TYPE(s32) sp5C = func_8033A12C(func_80330B1C(marker));
    Actor *this = marker_getActor(marker);
    f32 sp4C[3];
    f32 sp40[3];
    f32 sp3C;

    sp4C[0] = (f32)marker->propPtr->x;
    sp4C[1] = (f32)marker->propPtr->y;
    sp4C[2] = (f32)marker->propPtr->z;

    sp40[0] = (f32)marker->pitch;
    sp40[1] = this->unk60;
    sp40[2] = (f32)marker->roll;
    sp3C = this->scale;
    if(func_802EA190(marker->unk20)){
        return func_802EBAE0(sp5C, sp4C, sp40, sp3C, NULL, marker->unk20, arg1, arg2, arg3);
    }
    else{
        return NULL;
    }
}

Actor *func_8038C1F8(ActorMarker *marker, Gfx **gfx, Mtx **mtx, Vtx **vtx){
    Actor *this = marker_getActor(marker);
    func_8033A45C(2, this->unk38_31);
    func_8033A45C(1, func_8033A0F0(2) ^ 1);
    return func_80325888(marker, gfx, mtx, vtx);
}

void func_8038C260(f32 position[3], s32 count, enum asset_e model_id){
    ParticleEmitter *pCtrl;

    pCtrl = partEmitList_pushNew(count);
    particleEmitter_setModel(pCtrl, model_id);
    particleEmitter_setPosition(pCtrl, position);
    particleEmitter_setPositionVelocityAndAccelerationRanges(pCtrl, &D_80392028);
    func_802EFE24(pCtrl,
        400.0f, 400.0f, 400.0f,
        800.0f, 800.0f, 800.0f
    );
    func_802EFB70(pCtrl, 0.1f, 0.2f);
    particleEmitter_setSpawnIntervalRange(pCtrl, 0.0f, 0.02f);
    func_802EFEC0(pCtrl, 1.5f, 1.5f);
    func_802EFA5C(pCtrl, 0.0f, 0.3f);
    func_802EF9F8(pCtrl, 0.6f);
    func_802EFA18(pCtrl, 0);
    func_802EFA20(pCtrl, 1.0f, 1.3f);
    func_802EF9EC(pCtrl, 0x7B, 8000);
    particleEmitter_emitN(pCtrl, count);
}

void func_8038C398(f32 position[3], enum marker_e marker_id){
    enum asset_e sp1C;
    switch(marker_id){
        case MARKER_200_TWINKLY_BLUE:
            sp1C = ASSET_497_MODEL_TWINKLY_SHARD_BLUE;
            break;

        case MARKER_201_TWINKLY_GREEN:
            sp1C = ASSET_499_MODEL_TWINKLY_SHARD_GREEN;
            break;
        
        case MARKER_202_TWINKLY_ORANGE:
            sp1C = ASSET_49A_MODLE_TWINKLY_SHARD_ORANGE;
            break;

        case MARKER_203_TWINKLY_RED:
            sp1C = ASSET_49B_MODEL_TWINKLY_SHARD_RED;
            break;
    }
    func_8038C260(position, 12, sp1C);
    func_8038C260(position, 4, ASSET_498_MODEL_TWINKLY_SHARD_YELLOW);
}

#ifndef NONMATCHING
void func_8038C428(Actor *this, f32 arg1[3], f32 arg2);
#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_5CC0/func_8038C428.s")
#else
void func_8038C428(Actor *this, f32 arg1[3], f32 arg2) {
    u8 sp7F;
    s32 sp78;
    f32 sp74;
    f32 sp70;
    f32 sp5C[3];
    f32 sp54;
    f32 sp50;
    f32 sp48;
    f32 temp_f0_2;
    f32 phi_f22;
    f32 phi_f24;
    f32 phi_f16;
    s32 phi_v0;
    s32 phi_v1;

    sp74 = arg2;
    sp70 = this->position[1];
    phi_v1 = (arg2 == 0.0f) ? FALSE : TRUE;
    phi_f22 = arg1[0] - this->position[0];
    phi_f24 = arg1[2] - this->position[2];
    sp78 = 0;
    sp48 = phi_f22 / sp54;
    sp50 = phi_f24 / sp54;
    sp54 = gu_sqrtf((phi_f22 * phi_f22) + (phi_f24 * phi_f24));
    if (sp7F = phi_v1) {
        temp_f0_2 = randf2(130.0f, 150.0f);
        if (!(sp54 < temp_f0_2)) {
            sp54 = temp_f0_2;
        }
        phi_f22 = sp48 * sp54;
        phi_f24 = sp50 * sp54;
    }
    sp5C[0] = this->position[0] + phi_f22;
    sp5C[1] = this->position[1];
    sp5C[2] = this->position[2] + phi_f24;
    sp78 = 0;
    if (sp7F) {
        do {
            // sp70 += arg2 += D_80392D80;
            // sp70 += arg2 += D_80392D80;
            sp70 += arg2 += -3.2;
            sp78++;
        } while (func_80309724(sp5C) < sp70 || arg2 > 0.0f);
    } else {
        sp74 = (f32) ((f64) (((arg1[1] + 40.0f) - this->position[1]) / 28.0f) - (-3.2 * (f64) 28.0f * 0.5));
        sp78 = 0x1C;
    }
    animctrl_setAnimTimer(this->animctrl, 0.0f);
    this->unk1C[0] = D_80392D90 / sp78;
    this->velocity[1] = sp74;
    this->velocity[0] = phi_f22 / sp78;
    this->velocity[2] = phi_f24 / sp78;
    if (sp7F) {
        func_8030E878(SFX_3F2_UNKNOWN, randf2(D_80392D98, D_80392D9C), 32000, this->position, D_80392DA0, D_80392DA4);
    }
    else{
        func_8030E878(SFX_53_BANJO_HUIII, randf2(D_80392DA8, 1.5f), 32000, this->position, D_80392DAC, D_80392DB0);
    }
}
#endif

bool func_8038C718(Actor *this, f32 arg1){
    f32 tmp;

    this->position[0] += this->velocity[0];
    this->position_y += (this->velocity_y += D_80392DB8);
    this->position_z += this->velocity_z;
    tmp = D_80392DC0 < animctrl_getAnimTimer(this->animctrl) + this->unk1C[0] ? D_80392DC8 : animctrl_getAnimTimer(this->animctrl) + this->unk1C[0];
    animctrl_setAnimTimer(this->animctrl, tmp);

    if(arg1 == 0.0f)
        arg1 = func_80309724(this->position);

    if(this->position_y <= arg1){
        this->position_y = arg1;
        return FALSE;
    }
    return TRUE;
}

bool func_8038C844(f32 arg0[3], f32 arg1[3]){
    if( (arg0[0] - arg1[0] < 26.0f && -26.0f < arg0[0] - arg1[0])
        && (arg0[1] - arg1[1] < 26.0f && -26.0f < arg0[1] - arg1[1])
        && (arg0[2] - arg1[2] < 26.0f && -26.0f < arg0[2] - arg1[2])
    ){
        return TRUE;
    }
    return FALSE;
}

void func_8038C8F0(ActorMarker *marker){
    Actor *this;
    Actor *muncher;
    Actor *other;
    s32 pad;

    this = marker_getActor(reinterpret_cast(ActorMarker *, marker));
    other = marker_getActor(this->unk100);
    muncher = func_8032813C(ACTOR_337_TWINKLY_MUNCHER, D_80392070, 170);
    muncher->unk100 = other->marker;
    muncher->unkF4_8 = 1;

    if(pad);
}

void func_8038C94C(ActorMarker *caller, enum asset_e text_id, s32 arg2){
    Actor *this = marker_getActor(caller);
    if(!func_803203FC(UNKFLAGS1_C1_IN_FINAL_CHARACTER_PARADE)){
        func_80328A84(this, 6);
        func_802C3C88(func_8038C8F0, this->marker);
    }
}

#ifndef NONAMTCHING
#pragma GLOBAL_ASM("asm/nonmatchings/FP/code_5CC0/func_8038C9A0.s")
#else
void func_8038C9A0(Actor *this){
    Actor *other; //sp34
    void * sp30;

    if(this->marker->unk14_20 == 0x200){
        sp30 = func_8034C2C4(this->marker, 0x190);
    }
    other = marker_getActor(this->unk100);

    if(!this->unk16C_4){
        this->unk16C_4 = TRUE;
        this->marker->unk18 = &D_80392018;
        this->unk38_31 = 0;
        if(0.0f != other->velocity[0]){
            func_80328A84(this, 4);
            this->unk1C[1] = this->position_y + 50.0f;
            this->unk1C[2] = this->position_y;
        }
        else{
            this->velocity_x = 0.0f;
            this->velocity_y = 0.0f;
            this->velocity_z = 0.0f;
            this->unk1C[0] = 0.0f;
            animctrl_setAnimTimer(this->animctrl, 0.0f);
            func_8038C428(this, &D_8039207C, 0);
            return;
        }
    }//L8038CA9C

    if(1.0f == other->unk1C[1]){
        func_8038C398(this->position, this->marker->unk14_20);
        FUNC_8030E8B4(SFX_7B_ICE_BREAKING_1, 1.0f, 32000, this->position, 0x6d6, 0xdac);\
        marker_despawn(this->marker);
        return;
    }//L8038CB04

    switch(this->state){
        case 1:// 8038CB2C
            if(func_8038C718(this, 0))
                break;

            func_80328B8C(this, 2, 0.001f, 1);
            func_8038C428(this, D_80392088, randf2(20.0f, 24.0f));
            this->unk60 = this->yaw;
            break;

        case 2:// 8038CB8C
            this->yaw += 4.0f;
            if(actor_animationIsAt(this, 0.999)){
                func_8034DFB0(sp30, D_803920A0, D_803920B0, 0.14f);
            }

            if(actor_animationIsAt(this, 0.8f)){
                func_8034DFB0(sp30, D_803920B0, D_803920A0, 0.14f);
            }

            if(0.8 < animctrl_getAnimTimer(this->animctrl) || animctrl_getAnimTimer(this->animctrl) < 0.2){
                this->unk38_31 = TRUE;
            }
            else{
                this->unk38_31 = FALSE;
            }

            if(func_8038C718(this, 0.0f))
                return;

            if(func_8038C844(this->position, D_80392088)){
                func_80328B8C(this, 3, 0.001f, 1);
                func_8038C428(this, D_80392094, 0.0f);
            }
            else{
                func_8038C428(this, D_80392088, randf2(20.0f, 24.0f));
            }
            break;

        case 3:// 8038CCFC
            if(func_8038C718(this, 0.0f)) 
                break;

            if(other->unk38_31 != 0){
                other->unk38_31--;
            }
            func_8025A6EC(COMUSIC_2B_DING_B, 28000);
            marker_despawn(this->marker);
            break;

        case 4:// 8038CD58
            this->position_y += 3.0f;
            if(this->unk1C[1] <= this->position_y){
                this->position_y = this->unk1C[1];
                if(!func_8031FF1C(0x82)){
                    func_80311480(0xc12, 0x2a, this->position, this->marker, func_8038C94C, NULL);
                    func_80320004(0x82, TRUE);
                }
                else{
                    func_80311480(0xc25, 0x2b, this->position, this->marker, func_8038C94C, NULL);
                }
                func_80328A84(this, 5);
                this->pitch -= 3.0f;
            }
            break;

        case 5:// 8038CE14
            this->yaw_moving = (f32)func_80329784(this);
            func_80328FB0(this, 8.0f);
            if(func_8038C718(this, this->unk1C[1]))
                break;
            
            this->velocity[1] = randf2(14.0f, 20.0f);
            break;

        case 6:// 8038CE64
            this->position_y -= 5.0f;
            if(this->position_y < this->unk1C[2] - 50.0f){
                this->velocity_x = 0.0f;
                marker_despawn(this->marker);
                return;
            }
            break;
    }//L8038CEB0
}
#endif
