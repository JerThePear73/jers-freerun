Lights1 jers_freerun_arrow_Arrow_Outline_lights = gdSPDefLights1(
	0xFF, 0xFF, 0xFF,
	0x0, 0x0, 0x0, 0x28, 0x28, 0x28);

Gfx jers_freerun_arrow_arrow_env_map_rgba16_aligner[] = {gsSPEndDisplayList()};
u8 jers_freerun_arrow_arrow_env_map_rgba16[] = {
	#include "actors/jers_freerun_arrow/arrow_env_map.rgba16.inc.c"
};

Vtx jers_freerun_arrow_Arrow_DL_mesh_layer_1_vtx_0[28] = {
	{{ {-50, 0, 50}, 0, {-401, -17}, {218, 141, 218, 255} }},
	{{ {-50, 0, -100}, 0, {-401, -273}, {183, 183, 183, 255} }},
	{{ {50, 0, -100}, 0, {-145, -273}, {73, 183, 183, 255} }},
	{{ {50, 50, -100}, 0, {111, 495}, {73, 73, 183, 255} }},
	{{ {50, 0, 50}, 0, {-145, 239}, {38, 141, 218, 255} }},
	{{ {50, 0, -100}, 0, {-145, 495}, {73, 183, 183, 255} }},
	{{ {50, 50, 50}, 0, {111, 239}, {38, 115, 218, 255} }},
	{{ {100, 0, 50}, 0, {-145, 239}, {98, 187, 215, 255} }},
	{{ {100, 50, 50}, 0, {111, 239}, {98, 69, 215, 255} }},
	{{ {0, 0, 150}, 0, {-145, -17}, {0, 183, 104, 255} }},
	{{ {0, 50, 150}, 0, {111, -17}, {0, 73, 104, 255} }},
	{{ {-100, 50, 50}, 0, {111, 239}, {158, 69, 215, 255} }},
	{{ {-100, 0, 50}, 0, {-145, 239}, {158, 187, 215, 255} }},
	{{ {-50, 50, 50}, 0, {111, 239}, {218, 115, 218, 255} }},
	{{ {-50, 0, 50}, 0, {-145, 239}, {218, 141, 218, 255} }},
	{{ {-50, 50, -100}, 0, {111, 495}, {183, 73, 183, 255} }},
	{{ {-50, 0, -100}, 0, {-145, 495}, {183, 183, 183, 255} }},
	{{ {50, 0, -100}, 0, {-145, -17}, {73, 183, 183, 255} }},
	{{ {50, 0, 50}, 0, {-401, -17}, {38, 141, 218, 255} }},
	{{ {100, 0, 50}, 0, {-401, -17}, {98, 187, 215, 255} }},
	{{ {-100, 0, 50}, 0, {-401, -17}, {158, 187, 215, 255} }},
	{{ {-50, 0, -100}, 0, {-145, -529}, {183, 183, 183, 255} }},
	{{ {-50, 50, -100}, 0, {367, -273}, {183, 73, 183, 255} }},
	{{ {50, 50, -100}, 0, {111, -529}, {73, 73, 183, 255} }},
	{{ {50, 50, 50}, 0, {367, -17}, {38, 115, 218, 255} }},
	{{ {-50, 50, 50}, 0, {367, -17}, {218, 115, 218, 255} }},
	{{ {-100, 50, 50}, 0, {367, -17}, {158, 69, 215, 255} }},
	{{ {100, 50, 50}, 0, {367, -17}, {98, 69, 215, 255} }},
};

Gfx jers_freerun_arrow_Arrow_DL_mesh_layer_1_tri_0[] = {
	gsSPVertex(jers_freerun_arrow_Arrow_DL_mesh_layer_1_vtx_0 + 0, 28, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
	gsSP2Triangles(3, 6, 4, 0, 6, 7, 4, 0),
	gsSP2Triangles(6, 8, 7, 0, 8, 9, 7, 0),
	gsSP2Triangles(8, 10, 9, 0, 9, 10, 11, 0),
	gsSP2Triangles(9, 11, 12, 0, 12, 11, 13, 0),
	gsSP2Triangles(12, 13, 14, 0, 14, 13, 15, 0),
	gsSP2Triangles(14, 15, 16, 0, 0, 17, 18, 0),
	gsSP2Triangles(0, 18, 9, 0, 18, 19, 9, 0),
	gsSP2Triangles(9, 20, 0, 0, 2, 21, 22, 0),
	gsSP2Triangles(22, 23, 2, 0, 22, 24, 23, 0),
	gsSP2Triangles(22, 25, 24, 0, 24, 25, 10, 0),
	gsSP2Triangles(25, 26, 10, 0, 24, 10, 27, 0),
	gsSPEndDisplayList(),
};

Vtx jers_freerun_arrow_Arrow_DL_mesh_layer_1_vtx_1[28] = {
	{{ {-53, -9, 47}, 0, {112, 496}, {41, 116, 33, 255} }},
	{{ {56, -6, -106}, 0, {368, 240}, {182, 72, 73, 255} }},
	{{ {-56, -6, -106}, 0, {112, 240}, {74, 72, 73, 255} }},
	{{ {56, 56, -106}, 0, {624, 1008}, {182, 184, 73, 255} }},
	{{ {56, -6, -106}, 0, {368, 1008}, {182, 72, 73, 255} }},
	{{ {53, -9, 47}, 0, {368, 752}, {215, 116, 33, 255} }},
	{{ {53, 59, 47}, 0, {624, 752}, {215, 140, 33, 255} }},
	{{ {108, -5, 47}, 0, {368, 752}, {157, 67, 42, 255} }},
	{{ {108, 55, 47}, 0, {624, 752}, {157, 189, 42, 255} }},
	{{ {0, -6, 158}, 0, {368, 496}, {0, 72, 151, 255} }},
	{{ {0, 56, 158}, 0, {624, 496}, {0, 184, 151, 255} }},
	{{ {-108, 55, 47}, 0, {624, 752}, {99, 189, 42, 255} }},
	{{ {-108, -5, 47}, 0, {368, 752}, {99, 67, 42, 255} }},
	{{ {-53, 59, 47}, 0, {624, 752}, {41, 140, 33, 255} }},
	{{ {-53, -9, 47}, 0, {368, 752}, {41, 116, 33, 255} }},
	{{ {-56, 56, -106}, 0, {624, 1008}, {74, 184, 73, 255} }},
	{{ {-56, -6, -106}, 0, {368, 1008}, {74, 72, 73, 255} }},
	{{ {53, -9, 47}, 0, {112, 496}, {215, 116, 33, 255} }},
	{{ {56, -6, -106}, 0, {368, 496}, {182, 72, 73, 255} }},
	{{ {-108, -5, 47}, 0, {112, 496}, {99, 67, 42, 255} }},
	{{ {108, -5, 47}, 0, {112, 496}, {157, 67, 42, 255} }},
	{{ {-56, 56, -106}, 0, {880, 240}, {74, 184, 73, 255} }},
	{{ {-56, -6, -106}, 0, {368, -16}, {74, 72, 73, 255} }},
	{{ {56, 56, -106}, 0, {624, -16}, {182, 184, 73, 255} }},
	{{ {53, 59, 47}, 0, {880, 496}, {215, 140, 33, 255} }},
	{{ {-53, 59, 47}, 0, {880, 496}, {41, 140, 33, 255} }},
	{{ {108, 55, 47}, 0, {880, 496}, {157, 189, 42, 255} }},
	{{ {-108, 55, 47}, 0, {880, 496}, {99, 189, 42, 255} }},
};

Gfx jers_freerun_arrow_Arrow_DL_mesh_layer_1_tri_1[] = {
	gsSPVertex(jers_freerun_arrow_Arrow_DL_mesh_layer_1_vtx_1 + 0, 28, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
	gsSP2Triangles(3, 5, 6, 0, 6, 5, 7, 0),
	gsSP2Triangles(6, 7, 8, 0, 8, 7, 9, 0),
	gsSP2Triangles(8, 9, 10, 0, 9, 11, 10, 0),
	gsSP2Triangles(9, 12, 11, 0, 12, 13, 11, 0),
	gsSP2Triangles(12, 14, 13, 0, 14, 15, 13, 0),
	gsSP2Triangles(14, 16, 15, 0, 0, 17, 18, 0),
	gsSP2Triangles(0, 9, 17, 0, 9, 0, 19, 0),
	gsSP2Triangles(17, 9, 20, 0, 1, 21, 22, 0),
	gsSP2Triangles(21, 1, 23, 0, 21, 23, 24, 0),
	gsSP2Triangles(21, 24, 25, 0, 24, 10, 25, 0),
	gsSP2Triangles(24, 26, 10, 0, 25, 10, 27, 0),
	gsSPEndDisplayList(),
};


Gfx mat_jers_freerun_arrow_Arrow_Env_Map[] = {
	gsSPGeometryMode(0, G_TEXTURE_GEN),
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, TEXEL0, 0, 0, 0, ENVIRONMENT, 0, 0, 0, TEXEL0, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(1984, 1984, 0, 0, 1),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 1, jers_freerun_arrow_arrow_env_map_rgba16),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadBlock(7, 0, 0, 1023, 256),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPEndDisplayList(),
};

Gfx mat_revert_jers_freerun_arrow_Arrow_Env_Map[] = {
	gsSPGeometryMode(G_TEXTURE_GEN, 0),
	gsDPPipeSync(),
	gsSPEndDisplayList(),
};

Gfx mat_jers_freerun_arrow_Arrow_Outline[] = {
	gsSPSetLights1(jers_freerun_arrow_Arrow_Outline_lights),
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsSPEndDisplayList(),
};

Gfx jers_freerun_arrow_Arrow_DL_mesh_layer_1[] = {
	gsSPDisplayList(mat_jers_freerun_arrow_Arrow_Env_Map),
	gsSPDisplayList(jers_freerun_arrow_Arrow_DL_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_jers_freerun_arrow_Arrow_Env_Map),
	gsSPDisplayList(mat_jers_freerun_arrow_Arrow_Outline),
	gsSPDisplayList(jers_freerun_arrow_Arrow_DL_mesh_layer_1_tri_1),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};

