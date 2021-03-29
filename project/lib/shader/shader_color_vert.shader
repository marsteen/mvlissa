//
// Vertex Shader
//


attribute vec4  aVertAttrib;
attribute vec4  aColorAttrib;
uniform  float  uAspect;
varying vec4    vColorVary;

void main()
{
  vec4 vertPos = aVertAttrib;
  vColorVary   = aColorAttrib;
  vertPos.x /= uAspect;
  gl_Position = vertPos;
}
