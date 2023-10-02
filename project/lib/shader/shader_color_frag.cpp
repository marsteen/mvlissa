const char* shader_color_frag =

    "//\n"
    "// Fragment Shader\n"
    "//\n"
    "\n"
    "// uniform vec4 uColor;\n"
    "varying vec4  vColorVary;\n"
    "\n"
    "\n"
    "void main()\n"
    "{\n"
    "   //gl_FragColor = uColor;\n"
    "   gl_FragColor = vColorVary;\n"
    "\n"
    "}\n"
    "\n";
