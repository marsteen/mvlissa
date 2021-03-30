#version 120
//
// Fragment Shader
//

// uniform vec4 uColor;
uniform vec4  uColor;
varying vec2  vTextVary;    // Textur-Koordinaten


void main()
{
    const float klim = 0.9;
	if (vTextVary.x > klim)
	{
		gl_FragColor = uColor;		
	}
	else
	{
		float d = smoothstep(0.0, 1.0, vTextVary.x / klim);
		gl_FragColor = vec4(uColor.r, uColor.g, uColor.b, uColor.a * d);
	}
}
