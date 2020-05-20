//
// Created by paul_s on 19.05.2020.
//

#pragma once

#include "IGraph.hpp"

#include <list>
#include <cassert>

class ListGraph : public IGraph {
public:
  ListGraph(int count);
  ListGraph(const IGraph &graph);

  virtual void AddEdge(int from, int to);
  virtual int VerticesCount() const;
  virtual std::vector<int> GetNextVertices(int vertex) const;
  virtual std::vector<int> GetPrevVertices(int vertex) const;

private:
  std::vector<std::list<int>>  _adjacencyLists;
};

