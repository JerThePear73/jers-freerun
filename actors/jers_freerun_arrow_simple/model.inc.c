Lights1 jers_freerun_arrow_simple_Simple_Arrow_lights = gdSPDefLights1(
	0xFF, 0x95, 0x0,
	0xFF, 0xFF, 0x0, 0x28, 0x28, 0x28);

Vtx jers_freerun_arrow_simple_Simple_Arrow_DL_mesh_layer_7_vtx_0[28] = {
	{{ {-50, 0, 50}, 0, {112, 496}, {218, 141, 218, 255} }},
	{{ {-50, 0, -100}, 0, {112, 240}, {183, 183, 183, 255} }},
	{{ {50, 0, -100}, 0, {368, 240}, {73, 183, 183, 255} }},
	{{ {50, 50, -100}, 0, {624, 1008}, {73, 73, 183, 255} }},
	{{ {50, 0, 50}, 0, {368, 752}, {38, 141, 218, 255} }},
	{{ {50, 0, -100}, 0, {368, 1008}, {73, 183, 183, 255} }},
	{{ {50, 50, 50}, 0, {624, 752}, {38, 115, 218, 255} }},
	{{ {100, 0, 50}, 0, {368, 752}, {98, 187, 215, 255} }},
	{{ {100, 50, 50}, 0, {624, 752}, {98, 69, 215, 255} }},
	{{ {0, 0, 150}, 0, {368, 496}, {0, 183, 104, 255} }},
	{{ {0, 50, 150}, 0, {624, 496}, {0, 73, 104, 255} }},
	{{ {-100, 50, 50}, 0, {624, 752}, {158, 69, 215, 255} }},
	{{ {-100, 0, 50}, 0, {368, 752}, {158, 187, 215, 255} }},
	{{ {-50, 50, 50}, 0, {624, 752}, {218, 115, 218, 255} }},
	{{ {-50, 0, 50}, 0, {368, 752}, {218, 141, 218, 255} }},
	{{ {-50, 50, -100}, 0, {624, 1008}, {183, 73, 183, 255} }},
	{{ {-50, 0, -100}, 0, {368, 1008}, {183, 183, 183, 255} }},
	{{ {50, 0, -100}, 0, {368, 496}, {73, 183, 183, 255} }},
	{{ {50, 0, 50}, 0, {112, 496}, {38, 141, 218, 255} }},
	{{ {100, 0, 50}, 0, {112, 496}, {98, 187, 215, 255} }},
	{{ {-100, 0, 50}, 0, {112, 496}, {158, 187, 215, 255} }},
	{{ {-50, 0, -100}, 0, {368, -16}, {183, 183, 183, 255} }},
	{{ {-50, 50, -100}, 0, {880, 240}, {183, 73, 183, 255} }},
	{{ {50, 50, -100}, 0, {624, -16}, {73, 73, 183, 255} }},
	{{ {50, 50, 50}, 0, {880, 496}, {38, 115, 218, 255} }},
	{{ {-50, 50, 50}, 0, {880, 496}, {218, 115, 218, 255} }},
	{{ {-100, 50, 50}, 0, {880, 496}, {158, 69, 215, 255} }},
	{{ {100, 50, 50}, 0, {880, 496}, {98, 69, 215, 255} }},
};

Gfx jers_freerun_arrow_simple_Simple_Arrow_DL_mesh_layer_7_tri_0[] = {
	gsSPVertex(jers_freerun_arrow_simple_Simple_Arrow_DL_mesh_layer_7_vtx_0 + 0, 28, 0),
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


Gfx mat_jers_freerun_arrow_simple_Simple_Arrow[] = {
	gsSPSetLights1(jers_freerun_arrow_simple_Simple_Arrow_lights),
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, PRIMITIVE, 0, 0, 0, SHADE, 0, 0, 0, PRIMITIVE),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetPrimColor(0, 0, 255, 255, 255, 153),
	gsSPEndDisplayList(),
};

Gfx jers_freerun_arrow_simple_Simple_Arrow_DL_mesh_layer_7[] = {
	gsSPDisplayList(mat_jers_freerun_arrow_simple_Simple_Arrow),
	gsSPDisplayList(jers_freerun_arrow_simple_Simple_Arrow_DL_mesh_layer_7_tri_0),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};

