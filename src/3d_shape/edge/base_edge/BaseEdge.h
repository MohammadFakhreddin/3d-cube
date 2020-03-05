#ifndef BaseEdge_class
#define BaseEdge_class

#include "../../../data_types/MatrixTemplate.h"
#include <vector>
#include "../../../data_types/VectorTemplate.h"


enum EdgeType{
  color,
  simple,
  texture,
  base
};

class BaseEdge
{
public:
  virtual void render(std::vector<MatrixFloat>* worldPoints);
  virtual EdgeType getEdgeType();
  int getEdgeByIndex(int index);
  bool areEdgesDataValid(int nodesSize);
protected:
  int edge1;
  int edge2;
  int edge3;
};

#endif