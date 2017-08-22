#pragma once

#include "shader.h"

#include <assimp/scene.h>
#include <glm/glm.hpp>

#include <vector>
#include <string>

struct Vertex{
    glm::vec3 Position;
    glm::vec3 Normal;
    glm::vec2 TexCoords;
};

struct Texture {
    unsigned int id;
    std::string type;
    aiString path;
};

class Mesh{
public:
    std::vector<Vertex> _vertices;
    std::vector<unsigned int> _indices;
    std::vector<Texture> _textures;

    Mesh(const std::vector<Vertex>& vertices,
         const std::vector<unsigned int>& indices,
         const std::vector<Texture>& textures);

    void draw(Shader shader);

private:
    unsigned int VBO, VAO, EBO;

    void setupMesh();
};
