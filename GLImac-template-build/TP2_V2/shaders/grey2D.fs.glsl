#version 330 core

in vec3 vFragColor;

out vec3 fFragColor;

void main() {
  fFragColor = vec3((vFragColor.r+vFragColor.b+vFragColor.g)/3);
};