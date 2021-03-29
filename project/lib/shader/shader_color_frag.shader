//
// Fragment Shader
//

// uniform vec4 uColor;
varying vec4  vColorVary;


void main()
{
   //gl_FragColor = uColor;
   gl_FragColor = vColorVary;

}
