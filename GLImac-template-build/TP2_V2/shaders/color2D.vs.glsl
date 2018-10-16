#version 330 core

layout(location = 0) in vec2 aVertexPosition;
layout(location = 1) in vec3 aVertexColor;

out vec3 vFragColor;


mat3 translate(float tx, float ty)
{
	  mat3 M = mat3(vec3(1, 0, 0), vec3(0, 1, 0), vec3(tx, ty, 1));
	  return M;
}


mat3 scale(float sx, float sy)
{
	  mat3 M = mat3(vec3(sx, 0, 0), vec3(0, sy, 0), vec3(0, 0, 1));
	  return M;
}

mat3 rotate(float a)
{
	  mat3 M = mat3(vec3(cos(a), sin(a), 0), vec3(-sin(a), cos(a), 0), vec3(0, 0, 1));
	  return M;
}



void main() {
  vFragColor = aVertexColor;
  
// Exemples de Transofmations à appliquer automatiquement sur le aVertexPosition
  vec2 aTranslatePosition = vec2(aVertexPosition.x+0.5,aVertexPosition.y+0.5);
  vec2 aScale = vec2(aVertexPosition.x*2,aVertexPosition.y*2);
  vec2 aScale2 = vec2(aVertexPosition.x*2,aVertexPosition.y/2);
// gl_Position = vec4(aScale2, 0, 1);


// Transformation matricielle
  gl_Position = vec4((rotate(45) * vec3(aVertexPosition, 1)).xy, 0, 1);

};