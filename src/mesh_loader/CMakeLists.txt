add_library(mesh_loader_library SHARED
    camera.h camera.cpp
    shader.h shader.cpp
    filesystem.h filesystem.cpp
    mesh.h mesh.cpp
    model.h model.cpp
    stb_image.h stb_image.cpp
)

target_link_libraries(mesh_loader_library
    ${OPENGL_gl_LIBRARY} 
    ${GLFW3_LIBRARY} 
    ${ASSIMP_LIBRARIES} 
    ${CMAKE_DL_LIBS}
)
