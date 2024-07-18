#include "input.h"
#include <iostream>

std::bitset<GLFW_KEY_LAST> Input::m_keys;
std::bitset<GLFW_MOUSE_BUTTON_LAST> Input::m_buttons;

void Input::update(const Window &window)
{
    for (int i = 0; i < GLFW_KEY_LAST; ++i)
        m_keys[i] = window.isKeyPressed(i);

    for (int i = 0; i < GLFW_MOUSE_BUTTON_LAST; ++i)
        m_buttons[i] = window.isButtonPressed(i);
}

bool Input::getButtonDown(const unsigned int &button)
{
    if (button >= GLFW_MOUSE_BUTTON_LAST)
        return false;
    return m_buttons[button];
}

bool Input::getButtonUp(const unsigned int &button)
{
    if (button >= GLFW_MOUSE_BUTTON_LAST)
        return false;
    return !m_buttons[button];
}

bool Input::getKeyDown(const unsigned int &key)
{
    if (key >= GLFW_KEY_LAST)
        return false;
    return m_keys[key];
}

bool Input::getKeyUp(const unsigned int &key)
{
    if (key >= GLFW_KEY_LAST)
        return false;
    return !m_keys[key];
}
