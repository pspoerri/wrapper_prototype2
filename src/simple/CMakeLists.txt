set(SRC
    main.c
    Simple.cpp)

add_executable(simple ${SRC})
target_link_libraries(simple wrapper)
