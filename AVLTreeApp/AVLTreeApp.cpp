#include <iostream>
#include <random>
#include <chrono>
#include <thread>
#include "..\AVLTreeLib\AVLTreeLib.h"
#include "..\benchmark\benchmark.h"
#include <cstdlib>

class Key
{
private:
	unsigned long value = 0UL;
	static bool performDelay;
	void delay() const
	{
		if (performDelay)
			std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
public:
	Key() = default;

	Key(Key const&) = default;

	Key(unsigned long v) : value(v)
	{
	}

	unsigned long getKey() const
	{
		return value;
	}

	static void delayOn()
	{
		performDelay = true;
	}

	static void delayOff()
	{
		performDelay = false;
	}


	bool operator==(Key const& v) const
	{
		delay();
		return value == v.value;
	}

	bool operator!=(Key const& v) const
	{
		delay();
		return value != v.value;
	}

	bool operator<(Key const& v) const
	{
		delay();
		return value < v.value;
	}
	bool operator<=(Key const& v) const
	{
		delay();
		return value <= v.value;
	}
	bool operator>(Key const& v) const
	{
		delay();
		return value > v.value;
	}
	bool operator>=(Key const& v) const
	{
		delay();
		return value >= v.value;
	}

};

bool Key::performDelay = false;

std::ostream & operator << (std::ostream& stream, Key const& key)
{
	stream << key.getKey();
	return stream;
}

int main()
{
    int tab[10] = {1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000};
    int tab2[1] = {10};
	auto seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::mt19937 generator((unsigned long)seed);
    srand (time(NULL));
	int size;
	for(auto i: tab)
	{
		//std::cout << "Enter size:";
		size = i;
		if (size > 0)
		{
			Key::delayOff();
			AVLTreeLib<Key, unsigned long> tree;
			while (tree.size() < size)
			{
				unsigned long n = generator();
                //int n = rand() % 1000;

				Key key(n);

				tree.insert(key, n);
			}
			if (tree.size() <= 100)
				std::cout << tree.print2D();

			Key::delayOn();
			unsigned long long sum = 0;
			int i;
			for (i = 0; i < 100; ++i)
			{
				unsigned long n = generator();
				Key key(n);

				Benchmark<std::chrono::nanoseconds> b;
				tree.find(Key(key));
				sum += b.elapsed();
			}
			std::cout << sum / i << "\n";
		}
	}
	return 0;
}
