#include<stack>
#include<iostream>

template<class T>
void sortStackByStack1(std::stack<T> st)
{
	std::stack<T> help;
	while (!st.empty())
	{
		T top = st.top();
		st.pop();
		if (help.empty())
			help.push(top);
		else
		{
			if (top <= help.top())
				help.push(top);
			else
			{
				int count = 0;
				while (top > help.top())
				{
					st.push(help.top());
					help.pop();
					count++;
				}
				help.push(top);
				for (int i = 0; i < count; i++)
				{
					help.push(st.top());
					st.pop();
				}
			}
		}
	}
	while (!help.empty())
	{
		std::cout << help.top() << " ";
		help.pop();
	}
	std::cout << std::endl;
}

template<class T>
void PrintStack(std::stack<T> st)
{
	while (!st.empty())
	{
		std::cout << st.top() << " ";
		st.pop();
	}
	std::cout << std::endl;
}

template<class T>
void sortStackByStack2(std::stack<T>& st)
{
	std::stack<T> help;
	while (!st.empty())
	{
		T cur = st.top();
		st.pop();
		while (!help.empty() && help.top() < cur)
		{
			st.push(help.top());
			help.pop();
		}
		help.push(cur);
	}
	while(!help.empty())
	{
		st.push(help.top());
		help.pop();
	}
}

int main()
{
	std::stack<int> st;
	for (int i = 10; i >= 1; i--)
		st.push(i);
	PrintStack(st);
	sortStackByStack2(st);
	PrintStack(st);
}