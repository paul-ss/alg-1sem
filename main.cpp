/* Дан базовый интерфейс для представления ориентированного графа:
 * struct IGraph {
 *  virtual ~IGraph() {}
 *
 *  // Добавление ребра от from к to.
 *  virtual void AddEdge(int from, int to) = 0;
 *
 *  virtual int VerticesCount() const  = 0;
 *  virtual std::vector<int> GetNextVertices(int vertex) const = 0;
 *  virtual std::vector<int> GetPrevVertices(int vertex) const = 0
 * };
 *
 * Необходимо написать несколько реализаций интерфейса:
 *  ListGraph, хранящий граф в виде массива списков смежности,
 *  MatrixGraph, хранящий граф в виде матрицы смежности,
 *  SetGraph, хранящий граф в виде массива хэш-таблиц/сбалансированных деревьев поиска,
 *  ArcGraph, хранящий граф в виде одного массива пар {from, to}.
 * Также необходимо реализовать конструктор, принимающий const IGraph&.
 * Такой конструктор должен скопировать переданный граф в создаваемый объект.
 * Для каждого класса создавайте отдельные h и cpp файлы.
 * Число вершин графа задается в конструкторе каждой реализации. */




#include <iostream>
#include <cassert>
#include <memory>
#include <set>

#include "IGraph.hpp"
#include "ListGraph.hpp"
#include "MatrixGraph.hpp"
#include "SetGraph.hpp"
#include "ArcGraph.hpp"

#define GRAPH_SIZE 1000




struct TestVertex {
  std::vector<int> next;
  std::vector<int> prev;
};


void vectorEq(const std::vector<int> &left, const std::vector<int> &right) {
  assert(left.size() == right.size());

  std::multiset<int> leftSet;
  std::multiset<int> rightSet;
  for (size_t i = 0; i < left.size(); i++) {
    rightSet.insert(right[i]);
    leftSet.insert(left[i]);
  }

  assert(leftSet == rightSet);
}


void testAdd(IGraph &graph) {
  std::vector<TestVertex> vertexes(GRAPH_SIZE);

  for (int i = 0; i < GRAPH_SIZE; i++) {
    int from = rand() % GRAPH_SIZE;
    int to = rand() % GRAPH_SIZE;
    graph.AddEdge(from, to);
    vertexes[from].next.push_back(to);
    vertexes[to].prev.push_back(from);
  }

  for (int i = 0; i < GRAPH_SIZE; i++) {
    vectorEq(graph.GetPrevVertices(i), vertexes[i].prev);
    vectorEq(graph.GetNextVertices(i), vertexes[i].next);
  }

  std::cout << "OK" << std::endl;
}


template <typename GraphType>
void testCopy(IGraph &graph) {
  std::vector<TestVertex> vertexes(GRAPH_SIZE);

  for (int i = 0; i < GRAPH_SIZE; i++) {
    int from = rand() % GRAPH_SIZE;
    int to = rand() % GRAPH_SIZE;
    graph.AddEdge(from, to);
    vertexes[from].next.push_back(to);
    vertexes[to].prev.push_back(from);
  }

  auto newGraph = new GraphType(graph);

  for (int i = 0; i < GRAPH_SIZE; i++) {
    vectorEq(newGraph->GetPrevVertices(i), vertexes[i].prev);
    vectorEq(newGraph->GetNextVertices(i), vertexes[i].next);
  }

  delete newGraph;
  std::cout << "OK" << std::endl;
}



void runTest() {
  // ArcGraph tests ----------
  std::cout << "ArcGraph tests ..." << std::endl;
  {
    auto graphPtr = new ArcGraph(GRAPH_SIZE);
    testAdd(*graphPtr);
    delete graphPtr;
  }

  {
    auto graphPtr = new ArcGraph(GRAPH_SIZE);
    testCopy<ArcGraph>(*graphPtr);
    delete graphPtr;
  }

  // ListGraph tests ----------
  std::cout << "ListGraph tests ..." << std::endl;
  {
    auto graphPtr = new ListGraph(GRAPH_SIZE);
    testAdd(*graphPtr);
    delete graphPtr;
  }

  {
    auto graphPtr = new ListGraph(GRAPH_SIZE);
    testCopy<ListGraph>(*graphPtr);
    delete graphPtr;
  }

  // MatrixGraph tests ----------
  std::cout << "MatrixGraph tests ..." << std::endl;
  {
    auto graphPtr = new MatrixGraph(GRAPH_SIZE);
    testAdd(*graphPtr);
    delete graphPtr;
  }

  {
    auto graphPtr = new MatrixGraph(GRAPH_SIZE);
    testCopy<MatrixGraph>(*graphPtr);
    delete graphPtr;
  }

  // SetGraph tests ----------
  std::cout << "SetGraph tests ..." << std::endl;
  {
    auto graphPtr = new SetGraph(GRAPH_SIZE);
    testAdd(*graphPtr);
    delete graphPtr;
  }

  {
    auto graphPtr = new SetGraph(GRAPH_SIZE);
    testCopy<SetGraph>(*graphPtr);
    delete graphPtr;
  }
}




int main() {
  runTest();
  return 0;
}
