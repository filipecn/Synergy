/**
* @brief MarchineCubesExample
*
*/

#pragma once

#include <Synergy/Synergy.hpp>
using namespace Synergy;

#include "GlfwOpenGlWindow.hpp"

// Forward Declaration:
class MarchingCubesRenderer;


const int kScreenWidth = 1024;
const int kScreenHeight = 768;

// Density grid dimensions
const int kGridWidth = 2;
const int kGridHeight = 2;
const int kGridDepth = 2;

const float kIsoSurfaceValue = 0.0f;

class MarchingCubesExample : public GlfwOpenGlWindow {

public:
    ~MarchingCubesExample();

    static std::shared_ptr<GlfwOpenGlWindow> getInstance();

private:
    MarchingCubesExample() = default; // Singleton. Prevent direct construction.

    MarchingCubesRenderer * marchingCubesRenderer;

    //-- 3D data sets to be rendered:
    GLuint volumeDensity_texture3d;
    GLuint cubeDensity_texture3d;


    virtual void init();
    virtual void logic();
    virtual void draw();
    virtual void cleanup();

    void createTextureStorage();
    void fillVolumeDensityTexture();
    void fillCubeDensityTexture();
    void setupCamera();

};
