#version 330 core

in vec3 vFragColor;
in vec2 vFragPosition;

out vec3 fFragColor;

float attenuation(float alpha, float beta)
{
	
	float dist=distance(vec2(0,0),vFragPosition);
	float attenuation=alpha*exp(-beta*(dist*dist));

	return attenuation;
}


void main() {
 
	 // TRIANGLE GRIS 
	  fFragColor = vec3((vFragColor.r+vFragColor.b+vFragColor.g)/3); // On mets dans les nuances de gris. 

	 // TRIANGLE - HALO 
	 // fFragColor = vec3(attenuation(1,100)*vFragColor); 

	  	
	 //	fFragColor=vec3(length(fract(5.0 * vFragPosition)));
	 // fFragColor=vec3(length(abs(fract(5.0 * vFragPosition) * 2.0 - 1.0)));
	 // fFragColor=vec3(mod(floor(10.0 * vFragPosition.x) + floor(10.0 * vFragPosition.y), 2.0));
	 // fFragColor=vec3(smoothstep(0.3, 0.32, length(fract(5.0 * vFragPosition) - 0.5)));
	 // fFragColor=vec3(smoothstep(0.4, 0.5, max(abs(fract(8.0 * vFragPosition.x - 0.5 * mod(floor(8.0 * vFragPosition.y), 2.0)) - 0.5), abs(fract(8.0 * vFragPosition.y) - 0.5)))*vFragColor);


};