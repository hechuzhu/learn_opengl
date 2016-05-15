#version 330 core
layout (location = 0) in vec3 position;
layout (location = 2) in vec2 texCoord;

out vec2 TexCoord;

// 定义4x4 的变换矩阵，可以在每次draw 的时候调整变换矩阵的内容，从而改变vertex 为止。
// 好处是，不需要重新设置新的vertex buffer，配置element 信息。driver 开销会很大。
uniform mat4 transform;

void main()
{
    gl_Position = transform * vec4(position, 1.0f);
    TexCoord = vec2(texCoord.x, 1.0 - texCoord.y);
}