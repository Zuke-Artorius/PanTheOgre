#include "modding.h"
#include "global.h"
#include "recomputils.h"
#include "recompconfig.h"
#include "playermodelmanager_api.h"
#include "modelreplacer_api.h"

#include "dl/gPanCullTri.h"

#include "skel/gPanDekuSkel.h"
#include "dl/gPanDekuGuard.h"
#include "dl/gPanDekuSax.h"
#include "dl/gPanDekuMaskNorm.h"
#include "dl/gPanDekuMaskScream.h"

#include "skel/gPanZoraSkel.h"
#include "dl/gPanZoraFinL.h"
#include "dl/gPanZoraFinR.h"
#include "dl/gPanZoraBoomL.h"
#include "dl/gPanZoraBoomR.h"
#include "dl/gPanZoraSwimL.h"
#include "dl/gPanZoraSwimR.h"
#include "dl/gPanZoraShield.h"
#include "dl/gPanZoraMaskNorm.h"
#include "dl/gPanZoraMaskScream.h"

#include "skel/gPanHumanSkel.h"
#include "skel/gPanHumanHands.h"
#include "skel/gPanHumanBottle.h"

#include "dl/gPanFistLDL.h"
#include "dl/gPanFistRDL.h"

#include "dl/gPanSword1BladeDL.h"
#include "dl/gPanSword1HiltDL.h"
#include "dl/gPanSheath1DL.h"
#include "dl/gPanSword2BladeDL.h"
#include "dl/gPanSword2HiltDL.h"
#include "dl/gPanSheath2DL.h"
#include "dl/gPanSword3BladeDL.h"
#include "dl/gPanSword3HiltDL.h"
#include "dl/gPanSheath3DL.h"
#include "dl/gPanSword4BladeDL.h"
#include "dl/gPanSword4HiltDL.h"
#include "dl/gPanShield1DL.h"
#include "dl/gPanShield2DL.h"
#include "dl/gPanShield3DL.h"
#include "dl/gPanBowDL.h"
#include "dl/gPanBowStringDL.h"
#include "dl/gOcarinaDL.h"
#include "dl/gLinkHumanHookshotDL_mesh.h"

#include "dl/gPanMaskFoxDL.h"
#include "dl/gPanMaskWingsDL.h"
#include "dl/gPanMaskGasDL.h"
#include "dl/gPanMaskDarkHelmDL.h"
#include "dl/gPanMaskGarosDL.h"
#include "dl/gPanMaskCowBatDL.h"
#include "dl/gPanMaskFairyDL.h"
#include "dl/gPanMaskBombDL.h"
#include "dl/gPanMaskBombCDDL.h"
#include "dl/gPanMaskDonDL.h"
#include "dl/gPanMaskHaloDL.h"
#include "dl/gPanMaskKamaroDL.h"
#include "dl/gPanMaskNightDL.h"
#include "dl/gPanMaskPostDL.h"
#include "dl/gPanMaskStoneDL.h"

//#include "dl/gElegyShellPanZoraDL.h"
#include "dl/gElegyShellYueZoraDL.h"
#include "dl/gElegyShellKapipiDekuDL.h"
#include "dl/gElegyShellPanHumanDL.h"

// Gi Masks
#include "dl/gi/gGiPanMaskBombDL.h"
#include "dl/gi/gGiPanMaskCowBatDL.h"
#include "dl/gi/gGiPanMaskDarkHelmDL.h"
#include "dl/gi/gGiPanMaskDonDL.h"
#include "dl/gi/gGiPanMaskFairyDL.h"
#include "dl/gi/gGiPanMaskFoxDL.h"
#include "dl/gi/gGiPanMaskGarosDL.h"
#include "dl/gi/gGiPanMaskGasDL.h"
#include "dl/gi/gGiPanMaskHaloDL.h"
#include "dl/gi/gGiPanMaskKamaroDL.h"
#include "dl/gi/gGiPanMaskNightDL.h"
#include "dl/gi/gGiPanMaskPostDL.h"
#include "dl/gi/gGiPanMaskStoneDL.h"
#include "dl/gi/gGiPanMaskWingsDL.h"

// Gi Transformation Masks
#include "dl/gi/gGiPanDekuMaskDL.h"
#include "dl/gi/gGiPanZoraMaskDL.h"

// Gi Gear
#include "dl/gi/gGiPanOcarinaDL.h"

#include "dl/gi/gGiPanBowDL.h"
#include "dl/gi/gGiPanBowStringDL.h"

#include "dl/gi/gGiPanShield1DL.h"
#include "dl/gi/gGiPanShield2DL.h"
#include "dl/gi/gGiPanShield3DL.h"

#include "dl/gi/gGiPanSword1BladeDL.h"
#include "dl/gi/gGiPanSword1HiltDL.h"
#include "dl/gi/gGiPanSword2DL.h"
#include "dl/gi/gGiPanSword3DL.h"
#include "dl/gi/gGiPanSword4BladeDL.h"
#include "dl/gi/gGiPanSword4HiltDL.h"

#include "dl/gi/gGiCull.h"

#define MASK_ROTATE_X 0.f
#define MASK_ROTATE_Y 0.f
#define MASK_ROTATE_Z 0.f
#define MASK_SCALE 1.f
#define MASK_TRANSLATE_X -125.f
#define MASK_TRANSLATE_Y 0.f
#define MASK_TRANSLATE_Z 0.f

#define SHIELD_ROTATE_X 0.f
#define SHIELD_ROTATE_Y 0.f
#define SHIELD_ROTATE_Z 180.f
#define SHIELD_SCALE 1.f
#define SHIELD_TRANSLATE_X 700.f
#define SHIELD_TRANSLATE_Y 0.f
#define SHIELD_TRANSLATE_Z 0.f

#define HOOKSHOT_ROTATE_X 0.f
#define HOOKSHOT_ROTATE_Y 0.f
#define HOOKSHOT_ROTATE_Z 0.f
#define HOOKSHOT_SCALE 1.f
#define HOOKSHOT_TRANSLATE_X -50.f
#define HOOKSHOT_TRANSLATE_Y 0.f
#define HOOKSHOT_TRANSLATE_Z 25.f

#define ARROW_ROTATE_X 0.f
#define ARROW_ROTATE_Y 0.f
#define ARROW_ROTATE_Z 0.f
#define ARROW_SCALE 1.f
#define ARROW_TRANSLATE_X 0.f
#define ARROW_TRANSLATE_Y 200.f
#define ARROW_TRANSLATE_Z -50.f
#define BOWSTRING_OFFSET 350.f

u8 gPushedMatrix;
extern Gfx* D_801C0B20[];
extern Gfx object_link_child_DL_017818[];
extern Vec3f* sPlayerCurBodyPartPos;
extern LinkAnimationHeader gPlayerAnim_cl_setmask;
Mtx gPanMaskMtx;
Mtx gPanShieldMtx;
Mtx gPanHookshotMtx;
Mtx gPanArrowMtx;

TexturePtr gPanMouthTextures[] = {
    mouth_closed,
    mouth_half,
    mouth_open,
    mouth_smile,
};

TexturePtr gPanEyeTextures[] = {
    eyes_open,
    eyes_half,
    eyes_closed,
    eyes_right,
    eyes_left,
    eyes_shock,
    eyes_down,
    eyes_clench,
};

TexturePtr gPanZoraEyes[] = {
    gPanZoraSkel_zora_eye_sep_open_ci8_copy,
    gPanZoraSkel_zora_eye_half_ci8_copy,
    gPanZoraSkel_zora_eye_closed_ci8_copy,
    gPanZoraSkel_zora_eye_right_ci8_copy,
    gPanZoraSkel_zora_eye_left_ci8_copy,
    gPanZoraSkel_zora_eye_sep_angry_ci8_copy,
    gPanZoraSkel_zora_eye_pleased_ci8_copy,
    gPanZoraSkel_zora_eye_wince_ci8,
};
TexturePtr gPanZoraMouthChin[] = {
    gPanZoraSkel_zora_mouth_closed_chin_ci8,
    gPanZoraSkel_zora_mouth_half_chin_ci8,
    gPanZoraSkel_zora_mouth_joy_chin_ci8,
    gPanZoraSkel_zora_mouth_open_chin_ci8,
};

TexturePtr gPanDekuMouths[] = {
    gPanDekuSkel_deku_mouth_smile_ci8,
    gPanDekuSkel_deku_mouth_half_ci8,
    gPanDekuSkel_deku_mouth_open_ci8,
    gPanDekuSkel_deku_mouth_pucker_ci8,
};
TexturePtr gPanDekuEyesL0[] = {
    gPanDekuSkel_deku_eyes_altnorm_ci8,
    gPanDekuSkel_deku_eyes_althalf_ci8,
    gPanDekuSkel_deku_eyes_altclose_ci8,
    gPanDekuSkel_deku_eyes_altleft_ci8,
    gPanDekuSkel_deku_eyes_altright_ci8,
    gPanDekuSkel_deku_eyes_altshock_ci8,
    gPanDekuSkel_deku_eyes_altdown_ci8,
    gPanDekuSkel_deku_eyes_altclench_ci8,
};

RECOMP_HOOK("Player_PostLimbDrawGameplay") void on_Player_PostLimbDrawGameplay(PlayState* play, s32 limbIndex, Gfx** dList1, Gfx** dList2, Vec3s* rot, Actor* actor) {
    Player* player = (Player*)actor;

    if (limbIndex == PLAYER_LIMB_RIGHT_HAND) {
        Actor* heldActor = player->heldActor;
        s32 pad;

        if (*dList1 != NULL) {
            if (player->rightHandType == PLAYER_MODELTYPE_RH_BOW) {

                OPEN_DISPS(play->state.gfxCtx);
                Matrix_Push();
                gPushedMatrix++;
                Matrix_Translate(0.f, BOWSTRING_OFFSET, 0.f, MTXMODE_APPLY);
                MATRIX_FINALIZE_AND_LOAD(POLY_XLU_DISP++, play->state.gfxCtx);
                CLOSE_DISPS(play->state.gfxCtx);
            }
        } else {
            gPushedMatrix = 0;
        }
    } else {
        gPushedMatrix = 0;
    }
}

RECOMP_HOOK_RETURN("Player_PostLimbDrawGameplay") void return_Player_PostLimbDrawGameplay(void) {
    while (gPushedMatrix) {
        Matrix_Pop();
        gPushedMatrix--;
    }
    gPushedMatrix = 0;
}

PLAYERMODELMANAGER_CALLBACK_REGISTER_MODELS void registerPan() {

    PlayerModelManagerHandle panHandle = PLAYERMODELMANAGER_REGISTER_MODEL("mm_pan_pmm", PMM_MODEL_TYPE_MODEL_PACK);
    PlayerModelManager_setAuthor(panHandle, "Zuke");
    PlayerModelManager_setDisplayName(panHandle, "Pan");

    PlayerModelManagerHandle panEquips = PLAYERMODELMANAGER_REGISTER_MODEL("mm_pan_equipment_pmm", PMM_MODEL_TYPE_MODEL_PACK);
    PlayerModelManager_setAuthor(panEquips, "Zuke");
    PlayerModelManager_setDisplayName(panEquips, "Astoltian Weaponry");

    PlayerModelManagerHandle panDeku = PLAYERMODELMANAGER_REGISTER_MODEL("mm_pan_deku_pmm", PMM_MODEL_TYPE_DEKU);
    PlayerModelManager_setAuthor(panDeku, "Zuke");
    PlayerModelManager_setDisplayName(panDeku, "Pan");

    PlayerModelManager_setEyesTextures(panDeku, gPanDekuEyesL0);
    PlayerModelManager_setMouthTextures(panDeku, gPanDekuMouths);

    PlayerModelManager_setSkeleton(panDeku, &gPanDekuSkel);
    
    PlayerModelManager_setDisplayList(panDeku, PMM_DL_DEKU_GUARD, gPanDekuGuard);
    PlayerModelManager_setDisplayList(panDeku, PMM_DL_PIPE_MOUTH, gPanDekuSax);
    PlayerModelManager_setDisplayList(panDeku, PMM_DL_PIPE_RIGHT, gPanCullTri);
    PlayerModelManager_setDisplayList(panDeku, PMM_DL_PIPE_UP, gPanCullTri);
    PlayerModelManager_setDisplayList(panDeku, PMM_DL_PIPE_DOWN, gPanCullTri);
    PlayerModelManager_setDisplayList(panDeku, PMM_DL_PIPE_LEFT, gPanCullTri);
    PlayerModelManager_setDisplayList(panDeku, PMM_DL_PIPE_A, gPanCullTri);

    PlayerModelManager_setDisplayList(panDeku, PMM_DL_ELEGY_OF_EMPTINESS_SHELL, gElegyShellKapipiDekuDL);

    PlayerModelManager_addHandleToPack(panHandle, panDeku);
    
    PlayerModelManagerHandle panDekuMask = PLAYERMODELMANAGER_REGISTER_MODEL("mm_pan_deku_mask_pmm", PMM_MODEL_TYPE_MASK_DEKU);
    PlayerModelManager_setAuthor(panDekuMask, "Zuke");
    PlayerModelManager_setDisplayName(panDekuMask, "Pan");

    PlayerModelManager_setDisplayList(panDekuMask, PMM_DL_MASK_DEKU, gPanDekuMaskNorm);
    PlayerModelManager_setDisplayList(panDekuMask, PMM_DL_MASK_DEKU_SCREAM, gPanDekuMaskScream);

    PlayerModelManager_addHandleToPack(panHandle, panDekuMask);

    PlayerModelManagerHandle panZoraMask = PLAYERMODELMANAGER_REGISTER_MODEL("mm_pan_zora_mask_pmm", PMM_MODEL_TYPE_MASK_ZORA);
    PlayerModelManager_setAuthor(panZoraMask, "Zuke");
    PlayerModelManager_setDisplayName(panZoraMask, "Pan");

    PlayerModelManager_setDisplayList(panZoraMask, PMM_DL_MASK_ZORA, gPanZoraMaskNorm);
    PlayerModelManager_setDisplayList(panZoraMask, PMM_DL_MASK_ZORA_SCREAM, gPanZoraMaskScream);

    PlayerModelManager_addHandleToPack(panHandle, panZoraMask);

    PlayerModelManagerHandle panZora = PLAYERMODELMANAGER_REGISTER_MODEL("mm_pan_zora_pmm", PMM_MODEL_TYPE_ZORA);
    PlayerModelManager_setAuthor(panZora, "Zuke");
    PlayerModelManager_setDisplayName(panZora, "Pan");

    PlayerModelManager_setEyesTextures(panZora, gPanZoraEyes);
    PlayerModelManager_setMouthTextures(panZora, gPanZoraMouthChin);
    
    PlayerModelManager_setSkeleton(panZora, &gPanZoraSkel);

    PlayerModelManager_setDisplayList(panZora, PMM_DL_LFIN, gPanZoraFinL);
    PlayerModelManager_setDisplayList(panZora, PMM_DL_LFIN_SWIM, gPanZoraSwimL);
    PlayerModelManager_setDisplayList(panZora, PMM_DL_LFIN_BOOMERANG, gPanZoraBoomL);
    PlayerModelManager_setDisplayList(panZora, PMM_DL_RFIN, gPanZoraFinR);
    PlayerModelManager_setDisplayList(panZora, PMM_DL_RFIN_SWIM, gPanZoraSwimR);
    PlayerModelManager_setDisplayList(panZora, PMM_DL_RFIN_BOOMERANG, gPanZoraBoomR);
    PlayerModelManager_setDisplayList(panZora, PMM_DL_FIN_SHIELD, gPanZoraShield);

    PlayerModelManager_setDisplayList(panZora, PMM_DL_ELEGY_OF_EMPTINESS_SHELL, gElegyShellYueZoraDL);

    PlayerModelManager_addHandleToPack(panHandle, panZora);

    PlayerModelManagerHandle panHuman = PLAYERMODELMANAGER_REGISTER_MODEL("mm_pan_human_pmm", PMM_MODEL_TYPE_CHILD);

    PlayerModelManager_setAuthor(panHuman, "Zuke");
    PlayerModelManager_setDisplayName(panHuman, "Pan");

    PlayerModelManager_setEyesTextures(panHuman, gPanEyeTextures);
    PlayerModelManager_setMouthTextures(panHuman, gPanMouthTextures);

    PlayerModelManager_setSkeleton(panHuman, &gPanHumanSkel);

    PlayerModelManager_setDisplayList(panHuman, PMM_DL_LHAND_BOTTLE, gPanHumanBottle_bone015_gLinkHumanLeftHandLimb_mesh_layer_Opaque);
    PlayerModelManager_setDisplayList(panHuman, PMM_DL_LFIST, gPanHumanHands_bone015_gLinkHumanLeftHandLimb_mesh_layer_Opaque);
    PlayerModelManager_setDisplayList(panHuman, PMM_DL_RFIST, gPanHumanHands_bone018_gLinkHumanRightHandLimb_mesh_layer_Opaque);
        
    guPosition(&gPanMaskMtx, MASK_ROTATE_X, MASK_ROTATE_Y, MASK_ROTATE_Z, MASK_SCALE, MASK_TRANSLATE_X, MASK_TRANSLATE_Y, MASK_TRANSLATE_Z);
    guPosition(&gPanShieldMtx, SHIELD_ROTATE_X, SHIELD_ROTATE_Y, SHIELD_ROTATE_Z, SHIELD_SCALE, SHIELD_TRANSLATE_X, SHIELD_TRANSLATE_Y, SHIELD_TRANSLATE_Z);
    guPosition(&gPanHookshotMtx, HOOKSHOT_ROTATE_X, HOOKSHOT_ROTATE_Y, HOOKSHOT_ROTATE_Z, HOOKSHOT_SCALE, HOOKSHOT_TRANSLATE_X, HOOKSHOT_TRANSLATE_Y, HOOKSHOT_TRANSLATE_Z);
    guPosition(&gPanArrowMtx, ARROW_ROTATE_X, ARROW_ROTATE_Y, ARROW_ROTATE_Z, ARROW_SCALE, ARROW_TRANSLATE_X, ARROW_TRANSLATE_Y, ARROW_TRANSLATE_Z);
    
    PlayerModelManager_setMatrix(panHuman, PMM_MTX_MASKS, &gPanMaskMtx);
    PlayerModelManager_setMatrix(panHuman, PMM_MTX_SHIELD1_BACK, &gPanShieldMtx);
    PlayerModelManager_setMatrix(panHuman, PMM_MTX_SHIELD2_BACK, &gPanShieldMtx);
    PlayerModelManager_setMatrix(panHuman, PMM_MTX_SHIELD3_BACK, &gPanShieldMtx);
    PlayerModelManager_setMatrix(panHuman, PMM_MTX_HOOKSHOT_CHAIN_AND_HOOK, &gPanHookshotMtx);
    PlayerModelManager_setMatrix(panHuman, PMM_MTX_ARROW_DRAWN, &gPanArrowMtx);

    PlayerModelManager_setDisplayList(panHuman, PMM_DL_HOOKSHOT, gLinkHumanHookshotDL_mesh);
    PlayerModelManager_setDisplayList(panHuman, PMM_DL_ELEGY_OF_EMPTINESS_SHELL, gElegyShellPanHumanDL);

    PlayerModelManager_addHandleToPack(panHandle, panHuman);

    PlayerModelManagerHandle panOcarina = PLAYERMODELMANAGER_REGISTER_MODEL("mm_pan_ocarina_pmm", PMM_MODEL_TYPE_OCARINA_TIME);
    PlayerModelManager_setAuthor(panOcarina, "Zuke");
    PlayerModelManager_setDisplayName(panOcarina, "Astoltian Gear");
    PlayerModelManager_setDisplayList(panOcarina, PMM_DL_OCARINA_TIME, gOcarinaDL);
    PlayerModelManager_addHandleToPack(panEquips, panOcarina);

    PlayerModelManagerHandle panOcarinaFairy = PLAYERMODELMANAGER_REGISTER_MODEL("mm_pan_ocarina_fairy_pmm", PMM_MODEL_TYPE_OCARINA_FAIRY);
    PlayerModelManager_setAuthor(panOcarinaFairy, "Zuke");
    PlayerModelManager_setDisplayName(panOcarinaFairy, "Astoltian Gear");
    PlayerModelManager_setDisplayList(panOcarinaFairy, PMM_DL_OCARINA_FAIRY, gOcarinaDL);
    PlayerModelManager_addHandleToPack(panEquips, panOcarinaFairy);
    
    PlayerModelManagerHandle panSwordKokiri = PLAYERMODELMANAGER_REGISTER_MODEL("mm_pan_sword_kokiri_pmm", PMM_MODEL_TYPE_SWORD_KOKIRI);
    PlayerModelManager_setAuthor(panSwordKokiri, "Zuke");
    PlayerModelManager_setDisplayName(panSwordKokiri, "Astoltian Weaponry");
    PlayerModelManager_setDisplayList(panSwordKokiri, PMM_DL_SWORD_KOKIRI_BLADE, gPanSword1BladeDL);
    PlayerModelManager_setDisplayList(panSwordKokiri, PMM_DL_SWORD_KOKIRI_HILT, gPanSword1HiltDL);
    PlayerModelManager_setDisplayList(panSwordKokiri, PMM_DL_SWORD_KOKIRI_SHEATH, gPanSheath1DL);
    PlayerModelManager_addHandleToPack(panEquips, panSwordKokiri);

    PlayerModelManagerHandle panSwordRazor = PLAYERMODELMANAGER_REGISTER_MODEL("mm_pan_sword_razor_pmm", PMM_MODEL_TYPE_SWORD_RAZOR);
    PlayerModelManager_setAuthor(panSwordRazor, "Zuke");
    PlayerModelManager_setDisplayName(panSwordRazor, "Astoltian Weaponry");
    PlayerModelManager_setDisplayList(panSwordRazor, PMM_DL_SWORD_RAZOR_BLADE, gPanSword2BladeDL);
    PlayerModelManager_setDisplayList(panSwordRazor, PMM_DL_SWORD_RAZOR_HILT, gPanSword2HiltDL);
    PlayerModelManager_setDisplayList(panSwordRazor, PMM_DL_SWORD_RAZOR_SHEATH, gPanSheath2DL);
    PlayerModelManager_addHandleToPack(panEquips, panSwordRazor);

    PlayerModelManagerHandle panSwordGilded = PLAYERMODELMANAGER_REGISTER_MODEL("mm_pan_sword_gilded_pmm", PMM_MODEL_TYPE_SWORD_GILDED);
    PlayerModelManager_setAuthor(panSwordGilded, "Zuke");
    PlayerModelManager_setDisplayName(panSwordGilded, "Astoltian Weaponry");
    PlayerModelManager_setDisplayList(panSwordGilded, PMM_DL_SWORD_GILDED_BLADE, gPanSword3BladeDL);
    PlayerModelManager_setDisplayList(panSwordGilded, PMM_DL_SWORD_GILDED_HILT, gPanSword3HiltDL);
    PlayerModelManager_setDisplayList(panSwordGilded, PMM_DL_SWORD_GILDED_SHEATH, gPanSheath3DL);
    PlayerModelManager_addHandleToPack(panEquips, panSwordGilded);

    PlayerModelManagerHandle panSwordFairy = PLAYERMODELMANAGER_REGISTER_MODEL("mm_pan_sword_fairy_pmm", PMM_MODEL_TYPE_SWORD_GREAT_FAIRY);
    PlayerModelManager_setAuthor(panSwordFairy, "Zuke");
    PlayerModelManager_setDisplayName(panSwordFairy, "Astoltian Weaponry");
    PlayerModelManager_setDisplayList(panSwordFairy, PMM_DL_SWORD_GREAT_FAIRY_BLADE, gPanSword4BladeDL);
    PlayerModelManager_setDisplayList(panSwordFairy, PMM_DL_SWORD_GREAT_FAIRY_HILT, gPanSword4HiltDL);
    PlayerModelManager_addHandleToPack(panEquips, panSwordFairy);
    
    PlayerModelManagerHandle panShieldDeku = PLAYERMODELMANAGER_REGISTER_MODEL("mm_pan_shield_deku_pmm", PMM_MODEL_TYPE_SHIELD_DEKU);
    PlayerModelManager_setAuthor(panShieldDeku, "Zuke");
    PlayerModelManager_setDisplayName(panShieldDeku, "Astoltian Gear");
    PlayerModelManager_setDisplayList(panShieldDeku, PMM_DL_SHIELD_DEKU, gPanShield1DL);
    PlayerModelManager_addHandleToPack(panEquips, panShieldDeku);
    
    PlayerModelManagerHandle panShieldHero = PLAYERMODELMANAGER_REGISTER_MODEL("mm_pan_shield_hero_pmm", PMM_MODEL_TYPE_SHIELD_HERO);
    PlayerModelManager_setAuthor(panShieldHero, "Zuke");
    PlayerModelManager_setDisplayName(panShieldHero, "Astoltian Gear");
    PlayerModelManager_setDisplayList(panShieldHero, PMM_DL_SHIELD_HERO, gPanShield2DL);
    PlayerModelManager_addHandleToPack(panEquips, panShieldHero);

    PlayerModelManagerHandle panShieldMirror = PLAYERMODELMANAGER_REGISTER_MODEL("mm_pan_shield_mirror_pmm", PMM_MODEL_TYPE_SHIELD_MIRROR);
    PlayerModelManager_setAuthor(panShieldMirror, "Zuke");
    PlayerModelManager_setDisplayName(panShieldMirror, "Astoltian Gear");
    PlayerModelManager_setDisplayList(panShieldMirror, PMM_DL_SHIELD_MIRROR, gPanShield3DL);
    PlayerModelManager_addHandleToPack(panEquips, panShieldMirror);

    PlayerModelManagerHandle panBow = PLAYERMODELMANAGER_REGISTER_MODEL("mm_pan_bow_pmm", PMM_MODEL_TYPE_BOW);
    PlayerModelManager_setAuthor(panBow, "Zuke");
    PlayerModelManager_setDisplayName(panBow, "Astoltian Gear");
    PlayerModelManager_setDisplayList(panBow, PMM_DL_BOW, gPanBowDL);
    PlayerModelManager_setDisplayList(panBow, PMM_DL_BOW_STRING, gPanBowStringDL);
    PlayerModelManager_addHandleToPack(panEquips, panBow);

    PlayerModelManagerHandle panMaskKeaton = PLAYERMODELMANAGER_REGISTER_MODEL("mm_pan_mask_keaton_pmm", PMM_MODEL_TYPE_MASK_KEATON);
    PlayerModelManager_setAuthor(panMaskKeaton, "Zuke");
    PlayerModelManager_setDisplayName(panMaskKeaton, "Astoltian Gear");
    PlayerModelManager_setDisplayList(panMaskKeaton, PMM_DL_MASK_KEATON, gPanMaskFoxDL);
    PlayerModelManager_addHandleToPack(panEquips, panMaskKeaton);

    PlayerModelManagerHandle panMaskBremen = PLAYERMODELMANAGER_REGISTER_MODEL("mm_pan_mask_bremen_pmm", PMM_MODEL_TYPE_MASK_BREMEN);
    PlayerModelManager_setAuthor(panMaskBremen, "Zuke");
    PlayerModelManager_setDisplayName(panMaskBremen, "Astoltian Gear");
    PlayerModelManager_setDisplayList(panMaskBremen, PMM_DL_MASK_BREMEN, gPanMaskWingsDL);
    PlayerModelManager_addHandleToPack(panEquips, panMaskBremen);

    PlayerModelManagerHandle panMaskScents = PLAYERMODELMANAGER_REGISTER_MODEL("mm_pan_mask_scents_pmm", PMM_MODEL_TYPE_MASK_SCENTS);
    PlayerModelManager_setAuthor(panMaskScents, "Zuke");
    PlayerModelManager_setDisplayName(panMaskScents, "Astoltian Gear");
    PlayerModelManager_setDisplayList(panMaskScents, PMM_DL_MASK_SCENTS, gPanMaskGasDL);
    PlayerModelManager_addHandleToPack(panEquips, panMaskScents);

    PlayerModelManagerHandle panMaskCaptain = PLAYERMODELMANAGER_REGISTER_MODEL("mm_pan_mask_captain_pmm", PMM_MODEL_TYPE_MASK_CAPTAIN);
    PlayerModelManager_setAuthor(panMaskCaptain, "Zuke");
    PlayerModelManager_setDisplayName(panMaskCaptain, "Astoltian Gear");
    PlayerModelManager_setDisplayList(panMaskCaptain, PMM_DL_MASK_CAPTAIN, gPanMaskDarkHelmDL);
    PlayerModelManager_addHandleToPack(panEquips, panMaskCaptain);

    PlayerModelManagerHandle panMaskGaro = PLAYERMODELMANAGER_REGISTER_MODEL("mm_pan_mask_garo_pmm", PMM_MODEL_TYPE_MASK_GARO);
    PlayerModelManager_setAuthor(panMaskGaro, "Zuke");
    PlayerModelManager_setDisplayName(panMaskGaro, "Astoltian Gear");
    PlayerModelManager_setDisplayList(panMaskGaro, PMM_DL_MASK_GARO, gPanMaskGarosDL);
    PlayerModelManager_addHandleToPack(panEquips, panMaskGaro);

    PlayerModelManagerHandle panMaskTruth = PLAYERMODELMANAGER_REGISTER_MODEL("mm_pan_mask_truth_pmm", PMM_MODEL_TYPE_MASK_TRUTH);
    PlayerModelManager_setAuthor(panMaskTruth, "Zuke");
    PlayerModelManager_setDisplayName(panMaskTruth, "Astoltian Gear");
    PlayerModelManager_setDisplayList(panMaskTruth, PMM_DL_MASK_TRUTH, gPanMaskCowBatDL);
    PlayerModelManager_addHandleToPack(panEquips, panMaskTruth);

    PlayerModelManagerHandle panMaskFairy = PLAYERMODELMANAGER_REGISTER_MODEL("mm_pan_mask_fairy_pmm", PMM_MODEL_TYPE_MASK_GREAT_FAIRY);
    PlayerModelManager_setAuthor(panMaskFairy, "Zuke");
    PlayerModelManager_setDisplayName(panMaskFairy, "Astoltian Gear");
    PlayerModelManager_setDisplayList(panMaskFairy, PMM_DL_MASK_GREAT_FAIRY, gPanMaskFairyDL);
    PlayerModelManager_addHandleToPack(panEquips, panMaskFairy);

    PlayerModelManagerHandle panMaskBlast = PLAYERMODELMANAGER_REGISTER_MODEL("mm_pan_mask_blast_pmm", PMM_MODEL_TYPE_MASK_BLAST);
    PlayerModelManager_setAuthor(panMaskBlast, "Zuke");
    PlayerModelManager_setDisplayName(panMaskBlast, "Astoltian Gear");
    PlayerModelManager_setDisplayList(panMaskBlast, PMM_DL_MASK_BLAST, gPanMaskBombDL);
    PlayerModelManager_setDisplayList(panMaskBlast, PMM_DL_MASK_BLAST_COOLING_DOWN, gPanMaskBombCDDL);
    PlayerModelManager_addHandleToPack(panEquips, panMaskBlast);

    PlayerModelManagerHandle panMaskDon = PLAYERMODELMANAGER_REGISTER_MODEL("mm_pan_mask_don_pmm", PMM_MODEL_TYPE_MASK_DON_GERO);
    PlayerModelManager_setAuthor(panMaskDon, "Zuke");
    PlayerModelManager_setDisplayName(panMaskDon, "Astoltian Gear");
    PlayerModelManager_setDisplayList(panMaskDon, PMM_DL_MASK_DON_GERO, gPanMaskDonDL);
    PlayerModelManager_addHandleToPack(panEquips, panMaskDon);

    PlayerModelManagerHandle panMaskGibdo = PLAYERMODELMANAGER_REGISTER_MODEL("mm_pan_mask_gibdo_pmm", PMM_MODEL_TYPE_MASK_GIBDO);
    PlayerModelManager_setAuthor(panMaskGibdo, "Zuke");
    PlayerModelManager_setDisplayName(panMaskGibdo, "Astoltian Gear");
    PlayerModelManager_setDisplayList(panMaskGibdo, PMM_DL_MASK_GIBDO, gPanMaskHaloDL);
    PlayerModelManager_addHandleToPack(panEquips, panMaskGibdo);

    PlayerModelManagerHandle panMaskKamaro = PLAYERMODELMANAGER_REGISTER_MODEL("mm_pan_mask_kamaro_pmm", PMM_MODEL_TYPE_MASK_KAMARO);
    PlayerModelManager_setAuthor(panMaskKamaro, "Zuke");
    PlayerModelManager_setDisplayName(panMaskKamaro, "Astoltian Gear");
    PlayerModelManager_setDisplayList(panMaskKamaro, PMM_DL_MASK_KAMARO, gPanMaskKamaroDL);
    PlayerModelManager_addHandleToPack(panEquips, panMaskKamaro);

    PlayerModelManagerHandle panMaskNight = PLAYERMODELMANAGER_REGISTER_MODEL("mm_pan_mask_night_pmm", PMM_MODEL_TYPE_MASK_ALL_NIGHT);
    PlayerModelManager_setAuthor(panMaskNight, "Zuke");
    PlayerModelManager_setDisplayName(panMaskNight, "Astoltian Gear");
    PlayerModelManager_setDisplayList(panMaskNight, PMM_DL_MASK_ALL_NIGHT, gPanMaskNightDL);
    PlayerModelManager_addHandleToPack(panEquips, panMaskNight);

    PlayerModelManagerHandle panMaskPostman = PLAYERMODELMANAGER_REGISTER_MODEL("mm_pan_mask_postman_pmm", PMM_MODEL_TYPE_MASK_POSTMAN);
    PlayerModelManager_setAuthor(panMaskPostman, "Zuke");
    PlayerModelManager_setDisplayName(panMaskPostman, "Astoltian Gear");
    PlayerModelManager_setDisplayList(panMaskPostman, PMM_DL_MASK_POSTMAN, gPanMaskPostDL);
    PlayerModelManager_addHandleToPack(panEquips, panMaskPostman);

    PlayerModelManagerHandle panMaskStone = PLAYERMODELMANAGER_REGISTER_MODEL("mm_pan_mask_stone_pmm", PMM_MODEL_TYPE_MASK_STONE);
    PlayerModelManager_setAuthor(panMaskStone, "Zuke");
    PlayerModelManager_setDisplayName(panMaskStone, "Astoltian Gear");
    PlayerModelManager_setDisplayList(panMaskStone, PMM_DL_MASK_STONE, gPanMaskStoneDL);
    PlayerModelManager_addHandleToPack(panEquips, panMaskStone);
}



#include "anim/gPanHumanSkelPan_fighter_wait_longAnim.h"
#include "anim/gPanHumanSkelPan_fighter_wait2waitr_longAnim.h"
#include "anim/gPanHumanSkelPan_fighter_waitl2wait_longAnim.h"
#include "anim/gPanHumanSkelPan_fighter_waitr2wait_longAnim.h"
#include "anim/gPanHumanSkelPan_fighter_walk_longAnim.h"
#include "anim/gPanHumanSkelPan_fighter_walk_endl_longAnim.h"
#include "anim/gPanHumanSkelPan_fighter_walk_endr_longAnim.h"
#include "anim/gPanHumanSkelPan_fighter_side_walk_longAnim.h"
#include "anim/gPanHumanSkelPan_fighter_side_walkl_longAnim.h"
#include "anim/gPanHumanSkelPan_fighter_side_walkr_longAnim.h"
#include "anim/gPanHumanSkelPan_fighter_run_longAnim.h"
#include "anim/gPanHumanSkelPan_fighter_fighter2longAnim.h"
#include "anim/gPanHumanSkelPan_fighter_lpierce_kiru_endAnim.h"
#include "anim/gPanHumanSkelPan_fighter_lrside_kiru_endAnim.h"
#include "anim/gPanHumanSkelPan_fighter_llside_kiru_endAnim.h"
#include "anim/gPanHumanSkelPan_fighter_lrside_kiru_finsh_endAnim.h"
#include "anim/gPanHumanSkelPan_fighter_llside_kiru_finsh_endAnim.h"
#include "anim/gPanHumanSkelPan_fighter_lnormal_kiru_finsh_endAnim.h"
#include "anim/gPanHumanSkelPan_fighter_lpower_kiru_wait_endAnim.h"
#include "anim/gPanHumanSkelPan_normal_normal2fighter_freeAnim.h"
#include "anim/gPanDekuSkelGpananim_pn_gakkistartAnim.h"
#include "anim/gPanDekuSkelGpananim_pn_gakkiplayAnim.h"

extern LinkAnimationHeader gPlayerAnim_link_fighter_wait_long[];
extern LinkAnimationHeader gPlayerAnim_link_fighter_wait2waitR_long[];
extern LinkAnimationHeader gPlayerAnim_link_fighter_waitL2wait_long[];
extern LinkAnimationHeader gPlayerAnim_link_fighter_waitR2wait_long[];
extern LinkAnimationHeader gPlayerAnim_link_fighter_walk_long[];
extern LinkAnimationHeader gPlayerAnim_link_fighter_walk_endL_long[];
extern LinkAnimationHeader gPlayerAnim_link_fighter_walk_endR_long[];
extern LinkAnimationHeader gPlayerAnim_link_fighter_side_walk_long[];
extern LinkAnimationHeader gPlayerAnim_link_fighter_side_walkL_long[];
extern LinkAnimationHeader gPlayerAnim_link_fighter_side_walkR_long[];
extern LinkAnimationHeader gPlayerAnim_link_fighter_run_long[];
extern LinkAnimationHeader gPlayerAnim_link_fighter_fighter2long[];
extern LinkAnimationHeader gPlayerAnim_link_fighter_Lpierce_kiru_end[];
extern LinkAnimationHeader gPlayerAnim_link_fighter_LRside_kiru_end[];
extern LinkAnimationHeader gPlayerAnim_link_fighter_LLside_kiru_end[];
extern LinkAnimationHeader gPlayerAnim_link_fighter_LRside_kiru_finsh_end[];
extern LinkAnimationHeader gPlayerAnim_link_fighter_LLside_kiru_finsh_end[];
extern LinkAnimationHeader gPlayerAnim_link_fighter_Lnormal_kiru_finsh_end[];
extern LinkAnimationHeader gPlayerAnim_link_fighter_Lpower_kiru_wait_end[];
extern LinkAnimationHeader gPlayerAnim_link_normal_normal2fighter[];
extern LinkAnimationHeader gPlayerAnim_pn_gakkistart[];
extern LinkAnimationHeader gPlayerAnim_pn_gakkiplay[];

void updateLink(PlayState* play) {
    Player* player = GET_PLAYER(play);
    if (player->transformation == PLAYER_FORM_HUMAN) {
        *(LinkAnimationHeader*)Lib_SegmentedToVirtual(&gPlayerAnim_link_fighter_wait_long) = gPanHumanSkelPan_fighter_wait_longAnim;
        *(LinkAnimationHeader*)Lib_SegmentedToVirtual(&gPlayerAnim_link_fighter_wait2waitR_long) = gPanHumanSkelPan_fighter_wait2waitr_longAnim;
        *(LinkAnimationHeader*)Lib_SegmentedToVirtual(&gPlayerAnim_link_fighter_waitL2wait_long) = gPanHumanSkelPan_fighter_waitl2wait_longAnim;
        *(LinkAnimationHeader*)Lib_SegmentedToVirtual(&gPlayerAnim_link_fighter_waitR2wait_long) = gPanHumanSkelPan_fighter_waitr2wait_longAnim;
        *(LinkAnimationHeader*)Lib_SegmentedToVirtual(&gPlayerAnim_link_fighter_walk_long) = gPanHumanSkelPan_fighter_walk_longAnim;
        *(LinkAnimationHeader*)Lib_SegmentedToVirtual(&gPlayerAnim_link_fighter_walk_endL_long) = gPanHumanSkelPan_fighter_walk_endl_longAnim;
        *(LinkAnimationHeader*)Lib_SegmentedToVirtual(&gPlayerAnim_link_fighter_walk_endR_long) = gPanHumanSkelPan_fighter_walk_endr_longAnim;
        *(LinkAnimationHeader*)Lib_SegmentedToVirtual(&gPlayerAnim_link_fighter_side_walk_long) = gPanHumanSkelPan_fighter_side_walk_longAnim;
        *(LinkAnimationHeader*)Lib_SegmentedToVirtual(&gPlayerAnim_link_fighter_side_walkL_long) = gPanHumanSkelPan_fighter_side_walkl_longAnim;
        *(LinkAnimationHeader*)Lib_SegmentedToVirtual(&gPlayerAnim_link_fighter_side_walkR_long) = gPanHumanSkelPan_fighter_side_walkr_longAnim;
        *(LinkAnimationHeader*)Lib_SegmentedToVirtual(&gPlayerAnim_link_fighter_run_long) = gPanHumanSkelPan_fighter_run_longAnim;
        *(LinkAnimationHeader*)Lib_SegmentedToVirtual(&gPlayerAnim_link_fighter_fighter2long) = gPanHumanSkelPan_fighter_fighter2longAnim;
        *(LinkAnimationHeader*)Lib_SegmentedToVirtual(&gPlayerAnim_link_fighter_Lpierce_kiru_end) = gPanHumanSkelPan_fighter_lpierce_kiru_endAnim;
        *(LinkAnimationHeader*)Lib_SegmentedToVirtual(&gPlayerAnim_link_fighter_LRside_kiru_end) = gPanHumanSkelPan_fighter_lrside_kiru_endAnim;
        *(LinkAnimationHeader*)Lib_SegmentedToVirtual(&gPlayerAnim_link_fighter_LLside_kiru_end) = gPanHumanSkelPan_fighter_llside_kiru_endAnim;
        *(LinkAnimationHeader*)Lib_SegmentedToVirtual(&gPlayerAnim_link_fighter_LRside_kiru_finsh_end) = gPanHumanSkelPan_fighter_lrside_kiru_finsh_endAnim;
        *(LinkAnimationHeader*)Lib_SegmentedToVirtual(&gPlayerAnim_link_fighter_LLside_kiru_finsh_end) = gPanHumanSkelPan_fighter_llside_kiru_finsh_endAnim;
        *(LinkAnimationHeader*)Lib_SegmentedToVirtual(&gPlayerAnim_link_fighter_Lnormal_kiru_finsh_end) = gPanHumanSkelPan_fighter_lnormal_kiru_finsh_endAnim;
        *(LinkAnimationHeader*)Lib_SegmentedToVirtual(&gPlayerAnim_link_fighter_Lpower_kiru_wait_end) = gPanHumanSkelPan_fighter_lpower_kiru_wait_endAnim;
        *(LinkAnimationHeader*)Lib_SegmentedToVirtual(&gPlayerAnim_link_normal_normal2fighter) = gPanHumanSkelPan_normal_normal2fighter_freeAnim;
        *(LinkAnimationHeader*)Lib_SegmentedToVirtual(&gPlayerAnim_pn_gakkistart) = gPanDekuSkelGpananim_pn_gakkistartAnim;
        *(LinkAnimationHeader*)Lib_SegmentedToVirtual(&gPlayerAnim_pn_gakkiplay) = gPanDekuSkelGpananim_pn_gakkiplayAnim;
    }
}

RECOMP_CALLBACK("*", recomp_on_play_main)
void mainUpdate(PlayState* play) {
    updateLink(play);
}

TexturePtr gPanZoraBrows[] = {
    gPanZoraSkel_zora_brow_normal_ci8,
    gPanZoraSkel_zora_brow_normal_ci8,
    gPanZoraSkel_zora_brow_normal_ci8,
    gPanZoraSkel_zora_brow_left_ci8,
    gPanZoraSkel_zora_brow_left_ci8,
    gPanZoraSkel_zora_brow_angry_ci8,
    gPanZoraSkel_zora_brow_raise_ci8,
    gPanZoraSkel_zora_brow_clean_ci8,
};
TexturePtr gPanZoraEyeR[] = {
    gPanZoraSkel_zora_eye_sep_open_ci8,
    gPanZoraSkel_zora_eye_half_ci8,
    gPanZoraSkel_zora_eye_closed_ci8,
    gPanZoraSkel_zora_eye_left_ci8,
    gPanZoraSkel_zora_eye_right_ci8,
    gPanZoraSkel_zora_eye_sep_angry_ci8,
    gPanZoraSkel_zora_eye_pleased_ci8,
    gPanZoraSkel_zora_eye_wince_ci8,
};
TexturePtr gPanZoraMouths[] = {
    gPanZoraSkel_zora_mouth_closed_ci8,
    gPanZoraSkel_zora_mouth_half_ci8,
    gPanZoraSkel_zora_mouth_joy_ci8,
    gPanZoraSkel_zora_mouth_open_ci8,
};

TexturePtr gPanDekuEyesR0[] = {
    gPanDekuSkel_deku_eyes_altnorm_ci8,
    gPanDekuSkel_deku_eyes_althalf_ci8,
    gPanDekuSkel_deku_eyes_altclose_ci8,
    gPanDekuSkel_deku_eyes_altright_ci8,
    gPanDekuSkel_deku_eyes_altleft_ci8,
    gPanDekuSkel_deku_eyes_altshock_ci8,
    gPanDekuSkel_deku_eyes_altdown_ci8,
    gPanDekuSkel_deku_eyes_altclench_ci8,
};

extern struct PlayerFaceIndices {
    /* 0x0 */ u8 eyeIndex;
    /* 0x1 */ u8 mouthIndex;
} PlayerFaceIndices; // size = 0x2

extern struct PlayerFaceIndices sPlayerFaces[];

RECOMP_HOOK("Player_DrawImpl") void on_Player_DrawImpl(PlayState* play, void** skeleton, Vec3s* jointTable, s32 dListCount, s32 lod,
                     PlayerTransformation playerForm, s32 boots, s32 face, OverrideLimbDrawFlex overrideLimbDraw,
                     PostLimbDrawFlex postLimbDraw, Actor* actor) {
    s32 eyeIndex = GET_EYE_INDEX_FROM_JOINT_TABLE(jointTable);
    s32 mouthIndex = GET_MOUTH_INDEX_FROM_JOINT_TABLE(jointTable);

    OPEN_DISPS(play->state.gfxCtx);

    if (eyeIndex < 0) {
        eyeIndex = sPlayerFaces[face].eyeIndex;
    }

    if (playerForm == PLAYER_FORM_GORON) {
        if ((eyeIndex >= PLAYER_EYES_ROLL_RIGHT) && (eyeIndex <= PLAYER_EYES_ROLL_DOWN)) {
            eyeIndex = PLAYER_EYES_OPEN;
        } else if (eyeIndex == PLAYER_EYES_7) {
            eyeIndex = PLAYER_EYES_ROLL_RIGHT;
        }
    }

    if (mouthIndex < 0) {
        mouthIndex = sPlayerFaces[face].mouthIndex;
    }

    if (playerForm == PLAYER_FORM_ZORA) {
        gSPSegment(POLY_OPA_DISP++, 0x0A, Lib_SegmentedToVirtual(gPanZoraBrows[eyeIndex]));
        gSPSegment(POLY_OPA_DISP++, 0x0B, Lib_SegmentedToVirtual(gPanZoraEyeR[eyeIndex]));
        gSPSegment(POLY_OPA_DISP++, 0x0C, Lib_SegmentedToVirtual(gPanZoraMouths[mouthIndex]));
    }
    
    if (playerForm == PLAYER_FORM_DEKU) {
        gSPSegment(POLY_OPA_DISP++, 0x0B, Lib_SegmentedToVirtual(gPanDekuEyesR0[eyeIndex])); 
    }

    CLOSE_DISPS(play->state.gfxCtx);
}

extern Gfx gGiKokiriSwordGuardDL[];
extern Gfx gGiKokiriSwordBladeHiltDL[];
extern Gfx gGiRazorSwordDL[];
extern Gfx gGiGildedSwordDL[];
extern Gfx gGiGreatFairysSwordHiltEmblemDL[];
extern Gfx gGiGreatFairysSwordBladeDL[];

extern Gfx gGiHerosShieldDL[];
extern Gfx gGiHerosShieldEmblemDL[];
extern Gfx gGiMirrorShieldDL[];

extern Gfx gGiBowHandleDL[];
extern Gfx gGiBowStringDL[];

extern Gfx gGiOcarinaOfTimeDL[];
extern Gfx gGiOcarinaOfTimeHolesDL[];

extern Gfx gGiDekuMaskDL[];
extern Gfx gGiZoraMaskDL[];

extern Gfx gGiBlastMaskDL[];
extern Gfx gGiMaskOfTruthDL[];
extern Gfx gGiMaskOfTruthAccentsDL[];
extern Gfx gGiCaptainsHatFaceDL[];
extern Gfx gGiCaptainsHatBodyDL[];
extern Gfx gGiDonGeroMaskBodyDL[];
extern Gfx gGiDonGeroMaskFaceDL[];
extern Gfx gGiGreatFairyMaskLeavesDL[];
extern Gfx gGiGreatFairyMaskFaceDL[];
extern Gfx gGiKeatonMaskDL[];
extern Gfx gGiKeatonMaskEyesDL[];
extern Gfx gGiGarosMaskFaceDL[];
extern Gfx gGiGarosMaskCloakDL[];
extern Gfx gGiMaskOfScentsTeethDL[];
extern Gfx gGiMaskOfScentsFaceDL[];
extern Gfx gGiGibdoMaskDL[];
extern Gfx gGiKamaroMaskDL[];
extern Gfx gGiAllNightMaskFaceDL[];
extern Gfx gGiAllNightMaskEyesDL[];
extern Gfx gGiPostmanHatBunnyLogoDL[];
extern Gfx gGiPostmanHatCapDL[];
extern Gfx gGiStoneMaskDL[];
extern Gfx gGiBremenMaskDL[];

MODEL_REPLACER_CALLBACK_ON_REGISTER_REPLACERS void registerPanGiModels() {

    //swords
    ModelReplacerHandle panGiSwordKokiri = ModelReplacer_registerReplacer(OBJECT_GI_SWORD_1, gGiKokiriSwordBladeHiltDL, gGiPanSword1BladeDL);
    ModelReplacerHandle panGiSwordKokiri2 = ModelReplacer_registerReplacer(OBJECT_GI_SWORD_1, gGiKokiriSwordGuardDL, gGiPanSword1HiltDL);
    
    ModelReplacerHandle panGiSwordRazor = ModelReplacer_registerReplacer(OBJECT_GI_SWORD_2, gGiRazorSwordDL, gGiPanSword2DL);
    
    ModelReplacerHandle panGiSwordGilded = ModelReplacer_registerReplacer(OBJECT_GI_SWORD_3, gGiGildedSwordDL, gGiPanSword3DL);

    ModelReplacerHandle panGiSwordFairy = ModelReplacer_registerReplacer(OBJECT_GI_SWORD_4, gGiGreatFairysSwordBladeDL, gGiPanSword4BladeDL);
    ModelReplacerHandle panGiSwordFairy2 = ModelReplacer_registerReplacer(OBJECT_GI_SWORD_4, gGiGreatFairysSwordHiltEmblemDL, gGiPanSword4HiltDL);
    
    ModelReplacer_setReplacerModel(panGiSwordKokiri, gGiPanSword1BladeDL);
    ModelReplacer_setReplacerModel(panGiSwordKokiri2, gGiPanSword1HiltDL);
    ModelReplacer_setReplacerModel(panGiSwordRazor, gGiPanSword2DL);
    ModelReplacer_setReplacerModel(panGiSwordGilded, gGiPanSword3DL);
    ModelReplacer_setReplacerModel(panGiSwordFairy, gGiPanSword4BladeDL);
    ModelReplacer_setReplacerModel(panGiSwordFairy2, gGiPanSword4HiltDL);
    
    //shields
    ModelReplacerHandle panGiShieldHero = ModelReplacer_registerReplacer(OBJECT_GI_SHIELD_2, gGiHerosShieldDL, gGiPanShield2DL);
    ModelReplacerHandle panGiShieldHero2 = ModelReplacer_registerReplacer(OBJECT_GI_SHIELD_2, gGiHerosShieldEmblemDL, gGiCull);
    
    ModelReplacerHandle panGiShieldMirror = ModelReplacer_registerReplacer(OBJECT_GI_SHIELD_3, gGiMirrorShieldDL, gGiPanShield3DL);
    
    ModelReplacer_setReplacerModel(panGiShieldHero, gGiPanShield2DL);
    ModelReplacer_setReplacerModel(panGiShieldHero2, gGiCull);
    ModelReplacer_setReplacerModel(panGiShieldMirror, gGiPanShield3DL);
    
    //bow
    ModelReplacerHandle panGiBow = ModelReplacer_registerReplacer(OBJECT_GI_BOW, gGiBowHandleDL, gGiPanBowDL);
    ModelReplacerHandle panGiBowString = ModelReplacer_registerReplacer(OBJECT_GI_BOW, gGiBowStringDL, gGiPanBowStringDL);
    
    ModelReplacer_setReplacerModel(panGiBow, gGiPanBowDL);
    ModelReplacer_setReplacerModel(panGiBowString, gGiPanBowStringDL);
    
    
    //ocarina
    ModelReplacerHandle panGiOcarina = ModelReplacer_registerReplacer(OBJECT_GI_OCARINA, gGiOcarinaOfTimeDL, gGiPanOcarinaDL);
    ModelReplacerHandle panGiOcarina2 = ModelReplacer_registerReplacer(OBJECT_GI_OCARINA, gGiOcarinaOfTimeHolesDL, gGiCull);
    
    ModelReplacer_setReplacerModel(panGiOcarina, gGiPanOcarinaDL);
    ModelReplacer_setReplacerModel(panGiOcarina2, gGiCull);
    
    //transformation masks
    ModelReplacerHandle panGiDekuMask = ModelReplacer_registerReplacer(OBJECT_MASK_NUTS, gGiDekuMaskDL, gGiPanDekuMaskDL);
    ModelReplacerHandle panGiZoraMask = ModelReplacer_registerReplacer(OBJECT_MASK_ZORA, gGiZoraMaskDL, gGiPanZoraMaskDL);

    //masks
    ModelReplacerHandle panGiMaskBomb = ModelReplacer_registerReplacer(OBJECT_GI_MASK21, gGiBlastMaskDL, gGiPanMaskBombDL);

    ModelReplacerHandle panGiMaskTruth = ModelReplacer_registerReplacer(OBJECT_GI_TRUTH_MASK, gGiMaskOfTruthDL, gGiPanMaskCowBatDL);
    ModelReplacerHandle panGiMaskTruth2 = ModelReplacer_registerReplacer(OBJECT_GI_TRUTH_MASK, gGiMaskOfTruthAccentsDL, gGiCull);

    ModelReplacerHandle panGiMaskCaptain = ModelReplacer_registerReplacer(OBJECT_GI_MASK18, gGiCaptainsHatFaceDL, gGiPanMaskDarkHelmDL);
    ModelReplacerHandle panGiMaskCaptain2 = ModelReplacer_registerReplacer(OBJECT_GI_MASK18, gGiCaptainsHatBodyDL, gGiCull);

    ModelReplacerHandle panGiMaskDon = ModelReplacer_registerReplacer(OBJECT_GI_MASK16, gGiDonGeroMaskBodyDL, gGiPanMaskDonDL);
    ModelReplacerHandle panGiMaskDon2 = ModelReplacer_registerReplacer(OBJECT_GI_MASK16, gGiDonGeroMaskFaceDL, gGiCull);

    ModelReplacerHandle panGiMaskFairy = ModelReplacer_registerReplacer(OBJECT_GI_MASK14, gGiGreatFairyMaskLeavesDL, gGiPanMaskFairyDL);
    ModelReplacerHandle panGiMaskFairy2 = ModelReplacer_registerReplacer(OBJECT_GI_MASK14, gGiGreatFairyMaskLeavesDL, gGiCull);
    
    ModelReplacerHandle panGiMaskKeaton = ModelReplacer_registerReplacer(OBJECT_GI_KI_TAN_MASK, gGiKeatonMaskDL, gGiPanMaskFoxDL);
    ModelReplacerHandle panGiMaskKeaton2 = ModelReplacer_registerReplacer(OBJECT_GI_KI_TAN_MASK, gGiKeatonMaskEyesDL, gGiCull);

    ModelReplacerHandle panGiMaskGaro = ModelReplacer_registerReplacer(OBJECT_GI_MASK09, gGiGarosMaskFaceDL, gGiPanMaskGarosDL);
    ModelReplacerHandle panGiMaskGaro2 = ModelReplacer_registerReplacer(OBJECT_GI_MASK09, gGiGarosMaskCloakDL, gGiCull);

    ModelReplacerHandle panGiMaskScents = ModelReplacer_registerReplacer(OBJECT_GI_MASK22, gGiMaskOfScentsTeethDL, gGiPanMaskGasDL);
    ModelReplacerHandle panGiMaskScents2 = ModelReplacer_registerReplacer(OBJECT_GI_MASK22, gGiMaskOfScentsFaceDL, gGiCull);

    ModelReplacerHandle panGiMaskGibdo = ModelReplacer_registerReplacer(OBJECT_GI_MASK15, gGiGibdoMaskDL, gGiPanMaskHaloDL);

    ModelReplacerHandle panGiMaskKamaro = ModelReplacer_registerReplacer(OBJECT_GI_MASK17, gGiKamaroMaskDL, gGiPanMaskKamaroDL);
    
    ModelReplacerHandle panGiMaskNight = ModelReplacer_registerReplacer(OBJECT_GI_MASK06, gGiAllNightMaskFaceDL, gGiPanMaskNightDL);
    ModelReplacerHandle panGiMaskNight2 = ModelReplacer_registerReplacer(OBJECT_GI_MASK06, gGiAllNightMaskEyesDL, gGiCull);

    ModelReplacerHandle panGiMaskPost = ModelReplacer_registerReplacer(OBJECT_GI_MASK12, gGiPostmanHatCapDL, gGiPanMaskPostDL);
    ModelReplacerHandle panGiMaskPost2 = ModelReplacer_registerReplacer(OBJECT_GI_MASK12, gGiPostmanHatBunnyLogoDL, gGiCull);

    ModelReplacerHandle panGiMaskStone = ModelReplacer_registerReplacer(OBJECT_GI_STONEMASK, gGiStoneMaskDL, gGiPanMaskStoneDL);

    ModelReplacerHandle panGiMaskBremen = ModelReplacer_registerReplacer(OBJECT_GI_MASK20, gGiBremenMaskDL, gGiPanMaskWingsDL);
    

    
    ModelReplacer_setReplacerModel(panGiDekuMask, gGiPanDekuMaskDL);
    ModelReplacer_setReplacerModel(panGiZoraMask, gGiPanZoraMaskDL);

    ModelReplacer_setReplacerModel(panGiMaskBomb, gGiPanMaskBombDL);
    ModelReplacer_setReplacerModel(panGiMaskTruth, gGiPanMaskCowBatDL);
    ModelReplacer_setReplacerModel(panGiMaskCaptain, gGiPanMaskDarkHelmDL);
    ModelReplacer_setReplacerModel(panGiMaskDon, gGiPanMaskDonDL);
    ModelReplacer_setReplacerModel(panGiMaskFairy, gGiPanMaskFairyDL);
    ModelReplacer_setReplacerModel(panGiMaskKeaton, gGiPanMaskFoxDL);
    ModelReplacer_setReplacerModel(panGiMaskGaro, gGiPanMaskGarosDL);
    ModelReplacer_setReplacerModel(panGiMaskScents, gGiPanMaskGasDL);
    ModelReplacer_setReplacerModel(panGiMaskNight, gGiPanMaskNightDL);
    ModelReplacer_setReplacerModel(panGiMaskPost, gGiPanMaskPostDL);
    ModelReplacer_setReplacerModel(panGiMaskGibdo, gGiPanMaskHaloDL);
    ModelReplacer_setReplacerModel(panGiMaskKamaro, gGiPanMaskKamaroDL);
    ModelReplacer_setReplacerModel(panGiMaskStone, gGiPanMaskStoneDL);
    ModelReplacer_setReplacerModel(panGiMaskBremen, gGiPanMaskWingsDL);
    
    ModelReplacer_setReplacerModel(panGiMaskTruth2, gGiCull);
    ModelReplacer_setReplacerModel(panGiMaskCaptain2, gGiCull);
    ModelReplacer_setReplacerModel(panGiMaskDon2, gGiCull);
    ModelReplacer_setReplacerModel(panGiMaskFairy2, gGiCull);
    ModelReplacer_setReplacerModel(panGiMaskKeaton2, gGiCull);
    ModelReplacer_setReplacerModel(panGiMaskGaro2, gGiCull);
    ModelReplacer_setReplacerModel(panGiMaskScents2, gGiCull);
    ModelReplacer_setReplacerModel(panGiMaskNight2, gGiCull);
    ModelReplacer_setReplacerModel(panGiMaskPost2, gGiCull);
}