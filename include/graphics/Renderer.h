#pragma once

class Renderer {
public:
    Renderer() = default;
    ~Renderer() = default;

    // Initialize the renderer and create window/GL context
    bool initialize();

    // Render a single frame
    void renderFrame();
};
