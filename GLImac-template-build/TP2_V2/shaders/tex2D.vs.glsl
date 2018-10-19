#version 330

layout(location = 3) in vec2 aVertexPosition;
layout(location = 8) in vec3 aVertexColor;

out vec3 vColor;

// Variable uniforme pour le temps écoulé depuis l'application du shader 
uniform float uTime;


// Fonction rotation
mat3 rotate(float a)
{
	  mat3 M = mat3(vec3(cos(a), sin(a), 0), vec3(-sin(a), cos(a), 0), vec3(0, 0, 1));
	  return M;
}


void main() {
    vColor = aVertexColor;
    mat3 MatriceRotateTime=rotate(uTime);
    vec2 transformed=(MatriceRotateTime*vec3(aVertexPosition,1)).xy;
    gl_Position = vec4(transformed, 0, 1);
}
