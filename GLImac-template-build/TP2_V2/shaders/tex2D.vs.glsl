#version 330 core

layout(location = 3) in vec2 aVertexPosition;
layout(location = 8) in vec2 aVertexTexture;

uniform mat3 uModelMatrix;

out vec2 vFragTexture;

void main() {
  vFragTexture = aVertexTexture;
  vec2 transformed = (uModelMatrix * vec3(aVertexPosition, 1)).xy;
  gl_Position = vec4(transformed, 0, 1);
};