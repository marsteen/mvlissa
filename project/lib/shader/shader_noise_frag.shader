//
// Fragment Textur Shader
//



varying vec2      vTextVary;  // Textur-Koordinaten
uniform float     uSeed;


float rand(vec2 co)
{
  return fract(sin(dot(co.xy ,vec2(12.9898,78.233))) * 43758.5453);
}


float Noise()
{
  vec3 col;
  vec2 seed;
  
  seed = fract(vTextVary.st * uSeed);
  
  return fract(rand(seed)) * 0.1;
}

void main()
{ 
  //gl_FragColor = vec4(1.0, 0.0, 0.0, 1.0); 
	
	float tr = Noise(); //fract(100007.0 * vTextVary.x + vTextVary.y * uSeed);

	//vec4 TexColor = texture2D(uTexture, vTextVary);
	//gl_FragColor = vec4(1.0, 1.0, 1.0, 1.0);
 	gl_FragColor = vec4(tr, tr, tr, 1.0);
}
