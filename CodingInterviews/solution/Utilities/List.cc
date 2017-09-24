#include <iostream>
#include <sstream>
class ListNode {
	public:
		void ConnectListNode(ListNode &dest) {
			this->next = &dest;
		}
		static void PrintList(ListNode &src) {
			ListNode *node = &src;
			while(node != NULL) {
				std::cout << (*node).val << " " ;
				node = node->next;
			}
			std::cout << std::endl;
		}
		friend std::ostream & operator << (std::ostream &os, ListNode &node) {
   /*         while(node != nullptr){*/
				//os << node->val << " " ;
				//node = node->next;
			/*}*/
			os << node.val << std::endl;
			return os;
		}
	private:
		int val;
		ListNode *next;
	public:
		ListNode(int x):
			val{x}, next{nullptr} {
			}
};

int main() {
	ListNode a(1);
	ListNode a1(2);
	ListNode a2(3);
	a.ConnectListNode(a1);
	a1.ConnectListNode(a2);
	ListNode::PrintList(a);
	std::cout << a << std::endl;
}
