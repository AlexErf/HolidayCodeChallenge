
#include "days.h"

#include <fstream>
#include <string>
#include <set>
#include <sstream>
#include <iostream>
#include <map>
#include <vector>


struct node {
	int own_score;
	std::string word;
	std::vector<std::string> children;
};


int score_node(std::map<std::string, node> & node_list, node n) {
	int score = n.own_score;
	for (std::string child : n.children) {
		node c = node_list[child];
		score += score_node(node_list, c);
	}
	return score;
}


std::string day7p1() {

	std::ifstream fin("input/day7.txt");
	std::string nextline;
	std::string nextword;
	std::set<std::string> words;

	while (std::getline(fin, nextline)) {
		std::istringstream extraction(nextline);
		extraction >> nextword;
		words.insert(nextword);
	}

	std::ifstream another_fin("input/day7.txt");
	
	while (std::getline(another_fin, nextline)) {
		std::istringstream extraction(nextline);
		extraction >> nextword;
		if (extraction >> nextword) {
			extraction >> nextword;
			while (extraction >> nextword) {
				if (nextword.back() == ',') {
					nextword.pop_back();
				}
				words.erase(nextword);
			}
		}
	}

	return *words.begin();

}


int check_children(std::map<std::string, node> node_map, node n) {

	std::vector<int> scores;
	auto children = n.children;
	for (auto s : children) {
		scores.push_back(score_node(node_map, s));
	}

	int outlier = -1;

	for (int i = 0; i < scores.size() - 2; ++i) {
		if (scores[i] != scores[i + 1]) {
			if (scores[i] != scores[i + 2]) {
				outlier = i;
				break;
			}
			else {
				outlier = i + 1;
				break;
			}
		}
	}

	if (scores[scores.size() - 2] != scores[scores.size() - 1]) {
		if (scores[scores.size() - 2] != scores[0]) {
			outlier = scores.size() - 2;
		}
		else {
			outlier = scores.size() - 1;
		}
	}

	if (outlier == -1) {
		return -1;
	}
	else {
		int a = check_children(node_map, node_map[children[outlier]].children);
		if (a == -1) {
			
		}
	}
}


int day7p2() {

	std::ifstream fin("input/day7.txt");
	std::string nextline;
	std::string node_word;
	std::string node_score;
	std::string next_word;

	std::map<std::string, node> node_map;

	while (std::getline(fin, nextline)) {
		std::istringstream extraction(nextline);
		node n;
		extraction >> node_word;
		extraction >> node_score;
		node_score.pop_back();
		node_score = node_score.substr(1);
		n.own_score = stod(node_score);
		n.word = node_word;
		if (extraction) {
			extraction >> next_word;
			while (extraction >> next_word) {
				if (next_word.back() == ',') {
					next_word.pop_back();
				}
				n.children.push_back(next_word);
			}
		}
		node_map[n.word] = n;
	}

	for (auto & kv : node_map) {
		std::string node_nam = kv.first;
		node n = kv.second;
		if (n.children.size() > 1) {
			int score = score_node(node_map, node_map[n.children[0]]);
			int score2 = score_node(node_map, node_map[n.children[1]]);
			if (score != score2) {
				std::cout << n.children[0] << std::endl;
				int score3 = score_node(node_map, node_map[n.children[2]]);
				if (score == score3) {
					return node_map[n.children[1]].own_score + score3 - score2;
				}
				else {
					return node_map[n.children[0]].own_score + score3 - score;
				}
			}
			for (int i = 2; i < n.children.size(); ++i) {
				int other_score = score_node(node_map, node_map[n.children[i]]);
				if (score != other_score) {
					std::cout << n.children[i] << std::endl;
					return score;
				}
			}
		}
	}

	throw -1;
}

