#include "EntityCollection.h"

template <class T>
void EntityCollection<T>::clear() {
	Bag.clear();
}

template <class T>
T EntityCollection<T>::get(int index) {
	return Bag.at(index);
}

template <class T>
int EntityCollection<T>::length() {
	return Bag.size();
}

/*
template <class T>
void EntityCollection<T>::insert(T const& entity, int index) {
	Bag.insert(Bag.begin() + index, entity);
}
*/
template <class T>
void EntityCollection<T>::pop() {
	Bag.pop_back();
}

template <class T>
void EntityCollection<T>::push(T entity) {
	Bag.push_back(entity);
}

template <class T>
void EntityCollection<T>::update() {
	for (std::vector<Entity>::iterator it = Bag.begin();
		it != Bag.end();
		++it) {

			//TODO(jouni):  Remove entities which are out of range/out of screen
			//				Call update to entities
			//				Check collision
	}
}

template <class T>
void EntityCollection<T>::render() {
	for (std::vector<Entity>::iterator it = Bag.begin();
		it != Bag.end();
		++it) {

		it->render();	

	}
}

template <class T>
void EntityCollection<T>::removeAt(int index) {
	Bag.erase(Bag.begin() + index);
}