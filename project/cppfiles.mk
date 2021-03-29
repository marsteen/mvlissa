
LIBBASE = ./lib

CPPFILES = source/mainSdl.cpp \
           source/CSDLblurline.cpp \
           source/CContextLissa.cpp \
           source/CPlayObject.cpp \
           $(LIBBASE)/CSdlApp.cpp \
           $(LIBBASE)/NStringTool.cpp \
           $(LIBBASE)/CFileIO.cpp \
           $(LIBBASE)/NGlobalLog-Desktop.cpp \
           $(LIBBASE)/CGL_Context.cpp \
           $(LIBBASE)/CGL_Shader.cpp \
           $(LIBBASE)/CGL_Shader_Color.cpp \
           $(LIBBASE)/CGL_Shader_Blurline.cpp \
           $(LIBBASE)/CGL_Shader_Texture.cpp \
           $(LIBBASE)/CGL_Shader_Noise.cpp \
           $(LIBBASE)/CGL_Basic.cpp \
           $(LIBBASE)/CGL_Texture.cpp \
           $(LIBBASE)/CFrameBuffer.cpp \
           $(LIBBASE)/CDataRect.cpp \
           $(LIBBASE)/NUtf.cpp \
           $(LIBBASE)/CPixel24.cpp \
           $(LIBBASE)/CPixel32.cpp \
           $(LIBBASE)/CBlockOperations.cpp \
           $(LIBBASE)/shader/shader_color_vert.cpp \
           $(LIBBASE)/shader/shader_color_frag.cpp \
           $(LIBBASE)/shader/shader_blurline_vert.cpp \
           $(LIBBASE)/shader/shader_blurline_frag.cpp \
           $(LIBBASE)/shader/shader_texture_vert.cpp \
           $(LIBBASE)/shader/shader_texture_frag.cpp \
           $(LIBBASE)/shader/shader_noise_vert.cpp \
           $(LIBBASE)/shader/shader_noise_frag.cpp \
           ./GLline/CLineData.cpp \
           ./GLline/CPointData.cpp  \
           ./GLline/CPointObject.cpp \
           ./GLline/CLineStrip.cpp
           
           
CFILES =  
           
