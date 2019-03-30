#if 0
#include<stack>

template<class T>
T& getAndRemove(std::stack<T>& st) //��stack��ջ��Ԫ�ط��ز����Ƴ�
{
	T result = st.top();
	st.pop();
	if (st.empty())
		return result;
	else
	{
		T last = getAndRemove(st);
		st.push(result);
		return last;
	}
}

template<class T>
void Reserse(std::stack<T>& st)  //��ջ��Ԫ������
{
	if (st.empty())
		return;
	T num = getAndRemove(st);
	Reserse(st);
	st.push(num);
}

int main()
{
	std::stack<int>  st;
	for (int i = 1; i <= 100; i++)
		st.push(i);
	Reserse(st);

}
#endif