#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;

out vec3 Normal;
out vec3 FragPos;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
// 注意，这里只是对每个vertex 进行操作，在fix raster 中会对这些vertex 和 normal 信息进行插值，计算出每个pixel 上的真正位置和attribute 信息。
void main()
{
    gl_Position = projection * view *  model * vec4(position, 1.0f);
	// fragment 位置，用来计算光照
    FragPos = vec3(model * vec4(position, 1.0f));
	// 使用 inverse 和 transpose 来获得normal 变换矩阵，防止非均匀缩放带来的normal 与surface 不垂直。
	// 为什么这么操作？简单来讲，fragment shading 的时候，光照的计算都是在world space 中，所以normal 不参与view project投影？
	// 那么为什么不利用model 矩阵直接变换到 world 空间即可？ 
	// 1. 一方面，normal 只是一个方向向量，没有w，无法做平移操作。
	// 2. 如果在三维空间中做非均匀的缩放，方向向量会发生变化，与surface 不垂直。
    Normal = mat3(transpose(inverse(model))) * normal;  
} 