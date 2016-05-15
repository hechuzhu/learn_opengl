#version 330 core
layout (location = 0) in vec3 position;
layout (location = 2) in vec2 texCoord;

out vec2 TexCoord;

// ����4x4 �ı任���󣬿�����ÿ��draw ��ʱ������任��������ݣ��Ӷ��ı�vertex Ϊֹ��
// �ô��ǣ�����Ҫ���������µ�vertex buffer������element ��Ϣ��driver ������ܴ�
uniform mat4 transform;

void main()
{
    gl_Position = transform * vec4(position, 1.0f);
    TexCoord = vec2(texCoord.x, 1.0 - texCoord.y);
}