#include <iostream>

// GLEW
#define GLEW_STATIC
#include <GL/glew.h>

// GLFW
#include <GLFW/glfw3.h>


// Function prototypes
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);

// Window dimensions
const GLuint WIDTH = 800, HEIGHT = 600;

// Shaders
<<<<<<< HEAD
// shader code ��string �ķ�ʽ�洢
=======
>>>>>>> 59ae59cfca24dd55936f35b8e21c6e7d28ea6ac7
const GLchar* vertexShaderSource = "#version 330 core\n"
    "layout (location = 0) in vec3 position;\n"
    "void main()\n"
    "{\n"
    "gl_Position = vec4(position.x, position.y, position.z, 1.0);\n"
    "}\0";
const GLchar* fragmentShaderSource = "#version 330 core\n"
    "out vec4 color;\n"
    "void main()\n"
    "{\n"
    "color = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
    "}\n\0";

// The MAIN function, from here we start the application and run the game loop
int main()
{
    std::cout << "Starting GLFW context, OpenGL 3.3" << std::endl;
    // Init GLFW
    glfwInit();
    // Set all the required options for GLFW
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    // Create a GLFWwindow object that we can use for GLFW's functions
    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "LearnOpenGL", nullptr, nullptr);
    glfwMakeContextCurrent(window);

    // Set the required callback functions
    glfwSetKeyCallback(window, key_callback);

    // Set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions
    glewExperimental = GL_TRUE;
    // Initialize GLEW to setup the OpenGL Function pointers
    glewInit();

    // Define the viewport dimensions
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    glViewport(0, 0, width, height);


    // Build and compile our shader program
    // Vertex shader
<<<<<<< HEAD
	// ����һ��vertex shader ����
    GLint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	// ��vertex shader source code �󶨵�vertex shader ������
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	// ����vertex shader ����
=======
    GLint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
>>>>>>> 59ae59cfca24dd55936f35b8e21c6e7d28ea6ac7
    glCompileShader(vertexShader);
    // Check for compile time errors
    GLint success;
    GLchar infoLog[512];
<<<<<<< HEAD
	// �鿴������
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
		// ��ӡʧ����Ϣ
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }


    // Fragment shader
	// ���� fragment shader ����
    GLint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	// ��fragment shader source code ������
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	// ����fragment shader
=======
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    // Fragment shader
    GLint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
>>>>>>> 59ae59cfca24dd55936f35b8e21c6e7d28ea6ac7
    glCompileShader(fragmentShader);
    // Check for compile time errors
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    // Link shaders
<<<<<<< HEAD
	// ����shader program������link
    GLint shaderProgram = glCreateProgram();
	// ��������ɵ�vertex shader �� fragment shader �󶨵�shader program
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
	// link shader program
    glLinkProgram(shaderProgram);
    // Check for linking errors
	// �鿴link ���
=======
    GLint shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    // Check for linking errors
>>>>>>> 59ae59cfca24dd55936f35b8e21c6e7d28ea6ac7
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }
<<<<<<< HEAD
	//  link ��ɿ���ɾ��shader ����
=======
>>>>>>> 59ae59cfca24dd55936f35b8e21c6e7d28ea6ac7
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);


    // Set up vertex data (and buffer(s)) and attribute pointers
    //GLfloat vertices[] = {
    //  // First triangle
    //   0.5f,  0.5f,  // Top Right
    //   0.5f, -0.5f,  // Bottom Right
    //  -0.5f,  0.5f,  // Top Left 
    //  // Second triangle
    //   0.5f, -0.5f,  // Bottom Right
    //  -0.5f, -0.5f,  // Bottom Left
    //  -0.5f,  0.5f   // Top Left
    //}; 
    GLfloat vertices[] = {
         0.5f,  0.5f, 0.0f,  // Top Right
         0.5f, -0.5f, 0.0f,  // Bottom Right
        -0.5f, -0.5f, 0.0f,  // Bottom Left
        -0.5f,  0.5f, 0.0f   // Top Left 
    };
    GLuint indices[] = {  // Note that we start from 0!
        0, 1, 3,  // First Triangle
        1, 2, 3   // Second Triangle
    };
    GLuint VBO, VAO, EBO;
<<<<<<< HEAD
	// �������Vertex Array object�� ���ǰ�Vertex Buffer object �Ͷ�Ӧ��attribute Pointer ������Ϣ���array �е�һ��object ����
	// ��Ȼ��array�� ���ǿ��Դ洢�ܶ��� vertex buffer object �� attribute pointer ���á� ÿ��ʹ�õ�ʱ��ֻ��Ҫ����bind ��Ӧ��VAO ��������
=======
>>>>>>> 59ae59cfca24dd55936f35b8e21c6e7d28ea6ac7
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    // Bind the Vertex Array Object first, then bind and set vertex buffer(s) and attribute pointer(s).
<<<<<<< HEAD
	// �����Ȱ�VAO������VBO�� EBO ����Ϣ�ͻ����VAO
    glBindVertexArray(VAO);
	// �� VBO����ʼ��VBO ����
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	// ��EBO�� ��ʼ��EBO ������Ϊindex
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
	// ����vertex buffer layout ��Ϣ
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);
	// ���VBO
    glBindBuffer(GL_ARRAY_BUFFER, 0); // Note that this is allowed, the call to glVertexAttribPointer registered VBO as the currently bound vertex buffer object so afterwards we can safely unbind
	// ���VAO��remember: do NOT unbind the EBO, keep it bound to this VAO
=======
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0); // Note that this is allowed, the call to glVertexAttribPointer registered VBO as the currently bound vertex buffer object so afterwards we can safely unbind

>>>>>>> 59ae59cfca24dd55936f35b8e21c6e7d28ea6ac7
    glBindVertexArray(0); // Unbind VAO (it's always a good thing to unbind any buffer/array to prevent strange bugs), remember: do NOT unbind the EBO, keep it bound to this VAO


    // Uncommenting this call will result in wireframe polygons.
<<<<<<< HEAD
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
=======
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
>>>>>>> 59ae59cfca24dd55936f35b8e21c6e7d28ea6ac7

    // Game loop
    while (!glfwWindowShouldClose(window))
    {
        // Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
        glfwPollEvents();

        // Render
        // Clear the colorbuffer
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Draw our first triangle
        glUseProgram(shaderProgram);
<<<<<<< HEAD
		// ÿ��draw ��ʱ�����°�VAO
        glBindVertexArray(VAO);
		// glDrawArrays �򵥵����ΪDX ��draw��glDrawElements �������ΪDraw indexed��
        //glDrawArrays(GL_TRIANGLES, 0, 6);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		// Draw ��֮����VAO
=======
        glBindVertexArray(VAO);
        //glDrawArrays(GL_TRIANGLES, 0, 6);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
>>>>>>> 59ae59cfca24dd55936f35b8e21c6e7d28ea6ac7
        glBindVertexArray(0);

        // Swap the screen buffers
        glfwSwapBuffers(window);
    }
    // Properly de-allocate all resources once they've outlived their purpose
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
    // Terminate GLFW, clearing any resources allocated by GLFW.
    glfwTerminate();
    return 0;
}

// Is called whenever a key is pressed/released via GLFW
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}