#ifndef OBJECT_H
#define OBJECT_H

#include <iostream>
#include <initializer_list>
#include <string>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>

class Object 
{
  private:
    std::string name;
    float *vertices;
    int numVertices;
    int iterator;
  public:
    // constructor
    // params: object name, vertices composing the shape, current iteration of object creation
    Object(const std::string name, std::initializer_list<float> list, int numVertices, int iterator)
    {
      this->name = name;
      this->numVertices = numVertices;
      this->iterator = iterator;

      // initialize vertices
      int index = 0;
      this->vertices = new float[this->numVertices];
      for (auto element : list) {
        this->vertices[index] = element;
        index++;
      }  
    }

    void printVertices()
    {
      for (int i = 0; i < this->numVertices; i++)
      {
        std::cout << this->vertices[i] << "\n";
      }
    }

    const void* getVertices()
    {
      return (const void *)this->vertices;
    }

    size_t getNumVertices()
    {
      return sizeof(float)*this->numVertices;
    }

};

#endif // OBJECT_H