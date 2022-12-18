#ifndef SIMPLEPOLY_H
#define SIMPLEPOLY_H
#include "node.h"

using namespace main_savitch_5;
class simplepoly
{
public:
	simplepoly();
	simplepoly (const simplepoly &);
	~simplepoly ();
	simplepoly & operator= (const simplepoly &);
	void read ();
	void write () const;
	simplepoly plus (simplepoly) const;
	simplepoly minus (simplepoly) const;
	float evaluate (float) const;
private:
	node * terms;
	char variable;

	void copy (const simplepoly &);
	void free ();
	void InsertTermSorted (term);
};
#endif
