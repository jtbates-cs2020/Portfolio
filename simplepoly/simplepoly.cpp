#include "simplepoly.h"
#include<iostream>
using namespace std;

simplepoly::simplepoly() {
	variable = 'x';
	//Dummy term is added so we can verify whether or not the list is empty
	//Dummy term is always removed before list is filled
	terms = new node(term(0, -1));
}

void simplepoly::copy(const simplepoly& p) {
	//Make terms nullptr so InsertTermSorted works correctly
	terms = nullptr;
	if (p.terms->data().exp != -1) {
		variable = p.variable;
		//terms should have been deleted already, so we don't need to worry about changing anything
		//We can copy it over as usual
		node* currNode = p.terms;
		while (currNode != NULL) {
			InsertTermSorted(currNode->data());
			currNode = currNode->link();
		}
	}
	else {
		terms = new node(term(0, -1));
	}
};

simplepoly::simplepoly(const simplepoly& p) {
	copy(p);
};

void simplepoly::free() {
	while (terms != NULL) {
		list_head_remove(terms);
	}
}

simplepoly::~simplepoly() {
	free();
}

simplepoly & simplepoly::operator=(const simplepoly& p) {
	if (this != &p) {
		this->free();
		this->copy(p);
	}
	return *this;
}

void simplepoly::read() {
	//temporary simplepoly created and deleted to test assignment operator
	simplepoly temp;
	//removing dummy term with exp -1
	list_head_remove(temp.terms);
	temp.terms = nullptr;
	int coeff;
	int exp;
	cin >> temp.variable;
	do
	{
		cin >> coeff;
		if (coeff)
		{
			cin >> exp;
			term t(coeff, exp);
			if (exp >= 0) temp.InsertTermSorted(t);
		}
		else while (cin && (cin.peek() != '\n')) cin.ignore();
	} while (coeff && (exp >= 0));
	//Just used to test = operator
	*this = temp;
}

//I just copied my code from project 2, with some replacements
//I know that I'm using namespace std, but VS got upset when I used cout instead of std::cout
void simplepoly::write() const {
	char sign(term);
	//Check to make sure it isn't empty
	if (terms->data().exp == -1) {
		std::cout << '0';
	}
	else {
		term t;
		for (node* cursor = terms; cursor != NULL; cursor = cursor->link())
		{
			t = cursor->data();
			//For first one, we don't need a plus, so we can output without worrying about sign.
			//We do need a minus if the first coefficient is negative, but that will be outputted anyway
			//with the coefficient. 
			if (cursor == terms) {
				if (abs(t.coeff) != 1) {
					if (t.exp == 0) std::cout << t.coeff;
					else if (t.exp == 1) std::cout << t.coeff << variable << ' ';
					else std::cout << t.coeff << variable << t.exp << ' ';
				}
				//if the coefficient is one (or negative one), the coefficient doesn't need to be displayed
				//However, the sign still needs to be displayed without the 1 after it.
				//This is mildly complicated, but I promise it works. 
				else {
					if (t.exp == 0) {
						std::cout << t.coeff;
					}
					else if (t.exp == 1) {
						if (t.sign() == '-') std::cout << t.sign() << variable << ' ';
						else std::cout << variable << ' ';
					}
					else {
						if (t.sign() == '-') std::cout << t.sign() << variable << t.exp << ' ';
						else std::cout << variable << t.exp << ' ';
					}
				}
			}
			else {
				//output sign and then absolute value of coefficient 
				//so we don't get --coeff x exp and we make sure we get the plus
				//Also, for term 0, we don't need the variable
				//and for term 1 we don't need to raise x to any exponent
				if (abs(t.coeff) != 1) {
					if (t.exp == 0) std::cout << t.sign() << abs(t.coeff);
					else if (t.exp == 1) std::cout << t.sign() << abs(t.coeff) << variable << ' ';
					else std::cout << t.sign() << abs(t.coeff) << variable << t.exp << ' ';
				}
				//coefficient of 1 doesn't need to be displayed
				//it is enough to say +x3 or -x2
				else {
					if (t.exp == 0) std::cout << t.sign() << abs(t.coeff);
					else if (t.exp == 1) std::cout << t.sign() << variable << ' ';
					else std::cout << t.sign() << variable << t.exp << ' ';
				}
			}
		}
	};
	std::cout << endl;
};

simplepoly simplepoly::plus(simplepoly right) const { 
	simplepoly h;
	//Return if variables don't match
	if (variable != right.variable) {
		cout << "This program can only add polynomials of the same variable\n";
	}
	else {
		//remove dummy term
		list_head_remove(h.terms);
		h.terms = nullptr;
		bool empty = true;
		//find starting point exp
		int startingPoint = 0;
		if (terms->data().exp >= right.terms->data().exp) startingPoint = terms->data().exp;
		else startingPoint = right.terms->data().exp;
		node* leftCursor = terms;
		node* rightCursor = right.terms;
		for (int i = startingPoint; i >= 0; i--) {
			//Make sure we're on the right exp for each cursor
			while (rightCursor != NULL && rightCursor->data().exp > i) {
				rightCursor = rightCursor->link();
			}
			while (leftCursor != NULL && leftCursor->data().exp > i) {
				leftCursor = leftCursor->link();
			}
			//leave if we've reached the end of both polynomials
			if (leftCursor == NULL && rightCursor == NULL) break;
			//Update coefficient
			int newCoeff = 0;
			//Only add coefficients if we're at the right exp for both polynomials
			if (leftCursor != NULL && leftCursor->data().exp == i) newCoeff += leftCursor->data().coeff;
			if (rightCursor != NULL && rightCursor->data().exp == i) newCoeff += rightCursor->data().coeff;
			if (newCoeff != 0) {
				h.InsertTermSorted(term(newCoeff, i));
				empty = false;
			}
		}
		//If all exps ended up being 0, we need to add a dummy term to show that the polynomial is empty
		if (empty) {
			h.InsertTermSorted(term(0, -1));
		}
	}
	return h;
}

simplepoly simplepoly::minus(simplepoly right) const {
	simplepoly h;
	if (variable != right.variable) {
		cout << "This program can only add polynomials of the same variable\n";
	}
	else {
		//Remove dummy term
		list_head_remove(h.terms);
		h.terms = nullptr;
		bool empty = true;
		//find starting point exp
		int startingPoint = 0;
		if (terms->data().exp >= right.terms->data().exp) startingPoint = terms->data().exp;
		else startingPoint = right.terms->data().exp;
		//Create cursors for each set of terms
		node* leftCursor = terms;
		node* rightCursor = right.terms;
		for (int i = startingPoint; i >= 0; i--) {
			//Make sure we're on the right exp for each cursor
			while (rightCursor != NULL && rightCursor->data().exp > i) rightCursor = rightCursor->link();
			while (leftCursor != NULL && leftCursor->data().exp > i) leftCursor = leftCursor->link();
			//leave if we've reached the end of both polynomials
			if (leftCursor == NULL && rightCursor == NULL) break;
			//Update coefficient
			int newCoeff = 0;
			//Add right coefficient if we have a coefficient at the correct exponent
			if (leftCursor != NULL && leftCursor->data().exp == i) newCoeff += leftCursor->data().coeff;
			//Subtract right coefficient instead of adding it
			if (rightCursor != NULL && rightCursor->data().exp == i) newCoeff -= rightCursor->data().coeff;
			//Only add the new term if the coefficient at exponent i is non-zero
			if (newCoeff != 0) {
				h.InsertTermSorted(term(newCoeff, i));
				empty = false;
			}
		}
		//If all exps ended up being 0, we need to add a dummy term to show that the polynomial is empty
		if (empty) {
			h.InsertTermSorted(term(0, -1));
		}
	}
	return h;
}

float simplepoly::evaluate(float arg) const {
	float total = 0.0;
	//If it's empty, just return 0
	if (terms->data().exp != -1) {
		//Iterate through entire polynomial
		node* cursor = terms;
		while (cursor != NULL) {
			//Raise the argument by each power and multiply it by the coefficient, then add it to total
			total += cursor->data().coeff * (pow(arg, cursor->data().exp));
			cursor = cursor->link();
		}
	}
	return total;
}

void simplepoly::InsertTermSorted(term t) {
	//I took this code from what I wrote for the bonus for one of the exercises
	list_insert_sorted(terms, t);
}