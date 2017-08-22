add_executable(mesh_loader_app
    mesh_loader_app.cpp glad.c
)

target_link_libraries(mesh_loader_app 
    mesh_loader_library
)

