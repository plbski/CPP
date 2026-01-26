#pragma once


#include<string>
#include<iostream>
#include<vector>
#include <stack>
#include<deque>



template<typename T,typename Container = std::deque<T> >

class MutantStack : public std::stack<T, std::deque<T> >
{
	public:
		using std::stack<T, Container>::c;
		MutantStack(){}
		~MutantStack(){}
		MutantStack(const MutantStack &other){*this->c = other.c;}
		MutantStack& operator=(const MutantStack& other){*this->cr = other.c; return(*this);}

		typedef typename Container::iterator iterator;
		typedef typename Container::const_iterator const_iterator;
		typedef typename Container::reverse_iterator reverse_iterator;
		typedef typename Container::const_reverse_iterator const_reverse_iterator;
		iterator begin(){return(c.begin());}
		iterator end(){return(c.end());}

		const_iterator begin()const {return(c.begin());}
		const_iterator end()const {return(c.end());}

		reverse_iterator rbegin(){return(c.rbegin());}
		reverse_iterator rend(){return(c.rend());}

		const_reverse_iterator rbegin()const {return(c.rbegin());}
		const_reverse_iterator rend()const {return(c.rend());}

	private:

};
