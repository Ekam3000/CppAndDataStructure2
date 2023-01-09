#include <vector>
using namespace std;
template <typename T>
class TreeNode
{
public:
	T data;
	vector<TreeNode<T> *> children; 
	// array ya linked list use kyu nahi kiya , array me size ki dikkat aani thi . linked list me access karne ki dikkat aani thi.
	// har ek parent node ko many of child nodes ke addresses store karne hai iss lie vector use kiya  and parent vector ko childern nodes ka address store karna hai(jiska datatype bhi T hai) so isse liye vector bhi class TreeNode of T datatype hai.
	// or
	// parent agr T type ka data rakhta hai to jo children ha wobhi T type ka data hi rakhe ge , warna tum parent ke vector me childrens nodes link nii kar paoo ge 
	TreeNode(T data)
	{
		this->data = data;
	}
	~TreeNode() {
		for (int i = 0; i < children.size(); i++) {
			delete children[i];
		}
	}
};