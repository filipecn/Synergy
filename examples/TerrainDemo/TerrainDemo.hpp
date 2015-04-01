/// TerrainDemo

#pragma once

#include <Synergy/Synergy.hpp>

#include "GlfwOpenGlWindow.hpp"
#include "TerrainBlockGenerator.hpp"

// Forward Declarations:
class TerrainBlockGenerator;
class MarchingCubesSurfacePolygonizer;
class RockDensityGenerator;
class LightingOven;
class TerrainRenderer;


const int kScreenWidth = 1024;
const int kScreenHeight = 768;

// Terrain Block density texture dimenions:
const int kGridWidth = 3;
const int kGridHeight = 3;
const int kGridDepth = 3;


class TerrainDemo : public GlfwOpenGlWindow {

public:
    ~TerrainDemo();

    static std::shared_ptr<GlfwOpenGlWindow> getInstance();

private:
    TerrainDemo() = default; // Singleton. Prevent direct construction.

	TerrainBlockGenerator * terrainBlockGenerator;
    MarchingCubesSurfacePolygonizer * surfacePolygonizer;
	RockDensityGenerator * rockDensityGenerator;
	LightingOven * lightingOven;
	TerrainRenderer * terrainRenderer;

	std::map<WorldSpaceIndex, TerrainBlock *> blockMap;

    virtual void init();
    virtual void logic();
    virtual void draw();
    virtual void cleanup();

    void setupCamera();
	void setupGl();
};
