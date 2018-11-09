#version 330 core

in vec2 vFragTexture;

out vec3 fFragColor;

uniform sampler2D uTexture;

void main() {
  //fFragColor.rgb = vec3(1,0,0);
  fFragColor.rgb = texture(uTexture, vFragTexture).rgb;
};