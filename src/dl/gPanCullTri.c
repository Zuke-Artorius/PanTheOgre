#include "gPanCullTri.h"

Vtx gPanCullTri_gPanCullTri_mesh_layer_Opaque_vtx_cull[8] = {
	{{ {-100, 0, -100}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {-100, 0, 100}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {-100, 0, 100}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {-100, 0, -100}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {100, 0, -100}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {100, 0, 100}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {100, 0, 100}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {100, 0, -100}, 0, {0, 0}, {0, 0, 0, 0} }},
};

Vtx gPanCullTri_gPanCullTri_mesh_layer_Opaque_vtx_0[3] = {
	{{ {-100, 0, 100}, 0, {-16, 1008}, {0, 127, 0, 255} }},
	{{ {100, 0, 0}, 0, {1008, -16}, {0, 127, 0, 255} }},
	{{ {-100, 0, -100}, 0, {-16, -16}, {0, 127, 0, 255} }},
};

Gfx gPanCullTri_gPanCullTri_mesh_layer_Opaque_tri_0[] = {
	gsSPVertex(gPanCullTri_gPanCullTri_mesh_layer_Opaque_vtx_0 + 0, 3, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSPEndDisplayList(),
};

Gfx mat_gPanCullTri_cull_f3d_layerOpaque[] = {
	gsSPLoadGeometryMode(G_FOG | G_CULL_FRONT | G_SHADE | G_ZBUFFER | G_CULL_BACK | G_SHADING_SMOOTH | G_LIGHTING),
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, 1, COMBINED, 0, PRIMITIVE, 0, 0, 0, 0, COMBINED),
	gsSPSetOtherMode(G_SETOTHERMODE_H, 4, 20, G_AD_NOISE | G_TT_NONE | G_TC_FILT | G_TP_PERSP | G_PM_NPRIMITIVE | G_CD_MAGICSQ | G_TF_BILERP | G_TD_CLAMP | G_CYC_2CYCLE | G_CK_NONE | G_TL_TILE),
	gsSPSetOtherMode(G_SETOTHERMODE_L, 0, 32, G_RM_FOG_SHADE_A | G_AC_NONE | G_ZS_PIXEL | G_RM_AA_ZB_OPA_SURF2),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetPrimColor(0, 0, 255, 255, 255, 255),
	gsSPEndDisplayList(),
};

Gfx mat_revert_gPanCullTri_cull_f3d_layerOpaque[] = {
	gsDPPipeSync(),
	gsSPSetOtherMode(G_SETOTHERMODE_L, 0, 32, G_AC_NONE | G_RM_AA_ZB_OPA_SURF | G_RM_AA_ZB_OPA_SURF2 | G_ZS_PIXEL),
	gsSPEndDisplayList(),
};

Gfx gPanCullTri[] = {
	gsSPClearGeometryMode(G_LIGHTING),
	gsSPVertex(gPanCullTri_gPanCullTri_mesh_layer_Opaque_vtx_cull + 0, 8, 0),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPCullDisplayList(0, 7),
	gsSPDisplayList(mat_gPanCullTri_cull_f3d_layerOpaque),
	gsSPDisplayList(gPanCullTri_gPanCullTri_mesh_layer_Opaque_tri_0),
	gsSPDisplayList(mat_revert_gPanCullTri_cull_f3d_layerOpaque),
	gsSPEndDisplayList(),
};

