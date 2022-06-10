/*By::Cebastian Santiago
* Leetcode 904
*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

//3, 3 , 3 , 1 , 2 , 1 , 1 , 2, 3 , 3, 4
//           



//1, 0, 1, 4, 1, 4, 1, 2, 3
//      l              r
int totalFruit(std::vector<int>& fruits){
	//if fruits is emoty return zero
	if (fruits.empty()){
		return 0;
	}
	//if fruits is size 1 return 1
	if (fruits.size() - 1 == 0) {
		return 1;
	}


	//variables
	int l = 0;
	int r = 1;
	int max = 0;
	int count = 0;
	std::map<int, int> hash;
	hash[fruits[l]]++;
	//1, 0, 0, 4, 7, 4, 4, 4, 7
	//l        r  

	//loop through the trees
	for (r; r <= fruits.size()-1; r++){
		//inser the fruite into the tree
		hash[fruits[r]]++;
		//if size is less then two get the current max 
		//of the fruit we can get 
		if (hash.size() <= 2){
			for (auto i : hash) {
				count += i.second;
			}
			max = std::max(max, count);
			//reset count back to zero
			count = 0;
		}

		//if the hash(map) is greater then two then 
		//loop through the left pointer and decrement
		//values until there less then 0 or equal to zero 
		//and exit out 
		if (hash.size() > 2){
			while (hash.size() > 2){
				hash[fruits[l]]--;
				if (hash[fruits[l]] <= 0) {
					hash.erase(fruits[l]);
				}
			    l++;
			}
		}
	}

	return max;
}

int main(int argc, char* argv[]) {
	std::vector<int> num = { 3, 3 , 3 , 1 , 2 , 1 , 1 , 2, 3 , 3, 4 };

	std::cout << totalFruit(num) << std::endl;
	return 0;
}