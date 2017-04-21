#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include <IL/il.h>
#include "Camera.h"
#include "Mesh.h"
#include "ShaderProgram.h"
#include "Texture2D.h"
#include "Transform.h"
#include <iostream>
#include <vector>

Mesh _mesh;
Mesh _mesh2;
ShaderProgram _shaderProgram;
Transform _transform;
Transform _transform2;
Transform _transform3;
Texture2D _texture;
Texture2D _texture2;
Texture2D _texture3;
Camera _camera;
float timee;
float timeY;
bool rotando = true;
bool iniciaDerecha = false;
bool iniciaIzquierda = false;
bool iniciaDerecha3 = false;
bool iniciaIzquierda3 = false;
bool estado2 = false;
bool estado3 = false;
bool estado1 = true;
void Initialize()
{
    std::vector<glm::vec3> positions;
    // Cara trasera
    positions.push_back(glm::vec3(-1.0f, -1.0f, -1.0));
    positions.push_back(glm::vec3(1.0f, -1.0f, -1.0f));
    positions.push_back(glm::vec3(1.0f, 1.0f, -1.0f));
    positions.push_back(glm::vec3(-1.0f, 1.0f, -1.0f));
    // Cara derecha
    positions.push_back(glm::vec3(1.0f, -1.0f, -1.0f));
    positions.push_back(glm::vec3(1.0f, -1.0f, 1.0f));
    positions.push_back(glm::vec3(1.0f, 1.0f, 1.0f));
    positions.push_back(glm::vec3(1.0f, 1.0f, -1.0f));
    // Cara frontal
    positions.push_back(glm::vec3(1.0f, -1.0f, 1.0f));
    positions.push_back(glm::vec3(-1.0f, -1.0f, 1.0f));
    positions.push_back(glm::vec3(-1.0f, 1.0f, 1.0f));
    positions.push_back(glm::vec3(1.0f, 1.0f, 1.0f));
    // Cara izquierda
    positions.push_back(glm::vec3(-1.0f, -1.0f, 1.0f));
    positions.push_back(glm::vec3(-1.0f, -1.0f, -1.0f));
    positions.push_back(glm::vec3(-1.0f, 1.0f, -1.0f));
    positions.push_back(glm::vec3(-1.0f, 1.0f, 1.0f));
    // Cara arriba
    positions.push_back(glm::vec3(-1.0f, 1.0f, -1.0f));
    positions.push_back(glm::vec3(1.0f, 1.0f, -1.0f));
    positions.push_back(glm::vec3(1.0f, 1.0f, 1.0f));
    positions.push_back(glm::vec3(-1.0f, 1.0f, 1.0f));
    // Cara abajo
    positions.push_back(glm::vec3(-1.0f, -1.0f, 1.0f));
    positions.push_back(glm::vec3(1.0f, -1.0f, 1.0f));
    positions.push_back(glm::vec3(1.0f, -1.0f, -1.0f));
    positions.push_back(glm::vec3(-1.0f, -1.0f, -1.0f));

    std::vector<glm::vec3> positions2;

    //Front face
    positions2.push_back(glm::vec3( 0.0f, 1.0f, 0.0f));
    positions2.push_back(glm::vec3( -1.0f, -1.0f, 1.0f));
    positions2.push_back(glm::vec3( 1.0f, -1.0f, 1.0f));

    //Right face
    positions2.push_back(glm::vec3( 0.0f, 1.0f, 0.0f));
    positions2.push_back(glm::vec3( 1.0f, -1.0f, 1.0f));
    positions2.push_back(glm::vec3( 1.0f, -1.0f, -1.0f));

    //back face
    positions2.push_back(glm::vec3( 0.0f, 1.0f, 0.0f));
    positions2.push_back(glm::vec3( 1.0f, -1.0f, -1.0f));
    positions2.push_back(glm::vec3( -1.0f, -1.0f, -1.0f));

    //LeftFace
    positions2.push_back(glm::vec3( 0.0f, 1.0f, 0.0f));
    positions2.push_back(glm::vec3( -1.0f, -1.0f, -1.0f));
    positions2.push_back(glm::vec3( -1.0f, -1.0f, 1.0f));



    /*
    //Frente
    positions2.push_back(glm::vec3( -1.0f, -1.0f, 1.0f)); //0
    positions2.push_back(glm::vec3( 1.0f, -1.0f, 1.0f)); // 1
    positions2.push_back(glm::vec3( 0.5f, 1.0f, -0.5f));  //2

    //derecha
    positions2.push_back(glm::vec3( 0.5f, 1.0f, -0.5f)); //3
    positions2.push_back(glm::vec3( 1.0f, -1.0f, -1.0f)); // 4
    positions2.push_back(glm::vec3( 1.0f, -1.0f, 1.0f));  //5
//
//    //atras
    positions2.push_back(glm::vec3( -1.0f, -1.0f, -1.0f)); //6
    positions2.push_back(glm::vec3( -1.0f, -1.0f, -1.0f)); // 7
    positions2.push_back(glm::vec3( 0.5f, 1.0f, 0.5f));  //8

//
    //izquierda
    positions2.push_back(glm::vec3( -1.0f, -1.0f, -1.0f)); //9
    positions2.push_back(glm::vec3( -1.0f, -1.0f, 1.0f)); // 10
    positions2.push_back(glm::vec3( 0.5f, 1.0f, -0.5f));  //11
     */









    // Right face (x = 1.0f)

    /*positions2.push_back(glm::vec3(1.0f,  1.0f, -1.0f));
    positions2.push_back(glm::vec3(1.0f,  1.0f,  1.0f));
    positions2.push_back(glm::vec3(1.0f, -1.0f,  1.0f));
    positions2.push_back(glm::vec3(1.0f, -1.0f, -1.0f));

    // Front face  (z = 1.0f)

    positions2.push_back(glm::vec3( 1.0f,  1.0f, 1.0f));
    positions2.push_back(glm::vec3(-1.0f,  1.0f, 1.0f));
    positions2.push_back(glm::vec3(-1.0f, -1.0f, 1.0f));
    positions2.push_back(glm::vec3( 1.0f, -1.0f, 1.0f));

    // Left face (x = -1.0f)

    positions2.push_back(glm::vec3(-1.0f,  1.0f,  1.0f));
    positions2.push_back(glm::vec3(-1.0f,  1.0f, -1.0f));
    positions2.push_back(glm::vec3(-1.0f, -1.0f, -1.0f));
    positions2.push_back(glm::vec3(-1.0f, -1.0f,  1.0f));

    // Top face (y = 1.0f)

    positions2.push_back(glm::vec3( 1.0f, 1.0f, -1.0f));
    positions2.push_back(glm::vec3(-1.0f, 1.0f, -1.0f));
    positions2.push_back(glm::vec3(-1.0f, 1.0f,  1.0f));
    positions2.push_back(glm::vec3( 1.0f, 1.0f,  1.0f));

    // Bottom face (y = -1.0f)

    positions2.push_back(glm::vec3( 1.0f, -1.0f,  1.0f));
    positions2.push_back(glm::vec3(-1.0f, -1.0f,  1.0f));
    positions2.push_back(glm::vec3(-1.0f, -1.0f, -1.0f));
    positions2.push_back(glm::vec3( 1.0f, -1.0f, -1.0f));*/

    std::vector<glm::vec3> colors;
    // Cara trasera
    colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
    colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
    colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
    colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
    // Cara derecha
    colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
    colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
    colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
    colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
    // Cara frontal
    colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
    colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
    colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
    colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
    // Cara izquierda
    colors.push_back(glm::vec3(1.0f, 0.0f, 1.0f));
    colors.push_back(glm::vec3(1.0f, 0.0f, 1.0f));
    colors.push_back(glm::vec3(1.0f, 0.0f, 1.0f));
    colors.push_back(glm::vec3(1.0f, 0.0f, 1.0f));
    // Cara arriba
    colors.push_back(glm::vec3(0.0f, 1.0f, 1.0f));
    colors.push_back(glm::vec3(0.0f, 1.0f, 1.0f));
    colors.push_back(glm::vec3(0.0f, 1.0f, 1.0f));
    colors.push_back(glm::vec3(0.0f, 1.0f, 1.0f));
    // Cara abajo
    colors.push_back(glm::vec3(0.3f, 0.5f, 0.7f));
    colors.push_back(glm::vec3(0.3f, 0.5f, 0.7f));
    colors.push_back(glm::vec3(0.3f, 0.5f, 0.7f));
    colors.push_back(glm::vec3(0.3f, 0.5f, 0.7f));

    std::vector<glm::vec3> normals;
    // Cara trasera
    normals.push_back(glm::vec3(0.0f, 0.0f, -1.0f));
    normals.push_back(glm::vec3(0.0f, 0.0f, -1.0f));
    normals.push_back(glm::vec3(0.0f, 0.0f, -1.0f));
    normals.push_back(glm::vec3(0.0f, 0.0f, -1.0f));
    // Cara derecha
    normals.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
    normals.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
    normals.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
    normals.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
    // Cara frontalt
    normals.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
    normals.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
    normals.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
    normals.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
    // Cara izquierda
    normals.push_back(glm::vec3(-1.0f, 0.0f, 0.0f));
    normals.push_back(glm::vec3(-1.0f, 0.0f, 0.0f));
    normals.push_back(glm::vec3(-1.0f, 0.0f, 0.0f));
    normals.push_back(glm::vec3(-1.0f, 0.0f, 0.0f));
    // Cara arriba
    normals.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
    normals.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
    normals.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
    normals.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
    // Cara abajo
    normals.push_back(glm::vec3(0.0f, -1.0f, 0.0f));
    normals.push_back(glm::vec3(0.0f, -1.0f, 0.0f));
    normals.push_back(glm::vec3(0.0f, -1.0f, 0.0f));
    normals.push_back(glm::vec3(0.0f, -1.0f, 0.0f));

    std::vector<glm::vec2> texCoords;
    texCoords.push_back(glm::vec2(0.0f, 0.0f));
    texCoords.push_back(glm::vec2(1.0f, 0.0f));
    texCoords.push_back(glm::vec2(1.0f, 1.0f));
    texCoords.push_back(glm::vec2(0.0f, 1.0f));
    texCoords.push_back(glm::vec2(0.0f, 0.0f));
    texCoords.push_back(glm::vec2(1.0f, 0.0f));
    texCoords.push_back(glm::vec2(1.0f, 1.0f));
    texCoords.push_back(glm::vec2(0.0f, 1.0f));
    texCoords.push_back(glm::vec2(0.0f, 0.0f));
    texCoords.push_back(glm::vec2(1.0f, 0.0f));
    texCoords.push_back(glm::vec2(1.0f, 1.0f));
    texCoords.push_back(glm::vec2(0.0f, 1.0f));
    texCoords.push_back(glm::vec2(0.0f, 0.0f));
    texCoords.push_back(glm::vec2(1.0f, 0.0f));
    texCoords.push_back(glm::vec2(1.0f, 1.0f));
    texCoords.push_back(glm::vec2(0.0f, 1.0f));
    texCoords.push_back(glm::vec2(0.0f, 0.0f));
    texCoords.push_back(glm::vec2(1.0f, 0.0f));
    texCoords.push_back(glm::vec2(1.0f, 1.0f));
    texCoords.push_back(glm::vec2(0.0f, 1.0f));
    texCoords.push_back(glm::vec2(0.0f, 0.0f));
    texCoords.push_back(glm::vec2(1.0f, 0.0f));
    texCoords.push_back(glm::vec2(1.0f, 1.0f));
    texCoords.push_back(glm::vec2(0.0f, 1.0f));

    std::vector<glm::vec2> texCoords2;

    texCoords2.push_back(glm::vec2(0.0f, 0.0f));
    texCoords2.push_back(glm::vec2(1.0f, 0.0f));
    texCoords2.push_back(glm::vec2(0.5f, 1.0f));
    texCoords2.push_back(glm::vec2(0.0f, 0.0f));
    texCoords2.push_back(glm::vec2(1.0f, 0.0f));
    texCoords2.push_back(glm::vec2(0.5f, 1.0f));
    texCoords2.push_back(glm::vec2(0.0f, 0.0f));
    texCoords2.push_back(glm::vec2(1.0f, 0.0f));
    texCoords2.push_back(glm::vec2(0.5f, 1.0f));
    texCoords2.push_back(glm::vec2(0.0f, 0.0f));
    texCoords2.push_back(glm::vec2(1.0f, 0.0f));
    texCoords2.push_back(glm::vec2(0.5f, 1.0f));

    std::vector<unsigned int> indices{0, 1, 2, 0, 2, 3, 4, 5, 6, 4, 6, 7, 8, 9, 10, 8, 10, 11, 12, 13, 14, 12, 14, 15, 16, 17, 18, 16, 18, 19, 20, 21, 22, 20, 22, 23};
    //std::vector<unsigned int> indices2{2, 1, 0, 2, 3, 0, 6, 5, 4, 6, 7, 4, 10, 9, 8, 10, 8, 11, 12, 13, 14, 12, 14, 15, 16, 17, 18, 16, 18, 19, 20, 21, 22, 20, 22, 23};
    std::vector<unsigned int> indices2{0, 1, 2,3,4,5,6,7,8,9,10,11};

    _mesh.CreateMesh(24);
    _mesh.SetPositionAttribute(positions, GL_STATIC_DRAW, 0);
    _mesh.SetColorAttribute(colors, GL_STATIC_DRAW, 1);
    _mesh.SetNormalAttribute(normals, GL_STATIC_DRAW, 2);
    _mesh.SetTexCoordAttribute(texCoords, GL_STATIC_DRAW, 3);
    _mesh.SetIndices(indices, GL_STATIC_DRAW);

    //Para la piramide
    _mesh2.CreateMesh(12);
    _mesh2.SetPositionAttribute(positions2, GL_STATIC_DRAW, 0);
    /*_mesh2.SetColorAttribute(colors, GL_STATIC_DRAW, 1);
    _mesh2.SetNormalAttribute(normals, GL_STATIC_DRAW, 2);*/
    _mesh2.SetTexCoordAttribute(texCoords2, GL_STATIC_DRAW, 3);
    //_mesh2.SetIndices(indices2, GL_STATIC_DRAW);



    _shaderProgram.CreateProgram();
    _shaderProgram.Activate();
    _shaderProgram.AttachShader("DefaultTextured.vert", GL_VERTEX_SHADER);
    _shaderProgram.AttachShader("DefaultTextured.frag", GL_FRAGMENT_SHADER);
    _shaderProgram.SetAttribute(0, "VertexPosition");
    _shaderProgram.SetAttribute(1, "VertexColor");
    _shaderProgram.SetAttribute(2, "VertexNormal");
    _shaderProgram.SetAttribute(3, "VertexTexCoord");
    _shaderProgram.LinkProgram();
    _shaderProgram.Deactivate();

    _camera.SetPerspective(1.0f, 1000.0f, 60.0f, 1.0f);
    _camera.SetPosition(0.0f, 0.0f, -5.0f);

    _texture.LoadTexture("crate.png");
    _texture2.LoadTexture("floor.jpg");
    _texture3.LoadTexture("pyramid.png");

    _shaderProgram.Activate();
    //_shaderProgram.SetUniformf("iResolution", 400.0f, 400.0f);
    _shaderProgram.SetUniformf("LightPosition", 0.0f, 3.0f, 5.0f);
    _shaderProgram.SetUniformf("LightColor", 1.0f, 1.0f, 1.0f);
    _shaderProgram.SetUniformf("CameraPosition", _camera.GetPosition().x, _camera.GetPosition().y, -_camera.GetPosition().z);
    _shaderProgram.SetUniformi("DiffuseTexture", 0);
    _shaderProgram.Deactivate();

    timee = 0.0f;
    //_transform.SetPosition(1.0f, 0.0f, 0.0f);
    _transform2.SetScale(50.f, 0.5f, 50.0f);
    _transform2.SetPosition(0.0f, -5.5f, 0.0f);

    //_transform3.SetScale(10.5f,0.5f,10.0f);
    _transform3.SetPosition(0.0f,2.0f,-0.5f);


}

void Idle()
{
    glutPostRedisplay();
}
void IniciaRotacion(){

    _transform.SetRotation(timee, timee, timee);
    _transform3.SetRotation(timee, timee, timee);
}
void GameLoop()
{
    // Siempre es recomendable borrar la información anterior del framebuffer.
    // En este caso estamos borrando la información de color,
    // y la información de profundidad.
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    _shaderProgram.Activate();

    _texture.Bind();
    glActiveTexture(GL_TEXTURE0);

    timee += 0.005f;
    timeY += 0.005f;
    if (timee >= 360)
        timee = 0;
    if (timeY >= 360)
        timee = 0;

    if(estado1){
        _transform.SetRotation(0.0f, timeY, 0.0f);
        _transform3.SetRotation(0.0f, timeY, 0.0f);
    }
    if(iniciaDerecha && estado2){
        _transform3.SetRotation(0.0f,timeY,0.0f);
    }
    if(iniciaIzquierda && estado2){
        _transform3.SetRotation(0.0f,-timeY,0.0f);
    }
    if(iniciaDerecha3 && estado3){
        _transform.SetRotation(0.0f,timeY,0.0f);
    }
    if(iniciaIzquierda3 && estado3){
        _transform.SetRotation(0.0f,-timeY,0.0f);
    }
    //_shaderProgram.SetUniformf("iGlobaltimee", timee);
   // _transform.SetRotation(timee, timee, timee);
    //_transform.SetPosition(1.0f, 0.0f, 0.0f);
    _shaderProgram.SetUniformMatrix("ModelMatrix", _transform.GetModelMatrix());
    _shaderProgram.SetUniformMatrix("NormalMatrix", glm::mat3(glm::transpose(glm::inverse(_transform.GetModelMatrix()))));
    _shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection() * _transform.GetModelMatrix());
    _mesh.Draw(GL_TRIANGLES);

    _texture.Unbind();

    //_transform.SetPosition(-1.0f, 0.0f, 0.0f);
    _texture2.Bind();// Textura del piso
    _shaderProgram.SetUniformMatrix("ModelMatrix", _transform2.GetModelMatrix());
    _shaderProgram.SetUniformMatrix("NormalMatrix", glm::mat3(glm::transpose(glm::inverse(_transform2.GetModelMatrix()))));
    _shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection() * _transform2.GetModelMatrix());
    _mesh.Draw(GL_TRIANGLES);

    _texture2.Unbind();

    _texture3.Bind();// Textura del piso
    _shaderProgram.SetUniformMatrix("ModelMatrix", _transform3.GetModelMatrix());
    _shaderProgram.SetUniformMatrix("NormalMatrix", glm::mat3(glm::transpose(glm::inverse(_transform3.GetModelMatrix()))));
    _shaderProgram.SetUniformMatrix("mvpMatrix", _camera.GetViewProjection() * _transform3.GetModelMatrix());
    _mesh2.Draw(GL_TRIANGLES);

    _texture3.Unbind();

    _shaderProgram.Deactivate();

    // Cambiar el buffer actual.
    glutSwapBuffers();
}

void Keyboard(unsigned char key, int x, int y){



    if(key == 'w') {
        _camera.MoveForward(0.1f, false);
    }
    if(key == 's') {
        _camera.MoveForward(-0.1f, false);
    }
    if(key == 'd') {
        _camera.MoveRight(0.1f, false);
    }
    if(key == 'a') {
        _camera.MoveRight(-0.1f, false);
    }
    if(key == '1'){
        estado1 = true;
        rotando = true;
        /*iniciaDerecha =false;
        iniciaIzquierda =false;
        iniciaDerecha3 = false;
        iniciaIzquierda3 = false;*/
        estado2 = false;
        estado3 = false;
    }
    if(key == '2'){
        rotando = false;
        estado2 = true;
        estado3 = false;
        estado1 =  false;

    }if (key == '3'){
        estado3 = true;
        rotando = false;
        estado2 = false;
        estado1 = false;
    }


}



void SpecialKeys(int key, int x, int y){

    if(key == GLUT_KEY_UP){
        _transform.MoveForward(0.1f, true);
    }
    if(key == GLUT_KEY_DOWN){
        _transform.MoveForward(-0.1f, true);
    }
    if(key == GLUT_KEY_RIGHT){
        if(estado2) {
            _transform.SetRotation(0.0f, timeY, 0.0f);
            iniciaDerecha = true;
            iniciaIzquierda = false;
        }
        //_transform3.SetRotation(0.0f,timeY,0.0f);

        if(estado3){
            _transform3.SetRotation(0.0f,timeY,0.0f);
            iniciaDerecha3 = true;
            iniciaIzquierda3 = false;
        }
    }
    if(key == GLUT_KEY_LEFT){
        if(estado2) {
            _transform.SetRotation(0.0f, -timeY, 0.0f);
            iniciaIzquierda = true;
            iniciaDerecha = false;
        }
        //_transform3.SetRotation(0.0f,-timeY,0.0f);
        if(estado3){
            _transform3.SetRotation(0.0f, timeY, 0.0f);
            iniciaIzquierda3 = true;
            iniciaDerecha3 = false;
        }
    }


}

int _previousX = -1;
bool _mousePressed = false;
void MouseButtons(int button, int state, int x, int y){

    if(button == GLUT_LEFT_BUTTON){
        if(state == GLUT_DOWN) {

            _mousePressed = true;
        }else if(state == GLUT_UP){
            _mousePressed = false;

        }
        _previousX = x;
    }

    if(button == GLUT_LEFT_BUTTON) {
        _transform.MoveForward(0.1f, true);
    }
    if(button == GLUT_RIGHT_BUTTON){
        _transform.MoveForward(-0.1f,true);
    }

}

void MouseMotion(int x, int y){

    if(!_mousePressed) return;
    _camera.Yaw((x - _previousX) * 0.1f);
    _previousX = x;

}

void MousePassiveMotion(int x, int y){

    int centerX = glutGet(GLUT_WINDOW_WIDTH)/2;
    int centerY = glutGet(GLUT_WINDOW_HEIGHT)/2;
    int deltaX = x - centerX;

    _camera.Rotate(0.0f, -deltaX * 0.01f, 0.0f, true);

    if(deltaX){
        glutWarpPointer(centerX, centerY);
    }

}

void ReshapeWindow(int width, int height){

    glViewport(0,0, width, height);
    _camera.SetPerspective(1.0f, 1000.0f, 60.0f, (float) width/(float) height);

}



int main(int argc, char* argv[])
{
    // Inicialización de Freeglut.
    // Freeglut se encarga de crear una ventana
    // En donde vamos a poder dibujar
    glutInit(&argc, argv);
    // Freeglut es el encargado de solicitar un contexto
    // de OpenGL. El contexto se refiere a las capacidades
    // que va a tener nuestra aplicación gráfica.
    glutInitContextVersion(4, 4);
    // Tenemos que informar que queremos trabajar únicamente con
    // el pipeline programable
    glutInitContextProfile(GLUT_CORE_PROFILE);
    // Freeglut nos permite configurar eventos que ocurren en la venta.
    // Un evento que nos interesa es cuando alguien cierra la venta.
    // En este caso simplemente dejamos de renderear y terminamos el programa.
    glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);
    // Configuramos el framebuffer. En este caso estamos solicitando
    // un buffer true color RGBA, un buffer de profundidad y un segundo buffer
    // para renderear.
    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
    glutInitWindowSize(400, 400);
    // Le damos un nombre a la ventana y la creamos.
    glutCreateWindow("Hello World GL");
    // Asociamos una funcion de render. Esta función se
    // mandará a llamar para dibujar un frame.
    glutDisplayFunc(GameLoop);
    glutIdleFunc(Idle);
    glutKeyboardFunc(Keyboard);
    glutSpecialFunc(SpecialKeys);
    //glutMouseFunc(MouseButtons);
    //glutMotionFunc(MouseMotion);



    //glutPassiveMotionFunc(MousePassiveMotion);

    int centerX = glutGet(GLUT_WINDOW_WIDTH)/2;
    int centerY = glutGet(GLUT_WINDOW_HEIGHT)/2;
    glutWarpPointer(centerX, centerY);
    glutReshapeFunc(ReshapeWindow);

    // Inicializar GLEW. Esta librería se encarga
    // de obtener el API de OpenGL de nuestra tarjeta
    // de video. SHAME ON YOU MICROSOFT.
    glewExperimental = GL_TRUE;
    glewInit();

    // Configuramos OpenGL. Este es el color
    // por default del buffer de color en el framebuffer.
    glClearColor(1.0f, 1.0f, 0.5f, 1.0f);
    glEnable(GL_DEPTH_TEST);
   glEnable(GL_CULL_FACE);

    // Inicializar DevIL
    ilInit(); // Inicializamos la librería y sus recursos
    ilEnable(IL_ORIGIN_SET); // Le decimos que queremos cambiar
    // el punto de origen
    ilOriginFunc(IL_ORIGIN_LOWER_LEFT); // Cambiarlo y configurarlo
    // como abajo a la izquerda. Hace match con las
    // coordenadas de textura.

    Initialize();

    // Iniciar la aplicación. El main se pausará en esta
    // línea hasta que se cierre la ventana de OpenGL.
    glutMainLoop();

    // Terminar.
    return 0;
}