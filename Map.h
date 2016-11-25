#pragma once
#ifndef MAP_H
#define MAP_H
#include "Node.h"
#include<vector>
#include<iostream>
using namespace std;
class Map
{
public:
	Map(int capacity);
	~Map();
	bool addNode(Node* pNode);//��ͼ���붥�㣨��㣩
	void resetNode();//���ö���
	bool setValueToMatrixForDirectedGraph(int row, int col, int val = 1);//Ϊ����ͼ�����ڽӾ���
	bool setValueToMatrixForUndirectedGraph(int row, int col, int val = 1);//Ϊ����ͼ�����ڽӾ���

	void printMatrix();// ��ӡ�ڽӾ���

	void depthFirstTraverse(int nodeIndex);//������ȱ���
	void breadthFirstTraverse(int nodeIndex);//������ȱ���

private:
	bool getValueFromMatrix(int row, int col, int &val);//�Ӿ����л�ȡֵ
	void breadthFirstTraverseImpl(vector<int> preVec);//������ȱ���ʵ�ֺ���

private:
	int m_iCapacity;//ͼ�����������ɵĶ�����
	int m_iNodeCount;//�Ѿ���ӵĶ��㣨��㣩����
	Node* m_pNodeArray;//������Ŷ�������
	int* m_pMatrix;//��������ڽӾ���
};

#endif // !MAP_H