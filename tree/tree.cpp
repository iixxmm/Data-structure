#include <iostream>
#include <vector>
using namespace std; 
vector<int> nums; 
class treenode {
	public:
	int item; 
  treenode *left, *right; 
  treenode(int val) {
  	item = val; 
  	left = right = nullptr; 
  }
};
void pre(treenode* root) {
    if (root == nullptr) {
    	return; 
    }
    pre(root->left); 
    cout << root->item << " "; 
    pre(root->right);
}
int findmin(treenode* root) {
	if (root == nullptr) 
		return INT_MAX; 
  else
  	return min(root->item, min(findmin(root->left), findmin(root->right))); 
}
int size(treenode* root) {
  if (root == nullptr)
  	return 0; 
  return size(root->left) + size(root->right) + 1; 
}
int width(treenode *root) {
  int l = 0, r = 0; 
  treenode *copy = root; 
  while (root->left != nullptr) {
    root = root->left; 
    l++; 
  }
  while (copy->left != nullptr) {
    copy = copy->left; 
    r++; 
  }
  return l + r; 
}
bool searchelement(treenode *root, int item) {
  if (root == nullptr) 
    return false; 
  if (root->item == item)
    return true; 
  return searchelement(root->left, item) or searchelement(root->right, item); 
}
bool isidentical(treenode *t1, treenode* t2) {
  if (t1 == nullptr and t2 == nullptr)
    return true; 
  if (t1 == nullptr or t2 == nullptr)
    return false; 
  return isidentical(t1->left, t2->left) and isidentical(t1->right, t2->right); 
}
bool issubtree(treenode* a, treenode* b) {
  return 0;
}
void addinvector(treenode *root) {
  if (root == nullptr)
    return; 
  addinvector(root->left); 
  nums.push_back(root->item); 
  addinvector(root->right); 
}
int main() {
  treenode *a = new treenode(5); 
  a->left = new treenode(3); 
  a->left->left = new treenode(-5); 
  a->left->left->left = new treenode(9);
  a->left->right = new treenode(4); 
  a->right = new treenode(8); 
  a->right->left = new treenode(6); 
  a->right->right = new treenode(9);
  a->right->right->right = new treenode(24);
  a->right->right->left = new treenode(55);
  a->right->right->right->right = new treenode(254);

  treenode *b = new treenode(9); 
  b->left = new treenode(55); 
  b->right = new treenode(24); 
  b->right->right = new treenode(254); 
  
  addinvector(a); 
  for (int i : nums)
    cout << searchelement(a, i) << " ";
  cout << size(a);
}
