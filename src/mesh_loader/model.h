#pragma once

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "shader.h"
#include "mesh.h"
#include "stb_image.h"

#include <vector>
#include <string>

unsigned int TextureFromFile(const char *path, const std::string &directory, bool gamma = false);

class Model{
public:
    Model(std::string const &path, bool gamma = false){
        loadModel(path);
    }
    void draw(Shader shader);
private:
    std::vector<Mesh> _meshes;
    std::string _directory;

    void loadModel(std::string path);
    void processNode(aiNode* node, const aiScene* scene);
    Mesh processMesh(aiMesh* mesh, const aiScene* scene);
    std::vector<Texture> loadMaterialTextures(aiMaterial* mat, aiTextureType type, std::string typeName);
};

