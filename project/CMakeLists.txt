cmake_minimum_required(VERSION 3.10)
project("mvlissa")

message("System: ${CMAKE_SYSTEM_NAME}")

include_directories(include source /usr/include/GL /usr/local/include)
#link_directories(./lib-extern/mac)

set(SRCBASE "source")
set(LIBBASE "lib")
set(GLBASE  "GLline")

set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -DGLEW_STATIC")



set(BINDIR  "./build/bin/${CMAKE_SYSTEM_NAME}")

add_executable(mvlissa
           ${SRCBASE}/mainSdl.cpp
           ${SRCBASE}/CSDLblurline.cpp
           ${SRCBASE}/CContextLissa.cpp
           ${SRCBASE}/CPlayObject.cpp
           ${LIBBASE}/CSdlApp.cpp
           ${LIBBASE}/NStringTool.cpp
           ${LIBBASE}/CFileIO.cpp
           ${LIBBASE}/NGlobalLog-Desktop.cpp
           ${LIBBASE}/CGL_Context.cpp
           ${LIBBASE}/CGL_Shader.cpp
           ${LIBBASE}/CGL_Shader_Color.cpp
           ${LIBBASE}/CGL_Shader_Blurline.cpp
           ${LIBBASE}/CGL_Shader_Texture.cpp
           ${LIBBASE}/CGL_Shader_Noise.cpp
           ${LIBBASE}/CGL_Basic.cpp
           ${LIBBASE}/CGL_Texture.cpp
           ${LIBBASE}/CFrameBuffer.cpp
           ${LIBBASE}/CDataRect.cpp
           ${LIBBASE}/NUtf.cpp
           ${LIBBASE}/CPixel24.cpp
           ${LIBBASE}/CPixel32.cpp
           ${LIBBASE}/CBlockOperations.cpp
           ${LIBBASE}/shader/shader_color_vert.cpp
           ${LIBBASE}/shader/shader_color_frag.cpp
           ${LIBBASE}/shader/shader_blurline_vert.cpp
           ${LIBBASE}/shader/shader_blurline_frag.cpp
           ${LIBBASE}/shader/shader_texture_vert.cpp
           ${LIBBASE}/shader/shader_texture_frag.cpp
           ${LIBBASE}/shader/shader_noise_vert.cpp
           ${LIBBASE}/shader/shader_noise_frag.cpp
           ${GLBASE}/CLineData.cpp
           ${GLBASE}/CPointData.cpp
           ${GLBASE}/CPointObject.cpp
           ${GLBASE}/CLineStrip.cpp)

if (CMAKE_SYSTEM_NAME STREQUAL "Windows")
    #
    # Windows
    #
    SET(SYSTEM_NAME "windows")
    target_link_libraries(${CMAKE_PROJECT_NAME}
        glu32
        opengl32
        gdi32
        winmm
        jpeg
        SDL2
        glew32
        png
    )
elseif (CMAKE_SYSTEM_NAME STREQUAL "Linux")
    #
    # Linux
    #
    SET(SYSTEM_NAME "linux")
    target_link_libraries(${CMAKE_PROJECT_NAME}
        SDL2
        GLEW
        GL
        )
elseif (CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    #
    # Mac OS
    #
    # *TODO*
    SET(SYSTEM_NAME "mac")



    target_link_libraries(${CMAKE_PROJECT_NAME}
        SDL2
        GLEW
        iconv
        "-framework IOKit"
        "-framework Foundation"
        "-framework Cocoa"
        "-framework CoreAudio"
        "-framework Carbon"
        "-framework OpenGL"
        "-framework ForceFeedback"
        "-framework AudioUnit"
        )
endif()


#LIBPATH    = -L../lib-extern/mac
#  INCPATH   += -I/usr/include/GL -I/usr/local/include/GL
#  FRAMEWORKS = -framework IOKit \
#               -framework Foundation \
#               -framework Cocoa   -framework CoreAudio -framework Carbon -framework OpenGL  -framework ForceFeedback  -framework AudioUnit
#  LDFLAGS   += -lSDL2 $(FRAMEWORKS) -L../lib-extern/mac -lpng -ljpeg -lGLEW -lz  -liconv  -lfreetype


file(MAKE_DIRECTORY ${BINDIR})
set_target_properties(mvlissa PROPERTIES OUTPUT_NAME ../${BINDIR}/mvlissa)
