#pragma once
#ifndef NODE_H
#define NODE_H


class Node
{
public:
	Node(char date=0);
	~Node();
	char m_cDate;
	bool m_bIsVisited;
};

#endif // !NODE_H