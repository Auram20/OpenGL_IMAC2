#include <glimac/SDLWindowManager.hpp>
#include <GL/glew.h>
#include <glimac/common.hpp>
#include <iostream>
#include <glimac/glm.hpp>
#include <glimac/Sphere.hpp>
#include <glimac/Shader.hpp>
#include <glimac/Image.hpp>
#include <glimac/Program.hpp>
#include <glimac/FilePath.hpp>

using namespace glimac;



int main(int argc, char** argv) {

    // Création d'une sphère 
    Sphere sphere(1, 32, 16);



    // Initialize SDL and open a window
    SDLWindowManager windowManager(800, 600, "Planetorium");

    // Initialize glew for OpenGL3+ support
    GLenum glewInitError = glewInit();
    if(GLEW_OK != glewInitError) {
        std::cerr << glewGetErrorString(glewInitError) << std::endl;
        return EXIT_FAILURE;
    }


    //********************************* IMPORTATION DES SHADERS 
    FilePath applicationPath(argv[0]);
    Program program=loadProgram(applicationPath.dirPath()+"shaders/3D.vs.glsl",applicationPath.dirPath()+"shaders/normale.fs.glsl");
    program.use();

    // Juste des indications sur le terminal
    std::cout << "OpenGL Version : " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLEW Version : " << glewGetString(GLEW_VERSION) << std::endl;




    //********************************* IMPORTATION DES VARIABLES UNIFORMES     
// On recupere uMVPMatrix
    GLint uMVPMatrix=glGetUniformLocation(program.getGLId(),"uMVPMatrix");
// On recupere uMVMatrix
    GLint uMVMatrix=glGetUniformLocation(program.getGLId(),"uMVMatrix");
// On recupere uNormalMatrix
    GLint uNormalMatrix=glGetUniformLocation(program.getGLId(),"uNormalMatrix");




    /*********************************
     * HERE SHOULD COME THE INITIALIZATION CODE
     *********************************/
    
    //********************************* VBO

     // Création du VBO 
     GLuint vbo;
     glGenBuffers(1,&vbo);
     // Binding du VBO
     glBindBuffer(GL_ARRAY_BUFFER,vbo);

     const ShapeVertex *vertices = sphere.getDataPointer();
     // Création des points 

     glBufferData(GL_ARRAY_BUFFER,sphere.getVertexCount()*sizeof(ShapeVertex),vertices,GL_STATIC_DRAW);
     //DéBinding
     glBindBuffer(GL_ARRAY_BUFFER,0);


    //********************************* VAO 

          // Création du VAO
     GLuint vao; 
     glGenVertexArrays(1,&vao);
     // Binding du VAO
     glBindVertexArray(vao);
     // ReBinding du VBO
     glBindBuffer(GL_ARRAY_BUFFER,vbo);

     // Activation des attributs en vertex
     const GLuint VERTEX_ATTR_POSITION = 0;
     glEnableVertexAttribArray(VERTEX_ATTR_POSITION);
     const GLuint VERTEX_ATTR_NORMAL = 1;
     glEnableVertexAttribArray(VERTEX_ATTR_NORMAL);
     const GLuint VERTEX_ATTR_TEXCOORDS = 2;
     glEnableVertexAttribArray(VERTEX_ATTR_TEXCOORDS);

    //Spécification des attributs de vertex 
    glVertexAttribPointer(VERTEX_ATTR_POSITION,3,GL_FLOAT,GL_FALSE,sizeof(ShapeVertex), (const GLvoid *) (offsetof(ShapeVertex, position)));
    glVertexAttribPointer(VERTEX_ATTR_NORMAL,3,GL_FLOAT,GL_FALSE,sizeof(ShapeVertex),(const GLvoid *) (offsetof(ShapeVertex, normal)));
    glVertexAttribPointer(VERTEX_ATTR_TEXCOORDS,2,GL_FLOAT,GL_FALSE,sizeof(ShapeVertex),(const GLvoid *) (offsetof(ShapeVertex, texCoords)));
     
    //ReDéBinding
     glBindBuffer(GL_ARRAY_BUFFER,0);
    // Débinding du VAO
     glBindVertexArray(0);


    //********************************* Test de profondeur du GPU 

    glEnable(GL_DEPTH_TEST);


//********************************* Variables
    glm::mat4 ProjMatrix;
    glm::mat4 MVMatrix;
    glm::mat4 NormalMatrix;

    ProjMatrix = glm::perspective(glm::radians(70.f),
                                 (float)800/600,
                                  0.1f,
                               100.f);

    MVMatrix= glm::translate(MVMatrix,glm::vec3(0.f, 0.f, -5.f));

    NormalMatrix = glm::transpose(glm::inverse(MVMatrix));



    /*********************************
     * HERE COMES THE LOOP
     *********************************/
    
    bool done = false;
    while(!done) {
        // Event loop:
        SDL_Event e;
        while(windowManager.pollEvent(e)) {
            if(e.type == SDL_QUIT) {
                done = true; // Leave the loop after this iteration
            }
        }

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // On dessine

         glUniformMatrix4fv(uMVPMatrix, 1, GL_FALSE, glm::value_ptr(ProjMatrix * MVMatrix)); 
         glUniformMatrix4fv(uMVMatrix, 1, GL_FALSE, glm::value_ptr(MVMatrix)); 
         glUniformMatrix4fv(uNormalMatrix, 1, GL_FALSE, glm::value_ptr(NormalMatrix)); 
         

         // SPHERE
         // On Bind le vao pour cibler
         glBindVertexArray(vao); 
         glDrawArrays(GL_TRIANGLES,0,sphere.getVertexCount());
         // On débind le vao afin de ne pas le modifier par erreur
         glBindVertexArray(0);   


        // Update the display
        windowManager.swapBuffers();

        /*********************************
         * HERE SHOULD COME THE RENDERING CODE
         *********************************/

        // Update the display
        windowManager.swapBuffers();
    }

    glDeleteBuffers(1,&vbo);
    glDeleteVertexArrays(1,&vao);

    return EXIT_SUCCESS;
}
