#include <glad/gl.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include "linmath.h"
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

typedef struct Vertex
{
    vec2 pos;
    vec3 col;
} Vertex;

static const Vertex vertices[] =
    {
        // Head - hat
        {{-0.f, 1.f},    {0.6f, 0.15f, 0.2f}},
        {{-0.2f, 0.92f}, {0.6f, 0.15f, 0.2f}},
        {{0.2f, 0.92f},  {0.6f, 0.15f, 0.2f}},
        // face left
        {{-0.2f, 0.92f}, {0.15f, 0.4f, 0.2f}},
        {{-0.2f, 0.6f},  {0.15f, 0.4f, 0.2f}},
        {{-0.4f, 0.86f}, {0.15f, 0.4f, 0.2f}},
        // face Right
        {{0.2f, 0.92f}, {0.15f, 0.4f, 0.2f}},
        {{0.2f, 0.6f},  {0.15f, 0.4f, 0.2f}},
        {{0.4f, 0.86f}, {0.15f, 0.4f, 0.2f}},
        // head
        {{-0.2f, 0.92f}, {0.15f, 0.6f, 0.2f}},
        {{-0.2f, 0.6f},  {0.15f, 0.6f, 0.2f}},
        {{0.0f, 0.6f},   {0.15f, 0.6f, 0.2f}},

        {{0.2f, 0.92f}, {0.15f, 0.6f, 0.2f}},
        {{0.2f, 0.6f}, {0.15f, 0.6f, 0.2f}},
        {{0.0f, 0.6f}, {0.15f, 0.6f, 0.2f}},

        {{0.2f, 0.92f},  {0.15f, 0.6f, 0.2f}},
        {{-0.2f, 0.92f}, {0.15f, 0.6f, 0.2f}},
        {{0.0f, 0.6f},   {0.15f, 0.6f, 0.2f}},

        //left eye
        {{-0.12f, 0.84f}, {0.26f, 0.34f, 0.4f}},
        {{-0.08f, 0.92f}, {0.26f, 0.34f, 0.4f}},
        {{-0.04f, 0.84f}, {0.26f, 0.34f, 0.4f}},

        //right eye
        {{0.04f, 0.84f}, {0.26f, 0.34f, 0.4f}},
        {{0.08f, 0.92f}, {0.26f, 0.34f, 0.4f}},
        {{0.12f, 0.84f}, {0.26f, 0.34f, 0.4f}},

        //mouth
        {{-0.12f, 0.76f}, {0.6f, 0.15f, 0.2f}},
        {{0.f, 0.6f},     {0.6f, 0.15f, 0.2f}},
        {{0.12f, 0.76f},  {0.6f, 0.15f, 0.2f}},

        //body
        {{-0.6f, 0.6f}, {0.6f, 0.15f, 0.2f}},
        {{0.6f, 0.6f},  {0.6f, 0.15f, 0.2f}},
        {{0.f, -0.52f}, {0.6f, 0.15f, 0.2f}},

        //feet
        {{0.f, -0.52f}, {0.6f, 0.15f, 0.2f}},
        {{-0.4f, -1.f}, {0.6f, 0.15f, 0.2f}},
        {{0.4f, -1.f},  {0.6f, 0.15f, 0.2f}},

        //left hand
        {{-0.6f, 0.6f}, {0.15f, 0.6f, 0.2f}},
        {{-0.8f, 0.2f}, {0.15f, 0.6f, 0.2f}},
        {{-0.4f, 0.2f}, {0.15f, 0.6f, 0.2f}},

        //left hand middle
        {{-0.6f, -0.2f}, {0.6f, 0.15f, 0.2f}},
        {{-0.8f, 0.2f},  {0.6f, 0.15f, 0.2f}},
        {{-0.4f, 0.2f},  {0.6f, 0.15f, 0.2f}},

        //left hand down
        {{-0.4f, 0.12f}, {0.6f, 0.15f, 0.2f}},
        {{-0.6f, -0.28f}, {0.6f, 0.15f, 0.2f}},
        {{-0.2f, -0.28f}, {0.6f, 0.15f, 0.2f}},

        //right hand
        {{0.6f, 0.6f}, {0.15f, 0.6f, 0.2f}},
        {{0.4f, 0.2f}, {0.15f, 0.6f, 0.2f}},
        {{0.8f, 0.2f}, {0.15f, 0.6f, 0.2f}},

        //right hand middle
        {{0.6f, -0.2f}, {0.6f, 0.15f, 0.2f}},
        {{0.4f, 0.2f},  {0.6f, 0.15f, 0.2f}},
        {{0.8f, 0.2f},  {0.6f, 0.15f, 0.2f}},

        //right hand down
        {{0.4f, 0.12f},  {0.6f, 0.15f, 0.2f}},
        {{0.6f, -0.28f}, {0.6f, 0.15f, 0.2f}},
        {{0.2f, -0.28f}, {0.6f, 0.15f, 0.2f}},

        //heart
        {{0.f, -0.6f},    {0.6f, 0.15f, 0.2f}},
        {{-0.2f, -0.28f}, {0.6f, 0.15f, 0.2f}},
        {{0.2f, -0.28f},  {0.6f, 0.15f, 0.2f}},

        //up part
        {{0.f, -0.28f},   {0.6f, 0.15f, 0.2f}},
        {{-0.2f, -0.28f}, {0.6f, 0.15f, 0.2f}},
        {{-0.08f, 0.f},   {0.6f, 0.15f, 0.2f}},

        //down part
        {{0.f, -0.28f},  {0.6f, 0.15f, 0.2f}},
        {{0.2f, -0.28f}, {0.6f, 0.15f, 0.2f}},
        {{0.08f, 0.f},   {0.6f, 0.15f, 0.2f}}

    };

static const char *vertex_shader_text =
    "#version 330\n"
    "uniform mat4 MVP;\n"
    "uniform vec4 WSIZE;\n"
    "in vec3 vCol;\n"
    "in vec2 vPos;\n"
    "out vec4 color;\n"
    "out mat4 mvp;\n"
    "out vec4 wsize;\n"
    "void main()\n"
    "{\n"
    "    gl_Position = MVP * vec4(vPos, 0.0, 1.0);\n"
    "    color = vec4(vCol, 1.0);\n"
    "    mvp = MVP;\n"
    "    wsize = WSIZE;\n"
    "}\n";

static const char *fragment_shader_text =
    "#version 330\n"
    "in vec4 color;\n"
    "in vec4 wsize;\n"
    "in mat4 mvp;\n"
    "out vec4 fragment;\n"
    "void main()\n"
    "{\n"
    "vec2 stepSize = 1.0/wsize.xy;\n"

    "vec4 sum = vec4(0.0);\n"

    "sum += vec4(vec2(color.x - stepSize.x, color.y - stepSize.y), 0, 0) *1/16;\n"
    "sum += vec4(vec2(color.x, color.y - stepSize.y), 0, 0) * 2/16;\n"
    "sum += vec4(vec2(color.x + stepSize.x, color.y -stepSize.y), 0, 0) *1/16;\n"
    "sum += vec4(vec2(color.x - stepSize.x, color.y), 0, 0) * 2/16;\n"
    "sum += vec4(vec2(color.x, color.y), 0, 0) *4/16;\n"
    "sum += vec4(vec2(color.x + stepSize.x, color.y), 0, 0) * 2/16;\n"
    "sum += vec4(vec2(color.x - stepSize.x, color.y + stepSize.y), 0, 0) *1/16;\n"
    "sum += vec4(vec2(color.x, color.y + stepSize.y), 0, 0) * 2/16;\n"
    "sum += vec4(vec2(color.x + stepSize.x, color.y + stepSize.y), 0, 0) *1/16;\n"

    "vec4 sum2 = vec4(0.0);\n"
    "float ml = 1.0 / 9.0;\n"
    "sum2 += vec4(vec2(color.x - stepSize.x, color.y - stepSize.y), 0, 0) * ml;\n"
    "sum2 += vec4(vec2(color.x, color.y - stepSize.y), 0, 0) * ml;\n"
    "sum2 += vec4(vec2(color.x + stepSize.x, color.y -stepSize.y), 0, 0) * ml;\n"
    "sum2 += vec4(vec2(color.x - stepSize.x, color.y), 0, 0) * ml;\n"
    "sum2 += vec4(vec2(color.x, color.y), 0, 0) * ml;\n"
    "sum2 += vec4(vec2(color.x + stepSize.x, color.y), 0, 0) * ml;\n"
    "sum2 += vec4(vec2(color.x - stepSize.x, color.y + stepSize.y), 0, 0) * ml;\n"
    "sum2 += vec4(vec2(color.x, color.y + stepSize.y), 0, 0) * ml;\n"
    "sum2 += vec4(vec2(color.x + stepSize.x, color.y + stepSize.y), 0, 0) *  ml;\n"
    // "sum.a = 1.0;\n"
    // "sum.z += 1;\n"
    "fragment = color;\n"
    // "fragment = color * mvp * sum;\n"
    // "fragment = color * mvp * sum2;\n"
    // "fragment = sum;\n"

    "}\n";

static void error_callback(int error, const char *description)
{
    fprintf(stderr, "Error: %s\n", description);
}

static void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods){
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}

int main(void){

    int width = 3* 200, height = 3 * 200;

    glfwSetErrorCallback(error_callback);

    if (!glfwInit())
        exit(EXIT_FAILURE);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow *window = glfwCreateWindow(width, height, "OpenGL 2D Scene", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwSetKeyCallback(window, key_callback);

    glfwMakeContextCurrent(window);
    gladLoadGL(glfwGetProcAddress);
    glfwSwapInterval(1);

    // NOTE: OpenGL error checks have been omitted for brevity

    GLuint vertex_buffer;
    glGenBuffers(1, &vertex_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    const GLuint vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex_shader, 1, &vertex_shader_text, NULL);
    glCompileShader(vertex_shader);

    const GLuint fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment_shader, 1, &fragment_shader_text, NULL);
    glCompileShader(fragment_shader);

    const GLuint program = glCreateProgram();
    glAttachShader(program, vertex_shader);
    glAttachShader(program, fragment_shader);
    glLinkProgram(program);

    const GLint mvp_location = glGetUniformLocation(program, "MVP");
    const GLint wsize_location = glGetUniformLocation(program, "WSIZE");
    const GLint vpos_location = glGetAttribLocation(program, "vPos");
    const GLint vcol_location = glGetAttribLocation(program, "vCol");



    GLuint vertex_array;
    glGenVertexArrays(1, &vertex_array);
    glBindVertexArray(vertex_array);
    glEnableVertexAttribArray(vpos_location);
    glVertexAttribPointer(vpos_location, 2, GL_FLOAT, GL_FALSE,
                          sizeof(Vertex), (void *)offsetof(Vertex, pos));
    glEnableVertexAttribArray(vcol_location);
    glVertexAttribPointer(vcol_location, 3, GL_FLOAT, GL_FALSE,
                          sizeof(Vertex), (void *)offsetof(Vertex, col));

    while (!glfwWindowShouldClose(window))
    {
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        const float ratio = width / (float)height;

        glViewport(0, 0, width, height);
        glClear(GL_COLOR_BUFFER_BIT);

        mat4x4 m, p, mvp;
        mat4x4_identity(m);

        vec4 wsize;

        wsize[0] =  width;
        wsize[1] =  height;



        // mat4x4_rotate_Z(m, m, (float) glfwGetTime());
        mat4x4_ortho(p, -ratio, ratio, -1.f, 1.f, 1.f, -1.f);
        mat4x4_mul(mvp, p, m);

        glUseProgram(program);
        glUniformMatrix4fv(mvp_location, 1, GL_FALSE, (const GLfloat *)&mvp);
        glUniform4fv(wsize_location, 1, wsize);


        // glUniform4f(GetUniformLocation("u_Colour"));
        glBindVertexArray(vertex_array);
        glDrawArrays(GL_TRIANGLES, 0, 60);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);

    glfwTerminate();

    exit(EXIT_SUCCESS);
}

//! [code]
