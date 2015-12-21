// bst.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>

template <typename item> 
class TreeNode
{
	//friend class Tree<item>;
public:
	TreeNode(const item &);
	item get_data();
public:
	TreeNode* left;
	TreeNode* right;
	TreeNode* parent;
	item data;
};

	template <class item>
	TreeNode<item>::TreeNode(const item &a) {
		data = a;
		left = right = NULL;
	}

	template <class item>
	item TreeNode<item>::get_data()
	{
		return data;
	}





//template <class item> class Tree;

template <class item>
class Tree
{
public:
	Tree();                                                    /* конструктор */
	void insert_node(const item &);                         /* вставляет узел */
	TreeNode<item>* delete_node(TreeNode<item> *);     /* удаляет узел */
	void up_print(TreeNode<item>*);                    /* печатает все ключи в неубывающем порядке */
	TreeNode<item>* find_max(TreeNode<item>*);         /* находит узел с минимальным значением ключа и возвращает указатель на него */
	TreeNode<item>* find_min(TreeNode<item>*);
	TreeNode<item>* find_node(TreeNode<item>*, const item &);
	TreeNode<item>* find_succsessor(const item &);     /* находит элемент с ключем, следующим за данным числом */
	TreeNode<item> *get_root();                            /* возвращает указатель на корень дерева */
private:
	TreeNode<item> *root;                                  /* собственно, сам корень */
};

template<class item>
Tree<item>::Tree()
{
	root = NULL;                      /* в начале дерево пусто */
}

template<class item>
void Tree<item>::insert_node(const item &x)
{
	TreeNode<item> *tmp = new TreeNode<item>(x);  /* создаем новый узел, его мы будем вставлять */
	TreeNode<item> *ptr = nullptr;
	TreeNode<item> *ptr1 = nullptr;

	tmp->parent = tmp->left = tmp->right = NULL;          /* он - лист */
	ptr = root;
	while (ptr != NULL)                     /* идем от корня и ищем подходящее место для нашего нового элемента, оно должно быть свободно */
	{
		ptr1 = ptr;                 /* будущий родитель нового узла */
		if (x < ptr->get_data())  /* по определению нашего дерева - слева значение ключа меньше родителя, */
			ptr = ptr->left;
		else
			ptr = ptr->right;   /* справа - больше */
	}
	tmp->parent = ptr1;
	if (ptr1 == NULL)                       /* дерево было пусто? */
		root = tmp;
	else
	{
		if (x < ptr1->get_data())
			ptr1->left = tmp;
		else
			ptr1->right = tmp;
	}
	return;
}

/* возможны три случая - если у z нет детей, то помещаем 0 в соответствующее поле
* родителя z, если у z есть один ребенок, то можно вырезать z, соединив его родителя напрямую с
* его ребенком. Если же детей двое, то требуются некоторые приготовления: мы находим следующий
* (в смысле порядка на ключах) за z элемент y; у него нет левого ребенка (всегда). Теперь можно
* скопировать ключ и дополнительные данные из вершины y в вершину z, а саму вершину y удалить
* описанным выше способом */

template<class item>
TreeNode<item>* Tree<item>::delete_node(TreeNode<item> *z)
{
	TreeNode<item>* y;
	TreeNode<item>* x;
	if (z->left == NULL || z->right == NULL)               /* в этой и следующих двух строках ищем вершину y, которую мы потом вырежем из дерева. Это либо z, либо следующий за z */
		y = z;
	else
		y = find_succsessor(z->get_data());
	if (y->left != NULL)                                  /* x - указатель на существующего ребенка y или 0 если таковых нет */
		x = y->left;
	else
		x = y->right;
	if (x != NULL)                                        /* эта и следующие 9 строк - вырезание y */
		x->parent = y->parent;
	if (y->parent == NULL)
		root = x;
	else
	{
		if (y == (y->parent)->left)
			(y->parent)->left = x;
		else
			(y->parent)->right = x;
	}
	if (y != z)                                        /* если мы вырезали вершин, отличную от z, то ее данные перемещаем в z */
		z->data = y->get_data();
	return y;
}
template<class item>
TreeNode<item>* Tree<item>::find_max(TreeNode<item>* x)
{
	while (x->right != NULL)                              /* здесь все очевидно - самыое максимальное значение у самого правого */
		x = x->right;
	return x;
}

template<class item>
TreeNode<item>* Tree<item>::find_min(TreeNode<item>* x)
{
	while (x->left != NULL)
		x = x->left;
	return x;
}

template<class item>
TreeNode<item>* Tree<item>::find_succsessor(const item & val)
{
	TreeNode<item>* x = find_node(root, val);                     /* получим указатель на ноду с ключем val */
	TreeNode<item>* y;
	if (x == NULL)
		return 0;
	if (x->right != 0)                                                /* если у нее есть правые дети, то следующий элемент - минимальный в правом поддереве */
		return find_min(x->right);
	y = x->parent;
	while (y != NULL && x == y->right)                                   /* иначе - идем вверх и ищем первый элемент, являющийся левым
																	  потомком своего родителя */
	{
		x = y;
		y = y->parent;
	}
	return y;
}
template<class item>
TreeNode<item>* Tree<item>::find_node(TreeNode<item>* n,
	const item & val)
{
	if (n == NULL || val == n->get_data())
		return n;
	if (val > n->get_data())
		return find_node(n->right, val);
	else
		return find_node(n->left, val);
}
template<class item>
void Tree<item>::up_print(TreeNode<item>* n)
{
	if (n != NULL)
	{
		up_print(n->left);
		cout << n->get_data() << endl;
		up_print(n->right);
	}
}

template<class item>
TreeNode<item>* Tree<item>::get_root()
{
	return root;
}



using namespace std;
int main()
{
	Tree<int> treee;           /* создаем новой бинароное дерево с ключем типа int */
	int a;
	cout << "5 numbers:" << endl;   /* заполняем его */
	for (int i = 0; i<5; i++)
	{
		cin >> a;
		treee.insert_node(a);
	}
	cout << endl << "up_print:" << endl;              /* обходим */
	treee.up_print(treee.get_root());       /* вот для этого понадобился метод get_root() :-) */
	cout << endl << "Minimum is: " << (treee.find_min(treee.get_root()))->get_data() << endl;
	cout << endl << "Maximum is: " << (treee.find_max(treee.get_root()))->get_data() << endl;
	int b;
	cout << "Enter node value U want to delete:";     /* попробуем удалить узел с ключем a */
	cin >> b;
	treee.delete_node(treee.find_node(treee.get_root(), b));    /* если их несколько, то удалится первй найденный */
	cout << endl << "Now up_print:" << endl;
	treee.up_print(treee.get_root());       /* посмотрим на результат */
	cin.get();
	cin.get();
}
