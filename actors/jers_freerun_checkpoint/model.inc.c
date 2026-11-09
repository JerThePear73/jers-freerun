Lights1 jers_freerun_checkpoint_Fast3D_Material_001_lights = gdSPDefLights1(
	0x0, 0xFF, 0xFF,
	0x0, 0x0, 0x0, 0x28, 0x28, 0x28);

Gfx jers_freerun_checkpoint_checkpoint_gradient_ia8_aligner[] = {gsSPEndDisplayList()};
u8 jers_freerun_checkpoint_checkpoint_gradient_ia8[] = {
	#include "actors/jers_freerun_checkpoint/checkpoint_gradient.ia8.inc.c"
};

Vtx jers_freerun_checkpoint_Checkpoint_DL_mesh_layer_5_vtx_0[16] = {
	{{ {0, 0, -100}, 0, {112, 1999}, {0, 0, 129, 255} }},
	{{ {0, 200, -100}, 0, {112, 17}, {0, 0, 129, 255} }},
	{{ {71, 200, -71}, 0, {200, 17}, {90, 0, 166, 255} }},
	{{ {-71, 0, -71}, 0, {24, 1999}, {166, 0, 166, 255} }},
	{{ {-71, 200, -71}, 0, {24, 17}, {166, 0, 166, 255} }},
	{{ {-100, 0, 0}, 0, {-12, 1999}, {129, 0, 0, 255} }},
	{{ {-100, 200, 0}, 0, {-12, 17}, {129, 0, 0, 255} }},
	{{ {-71, 0, 71}, 0, {24, 1999}, {166, 0, 90, 255} }},
	{{ {-71, 200, 71}, 0, {24, 17}, {166, 0, 90, 255} }},
	{{ {0, 0, 100}, 0, {112, 1999}, {0, 0, 127, 255} }},
	{{ {0, 200, 100}, 0, {112, 17}, {0, 0, 127, 255} }},
	{{ {71, 0, 71}, 0, {200, 1999}, {90, 0, 90, 255} }},
	{{ {71, 200, 71}, 0, {200, 17}, {90, 0, 90, 255} }},
	{{ {100, 0, 0}, 0, {236, 1999}, {127, 0, 0, 255} }},
	{{ {100, 200, 0}, 0, {236, 17}, {127, 0, 0, 255} }},
	{{ {71, 0, -71}, 0, {200, 1999}, {90, 0, 166, 255} }},
};

Gfx jers_freerun_checkpoint_Checkpoint_DL_mesh_layer_5_tri_0[] = {
	gsSPVertex(jers_freerun_checkpoint_Checkpoint_DL_mesh_layer_5_vtx_0 + 0, 16, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 1, 0, 0),
	gsSP2Triangles(3, 4, 1, 0, 5, 4, 3, 0),
	gsSP2Triangles(5, 6, 4, 0, 7, 6, 5, 0),
	gsSP2Triangles(7, 8, 6, 0, 9, 8, 7, 0),
	gsSP2Triangles(9, 10, 8, 0, 11, 10, 9, 0),
	gsSP2Triangles(11, 12, 10, 0, 13, 12, 11, 0),
	gsSP2Triangles(13, 14, 12, 0, 15, 14, 13, 0),
	gsSP2Triangles(15, 2, 14, 0, 0, 2, 15, 0),
	gsSPEndDisplayList(),
};


Gfx mat_jers_freerun_checkpoint_Fast3D_Material_001[] = {
	gsSPGeometryMode(G_CULL_BACK, 0),
	gsSPSetLights1(jers_freerun_checkpoint_Fast3D_Material_001_lights),
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, SHADE, 0, TEXEL0, 0, ENVIRONMENT, 0),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_8b_LOAD_BLOCK, 1, jers_freerun_checkpoint_checkpoint_gradient_ia8),
	gsDPSetTile(G_IM_FMT_IA, G_IM_SIZ_8b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadBlock(7, 0, 0, 255, 2048),
	gsDPSetTile(G_IM_FMT_IA, G_IM_SIZ_8b, 1, 0, 0, 0, G_TX_CLAMP | G_TX_NOMIRROR, 6, 0, G_TX_CLAMP | G_TX_NOMIRROR, 3, 0),
	gsDPSetTileSize(0, 0, 0, 28, 252),
	gsSPEndDisplayList(),
};

Gfx mat_revert_jers_freerun_checkpoint_Fast3D_Material_001[] = {
	gsSPGeometryMode(0, G_CULL_BACK),
	gsDPPipeSync(),
	gsSPEndDisplayList(),
};

Gfx jers_freerun_checkpoint_Checkpoint_DL_mesh_layer_5[] = {
	gsSPDisplayList(mat_jers_freerun_checkpoint_Fast3D_Material_001),
	gsSPDisplayList(jers_freerun_checkpoint_Checkpoint_DL_mesh_layer_5_tri_0),
	gsSPDisplayList(mat_revert_jers_freerun_checkpoint_Fast3D_Material_001),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};

