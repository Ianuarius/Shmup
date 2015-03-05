/**
 * EntityCollection.h
 * 
 */

#ifndef __ENTITYCOLLECTION_H_DEFINED__
#define __ENTITYCOLLECTION_H_DEFINED__

#include <vector>

template <class T>
class EntityCollection {
	public:
		void clear() {
			Bag.clear();
		}

		T* get(int index) {
			return &(Bag.at(index));
		}

		int length() {
			return Bag.size();
		}

		//void insert(T const& entity, int index);

		void pop() {
			Bag.pop_back();
		}

		void push(T entity) {
			Bag.push_back(entity);
		}

		void update() {
			int index = 0;

			for (std::vector<T>::iterator it = Bag.begin();
				it != Bag.end();
				++it) {
					//TODO(jouni):  Remove entities which are out of range/out of screen
					//				Call update to entities
					//				Check collision
					it->update();
					
			}
		}

		void render() {
			for (std::vector<T>::iterator it = Bag.begin();
				it != Bag.end();
				++it) {
					it->render();

			}
		}

		void removeAt(int index) {
			Bag.erase(Bag.begin() + index);
		}


	private:
		std::vector<T> Bag;
};

#endif // __ENTITYCOLLECTION_H_DEFINED__