//
// Fragment Textur Shader
//


uniform sampler2D uTexture;
varying vec2      vTextVary;  // Textur-Koordinaten


void main()
{ 
  //gl_FragColor = vec4(1.0, 0.0, 0.0, 1.0); 
	
	

	//vec4 TexColor = texture2D(uTexture, vTextVary);
	//gl_FragColor = vec4(0.0, 0.5, 0.0, 1.0);
	gl_FragColor = texture2D(uTexture, vTextVary);
}
