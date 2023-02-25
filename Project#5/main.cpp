#include "header.h"
using namespace std;

int main()
{
	binaryTreeType<int>  treeRoot;
	int num;
	char response = 'y';
	
	while (tolower(response) == 'y') {
		cout << "Enter integers ending with -999" << endl;
		cin >> num;
		while (num != -999)
		{
			treeRoot.insert(num);
			cin >> num;
		}
		//Data: 65 55 22 44 61 19 90 10 78 52 -999
		/*cout << "Numbers before Binary Tree: "
			<< 65 << " " << 55 << " " << 22 << " " << 44
			<< " " << 61 << " " << 19 << " " << 90 << " " << 10
			<< " " << 78 << " " << 52 << endl;
		treeRoot.insert(65);
		treeRoot.insert(55);
		treeRoot.insert(22);
		treeRoot.insert(44);
		treeRoot.insert(61);
		treeRoot.insert(19);
		treeRoot.insert(90);
		treeRoot.insert(10);
		treeRoot.insert(78);
		treeRoot.insert(52);*/
		cout << endl;
		treeRoot.displayRoot();
		cout << endl;
		treeRoot.displayL2();
		cout << endl;
		treeRoot.displayL3();
		cout << endl;
		treeRoot.displayL4();
		cout << endl;
		treeRoot.displayL5();
		cout << endl << "Tree nodes in inorder: ";
		treeRoot.inorderTraversal();
		cout << endl << "Tree nodes in preorder: ";
		treeRoot.preorderTraversal();
		cout << endl << "Tree nodes in postorder: ";
		treeRoot.postorderTraversal();
		cout << endl;
		cout << "Tree Height: " << treeRoot.treeHeight() << endl;
		cout << "Number of Nodes: " << treeRoot.treeNodeCount() << endl;
		cout << endl;
		cout << endl << "===========================" << endl;
		int val = 0;
		cout << "enter a number to delete: ";
		cin >> val;
		treeRoot.deleteNode(val);
		cout << endl << "tree nodes in preorder after delete: ";
		treeRoot.preorderTraversal();
		cout << endl << "===========================" << endl;
		cout << "enter a number to insert: ";
		cin >> val;
		treeRoot.insert(val);
		cout << endl << "tree nodes in preorder after insert: ";
		treeRoot.preorderTraversal();
		cout << endl << "===========================" << endl;
		cout << "enter a number to search: ";
		cin >> val;
		if (treeRoot.search(val))
			cout << "number was found in the tree!" << endl;
		cout << endl << "tree nodes in preorder after search: ";
		treeRoot.preorderTraversal();
		cout << endl << "===========================" << endl;

		cout << "The number of single Parent node : "
			<< treeRoot.singleParent() << endl << endl;

		cout << "wanna try again? (enter y / n) : ";
		cin >> response;
		cin.ignore(100, '\n');
		cout << endl;
		if (response == 'n')
			return 0;
		while (tolower(response) != 'y' && tolower(response) != 'n') {
			cout << "please enter correct letter : ";
			cin >> response;
			cin.ignore(100, '\n');
		}
	}
	return 0;
}