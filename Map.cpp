#include "Map.h"


Map::Map(int capacity)
{
	m_iCapacity = capacity;
	m_iNodeCount = 0;
	m_pNodeArray = new Node[m_iCapacity];
	m_pMatrix = new int[m_iCapacity*m_iCapacity];
	memset(m_pMatrix, 0, m_iCapacity*m_iCapacity*sizeof(int));
}

Map::~Map()
{
	delete[] m_pNodeArray;
	delete[] m_pMatrix;
}

bool Map::addNode(Node* pNode)
{
	m_pNodeArray[m_iNodeCount++].m_cDate = pNode->m_cDate;
	return true;
}

void Map::resetNode()
{
	for (int i= 0; i < m_iNodeCount; i++)
	{
		m_pNodeArray[i].m_bIsVisited = false;
	}
}

bool Map::setValueToMatrixForDirectedGraph(int row, int col, int val)
{
	m_pMatrix[row*m_iCapacity + col] = val;
	return true;
}

bool Map::setValueToMatrixForUndirectedGraph(int row, int col, int val)
{
	m_pMatrix[row*m_iCapacity + col] = val;
	m_pMatrix[col*m_iCapacity + row] = val;
	return true;
}

bool Map::getValueFromMatrix(int row, int col, int &val)
{
	val = m_pMatrix[row*m_iCapacity + col];
	return true;
}

void Map::printMatrix()
{
	for (int i = 0; i < m_iCapacity; i++)
	{
		for (int k = 0; k < m_iCapacity; k++)
		{
			cout << m_pMatrix[i*m_iCapacity + k] << " ";
		}
		cout << endl;
	}
}

//深度优先搜索
void Map::depthFirstTraverse(int nodeIndex)
{
	int value = 0;
	cout << m_pNodeArray[nodeIndex].m_cDate << " ";
	m_pNodeArray[nodeIndex].m_bIsVisited = true;

	//通过邻接矩阵判断是否与其他的顶点有连接
	for (size_t i = 0; i < m_iCapacity; i++)
	{
		getValueFromMatrix(nodeIndex, i, value);
		if (value!=0)//判断有弧连接其他顶点
		{
			//再判断该店是否被访问过
			if (m_pNodeArray[i].m_bIsVisited)
			{
				continue;
			}
			else
			{
				depthFirstTraverse(i);
			}
		}
		else//如果没有去向索引为i的顶点的弧，则循环继续
		{
			continue;
		}
	}
}