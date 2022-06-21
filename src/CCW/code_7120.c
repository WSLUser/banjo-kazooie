#include <ultra64.h>
#include "functions.h"
#include "variables.h"

typedef struct {
    f32 unk0;
} ActorLocal_CCW_7120;

void func_8038D85C(Actor *this);

/* .data */
extern ActorInfo D_8038F640 = {
    0x1BF, 0x2AC, 0x490,
    0x0, NULL,
    func_8038D85C, NULL, func_80325888,
    0, 0, 2.2f, 0
};
extern s32 D_8038F664[3];
extern struct42s D_8038F670;
extern struct43s D_8038F6A0;

void func_8038D510(Actor *this) {
    ParticleEmitter *pCtrl;

    pCtrl = partEmitList_pushNew(6);
    particleEmitter_setSprite(pCtrl, ASSET_70E_SPRITE_SMOKE_2);
    func_802EFA5C(pCtrl, 0.01f, 0.5f);
    particleEmitter_setStartingFrameRange(pCtrl, 0, 7);
    particleEmitter_setPosition(pCtrl, this->position);
    func_802EFB70(pCtrl, 1.0f, 2.0f);
    func_802EFB84(pCtrl, 3.0f, 4.0f);
    particleEmitter_setPositionAndVelocityRanges(pCtrl, &D_8038F670);
    func_802EFFA8(pCtrl, D_8038F664);
    func_802EFEC0(pCtrl, 3.0f, 4.0f);
    particleEmitter_emitN(pCtrl, 6);
}

void func_8038D5DC(Actor *this) {
    ParticleEmitter *pCtrl;

    pCtrl = partEmitList_pushNew(30);
    func_802EF9F8(pCtrl, 0.6f);
    func_802EFA18(pCtrl, 3);
    particleEmitter_setModel(pCtrl, 0x896);
    particleEmitter_setPosition(pCtrl, this->position);
    func_802EFB70(pCtrl, 0.05f, 0.3f);
    func_802EFE24(pCtrl,
        -600.0f, -600.0f, -600.0f,
         600.0f,  600.0f,  600.0f
    );
    particleEmitter_setSpawnIntervalRange(pCtrl, 0.0f, 0.01f);
    func_802EFEC0(pCtrl, 10.0f, 10.0f);
    particleEmitter_setPositionVelocityAndAccelerationRanges(pCtrl, &D_8038F6A0);
    particleEmitter_emitN(pCtrl, 30);
}

void func_8038D6D8(Actor *this, s32 next_state) {
    ActorLocal_CCW_7120 *local = (ActorLocal_CCW_7120 *)&this->local;

    local->unk0 = 0.0f;
    if (next_state == 2) {
        this->marker->propPtr->unk8_3 = FALSE;
        func_802BB3DC(0, 60.0f, 0.7f);
        func_8038D510(this);
        func_8038D5DC(this);
        FUNC_8030E624(SFX_9B_BOULDER_BREAKING_1, 0x1D4, 0x132);
        FUNC_8030E624(SFX_9B_BOULDER_BREAKING_1, 0x1D4, 0x1FF);
        FUNC_8030E624(SFX_9B_BOULDER_BREAKING_1, 0x1D4, 0x2CC);
        FUNC_8030E624(SFX_9B_BOULDER_BREAKING_1, 0x1D4, 0x398);
        func_80324E38(0.0f, 3);
        timed_setCameraToNode(0.5f, 3);
        timedFunc_set_2(0.5f, levelSpecificFlags_set, 0x25, TRUE);
        func_80324E88(4.0f);
        func_80324E38(4.0f, 0);
        local->unk0 = 0.5f;
        marker_despawn(this->marker);
    }
    if (next_state == 3) {
        marker_despawn(this->marker);
    }
    this->state = next_state;
}

void func_8038D81C(ActorMarker* marker, ActorMarker *other_marker) {
    Actor* actor = marker_getActor(marker);
    if (actor->state == 1) {
        func_8038D6D8(actor, 2);
    }
}

void func_8038D85C(Actor *this) {
    ActorLocal_CCW_7120 *local = (ActorLocal_CCW_7120 *)&this->local;
    f32 tick;

    tick = time_getDelta();
    if (!this->unk16C_4) {
        this->marker->propPtr->unk8_3 = TRUE;
        this->unk16C_4 = TRUE;
        marker_setCollisionScripts(this->marker, 0, &func_8038D81C, 0);
        func_8038D6D8(this, 1);
        if (jiggyscore_isCollected(JIGGY_4B_CCW_GNAWTY) != 0) {
            levelSpecificFlags_set(0x25, 1);
        }
        if ((levelSpecificFlags_get(0x25) != 0) && (map_get() != MAP_43_CCW_SPRING)) {
            marker_despawn(this->marker);
        }
        return;
    } 
    if(this->state == 2){
        if (func_8025773C(&local->unk0, tick) ) {
            func_8038D6D8(this, 3);
        }
    }
}
