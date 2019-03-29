
//编写一个类，用两个栈实现队列，支持队列的基本操作（增删查）
#if 0
#include<stack>

template<class T>
class MyQueue {
private:
	void pushToPop()
	{
		if (stackPop.empty())
		{
			while (!stackPush.empty())
			{
				stackPop.push(stackPush.top());
				stackPush.pop();
			}
		}
	}
public:
	void Push(T data)
	{
		stackPush.push(data);
		this->pushToPop();
	}
	void Pop()
	{
		this->pushToPop();
		stackPop.pop();
	}
	T& front()
	{
		this->pushToPop();
		return stackPop.top();
	}

private:
	std::stack<T> stackPush;
	std::stack<T> stackPop;
};


int main()
{
	MyQueue<int> qu;
	qu.Push(1);
	qu.Push(2);
	qu.Push(3);
	qu.Push(4);
	qu.Push(5);
	qu.Push(6);
	int num = qu.front();
	qu.Pop();
	num = qu.front();
	return 0;
}

#endif