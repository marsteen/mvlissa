//
// Fragment Shader
//

// uniform vec4 uColor;
uniform vec4  uColor;
varying vec2  vTextVary;    // Textur-Koordinaten


void main()
{
	float klim = 0.5;
   //gl_FragColor = uColor;
	if (vTextVary.x > klim)
	{
		gl_FragColor = uColor;
		//float d = klim; //+ (1.0 - (vTextVary.x * vTextVary.x));
		//gl_FragColor = vec4(uColor.r, uColor.g, uColor.b, uColor.a * d);
		
	}
	else
	{
		//float d = vTextVary.x / (klim * 1.2);
		float d = vTextVary.x / klim;
		d = d * d;
		gl_FragColor = vec4(uColor.r, uColor.g, uColor.b, uColor.a * d);
		//gl_FragColor = vec4(0.0, 1.0, 0.0, 1.0);
	}
// 	gl_FragColor = vec4(0.0, 1.0, 0.0, 1.0);
	
	
}
