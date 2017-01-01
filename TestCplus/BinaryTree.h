#pragma once

#include <stdlib.h>
#include <iostream>

typedef struct tagNode {

	struct tagNode* Left;  //왼쪽
	struct tagNode* Right;  //오른쪽
	char Data;     //데이터

}BinaryTree;

BinaryTree* BT_CreateNode(char Data);   /* 노드 생성 */
void BT_InoderPrintTree(BinaryTree* Node);  /* 중위 표기식 출력 */
void BT_PostoderPrintTree(BinaryTree* Node); /* 후위 표기식 출력 */
void BT_PreorderPrintTree(BinaryTree* Node); /* 전위 표기식 출력 */
void BT_DestroyNode(BinaryTree* Node);   /* 노드 소멸 */
void BT_DestroyTree(BinaryTree* Root);   /* 트리 소멸 */
