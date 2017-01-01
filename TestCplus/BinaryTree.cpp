#include "BinaryTree.h"
/* ��� ���� */
BinaryTree* BT_CreateNode(char Data) {

	BinaryTree* NewNode = (BinaryTree*)malloc(sizeof(BinaryTree));
	NewNode->Left = NULL;
	NewNode->Right = NULL;
	NewNode->Data = Data;

	return NewNode;
}

/* ���� ǥ��� ��� */
void BT_PostoderPrintTree(BinaryTree* Node) {

	if (Node == NULL)
		return;

	//���� ��� ���
	BT_PostoderPrintTree(Node->Left);

	//������ ��� ���
	BT_PostoderPrintTree(Node->Right);

	//��Ʈ ��� ���
	printf(" %c", Node->Data);

}

/* ���� ǥ��� ��� */
void BT_InoderPrintTree(BinaryTree* Node) {

	if (Node == NULL)
		return;

	//���� ��� ���
	BT_InoderPrintTree(Node->Left);

	//��Ʈ ��� ���
	printf(" %c", Node->Data);

	//������ ��� ���
	BT_InoderPrintTree(Node->Right);

}

/* ���� ǥ��� ��� */
void BT_PreorderPrintTree(BinaryTree* Node) {

	if (Node == NULL)
		return;

	//��Ʈ ���
	printf(" %c", Node->Data);

	//���� ��� ���
	BT_PreorderPrintTree(Node->Left);

	//������ ��� ���
	BT_PreorderPrintTree(Node->Right);

}

void BT_DestroyTree(BinaryTree* Root) {

	if (Root == NULL)
		return;

	//���� �Ҹ�
	BT_DestroyTree(Root->Left);

	//������ �Ҹ�
	BT_DestroyTree(Root->Right);

	//��Ʈ �Ҹ�
	BT_DestroyNode(Root);

}

/* ��� �Ҹ� */
void BT_DestroyNode(BinaryTree* Node) {
	free(Node);
}