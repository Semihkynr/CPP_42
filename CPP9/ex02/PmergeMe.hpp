#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <vector>
#include <deque>
#include <string>

class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();
		void run(int argc, char **argv) const;
	private:
		std::vector<int>	parseArgs(int argc, char **argv) const;
		template <typename Container>
		static void binaryInsert(const std::vector<int> &values, Container &chain, int elem)
		{
			typename Container::iterator lo = chain.begin();
			typename Container::iterator hi = chain.end();
			while (lo != hi)
			{
				typename Container::iterator mid = lo + (hi - lo) / 2;
				if (values[*mid] < values[elem])
					lo = mid + 1;
				else
					hi = mid;
			}
			chain.insert(lo, elem);
		}
		template <typename Container>
		static Container sortChain(const std::vector<int> &values, Container idx)
		{
			if (idx.size() <= 1)
				return (idx);
			bool hasStraggler = (idx.size() % 2 != 0);
			int straggler = 0;
			if (hasStraggler)
			{
				straggler = idx.back();
				idx.pop_back();
			}
			Container winners;
			std::vector<int> losers;
			for (size_t i = 0; i < idx.size(); i += 2)
			{
				int a = idx[i];
				int b = idx[i + 1];
				if (values[a] > values[b])
				{
					winners.push_back(a);
					losers.push_back(b);
				}
				else
				{
					winners.push_back(b);
					losers.push_back(a);
				}
			}
			Container chain = sortChain(values, winners);
			for (size_t i = 0; i < losers.size(); ++i)
				binaryInsert(values, chain, losers[i]);
			if (hasStraggler)
				binaryInsert(values, chain, straggler);
			return (chain);
		}
	public:
		template <typename Container>
		static Container mergeInsertionSort(const std::vector<int> &input)
		{
			Container indices;
			for (size_t i = 0; i < input.size(); ++i)
				indices.push_back(static_cast<int>(i));
			Container sortedIdx = sortChain(input, indices);
			Container result;
			for (typename Container::const_iterator it = sortedIdx.begin(); it != sortedIdx.end(); ++it)
				result.push_back(input[*it]);
			return (result);
		}
};
#endif