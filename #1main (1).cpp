#include <iostream>
//include header file
#include "graph.h"
#include <vector>

using namespace main_savitch_15;
using namespace std;
//textbook reference 


//this includes graph.cpp and graph.h
int main()
{
  graph<int> numElements;
  numElements.add_vertex(1);
  numElements.add_vertex(3);
  numElements.add_vertex(4);
  numElements.add_vertex(5);
  numElements.add_vertex(6);
  numElements.add_vertex(7);

  numElements.add_edge(1,3);
  numElements.add_edge(2,5);
  numElements.add_edge(1,6);
  numElements.add_edge(2,6);
  numElements.add_edge(3,6);
  numElements.add_edge(4,5);
  numElements.add_edge(7,2);

  int lengthElements = numElements.longestDistance(0, 5);
  cout << "Longest distance: " << lengthElements << " vertices in the graph" << endl;

  return 0;
}

	
  
