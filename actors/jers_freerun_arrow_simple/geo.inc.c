#include "src/game/envfx_snow.h"

const GeoLayout jers_freerun_arrow_simple_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_SCALE(LAYER_FORCE, 16384),
		GEO_OPEN_NODE(),
			GEO_ANIMATED_PART(LAYER_TRANSPARENT_INTER, 0, 0, 0, jers_freerun_arrow_simple_Simple_Arrow_DL_mesh_layer_7),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
