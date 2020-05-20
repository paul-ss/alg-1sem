//
// Created by paul_s on 19.05.2020.
//


#pragma once

#include <vector>

struct IGraph {
  virtual ~IGraph() = default;
  // Добавление ребра от from к to.
  virtual void AddEdge(int from, int to) = 0;

  virtual int VerticesCount() const  = 0;
  virtual std::vector<int> GetNextVertices(int vertex) const = 0;
  virtual std::vector<int> GetPrevVertices(int vertex) const = 0;
};


