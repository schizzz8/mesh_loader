#include "model.h"

using namespace std;

unsigned int TextureFromFile(const char *path, const std::string &directory, bool gamma) {
    std::string filename = std::string(path);
    filename = directory + '/' + filename;

    unsigned int textureID;
    glGenTextures(1, &textureID);

    int width, height, nrComponents;
    unsigned char *data = stbi_load(filename.c_str(), &width, &height, &nrComponents, 0);
    if (data) {
        GLenum format;
        if (nrComponents == 1)
            format = GL_RED;
        else if (nrComponents == 3)
            format = GL_RGB;
        else if (nrComponents == 4)
            format = GL_RGBA;

        glBindTexture(GL_TEXTURE_2D, textureID);
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        stbi_image_free(data);
    }
    else {
        std::cout << "Texture failed to load at path: " << path << std::endl;
        stbi_image_free(data);
    }

    return textureID;
}

vector<string> names;

constexpr unsigned int str2int(const char* str, int h = 0) {
    return !str[h] ? 5381 : (str2int(str, h+1) * 33) ^ str[h];
}

Material materialFromString(const char* name){
    Material mat;
    string label(name);
    label = label.substr(0,label.find_first_of("_"));

    vector<string>::iterator it;

    it = find (names.begin(),names.end(),label);
    if(it == names.end()){
        cerr << label << endl;
        names.push_back(label);
    }
    switch (str2int(label.c_str())) {
    case str2int("clutter"):
        mat.ambient = glm::vec3 (0.2f, 1.0f, 1.0f);
        mat.diffuse = glm::vec3 (0.1f, 0.1f, 0.1f);
        mat.specular = glm::vec3 (0.1f, 0.1f, 0.1f);
        mat.shininess = 32.0f;
        break;
    case str2int("chair"):
        mat.ambient = glm::vec3 (0.4f, 1.0f, 1.0f);
        mat.diffuse = glm::vec3 (0.1f, 0.1f, 0.1f);
        mat.specular = glm::vec3 (0.1f, 0.1f, 0.1f);
        mat.shininess = 32.0f;
        break;
    case str2int("wall"):
        mat.ambient = glm::vec3 (0.6f, 1.0f, 1.0f);
        mat.diffuse = glm::vec3 (0.1f, 0.1f, 0.1f);
        mat.specular = glm::vec3 (0.1f, 0.1f, 0.1f);
        mat.shininess = 32.0f;
        break;
    case str2int("bookcase"):
        mat.ambient = glm::vec3 (0.8f, 1.0f, 1.0f);
        mat.diffuse = glm::vec3 (0.1f, 0.1f, 0.1f);
        mat.specular = glm::vec3 (0.1f, 0.1f, 0.1f);
        mat.shininess = 32.0f;
        break;
    case str2int("table"):
        mat.ambient = glm::vec3 (1.0f, 0.2f, 1.0f);
        mat.diffuse = glm::vec3 (0.1f, 0.1f, 0.1f);
        mat.specular = glm::vec3 (0.1f, 0.1f, 0.1f);
        mat.shininess = 32.0f;
        break;
    case str2int("board"):
        mat.ambient = glm::vec3 (1.0f, 0.4f, 1.0f);
        mat.diffuse = glm::vec3 (0.1f, 0.1f, 0.1f);
        mat.specular = glm::vec3 (0.1f, 0.1f, 0.1f);
        mat.shininess = 32.0f;
        break;
    case str2int("floor"):
        mat.ambient = glm::vec3 (1.0f, 0.6f, 1.0f);
        mat.diffuse = glm::vec3 (0.1f, 0.1f, 0.1f);
        mat.specular = glm::vec3 (0.1f, 0.1f, 0.1f);
        mat.shininess = 32.0f;
        break;
    case str2int("beam"):
        mat.ambient = glm::vec3 (1.0f, 0.8f, 1.0f);
        mat.diffuse = glm::vec3 (0.1f, 0.1f, 0.1f);
        mat.specular = glm::vec3 (0.1f, 0.1f, 0.1f);
        mat.shininess = 32.0f;
        break;
    case str2int("ceiling"):
        mat.ambient = glm::vec3 (1.0f, 1.0f, 0.2f);
        mat.diffuse = glm::vec3 (0.1f, 0.1f, 0.1f);
        mat.specular = glm::vec3 (0.1f, 0.1f, 0.1f);
        mat.shininess = 32.0f;
        break;
    case str2int("window"):
        mat.ambient = glm::vec3 (1.0f, 1.0f, 0.4f);
        mat.diffuse = glm::vec3 (0.1f, 0.1f, 0.1f);
        mat.specular = glm::vec3 (0.1f, 0.1f, 0.1f);
        mat.shininess = 32.0f;
        break;
    case str2int("door"):
        mat.ambient = glm::vec3 (1.0f, 1.0f, 0.6f);
        mat.diffuse = glm::vec3 (0.1f, 0.1f, 0.1f);
        mat.specular = glm::vec3 (0.1f, 0.1f, 0.1f);
        mat.shininess = 32.0f;
        break;
    case str2int("sofa"):
        mat.ambient = glm::vec3 (1.0f, 1.0f, 0.8f);
        mat.diffuse = glm::vec3 (0.1f, 0.1f, 0.1f);
        mat.specular = glm::vec3 (0.1f, 0.1f, 0.1f);
        mat.shininess = 32.0f;
        break;
    case str2int("column"):
        mat.ambient = glm::vec3 (1.0f, 1.0f, 1.0f);
        mat.diffuse = glm::vec3 (0.1f, 0.1f, 0.1f);
        mat.specular = glm::vec3 (0.1f, 0.1f, 0.1f);
        mat.shininess = 32.0f;
        break;
    default:
        mat.ambient = glm::vec3 (1.0f, 1.0f, 1.0f);
        mat.diffuse = glm::vec3 (0.1f, 0.1f, 0.1f);
        mat.specular = glm::vec3 (0.1f, 0.1f, 0.1f);
        mat.shininess = 32.0f;
        break;
    }

    return mat;
}

void Model::draw(Shader shader){
    for(unsigned int i=0; i < _meshes.size(); ++i)
        _meshes[i].draw(shader);
}

void Model::loadModel(string path){
    Assimp::Importer importer;

    const aiScene* scene = importer.ReadFile(path, aiProcess_Triangulate | aiProcess_FlipUVs);
    if(!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) {
        cout << "ERROR::ASSIMP::" << importer.GetErrorString() << endl;
        return;
    }

    _directory = path.substr(0, path.find_last_of('/'));



    processNode(scene->mRootNode, scene);

}

void Model::processNode(aiNode *node, const aiScene *scene){

    for(unsigned int i = 0; i < node->mNumMeshes; i++) {
        aiMesh *mesh = scene->mMeshes[node->mMeshes[i]];
        _meshes.push_back(processMesh(mesh, scene));
    }

    for(unsigned int i = 0; i < node->mNumChildren; i++)
        processNode(node->mChildren[i], scene);
}

Mesh Model::processMesh(aiMesh *mesh, const aiScene *scene){
    vector<Vertex> vertices;
    vector<unsigned int> indices;
    vector<Texture> textures;
    vector<Material> materials;

    for(unsigned int i = 0; i < mesh->mNumVertices; i++){

        Vertex vertex;

        // process vertex positions, normals and texture coordinates
        vertex.Position = glm::vec3 (mesh->mVertices[i].x,
                                     mesh->mVertices[i].y,
                                     mesh->mVertices[i].z);

        vertex.Normal = glm::vec3 (mesh->mNormals[i].x,
                                   mesh->mNormals[i].y,
                                   mesh->mNormals[i].z);

        if(mesh->mTextureCoords[0]){
            vertex.TexCoords = glm::vec2 (mesh->mTextureCoords[0][i].x,
                    mesh->mTextureCoords[0][i].y);
        } else
            vertex.TexCoords = glm::vec2 (0.0f, 0.0f);

        vertices.push_back(vertex);
    }

    // process indices
    for(unsigned int i=0; i < mesh->mNumFaces; i++){
        aiFace face = mesh->mFaces[i];

        for(unsigned int j=0; j < face.mNumIndices; j++)
            indices.push_back(face.mIndices[j]);
    }

    // process material
    if(mesh->mMaterialIndex >= 0){
        aiMaterial *material = scene->mMaterials[mesh->mMaterialIndex];
        aiString name;
        material->Get(AI_MATKEY_NAME, name);
        materials.push_back(materialFromString(name.C_Str()));

        //        cerr << name.C_Str() << ": ";
//        aiColor3D color;
//        material->Get(AI_MATKEY_COLOR_AMBIENT, color);
//        cerr << color.r << " " << color.g << " " << color.b << endl;

        vector<Texture> diffuseMaps = loadMaterialTextures(material, aiTextureType_DIFFUSE, "texture_diffuse");
        textures.insert(textures.end(), diffuseMaps.begin(), diffuseMaps.end());

        vector<Texture> specularMaps = loadMaterialTextures(material, aiTextureType_SPECULAR, "texture_specular");
        textures.insert(textures.end(), specularMaps.begin(), specularMaps.end());
    }

    return Mesh(vertices, indices, textures, materials);
}

vector<Texture> Model::loadMaterialTextures(aiMaterial *mat, aiTextureType type, string typeName){
    vector<Texture> textures;
    for(unsigned int i = 0; i < mat->GetTextureCount(type); i++){
        aiString str;
        mat->GetTexture(type, i, &str);
        Texture texture;
        texture.id = TextureFromFile(str.C_Str(), _directory);
        texture.type = typeName;
        texture.path = str;
        textures.push_back(texture);
    }
    return textures;
}
