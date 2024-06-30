#include "framebuffer.h"

Framebuffer::Framebuffer(){

    this->m_fbo = 0;
    this->m_rbo = 0;

    this->m_isDefault = true;
    glGetIntegerv(GL_FRAMEBUFFER_BINDING_OES, (GLint *)&m_fbo);

}

void Framebuffer::createFramebuffer(const Texture2D & texture){

    glGenFramebuffers(1, &m_fbo);
    glBindFramebuffer(GL_FRAMEBUFFER, m_fbo);
    glFramebufferTexture2D(GL_FRAMEBUFFER,GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, texture(), 0);

}

void Framebuffer::createRendebuffer(){

    glGenRenderbuffers(1, &m_rbo);

}

void Framebuffer::bind() const{
    glBindFramebuffer(GL_FRAMEBUFFER, m_fbo);
}

Framebuffer::~Framebuffer(){

    if(!m_isDefault)
        glDeleteFramebuffers(1, &m_fbo);

}
