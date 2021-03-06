#include "stdafx.h"
#include <windows.h>
#include <iostream>
#include <stdlib.h>

struct Node {
	int val;
	struct Node *parent;
	struct Node *left;
	struct Node *right;
};

struct Node *root;

struct Node* findElement(struct Node *node, int x) {
	if (root == NULL)
		return NULL;

	if (node->val == x)
		return node;
	else if (x < node->val && node->left != NULL)
		return findElement(node->left, x);
	else if (x > node->val && node->right != NULL)
		return findElement(node->right, x);
	else
		return NULL;
}

void add(struct Node *node, int x) {
	if (root == NULL)
	{
		root = (struct Node*)malloc(sizeof(struct Node));
		root->val = x;
		root->left = NULL;
		root->right = NULL;
		root->parent = NULL;
	}
	else if (x > node->val) {
		if (node->right != NULL)
			add(node->right, x);
		else {
			struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
			newNode->val = x;
			newNode->parent = node;
			newNode->left = NULL;
			newNode->right = NULL;
			node->right = newNode;
		}
	}
	else if (x < node->val) {
		if (node->left != NULL)
			add(node->left, x);
		else {
			struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
			newNode->val = x;
			newNode->parent = node;
			newNode->left = NULL;
			newNode->right = NULL;
			node->left = newNode;
		}
	}

}

struct Node* minLeft(struct Node *node) {
	if (node->left != NULL)
		return minLeft(node->left);
	return node;
}

void remove(struct Node *removed) {
	if (removed == NULL) {
		printf("No item in the tree");
		return;
	}
	if (removed->left == NULL && removed->parent == NULL) {
		if (removed->parent == NULL)
			root = NULL;
		else if (removed->parent->left == removed)
			removed->parent->left = NULL;
		else
			removed->parent->right = NULL;
		delete removed;
	}
	else if (removed->left == NULL && removed->right == NULL) {
		if (removed->left = NULL) {
			if (removed->parent == NULL)
				root = removed->right;
			else if (removed->parent->left == removed)
				removed->parent->left = removed->right;
			else
				removed->parent->right = removed->right;
		}
		else {
			if (removed->parent == NULL)
				root = removed->left;
			else if (removed->parent->left == removed)
				removed->parent->left = removed->left;
			else
				removed->parent->right = removed->left;
		}
		free(removed);
	}
	else {
		struct Node *temp;
		temp = minLeft(removed->right);
		removed->val = temp->val;
		remove(temp);
	}
}

void inorder(struct Node* node)
{
	if (node == NULL)
		return;
	inorder(node->left);
	printf("%d ", node->val);
	inorder(node->right);
}
