Gfx jers_freerun_flag_finish_flag_finish_rgba16_aligner[] = {gsSPEndDisplayList()};
u8 jers_freerun_flag_finish_flag_finish_rgba16[] = {
	#include "actors/jers_freerun_flag_finish/flag_finish.rgba16.inc.c"
};

Vtx jers_freerun_flag_finish_Flag_Finish_DL_mesh_layer_5_vtx_0[4] = {
	{{ {-150, 300, 0}, 0, {1008, -16}, {0, 0, 129, 255} }},
	{{ {150, 300, 0}, 0, {-16, -16}, {0, 0, 129, 255} }},
	{{ {150, 0, 0}, 0, {-16, 1008}, {0, 0, 129, 255} }},
	{{ {-150, 0, 0}, 0, {1008, 1008}, {0, 0, 129, 255} }},
};

Gfx jers_freerun_flag_finish_Flag_Finish_DL_mesh_layer_5_tri_0[] = {
	gsSPVertex(jers_freerun_flag_finish_Flag_Finish_DL_mesh_layer_5_vtx_0 + 0, 4, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSPEndDisplayList(),
};


Gfx mat_jers_freerun_flag_finish_Fast3D_Material[] = {
	gsSPGeometryMode(G_CULL_BACK, 0),
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetPrimColor(0, 0, 255, 255, 255, 153),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 1, jers_freerun_flag_finish_flag_finish_rgba16),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadBlock(7, 0, 0, 1023, 256),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, 0, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPEndDisplayList(),
};

Gfx mat_revert_jers_freerun_flag_finish_Fast3D_Material[] = {
	gsSPGeometryMode(0, G_CULL_BACK),
	gsDPPipeSync(),
	gsSPEndDisplayList(),
};

Gfx jers_freerun_flag_finish_Flag_Finish_DL_mesh_layer_5[] = {
	gsSPDisplayList(mat_jers_freerun_flag_finish_Fast3D_Material),
	gsSPDisplayList(jers_freerun_flag_finish_Flag_Finish_DL_mesh_layer_5_tri_0),
	gsSPDisplayList(mat_revert_jers_freerun_flag_finish_Fast3D_Material),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};

