#include <glimac/SDLWindowManager.hpp>
#include <glimac/glm.hpp>
#include <GL/glew.h>
#include <iostream>
#include <vector>
#include <glimac/Program.hpp>
#include <glimac/FilePath.hpp>

using namespace glimac;

struct Vertex2DColor
{
    
    Vertex2DColor();
    Vertex2DColor(const float x, const float y, const float r, const float v, const float b);
    Vertex2DColor(const glm::vec2 &vecpos, const glm::vec3 &veccol):
    position(vecpos), color(veccol){}

    glm::vec2 position;
    glm::vec3 color;    
};



Vertex2DColor::Vertex2DColor(const float x, const float y, const float r, const float v, const float b)
{
    position[0]=x;
    position[1]=y;
    color[0]=r;
    color[1]=v;
    color[2]=b;
}


int main(int argc, char** argv) {
    // Initialize SDL and open a window
    SDLWindowManager windowManager(800, 800, "TP1-Colourful");

    // Initialize glew for OpenGL3+ support
    GLenum glewInitError = glewInit();
    if(GLEW_OK != glewInitError) {
        std::cerr << glewGetErrorString(glewInitError) << std::endl;
        return EXIT_FAILURE;
    }

    FilePath applicationPath(argv[0]);
    Program program=loadProgram(applicationPath.dirPath()+"shaders/triangle.vs.glsl",applicationPath.dirPath()+"shaders/triangle.fs.glsl");
    program.use();
    



    std::cout << "OpenGL Version : " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLEW Version  : " << glewGetString(GLEW_VERSION) << std::endl;




    /*********************************
     * HERE SHOULD COME THE INITIALIZATION CODE
     *********************************/
     // Création du VBO 
     GLuint vbo;
     glGenBuffers(1,&vbo);
     // Binding du VBO
     glBindBuffer(GL_ARRAY_BUFFER,vbo);
     // Création des points 

    std::vector<Vertex2DColor> vertices;
    const size_t NB_TRIANGLES=150;
    float r=0.5;
    float angle=0;

    for (size_t i=0; i<NB_TRIANGLES; i++)
    {
        vertices.push_back(Vertex2DColor(glm::vec2(0.f, 0.f), glm::vec3(0.0f, 0.f, 1.f)));
        vertices.push_back(Vertex2DColor(glm::vec2(r*glm::cos(angle), r*glm::sin(angle)), glm::vec3(0.0f, 0.f, 0.5f)));
        angle=2*glm::pi<float>()*((i+1)/(float)NB_TRIANGLES);
        vertices.push_back(Vertex2DColor(glm::vec2(r*glm::cos(angle), r*glm::sin(angle)), glm::vec3(0.0f, 0.f, 0.5f)));

   }


   
     glBufferData(GL_ARRAY_BUFFER,3*NB_TRIANGLES*sizeof(Vertex2DColor),vertices.data(),GL_STATIC_DRAW);
     //DéBinding
     glBindBuffer(GL_ARRAY_BUFFER,0);

     // Création du VAO
     GLuint vao; 
     glGenVertexArrays(1,&vao);
     // Binding du VAO
     glBindVertexArray(vao);
     // ReBinding du VBO
     glBindBuffer(GL_ARRAY_BUFFER,vbo);
     // Activation des attributs en vertex
     const GLuint VERTEX_ATTR_POSITION = 3;
     glEnableVertexAttribArray(VERTEX_ATTR_POSITION);
     const GLuint VERTEX_ATTR_SHADERB = 8;
     glEnableVertexAttribArray(VERTEX_ATTR_SHADERB);



     //Spécification des attributs de vertex 
    glVertexAttribPointer(VERTEX_ATTR_POSITION,2,GL_FLOAT,GL_FALSE,5*sizeof(GLfloat), (const GLvoid *) offsetof(Vertex2DColor, position));
    glVertexAttribPointer(VERTEX_ATTR_SHADERB,3,GL_FLOAT,GL_FALSE,5*sizeof(GLfloat),(const GLvoid *) (offsetof(Vertex2DColor, color)));
     
     //ReDéBinding
     glBindBuffer(GL_ARRAY_BUFFER,0);
     // Débinding du VAO
     glBindVertexArray(0);


    // Application loop:
    bool done = false;
    while(!done) {
        // Event loop:
        SDL_Event e;
        while(windowManager.pollEvent(e)) {
            if(e.type == SDL_QUIT) {
                done = true; // Leave the loop after this iteration
            }
        }

        /*********************************
         * HERE SHOULD COME THE RENDERING CODE
         *********************************/
        // On nettoie la fenetre à chaque tour de boucle
         glClear(GL_COLOR_BUFFER_BIT);
         // On dessine
         glBindVertexArray(vao);
         glDrawArrays(GL_TRIANGLES,0,NB_TRIANGLES*3);
         glBindVertexArray(0);




        // Update the display
        windowManager.swapBuffers();
    }

    // On libère les ressources 
    glDeleteBuffers(1,&vbo);
    glDeleteVertexArrays(1,&vao);

    return EXIT_SUCCESS;
}
