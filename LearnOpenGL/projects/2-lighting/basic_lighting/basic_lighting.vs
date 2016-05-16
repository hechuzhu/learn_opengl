#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;

out vec3 Normal;
out vec3 FragPos;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
// ע�⣬����ֻ�Ƕ�ÿ��vertex ���в�������fix raster �л����Щvertex �� normal ��Ϣ���в�ֵ�������ÿ��pixel �ϵ�����λ�ú�attribute ��Ϣ��
void main()
{
    gl_Position = projection * view *  model * vec4(position, 1.0f);
	// fragment λ�ã������������
    FragPos = vec3(model * vec4(position, 1.0f));
	// ʹ�� inverse �� transpose �����normal �任���󣬷�ֹ�Ǿ������Ŵ�����normal ��surface ����ֱ��
	// Ϊʲô��ô��������������fragment shading ��ʱ�򣬹��յļ��㶼����world space �У�����normal ������view projectͶӰ��
	// ��ôΪʲô������model ����ֱ�ӱ任�� world �ռ伴�ɣ� 
	// 1. һ���棬normal ֻ��һ������������û��w���޷���ƽ�Ʋ�����
	// 2. �������ά�ռ������Ǿ��ȵ����ţ����������ᷢ���仯����surface ����ֱ��
    Normal = mat3(transpose(inverse(model))) * normal;  
} 