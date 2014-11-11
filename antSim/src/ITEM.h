/*
 * ITEM.h
 *
 *  Created on: 11.11.2014
 *      Author: Gerold
 */

#ifndef SRC_ITEM_H_
#define SRC_ITEM_H_

namespace std {

class ITEM {
public:


	virtual void act() = 0; //pure virtual

	ITEM();
	virtual ~ITEM();
};

} /* namespace std */

#endif /* SRC_ITEM_H_ */
