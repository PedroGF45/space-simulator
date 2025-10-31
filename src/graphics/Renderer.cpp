#include <graphics/Renderer.h>
#include <iostream>

bool Renderer::initialize(bool useVulkan, bool useSDL, bool useAudio) {
    // Minimal stub: just record that the renderer is initialized.
    // Real implementation will create windows, contexts and audio devices.
    std::cout << "Renderer::initialize called. Vulkan=" << useVulkan << " SDL=" << useSDL << " Audio=" << useAudio << "\n";
    initialized.store(true);
    return true;
}

void Renderer::renderFrame() {
    if (!initialized.load()) return;
    // Stubbed clear color output
    std::cout << "Renderer::renderFrame - rendering a frame (stub)" << std::endl;
}

void Renderer::shutdown() {
    if (!initialized.load()) return;
    std::cout << "Renderer::shutdown - releasing resources (stub)" << std::endl;
    initialized.store(false);
}
