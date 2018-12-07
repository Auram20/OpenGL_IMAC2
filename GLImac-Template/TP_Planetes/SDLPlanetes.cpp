#include <glimac/SDLWindowManager.hpp>
#include <GL/glew.h>
#include <glimac/common.hpp>
#include <iostream>
#include <glimac/glm.hpp>
#include <glm/gtc/random.hpp>
#include <glimac/Sphere.hpp>
#include <glimac/SDLWindowManager.hpp>
#include <glimac/Shader.hpp>
#include <glimac/Image.hpp>
#include <glimac/Program.hpp>
#include <glimac/FilePath.hpp>
#include <vector>

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
    Program program=loadProgram(applicationPath.dirPath()+"shaders/3D.vs.glsl",applicationPath.dirPath()+"shaders/tex3D.fs.glsl");
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
// On recupere la texture
    GLint uTexture=glGetUniformLocation(program.getGLId(),"uTexture");



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
    glm::mat4 ProjMatrix, ProjMatrixLune;
    glm::mat4 MVMatrix, MVMatrixLune;
    glm::mat4 NormalMatrix, NormalMatrixLune;

    ProjMatrix = glm::perspective(glm::radians(70.f),
                                 (float)800/600,
                                  0.1f,
                               100.f);

    MVMatrix= glm::translate(MVMatrix,glm::vec3(0.f, 0.f, -5.f));
    NormalMatrix = glm::transpose(glm::inverse(MVMatrix));

    std::vector<glm::vec3> Rotations;
    std::vector<glm::vec3> Positions;

    for (int i=0; i<32 ; i++)
    { 
        Rotations.push_back(glm::sphericalRand(3.f));
        Positions.push_back(glm::vec3(glm::linearRand(0.f,3.f),glm::linearRand(0.f,3.f),0));
    }
   
    
   
    /*********************************
     * TEXTURE
     *********************************/


    GLuint textures;
    glGenTextures(1,&textures);
    glUniform1i(uTexture,0);

    FilePath fp = applicationPath.dirPath() + "../../GLImac-Template/assets/textures/EarthMap.jpg";

    std::unique_ptr<Image> earthImage = loadImage(fp);
    if (earthImage != NULL) {
        glBindTexture(GL_TEXTURE_2D, textures);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, earthImage->getWidth(), earthImage->getHeight(), 0, GL_RGBA, GL_FLOAT, earthImage->getPixels());
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBindTexture(GL_TEXTURE_2D, 0);
    }





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

         // On Bind le vao pour cibler
         glBindVertexArray(vao);    

         
         // TRANSFORMATIONS PLANETES
         MVMatrix=glm::mat4(1.f);
         MVMatrix= glm::translate(MVMatrix,glm::vec3(0.f, 0.f, -5.f));
         MVMatrix = glm::rotate(MVMatrix, windowManager.getTime(),glm::vec3(0.f,1.f,0.f)); // Rotation

         // ENVOI DE MATRICES PLANETES
         glUniformMatrix4fv(uMVPMatrix, 1, GL_FALSE, glm::value_ptr(ProjMatrix * MVMatrix)); 
         glUniformMatrix4fv(uMVMatrix, 1, GL_FALSE, glm::value_ptr(MVMatrix)); 
         glUniformMatrix4fv(uNormalMatrix, 1, GL_FALSE, glm::value_ptr(NormalMatrix)); 
      

         // LA PLANETE

         glBindTexture(GL_TEXTURE_2D, textures);    
         glDrawArrays(GL_TRIANGLES,0,sphere.getVertexCount());
         glBindTexture(GL_TEXTURE_2D, 0);




// BOUCLE 32 LUNES MDR 

// On randomise un axe de rotation à chaque boucle 


    for (int i=0; i<32 ; i++)
    {    // TRANSFORMATION LUNE   

         MVMatrix=glm::mat4(1.f);
         MVMatrix = glm::translate(MVMatrix, glm::vec3(0.f ,0.f, -5.f)); // Translation, on se met sur le repère de la Terre pour faire la Rotation
         MVMatrix = glm::rotate(MVMatrix, windowManager.getTime(), Rotations[i]); // Rotation
         MVMatrix = glm::translate(MVMatrix, Positions[i]); // Translation
         MVMatrix = glm::scale(MVMatrix, glm::vec3(0.2f, 0.2f, 0.2f));      
         
         // ENVOI DE MATRICES LUNE
         glUniformMatrix4fv(uMVPMatrix, 1, GL_FALSE, glm::value_ptr(ProjMatrix * MVMatrix)); 
         glUniformMatrix4fv(uMVMatrix, 1, GL_FALSE, glm::value_ptr(MVMatrix)); 
         glUniformMatrix4fv(uNormalMatrix, 1, GL_FALSE, glm::value_ptr(NormalMatrix)); 
      
         // LA LUNE 
         glDrawArrays(GL_TRIANGLES,0,sphere.getVertexCount());
    }
      

         glBindVertexArray(0);   
         // On débind le vao afin de ne pas le modifier par erreur




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
    glDeleteTextures(1,&textures);

    return EXIT_SUCCESS;
}
