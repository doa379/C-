#include <iostream>
#include <vector>
#include <thread>

using namespace std;

class M
{
	uint i;

public:
	//thread th;
	M(uint);
	M(M &&);
	M &operator =(const M &);
	~M(void);
	void evFn(void);
};

const unsigned char N = 20;
vector<M> C;

M::M(uint arg): i(move(arg))
{

}

M::M(M &&arg): i(move(arg.i))
{

}

M &M::operator =(const M &arg)
{
	return *this;
}

M::~M(void)
{
	cout << "Class M object destructed\n";
}

int main(void)
{
	C.reserve(N);
	
	for (auto i = 0; i < N; i++)
	{
		C.emplace_back(i);
		//M m(i);
		//C.emplace_back(move(M(i)));
		
	}

	for (;;);

	return 0;
}

void M::evFn(void)
{

}
