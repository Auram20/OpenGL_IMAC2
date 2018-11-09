
#include <glimac/SDLWindowManager.hpp>
#include <glimac/glm.hpp>
#include <glimac/Image.hpp>
#include <GL/glew.h>
#include <iostream>
#include <glimac/Program.hpp>
#include <glimac/FilePath.hpp>

using namespace glimac;

// Se placer dans le dossier GLImac-template-build/TP2_V2 et lancer : cmake ../../GLImac-Template-build && make && ./TP2_V2_SDLtemplate



struct Vertex2Duv{
    
    Vertex2Duv();
    Vertex2Duv(const glm::vec2 &vecpos, const glm::vec2 &vectex):
    position(vecpos), textures(vectex){}

    glm::vec2 position;
    glm::vec2 textures;    
};


glm::mat3 translate(float tx, float ty)
{
      glm::mat3 M = glm::mat3(glm::vec3(1, 0, 0), glm::vec3(0, 1, 0), glm::vec3(tx, ty, 1));
      return M;
}


glm::mat3 scale(float sx, float sy)
{
      glm::mat3 M = glm::mat3(glm::vec3(sx, 0, 0), glm::vec3(0, sy, 0), glm::vec3(0, 0, 1));
      return M;
}

glm::mat3 rotate(float a)
{
      glm::mat3 M = glm::mat3(glm::vec3(cos(a), sin(a), 0), glm::vec3(-sin(a), cos(a), 0), glm::vec3(0, 0, 1));
      return M;
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
    Program program=loadProgram(applicationPath.dirPath()+"shaders/tex2D.vs.glsl",applicationPath.dirPath()+"shaders/tex2D.fs.glsl");
    program.use();
// On recupere le modele matrice
    GLint uModelMatrix=glGetUniformLocation(program.getGLId(),"uModelMatrix");
// On recupere la texture
    GLint uTexture=glGetUniformLocation(program.getGLId(),"uTexture");




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


    Vertex2Duv vertices[] = { 
          Vertex2Duv(glm::vec2(-1.0f, -1.0f), glm::vec2(0.f, 1.f)),
          Vertex2Duv(glm::vec2(1.0f, -1.0f), glm::vec2(1.f, 1.f)),
          Vertex2Duv(glm::vec2(0.f, 1.f), glm::vec2(0.5f, 0.f)),
        };

   
     glBufferData(GL_ARRAY_BUFFER,3*sizeof(Vertex2Duv),vertices,GL_STATIC_DRAW);
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
    glVertexAttribPointer(VERTEX_ATTR_POSITION,2,GL_FLOAT,GL_FALSE,sizeof(Vertex2Duv), (const GLvoid *) (offsetof(Vertex2Duv, position)));
    glVertexAttribPointer(VERTEX_ATTR_SHADERB,2,GL_FLOAT,GL_FALSE,sizeof(Vertex2Duv),(const GLvoid *) (offsetof(Vertex2Duv, textures)));
     
     //ReDéBinding
     glBindBuffer(GL_ARRAY_BUFFER,0);
     // Débinding du VAO
     glBindVertexArray(0);

    GLuint textures;
    glGenTextures(1,&textures);
    glUniform1i(uTexture,0);


    float timer= 0;
    float i=0;

    FilePath fp = applicationPath.dirPath() + "../../GLImac-Template/assets/textures/triforce.png";

    std::unique_ptr<Image> triforce = loadImage(fp);
    if (triforce != NULL) {
        glBindTexture(GL_TEXTURE_2D, textures);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, triforce->getWidth(), triforce->getHeight(), 0, GL_RGBA, GL_FLOAT, triforce->getPixels());
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBindTexture(GL_TEXTURE_2D, 0);
    }

    // BOUCLE DE RENDU
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

         // REMPLISSAGE TEXTURE
         // TRIANGLE 1 
         glUniformMatrix3fv(uModelMatrix, 1, GL_FALSE, glm::value_ptr(scale(0.25,0.25)*translate(2,1.5)*rotate(-i)));
         i+=0.01;
         glBindTexture(GL_TEXTURE_2D, textures);
         glDrawArrays(GL_TRIANGLES,0,3);
         glBindTexture(GL_TEXTURE_2D, 0);


         // TRIANGLE 2 
         glUniformMatrix3fv(uModelMatrix, 1, GL_FALSE, glm::value_ptr(scale(0.25,0.25)*translate(-2,1.5)*rotate(-i)));
         i+=0.01;
         glBindTexture(GL_TEXTURE_2D, textures);
         glDrawArrays(GL_TRIANGLES,0,3);
         glBindTexture(GL_TEXTURE_2D, 0);


        // TRIANGLE 3 
         glUniformMatrix3fv(uModelMatrix, 1, GL_FALSE, glm::value_ptr(scale(0.25,0.25)*translate(2,-1.5)*rotate(i)));
         i+=0.01;
         glBindTexture(GL_TEXTURE_2D, textures);
         glDrawArrays(GL_TRIANGLES,0,3);
         glBindTexture(GL_TEXTURE_2D, 0);


        // TRIANGLE 4
         glUniformMatrix3fv(uModelMatrix, 1, GL_FALSE, glm::value_ptr(scale(0.25,0.25)*translate(-2,-1.5)*rotate(i)));
         i+=0.01;
         glBindTexture(GL_TEXTURE_2D, textures);
         glDrawArrays(GL_TRIANGLES,0,3);
         glBindTexture(GL_TEXTURE_2D, 0);

         glBindVertexArray(0);




        // Update the display
        windowManager.swapBuffers();
    }

    // On libère les ressources 
    glDeleteBuffers(1,&vbo);
    glDeleteVertexArrays(1,&vao);
    glDeleteTextures(1,&textures);

    return EXIT_SUCCESS;
}
