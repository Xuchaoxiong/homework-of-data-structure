//赫夫曼树

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <iostream>
using namespace std;
typedef unsigned int uint;
typedef unsigned int uchar;
class HTNode {
private:
public:
	uint weight;
	HTNode * parent;
	HTNode * lchild;
	HTNode * rchild;
	HTNode() {
		weight = 0;
		parent = NULL;
		lchild = NULL;
		rchild = NULL;
	}
	HTNode(uint w, HTNode *p, HTNode *l, HTNode *r) {
		weight = w;
		parent = p;
		lchild = l;
		rchild = r;
	}
	/*
	 * 先序遍历二叉树
	 */
	int PreorderTraversalAlgorithm() {
		if (weight > 0) {
			cout << weight << " ";
		}
		if (lchild) {
			lchild->PreorderTraversalAlgorithm();
		}
		if (rchild) {
			rchild->PreorderTraversalAlgorithm();
		}
		return 0;
	}
	/*
	 * 中序遍历二叉树
	 */
	int inorderTraversal() {

		if (lchild) {
			lchild->inorderTraversal();
		}
		if (weight > 0) {
			cout << weight << " ";
		}
		if (rchild) {
			rchild->inorderTraversal();
		}
		return 0;
	}
	void Select(HTNode **w, int n, int&s1, int &s2) {
		s1 = 0;
		uint current = w[0]->weight;
		for (int i = 1; i < n; i++) {
			if ((w[i]->weight > 0) & (w[i]->weight <= current)) {
				s1 = i;
				current = w[i]->weight;
			}
		}
		/*
		 * s1==s2,说明0最小
		 */
		s2 = 0;
		current = 0xfffffff;
		for (i = 0; i < n; i++) {
			if ((i != s1) & (w[i]->weight > 0) & (w[i]->weight <= current)) {
				s2 = i;
				current = w[i]->weight;
			}
		}
	}
	HTNode(uint *w, int n) {
		weight = 0;
		parent = NULL;
		lchild = NULL;
		rchild = NULL;
		int i;
		if (n < 0) {
			throw new exception();
		}

		HTNode **htnode = new HTNode*[n];
		for (i = 0; i < n; i++) {
			htnode[i] = new HTNode(*(w + i), NULL, NULL, NULL);
		}
		int s1, s2;
		for (i = 0; i < n; i++) {
			/*
			 * 寻找最小且权重不为零的下标，将两个位置的指针存入新节点htnode[s1]中，并将htnode[s2]处的weight设为0
			 */

			Select(htnode, n, s1, s2);
#ifdef DEBUG
			cout << s1 << "  " << s2 << endl;
#endif
			htnode[s1] = new HTNode(htnode[s1]->weight + htnode[s2]->weight,
			NULL, htnode[s1], htnode[s2]);
			htnode[s2] = new HTNode(0, NULL, NULL, NULL);
		}
		*this = *htnode[s1];
#ifdef DEBUG
		cout<<s1;
#endif
	}
};
typedef HTNode* HuffmanTree;


int main(int argc, char* argv[]) {
	int n,i;
	uint w[100];
	printf("请输入要编码的字母的个数:\n");
	scanf("%d",n);
	for(i=0;i<=n;i++){
	printf("请输入权重:\n");
	scanf("%d",&w[i]);
	}
	HTNode *ht = new HTNode(w, n);
	cout<<"中序遍历"<<endl;
	ht->inorderTraversal();
	cout << endl;
	cout<<"先序遍历"<<endl;
	ht->PreorderTraversalAlgorithm();
}

