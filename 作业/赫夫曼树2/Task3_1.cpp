//�շ�����

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
	 * �������������
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
	 * �������������
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
		 * s1==s2,˵��0��С
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
			 * Ѱ����С��Ȩ�ز�Ϊ����±꣬������λ�õ�ָ������½ڵ�htnode[s1]�У�����htnode[s2]����weight��Ϊ0
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
	printf("������Ҫ�������ĸ�ĸ���:\n");
	scanf("%d",n);
	for(i=0;i<=n;i++){
	printf("������Ȩ��:\n");
	scanf("%d",&w[i]);
	}
	HTNode *ht = new HTNode(w, n);
	cout<<"�������"<<endl;
	ht->inorderTraversal();
	cout << endl;
	cout<<"�������"<<endl;
	ht->PreorderTraversalAlgorithm();
}

