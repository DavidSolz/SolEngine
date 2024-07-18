#ifndef INPUT_H
#define INPUT_H

#include <bitset>
#include <memory>

#include "window.h"

class Input
{
private:
    static std::bitset<GLFW_KEY_LAST> m_keys;
    static std::bitset<GLFW_MOUSE_BUTTON_LAST> m_buttons;

    Input() = default;
    Input(const Input &input) = delete;
    Input operator=(const Input &input) = delete;

public:
    static void update(const Window &window);

    static bool getButtonDown(const unsigned int &button);

    static bool getButtonUp(const unsigned int &button);

    static bool getKeyDown(const unsigned int &key);

    static bool getKeyUp(const unsigned int &key);
};

#endif
