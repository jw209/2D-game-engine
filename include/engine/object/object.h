/*
  Object class

  Objects are a 2D set of vertices for containing sprites. Objects are the base
  on which we attach other functionality such as physics, collision, and input.
*/
#ifndef OBJECT_H
#define OBJECT_H

#include <iostream>
#include <string>

class Object {
  private:
    int num_vertices;
    int num_coords;
    std::string name;    
    float *shape_vertices;
    float *init_coords;
  public:
    // constructor
    // parameters: object name, array of vertices of shape, initial spawn coordinates in world space
    Object(std::string in_name, float *in_shape_vertices, float *in_init_coords, 
           int in_num_vertices, int in_num_coords)
    {
      // set sizes
      num_vertices = in_num_vertices;
      num_coords = in_num_coords;
      // create new arrays for storing vertices and coordinates
      shape_vertices = new float[in_num_vertices];
      init_coords = new float[in_num_coords];

      // initialize object name
      this->name = in_name;
      
      // set vertice and coordinate arrays
      for (int i = 0; i < in_num_vertices; i++) 
      {
        shape_vertices[i] = in_shape_vertices[i];
      }
      for (int i = 0; i < in_num_coords; i++)
      {
        init_coords[i] = in_init_coords[i];
      }
    }

    // print current vertices
    void printVertices()
    {
      for (int i = 0; i < num_vertices; i++)
      {
        std::cout << shape_vertices[i] << "  ";
        if ((i+1)%3 == 0)
          std::cout << "\n";
      }
    }

    float *getVertices()
    {
      return shape_vertices;
    }
};

#endif // OBJECT_H
