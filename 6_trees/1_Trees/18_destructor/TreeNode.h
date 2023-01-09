#include <vector>
using namespace std;
template <typename T>
class TreeNode {
	public:
	T data;
	vector<TreeNode<T>*> children;
	TreeNode(T data) {
		this->data = data;
	}
	~TreeNode() {
		for (int i = 0; i < children.size(); i++) {
			delete children[i];
		}
	} // jab taak destructor function ke body ka content pura execute nii hota tab takk (root node) delete nii hogi , so hum destreuctor ki body me uski saari child nodes and further unki child nodes ko delete kar sakte hai. and in last jab destructor function close ho jaye ga with closing bracket then root node delete ho jaye ga.
}; 