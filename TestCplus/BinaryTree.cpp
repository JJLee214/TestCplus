#include "BinaryTree.h"
/* 노드 생성 */
BinaryTree* BT_CreateNode(char Data) {

	BinaryTree* NewNode = (BinaryTree*)malloc(sizeof(BinaryTree));
	NewNode->Left = NULL;
	NewNode->Right = NULL;
	NewNode->Data = Data;

	return NewNode;
}

/* 후위 표기식 출력 */
void BT_PostoderPrintTree(BinaryTree* Node) {

	if (Node == NULL)
		return;

	//왼쪽 노드 출력
	BT_PostoderPrintTree(Node->Left);

	//오른쪽 노드 출력
	BT_PostoderPrintTree(Node->Right);

	//루트 노드 출력
	printf(" %c", Node->Data);

}

/* 중위 표기식 출력 */
void BT_InoderPrintTree(BinaryTree* Node) {

	if (Node == NULL)
		return;

	//왼쪽 노드 출력
	BT_InoderPrintTree(Node->Left);

	//루트 노드 출력
	printf(" %c", Node->Data);

	//오른쪽 노드 출력
	BT_InoderPrintTree(Node->Right);

}

/* 전위 표기식 출력 */
void BT_PreorderPrintTree(BinaryTree* Node) {

	if (Node == NULL)
		return;

	//루트 출력
	printf(" %c", Node->Data);

	//왼쪽 노드 출력
	BT_PreorderPrintTree(Node->Left);

	//오른쪽 노드 출력
	BT_PreorderPrintTree(Node->Right);

}

void BT_DestroyTree(BinaryTree* Root) {

	if (Root == NULL)
		return;

	//왼쪽 소멸
	BT_DestroyTree(Root->Left);

	//오른쪽 소멸
	BT_DestroyTree(Root->Right);

	//루트 소멸
	BT_DestroyNode(Root);

}

/* 노드 소멸 */
void BT_DestroyNode(BinaryTree* Node) {
	free(Node);
}