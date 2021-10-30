#ifndef __MUTANT_STACK_HPP
# define __MUTANT_STACK_HPP

#include <stack>


template <typename T>
class MutantStack: public std::stack<T> {
	public:

		typedef T* iterator;

		MutantStack();
		MutantStack(const MutantStack<T> & obj);
		MutantStack & operator = (const MutantStack<T> & obj);
		virtual ~MutantStack();

		iterator begin();
		iterator end();
};


template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
	return end() - this->size();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {
	return &(this->top()) + 1;
}

///////////////////////////////////////////////////////////////////////////////////
// ORTHODOX
template <typename T>
MutantStack<T>::MutantStack() {
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T> & obj) {
	*this = obj;
}

template <typename T>
MutantStack<T> & MutantStack<T>::operator = (const MutantStack<T> & rhs) {
	if (this == & rhs) 
		return *this;
	return MutantStack(rhs);
}

template <typename T>
MutantStack<T>::~MutantStack() {
}

#endif // __MUTANT_STACK_HPP
