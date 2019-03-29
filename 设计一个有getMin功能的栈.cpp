#if 0
#include<stack>
using namespace std;

template<class T>
class MyStack {
public:
	MyStack() {}
	void Push(T data)
	{
		stackDate.push(data);
		if (stackMin.empty())
			stackMin.push(data);
		else
		{
			if (data > stackMin.top())
				stackMin.push(stackMin.top());
			else
				stackMin.push(data);
		}
	}
	void Pop()
	{
		stackDate.pop();
		stackMin.pop();
	}
	T& getMin()
	{
		return stackMin.top();
	}

private:
	stack<T> stackDate;
	stack<T> stackMin;
};

int main()
{
	MyStack<int> st;
	st.Push(3);
	st.Push(4);
	st.Push(5);
	st.Push(1);
	st.Push(2);
	st.Push(1);
	st.Pop();
	int num = st.getMin();
	return 0;
}
#endif