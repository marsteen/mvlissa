#ifndef CGL_Shader_H
#define CGL_Shader_H

#include <vector>
#include <GLinclude.h>

class CGL_Shader
{
    public:


        CGL_Shader();

        bool InitShader(const char* VertexShader, const char* FragmentShader);
        void InitShaderModes(const char** Uniloc);
        virtual void InitAttribs();
        virtual void InitVars() const;

        GLuint VertAttrib() const { return mVertAttrib; }
        GLuint TextAttrib() const { return mTextAttrib; }
        GLuint ColorAttrib() const { return mColorAttrib; }

        void UseProgram() const;
        void DeleteProgram();
        GLint GetUniformLocation(const char* UniName) const;
        bool SetUniformInt(const char* Name, int i) const;
        bool SetUniformFloat(const char* UniName, float f) const;
        bool SetUniformMatrix(const char* UniName, const float* mat) const;
        bool SetUniformVec2(const char* UniName, const float* v) const;
        bool SetUniformVec3(const char* UniName, const float* v) const;
        bool SetUniformVec4(const char* UniName, const float* v) const;

        void SetUniformInt(int uloc, int i) const;
        void SetUniformMatrix(int uloc, const float* mat) const;
        void SetUniformFloat(int UniName, const float f) const;
        void SetUniformVec2(int UniName, const float* v) const;
        void SetUniformVec3(int UniName, const float* v) const;
        void SetUniformVec4(int UniName, const float* v) const;


        void SetScale(float x, float y) const;
        void SetRotation(float deg_angle) const;
        void SetPosition(float x, float y) const;
        void SetUniformVec2(const char* UniName, float x, float y) const;
        void SetViewScale(int Width, int Height) const;
        void SetColor(float r, float g, float b, float a) const;



    protected:


        GLuint LoadShader(GLenum shaderType, const char* ShaderSource);
        GLuint CreateProgram(const char* pVertexSource, const char* pFragmentSource);

        const char* mName;
        GLuint mProgram;
        GLuint mVertAttrib;
        GLuint mTextAttrib;
        GLuint mColorAttrib;
        std::vector<int> mShaderLoc;
};

#endif
