#include<iostream>
#include"Map.h"
//#include<vector>
using namespace std;
int main(void) {
	//vector<int> vec;
	//vec.push_back(1);
	//vec.push_back(2);
	//vec.push_back(3);
	//vec.push_back(4);
	//vec.push_back(5);
	//vector<int>::iterator it;
	//for (it  = vec.begin(); it !=vec.end(); it++)
	//{
	//	*it = 5;
	//	cout << *it;
	//}
	//return 0;.
	Map *pMap = new Map(8);
	Node *pNodeA = new Node('A');
	Node *pNodeB = new Node('B');
	Node *pNodeC = new Node('C');
	Node *pNodeD = new Node('D');
	Node *pNodeE = new Node('E');
	Node *pNodeF = new Node('F');
	Node *pNodeG = new Node('G');
	Node *pNodeH = new Node('H');

	pMap->addNode(pNodeA);
	pMap->addNode(pNodeB);
	pMap->addNode(pNodeC);
	pMap->addNode(pNodeD);
	pMap->addNode(pNodeE);
	pMap->addNode(pNodeF);
	pMap->addNode(pNodeG);
	pMap->addNode(pNodeH);

	pMap->setValueToMatrixForUndirectedGraph(0, 1);
	pMap->setValueToMatrixForUndirectedGraph(0, 3);
	pMap->setValueToMatrixForUndirectedGraph(1, 2);
	pMap->setValueToMatrixForUndirectedGraph(1, 5);
	pMap->setValueToMatrixForUndirectedGraph(3, 6);
	pMap->setValueToMatrixForUndirectedGraph(3, 7);
	pMap->setValueToMatrixForUndirectedGraph(6, 7);
	pMap->setValueToMatrixForUndirectedGraph(2, 4);
	pMap->setValueToMatrixForUndirectedGraph(4, 5);

	pMap->printMatrix();
	cout << endl;

	pMap->resetNode();
	pMap->depthFirstTraverse(0);

	pMap->resetNode();
	pMap->breadthFirstTraverse(0);
	system("pause");
}