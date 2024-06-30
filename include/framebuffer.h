#ifndef FRAMEBUFFER_H
#define FRAMEBUFFER_H

#include <GL/glew.h>

#include "texture2d.h"

class Framebuffer{

    GLuint m_fbo;
    GLuint m_rbo;

    bool m_isDefault;

public:

    Framebuffer();

    void createFramebuffer(const Texture2D & texture);

    void createRendebuffer();

    void bind() const;

    ~Framebuffer();
};

#endif
