//
// Created by paul_s on 19.05.2020.
//

#include "MatrixGraph.hpp"

MatrixGraph::MatrixGraph(int count) {
  assert(count >= 0);
  _adjacencyMatrix.reserve(count);
  _adjacencyMatrix.resize(count);

  for (auto &row : _adjacencyMatrix) {
    row.reserve(count);
    row.resize(count, 0);
  }
}


MatrixGraph::MatrixGraph(const IGraph &graph) :
    MatrixGraph(graph.VerticesCount()) {
  for (size_t i = 0; i < graph.VerticesCount(); i++) {
    auto nextVertices = graph.GetNextVertices(i);
    for (auto vertex : nextVertices) {
      _adjacencyMatrix[i][vertex]++;
    }
  }
}



void MatrixGraph::AddEdge(int from, int to) {
  assert(from >= 0 && from < VerticesCount());
  assert(to >= 0 && to < VerticesCount());

  _adjacencyMatrix[from][to]++;
}



int MatrixGraph::VerticesCount() const {
  return _adjacencyMatrix.size();
}



std::vector<int> MatrixGraph::GetNextVertices(int vertex) const {
  assert(vertex >= 0 && vertex < VerticesCount());

  std::vector<int> result;
  for (int j = 0; j < VerticesCount(); j++) {
    int count = _adjacencyMatrix[vertex][j];

    if (count != 0) {
      for (int k = 0; k < count; k++) {
        result.push_back(j);
      }
    }
  }

  return result;
}


std::vector<int> MatrixGraph::GetPrevVertices(int vertex) const {
  assert(vertex >= 0 && vertex < VerticesCount());

  std::vector<int> result;
  for (int i = 0; i < VerticesCount(); i++) {
    int count = _adjacencyMatrix[i][vertex];

    if (count != 0) {
      for (int k = 0; k < count; k++) {
        result.push_back(i);
      }
    }
  }

  return result;
}

