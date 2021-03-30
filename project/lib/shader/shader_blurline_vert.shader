#version 120
//
// Vertex Shader
//


attribute vec4   aVertAttrib;
attribute vec4   aColorAttrib;
attribute vec2   aTextAttrib;
uniform   float  uAspect;
uniform   float  uAngle;
uniform   vec4   uColor;
uniform   vec2   uPos;
uniform   vec2   uObjPos;      // Objekt-Position
uniform   float  uObjAngle;    // Objekt-Drehwinkel
uniform   float  uObjScale;    // Objekt-Skalierung
uniform   vec2   uObjOrigin;   // Objekt-Mittelpunkt
varying   vec2   vTextVary;

void main()
{
	float cosAlpha = cos(uAngle);
	float sinAlpha = sin(uAngle);
	float xrotpos = uPos.x + (cosAlpha * aVertAttrib.x - sinAlpha * aVertAttrib.y);
	float yrotpos = uPos.y + (sinAlpha * aVertAttrib.x + cosAlpha * aVertAttrib.y);

	float ScaledPosX = uObjOrigin.x + (xrotpos - uObjOrigin.x) * uObjScale;
	float ScaledPosY = uObjOrigin.y + (yrotpos - uObjOrigin.y) * uObjScale;
	
	float cosAlphaObj = cos(uObjAngle);
	float sinAlphaObj = sin(uObjAngle);
	float xobjpos = uObjPos.x + (cosAlphaObj * (ScaledPosX - uObjOrigin.x) - sinAlphaObj * (ScaledPosY - uObjOrigin.y));
	float yobjpos = uObjPos.y + (sinAlphaObj * (ScaledPosX - uObjOrigin.x) + cosAlphaObj * (ScaledPosY - uObjOrigin.y));
	
	
  vec4 vertPos = vec4(xobjpos, yobjpos, aVertAttrib.z, aVertAttrib.a);
	//vec4 vertPos = aVertAttrib;
	  
	vTextVary    = aTextAttrib;
  vertPos.x   /= uAspect;
  gl_Position  = vertPos;
}
