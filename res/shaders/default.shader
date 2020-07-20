#shader vertex
#version 330 core
layout (location = 0) in vec3 aPos;
void main()
{
    gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
}
#shader fragment
#version 330 core
out vec4 FragColor;
uniform vec4 u_color;
void main()
{
    FragColor = u_color;
}