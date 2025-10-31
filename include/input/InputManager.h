#pragma once

class InputManager {
public:
    InputManager() = default;
    ~InputManager() = default;

    void pollEvents();
};
