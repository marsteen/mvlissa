const char* shader_blurline_vert =

"#version 150\n"
"//\n"
"// Vertex Shader\n"
"//\n"
"\n"
"\n"
"attribute vec4   aVertAttrib;\n"
"attribute vec4   aColorAttrib;\n"
"attribute vec2   aTextAttrib;\n"
"uniform   float  uAspect;\n"
"uniform   float  uAngle;\n"
"uniform   vec4   uColor;\n"
"uniform   vec2   uPos;\n"
"uniform   vec2   uObjPos;      // Objekt-Position\n"
"uniform   float  uObjAngle;    // Objekt-Drehwinkel\n"
"uniform   float  uObjScale;    // Objekt-Skalierung\n"
"uniform   vec2   uObjOrigin;   // Objekt-Mittelpunkt\n"
"varying   vec2   vTextVary;\n"
"\n"
"void main()\n"
"{\n"
"	float cosAlpha = cos(uAngle);\n"
"	float sinAlpha = sin(uAngle);\n"
"	float xrotpos = uPos.x + (cosAlpha * aVertAttrib.x - sinAlpha * aVertAttrib.y);\n"
"	float yrotpos = uPos.y + (sinAlpha * aVertAttrib.x + cosAlpha * aVertAttrib.y);\n"
"\n"
"	float ScaledPosX = uObjOrigin.x + (xrotpos - uObjOrigin.x) * uObjScale;\n"
"	float ScaledPosY = uObjOrigin.y + (yrotpos - uObjOrigin.y) * uObjScale;\n"
"	\n"
"	float cosAlphaObj = cos(uObjAngle);\n"
"	float sinAlphaObj = sin(uObjAngle);\n"
"	float xobjpos = uObjPos.x + (cosAlphaObj * (ScaledPosX - uObjOrigin.x) - sinAlphaObj * (ScaledPosY - uObjOrigin.y));\n"
"	float yobjpos = uObjPos.y + (sinAlphaObj * (ScaledPosX - uObjOrigin.x) + cosAlphaObj * (ScaledPosY - uObjOrigin.y));\n"
"	\n"
"	\n"
"  vec4 vertPos = vec4(xobjpos, yobjpos, aVertAttrib.z, aVertAttrib.a);\n"
"	//vec4 vertPos = aVertAttrib;\n"
"	  \n"
"	vTextVary    = aTextAttrib;\n"
"  vertPos.x   /= uAspect;\n"
"  gl_Position  = vertPos;\n"
"}\n"
"\n";
