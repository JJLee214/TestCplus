#pragma once

#include <stdlib.h>
#include <iostream>

typedef struct tagNode {

	struct tagNode* Left;  //����
	struct tagNode* Right;  //������
	char Data;     //������

}BinaryTree;

BinaryTree* BT_CreateNode(char Data);   /* ��� ���� */
void BT_InoderPrintTree(BinaryTree* Node);  /* ���� ǥ��� ��� */
void BT_PostoderPrintTree(BinaryTree* Node); /* ���� ǥ��� ��� */
void BT_PreorderPrintTree(BinaryTree* Node); /* ���� ǥ��� ��� */
void BT_DestroyNode(BinaryTree* Node);   /* ��� �Ҹ� */
void BT_DestroyTree(BinaryTree* Root);   /* Ʈ�� �Ҹ� */
