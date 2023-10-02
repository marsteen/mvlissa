const char* shader_texture_frag =

    "//\n"
    "// Fragment Textur Shader\n"
    "//\n"
    "\n"
    "\n"
    "uniform sampler2D uTexture;\n"
    "varying vec2      vTextVary;  // Textur-Koordinaten\n"
    "\n"
    "\n"
    "void main()\n"
    "{ \n"
    "  //gl_FragColor = vec4(1.0, 0.0, 0.0, 1.0); \n"
    "	\n"
    "	\n"
    "\n"
    "	//vec4 TexColor = texture2D(uTexture, vTextVary);\n"
    "	//gl_FragColor = vec4(0.0, 0.5, 0.0, 1.0);\n"
    "	gl_FragColor = texture2D(uTexture, vTextVary);\n"
    "}\n"
    "\n";
